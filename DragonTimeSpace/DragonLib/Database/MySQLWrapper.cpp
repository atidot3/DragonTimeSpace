#include "MySQLWrapper.h"
#include "../Utils/Logger/Logger.h"

#include <sstream>
#include <cstring>
#include <boost\bind.hpp>

#include <mysql/errmsg.h>
#include <mysql/mysqld_error.h>

static MySQLConnWrapper *mapManager = nullptr;

MySQLConnWrapper& MySQLConnWrapper::instance()
{
	return *mapManager;
}

void MySQLConnWrapper::Initialize()
{
	if (!mapManager)
	{
		mapManager = new MySQLConnWrapper();
	}
}

/*static*/ void MySQLConnWrapper::Destruct()
{
	if (mapManager)
		delete mapManager;
}
MySQLConnWrapper::~MySQLConnWrapper()
{
	/* Execute all remaining query's*/
	LOG_TRACE << "MySQL execute all remaining query's...";
	//while (_queue.size() > 0);

	//_running = false;
	//_worker.join();

	// -- Await everything to be done
	std::this_thread::sleep_for(std::chrono::seconds(5));
	
	mysql_close(_con);
	_con = nullptr;
}
MySQLConnWrapper::MySQLConnWrapper()
	: _con{nullptr}
	, _reconnecting{ false }
	//, _queue{}
	//, _running{ false }
{
	_con = mysql_init(NULL);
	if (_con == nullptr)
	{
		LOG_FATAL << "#ERR : " << std::string(mysql_error(_con));
	}
	else
	{
		unsigned int readTimeout = 30;
		unsigned int writeTimeout = 30;
		unsigned int connectionTimeout = 30;
		if (mysql_options(_con, MYSQL_OPT_READ_TIMEOUT, &readTimeout) ||
			mysql_options(_con, MYSQL_OPT_WRITE_TIMEOUT, &writeTimeout) ||
			mysql_options(_con, MYSQL_OPT_CONNECT_TIMEOUT, &connectionTimeout))
		{
			throw std::runtime_error("Unable to set mysql options.");
		}
	}
	//_worker = std::thread(&MySQLConnWrapper::run, this);
}
bool MySQLConnWrapper::manageException(uint32_t errNo, uint8_t attempts /*= 5*/)
{
	if (_con != nullptr)
	{
		LOG_FATAL << "MySQLServer error: [" << errNo << "]";
		LOG_FATAL << "Server status [" << std::to_string(_con->server_status) << "] Normal status [" << std::to_string(_con->status) << "]";
		LOG_FATAL << "#ERR: " << std::string(mysql_error(_con));
	}
	switch (errNo)
	{
	case CR_SERVER_GONE_ERROR:
	case CR_SERVER_LOST:
	/*case CR_INVALID_CONN_HANDLE: VANISHED*/
	case CR_SERVER_LOST_EXTENDED:
	{
		if (_con)
		{
			LOG_FATAL << "Lost the connection to the MySQL server!";

			mysql_close(_con);
			_con = nullptr;
		}

		/*no break*/
	}
	case CR_CONN_HOST_ERROR:
	{
		LOG_FATAL << "Attempting to reconnect to the MySQL server...";

		_reconnecting = true;

		const bool lErrno = connect(_conInfo._host, _conInfo._user, _conInfo._password, _conInfo._database);
		if (!lErrno)
		{
			LOG_INFO << "Successfully reconnected to " << _conInfo._database << " @" << _conInfo._user << ":" << _conInfo._password << "(" << _conInfo._host << ")";
			_reconnecting = false;
			return true;
		}

		if ((--attempts) == 0)
		{
			// Shut down the server when the mysql server isn't
			// reachable for some time
			LOG_FATAL << "Failed to reconnect to the MySQL server, ";
			// We could also initiate a shutdown through using std::raise(SIGTERM)
			std::this_thread::sleep_for(std::chrono::seconds(10));
			std::abort();
		}
		else
		{
			// It's possible this attempted reconnect throws 2006 at us.
			// To prevent crazy recursive calls, sleep here.
			std::this_thread::sleep_for(std::chrono::seconds(3)); // Sleep 3 seconds
			return manageException(lErrno, attempts); // Call self (recursive)
		}
	}

	case ER_LOCK_DEADLOCK:
	{
		LOG_FATAL << "MySQLServer encounter ER_LOCK_DEADLOCK";
		return false;
	}
	// Query related errors - skip query
	case ER_WRONG_VALUE_COUNT:
	case ER_DUP_ENTRY:
	{
		return false;
	}
		// Outdated table or database structure - terminate core
	case ER_BAD_FIELD_ERROR:
	case ER_NO_SUCH_TABLE:
	{
		LOG_FATAL << "Your database structure is not up to date. Please make sure you've executed all queries in the sql/updates folders.";
		std::this_thread::sleep_for(std::chrono::seconds(10));
		std::abort();
		return false;
	}
	case ER_PARSE_ERROR:
	{
		LOG_FATAL << "Error while parsing SQL. Core fix required.";
		std::this_thread::sleep_for(std::chrono::seconds(10));
		std::abort();
		return false;
	}
	default:
		LOG_FATAL << "Unhandled MySQL errno " << errNo << ". Unexpected behaviour possible.";
		return false;
	}
}

// TODO : add mysql port on configuration to ensure secure newtork open database
bool MySQLConnWrapper::connect(const std::string& host, const std::string& user, const std::string& password, const std::string& database)
{
	if (!_con)
		_con = mysql_init(NULL);
	if (mysql_real_connect(_con, host.c_str(), user.c_str(), password.c_str(),
		database.c_str(), 3306, NULL, 0) == nullptr)
	{
		if (_con != nullptr)
		{
			LOG_FATAL << "Server status [" << std::to_string(_con->server_status) << "] Normal status [" << std::to_string(_con->status) << "]";
			LOG_FATAL << "#ERR: " << std::string(mysql_error(_con));
		}
		return false;
	}

	if (!_reconnecting)
	{
		LOG_INFO << "Connected to MySQL database " << user << "@" << host << ":" << database;
		LOG_INFO << "MySQL client library: " << std::string(mysql_get_client_info());
		LOG_INFO << "MySQL server ver: " << std::string(mysql_get_server_info(_con));
	}
	_conInfo._host = host;
	_conInfo._user = user;
	_conInfo._password = password;
	_conInfo._database = database;

	return true;
}
void MySQLConnWrapper::Ping()
{
	if (_con)
		mysql_ping(_con);
}
char* MySQLConnWrapper::EscapeString(const std::string& str)
{
	char* to = new char[str.size()];

	mysql_escape_string(to, str.c_str(), static_cast<unsigned long>(str.size()));
	std::string newEscape = std::string(to);

	return to;
}

std::unique_ptr<QueryResult> MySQLConnWrapper::ExecuteQuery(const std::string& query, bool& ret)
{
	if (!_con)
	{
		LOG_FATAL << "Connection not setup.";
		ret = false;
		return nullptr;
	}
	if (mysql_query(_con, query.c_str()))
	{
		LOG_ERROR << "SQL causing error: " << query;
		// If it returns true, an error was handled successfully (i.e. reconnection)
		uint32_t lErrno = mysql_errno(_con);
		if (!manageException(lErrno))
		{
			ret = false;
			return nullptr;
		}
	}
	ret = true;
	auto result = std::make_unique<QueryResult>(mysql_store_result(_con));
	result->setInsertedID(mysql_insert_id(_con));

	return result;
}

void MySQLConnWrapper::DirectExecute(const std::string& query)
{
	if (!_con)
	{
		LOG_FATAL << "Connection not setup.";
		return;
	}
	if (mysql_query(_con, query.c_str()))
	{
		LOG_ERROR << "SQL causing error: " << query;
		// If it returns true, an error was handled successfully (i.e. reconnection)
		uint32_t lErrno = mysql_errno(_con);
		if (!manageException(lErrno))
			return;
	}
}

/*void MySQLConnWrapper::RealExecuteQuery(const std::string sqlQuery, boost::function<void(std::shared_ptr<QueryResult>)> callBack)
{
	if (!_con)
	{
		LOG_FATAL << "Connection not setup.";
		if (callBack)
			callBack(nullptr);
		return;
	}
	if (mysql_query(_con, sqlQuery.c_str()))
	{
		LOG_ERROR << "SQL causing error: " << sqlQuery;
		// If it returns true, an error was handled successfully (i.e. reconnection)
		uint32_t lErrno = mysql_errno(_con);
		if (manageException(lErrno))
			return DirectExecute(sqlQuery); // Try again

		if (callBack)
			callBack(nullptr);
	}
	auto result = std::make_shared<QueryResult>(mysql_store_result(_con));
	if (result && result.get())
		result->setInsertedID(mysql_insert_id(_con));
	// callback
	if (callBack)
		callBack(result);
}

void MySQLConnWrapper::ExecuteQuery(const std::string sqlQuery, boost::function<void(std::shared_ptr<QueryResult>)> callBack)
{
	if (!_con)
	{
		LOG_FATAL << "Connection not setup.";
		if (callBack)
			callBack(nullptr);
	}
	_queue.push(std::move(new QueryToExecute(sqlQuery, callBack)));
}
void MySQLConnWrapper::ExecuteQuery(const std::string sqlQuery)
{
	if (!_con)
	{
		LOG_FATAL << "Connection not setup.";
		return;
	}
	_queue.push(std::move(new QueryToExecute(sqlQuery, [](std::shared_ptr<QueryResult>)
	{
	})));
}

void MySQLConnWrapper::run()
{
	_running = true;
	while (_running)
	{
		if (_queue.size() > 0)
			DoWork();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}
void MySQLConnWrapper::DoWork()
{
	QueryToExecute *query;
	if (_queue.try_pop(query))
	{
		if (query)
		{
			RealExecuteQuery(query->_query, query->_callback);
			delete query;
		}
	}
}*/