#pragma once

#include <Utils/Define.h>
#include <Utils/Logger/Logger.h>
#include <Configuration/Configuration.h>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include <vector>
#include <map>

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

class Map
{
public:
	Map(const std::string& json_file)
	{

	}
	~Map()
	{

	}

private:
	uint32_t _mapid;
};

class MapManager
{
public:
	MapManager()
	{
		// -- Load master json from devin that contains maps id + filename
		// -- This file is called mapinfo.json in the root data directory. 
		// -- I have added to the gateway json config file to find it from GetMapConfigJsonData
		// -- this is only for preparing struct and read code for each map
		boost::filesystem::path p(sConfig.GetServerMapJsonData());

		if (boost::filesystem::is_directory(p))
		{
			std::vector<boost::filesystem::directory_entry> v; // To save the file names in a vector.
			std::copy(boost::filesystem::directory_iterator(p), boost::filesystem::directory_iterator(), std::back_inserter(v));
			std::cout << p << " is a directory containing:\n";

			for (std::vector<boost::filesystem::directory_entry>::const_iterator it = v.begin(); it != v.end(); ++it)
			{
				if ((*it).path().extension().string() == ".json")
					load_maps((*it).path().string());
			}
		}
		//This will eventually need reworked for all configs - San
		//load_mapconfig(sConfig.GetMapConfigJsonData());
		LOG_DEBUG << "All map_json loaded.";
	}
	~MapManager()
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

		LOG_DEBUG << "ok";
	}
private:
	map_info info;
	std::map<uint32_t, Map> _maps;
};