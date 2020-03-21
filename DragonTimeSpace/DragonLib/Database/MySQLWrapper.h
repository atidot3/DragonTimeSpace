#ifndef _MYSQLWRAPPER_H_
#define _MYSQLWRAPPER_H_

#pragma once

#include <boost/move/unique_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/function.hpp>

#include <mysql.h>

#include "Query/Query.h"
#include "Query/QueryResult.h"

#include <Utils/SafeQueue/SafeQueue.h>

#include <mutex>
#include <thread>

class Query;
class MySQLConnWrapper final
{
	struct MySQLInfo
	{
		std::string _host;
		std::string _user;
		std::string _password;
		std::string _database;
	};
	/*struct QueryToExecute
	{
	public:
		QueryToExecute(){}
		QueryToExecute(std::string query, boost::function<void(std::shared_ptr<QueryResult>)> callback)
		{
			_query = query;
			_callback = callback;
		}
		std::string _query;
		boost::function<void(std::shared_ptr<QueryResult>)> _callback;
	};*/
public:
	static MySQLConnWrapper& instance();
	static void Destruct();
	static void Initialize();

	bool connect(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
	void Ping();
	MySQLConnWrapper();
	~MySQLConnWrapper();

	std::unique_ptr<QueryResult> ExecuteQuery(const std::string& sqlQuery, bool& ret);
	void DirectExecute(const std::string& sqlQuery);
	std::string EscapeString(const std::string& str);
private:
	bool manageException(uint32_t errNo, uint8_t attempts = 5);

	/* ASYNC REQUEST REMOVED */
	//void ExecuteQuery(const std::string sqlQuery, boost::function<void(std::shared_ptr<QueryResult>)> funct);
	//void ExecuteQuery(const std::string sqlQuery);
	//void DirectExecute(const std::string sqlQuery);
	//void RealExecuteQuery(const std::string sqlQuery, boost::function<void(std::shared_ptr<QueryResult>)> funct);
	//void run();
	//void DoWork();
private:
	MySQLInfo	_conInfo;
	MYSQL*		_con;
	bool		_reconnecting;

	//SafeQueue<QueryToExecute*> _queue;
	//std::thread _worker;
	//bool _running;
};

#define sDB MySQLConnWrapper::instance()

#endif //_MYSQLWRAPPER_H_