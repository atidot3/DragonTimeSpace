#pragma once

#include <Utils/Define.h>

#pragma pack(1)
struct char_packet
{
	WORD CMD;
	int32_t timestamp;
};
// RECV
struct gateway_version : public char_packet
{
	uint32_t reserve;
	uint32_t version;
};
#pragma pack()

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

#pragma pack(1)
struct res_test
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

struct res_testnopad
{
	WORD size;
	BYTE encrypt;
	BYTE compress;

	WORD CMD;

	WORD protobuff_length;
};
#pragma pack()