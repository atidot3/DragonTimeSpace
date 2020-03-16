#include "AuthSocket.h"

#include <Network/Packet/Packet.h>
#include <Network\Packet\Auth\Auth.h>

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
AuthSocket::AuthSocket(boost::asio::io_context &service)
	: Socket{ service }
{
	methodList.emplace_back(AUTH_CONNECT_FIT, std::bind(&AuthSocket::onConnectFit, this, std::placeholders::_1));
	methodList.emplace_back(AUTH_CLIENT_IP, std::bind(&AuthSocket::OnClientIp, this, std::placeholders::_1));
	methodList.emplace_back(AUTH_LOGIN_REQ, std::bind(&AuthSocket::OnLoginReq, this, std::placeholders::_1));
}

//----------------------------------------
//	Called when we open the socket
//----------------------------------------
AuthSocket::~AuthSocket()
{
	LOG_TRACE << "AuthSocket connection close: [" << GetRemoteEndPoint() << "]";
}
void AuthSocket::OnConnected()
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
bool AuthSocket::ProcessIncomingData(const Packet& packet)
{
	auth_packet* p = (auth_packet*)packet.GetPacketData();
	LOG_WARNING << "Get packet: command type [" << std::to_string(p->CMD) << "] param: [" << std::to_string(p->CMD_PARAM) << "]";
	for (const auto& method : methodList)
	{
		if (std::get<0>(method) == p->CMD_PARAM)
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
bool AuthSocket::onConnectFit(const Packet& packet)
{
	return true;
}
bool AuthSocket::OnClientIp(const Packet& packet)
{
	LOG_DEBUG << "Received send client ip";

	client_ip stru_ip;

	stru_ip.size = sizeof(client_ip) - 4;
	stru_ip.encrypt = 0;
	stru_ip.compress = 0;
	stru_ip.CMD = 104;
	stru_ip.CMD_PARAM = 16;
	stru_ip.timestamp = 0;
	std::string ip = "073.240.48.134"; //+ this->GetAddress();
	memcpy(stru_ip.ip, ip.c_str(), 16);

	st_Write(stru_ip);
	return true;
}
bool AuthSocket::OnLoginReq(const Packet& packet)
{
	LOG_DEBUG << "Received login data";

	real_login* real_data = (real_login*)packet.GetPacketData();
	login_accept login_ok;
	{
		memset(login_ok.ip, '\0', 16);
		memset(login_ok.key, '\0', 256);
	}

	login_ok.size = sizeof(login_accept) - 4;
	login_ok.CMD = 104;
	login_ok.CMD_PARAM = 4;
	login_ok.timestamp = 0;
	login_ok.compress = 0;
	login_ok.encrypt = 0;

	login_ok.dwUserID = 14578;
	login_ok.loginTempID = 421;
	login_ok.state = BYTE(1);
	login_ok.wdPort = WORD(50300);

	std::string ip = "10.0.0.209";
	memcpy(login_ok.ip, ip.c_str(), strlen("10.0.0.209"));
	memcpy(login_ok.key, "coucou", strlen("coucou"));

	st_Write(login_ok);
	return true;
}