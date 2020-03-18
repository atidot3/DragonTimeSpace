#include "map.h"

static MapManager* mapManager = nullptr;

//----------------------------------------
//	Map Manager Singleton
//----------------------------------------
MapManager& MapManager::instance()
{
	return *mapManager;
}

void MapManager::Destruct()
{
	if (mapManager)
	{
		delete mapManager;
		mapManager = nullptr;
	}
}

void MapManager::Initialize(io_context_pool& pool)
{
	if (!mapManager)
	{
		mapManager = new MapManager(pool);
	}
}

MapManager::MapManager(io_context_pool& pool)
	: _pool{ pool }
{
	load();
}
MapManager::~MapManager()
{
}

void MapManager::load()
{
	std::ifstream ifs(sConfig.GetMapConfigJsonData());
	if (!ifs.is_open())
	{
		throw std::runtime_error("Unable to load: " + sConfig.GetMapConfigJsonData() + "\n");
	}
	Json::Reader reader;
	Json::Value obj;
	reader.parse(ifs, obj); // reader can also read strings

	Json::Value& maplabel = obj["maplabel"];
	for (auto it = maplabel.begin(); it != maplabel.end(); ++it)
	{
	}
	Json::Value& mapinfo = obj["mapinfo"];
	for (auto it = mapinfo.begin(); it != mapinfo.end(); ++it)
	{
		Json::Value& map = *it;
		{
			if (map["fileName"].asString() != "")
			{
				try
				{
					const std::string filename(sConfig.GetServerMapJsonData() + map["fileName"].asString() + ".xml.json");
					const uint32_t mapid = std::stoul(map["mapID"].asString());
					_maps.emplace(mapid, std::move(Map(filename, mapid)));
				}
				catch (std::exception & e)
				{
					// -- file not found
					//LOG_DEBUG << e.what();
				}
			}
			else
			{
				//LOG_DEBUG << "Mapid: " << map["mapID"].asString() << " dont contain json file";
			}
		}
	}
}

const Map& MapManager::get_map(const uint32_t& id) const
{
	const auto map = _maps.find(id);
	//if (map == _maps.end())
		//return Map();
	return map->second;
}