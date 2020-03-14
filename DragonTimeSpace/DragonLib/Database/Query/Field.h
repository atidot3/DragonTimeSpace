#pragma once

#include <string>
#include <iostream>
#include <sstream>

class Field final
{
public:
	Field() = delete;
	Field(const char* value)
		: mValue{ value }
	{
	}
	~Field()
	{
	}

	bool IsNULL() const
	{
		return mValue == nullptr;
	}
	std::string GetString() const
	{
		return mValue ? mValue : "";
	}

	// TODO : template this, its pretty messed
	int32_t getInt() const
	{
		return mValue ? static_cast<int32_t>(atol(mValue)) : int32_t(0);
	}
	int64_t getInt64() const
	{
		return mValue ? static_cast<int64_t>(atol(mValue)) : int64_t(0);
	}
	uint32_t getUInt() const
	{
		return mValue ? static_cast<uint32_t>(atol(mValue)) : uint32_t(0);
	}
	uint64_t getUInt64() const
	{
		char * pEnd;
		// 0 is the base see http://www.cplusplus.com/reference/cstdlib/strtol/
		return strtoull(mValue, &pEnd, 0);
	}
	float getFloat() const
	{
		return mValue ? static_cast<float>(atof(mValue)) : float(0);
	}
	double getDouble() const
	{
		return mValue ? static_cast<double>(atof(mValue)) : double(0);
	}
	const std::string getString() const
	{
		return mValue ? mValue : "";
	}
	bool getBoolean() const
	{
		return mValue ? static_cast<bool>(atol(mValue)) : bool(0);
	}
	unsigned char getByte() const
	{
		return mValue ? static_cast<unsigned char>(atol(mValue)) : 0;
	}
private:
	const char* mValue;
};