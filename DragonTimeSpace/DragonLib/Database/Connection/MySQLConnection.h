#pragma once

#include <memory>
#include <string>

#include <mysql.h>

class MySQLConnection : public std::enable_shared_from_this<MySQLConnection>
{
public:
	MySQLConnection();
	~MySQLConnection();

	bool connect(const std::string& host, const std::string& user, const std::string& password, const std::string& database);

	void Ping();

	bool SetAutoCommit(bool val);
	bool Rollback();
	bool Commit();

private:
	void manageException();
private:
	std::unique_ptr<MYSQL> con;
};