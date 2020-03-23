#pragma once

#include <Utils/Define.h>
#include "../Entity.h"

class WorldSession;
class Map;
class MessageBuffer;

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


	// -- SETTER
	void set_map(Map* map) { _map = map; }

private:
	WorldSession*	_session;
	Map*			_map;

	std::string		_quick_slots;
	std::string		_shortcuts;
	std::string		_chat_tabs;

	uint32_t		_char_id;
};