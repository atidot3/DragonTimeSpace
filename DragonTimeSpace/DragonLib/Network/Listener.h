#pragma once

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>

#include "Socket.h"
#include "io_context_pool.h"
#include "../Utils/Logger/Logger.h"

template <typename SocketType>
class Listener
{
public:
	Listener(io_context_pool& pool, const int& port, const int& threadCount);
	~Listener();
	void run();
private:
	void start_accept();
	void handle_accept(SocketType* new_session, const boost::system::error_code& error);
	void Update();

	SocketType* CreateSocket();

private:
	io_context_pool& _pool;
	tcp::acceptor acceptor_;
	
	typedef std::vector<std::shared_ptr<SocketType>> SocketContainer;
	
	SocketContainer _sockets;
	std::mutex m_socketLock;
	
	boost::asio::deadline_timer session_timer;
};

template <typename SocketType>
Listener<SocketType>::Listener(io_context_pool& pool, const int& port, const int& threadCount)
	: _pool{ pool },
	acceptor_{ _pool.get_io_context(), tcp::endpoint(tcp::v4(), port) },
	session_timer{ _pool.get_io_context(), boost::posix_time::seconds(1) }
{
	LOG_INFO << "Listener will be initiate at port: " << std::to_string(acceptor_.local_endpoint().port()) << " and at " << std::to_string(threadCount) << " threadCount";
}

template <typename SocketType>
Listener<SocketType>::~Listener()
{
}

template <typename SocketType>
void Listener<SocketType>::run()
{
	session_timer.async_wait(boost::bind(&Listener::Update, this));
	start_accept();
}

template <typename SocketType>
void Listener<SocketType>::Update()
{
	std::lock_guard<std::mutex> lock(m_socketLock);

	_sockets.erase(std::remove_if(_sockets.begin(), _sockets.end(), [this](std::shared_ptr<SocketType> sock)
	{
		if (!sock->Update())
		{
			if (!sock->IsClosed())
				sock->Close();
			return true;
		}

		return false;
	}), _sockets.end());

	session_timer.expires_from_now(boost::posix_time::milliseconds(50));
	session_timer.async_wait(std::bind(&Listener<SocketType>::Update, this));
}

template <typename SocketType>
void Listener<SocketType>::start_accept()
{
	SocketType* new_session = CreateSocket();
	acceptor_.async_accept(new_session->socket(),
		boost::bind(&Listener::handle_accept, this, new_session,
			boost::asio::placeholders::error));
}

template <typename SocketType>
void Listener<SocketType>::handle_accept(SocketType* new_session, const boost::system::error_code& error)
{
	std::lock_guard<std::mutex> lock(m_socketLock);

	if (!error)
	{
		new_session->Open();
	}
	else
	{
		for (auto i = _sockets.begin(); i != _sockets.end(); ++i)
		{
			if (i->get() == new_session)
			{
				_sockets.erase(i);
				return;
			}
		}
	}
	start_accept();
}

template <typename SocketType>
SocketType* Listener<SocketType>::CreateSocket()
{
	_sockets.push_back(std::make_shared<SocketType>(_pool.get_io_context()));
	return _sockets.back().get();
}
