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
#pragma pack()