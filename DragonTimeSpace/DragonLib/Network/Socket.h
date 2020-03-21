#pragma once

#include <iostream>
#include <queue>

#include <boost/asio/strand.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "Utils/SafeQueue/SafeVector.h"
#include "Buffer/MessageBuffer.h"
#include "Packet/Packet.h"
//#include "../Utils/ResultCode.h"

#ifdef BOOST_ASIO_HAS_IOCP
	// -- By using iocp socket we get boost error 10014 invalid pointer for some reason and the socket get disconnected alot (almost all) of the time
	//#define SOCKET_USE_IOCP
#endif

using boost::asio::ip::tcp;

using Method = std::function<bool(const char* data)>;
using TupleMethod = std::tuple<unsigned short, Method>;
using MethodList = std::list<TupleMethod>;

class Socket : public std::enable_shared_from_this<Socket>
{
public:

	Socket(boost::asio::io_context& io_context);
	virtual ~Socket();
	tcp::socket& socket();

	/**
	*	Open our socket.
	*	return true on success overwise false.
	**/
	bool Open();

	/**
	*	Called once the socket connection is made
	**/
	void StartAsyncRead();

	/**
	*	Gets the endpoint of this connection '127.0.0.1:0000'
	*	return the endpoint as string.
	**/
	const std::string& GetRemoteEndPoint();

	/**
	*	Gets this connection address: '127.0.0.1'
	*	return the address as string
	**/
	const std::string& GetAddress();

	/**
	*	Get if the socket is close.
	*	return true on close or false on open
	**/
	bool IsClosed() const;

	/**
	*	Close this connection
	**/
	void Close();

	/**
	*	Get if the socket is close.
	*	return true on close or false on open
	**/
	template <class T>
	void ms_Write(const T& t)
	{
		if (_closed)
			return;
		if (_pendingClose)
			return;
		if (IsClosed())
			return;

		MessageBuffer buffer = t;
		// -- Emplace the packet in the queue
		if (_writeQueue.push(std::move(buffer)))
		{
#ifdef SOCKET_USE_IOCP
			AsyncProcessQueue();
#endif
		}
	}
	/**
	*	Get if the socket is close.
	*	return true on close or false on open
	**/
	template <class T>
	void st_Write(const T& t)
	{
		if (_closed)
			return;
		if (_pendingClose)
			return;
		if (IsClosed())
			return;

		MessageBuffer buffer;
		// -- Pre allocate memory
		buffer.Resize(size_t(4UL + t.size));
		// -- Write the data
		buffer.Write((char*)&t, size_t(4UL + t.size));
		LOG_DEBUG << "Buff to send size: " << buffer.GetBufferSize();
		// -- Emplace the packet in the queue
		if (_writeQueue.push(std::move(buffer)))
		{
			#ifdef SOCKET_USE_IOCP
				AsyncProcessQueue();
			#endif
		}
	}
	/**
	*	Asynchronous handle our send MessageBuffer queue.
	*	return true if the job has started.
	**/
	bool AsyncProcessQueue();
	
	void WriteHandlerWrapper(boost::system::error_code error, std::size_t transferedBytes);

	bool Update();

	bool HandleQueue();

	void SetPendingClose() { _pendingClose.exchange(true); }

	uint32_t	internalError;
private:
	/**
	*	Gets boost error code + Gets the read size.
	**/
	void OnRead(const boost::system::error_code& error,
		size_t bytes_transferred);
protected:
	/**
	*	Read some data from our internal storage
	**/
	bool Read(char *_buffer, const int& length);
	virtual bool ProcessIncomingData(const Packet& p) { return true; }
	virtual void OnConnected(){}
	virtual bool ProcessBuffer(const size_t& sizeInc);
private:
	tcp::socket socket_;
	boost::recursive_mutex mutex;
	std::atomic<bool> _pendingClose;
	std::atomic<bool> _closed;
	SafeVector<MessageBuffer> _writeQueue;
	/**
	*	Handle the packet cutting etc in the internal storage
	*/
	MessageBuffer _recvBuffer;
	MessageBuffer _headerBuffer;
	MessageBuffer _packetBuffer;

	size_t getSizeLeft() { return _recvBuffer.GetRemainingSpace(); }
	size_t getActiveSize() { return _recvBuffer.GetActiveSize(); }

	bool _isWritingAsync;
protected:
	const std::string m_address;
	const std::string m_remoteEndpoint;
	int receiveSequence;
};