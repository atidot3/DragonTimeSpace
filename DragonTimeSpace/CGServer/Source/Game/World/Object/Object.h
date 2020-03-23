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
	Position() noexcept;
	explicit Position(const uint32_t& x, const uint32_t& y, const uint32_t& dir) noexcept;
	const float& get_position_x() const;
	const float& get_position_y() const;
	const void get_position(uint32_t& x, uint32_t& y) const;
	const int32_t get_dir() const;
	const void get_dir(int32_t& dir);

	void set_position(const uint32_t& x, const uint32_t& y);
	void set_rotation(const int32_t& dir);

private:
	uint32_t _x, _y;
	uint32_t _dir;
};

class MessageBuffer;
class Object : public std::enable_shared_from_this<Object>
{
public:
	Object();
	// -- CONST GETTER
	const Position& get_position() const;
	const msg::MapDataType& get_object_type() const;
	const uint32_t& get_id() const;
	const uint32_t& get_temp_id() const;
	const uint32_t& get_map_id() const;
	// GETTER EDITABLE
	Position& get_position();
	msg::MapDataType& get_object_type();

	// -- SETTER
	void set_position(const uint32_t& x, const uint32_t& y, const uint32_t& dir);
	void set_map_id(const uint32_t& map_id);
	void set_id(const uint32_t& id);
	void set_temp_id(const uint32_t& id);


protected:
	Position			_position;
	msg::MapDataType	_obj_type;
	uint32_t			_id;
	uint32_t			_temp_id;
	uint32_t			_map_id;
};
