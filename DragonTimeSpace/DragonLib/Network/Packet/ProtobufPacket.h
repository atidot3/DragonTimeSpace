#pragma once

#include "Packet.h"
#include "../Buffer/MessageBuffer.h"

#include <Network\Messages\CommandID.h>
#include <Network\Messages\message.pb.h>
#include <Network\Messages\avatar.pb.h>
#include <Network\Messages\object.pb.h>
#include <Network\Messages\hero.pb.h>
#include <Network\Messages\team.pb.h>
#include <Network\Messages\chat.pb.h>
#include <Network\Messages\quest.pb.h>
#include <Network\Messages\battle.pb.h>
#include <Network\Messages\basic.pb.h>
#include <Network\Messages\market.pb.h>
#include <Network\Messages\massive.pb.h>
#include <Network\Messages\mobapk.pb.h>
#include <Network\Messages\relation.pb.h>
#include <Network\Messages\apprentice.pb.h>
#include <Network\Messages\chatset.pb.h>
#include <Network\Messages\copymap.pb.h>
#include <Network\Messages\country.pb.h>
#include <Network\Messages\mail_cmd.pb.h>
#include <Network\Messages\magic_msg.pb.h>
#include <Network\Messages\career.pb.h>

// -- Protobuf packet:
// -- HEADER_SIZE + 8 + protobuff->bytesizelong()

template <typename T>
class ProtobufPacket
{
#pragma pack(1)
	struct responce
	{
		WORD size;
		BYTE encrypt;
		BYTE compress;

		WORD CMD;
		BYTE pad;
		BYTE pad1;
		BYTE pad2;
		BYTE pad3;

		WORD protobuff_length;
	};
#pragma pack()
	const int PROTOBUF_HEADER_SIZE = sizeof(responce) - HEADER_SIZE;
public:
	// -- Outbound proto message
	ProtobufPacket<T>(const CommandID& cmd)
		: res{ 0 }
	{
		res.CMD = cmd;
		res.size = 0;
		res.encrypt = 0;
		res.compress = 0;
		res.pad = 0x81;
		res.pad1 = 0xde;
		res.pad2 = 0x46;
		res.pad3 = 0xdf;
		res.protobuff_length = 0;
	}

	// -- Inband proto message
	ProtobufPacket<T>(const Packet& cmd)
		: res{ 0 }
	{
		fill_my_data<T>(data, (unsigned char*)cmd.GetPacketData(), cmd.GetPacketHeader().size);
	}
	// -- Build the internal packet ready to send
	void compute()
	{
		res.protobuff_length = static_cast<WORD>(data.ByteSizeLong());
		res.size = static_cast<WORD>(PROTOBUF_HEADER_SIZE + res.protobuff_length);

		buffer.Resize(std::size_t(HEADER_SIZE + PROTOBUF_HEADER_SIZE + res.protobuff_length));

		buffer.Write(&res, sizeof(responce));
		buffer.Write(data.SerializePartialAsString().c_str(), static_cast<size_t>(res.protobuff_length));
	}

	// -- return packet size without header
	const WORD get_size() const
	{
		return responce.size;
	}

	// -- return protobuf T struct
	T& get_protobuff()
	{
		return data;
	}

	// -- return message buffer packet
	const MessageBuffer& get_buffer() const
	{
		return buffer;
	}

	// -- print as hex protobuf data
	void log_data()
	{
		std::cout << std::hex << std::setfill('0');  // needs to be set only once

		std::vector<BYTE> protobuff_buffer(res.protobuff_length);
		data.SerializeToArray(protobuff_buffer.data(), res.protobuff_length);

		auto *ptr = protobuff_buffer.data();
		for (int i = 0; i < res.protobuff_length; i++, ptr++)
		{
			std::cout << std::setw(2) << static_cast<unsigned>(*ptr) << " ";
		}
		std::cout << std::endl;
	}
	template<class T>
	bool fill_my_data(T& t, const unsigned char* data, const WORD& size)
	{
		MessageBuffer buffer;
		buffer.Resize(size - 8);
		buffer.Write(&data[8], size - 8);

		return ParseProtoMsg<T>((const char*)buffer.GetReadPointer(), (size - 8), t);
	}

private:
	responce res;
	T data;

	MessageBuffer buffer;
};
