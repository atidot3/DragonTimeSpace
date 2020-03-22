#ifndef _WORLDSESSION_H
#define _WORLDSESSION_H

#pragma once

#include <memory>
#include <functional>
#include <Utils/SafeQueue/SafeQueue.h>
#include <Network/Socket.h>

class Player;
class WorldSession : public std::enable_shared_from_this<WorldSession>
{
private:
	enum THREAD_METHOD
	{
		THREAD_SAFE,
		THREAD_UNSAFE
	};
public:
	WorldSession(Socket* gameSock, std::function<void()> destruct_handler);
	WorldSession() = default;
	~WorldSession();
	
	void			SetAccountId(const uint32_t& accid) { _account_id = accid; }
	bool			_ProcessGamePacket(const Packet& packet);
	void			OnDisconnect();
	//----------------------------------------
	//	WorldSession send packet to our player game
	//----------------------------------------
	template <class T>
	void SendPacket(const T& t) const
	{
		if (_socket && !_socket->IsClosed())
		{
			_socket->ms_Write(t);
		}
	}
	const uint32_t& GetAccountID() const;
	void			Kick();
	bool			CreatePlayer(const uint32_t& char_id);
	//std::shared_ptr<Player>	GetPlayer() const { return _player; }
private:
	uint32_t			_account_id;
	Socket*				_socket;
	std::shared_ptr<Player>	 _player;
	bool				_firstLogging;
	std::string			_ip;
	SafeVector<Packet>	_packets;
	std::function<void()> _destruct_handler;
private:
	using Method = std::function<bool(const Packet&)>;
	using MapMethod = std::map<unsigned short, std::tuple<Method, THREAD_METHOD>>;
	using MapList = std::list<MapMethod>;
	MapMethod methodList;

private:
	void ProcessUnSafe();

	// -- packet
	bool onReceiveMainHero(const Packet& packet);
	bool onSceneLoaded(const Packet& packet);
	bool onNewRoleCutScene(const Packet& packet);
	bool onReceiveOperateDatasReq(const Packet& packet);
	bool onReceiveTeamMemberReq(const Packet& packet);
	bool onReceiveCardPackInfo(const Packet& packet);
	bool onReceiveMyHeroAttrData(const Packet& packet);
	bool onReceiveDNABagInfo(const Packet& packet);
	bool onReceiveVisitNpcTrade(const Packet& packet);
	bool onReceiveOfflineChat(const Packet& packet);
	bool onReceiveMailList(const Packet& packet);
	bool onReceiveBlacklist(const Packet& packet);
	bool onReceiveReturnToChar(const Packet& packet);
	bool onReceiveAllDNAPageInfo(const Packet& packet);
	bool onReceiveRefreshRadar(const Packet& packet);
	bool onReceiveRefreshMapQuestInfo(const Packet& packet);
	bool onReceiveEntrySelectState(const Packet& packet);
	bool onReceiveSetChooseTarget(const Packet& packet);
	bool onRecieveChat(const Packet& packet);
	bool onRecieveSyncSkillStage(const Packet& packet);
	bool onReceiveMagicAttack(const Packet& packet);
	void SendUpdateXpLevel(uint32_t herothisid, uint32_t exp, uint32_t level, uint32_t secXP, uint32_t secLevel);
};

#endif /*_WORLDSESSION_H*/