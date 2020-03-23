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
	, _map{ nullptr }
	, _hero{ }
	, _quick_slots{ "" }
	, _shortcuts{ "" }
	, _chat_tabs{ "" }
	, _char_id{ 0 }
	, _selected_hero{ Hero::selected_hero::PRIMARY }
{
}

Player::~Player()
{
}


void Player::SendPacket(const MessageBuffer& buffer)
{
	_session->SendPacket(buffer);
}