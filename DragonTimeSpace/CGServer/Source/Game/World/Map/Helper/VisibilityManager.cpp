#include "VisibilityManager.h"
#include "../../Object/Object.h"
#include "../../Object/Entity/Npc/Npc.h"
#include "../../Object/Entity/Player/Player.h"

#include <Network/Packet/ProtobufPacket.h>

using object_vect_t = std::vector<const Object*>;

//send spawn packets for objects
static void sendCreatePacketsFor(const Object* receiver, const Object* sender)
{
	Player* plr = (Player*)receiver;

	if (sender->get_object_type() == msg::MapDataType::MAP_DATATYPE_NPC)
	{
		sender->compose_spawn_packet(plr);
	}
}

//send destroy packets for objects
static void sendDestroyPacketsFor(const Object* receiver, const Object* sender)
{
	Player* plr = (Player*)receiver;

	if (sender->get_object_type() == msg::MapDataType::MAP_DATATYPE_NPC)
	{
		auto remove = ProtobufPacket<msg::MSG_Ret_MapScreenBatchRemoveNpc_SC>(CommandID::Ret_MapScreenBatchRemoveNpc_SC);
		{
			remove.get_protobuff().add_tempids(sender->get_temp_id());
		}
		remove.compute();
		plr->SendPacket(remove.get_buffer());
	}
}

void VisibilityManager::ManageCreate(const Object* source, object_vect_t curSet)
{
	if (curSet.size() == 0)
		return;

	Player* plr = (Player*)source;
	auto npcs = ProtobufPacket<msg::MSG_Ret_MapScreenBatchRefreshNpc_SC>(CommandID::Ret_MapScreenBatchRefreshNpc_SC);
	auto func_npc = ProtobufPacket<msg::MSG_Ret_MapScreenFuncNpc_SC>(CommandID::Ret_MapScreenFuncNpc_SC);

	for (auto& it : curSet)
	{
		if (it->get_object_type() == msg::MapDataType::MAP_DATATYPE_NPC)
		{
			((Npc*)it)->compose_spawn_packet(npcs, func_npc);
		}
		// -- build packet here ?
		//sendCreatePacketsFor(source, it);
		_visibilityMap[it].emplace(source);
	}

	npcs.compute();
	func_npc.compute();

	plr->SendPacket(npcs.get_buffer());
	plr->SendPacket(func_npc.get_buffer());
}
void VisibilityManager::ManageDelete(const Object* source, object_vect_t curSet)
{
	for (auto& it : curSet)
	{
		// -- build packet here ?

		sendDestroyPacketsFor(source, it);
		_visibilityMap[it].erase(source);
	}
}

//send create packets for objects at first login on map AddPlayer ONLY
void VisibilityManager::Add(const Object* object)
{
	object_set_t curSet;
	_visibilityMap[object] = curSet;
}

float get_distance(float fPositionX1, float fPositionY1, float fPositionX2, float fPositionY2)
{
	double val = sqrt((fPositionX1 - fPositionX2) * (fPositionX1 - fPositionX2) + (fPositionY1 - fPositionY2) * (fPositionY1 - fPositionY2));
	val = floor(val);
	return static_cast<float>(val);
}

void VisibilityManager::Update(const Object* object)
{
	if (object->get_object_type() != msg::MapDataType::MAP_DATATYPE_USER)
		return;
	//get existing visible entity set
	object_set_t& oldSet = _visibilityMap[object];

	//get entities currently in VIEW_DISTANCE range of 'player'
	object_set_t curSet;
	
	// -- check distance based
	const auto _plr_position = object->get_position();
	for (auto& entity : _visibilityMap)
	{
		if (entity.first != object)
		{
			const auto _position = entity.first->get_position();
			const auto distance = get_distance(_position.get_position_x(), _position.get_position_y(), _plr_position.get_position_x(), _plr_position.get_position_y());
			
			// -- a bit ugly
			Npc* npc = nullptr;
			if (entity.first->get_object_type() == msg::MapDataType::MAP_DATATYPE_NPC)
				npc = (Npc*)entity.first;

			if (distance <= 500 || (npc && npc->get_npc_type() == NpcType::NPC_TYPE_VISIT))
			{
				curSet.emplace(entity.first);
			}
		}
	}
	//get & remove missing entities
	object_vect_t destroyList;
	std::set_difference(oldSet.cbegin(), oldSet.cend(), curSet.cbegin(), curSet.cend(), std::back_inserter(destroyList));

	ManageDelete(object, destroyList);
	//get & add new entities
	object_vect_t createList;
	std::set_difference(curSet.cbegin(), curSet.cend(), oldSet.cbegin(), oldSet.cend(), std::back_inserter(createList));

	ManageCreate(object, createList);

	//store current visible entities
	_visibilityMap[object] = curSet;
}

void VisibilityManager::Remove(const Object* object)
{
	//send destroy to all other players
	for (auto& it : _visibilityMap[object])
	{
		_visibilityMap[it].erase(object);
	}
	_visibilityMap.erase(object);
}