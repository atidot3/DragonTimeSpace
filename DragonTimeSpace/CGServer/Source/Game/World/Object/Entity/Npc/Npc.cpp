#include "Npc.h"

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
uint64_t GenernateBuffHash(uint64_t entryID, uint64_t userState, uint64_t entrytype, uint64_t uniqueID)
{
	return (userState & 65535UL) << 48 | (uniqueID & 255UL) << 40 | (entrytype & 255UL) << 32 | (entryID & (uint64_t)-1);
}

MessageBuffer Npc::compose_spawn_packet() const
{

	ProtobufPacket<msg::MSG_Ret_MapScreenRefreshNpc_SC> npc_refresh(CommandID::Ret_MapScreenRefreshNpc_SC);
	{
		msg::MapNpcData* data = new msg::MapNpcData();
		{
			msg::FloatMovePos* pos = new msg::FloatMovePos();
			{
				pos->set_fx(get_position().get_position_x());
				pos->set_fy(get_position().get_position_y());
			}
			msg::EntryIDType* myType = new msg::EntryIDType();
			{
				myType->set_id(get_id());
				myType->set_type(msg::MapDataType::MAP_DATATYPE_NPC);
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
				// -- what am i doing
				//if (is_ou_npc.hatred_distance() > 0)
				//{
					//list->add_enemytempid(is_ou_npc.id());
				//}
				//else
				//{
				list->set_npctempid(get_temp_id());
				//}
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
			//auto it = data->add_states();		
			//it->set_uniqid(GenernateBuffHash(get_temp_id(), 6, 1, get_temp_id()));
		}
		npc_refresh.get_protobuff().set_allocated_data(data);
		npc_refresh.compute();
	}
	return MessageBuffer(npc_refresh.get_buffer());
}
