#include "CharSocket.h"

#include <Network/Packet/Packet.h>
#include <Network\Packet\Char\Char.h>

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
bool CharSocket::onReceiveUserInfo(const Packet& packet)
{
	LOG_DEBUG << "Received user info";

	stIphoneLoginUserCmd_CS* data = (stIphoneLoginUserCmd_CS*)packet.GetPacketData();
	LOG_DEBUG << "accid: " << data->accid;

	struct Vector2
	{
		float x, y;
	};
#pragma pack(1)
	struct MSG_Ret_UserMapInfo_SC : public PACKETDATA, char_packet
	{
		int32_t _mapid;
		BYTE _mapname[32];
		BYTE _filename[32];
		//Vector2 _pos;
		//uint32_t _lineid;
		//uint32_t _copymapidx;
		//uint32_t _subcopymapidx;
		//unsigned long _sceneid;
		// IExtension extensionObject;
	};
#pragma pack()

	MSG_Ret_UserMapInfo_SC map_info;
	{
		map_info.CMD = 2273;
		map_info.compress = 0;
		map_info.encrypt = 0;
		map_info.size = sizeof(MSG_Ret_UserMapInfo_SC) - 4;
		map_info.timestamp = 0;

		//map_info._copymapidx = 0;
		//memcpy(map_info._filename, "coucou", strlen("coucou"));
		memcpy(map_info._mapname, "fb_10022.xml", strlen("fb_10022.xml"));
		//map_info._lineid = 0;
		map_info._mapid = 150;
		//map_info._pos = { 10.0f, 10.0f };
		//map_info._sceneid = 1;
		//map_info._subcopymapidx = 0;
	}
	Write(map_info);

	return true;
}