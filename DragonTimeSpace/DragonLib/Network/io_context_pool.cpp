#include "io_context_pool.h"

#include <stdexcept>
#include <memory>
#include <thread>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

io_context_pool::io_context_pool(std::size_t pool_size)
	: _next_io_context{ 0 }
{
	if (pool_size == 0)
		throw std::runtime_error("io_context_pool size is 0");

	//create io_context and add some fake work to keep io_context running
	for (std::size_t i = 0; i < pool_size; ++i)
	{
		auto ioc = std::make_shared<boost::asio::io_context>();
		_io_contexts.push_back(ioc);
		_works.push_back(boost::asio::make_work_guard(*ioc));
	}
}

void io_context_pool::run()
{
	// launch one thread per io_contexts
	std::vector<std::shared_ptr<std::thread>> threads;
	for (std::size_t i = 0; i < _io_contexts.size(); ++i)
	{
		threads.push_back(std::make_shared<std::thread>(boost::bind(&boost::asio::io_context::run, _io_contexts[i].get())));
	}

	// Wait for threads in the pool to exit.
	for (std::size_t i = 0; i < threads.size(); ++i)
	{
		if (threads[i]->joinable())
		{
			threads[i]->join();
		}
	}
}

void io_context_pool::stop()
{
	// Explicitly stop all io_contexts.
	for (std::size_t i = 0; i < _io_contexts.size(); ++i)
	{
		_io_contexts[i]->stop();
	}
}

//round-robin like io_contect getter
boost::asio::io_context& io_context_pool::get_io_context()
{
	//get next io_context
	auto& ioc = *_io_contexts[_next_io_context];

	//cycle for next call	
	++_next_io_context;
	if (_next_io_context == _io_contexts.size())
	{
		_next_io_context = 0;
	}

	return ioc;
}