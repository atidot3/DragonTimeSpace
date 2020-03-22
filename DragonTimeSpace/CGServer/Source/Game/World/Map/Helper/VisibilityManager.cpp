#include "VisibilityManager.h"
#include "../../Object/Object.h"

using object_vect_t = std::vector<const Object*>;

//send spawn packets for objects
static void sendCreatePacketsFor(const Object* object, const Object* obj)
{
}

//send destroy packets for objects
static void sendDestroyPacketsFor(const Object* object, const Object* obj)
{

}

void VisibilityManager::ManageCreate(const Object* source, object_vect_t curSet)
{
	for (auto& it : curSet)
	{
		// -- build packet here ?
		_visibilityMap[it].emplace(source);
	}
}
void VisibilityManager::ManageDelete(const Object* source, object_vect_t curSet)
{
	for (auto& it : curSet)
	{
		// -- build packet here ?
		_visibilityMap[it].erase(source);
	}
}

//send create packets for objects at first login on map AddPlayer ONLY
void VisibilityManager::Add(const Object* object)
{
	object_set_t curSet;
	_visibilityMap[object] = curSet;
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
			const auto distance = sqrt(pow(_position.get_position_x() - _plr_position.get_position_x(), 2) +
				pow(_position.get_position_y() - _plr_position.get_position_y(), 2) * 1.0);

			if (distance <= 100)
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