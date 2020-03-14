#pragma once

#include <iostream>
#include <queue>

#include <boost/asio/strand.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <sstream>

#include "Socket.h"

class WebSocketRequest : public Socket
{
public:
	WebSocketRequest(boost::asio::io_context& io_context)
		: Socket(io_context)
	{

	}
protected:
	virtual bool ProcessBuffer(const size_t& sizeInc) override
	{
		LOG_DEBUG << "HTTP REQUEST";


		char* data = new char[sizeInc];
		if (Read((char*)data, sizeInc) == false)
		{
			return false;
		}

		std::string str(data);
		std::string loc = GetNthWord(str, 2);
		/*
		

		LOG_DEBUG << data;*/
		LOG_DEBUG << "Location Request:";
		LOG_DEBUG << loc;
		delete data;

		MessageBuffer buffer;
		std::string response;
		

		if (loc.compare("/uptime") == 0)
		{
			std::string uptime = "Days:" + std::to_string(clock() / CLOCKS_PER_SEC / 60 / 60 / 24) +
				" Hours:" + std::to_string(clock() / CLOCKS_PER_SEC / 60 / 60) + " Minutes:" + std::to_string(clock() / CLOCKS_PER_SEC / 60) + " Seconds:" + std::to_string(clock() / CLOCKS_PER_SEC);
			response = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: " + std::to_string(uptime.size()) + "\n\n" + uptime;

		}
		else
		{
			response = GetDefaultResponse(); 
		}

		buffer.Write(response.c_str(), response.size());
		_writeQueue.push(std::move(buffer));
		return false;
	}
	std::string GetNthWord(std::string s, std::size_t n)
	{
		std::istringstream iss(s);
		while (n-- > 0 && (iss >> s));
		return s;
	}
	std::string GetDefaultResponse()
	{
		std::string s = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12 \n\nHello World!";
		return s;
	}

};