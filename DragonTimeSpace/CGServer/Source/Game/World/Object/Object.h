#pragma once

#include <Utils/Define.h>

// -- refer to npc_data => 'kind'
enum NpcType
{
	NPC_TYPE_NONE,
	NPC_TYPE_VISIT,
	NPC_TYPE_NOACTIVE,
	NPC_TYPE_ACTIVE,
	NPC_TYPE_MONSTER,
	NPC_TYPE_BOSS,
	NPC_TYPE_GATHER,
	NPC_TYPE_BUILDING,
	NPC_TYPE_HOLDON,
	NPC_TYPE_TRAP,
	NPC_TYPE_SUMMONPET,
	NPC_TYPE_QUESTGATHER,
	NPC_TYPE_BLOCK_LOCK,
	NPC_TYPE_NOBLOCK_LOCK,
	NPC_TYPE_MECHANISM,
	NPC_TYPE_DYN_BUILDING,
	NPC_TYPE_HERO,
	NPC_TYPE_ASSIST,
	NPC_TYPE_SUMMON_ASSIST,
	NPC_TYPE_PICK_UP,
	NPC_TYPE_OBJ_BAG,
	NPC_TYPE_OBJ_RUN_QUEST,
	NPC_TYPE_NOACTSKILL,
	NPC_TYPE_TEAMEFFECT,
	NPC_TYPE_DRAGONBALL,
	NPC_TYPE_MASTERCOPY,
	NPC_TYPE_MOBAPK_BOSS,
	NPC_TYPE_MOBAPK_NORMAL,
	NPC_TYPE_SPECIAL_VISIT = 999
};


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

class Object : public std::enable_shared_from_this<Object>
{
public:
	explicit Object(const msg::MapDataType& obj_type, const uint32_t& id, const uint32_t& temp_id, const Position& pos, const uint32_t& map_id) noexcept
		: _position{ pos.get_position_x(), pos.get_position_x(), pos.get_dir() }
		, _obj_type{ obj_type }
		, _id{ id }
		, _temp_id{ temp_id }
		, _map_id{ map_id }
	{
	}

	// -- CONST GETTER
	const Position& get_position() const { return _position; }
	const msg::MapDataType& get_object_type() const { return _obj_type; }
	const uint32_t& get_id() const { return _id; }
	const uint32_t& get_temp_id() const { return _temp_id; }
	const uint32_t& get_map_id() const { return _map_id; }
	// GETTER EDITABLE
	Position& get_position() { return _position; }
	msg::MapDataType& get_object_type() { return _obj_type; }

	// -- SETTER
	void set_position(const Position& pos) { _position = pos; }
	void set_map_id(const uint32_t& map_id) { _map_id = map_id; }
protected:
	Position			_position;
	msg::MapDataType	_obj_type;
	const uint32_t		_id;
	const uint32_t		_temp_id;
	uint32_t			_map_id;
};

class Entity : public Object
{
public:
	explicit Entity(const uint32_t& id, const uint32_t& temp_id, const Position& pos, const Health& health, const uint32_t& map_id) noexcept
		: Object{ msg::MapDataType::MAP_DATATYPE_NPC, id, temp_id, pos, map_id }
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
	std::string		_name;
};