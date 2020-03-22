#pragma once

#include <Utils/Define.h>
#include <Utils/Logger/Logger.h>

#include <Network/io_context_pool.h>

#include <Configuration/Configuration.h>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include <vector>
#include <map>

class Object;
class VisibilityManager;
class Map
{
public:
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
private:
	void fill_npc(const Json::Value& npc, Map::map_info& info);
	void fill_on_zone_script(const Json::Value& on_zone_script, Map::map_info& info);
	void load_maps(const std::string& raw_file);
	void update_visibility();
protected:
	virtual void Update();
public:
	Map(const std::string& json_file, const uint32_t& mapid, boost::asio::io_context& io);
	~Map();

	void add_to_map(std::shared_ptr<Object> what);
	void remove_from_map(std::shared_ptr<Object> what);
	// -- getter
	const Map::map_info& get_map_info() const { return *info; }
	const uint32_t& get_map_id() const { return _mapid; }
	std::shared_ptr<Object> get_object_by_id(const uint32_t& id);
	std::shared_ptr<Object> get_object_by_temp_id(const uint32_t& temp_id);
	// Get strand, used to do safe async method
	boost::asio::io_context::strand& GetStrand() { return map_strand; }
private:
	const uint32_t _mapid;
	Map::map_info* info;
	std::vector<std::shared_ptr<Object>> _objects;
	std::unique_ptr<VisibilityManager> _visibility_manager;

	// io stuff
	boost::asio::io_context::strand map_strand;
	boost::asio::deadline_timer map_timer;
	bool _pendingDelete;
};

