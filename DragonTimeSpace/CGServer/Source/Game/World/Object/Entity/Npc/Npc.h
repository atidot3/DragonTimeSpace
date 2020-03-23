#pragma once

#include <Utils/Define.h>
#include <Tables/Definitions/npc_data.pb.h>

#include "../Entity.h"

class Npc : public Entity
{
public:
	Npc(const uint32_t& x, const uint32_t& y, const uint32_t& dir, const pb::npc_data_t_npc_config& data, const uint32_t& mapid);
	~Npc();

	virtual MessageBuffer compose_spawn_packet() const override;
	const uint32_t get_respawn_time_left() const;
	const NpcType& get_npc_type() const;
private:
	uint32_t _respawn_timer;
	NpcType	_npc_type;
};