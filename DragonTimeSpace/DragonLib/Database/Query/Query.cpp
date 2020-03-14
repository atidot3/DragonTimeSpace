#include "Query.h"

#include <Utils/Logger/Logger.h>

#include <iostream>
#include <string>

Query::Query(const std::string sql)
	: _sql{sql}
{
}
Query::~Query()
{
}
int Query::GetPosition(const int index)
{
	if (_sql == "")
		return -1;

	std::size_t pos = 0;
	int occurrence = 0;

	while (occurrence < index && pos != std::string::npos)
	{
		pos = _sql.find("?", pos);
		occurrence++;
	}
	return static_cast<int>(pos);
}
void Query::setValue(const std::string val)
{
	std::size_t pos = GetPosition(1);
	std::string tmp = _sql;

	// valid position
	if (pos != std::string::npos)
	{
		tmp.erase(pos, 1);
		tmp.insert(pos, val);

		_sql.assign(tmp);
	}
}
void Query::setValue(const char* val)
{
	std::size_t pos = GetPosition(1);
	std::string tmp = _sql;
	std::string value(val);

	// valid position
	if (pos != std::string::npos)
	{
		tmp.erase(pos, 1);
		tmp.insert(pos, value);

		_sql.assign(tmp);
	}
}
void Query::setValue(const int val)
{
	std::size_t pos = GetPosition(1);
	std::string tmp = _sql;

	std::string toStr = std::to_string(val);
	// valid position
	if (pos != std::string::npos)
	{
		tmp.erase(pos, 1);
		tmp.insert(pos, toStr);

		_sql.assign(tmp);
	}
}
void Query::setValue(const bool val)
{
	std::size_t pos = GetPosition(1);
	std::string tmp = _sql;

	std::string toStr = std::to_string(val);
	// valid position
	if (pos != std::string::npos)
	{
		tmp.erase(pos, 1);
		tmp.insert(pos, toStr);

		_sql.assign(tmp);
	}
}
void Query::setValue(const float val)
{
	std::size_t pos = GetPosition(1);
	std::string tmp = _sql;

	std::string toStr = std::to_string(val);
	// valid position
	if (pos != std::string::npos)
	{
		tmp.erase(pos, 1);
		tmp.insert(pos, toStr);

		_sql.assign(tmp);
	}
}
void Query::setValue(const double val)
{
	std::size_t pos = GetPosition(1);
	std::string tmp = _sql;

	std::string toStr = std::to_string(val);
	// valid position
	if (pos != std::string::npos)
	{
		tmp.erase(pos, 1);
		tmp.insert(pos, toStr);

		_sql.assign(tmp);
	}
}
void Query::setValue(const uint64_t val)
{
	std::size_t pos = GetPosition(1);
	std::string tmp = _sql;

	std::string toStr = std::to_string(val);
	// valid position
	if (pos != std::string::npos)
	{
		tmp.erase(pos, 1);
		tmp.insert(pos, toStr);

		_sql.assign(tmp);
	}
}
void Query::setValue(const uint32_t val)
{
	std::size_t pos = GetPosition(1);
	std::string tmp = _sql;

	std::string toStr = std::to_string(val);
	// valid position
	if (pos != std::string::npos)
	{
		tmp.erase(pos, 1);
		tmp.insert(pos, toStr);

		_sql.assign(tmp);
	}
}
void Query::setValue(const uint16_t val)
{
	std::size_t pos = GetPosition(1);
	std::string tmp = _sql;

	std::string toStr = std::to_string(val);
	// valid position
	if (pos != std::string::npos)
	{
		tmp.erase(pos, 1);
		tmp.insert(pos, toStr);

		_sql.assign(tmp);
	}
}
void Query::setValue(const uint8_t val)
{
	std::size_t pos = GetPosition(1);
	std::string tmp = _sql;

	std::string toStr = std::to_string(val);
	// valid position
	if (pos != std::string::npos)
	{
		tmp.erase(pos, 1);
		tmp.insert(pos, toStr);

		_sql.assign(tmp);
	}
}
const std::string Query::GetQuery() const
{
	return _sql;
}
void Query::setSQL(const std::string sql)
{
	_sql = sql;
}
void Query::Append(const std::string val)
{
	_sql.append(val);
}
void Query::ReplaceLastCharacters()
{
	_sql.replace(_sql.size() - 1, 1, ";");
}