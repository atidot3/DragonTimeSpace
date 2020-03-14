#ifndef SocketMgr_h__
#define SocketMgr_h__

#pragma once

#include <Utils/Logger/Logger.h>

#include "AsyncAcceptor.h"
#include "NetworkThread.h"
#include <boost/asio/ip/tcp.hpp>
#include <memory>
#include <assert.h>

using boost::asio::ip::tcp;

template<class SocketType>
class SocketManager
{
public:
	virtual ~SocketManager()
	{
		assert(!_threads && !_acceptor && !_threadCount, "StopNetwork must be called prior to SocketManager destruction");
	}

	virtual bool StartNetwork(Trinity::Asio::IoContext& ioContext, std::string const& bindIp, unsigned shot port, int threadCount)
	{
		assert(threadCount > 0);

		AsyncAcceptor* acceptor = nullptr;
		try
		{
			acceptor = new AsyncAcceptor(ioContext, bindIp, port);
		}
		catch (boost::system::system_error const& err)
		{
			LOG_FATAL << "Exception caught in SocketManager.StartNetwork ("<< bindIp.c_str() <<":"<< port <<"): "<< err.what();
			return false;
		}

		if (!acceptor->Bind())
		{
			LOG_FATAL << "StartNetwork failed to bind socket acceptor");
			return false;
		}

		_acceptor = acceptor;
		_threadCount = threadCount;
		_threads = CreateThreads();

		assert(_threads);

		for (int32_t i = 0; i < _threadCount; ++i)
			_threads[i].Start();

		return true;
	}

	virtual void StopNetwork()
	{
		_acceptor->Close();

		if (_threadCount != 0)
			for (int32_t i = 0; i < _threadCount; ++i)
				_threads[i].Stop();

		Wait();

		delete _acceptor;
		_acceptor = nullptr;
		delete[] _threads;
		_threads = nullptr;
		_threadCount = 0;
	}

	void Wait()
	{
		if (_threadCount != 0)
			for (int32_t i = 0; i < _threadCount; ++i)
				_threads[i].Wait();
	}

	virtual void OnSocketOpen(tcp::socket && sock, uint32_t threadIndex)
	{
		try
		{
			std::shared_ptr<SocketType> newSocket = std::make_shared<SocketType>(std::move(sock));
			newSocket->Start();

			_threads[threadIndex].AddSocket(newSocket);
		}
		catch (boost::system::system_error const& err)
		{
			LOG_WARNING << "Failed to retrieve client's remote address "<< err.what();
		}
	}

	int32_t GetNetworkThreadCount() const { return _threadCount; }

	uint32_t SelectThreadWithMinConnections() const
	{
		uint32_t min = 0;

		for (int32 i = 1; i < _threadCount; ++i)
			if (_threads[i].GetConnectionCount() < _threads[min].GetConnectionCount())
				min = i;

		return min;
	}

	std::pair<tcp::socket*, uint32_t> GetSocketForAccept()
	{
		uint32_t threadIndex = SelectThreadWithMinConnections();
		return std::make_pair(_threads[threadIndex].GetSocketForAccept(), threadIndex);
	}

protected:
	SocketManager() : _acceptor(nullptr), _threads(nullptr), _threadCount(0)
	{
	}

	virtual NetworkThread<SocketType>* CreateThreads() const = 0;

	AsyncAcceptor* _acceptor;
	NetworkThread<SocketType>* _threads;
	int32_t _threadCount;
};

#endif // SocketMgr_h__