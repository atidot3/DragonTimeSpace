#pragma once

#include <list>
#include <vector>
#include <memory>

#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

/// A pool of io_context objects.
class io_context_pool : private boost::noncopyable
{
public:
	//constructor
	io_context_pool(std::size_t pool_size);
	/// Run all io_contexts in pool.
	void run();

	/// Stop all io_contexts in pool.
	void stop();

	// Get an io_context to work with (round robin on pool)
	boost::asio::io_context& get_io_context();
private:
	//some types
	using io_context_ptr = std::shared_ptr<boost::asio::io_context>;
	using io_context_work = boost::asio::executor_work_guard<boost::asio::io_context::executor_type>;

	/// The pool of io_contexts.
	std::vector<io_context_ptr> _io_contexts;

	/// The work that keeps the io_contexts running.
	std::list<io_context_work> _works;

	/// The next io_context to use for a connection.
	std::size_t _next_io_context;
};