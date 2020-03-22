#pragma once

#include <Utils/Define.h>
#include "../../Object.h"

class WorldSession;
class Map;
class msg::CharacterBaseData;
class msg::CharacterMapData;
class msg::CharacterMapShow;
class msg::CharacterFightData;
class msg::AttributeData;

class Player
	: public Entity
	, public std::enable_shared_from_this<Player>
{
public:
	explicit Player(WorldSession* session);
	~Player();

	bool load(const uint32_t& char_id);


	// -- GETER
		// map
	Map* get_map() { return _map; }
		// user datas
	msg::CharacterBaseData& get_base_data() { return *_base_data.get(); }
	msg::CharacterMapData&	get_map_data() { return *_map_data.get(); }
	msg::CharacterMapShow&	get_map_show() { return *_map_show.get(); }
	msg::CharacterMapShow&	get_second_hero() { return *_second_hero.get(); }
	msg::CharacterFightData& get_fight_data() { return *_fight_data.get(); }
	msg::AttributeData& get_attribute_data() { return *_attribute_data.get(); }

	// -- CONST GETTER
		// user datas
	const msg::CharacterBaseData& get_base_data() const { return *_base_data.get(); }
	const msg::CharacterMapData& get_map_data() const { return *_map_data.get(); }
	const msg::CharacterMapShow& get_map_show() const { return *_map_show.get(); }
	const msg::CharacterMapShow& get_second_hero() const { return *_second_hero.get(); }
	const msg::CharacterFightData& get_fight_data() const { return *_fight_data.get(); }
	const msg::AttributeData& get_attribute_data() const { return *_attribute_data.get(); }
		// user parameters
	const std::string& get_char_tabs_config() const { return _chat_tabs; }
	const std::string& get_quickslots_config() const { return _quick_slots; }
	const std::string& get_shortcuts_config() const { return _shortcuts; }


	// -- SETTER
	void set_map(Map* map) { _map = map; }

private:
	WorldSession*	_session;
	Map*			_map;
	std::unique_ptr<msg::CharacterBaseData>	_base_data;
	std::unique_ptr<msg::CharacterMapData>	_map_data;
	std::unique_ptr<msg::CharacterMapShow>	_map_show;
	std::unique_ptr<msg::CharacterMapShow>	_second_hero;
	std::unique_ptr<msg::CharacterFightData> _fight_data;
	// -- todo: move attribute in attribute class
	std::unique_ptr<msg::AttributeData>		_attribute_data;

	std::string		_quick_slots;
	std::string		_shortcuts;
	std::string		_chat_tabs;

	uint32_t		_char_id;
};