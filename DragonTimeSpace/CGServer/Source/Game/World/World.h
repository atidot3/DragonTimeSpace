#ifndef _WORLD_H_
#define _WORLD_H_

#pragma once

#include <Utils/Define.h>

#include "WorldSession.h"
#include "QueueManager.h"

#include <mutex>
#include <vector>

class World
{
public:
	static World& instance();

	bool IsShutDownPending() const;
	void SetPendingTime(const short& val);
	void SetPending(const bool& val);
	const short& GetPendingTime() const;
	void Purge();


	// -- manage game session
	void AddSession(std::shared_ptr<WorldSession> s);
	WorldSession* FindSession(const uint32_t& id) const;
	bool RemoveSession(std::shared_ptr<WorldSession> s, const std::string& ip);
	bool IsFull() const;

	// -- manage pending queue
	void AddToQueue(const std::shared_ptr<WorldSession> s);
	void RemoveFromQueue(const std::shared_ptr<WorldSession> s);
	uint32_t GetQueuePosition(const std::shared_ptr<WorldSession> s);
	uint32_t GetMyQueueEstimatedTime(const std::shared_ptr<WorldSession> s);
	//----------------------------------------
	//	World send packet to all / exept Skip (handle)
	//----------------------------------------
	template <class T>
	void SendToAll(const T& /*t*/) const
	{
		std::lock_guard<std::mutex> guard(wMutex);

		/*for (auto itr = _sessionList.begin(); itr != _sessionList.end(); ++itr)
		{
			if ((*itr) && (*itr)->GetPlayer()->IsInWorld())
			{
				(*itr)->SendPacket(t);
			}
		}*/
	}
	template <class T>
	void SendTo(const std::string& /*PlrName*/, const T& /*t*/) const
	{
		std::lock_guard<std::mutex> guard(wMutex);

		/*for (auto itr = _sessionList.begin(); itr != _sessionList.end(); ++itr)
		{
			if ((*itr) && (*itr)->GetPlayer()->IsInWorld() && (*itr)->GetPlayer()->GetName() == PlrName)
			{
				(*itr)->SendPacket(t);
			}
		}*/
	}
	//void SendDisplayText(const std::string& message, const eSERVER_TEXT_TYPE& test_type, const std::string& from);

	uint32_t AcquireSerialId();

private:
	World();
	~World();
	void UpdateRealm();
	void UpdateQueue();

private:
	std::vector<std::shared_ptr<WorldSession>>	_sessionList;
	QueueManager								_pending_queue;
	uint32_t									_playerLimit;
	bool										_pending_shutdown;
	short										_pending_shutdown_time;

	// -- threading / mutex
	std::mutex mutable							wMutex;

	std::thread									_queue_handler;
	std::mutex mutable							_queue_mutex;
};

#define sWorld World::instance()

#endif //_WORLD_H_