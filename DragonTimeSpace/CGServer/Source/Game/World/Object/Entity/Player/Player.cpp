#include "Player.h"
#include "../../../WorldSession.h"

#include <Network/Packet/ProtobufPacket.h>
#include <Network/Buffer/MessageBuffer.h>
#include <Tables/TableContainer.h>
#include <Database/Repository/RepositoryManager.h>
#include <Configuration/Configuration.h>

Player::Player(WorldSession* session)
    : Entity()
    , _session{ session }
{
}

Player::~Player()
{
}

bool Player::load(const uint32_t& char_id)
{
	_char_id = char_id;
	LOG_DEBUG << "Need to load the character data from here";

	// -- Load quickslots, shortcuts, chattabs
	{
		bool ret = false;
		auto result = sQueryRepository.GetCGServerRepository().GetChatTabs(_session->GetAccountID(), ret);
		if (ret && result)
		{
			result->next();
			_chat_tabs = result->getString("chattab");
		}
		else
		{
			LOG_ERROR << "unable to retreive chat tabs from charid: " << char_id;
		}
		result = sQueryRepository.GetCGServerRepository().GetQuickSlots(char_id, 0, ret);
		if (ret && result)
		{
			result->next();
			_quick_slots = result->getString("quickslot");
		}
		else
		{
			LOG_ERROR << "unable to retreive quickslots from charid: " << char_id;
		}
		result = sQueryRepository.GetCGServerRepository().GetShortcuts(_session->GetAccountID(), ret);
		if (ret && result)
		{
			result->next();
			_shortcuts = result->getString("shortcut");
		}
		else
		{
			LOG_ERROR << "unable to retreive shortcuts from charid: " << char_id;
		}
	}

	return true;
}

void Player::SendPacket(const MessageBuffer& buffer)
{
	_session->SendPacket(buffer);
}