#pragma once

#include <map>
#include <list>
#include <set>
#include <vector>
#include <memory>

#include <Utils/Define.h>

#define MAX_VIEW_DISTANCE 150

//fwd decl
class Object;
class Player;

//Manage entities visibility by players
class VisibilityManager
{
public:

	void Update(const Object* object);
	void Remove(const Object* object);
	void Add(const Object* object);
private:
	void ManageCreate(const Object* source, std::vector<const Object*> curSet);
	void ManageDelete(const Object* source, std::vector<const Object*> curSet);
private:
	using object_set_t = std::set<const Object*>;
	using visibility_map_t = std::map<const Object*, object_set_t>;
	visibility_map_t _visibilityMap;
};