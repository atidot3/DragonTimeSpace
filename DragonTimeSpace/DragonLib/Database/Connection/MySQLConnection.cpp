#include "MySQLConnection.h"

#include <Utils/Logger/Logger.h>

MySQLConnection::MySQLConnection()
{
	con.reset(mysql_init(NULL));
	if (con == nullptr)
	{
		LOG_FATAL << "#ERR : " << std::string(mysql_error(con.get()));
	}
	else
	{
		unsigned int readTimeout = 30;
		unsigned int writeTimeout = 30;
		unsigned int connectionTimeout = 30;
		if (mysql_options(con.get(), MYSQL_OPT_READ_TIMEOUT, &readTimeout) ||
			mysql_options(con.get(), MYSQL_OPT_WRITE_TIMEOUT, &writeTimeout) ||
			mysql_options(con.get(), MYSQL_OPT_CONNECT_TIMEOUT, &connectionTimeout))
		{
			throw std::runtime_error("Unable to set mysql options.");
		}
	}
}

MySQLConnection::~MySQLConnection()
{
	mysql_close(con.get());
}

void MySQLConnection::manageException()
{
	if (con.get() != nullptr)
	{
		LOG_FATAL << "Server status [" << std::to_string(con.get()->server_status) << "] Normal status [" << std::to_string(con.get()->status) << "]";
		LOG_FATAL << "#ERR: " << std::string(mysql_error(con.get()));
	}
}

bool MySQLConnection::connect(const std::string& host, const std::string& user, const std::string& password, const std::string& database)
{
	if (mysql_real_connect(con.get(), host.c_str(), user.c_str(), password.c_str(),
		database.c_str(), 3306, NULL, 0) == nullptr)
	{
		manageException();
		return false;
	}

	LOG_INFO << "Connected to MySQL database " << user << "@" << host << ":" << database;
	LOG_INFO << "MySQL client library: " << std::string(mysql_get_client_info());
	LOG_INFO << "MySQL server ver: " << std::string(mysql_get_server_info(con.get()));
	return true;
}

void MySQLConnection::Ping()
{
	if (con.get())
		mysql_ping(con.get());
}

bool MySQLConnection::SetAutoCommit(bool val)
{
	if (mysql_autocommit(con.get(), val))
	{
		manageException();
		return false;
	}
	return true;
}
bool MySQLConnection::Rollback()
{
	if (mysql_rollback(con.get()))
	{
		manageException();
		return false;
	}
	return true;
}
bool MySQLConnection::Commit()
{
	if (mysql_commit(con.get()))
	{
		manageException();
		return false;
	}
	return true;
}