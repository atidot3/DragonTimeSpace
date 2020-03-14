#pragma once

#include <Utils\Opcodes.h>
#include <Utils\Define.h>

#pragma pack(1)

//------------------------------------------------------------------
struct sUT_ENTER_CHAT
{
	ACCOUNTID			accountId;
	BYTE				abyAuthKey[MAX_SIZE_AUTH_KEY];
	DWORD               dwUnk;
};
//------------------------------------------------------------------
struct sUT_CHAT_MESSAGE_SAY
{
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_CHAT_MESSAGE_SHOUT
{
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_CHAT_MESSAGE_FIND_PARTY
{
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_CHAT_MESSAGE_TRADE
{
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_CHAT_MESSAGE_WHISPER
{
	WCHAR				awchReceiverCharName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
	//- yoshiki : I don't remember why "dwTellMessageID" was needed before.
	//	DWORD				dwTellMessageID;
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_CHAT_MESSAGE_PARTY
{
	BYTE				byChattingType;		// eDBO_CHATTING_TYPE
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_CHAT_MESSAGE_GUILD
{
	BYTE				byChattingType;		// eDBO_CHATTING_TYPE
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_GUILD_DISBAND_REQ
{
};
//------------------------------------------------------------------
struct sUT_GUILD_DISBAND_CANCEL_REQ
{
};
//------------------------------------------------------------------
struct sUT_GUILD_RESPONSE_INVITATION
{
	BYTE				byResponse;		// eINVITATION_RESPONSE
};
//------------------------------------------------------------------
struct sUT_GUILD_LEAVE_REQ
{
};
//------------------------------------------------------------------
struct sUT_GUILD_KICK_OUT_REQ
{
	CHARACTERID			targetMemberCharId;
};
//------------------------------------------------------------------
struct sUT_GUILD_APPOINT_SECOND_MASTER_REQ
{
	CHARACTERID			targetMemberCharId;
};
//------------------------------------------------------------------
struct sUT_GUILD_DISMISS_SECOND_MASTER_REQ
{
	CHARACTERID			targetMemberCharId;
};
//------------------------------------------------------------------
struct sUT_GUILD_CHANGE_GUILD_MASTER_REQ
{
	CHARACTERID			targetMemberCharId;
};
//------------------------------------------------------------------
struct sUT_CHAT_MESSAGE_PRIVATESHOP_BUSINESS
{
	WCHAR				awchReceiverCharName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
	//- yoshiki : I don't remember why "dwTellMessageID" was needed before.
	//	DWORD				dwTellMessageID;
	WORD				wMessageLengthInUnicode;
	WCHAR				awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_FRIEND_ADD_REQ
{
	WCHAR				wchName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_FRIEND_DEL_REQ
{
	CHARACTERID			targetID;
};
//------------------------------------------------------------------
struct sUT_FRIEND_MOVE_REQ
{
	CHARACTERID			targetID;
};
//------------------------------------------------------------------
struct sUT_FRIEND_BLACK_ADD_REQ
{
	WCHAR				awchName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_FRIEND_BLACK_DEL_REQ
{
	CHARACTERID			targetID;
};
//------------------------------------------------------------------
struct sUT_RANKBATTLE_RANK_LIST_REQ
{
	DWORD				dwPage;
	BYTE				byCompareDay;
};
//------------------------------------------------------------------
struct sUT_RANKBATTLE_RANK_FIND_CHARACTER_REQ
{
	DWORD				dwPage;
	BYTE				byCompareDay;

	WCHAR				wszCharName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_RANKBATTLE_RANK_COMPARE_DAY_REQ
{
	DWORD				dwPage;
	BYTE				byCompareDay;
};
//------------------------------------------------------------------
struct sUT_GUILD_CHANGE_NOTICE_REQ
{
	WORD				wNoticeLengthInUnicode;
	WCHAR				awchNotice[MAX_LENGTH_OF_GUILD_NOTICE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_TMQ_RECORD_LIST_REQ
{
	TBLIDX						tmqTblidx;
	BYTE						byDifficult;
};
//------------------------------------------------------------------
struct sUT_TMQ_MEMBER_LIST_REQ
{
	TBLIDX						tmqTblidx;
	BYTE						byDifficult;
	BYTE						byRank;		// 0 : Best 1~5:
};
//------------------------------------------------------------------
struct sUT_BUDOKAI_TOURNAMENT_INDIVIDUAL_LIST_REQ
{
	BYTE						byReceivedListCount;
};
//------------------------------------------------------------------
struct sUT_BUDOKAI_TOURNAMENT_INDIVIDUAL_INFO_REQ
{
	WORD						awJoinId[2];
};
//------------------------------------------------------------------
//------------------------------------------------------------------
struct sUT_BUDOKAI_TOURNAMENT_TEAM_LIST_REQ
{
	BYTE						byReceivedListCount;
};
//------------------------------------------------------------------
struct sUT_BUDOKAI_TOURNAMENT_TEAM_INFO_REQ
{
	WORD						awJoinId[2];
};
//------------------------------------------------------------------
struct sUT_PETITION_CHAT_START_RES
{
	//PETITIONID					petitionID;
	WORD						wResultCode;
	ACCOUNTID					gmAccountID;
};
//------------------------------------------------------------------
struct sUT_PETITION_CHAT_USER_SAY_REQ
{
	//PETITIONID					petitionID;
	ACCOUNTID					gmAccountID;
	WORD						wMessageLengthInUnicode;
	WCHAR						awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_PETITION_CHAT_USER_END_NFY
{
	ACCOUNTID					gmAccountID;
};
//------------------------------------------------------------------
struct sUT_PETITION_CHAT_GM_SAY_RES
{
	WORD						wResultCode;
	ACCOUNTID					gmAccountID;
};
//------------------------------------------------------------------
struct sUT_PETITION_USER_INSERT_REQ
{
	WCHAR						awchUserCharName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
	//WCHAR						awchQuestionContent[MAX_SIZE_QUESTION_CONTENT_UNICODE + 1];
	//PETITIONCATEGORY			nCategory1;//ePETITIONSYSTEM_CATEGORY_1
	//PETITIONCATEGORY			nCategory2;//ePETITIONSYSTEM_CATEGORY_2
};
//------------------------------------------------------------------
struct sUT_PETITION_CONTENT_MODIFY_REQ
{
	//PETITIONID					petitionID;
	//WCHAR						awchQuestionContent[MAX_SIZE_QUESTION_CONTENT_UNICODE + 1];
	//PETITIONCATEGORY			nCategory1;//ePETITIONSYSTEM_CATEGORY_1
	//PETITIONCATEGORY			nCategory2;//ePETITIONSYSTEM_CATEGORY_2
};
//------------------------------------------------------------------
struct sUT_PETITION_SATISFACTION_NFY
{
	//PETITIONID					petitionID;
	ACCOUNTID					gmAccountID;
	BYTE						bySatisfactionRate;
};
//------------------------------------------------------------------
struct sUT_PETITION_USER_CANCEL_REQ
{
	//PETITIONID					petitionID;
	ACCOUNTID					gmAccountID;
};
//------------------------------------------------------------------
struct sUT_DOJO_BUDOKAI_SEED_ADD_REQ
{
	WCHAR				wszCharName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_DOJO_BUDOKAI_SEED_DEL_REQ
{
	WCHAR				wszCharName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_DOJO_NOTICE_CHANGE_REQ
{
	WORD				wNoticeLengthInUnicode;
	WCHAR				awchNotice[MAX_LENGTH_OF_GUILD_NOTICE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_CHAT_USER_ON_CHANNEL_UPDATE_NFY
{
	//WORD				wMessageLengthInUnicode;
	//WCHAR				awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUT_HLS_SLOT_MACHINE_INFO_REQ
{
	BYTE TabType;//0 Waggu 1 Event
	BYTE   unk;
};
struct sUT_HLS_SLOT_MACHINE_EXTRACT_REQ
{
	BYTE MachineID;
	BYTE   unk;
	BYTE   PlayTimes;
};
struct sUT_HLS_SLOT_MACHINE_WINNER_INFO_REQ
{
	BYTE MachineID;
	BYTE unk;
};
//------------------------------------------------------------------
const char * GetPacketName_UT(WORD wOpCode);
#pragma pack()