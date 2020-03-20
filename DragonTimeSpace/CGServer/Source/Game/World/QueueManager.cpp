#include "QueueManager.h"
#include "WorldSession.h"

#include <chrono>

QueueManager::QueueManager()
{
	// -- 10 minutes default
	_estimated_time.push_back(600);
}

void QueueManager::add_to_queue(std::shared_ptr<WorldSession> identifier)
{
	auto start = std::chrono::steady_clock::now();
	_queue.emplace_back(identifier, start);
}

void QueueManager::remove_from_queue(std::shared_ptr<WorldSession> identifier)
{
	for (auto it = _queue.begin(); it != _queue.end(); )
	{
		if (std::get<0>(*it) == identifier)
		{
			_queue.erase(it);
			break;
		}
		else
			++it;
	}
}

bool QueueManager::contain_identifier(std::shared_ptr<WorldSession> identifier)
{
	for (auto& c : _queue)
	{
		if (std::get<0>(c) == identifier)
			return true;
	}
	return false;
}

uint32_t QueueManager::get_position(std::shared_ptr<WorldSession> identifier)
{
	int position = 0;
	for (auto it = _queue.begin(); it != _queue.end(); ++it, ++position)
	{
		if (std::get<0>(*it) == identifier)
		{
			return position + 1;
		}
	}
	return 0;
}

std::shared_ptr<WorldSession> QueueManager::pop_session()
{
	std::shared_ptr<WorldSession> session = std::get<0>(_queue.front());
	auto entered_time = std::get<1>(_queue.front());

	_queue.pop_front();

	auto end = std::chrono::steady_clock::now();

	const auto elapsedDurationS = std::chrono::duration_cast<std::chrono::seconds>(end - entered_time).count();

	_estimated_time.push_back(elapsedDurationS);
	if (_estimated_time.size() > 100)
		_estimated_time.erase(_estimated_time.begin());

	return session;
}

uint32_t QueueManager::get_size()
{
	return _queue.size();
}

long long QueueManager::get_estimated_time(std::shared_ptr<WorldSession> identifier)
{
	const uint32_t position = get_position(identifier);
	long long moyenne = 0;

	for (auto& c : _estimated_time)
	{
		moyenne += c;
	}
	
	return (moyenne / _estimated_time.size()) * position;
}