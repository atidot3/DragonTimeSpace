#include "QueryResult.h"

#include <cstring>
#include <map>
#include <algorithm>

QueryResult::QueryResult(MYSQL_RES* res)
	: _resultStorage{ res }
	, _insertedID { 0 }
{
	//read headers
	if (_resultStorage)
	{
		MYSQL_FIELD* field;
		for (unsigned int i = 0; (field = mysql_fetch_field(_resultStorage)); i++)
		{
			std::string lower = field->name;
			std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

			_field[lower] = i;
		}
	}
}
QueryResult::~QueryResult()
{
	if (_resultStorage != nullptr)
	{
		mysql_free_result(_resultStorage);
		_resultStorage = nullptr;
	}
}
bool QueryResult::next()
{
	if (!_resultStorage)
		return false;
	_records.clear();
	//read all datas
	MYSQL_ROW row = mysql_fetch_row(_resultStorage);
	if (!row)
	{
		return false;
	}
	for (auto& pair : _field)
	{
		_records.emplace(pair.first, row[pair.second]);
	}
	return true;
}
uint32_t QueryResult::rowsCount() const
{
	if (_resultStorage != nullptr)
		return static_cast<uint32_t>(mysql_num_rows(_resultStorage));
	return 0;
}
uint32_t QueryResult::fieldCount() const
{
	if (_resultStorage != nullptr)
		return mysql_num_fields(_resultStorage);
	return 0;
}
int32_t QueryResult::getInt(const std::string_view& column) const
{
	const Field* field = get(column);
	if (field)
		return field->getInt();
	throw std::runtime_error("Unknow field[: " + std::string(column) + "].\n");
}
int64_t QueryResult::getInt64(const std::string_view& column) const
{
	const Field* field = get(column);
	if (field)
		return field->getInt64();
	throw std::runtime_error("Unknow field[: " + std::string(column) + "].\n");
}
uint32_t QueryResult::getUInt(const std::string_view& column) const
{
	const Field* field = get(column);
	if (field)
		return field->getUInt();
	throw std::runtime_error("Unknow field[: " + std::string(column) + "].\n");
}
uint64_t QueryResult::getUInt64(const std::string_view& column) const
{
	const Field* field = get(column);
	if (field)
		return field->getUInt64();
	throw std::runtime_error("Unknow field[: " + std::string(column) + "].\n");
}
float QueryResult::getFloat(const std::string_view& column) const
{
	const Field* field = get(column);
	if (field)
		return field->getFloat();
	throw std::runtime_error("Unknow field[: " + std::string(column) + "].\n");
}
double QueryResult::getDouble(const std::string_view& column) const
{
	const Field* field = get(column);
	if (field)
		return field->getDouble();
	throw std::runtime_error("Unknow field[: " + std::string(column) + "].\n");
}
const std::string QueryResult::getString(const std::string_view& column) const
{
	const Field* field = get(column);
	if (field)
		return field->getString();
	throw std::runtime_error("Unknow field[: " + std::string(column) + "].\n");
}
bool QueryResult::getBoolean(const std::string_view& column) const
{
	const Field* field = get(column);
	if (field)
		return field->getBoolean();
	throw std::runtime_error("Unknow field[: " + std::string(column) + "].\n");
}
unsigned char QueryResult::getByte(const std::string_view& column) const
{
	const Field* field = get(column);
	if (field)
		return field->getByte();
	throw std::runtime_error("QueryResult: Unknow field[: " + std::string(column) + "].\n");
}
const Field* QueryResult::get(const std::string_view column) const
{
	std::string lower = column.data();
	std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

	auto it = _records.find(lower);
	if (it != _records.end())
	{
		return &it->second;
	}

	return nullptr;
}
int QueryResult::getInsertedID() const
{
	return static_cast<int>(_insertedID);
}
void QueryResult::setInsertedID(const my_ulonglong& id)
{
	_insertedID = id;
}
unsigned int QueryResult::getCount() const
{
	if (_resultStorage)
	{
		if (_resultStorage->fields)
		{
			return _resultStorage->fields->catalog_length;
		}
	}
	return 0;
}