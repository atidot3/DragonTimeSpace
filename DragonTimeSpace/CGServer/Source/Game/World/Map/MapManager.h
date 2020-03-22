#pragma once

#include <Utils/Define.h>
#include "map.h"

class MapManager
{
private:
	MapManager(io_context_pool& pool);
	~MapManager();

	void load();
public:
	//----------------------------------------
//	Map Manager Singleton
//----------------------------------------
	static MapManager& instance();
	void Destruct();
	void Initialize(io_context_pool& pool);

	Map* get_map(const uint32_t& id) const;
private:
	io_context_pool& _pool;
	std::map<uint32_t, std::unique_ptr<Map>> _maps;
};

#define sMapMgr MapManager::instance()