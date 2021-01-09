#include "Npc.h"
#include "../Player/Player.h"

#include <Utils/Logger/Logger.h>
#include <Network/Buffer/MessageBuffer.h>
#include <Network/Packet/ProtobufPacket.h>

#include "../../../World.h"

Npc::Npc(const uint32_t& x, const uint32_t& y, const uint32_t& dir, const pb::npc_data_t_npc_config& data, const uint32_t& mapid)
	: Entity()
	, _respawn_timer{0}
{
	set_position(x, y, dir);
	update_health(data.maxhp());
	update_max_health(data.maxhp());
	set_map_id(mapid);
	set_id(data.tbxid());
	set_temp_id(sWorld.AcquireSerialId());
	set_name(data.name());
	_obj_type = msg::MapDataType::MAP_DATATYPE_NPC;
	_npc_type = (NpcType)data.kind();
	_npc_function = data.function();
}

Npc::~Npc()
{

}

const uint32_t Npc::get_respawn_time_left() const
{
	return _respawn_timer;
}

const NpcType& Npc::get_npc_type() const
{
	return _npc_type;
}

void Npc::compose_spawn_packet(ProtobufPacket<msg::MSG_Ret_MapScreenBatchRefreshNpc_SC>& npc_data, ProtobufPacket<msg::MSG_Ret_MapScreenFuncNpc_SC>& npc_func) const
{
	auto data = npc_data.get_protobuff().add_data();

	msg::FloatMovePos* pos = new msg::FloatMovePos();
	{
		pos->set_fx(get_position().get_position_x());
		pos->set_fy(get_position().get_position_y());
	}
	msg::EntryIDType* myType = new msg::EntryIDType();
	{
		myType->set_id(get_id());
		myType->set_type(_npc_type);
	}
	msg::MasterData* master = new msg::MasterData();
	{
		//master.set_country(1);
		//master.set_allocated_idtype(&myType);
		//master.set_name(std::move(std::string(is_ou_npc.name())));
		//master.set_teamid(0);
	}
	msg::CharacterMapShow* cmshow = new msg::CharacterMapShow();
	{
		//cmshow.set_avatarid(80);
		//cmshow.set_heroid(80);
		//cmshow.set_occupation(1);
	}
	msg::NPC_HatredList* list = new msg::NPC_HatredList();
	{
		if (_npc_type == NpcType::NPC_TYPE_BOSS || _npc_type == NpcType::NPC_TYPE_MOBAPK_BOSS || _npc_type == NpcType::NPC_TYPE_MOBAPK_NORMAL || 
			_npc_type == NpcType::NPC_TYPE_MONSTER)
			list->add_enemytempid(get_temp_id());
		else
			list->set_npctempid(get_temp_id());
	}
	data->set_tempid(get_temp_id());
	data->set_allocated_hatredlist(list);
	data->set_allocated_master(master);
	data->set_allocated_pos(pos);
	data->set_allocated_showdata(cmshow);
	data->set_attspeed(0);
	data->set_baseid(get_id());
	data->set_birth(false);
	data->set_dir(get_position().get_dir());
	data->set_hp(get_health().get_cur_health());
	data->set_maxhp(get_health().get_max_health());
	data->set_movespeed(0);
	data->set_name(get_name());
	//npcs->set_titlename();
	data->set_visit(0);
	auto it = data->add_states();		
	// -- state define if this npc is quest giver / finish etc
	it->set_uniqid(Entity::GenernateBuffHash(get_id(), Entity::USTATE_NOSTATE, _npc_type, get_temp_id()));

	if (_npc_function != "")
	{
		auto func_data = npc_func.get_protobuff().add_data();
		func_data->set_baseid(get_id());
		func_data->set_tempid(get_temp_id());
		func_data->set_x(get_position().get_position_x());
		func_data->set_y(get_position().get_position_y());
	}
}