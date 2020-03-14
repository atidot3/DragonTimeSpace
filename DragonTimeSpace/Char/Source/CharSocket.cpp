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
	LOG_WARNING << "Get packet: command type [" << std::to_string(p->CMD) << "] param: [" << std::to_string(p->CMD) << "]";
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

	struct version
	{
		uint32_t reserve;
		uint32_t version;
	};

	version* data = (version*)packet.GetPacketData();
	LOG_DEBUG << "version : " << data->version;

	return true;
}
bool CharSocket::onReceiveUserInfo(const Packet& packet)
{
	LOG_DEBUG << "Received user info";

#pragma pack(1)
	struct PhoneInfo
	{
		char phone_uuid[100];
		char pushid[100];
		char phone_model[100];
		char resolution[100];
		char opengl[100];
		char _cpu[100];
		char ram[100];
		char os[100];
	};
	struct stIphoneLoginUserCmd_CS
	{
		uint32_t accid;
		short user_type;
		uint32_t temp_user_id;
		BYTE user[48];
		BYTE password[33];
		BYTE mac[24];
		BYTE szFlat[100];
		PhoneInfo info;
	};
#pragma pack()

	stIphoneLoginUserCmd_CS* data = (stIphoneLoginUserCmd_CS*)packet.GetPacketData();
	LOG_DEBUG << "accid: " << data->accid;

	return true;
}