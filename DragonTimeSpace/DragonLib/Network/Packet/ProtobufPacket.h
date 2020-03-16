#pragma once

#include "Packet.h"
#include "../Buffer/MessageBuffer.h"

#include <Network\Messages\CommandID.h>
#include <Network\Messages\message.pb.h>
#include <Network\Messages\avatar.pb.h>
#include <Network\Messages\object.pb.h>
#include <Network\Messages\hero.pb.h>
#include <Network\Messages\team.pb.h>

// -- Protobuf packet:
// -- HEADER_SIZE + 8 + protobuff->bytesizelong()

template <typename T>
class ProtobufPacket
{
	const int PROTOBUF_HEADER_SIZE = sizeof(WORD) + sizeof(BYTE) + sizeof(BYTE) + sizeof(BYTE) + sizeof(BYTE) + sizeof(WORD);
public:
	ProtobufPacket<T>(const CommandID& cmd)
		: size{ 0 }
		, encrypt{ 0 }
		, compress{ 0 }
		, CMD{ static_cast<WORD>(cmd) }
		, pad{ 0 }
		, pad1{ 0 }
		, pad2{ 0 }
		, pad3{ 0 }
		, protobuff_length{ 0 }
	{
	}

	// -- Build the internal packet ready to send
	void compute()
	{
		protobuff_length = data.ByteSizeLong();
		size = PROTOBUF_HEADER_SIZE + protobuff_length;

		buffer.Resize(HEADER_SIZE + PROTOBUF_HEADER_SIZE + protobuff_length);

		buffer.Write(&size, sizeof(WORD));
		buffer.Write(&encrypt, sizeof(BYTE));
		buffer.Write(&compress, sizeof(BYTE));
		buffer.Write(&CMD, sizeof(WORD));
		buffer.Write(&pad, sizeof(BYTE));
		buffer.Write(&pad1, sizeof(BYTE));
		buffer.Write(&pad2, sizeof(BYTE));
		buffer.Write(&pad3, sizeof(BYTE));
		buffer.Write(&protobuff_length, sizeof(WORD));
		buffer.Write(data.SerializePartialAsString().c_str(), protobuff_length);

		BYTE padding = 0;
		while (((PROTOBUF_HEADER_SIZE + protobuff_length) + padding) % 8 != 0 && padding < 10)
			buffer.Write(&++padding, 1);
	}

	// -- return packet size without header
	const WORD get_size() const
	{
		return size;
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

private:
	WORD size;
	BYTE encrypt;
	BYTE compress;

	WORD CMD;
	BYTE pad;
	BYTE pad1;
	BYTE pad2;
	BYTE pad3;

	WORD protobuff_length;

	T data;

	MessageBuffer buffer;
};
