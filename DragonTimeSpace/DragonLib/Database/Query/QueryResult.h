#ifndef _QUERYRESULT_H_
#define _QUERYRESULT_H_

#pragma once

#include "Field.h"

#include <mysql/mysql.h>
#include <memory>
#include <list>
#include <map>
#include <string_view>

class QueryResult final
{
public:
	QueryResult(MYSQL_RES* res);
	~QueryResult();

	uint32_t rowsCount() const;
	uint32_t fieldCount() const;
	bool next();

	int32_t getInt(const std::string_view& column) const;
	int64_t getInt64(const std::string_view& column) const;
	uint32_t getUInt(const std::string_view& column) const;
	uint64_t getUInt64(const std::string_view& column) const;
	float getFloat(const std::string_view& column) const;
	double getDouble(const std::string_view& column) const;
	const std::string getString(const std::string_view& column) const;
	bool getBoolean(const std::string_view& column) const;
	unsigned char getByte(const std::string_view& column) const;
	int getInsertedID() const;
	unsigned int getCount() const;

	void setInsertedID(const my_ulonglong& id);
private:
	const Field* get(const std::string_view column)const;
private:
	MYSQL_RES*						_resultStorage;
	std::map<std::string, Field>	_records;
	std::map<std::string, int>		_field;

	my_ulonglong					_insertedID;
};

#endif //_QUERYRESULT_H_
