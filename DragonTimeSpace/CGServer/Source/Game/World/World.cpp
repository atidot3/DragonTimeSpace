#include "World.h"

#include <Utils/Logger/Logger.h>
#include <Database/Query/Query.h>
#include <Database/MySQLWrapper.h>
#include <Configuration/Configuration.h>

#include <algorithm>
#include <mutex>
#include <cstdarg>

#include <ctime>
#include <chrono>

constexpr uint32_t DEFAULT_THREAD_SLEEP_TIME = 1;
constexpr uint32_t MAX_THREAD_SLEEP_TIME = 50;
constexpr uint32_t MAX_PLAYER_PER_SERVER = 1;
static uint32_t m_uiSerialId = 0;

//----------------------------------------
//	World acquire serial ID (Object handle)
//----------------------------------------
uint32_t World::AcquireSerialId()
{
	if (m_uiSerialId++)
	{
		if (m_uiSerialId == 0xffffffff)//INVALID_SERIAL_ID)
			m_uiSerialId = 0;
	}

	return m_uiSerialId;
}

//----------------------------------------
//	Retreive the world instance singleton
//----------------------------------------
World& World::instance()
{
	static World pInstance;
	return pInstance;
}

//----------------------------------------
//	World Constructor
//----------------------------------------
World::World()
	: _sessionList{ std::vector<std::shared_ptr<WorldSession>>() }
	, _playerLimit{ MAX_PLAYER_PER_SERVER }
	, _pending_shutdown{ false }
	, _pending_shutdown_time{ 75 }
	, _queue_handler{ std::thread(&World::UpdateQueue, this) }
{
	_sessionList.reserve(MAX_PLAYER_PER_SERVER);
}
//----------------------------------------
//	World destructor
//----------------------------------------
World::~World()
{
	_pending_shutdown = true;

	while (!_queue_handler.joinable())
		_queue_handler.join();
}
//----------------------------------------
//	World realm update itself (population / online / offline)
//----------------------------------------
void World::UpdateRealm()
{
	///- Update realm !
	{
		// Updates the population
		if (_playerLimit > 0)
		{
			LOG_INFO << "Server Population (" << std::to_string(_sessionList.size()) << ").";

			Query query("UPDATE `realmlist` SET `realmflags` = '?', `population` = '?' WHERE `LineID` = '?';");
			query.setValue(ServerState::UP);
			query.setValue(_sessionList.size());
			query.setValue(sConfig.GetGameServerServerId());
			sDB.DirectExecute(query.GetQuery());
		}
	}
}

//----------------------------------------
//	World add new connected session
//----------------------------------------
void World::AddSession(std::shared_ptr<WorldSession> s)
{
	std::lock_guard<std::mutex> guard(wMutex);

	if (s == nullptr)
		return;

	_sessionList.push_back(s);
	UpdateRealm();
}

//----------------------------------------
//	World get session by Account ID
//----------------------------------------
WorldSession* World::FindSession(const uint32_t& id) const
{
	std::lock_guard<std::mutex> guard(wMutex);

	for (auto &session : _sessionList)
	{
		if (session->GetAccountID() == id)
		{
			return (session.get());
		}
	}
	return nullptr;
}
//----------------------------------------
//	World remove session
//----------------------------------------
bool World::RemoveSession(std::shared_ptr<WorldSession> s, const std::string& ip)
{
	std::lock_guard<std::mutex> guard(wMutex);

	///- Find the session if it already exist and kick the user, but we can't delete session at this moment to prevent iterator invalidation
	if (s != nullptr)
	{
		///- Remove sessions
		auto itr = std::find(_sessionList.begin(), _sessionList.end(), s);
		if (itr != _sessionList.end())
		{
			_sessionList.erase(itr);
			UpdateRealm();
		}
		return true;
	}
	return false;
}
//----------------------------------------
//	World initiate shutdown
//----------------------------------------
bool World::IsShutDownPending() const
{
	std::lock_guard<std::mutex> guard(wMutex);

	return _pending_shutdown;
}
//----------------------------------------
//	World return time before shutdown
//----------------------------------------
const short& World::GetPendingTime() const
{
	std::lock_guard<std::mutex> guard(wMutex);

	return _pending_shutdown_time;
}
//----------------------------------------
//	World set new shutdown time
//----------------------------------------
void World::SetPendingTime(const short& val)
{
	std::lock_guard<std::mutex> guard(wMutex);

	_pending_shutdown_time = val;
}
//----------------------------------------
//	World purge all connected session
//----------------------------------------
void World::Purge()
{
	std::lock_guard<std::mutex> guard(wMutex);

	for (auto itr : _sessionList)
	{
		//if (itr->GetPlayer())
			//itr->GetPlayer()->Eject();
		//else
			//itr->Kick();
	}
	_sessionList.clear();
}
//----------------------------------------
//	World set penfing shutdown value
//----------------------------------------
void World::SetPending(const bool& val)
{
	_pending_shutdown = val;
}
//----------------------------------------
//	World set penfing shutdown value
//----------------------------------------
bool World::IsFull() const
{
	return _playerLimit == _sessionList.size();
}
//----------------------------------------
//	Add a session to the pending connect queue
//----------------------------------------
void World::AddToQueue(std::shared_ptr<WorldSession> s)
{
	std::lock_guard<std::mutex> guard(_queue_mutex);
	_pending_queue.add_to_queue(s);
}
//----------------------------------------
//	remove a session to the pending connect queue
//----------------------------------------
void World::RemoveFromQueue(std::shared_ptr<WorldSession> s)
{
	std::lock_guard<std::mutex> guard(_queue_mutex);
	_pending_queue.remove_from_queue(s);
}
//----------------------------------------
//	Get this session queue position
//----------------------------------------
uint32_t World::GetQueuePosition(const std::shared_ptr<WorldSession> s)
{
	std::lock_guard<std::mutex> guard(_queue_mutex);
	return _pending_queue.get_position(s);
}
//----------------------------------------
//	Get this session estimated queue time
//----------------------------------------
uint32_t World::GetMyQueueEstimatedTime(const std::shared_ptr<WorldSession> s)
{
	std::lock_guard<std::mutex> guard(_queue_mutex);
	return _pending_queue.get_estimated_time(s);
}
//----------------------------------------
//	Handle queue management
//----------------------------------------
void World::UpdateQueue()
{
	while (!_pending_shutdown)
	{
		// mutex guard context only
		if (!_pending_shutdown)
		{
			std::lock_guard<std::mutex> guard(_queue_mutex);
			if (_pending_queue.get_size() > 0)
			{
				std::lock_guard<std::mutex> guard2(wMutex);
				if (_sessionList.size() < _playerLimit)
				{
					_sessionList.emplace_back(_pending_queue.pop_session());
				}
			}
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}