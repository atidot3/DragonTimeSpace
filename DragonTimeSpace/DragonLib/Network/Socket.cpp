#include "Socket.h"

#include <iostream>
#include <boost/lexical_cast.hpp>
//#include "../Utils/ResultCode.h"
#include "../Utils/Logger/Logger.h"

Socket::Socket(boost::asio::io_context& io_context)
	: socket_(io_context)
	, m_address{ "0.0.0.0" }
	, receiveSequence{ 0 }
	, _pendingClose{ false }
	, _closed{ false }
	, internalError{ 0 }
	, _recvBuffer{ }
	, _isWritingAsync{ false }
{
	_recvBuffer.Resize(PACKET_LIMIT_SIZE);
	_headerBuffer.Resize(HEADER_SIZE);
}

Socket::~Socket()
{
	//LOG_TRACE << "Socket deleted";
}

tcp::socket& Socket::socket()
{
	return socket_;
}

void Socket::Close()
{
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);
	try
	{
		// -- If we are not closed and not already trying to close
		if (_closed)
			return;
		_closed.exchange(true);
		if (!IsClosed())
		{
			boost::system::error_code ec;
			socket_.shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
			if (ec)
			{
				LOG_ERROR << "Socket::CloseSocket: " << GetAddress() << " errored when shutting down socket: " << std::to_string(ec.value()) <<
					" (" << ec.message() << ")";
				throw ec;
			}
			boost::system::error_code cancel;
			socket_.cancel(cancel);
			if (cancel)
			{
				LOG_ERROR << "Socket::CloseSocket: " << GetAddress() << " errored when canceling all requests: " << std::to_string(cancel.value()) <<
					" (" << cancel.message() << ")";
				throw cancel;
			}

			boost::system::error_code error;
			socket_.close(error);
			if (error)
			{
				LOG_ERROR << "Socket::OnError: " << error.message() << " [" << std::to_string(error.value()) << "]";
				throw error;
			}
		}
	}
	catch (boost::system::error_code& error)
	{
		LOG_ERROR << "Socket failed to close, error: " << error.message();
	}
	catch (std::exception& e)
	{
		LOG_ERROR << "Socket failed to close, error: " << std::string(e.what());  
	}
}
/**
*	Open our socket.
*	return true on success overwise false.
**/
bool Socket::Open()
{
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);

	try
	{
		_closed = false;
		const_cast<std::string &>(m_address) = socket_.remote_endpoint().address().to_string();
		const_cast<std::string &>(m_remoteEndpoint) = boost::lexical_cast<std::string>(socket_.remote_endpoint());
		OnConnected();
	}
	catch (boost::system::error_code& error)
	{
		LOG_ERROR << "Socket::Open() failed to get remote address. Error: " << error.message() << " [" << std::to_string(error.value()) << "].";
		return false;
	}

	StartAsyncRead();
	return true;
}

/**
*	Called once the socket connection is made
**/
void Socket::StartAsyncRead()
{
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);

	if (_closed)
		return;
	if (_pendingClose)
		return;
	if (IsClosed())
		return;

	_recvBuffer.Normalize();
	_recvBuffer.EnsureFreeSpace();
	socket_.async_read_some(boost::asio::buffer(_recvBuffer.GetWritePointer(), _recvBuffer.GetRemainingSpace()),
		boost::bind(&Socket::OnRead, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

/**
*	Gets the endpoint of this connection '127.0.0.1:0000'
*	return the endpoint as string.
**/
const std::string& Socket::GetRemoteEndPoint() 
{
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);
	return m_remoteEndpoint;
}

/**
*	Gets this connection address: '127.0.0.1'
*	return the address as string
**/
const std::string& Socket::GetAddress()
{
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);
	return m_address;
}

/**
*	Get if the socket is close.
*	return true on close or false on open
**/
bool Socket::IsClosed() const
{
	return !socket_.is_open();
}

/**
*	Gets boost error code + Gets the read size.
**/
void Socket::OnRead(const boost::system::error_code& error,
	size_t bytes_transferred)
{
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);
	if (!error)
	{
		_recvBuffer.WriteCompleted(bytes_transferred);

		while (_recvBuffer.GetActiveSize() > 0)
		{
			if (ProcessBuffer(_recvBuffer.GetActiveSize()) == false)
			{
				if (internalError == 1000)
				{
					LOG_ERROR << "Processing data received failed..";
					Close();
					return;
				}
				else
				{
					StartAsyncRead();
				}
				return;
			}
		}
		StartAsyncRead();
	}
	else
	{
		if (error != boost::asio::error::eof)
			LOG_ERROR << error.message();
		Close();
	}
}

/**
*	Process the received data
**/
bool Socket::ProcessBuffer(const size_t& sizeInc)
{
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);
	MessageBuffer& packet = _recvBuffer;
	Packet p;

	//LOG_DEBUG << "Received: " << sizeInc;

	// -- Did our header buffer can contain more data ?
	if (_headerBuffer.GetRemainingSpace() > 0)
	{
		// -- receive the header
		std::size_t readHeaderSize = std::min(packet.GetActiveSize(), _headerBuffer.GetRemainingSpace());
		_headerBuffer.Write(packet.GetReadPointer(), readHeaderSize);
		packet.ReadCompleted(readHeaderSize);
		if (_headerBuffer.GetRemainingSpace() > 0)
		{
			// Couldn't receive the whole header this time.
			return false;
		}
	}

	PACKETDATA *head = (PACKETDATA*)_headerBuffer.GetReadPointer();
	// -- Check if the packet header is valid
	{
		if (head->size >= PACKET_LIMIT_SIZE)
		{
			LOG_ERROR << "Realloc invalid size ! - Packet size: " << std::to_string(head->size);
			internalError = 1000;
			return false;
		}
	}
	if (packet.GetRemainingSpace() > 0)
	{
		// -- Did the packet contain data ?
		if (packet.GetActiveSize() >= head->size)
		{

			// -- Try to read the header
			_headerBuffer.Read((char*)& p._header, HEADER_SIZE);
			// removing 2 at the packet size as we read the opcode on the header

			// -- Read the data
			if (head->size > 0)
			{
				// -- Alloc the packet data buffer
				p.Realloc();
				packet.Read(p._data.data(), p._header.size);
				packet.ReadCompleted(p._header.size);

				_headerBuffer.Reset();
				_headerBuffer.Resize(HEADER_SIZE);
			}
			ProcessIncomingData(p);
			return true;
		}
		LOG_ERROR << "packet.GetActiveSize() >= (header->wSize - sizeof(WORD)) WHERE FALSE";
		packet.Reset();
		internalError = 1000;
		return false;
	}
	LOG_ERROR << "packet.GetRemainingSpace() > 0 WHERE FALSE";
	return false;
}
bool Socket::Read(char *_buffer, const int& length)
{
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);

	if (_recvBuffer.GetActiveSize() < (size_t)length)
	{
		// in case we didn't read all data on socket
		return false;
	}
	memcpy(_buffer, _recvBuffer.GetReadPointer(), length);

	return true;
}
/**
*	Asynchronous handle our send MessageBuffer queue.
*	return true if the job has started.
**/
bool Socket::AsyncProcessQueue()
{
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);

	if (_isWritingAsync)
		return false;

	_isWritingAsync = true;
#ifdef SOCKET_USE_IOCP
	bool success = false;
	MessageBuffer* buffer = &_writeQueue.get_front_reference(success);
	if (success)
	{
		socket_.async_write_some(boost::asio::buffer(buffer->GetReadPointer(), buffer->GetActiveSize()), std::bind(&Socket::WriteHandlerWrapper,
			this->shared_from_this(), std::placeholders::_1, std::placeholders::_2));
	}
#else
	socket_.async_write_some(boost::asio::null_buffers(), std::bind(&Socket::WriteHandlerWrapper,
		this->shared_from_this(), std::placeholders::_1, std::placeholders::_2));
#endif
	return true;
}

void Socket::WriteHandlerWrapper(boost::system::error_code error, std::size_t transferedBytes)
{
#ifdef SOCKET_USE_IOCP	
	if (!error)
	{
		_isWritingAsync = false;
		bool success = false;
		MessageBuffer& buffer = _writeQueue.get_front_reference(success);
		if (success)
		{
			buffer.ReadCompleted(transferedBytes);
			if (!buffer.GetActiveSize())
				_writeQueue.pop();

			if (!_writeQueue.empty())
				AsyncProcessQueue();
			else if (_pendingClose)
				Close();
		}
	}
	else
	{
		LOG_ERROR << "Socket::WriteHandlerWrapper() failed. Error: " << error.message() << " [" << std::to_string(error.value()) << "].";
		Close();
	}
#else
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);

	_isWritingAsync = false;
	HandleQueue();
#endif
}

bool Socket::Update()
{
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);

	if (_closed)
		return false;

#ifndef  SOCKET_USE_IOCP
	if (_pendingClose)
		return false;
	if (_isWritingAsync || (_writeQueue.size() == 0 && !_pendingClose))
		return true;

	for (; HandleQueue();)
		;
#endif

	return true;
}

bool Socket::HandleQueue()
{
	//LOG_DEBUG << "HandleQueue";
	boost::unique_lock<boost::recursive_mutex> scoped_lock(mutex);

	if (_writeQueue.empty())
		return false;
	
	bool success = false;
	MessageBuffer& queuedMessage = _writeQueue.get_front_reference(success);
	if (!success)
	{
		return false;
	}

	std::size_t bytesToSend = queuedMessage.GetActiveSize();

	boost::system::error_code error;
	std::size_t bytesSent = socket_.write_some(boost::asio::buffer(queuedMessage.GetReadPointer(), bytesToSend), error);
	if (error)
	{
		if (error == boost::asio::error::would_block || error == boost::asio::error::try_again)
			return AsyncProcessQueue();

		_writeQueue.pop();
		if (_pendingClose && _writeQueue.empty())
		{
			LOG_FATAL << error.message();
			Close();
		}
		return false;
	}
	else if (bytesSent == 0)
	{
		_writeQueue.pop();
		if (_pendingClose && _writeQueue.empty())
		{
			LOG_FATAL << error.message();
			Close();
		}
		return false;
	}
	else if (bytesSent < bytesToSend) // now n > 0
	{
		queuedMessage.ReadCompleted(bytesSent);
		return AsyncProcessQueue();
	}

	_writeQueue.pop();
	if (_pendingClose && _writeQueue.empty())
	{
		LOG_FATAL << error.message();
		Close();
	}
	return !_writeQueue.empty();
}