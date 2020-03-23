#pragma once

#include <Utils/Define.h>
#include <Network/Packet/ProtobufPacket.h>
#include <Tables/Definitions/npc_data.pb.h>

#include "../Entity.h"

class Npc : public Entity
{
public:
	Npc(const uint32_t& x, const uint32_t& y, const uint32_t& dir, const pb::npc_data_t_npc_config& data, const uint32_t& mapid);
	~Npc();

	void compose_spawn_packet(ProtobufPacket<msg::MSG_Ret_MapScreenBatchRefreshNpc_SC>& npc_data, ProtobufPacket<msg::MSG_Ret_MapScreenFuncNpc_SC>& npc_func) const;
	const uint32_t get_respawn_time_left() const;
	const NpcType& get_npc_type() const;
private:
	uint32_t _respawn_timer;
	NpcType	_npc_type;
	std::string _npc_function;
};