#include "Player.h"
#include "../../../WorldSession.h"

#include <Network/Packet/ProtobufPacket.h>
#include <Network/Buffer/MessageBuffer.h>
#include <Tables/TableContainer.h>
#include <Database/Repository/RepositoryManager.h>
#include <Configuration/Configuration.h>

bool Player::load(const uint32_t& char_id)
{
	_char_id = char_id;
	LOG_DEBUG << "Need to load the character data from here";

	// -- mysql select

	bool ret = false;
	auto result = sQueryRepository.GetCGServerRepository().GetCharacterByCharId(char_id, ret);
	if (!ret)
	{
		LOG_FATAL << "query were null: " << char_id;
		auto error = ProtobufPacket<msg::MSG_Ret_Common_Error_SC>(CommandID::Ret_Common_Error_SC);
		{
			error.get_protobuff().set_errorcode(msg::LoginRetCode::LOGIN_RETURN_DB);
			error.compute();
			SendPacket(error.get_buffer());
			return false;
		}
	}
	if (result->rowsCount() <= 0)
	{
		LOG_FATAL << "Unable to retreive characterid: " << char_id;
		auto error = ProtobufPacket<msg::MSG_Ret_Common_Error_SC>(CommandID::Ret_Common_Error_SC);
		{
			error.get_protobuff().set_errorcode(msg::LoginRetCode::LOGIN_RETURN_DB);
			error.compute();
			SendPacket(error.get_buffer());
			return false;
		}
	}
	result->next();

	// -- Load base
	load_player_data(result.get());

	// -- Load skills
	// -- Load other stuff

	// -- Load system data
	ret = load_player_system_data();
	

	return true;
}

bool Player::load_player_data(QueryResult* result)
{
	// -- name
	{
		set_name(result->getString("Name"));
	}
	// -- position
	{
		set_map_id(result->getUInt("MapID"));
		set_position(result->getUInt("Position_X"), result->getUInt("Position_Y"), 0);
	}
	// -- hero
	{
		_hero[Hero::selected_hero::PRIMARY]._cur_exp = result->getUInt("CurrentExp");
		_hero[Hero::selected_hero::PRIMARY]._level = result->getUInt("CurrentLevel");
		_hero[Hero::selected_hero::PRIMARY]._heroid = result->getUInt("HeroID");
		_hero[Hero::selected_hero::PRIMARY]._avatarid = result->getUInt("AvatarID");
		_hero[Hero::selected_hero::PRIMARY]._occupation = msg::Occupation::Occu_Yaohu;
		_hero[Hero::selected_hero::PRIMARY]._hairstyle = result->getUInt("Hairstyle");
		_hero[Hero::selected_hero::PRIMARY]._haircolor = result->getUInt("Haircolor");
		_hero[Hero::selected_hero::PRIMARY]._facestyle = result->getUInt("Facestyle");
		_hero[Hero::selected_hero::PRIMARY]._antenna = result->getUInt("Antenna");
		_hero[Hero::selected_hero::PRIMARY]._self_created = true;
	}

	return true;
}

bool Player::load_player_system_data()
{
	// -- Load quickslots, shortcuts, chattabs

	bool ret = false;
	auto result = sQueryRepository.GetCGServerRepository().GetChatTabs(_session->GetAccountID(), ret);
	if (ret && result)
	{
		result->next();
		_chat_tabs = result->getString("chattab");
	}
	else
	{
		LOG_ERROR << "unable to retreive chat tabs from charid: " << _char_id;
		return false;
	}
	result = sQueryRepository.GetCGServerRepository().GetQuickSlots(_char_id, 0, ret);
	if (ret && result)
	{
		result->next();
		_quick_slots = result->getString("quickslot");
	}
	else
	{
		LOG_ERROR << "unable to retreive quickslots from charid: " << _char_id;
		return false;
	}
	result = sQueryRepository.GetCGServerRepository().GetShortcuts(_session->GetAccountID(), ret);
	if (ret && result)
	{
		result->next();
		_shortcuts = result->getString("shortcut");
	}
	else
	{
		LOG_ERROR << "unable to retreive shortcuts from charid: " << _char_id;
		return false;
	}

	return true;
}