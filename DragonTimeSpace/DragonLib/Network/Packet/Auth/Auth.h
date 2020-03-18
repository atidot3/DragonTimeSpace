#pragma once

//#include <Utils\Opcodes.h>
#include <Network\Packet\Packet.h>
#include "../../../Utils/Define.h"

const int AUTH_CONNECT_FIT = 120;
const int AUTH_CLIENT_IP = 15;
const int AUTH_LOGIN_REQ = 2;

const int CHECK_GATEWAY_VER = 1008;

// SEND
#pragma pack(1)
struct auth_packet
{
	BYTE CMD;
	BYTE CMD_PARAM;
	int32_t timestamp;
};
#pragma pack()
struct client_ip : public PACKETDATA, auth_packet
{
	char ip[16];
	uint32_t bullshit;
};
#pragma pack(1)
struct login_accept : public PACKETDATA, auth_packet
{
	uint32_t	dwUserID;
	uint32_t	loginTempID;
	BYTE		ip[16];
	short		wdPort;
	BYTE		key[256];
	DWORD		state;
};
struct login_failed : public PACKETDATA, auth_packet
{
	BYTE error_code;
};
#pragma pack()


// RECV
struct real_login
{
	char user[48];
	char password[33];
	short game;
	short zone;
	char passport[7];
	char max_addr[13];
	char uuid[25];
	short wd_net_type;
	char pass_pod_password[9];
	short user_type;
};
