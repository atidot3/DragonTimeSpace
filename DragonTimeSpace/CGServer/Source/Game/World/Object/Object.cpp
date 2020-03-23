#include "Object.h"

#include <Utils/Logger/Logger.h>
#include <Network/Buffer/MessageBuffer.h>

// --------------------- POSITION

Position::Position() noexcept
	: _x{ 0 }
	, _y{ 0 }
	, _dir{ 0 }
{
}

Position::Position(const uint32_t& x, const uint32_t& y, const uint32_t& dir) noexcept
	: _x{ x }
	, _y{ y }
	, _dir{ dir }
{
}

const float& Position::get_position_x() const
{
	return _x;
}

const float& Position::get_position_y() const
{
	return _y;
}

const void Position::get_position(uint32_t& x, uint32_t& y) const
{
	x = _x;
	y = _y;
}

const int32_t Position::get_dir() const
{
	return _dir;
}

const void Position::get_dir(int32_t& dir)
{
	dir = _dir;
}

void Position::set_position(const uint32_t& x, const uint32_t& y)
{
	_x = x;
	_y = y;
}

void Position::set_rotation(const int32_t& dir)
{
	_dir = dir;
}

// --------------------- OBJECT

Object::Object()
	: _position{}
	, _obj_type{}
	, _id{}
	, _temp_id{}
	, _map_id{}
{
}

const Position& Object::get_position() const
{
	return _position;
}

const msg::MapDataType& Object::get_object_type() const
{
	return _obj_type;
}

const uint32_t& Object::get_id() const
{
	return _id;
}

const uint32_t& Object::get_temp_id() const
{
	return _temp_id;
}

const uint32_t& Object::get_map_id() const
{
	return _map_id;
}

Position& Object::get_position()
{
	return _position;
}

msg::MapDataType& Object::get_object_type()
{
	return _obj_type;
}

void Object::set_position(const uint32_t& x, const uint32_t& y, const uint32_t& dir)
{
	_position.set_position(x, y);
	_position.set_rotation(dir);
}

void Object::set_map_id(const uint32_t& map_id)
{
	_map_id = map_id;
}

void Object::set_id(const uint32_t& id)
{
	_id = id;
}

void Object::set_temp_id(const uint32_t& temp_id)
{ 
	_temp_id = temp_id;
}
