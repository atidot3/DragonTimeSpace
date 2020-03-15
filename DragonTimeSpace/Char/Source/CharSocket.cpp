#include "CharSocket.h"

#include <Network/Packet/Packet.h>
#include <Network\Packet\Char\Char.h>
#include <Network\Messages\message.pb.h>
//#include <Utils/Opcodes.h>
//#include <Utils/ResultCode.h>
#include <Utils/Logger/Logger.h>
#include <Utils\Utils.h>

#include <Configuration\Configuration.h>
#include <Database\Repository\RepositoryManager.h>
#include <Configuration\Configuration.h>

//----------------------------------------
//	Called when we open the socket
//----------------------------------------
CharSocket::CharSocket(boost::asio::io_context &service)
	: Socket{ service }
{
	methodList.emplace_back(CHAR_GATEWAY_VERSION, std::bind(&CharSocket::onCheckGatewayVer, this, std::placeholders::_1));
	methodList.emplace_back(CHAR_USER_INFO, std::bind(&CharSocket::onReceiveUserInfo, this, std::placeholders::_1));

	methodList.emplace_back(2273, std::bind(&CharSocket::onReceiveProtobuf, this, std::placeholders::_1));
}

//----------------------------------------
//	Called when we open the socket
//----------------------------------------
CharSocket::~CharSocket()
{
	LOG_TRACE << "CharSocket connection close: [" << GetRemoteEndPoint() << "]";
}
void CharSocket::OnConnected()
{
	LOG_DEBUG << "New Connection from: " << this->GetAddress();

	/*
			On connected received :

			opcode : (104 ? 120)
			version should be 2000

			uint_32 reserve;
			uint_32 version;

	*/
}

//----------------------------------------
//	We got incomming data from our player
//	Return false in case we was not able to parse data
//	Set internalError = ResultCodes::RESULT_FAIL in case of something unexpected to kick the connection
//----------------------------------------
bool CharSocket::ProcessIncomingData(const Packet& packet)
{
	char_packet* p = (char_packet*)packet.GetPacketData();
	LOG_WARNING << "Get packet: command type [" << std::to_string(p->CMD) << "]";
	for (const auto& method : methodList)
	{
		if (std::get<0>(method) == p->CMD)
		{
			auto _method = std::get<1>(method);
			_method(packet);
			return true;
		}
	}
	//LOG_WARNING << "Get an unexpected packet: [" << std::to_string(packet._header.CMD_PARAM) << "]";
	internalError = 1000;
	return false;
}
bool CharSocket::onCheckGatewayVer(const Packet& packet)
{
	LOG_DEBUG << "Received gateway check version";

	gateway_version* data = (gateway_version*)packet.GetPacketData();
	LOG_DEBUG << "version : " << data->version;

	return true;
}

void log_data(const unsigned char* data, const int32_t& size)
{
	std::cout << std::hex << std::setfill('0');  // needs to be set only once
	auto* ptr = data;
	for (int i = 0; i < size; i++, ptr++)
	{
		std::cout << std::setw(2) << static_cast<unsigned>(*ptr) << " ";
	}
	std::cout << std::endl;
}

bool CharSocket::onReceiveUserInfo(const Packet& packet)
{
#pragma pack(1)
	struct res {
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


	LOG_DEBUG << "Received user info";
	stIphoneLoginUserCmd_CS* data = (stIphoneLoginUserCmd_CS*)packet.GetPacketData();
	msg::MSG_Ret_UserMapInfo_SC* mapInfo = new msg::MSG_Ret_UserMapInfo_SC();
	msg::FloatMovePos pos;

	mapInfo->set_mapid(695);
	mapInfo->set_filename(std::move(std::string("toto")));
	mapInfo->set_mapname(std::move(std::string("toto")));
	mapInfo->set_lineid(64);
	mapInfo->set_sceneid(864);
	mapInfo->set_allocated_pos(&pos);
	mapInfo->set_copymapidx(123);
	mapInfo->set_subcopymapidx(486);

	const unsigned short protobuff_data_size = mapInfo->ByteSizeLong();
	BYTE * protobuff_buffer = new BYTE[protobuff_data_size];
	mapInfo->SerializeToArray(protobuff_buffer, protobuff_data_size);
	

	LOG_DEBUG << "Protobuff packet to send HEX: ";
	log_data(protobuff_buffer, protobuff_data_size);


	res resp;
	MessageBuffer buffer;

	buffer.Resize((sizeof(res) + protobuff_data_size));

	resp.size = (sizeof(res) - 4) + protobuff_data_size;
	resp.CMD = 2273;
	resp.compress = 0;
	resp.encrypt = 0;
	resp.pad = 0x81;
	resp.pad1 = 0xde;
	resp.pad2 = 0x46;
	resp.pad3 = 0xdf;
	resp.protobuff_length = protobuff_data_size;
	

	buffer.Write(&resp, sizeof(res));
	buffer.Write(protobuff_buffer, protobuff_data_size);
	buffer.Write("0", 1);
	buffer.Resize(sizeof(res) + protobuff_data_size + 1);

	LOG_DEBUG << "PACKET TO SEND HEX:";
	log_data(buffer.GetReadPointer(), sizeof(res) + protobuff_data_size + 1);

	_writeQueue.push(std::move(buffer));;
	return true;
}

#include <Network/Messages/ParseProto.h>
bool CharSocket::onReceiveProtobuf(const Packet& packet)
{
	LOG_DEBUG << "on protobuf received";

	// -- Protobuf packet recev :
	/*
	
		2 bytes		=>	commandId
		4 bytes		=>	????
		2 bytes		=>	protobuf data size
		X bytes		=>	protobuf data
	
	*/

	LOG_DEBUG << "PACKET HEX: ";
	log_data((unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);

	// -- for some reason the received protobuf packet looks like:
	// -- HEADER	4 sized
	// -- cmdId		2 size
	// -- int time?	4 size
	// -- padding ?	2 size
	MessageBuffer buffer;
	buffer.Resize((packet.GetPacketHeader().size - 8));
	buffer.Write(&packet.GetPacketData()[8], (packet.GetPacketHeader().size - 8));

	LOG_DEBUG << "USERMAP HEX[from 8]: ";
	log_data(buffer.GetReadPointer(), (packet.GetPacketHeader().size - 8));

	msg::MSG_Ret_UserMapInfo_SC mapInfo;
	bool isOk = ParseProtoMsg<msg::MSG_Ret_UserMapInfo_SC>((const char*)buffer.GetReadPointer(), (packet.GetPacketHeader().size - 8), mapInfo);

	LOG_DEBUG << "mapid " << mapInfo.mapid();
	LOG_DEBUG << "filename " << mapInfo.filename();
	LOG_DEBUG << "mapname " << mapInfo.mapname();
	LOG_DEBUG << "copymapidx " << mapInfo.copymapidx();
	LOG_DEBUG << "subcopymapidx " << mapInfo.subcopymapidx();
	LOG_DEBUG << "lineid " << mapInfo.lineid();
	LOG_DEBUG << "mapInfo ByteSizeLong: " << mapInfo.ByteSizeLong();
	
	return true;
}