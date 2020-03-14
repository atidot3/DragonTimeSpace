#include "ChatUT.h"
#include <Network\Packet\Packet.h>

const char * s_packetName_UT[] =
{
	DECLARE_PACKET_NAME(UT_ENTER_CHAT),
	DECLARE_PACKET_NAME(UT_CHAT_MESSAGE_SAY),
	DECLARE_PACKET_NAME(UT_CHAT_MESSAGE_SHOUT),
	DECLARE_PACKET_NAME(UT_CHAT_MESSAGE_WHISPER),
	DECLARE_PACKET_NAME(UT_CHAT_MESSAGE_PARTY),
	DECLARE_PACKET_NAME(UT_CHAT_MESSAGE_GUILD),

	DECLARE_PACKET_NAME(UT_GUILD_DISBAND_REQ),
	DECLARE_PACKET_NAME(UT_GUILD_DISBAND_CANCEL_REQ),
	DECLARE_PACKET_NAME(UT_GUILD_RESPONSE_INVITATION),
	DECLARE_PACKET_NAME(UT_GUILD_LEAVE_REQ),
	DECLARE_PACKET_NAME(UT_GUILD_KICK_OUT_REQ),
	DECLARE_PACKET_NAME(UT_GUILD_APPOINT_SECOND_MASTER_REQ),
	DECLARE_PACKET_NAME(UT_GUILD_DISMISS_SECOND_MASTER_REQ),
	DECLARE_PACKET_NAME(UT_GUILD_CHANGE_GUILD_MASTER_REQ),

	DECLARE_PACKET_NAME(UT_CHAT_MESSAGE_PRIVATESHOP_BUSINESS),// [10/31/2007 SGpro]

	DECLARE_PACKET_NAME(UT_FRIEND_ADD_REQ),		// 模备 眠啊
	DECLARE_PACKET_NAME(UT_FRIEND_DEL_REQ),		// 模备 昏力
	DECLARE_PACKET_NAME(UT_FRIEND_MOVE_REQ),		// 模备 -> 喉发府胶飘肺 捞悼
	DECLARE_PACKET_NAME(UT_FRIEND_BLACK_ADD_REQ),		// 模备 喉发 府胶飘 眠啊
	DECLARE_PACKET_NAME(UT_FRIEND_BLACK_DEL_REQ),		// 模备 喉发 府胶飘 昏力

	DECLARE_PACKET_NAME(UT_RANKBATTLE_RANK_LIST_REQ),
	DECLARE_PACKET_NAME(UT_RANKBATTLE_RANK_FIND_CHARACTER_REQ),
	DECLARE_PACKET_NAME(UT_RANKBATTLE_RANK_COMPARE_DAY_REQ),

	DECLARE_PACKET_NAME(UT_GUILD_CHANGE_NOTICE_REQ),
	DECLARE_PACKET_NAME(UT_TMQ_RECORD_LIST_REQ),
	DECLARE_PACKET_NAME(UT_TMQ_MEMBER_LIST_REQ),

	DECLARE_PACKET_NAME(UT_BUDOKAI_TOURNAMENT_INDIVIDUAL_LIST_REQ),
	DECLARE_PACKET_NAME(UT_BUDOKAI_TOURNAMENT_INDIVIDUAL_INFO_REQ),
	DECLARE_PACKET_NAME(UT_BUDOKAI_TOURNAMENT_TEAM_LIST_REQ),
	DECLARE_PACKET_NAME(UT_BUDOKAI_TOURNAMENT_TEAM_INFO_REQ),

	DECLARE_PACKET_NAME(UT_PETITION_CHAT_START_RES),
	DECLARE_PACKET_NAME(UT_PETITION_CHAT_USER_SAY_REQ),
	DECLARE_PACKET_NAME(UT_PETITION_CHAT_USER_END_NFY),
	DECLARE_PACKET_NAME(UT_PETITION_CHAT_GM_SAY_RES),
	DECLARE_PACKET_NAME(UT_PETITION_USER_INSERT_REQ),
	DECLARE_PACKET_NAME(UT_PETITION_CONTENT_MODIFY_REQ),
	DECLARE_PACKET_NAME(UT_PETITION_SATISFACTION_NFY),
	DECLARE_PACKET_NAME(UT_PETITION_USER_CANCEL_REQ),
	DECLARE_PACKET_NAME(UT_DOJO_BUDOKAI_SEED_ADD_REQ),
	DECLARE_PACKET_NAME(UT_DOJO_BUDOKAI_SEED_DEL_REQ),
	DECLARE_PACKET_NAME(UT_DOJO_NOTICE_CHANGE_REQ),
};


//------------------------------------------------------------------
//
//------------------------------------------------------------------
const char * GetPacketName_UT(WORD wOpCode)
{
	if (wOpCode < UT_OPCODE_BEGIN)
	{
		return "NOT DEFINED PACKET NAME : OPCODE LOW";
	}

	if (wOpCode > UT_OPCODE_END)
	{
		return "NOT DEFINED PACKET NAME : OPCODE HIGH";
	}

	int nIndex = wOpCode - UT_OPCODE_BEGIN;
	if (nIndex >= _countof(s_packetName_UT))
	{
		return "OPCODE BUFFER OVERFLOW";
	}

	return s_packetName_UT[nIndex];
}