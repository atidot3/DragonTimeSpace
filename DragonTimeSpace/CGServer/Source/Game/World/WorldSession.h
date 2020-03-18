#ifndef _WORLDSESSION_H
#define _WORLDSESSION_H

#pragma once

#include <memory>
#include <functional>
#include <Utils/SafeQueue/SafeQueue.h>
#include <Network/Socket.h>

class WorldSession : public std::enable_shared_from_this<WorldSession>
{
private:
	enum THREAD_METHOD
	{
		THREAD_SAFE,
		THREAD_UNSAFE
	};
public:
	WorldSession(Socket* gameSock, const uint32_t& AccountID);
	WorldSession() = default;
	~WorldSession();
	
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
			_socket->Write(t);
		}
	}

	const uint32_t& GetAccountID() const;
	void			Kick();
	bool			CreatePlayer(const uint32_t& char_id);
	//std::shared_ptr<Player>	GetPlayer() const { return _player; }
private:
	uint32_t			_account_id;
	Socket*				_socket;
	//std::shared_ptr<Player>	 _player;
	bool				_firstLogging;
	std::string			_ip;
	SafeVector<Packet>	_packets;
private:
	using Method = std::function<bool(const Packet&)>;
	using MapMethod = std::map<unsigned short, std::tuple<Method, THREAD_METHOD>>;
	using MapList = std::list<MapMethod>;
	MapMethod methodList;

private:
	void ProcessUnSafe();
public:
};

#endif /*_WORLDSESSION_H*/