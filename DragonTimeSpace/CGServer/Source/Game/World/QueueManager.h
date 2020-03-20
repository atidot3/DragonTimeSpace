#pragma once

#include <Utils/Define.h>

#include <memory>
#include <deque>
#include <chrono>
#include <vector>

class WorldSession;
class QueueManager
{
public:
	QueueManager();
	void add_to_queue(std::shared_ptr<WorldSession> identifier);
	void remove_from_queue(std::shared_ptr<WorldSession> identifier);
	std::shared_ptr<WorldSession> pop_session();
	bool contain_identifier(std::shared_ptr<WorldSession> identifier);
	uint32_t get_position(std::shared_ptr<WorldSession> identifier);
	uint32_t get_size();
	long long get_estimated_time(std::shared_ptr<WorldSession> identifier);
private:
	std::deque<std::tuple<std::shared_ptr<WorldSession>, std::chrono::time_point<std::chrono::steady_clock>>> _queue;
	std::vector<long long> _estimated_time;
};