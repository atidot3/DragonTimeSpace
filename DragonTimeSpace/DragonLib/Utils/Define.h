#ifndef _DEFINE_H_
#define _DEFINE_H_

#pragma once

#include <cstdint>
#include <WinSock2.h>
#include <Network/Messages/message.pb.h>


#define LINE_IMP(l)				#l
#define LINE(l)					LINE_IMP( l )
#define TS_CODE_TRACE()			"[" __FILE__ "] [" __FUNCTION__ "] [" LINE( __LINE__ ) "]"

enum ServerState
{
	DOWN = 0,
	UP
};

#endif