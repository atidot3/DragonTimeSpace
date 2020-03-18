#pragma once

#include <Utils/Define.h>
#include <Utils/Logger/Logger.h>

#include <Network/io_context_pool.h>

#include <Configuration/Configuration.h>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include <vector>
#include <map>

class Map
{
	struct map_info
	{
		struct npc
		{
			int32_t id;
			int32_t x;
			int32_t y;
			int32_t num;
			int32_t interval;
			int32_t dir;
		};
		struct on_zone_script
		{
			int32_t questid;
			int32_t zoneid;
			int32_t x;
			int32_t y;
			int32_t width;
			int32_t height;
			int32_t zonecheckquest;
		};
		struct zonedef
		{
			int32_t width;
			int32_t height;
			int32_t x;
			int32_t y;
			int32_t type;
			int32_t UniqueID;
			int32_t id;
			int32_t num;
			int32_t userdir;
		};
		struct other
		{
			int32_t default_pkmode;
		};

		std::vector<npc> _npc;
		std::vector<on_zone_script> _on_zone_script;
		std::vector<zonedef> _zonedef;
		std::vector<other> _other;
	};
public:
	Map(const std::string& json_file, const uint32_t& mapid)
		: _mapid{ mapid }
	{
		load_maps(json_file);
		LOG_DEBUG << json_file << " Map id: " << _mapid << " laoded, npc: " << info._npc.size();
	}
	~Map()
	{

	}
	void fill_npc(const Json::Value& npc, map_info& info)
	{
		if (npc.isNull())
			return;

		if (!npc.isObject())
		{
			for (auto& it : npc)
			{
				fill_npc(it, info);
			}
		}
		else
		{
			map_info::npc _npc_struct;

			if (!npc["dir"].isNull())
				_npc_struct.dir = std::stoi(npc["dir"].asString());

			if (!npc["id"].isNull())
				_npc_struct.id = std::stoi(npc["id"].asString());

			if (!npc["interval"].isNull())
				_npc_struct.interval = std::stoi(npc["interval"].asString());

			if (!npc["num"].isNull())
				_npc_struct.num = std::stoi(npc["num"].asString());

			if (!npc["x"].isNull())
				_npc_struct.x = std::stoi(npc["x"].asString());

			if (!npc["y"].isNull())
				_npc_struct.y = std::stoi(npc["y"].asString());

			info._npc.emplace_back(std::move(_npc_struct));
		}
	}

	void fill_on_zone_script(const Json::Value& on_zone_script, map_info& info)
	{
		if (on_zone_script.isNull())
			return;
		if (!on_zone_script.isObject())
		{
			for (auto& it : on_zone_script)
			{
				fill_on_zone_script(it, info);
			}
		}
		else
		{
			map_info::on_zone_script _on_zone_script_struct;

			if (!on_zone_script["zoneid"].isNull())
				_on_zone_script_struct.zoneid = std::stoi(on_zone_script["zoneid"].asString());

			if (!on_zone_script["width"].isNull())
				_on_zone_script_struct.width = std::stoi(on_zone_script["width"].asString());

			if (!on_zone_script["height"].isNull())
				_on_zone_script_struct.height = std::stoi(on_zone_script["height"].asString());

			if (!on_zone_script["questid"].isNull())
				_on_zone_script_struct.questid = std::stoi(on_zone_script["questid"].asString());

			if (!on_zone_script["zonecheckquest"].isNull())
				_on_zone_script_struct.zonecheckquest = std::stoi(on_zone_script["zonecheckquest"].asString());

			if (!on_zone_script["x"].isNull())
				_on_zone_script_struct.x = std::stoi(on_zone_script["x"].asString());

			if (!on_zone_script["y"].isNull())
				_on_zone_script_struct.y = std::stoi(on_zone_script["y"].asString());

			info._on_zone_script.emplace_back(std::move(_on_zone_script_struct));
		}
	}

	void load_maps(const std::string& raw_file)
	{
		std::ifstream ifs(raw_file);
		if (!ifs.is_open())
		{
			throw std::runtime_error("Unable to load: " + raw_file + "\n");
		}
		Json::Reader reader;
		Json::Value obj;
		reader.parse(ifs, obj); // reader can also read strings

		const Json::Value& npc = obj["map"]["npc"];
		const Json::Value& on_zone_script = obj["map"]["on_zone_script"];

		fill_npc(npc, info);
		fill_on_zone_script(on_zone_script, info);
	}

	const map_info& get_map_info() { return info; }
	const uint32_t& get_map_id() { return _mapid; }
private:
	const uint32_t _mapid;
	map_info info;
};

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

	const Map& get_map(const uint32_t& id) const;
private:
	io_context_pool& _pool;
	std::map<uint32_t, Map> _maps;
};

#define sMapMgr MapManager::instance()