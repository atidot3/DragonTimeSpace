#pragma once

#include <Utils/Define.h>

const int CHAR_GATEWAY_VERSION = 2002;
const int CHAR_USER_INFO = 2004;

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
#pragma pack(0)

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

#pragma pack(4)
// SEND
struct MSG_Ret_UserMapInfo_SC
{
	WORD size;
	BYTE encrypt;
	BYTE compress;

	WORD CMD;
	int32_t timestamp;

	int32_t _mapid;
	BYTE _mapname[128];
	BYTE _filename[128];
	float x, y;
	uint32_t _lineid;
	uint32_t _copymapidx;
	uint32_t _subcopymapidx;
	unsigned long _sceneid;
	// IExtension extensionObject;
};
#pragma pack()