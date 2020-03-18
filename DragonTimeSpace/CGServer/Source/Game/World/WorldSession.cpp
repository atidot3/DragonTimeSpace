#include "WorldSession.h"

#include "../../Network/CGSocket.h"

#include <Utils/Logger/Logger.h>
#include <Database/Repository/RepositoryManager.h>
#include <Configuration/Configuration.h>

#include <Network/Packet/Char/Char.h>
#include <Network/ResultCodes.h>
#include <Network/Messages/CommandID.h>

//----------------------------------------
//	WorldSession constructor
//	This class handle all data related to the player
//----------------------------------------
WorldSession::WorldSession(Socket* gameSock, const uint32_t& AccountID)
	: _account_id{ AccountID }
	, _socket{ gameSock }
	//, _player{ nullptr }
	, _firstLogging{ true }
	, _ip{ "" }
	, methodList{}
{
	//--- Tutorial
	//methodList.emplace(Opcodes::UG_TUTORIAL_HINT_UPDATE_REQ, std::make_tuple(std::bind(&WorldSession::OnCharUpdateTutorialReq, this, std::placeholders::_1), THREAD_METHOD::THREAD_SAFE));
}
//----------------------------------------
//	WorldSession destructor
//	This is responsive to remove player propely
//----------------------------------------
WorldSession::~WorldSession()
{
	_socket = nullptr;
	//LOG_TRACE << "WorldSession destructed";
}
//----------------------------------------
//	WorldSession kick the player from our server
//----------------------------------------
void WorldSession::Kick()
{
	if (_socket && !_socket->IsClosed())
		_socket->Close();
}
//----------------------------------------
//	WorldSession retrive our player account id
//----------------------------------------
const uint32_t& WorldSession::GetAccountID() const
{
	return _account_id;
}
//----------------------------------------
//	WorldSession create the player data before sending it to the world
//----------------------------------------
bool WorldSession::CreatePlayer(const uint32_t& char_id)
{
	// create plr obj
	//_player = std::make_shared<Player>(_socket, this, _account_id);
	// update account online in database

	return true;
}
//----------------------------------------
//	Trigger at socket close
//----------------------------------------
void WorldSession::OnDisconnect()
{
	_socket = nullptr;
}

//----------------------------------------
//	Process our packet safe / unsafe way
//----------------------------------------
void WorldSession::ProcessUnSafe()
{
	Packet packet;
	_packets.pop(packet);

	char_packet* p = (char_packet*)packet.GetPacketData();

	auto it = methodList.find(p->CMD);
	if (it != methodList.end())
	{
		std::function<bool(const Packet&)> _method = std::get<0>(it->second);
		THREAD_METHOD thr = std::get<1>(it->second);

		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

		if (_method(packet) == false)
		{
			// ?
		}

		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		const auto elapsedDurationMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		const auto elapsedDurationS = std::chrono::duration_cast<std::chrono::seconds> (end - begin).count();

		if (elapsedDurationMS > 500)
		{
			LOG_WARNING << "Packet: " << std::string(GetPacketName(p->CMD));
			LOG_DEBUG << "Time difference = " << elapsedDurationMS << " ms";
			LOG_DEBUG << "Time difference = " << elapsedDurationS << " s";
		}
	}
}


bool WorldSession::_ProcessGamePacket(const Packet& packet)
{
	char_packet* p = (char_packet*)packet.GetPacketData();

	auto it = methodList.find(p->CMD);
	if (it != methodList.end())
	{
		std::function<bool(const Packet&)> _method = std::get<0>(it->second);
		THREAD_METHOD thr = std::get<1>(it->second);

		switch (thr)
		{
		case THREAD_METHOD::THREAD_UNSAFE:
		{
			/*if (_player && _player->GetMap())
			{
				_packets.push(std::move(packet));
				_player->GetMap()->GetStrand().post([t = shared_from_this()]
					{
						t->ProcessUnSafe();
					});
			}*/
			break;
		}
		case THREAD_METHOD::THREAD_SAFE:
		{
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

			if (_method(packet) == false)
			{
				// ?
			}

			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			const auto elapsedDurationMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
			const auto elapsedDurationS = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();

			if (elapsedDurationMS > 500)
			{
				LOG_WARNING << "Packet: " << std::string(GetPacketName(p->CMD));
				LOG_DEBUG << "Time difference = " << elapsedDurationMS << " ms";
				LOG_DEBUG << "Time difference = " << elapsedDurationS << " s";
			}

			break;
		}
		}
		return true;
	}
	else
	{
		LOG_WARNING << "Get an unexpected Game packet: [" << std::string(GetPacketName(p->CMD)) << "]";
		return false;
	}
}
