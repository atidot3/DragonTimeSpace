#pragma once

#include <Utils/Define.h>

const int CHAR_GATEWAY_VERSION = 2002;
const int CHAR_USER_INFO = 2004;

struct char_packet
{
	WORD CMD;
	int32_t timestamp;
};

// SEND

// RECV
struct gateway_version : public char_packet
{
	uint32_t reserve;
	uint32_t version;
};

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
struct stIphoneLoginUserCmd_CS : public char_packet
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