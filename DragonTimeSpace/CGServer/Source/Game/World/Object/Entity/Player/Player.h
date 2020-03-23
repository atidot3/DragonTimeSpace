#pragma once

#include <Utils/Define.h>
#include "../Entity.h"

class WorldSession;
class Map;
class MessageBuffer;
class QueryResult;

class Hero
{
public:
	enum selected_hero
	{
		PRIMARY = 0,
		SECONDARY
	};
public:
	Hero()
		: _face{ 0 }
		, _weapon{ 0 }
		, _coat{ 0 }
		, _occupation{ 0 }
		, _heroid{ 0 }
		, _facestyle{ 0 }
		, _hairstyle{ 0 }
		, _haircolor{ 0 }
		, _antenna{ 0 }
		, _bodystyle{ 0 }
		, _avatarid{ 0 }
		, _level{ 0 }
		, _cur_exp{ 0 }
		, _self_created{ false }
	{

	}
public:
	uint32_t _face;
	uint32_t _weapon;
	uint32_t _coat;
	uint32_t _occupation;
	uint32_t _heroid;
	uint32_t _facestyle;
	uint32_t _hairstyle;
	uint32_t _haircolor;
	uint32_t _antenna;
	uint32_t _bodystyle;
	uint32_t _avatarid;
	uint32_t _level;
	uint32_t _cur_exp;
	bool _self_created;
};
class Inventory{};
class Attribute{};

class Player
	: public Entity
	, public std::enable_shared_from_this<Player>
{
public:
	explicit Player(WorldSession* session);
	~Player();

	bool load(const uint32_t& char_id);
	void SendPacket(const MessageBuffer& buffer);

	// -- GETER
		// map
	Map* get_map() { return _map; }
		// user datas


	// -- CONST GETTER
		// user datas

		// user parameters
	const std::string& get_char_tabs_config() const { return _chat_tabs; }
	const std::string& get_quickslots_config() const { return _quick_slots; }
	const std::string& get_shortcuts_config() const { return _shortcuts; }
	const uint32_t& get_level() const { return _hero[_selected_hero]._level; }
	const uint32_t& get_cur_exp() const { return _hero[_selected_hero]._cur_exp; }
	const Hero& get_hero_data(const uint32_t& index) { return _hero[index]; }
	const uint32_t& get_character_id() const { return _char_id; }
	// -- SETTER
	void set_map(Map* map) { _map = map; }
	void set_level(const uint32_t& level) { _hero[_selected_hero]._level = level; }
	void set_cur_exp(const uint32_t& exp) { _hero[_selected_hero]._cur_exp = exp; }
private:
	bool load_player_data(QueryResult* result);
	bool load_player_system_data();
private:
	WorldSession*	_session;
	Map*			_map;
	Hero			_hero[2];

	std::string		_quick_slots;
	std::string		_shortcuts;
	std::string		_chat_tabs;

	uint32_t		_char_id;
	// this must only be 0 or 1
	Hero::selected_hero	_selected_hero;
};