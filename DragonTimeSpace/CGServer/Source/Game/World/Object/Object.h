#pragma once

#include <Utils/Define.h>

class Position
{
public:
	explicit Position(const float& x, const float& y, const int32_t& dir) noexcept
	{
		set_position(x, y);
		set_rotation(dir);
	}
	const float& get_position_x() const { return _x; }
	const float& get_position_y() const { return _y; }
	const void get_position(float& x, float& y) const { x = _x; y = _y; }
	const int32_t get_dir() const { return _dir; }
	const void get_dir(int32_t& dir) { dir = _dir; }

	void set_position(const float& x, const float& y) { _x = x; _y = y; }
	void set_rotation(const int32_t& dir) { _dir = dir; }
private:
	float _x, _y;
	int32_t _dir;
};

class Health
{
public:
	explicit Health(const uint32_t& max, const uint32_t& cur) noexcept
	{
		set_max_cur_health(max, cur);
	}
	const uint32_t& get_max_health() const { return _max_hp; }
	const uint32_t& get_cur_health() const { return _cur_hp; }

	void set_max_cur_health(const uint32_t& max, const uint32_t& cur) { _max_hp = max; _cur_hp = cur; }
	void set_cur_health(const uint32_t& cur) { _cur_hp = cur; }
private:
	uint32_t _max_hp, _cur_hp;
};

class Object
{
public:
	enum class ObjectType
	{
		OBJECT = 0,
		NPC,
		PLAYER,
	};
public:
	explicit Object(const ObjectType& obj_type, const uint32_t& id, const Position& pos) noexcept
		: _position{ pos.get_position_x(), pos.get_position_x(), pos.get_dir() }
		, _obj_type{ obj_type }
		, _id{ id }
	{
	}

	// -- CONST GETTER
	const Position& get_position() const { return _position; }
	const ObjectType& get_object_type() const { return _obj_type; }
	const uint32_t& get_id() const { return _id; }

	// GETTER EDITABLE
	Position& get_position() { return _position; }
	ObjectType& get_object_type() { return _obj_type; }
	uint32_t& get_id() { return _id; }

private:
	Position		_position;
	ObjectType		_obj_type;
	uint32_t		_id;
};

class Entity : public Object
{
public:
	explicit Entity(const uint32_t& id, const Position& pos, const Health& health) noexcept
		: Object{ Object::ObjectType::NPC, id, pos }
		, _health{ health.get_max_health(), health.get_cur_health() }
	{
	}

	// -- CONST GETTER
	const Object& get_object() const { return (Object)*this; }
	const Health& get_health() const { return _health; }

	// GETTER EDITABLE
	Object& get_object() { return (Object)*this; }
	Health& get_health() { return _health; }

private:
	Health			_health;
};