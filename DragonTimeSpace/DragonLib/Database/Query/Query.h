#ifndef _QUERY_H_
#define _QUERY_H_

#pragma once

#include <string>
#include <chrono>

class Query final
{
public:
	Query(const std::string sql);
	~Query();

	void setSQL(const std::string sql);

	// TODO : template this, its pretty messed
	void setValue(const std::string val);
	void setValue(const char* val);

	void setValue(const int val);
	void setValue(const bool val);
	void setValue(const float val);
	void setValue(const double val);

	void setValue(const uint64_t val);
	void setValue(const uint32_t val);
	void setValue(const uint16_t val);
	void setValue(const uint8_t val);

	const std::string GetQuery() const;
	void Append(const std::string val);
	void ReplaceLastCharacters();
private:
	int GetPosition(const int index);
private:
	std::string _sql;
};

#endif //_QUERY_H_