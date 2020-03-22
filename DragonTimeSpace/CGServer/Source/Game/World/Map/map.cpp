#include "map.h"
#include "Helper/VisibilityManager.h"
#include "../Object/Object.h"
#include "../World.h"

#include <Tables/TableContainer.h>

constexpr uint32_t DBO_UPDATE_TIME_IN_MILLI = 50;

Map::Map(const std::string& json_file, const uint32_t& mapid, boost::asio::io_context& io)
	: _mapid{ mapid }
	, info{ new Map::map_info() }
	, _visibility_manager{std::make_unique<VisibilityManager>()}
	, map_strand{ io }
	, map_timer(io, boost::posix_time::milliseconds(DBO_UPDATE_TIME_IN_MILLI))
	, _pendingDelete{ false }
{
	load_maps(json_file);
	LOG_DEBUG << json_file << " Map id: " << _mapid << " loaded, npc: " << info->_npc.size();

	auto npc_table = sTBL.get_table<pb::npc_data>();
	for (auto& npc : npc_table.datas())
	{
		for (auto& c : info->_npc)
		{
			if (c.id == npc.tbxid())
			{
				msg::MapDataType obj_type = msg::MapDataType::MAP_DATATYPE_NPC;
				const uint32_t id = c.id;
				const uint32_t temp_id = sWorld.AcquireSerialId();
				const Position pos = Position(c.x, c.y, c.dir);
				const Health health = Health(npc.maxhp(), npc.maxhp());
				add_to_map(std::make_shared<Entity>(id, temp_id, pos, health));
			}
		}
	}
	// TODO: delete later when we are done with the proximity spawn
	//delete info;
	//info = nullptr;

	map_timer.async_wait(map_strand.wrap(boost::bind(&Map::Update, this)));
}
Map::~Map()
{
	_pendingDelete = true;
	map_timer.cancel();
	map_timer.wait();

	if (info)
	{
		delete info;
		info = nullptr;
	}
}

void Map::add_to_map(std::shared_ptr<Object> what)
{
	map_strand.post([this, what]
	{
		auto it = std::find(_objects.cbegin(), _objects.cend(), what);
		if (it != _objects.end())
		{
			LOG_ERROR << "Object already in map";
		}
		else
		{
			_objects.emplace_back(what);
			_visibility_manager->Add(what.get());
		}
	});
	
}
void Map::remove_from_map(std::shared_ptr<Object> what)
{
	map_strand.post([this, what]
	{
		auto it = std::find(_objects.cbegin(), _objects.cend(), what);
		if (it != _objects.end())
		{
			_objects.erase(it);
			_visibility_manager->Remove(what.get());
		}
		else
		{
			LOG_ERROR << "Object not in map";
		}
	});
}

//update map
void Map::Update()
{
	if (_pendingDelete)
		return;

	update_visibility();

	// Sheldule next update
	map_timer.expires_at(map_timer.expires_at() + boost::posix_time::milliseconds(DBO_UPDATE_TIME_IN_MILLI));
	map_timer.async_wait(map_strand.wrap(boost::bind(&Map::Update, this)));
}

void Map::update_visibility()
{
	for (auto& entity : _objects)
	{
		_visibility_manager->Update(entity.get());
	}
}

//return shared object, by temp_id or nullptr if inexisting, this function is only safe when called from GetMap().strand (update function too)
std::shared_ptr<Object> Map::get_object_by_id(const uint32_t& id)
{
	for (auto& obj : _objects)
	{
		if (obj->get_id() == id)
		{
			return obj->shared_from_this();
		}
	}
	return nullptr;
}

//return shared object, by id or nullptr if inexisting, this function is only safe from when called from GetMap().strand (update function too)
std::shared_ptr<Object> Map::get_object_by_temp_id(const uint32_t& temp_id)
{
	for (auto& obj : _objects)
	{
		if (obj->get_temp_id() == temp_id)
		{
			return obj->shared_from_this();
		}
	}
	return nullptr;
}

void Map::fill_npc(const Json::Value& npc, Map::map_info& info)
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
		Map::map_info::npc _npc_struct;

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

void Map::fill_on_zone_script(const Json::Value& on_zone_script, Map::map_info& info)
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
		Map::map_info::on_zone_script _on_zone_script_struct;

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

void Map::load_maps(const std::string& raw_file)
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

	fill_npc(npc, *info);
	fill_on_zone_script(on_zone_script, *info);
}