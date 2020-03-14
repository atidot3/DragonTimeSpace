#ifndef _PACKET_H
#define _PACKET_H

#pragma once

#include <Utils/Logger/Logger.h>
#include <Utils\Define.h>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <vector>
#include <chrono>

#pragma pack(1)
typedef struct PACKETDATA
{
	PACKETDATA()
		: size{ 0 }
		, encrypt{ 0 }
		, compress{ 0 }
	{
	}
	WORD size;
	BYTE encrypt;
	BYTE compress;
} PACKETDATA, *LPPACKETDATA;
#pragma pack()
const int HEADER_SIZE = sizeof(PACKETDATA);
const int PACKET_LIMIT_SIZE = 4096;
const BYTE PACKET_MAX_SEQUENCE = 0xFF;

class Packet final
{
public:
	Packet()
		: _header{}
		, _receiveTime{}
	{
	}
	~Packet()
	{
	}
	void Realloc()
	{
		_data.resize(this->_header.size);
	}
	const char* GetPacketData() const
	{
		return _data.data();
	}
	const PACKETDATA& GetPacketHeader() const
	{
		return _header;
	}
	const WORD& GetPacketSize() const
	{
		return _header.size;
	}
	void ShowHandleTime(const std::string& name) const
	{
		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		std::chrono::duration<long double> elapsed_seconds = end - _receiveTime;

		LOG_DEBUG << "Packet " << name << " tooked: " << std::to_string(elapsed_seconds.count()) << "s";
	}
	PACKETDATA _header;
	std::vector<char> _data;
	std::chrono::time_point<std::chrono::system_clock> _receiveTime;

//Quick Definitions for Packets
#define BEGIN_PROTOCOL(opcode)						\
struct s##opcode :									\
	public PACKETDATA								\
{													\
	s##opcode() :									\
		PACKETDATA(opcode)							\
	{												\
		wSize = sizeof(s##opcode) - 4;				\
		wOpcode = opcode;							\
	}

#define END_PROTOCOL()	};

#define DECLARE_PACKET_NAME( opcode )	{ #opcode }
};
#endif /* _GAMESOCKET_H */