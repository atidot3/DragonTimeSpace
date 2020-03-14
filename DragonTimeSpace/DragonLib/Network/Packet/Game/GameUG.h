#ifndef _GAMEUG_H_
#define _GAMEUG_H_

#pragma once

#include <Utils\Opcodes.h>
#include <Game\Entity\Skill\Skill.h>
#include <Game\Guilde\Dojo\Dojo.h>
#include <Game\Object\Item.h>
#include <Game\Mail\Mail.h>
#include <Game\Party\Party.h>

#pragma pack(1)

//------------------------------------------------------------------
struct sUG_GAME_ENTER_REQ {
	ACCOUNTID			accountId;
	CHARACTERID			charId;
	BYTE				abyAuthKey[MAX_SIZE_AUTH_KEY];
	bool				bTutorialMode;	// 튜토리얼 요청 값
};
//------------------------------------------------------------------
struct sUG_GAME_LEAVE_REQ {
};
//------------------------------------------------------------------
struct sUG_AUTH_KEY_FOR_COMMUNITY_SERVER_REQ {
};
//------------------------------------------------------------------
struct sUG_ENTER_WORLD {
};
//------------------------------------------------------------------
struct sUG_SERVER_COMMAND {
	WORD				wMessageLengthInUnicode;
	WCHAR				awchCommand[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUG_CHAR_READY_FOR_COMMUNITY_SERVER_NFY {
};
//------------------------------------------------------------------
struct sUG_CHAR_READY_TO_SPAWN {
};
//------------------------------------------------------------------
struct sUG_CHAR_READY {
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
};
//------------------------------------------------------------------
struct sUG_CHAR_MOVE {
//- yoshiki : Do we use dwTimeStamp or not?
	DWORD				dwTimeStamp;
	BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
	Vector3				vCurLoc;
	Vector2				vCurDir;
	BYTE				byMoveDirection;
};
//------------------------------------------------------------------
struct sUG_CHAR_DEST_MOVE {
//- yoshiki : Do we use dwTimeStamp or not?
DWORD				dwTimeStamp;
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
Vector3			vCurLoc;
Vector3			vDestLoc;
};
//------------------------------------------------------------------
struct sUG_CHAR_CHANGE_HEADING {
//- yoshiki : Do we use dwTimeStamp or not?
DWORD				dwTimeStamp;
Vector3			vCurrentPosition;
Vector3			vCurrentHeading;
};
//------------------------------------------------------------------
struct sUG_CHAR_MOVE_SYNC {
//- yoshiki : Do we use dwTimeStamp or not?
DWORD				dwTimeStamp;
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
Vector3			vCurLoc;
Vector3			vCurDir;
};
//------------------------------------------------------------------
struct sUG_CHAR_CHANGE_DIRECTION_ON_FLOATING {
//- yoshiki : Do we use dwTimeStamp or not?
DWORD				dwTimeStamp;
Vector3				vCurDir;
BYTE				byMoveDirection;
};
//------------------------------------------------------------------
struct sUG_CHAR_FOLLOW_MOVE {
//- yoshiki : Do we use dwTimeStamp or not?
DWORD				dwTimeStamp;
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
HOBJECT				hTarget;
float				fDistance;
BYTE				byMovementReason;
};
//------------------------------------------------------------------
struct sUG_CHAR_DASH_KEYBOARD {
//- yoshiki : Do we use dwTimeStamp or not?
DWORD				dwTimeStamp;
Vector3				vCurLoc;
Vector2				vCurDir;
BYTE				byMoveDirection;
};
//------------------------------------------------------------------
struct sUG_CHAR_DASH_MOUSE {
//- yoshiki : Do we use dwTimeStamp or not?
DWORD				dwTimeStamp;
Vector3				vDestLoc;
};
//------------------------------------------------------------------
struct sUG_CHAR_JUMP {
Vector3			vCurrentHeading;
};
//------------------------------------------------------------------
struct sUG_CHAR_JUMP_END {
};
//------------------------------------------------------------------
struct sUG_CHAR_FALLING {
bool				bIsFalling;
Vector3			vCurLoc;
Vector2			vCurDir;
BYTE				byMoveDirection;
};
//------------------------------------------------------------------
struct sUG_CHAR_TOGG_SITDOWN {
bool				bSitDown;
};
//------------------------------------------------------------------
struct sUG_CHAR_TOGG_FIGHTING {
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
bool				bFightMode;
};
//------------------------------------------------------------------
struct sUG_CHAR_TOGG_RUNNING {
bool				bRunMode;
};
//------------------------------------------------------------------
struct sUG_CHAR_TARGET_SELECT {
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
HOBJECT				hTarget;
};
//------------------------------------------------------------------
struct sUG_CHAR_TARGET_INFO {
HOBJECT				hTarget;
};
//------------------------------------------------------------------
struct sUG_CHAR_TARGET_FACING {
HOBJECT				hTarget;
};
//------------------------------------------------------------------
struct sUG_CHAR_ATTACK_BEGIN {
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
BYTE				byType;	// 형석 : 임시
};
//------------------------------------------------------------------
struct sUG_CHAR_ATTACK_END {
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
BYTE				byType;	// 형석 : 임시
};
//------------------------------------------------------------------
struct sUG_CHAR_CHARGE {
bool				bCharge; // ON/OFF
};
//------------------------------------------------------------------
struct sUG_CHAR_GUARD_MODE
{
	bool				bIsOn;		// On/Off
};
//------------------------------------------------------------------
struct sUG_CHAR_TELEPORT_REQ {
};
//------------------------------------------------------------------
struct sUG_CHAR_BIND_REQ {
TBLIDX				bindObjectTblidx;
};
//------------------------------------------------------------------
struct sUG_CHAR_REVIVAL_REQ {
BYTE				byRevivalRequestType;		// eDBO_REVIVAL_REQUEST_TYPE
};
//------------------------------------------------------------------
struct sUG_CHAR_SERVER_CHANGE_REQ {
};
//------------------------------------------------------------------
struct sUG_CHAR_CHANNEL_CHANGE_REQ {
SERVERCHANNELID		destServerChannelId;
};
//------------------------------------------------------------------
struct sUG_CHAR_EXIT_REQ {
};
//------------------------------------------------------------------
struct sUG_GAME_EXIT_REQ {
};
//------------------------------------------------------------------
struct sUG_CHAR_AWAY_REQ {
bool	bIsAway;		// AwayOn 1: Awayoff: 0
};
//------------------------------------------------------------------
struct sUG_CHAR_KEY_UPDATE_REQ {
BYTE	byCount;		// 변경갯수
//sSHORTCUT_UPDATE_DATA asData[SHORTCUT_MAX_COUNT]; // TODO
};
//------------------------------------------------------------------
struct sUG_CHAR_DIRECT_PLAY_ACK {
};
//------------------------------------------------------------------
struct sUG_CHAR_KNOCKDOWN_RELEASE_NFY {
};
//------------------------------------------------------------------
struct sUG_CHAR_SKILL_REQ {
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
BYTE				bySlotIndex;
BYTE				byRpBonusType;		// eDBO_RP_BONUS_TYPE
HOBJECT				hTarget;
// If skill effect should be applied on a target character, too, the target character must be included in both byApplyTargetCount and ahApplyTarget.
// 스킬의 타겟 캐릭터가 스킬 적용 대상인 경우에는 타겟 캐릭터도 byApplyTargetCount와 ahApplyTarget에 포함되어야 한다.
// by YOSHIKI(2007-01-12 {
BYTE				byApplyTargetCount;
HOBJECT				ahApplyTarget[MAX_NUMBER_OF_SKILL_TARGET];
};
//------------------------------------------------------------------
struct sUG_SKILL_TARGET_LIST {
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
										// If skill effect should be applied on a target character, too, the target character must be included in both byApplyTargetCount and ahApplyTarget.
										// 스킬의 타겟 캐릭터가 스킬 적용 대상인 경우에는 타겟 캐릭터도 byApplyTargetCount와 ahApplyTarget에 포함되어야 한다.
										// by YOSHIKI(2007-02-22 {
BYTE				byApplyTargetCount;
HOBJECT				ahApplyTarget[MAX_NUMBER_OF_SKILL_TARGET];
};
//------------------------------------------------------------------
struct sUG_SKILL_LEARN_REQ {
TBLIDX				skillTblidx;
};
//------------------------------------------------------------------
struct sUG_SKILL_UPGRADE_REQ {
BYTE				bySlotIndex;
};
//------------------------------------------------------------------
struct sUG_SKILL_RP_BONUS_SETTING_REQ {
BYTE				bySlotIndex;
BYTE				byRpBonusType;		// eDBO_RP_BONUS_TYPE
bool				bIsRpBonusAuto;
};
//------------------------------------------------------------------
struct sUG_HTB_START_REQ {
HOBJECT				hTarget;
BYTE				bySkillSlot;
};
//------------------------------------------------------------------
struct sUG_HTB_LEARN_REQ {
HOBJECT				hTrainer; // 트레이너 핸들
TBLIDX				skillId; // HTB set 테이블 번호
};
//------------------------------------------------------------------
struct sUG_HTB_FORWARD_REQ {
Vector3			vCurLoc; // 진행 위치
Vector2			vCurDir; // 진행 방향
};
//------------------------------------------------------------------
struct sUG_HTB_RP_BALL_USE_REQ {
BYTE				byRpBallCount;
};
//------------------------------------------------------------------
struct sUG_BUFF_DROP_REQ {
BYTE				bySourceType;		// eDBO_OBJECT_SOURCE
TBLIDX				tblidx;
};
//------------------------------------------------------------------
struct sUG_ITEM_MOVE_REQ {
BYTE				bySrcPlace;
BYTE				bySrcPos;
BYTE				byDestPlace;
BYTE				byDestPos;
};
//------------------------------------------------------------------
struct sUG_ITEM_MOVE_STACK_REQ {
BYTE				bySrcPlace;
BYTE				bySrcPos;
BYTE				byDestPlace;
BYTE				byDestPos;
BYTE				byStackCount;
};
//------------------------------------------------------------------
struct sUG_ITEM_DELETE_REQ {
BYTE				bySrcPlace;
BYTE				bySrcPos;
};
//------------------------------------------------------------------
struct sUG_ITEM_EQUIP_REPAIR_REQ {
HOBJECT				handle;			// NpcHandle
};
//------------------------------------------------------------------
struct sUG_ITEM_PICK_REQ {
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
HOBJECT				handle;			// ItemHandle
};
//------------------------------------------------------------------
struct sUG_ITEM_REPAIR_REQ {
HOBJECT				handle;			// NpcHandle
BYTE				byPlace;
BYTE				byPos;
};
//------------------------------------------------------------------
struct sUG_ITEM_USE_REQ {
HOBJECT				hTarget;
BYTE				byPlace;
BYTE				byPos;
};
//------------------------------------------------------------------
struct sUG_ITEM_UPGRADE_REQ {
HOBJECT				handle;				// NpcHandle
BYTE				byItemPlace;		// 업그레이드 할 아이템의 컨테이너 위치
BYTE				byItemPos;			// 업그레이드 할 아이템의 위치
BYTE				byStonPlace;		// 호이포이스톤 컨테이너 위치
BYTE				byStonPos;			// 호이포이스톤 위치
BYTE				byPosNum;			// 업그레이드 창의 조합위치: (아이템의 슬롯번호 * 10 + 호이포이스톤슬롯번호 { 
};
//------------------------------------------------------------------
struct sUG_ITEM_IDENTIFY_REQ {
BYTE				byPlace;			// 아이템 확인시의 확인 할 아이템의 컨테이너 위치
BYTE				byPos;				// 아이템의 포지션.
};
//------------------------------------------------------------------
struct sUG_ZENNY_PICK_REQ {
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
HOBJECT				handle;			// ItemHandle
};
//------------------------------------------------------------------
struct sUG_SHOP_START_REQ {
HOBJECT				handle;
};
//------------------------------------------------------------------
struct sUG_SHOP_BUY_REQ
{
	HOBJECT				handle;
	BYTE				byBuyCount;
	sSHOP_BUY_CART		sBuyData[MAX_BUY_SHOPPING_CART];
};
//------------------------------------------------------------------
struct sUG_SHOP_SELL_REQ {
HOBJECT				handle;
BYTE				bySellCount;
sSHOP_SELL_CART		sSellData[MAX_SELL_SHOPPING_CART]; // 3BYTE * 8 = 24
};
//------------------------------------------------------------------
struct sUG_SHOP_END_REQ {
};
//------------------------------------------------------------------
struct sUG_SHOP_SKILL_BUY_REQ {
HOBJECT				hNpchandle;
BYTE				byMerchantTab;
BYTE				byPos;
};
//------------------------------------------------------------------
struct sUG_PARTY_CREATE_REQ {
WCHAR				wszPartyName[MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUG_PARTY_DISBAND_REQ {
};
//------------------------------------------------------------------
struct sUG_PARTY_INVITE_REQ {
HOBJECT				hTarget;
// If the player belong to a party, the part of 'wszPartyName' doesn't need to be sent when inviting another player.
// 이미 파티에 가입한 상태에서 다른 플레이어를 초대할 때에는 wszPartyName 부분을 전송하지 않아도 된다.
// by YOSHIKI(2009-02-13 {
WCHAR				wszPartyName[MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUG_PARTY_INVITE_CHARID_REQ {
CHARACTERID			targetCharId;
// If the player belong to a party, the part of 'wszPartyName' doesn't need to be sent when inviting another player.
// 이미 파티에 가입한 상태에서 다른 플레이어를 초대할 때에는 wszPartyName 부분을 전송하지 않아도 된다.
// by YOSHIKI(2009-02-13 {
WCHAR				wszPartyName[MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUG_PARTY_INVITE_CHAR_NAME_REQ {
WCHAR				wszTargetName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
// If the player belong to a party, the part of 'wszPartyName' doesn't need to be sent when inviting another player.
// 이미 파티에 가입한 상태에서 다른 플레이어를 초대할 때에는 wszPartyName 부분을 전송하지 않아도 된다.
// by YOSHIKI(2009-02-13 {
WCHAR				wszPartyName[MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUG_PARTY_RESPONSE_INVITATION {
BYTE				byResponse;		// eINVITATION_RESPONSE
};
//------------------------------------------------------------------
struct sUG_PARTY_LEAVE_REQ {
};
//------------------------------------------------------------------
struct sUG_PARTY_KICK_OUT_REQ
{
	HOBJECT				hTargetMember;
};
//------------------------------------------------------------------
struct sUG_PARTY_CHANGE_LEADER_REQ {
HOBJECT				hTargetMember;
};
//------------------------------------------------------------------
struct sUG_PARTY_OPEN_CHARM_SLOT_REQ {
BYTE				byCharmInventoryIndex;
};
//------------------------------------------------------------------
struct sUG_PARTY_CLOSE_CHARM_SLOT_REQ {
};
//------------------------------------------------------------------
struct sUG_PARTY_REGISTER_VICTIM_ITEM_REQ {
BYTE				bySrcPlace;
BYTE				bySrcPos;
BYTE				byDestSlotIndex;
};
//------------------------------------------------------------------
struct sUG_PARTY_UNREGISTER_VICTIM_ITEM_REQ {
BYTE				byDestSlotIndex;
};
//------------------------------------------------------------------
struct sUG_PARTY_REGISTER_VICTIM_ZENNY_REQ {
DWORD				dwZenny;
};
//------------------------------------------------------------------
struct sUG_PARTY_UNREGISTER_VICTIM_ZENNY_REQ {
DWORD				dwZenny;
};
//------------------------------------------------------------------
struct sUG_PARTY_DECLARE_ZENNY_REQ {
DWORD				dwZennyToDeclare;
};
//------------------------------------------------------------------
struct sUG_PARTY_ACTIVATE_CHARM_REQ {
};
//------------------------------------------------------------------
struct sUG_PARTY_DEACTIVATE_CHARM_REQ {
BYTE				byCharmInventoryIndex;
};
//------------------------------------------------------------------
struct sUG_PARTY_CHANGE_ZENNY_LOOTING_METHOD_REQ {
BYTE				byLootingMethod;		// ePARTY_ZENNY_LOOTING
};
//------------------------------------------------------------------
struct sUG_PARTY_CHANGE_ITEM_LOOTING_METHOD_REQ {
BYTE				byLootingMethod;		// ePARTY_ITEM_LOOTING
};
//------------------------------------------------------------------
struct sUG_PARTY_INVEST_ZENNY_REQ {
BYTE			byPos;
// 'dwZennyToInvest' doesn't mean relative value to the current zenny but final invested zenny.
// 현재 투자된 포인트와의 상대적인 값이 아니라, 아이템에 최종적으로 투자될 제니이다.
// by YOSHIKI(2006-11-01 {
DWORD			dwZennyToInvest;
};
//------------------------------------------------------------------
struct sUG_PARTY_INVEN_ITEM_RANK_SET_REQ {
BYTE				byItemRank; // eITEM_RANK 
};
//------------------------------------------------------------------
struct sUG_BANK_START_REQ {
HOBJECT				handle;			// NpcHandle
};
//------------------------------------------------------------------
struct sUG_BANK_MOVE_REQ {
HOBJECT				handle;
BYTE				bySrcPlace;
BYTE				bySrcPos;
BYTE				byDestPlace;
BYTE				byDestPos;
};
//------------------------------------------------------------------
struct sUG_BANK_MOVE_STACK_REQ {
HOBJECT				handle;
BYTE				bySrcPlace;
BYTE				bySrcPos;
BYTE				byDestPlace;
BYTE				byDestPos;
BYTE				byStackCount;
};
//------------------------------------------------------------------
struct sUG_BANK_END_REQ {
};
//------------------------------------------------------------------
struct sUG_BANK_ZENNY_REQ {
HOBJECT				handle;			// NpcHandle
DWORD				dwZenny;		// 빼거나 넣을 액수
bool				bIsSave;		// 1 은 넣을 경우 0 은 빼는경우
};
//------------------------------------------------------------------
struct sUG_BANK_BUY_REQ {
HOBJECT				hNpchandle;
BYTE				byMerchantTab;
BYTE				byPos;
};
//------------------------------------------------------------------
struct sUG_BANK_ITEM_DELETE_REQ {
BYTE				byPlace;
BYTE				byPos;
};
//------------------------------------------------------------------
struct sUG_SCOUTER_INDICATOR_REQ {
HOBJECT				hTarget;
};
//------------------------------------------------------------------
struct sUG_SCOUTER_PREDICT_REQ {
BYTE				byPusNum;
};
//------------------------------------------------------------------
struct sUG_SCOUTER_EQUIP_CHECK_REQ {
HOBJECT				hTarget;			// 확인 하고자 하는 상대 타겟 핸들
};
//------------------------------------------------------------------
struct sUG_SCOUTER_CHIP_REMOVE_ALL_REQ {
};
//------------------------------------------------------------------
struct sUG_SOCIAL_ACTION {
TBLIDX				socialActionId;
};
//------------------------------------------------------------------
struct sUG_TS_CONFIRM_STEP_REQ
{
BYTE				byTsType; // 트리거 타입
TS_T_ID				tId;
TS_TC_ID			tcCurId;
TS_TC_ID			tcNextId;
DWORD				dwParam;
BYTE				byEventType;
DWORD				dwEventData;
};
//------------------------------------------------------------------
struct sUG_TS_UPDATE_STATE
{
BYTE				byTsType;	// 트리거 타입
TS_T_ID				tId;
BYTE				byType;
WORD				wTSState;
DWORD				dwParam;
};
//------------------------------------------------------------------
struct sUG_TS_EXCUTE_TRIGGER_OBJECT
{
HOBJECT				hSource;
HOBJECT				hTarget;
BYTE				byEvtGenType;
unsigned int		uiParam;
};
//------------------------------------------------------------------
struct sUG_QUEST_ITEM_MOVE_REQ
{
BYTE				bySrcPos;
BYTE				byDestPos;
};
//------------------------------------------------------------------
struct sUG_QUEST_ITEM_DELETE_REQ
{
BYTE				byDeletePos;
};
//------------------------------------------------------------------
struct sUG_QUEST_GIVEUP_REQ
{
	TS_T_ID			tId;
};
//------------------------------------------------------------------
struct sUG_QUEST_SHARE
{
	TS_T_ID			tId;
};
//------------------------------------------------------------------
struct sUG_QUEST_OBJECT_VISIT_REQ 
{
QUESTID				qId;
WORLDID				worldId;
BYTE				byObjType;			// eOBJTYPE
TBLIDX				objectTblidx;
};
//------------------------------------------------------------------
struct sUG_FREEBATTLE_CHALLENGE_REQ {
HOBJECT				hTarget;	// 대전신청 상대캐릭터의 핸들
};
//------------------------------------------------------------------
struct sUG_FREEBATTLE_ACCEPT_RES
{
	BYTE				byAccept; // 1: 수락 0: 거절 2: 수락할상태가 아님 대전 수락 여부
};
//------------------------------------------------------------------
struct sUG_QUICK_SLOT_UPDATE_REQ {
TBLIDX				tblidx;
BYTE				bySlotID;
BYTE				byType;
BYTE				byPlace;
BYTE				byPos;
};
//------------------------------------------------------------------
struct sUG_QUICK_SLOT_DEL_REQ
{
	BYTE				bySlotID;
};
//------------------------------------------------------------------
struct sUG_PET_DISMISS_PET_REQ {
BYTE				byAvatarType;		// eDBO_AVATAR_TYPE
};
//------------------------------------------------------------------
struct sUG_TRADE_START_REQ {			// 해당 유저와의 교환 요청
HOBJECT				hTarget;			// 타겟 핸들
};
//------------------------------------------------------------------
struct sUG_TRADE_OK_RES {				// 해당 유져의 응답
HOBJECT				handle;				// 요청자의 핸들
BYTE				byOK;				// 승락 유무 1 : 승락 0 : 거부 3: 바쁜상황
};
//------------------------------------------------------------------
struct sUG_TRADE_ADD_REQ {			// 교환창에 아이템 등록
HOBJECT				hTarget;			// 타겟 핸들
HOBJECT				hItem;				// 아이템 핸들
BYTE				byCount;			// 겹쳐있는 아이템중 몇개인가? Default 1개
};
//------------------------------------------------------------------
struct sUG_TRADE_DEL_REQ {			// 교환창에 아이템 삭제
HOBJECT				hTarget;			// 타겟 핸들
HOBJECT				hItem;				// 아이템 핸들
};
//------------------------------------------------------------------
struct sUG_TRADE_MODIFY_REQ {			// 교환창에 아이템 등록
HOBJECT				hTarget;			// 타겟 핸들
HOBJECT				hItem;				// 아이템 핸들
BYTE				byCount;			// 겹쳐있는 아이템중 몇개인가? Default 1개
};
//------------------------------------------------------------------
struct sUG_TRADE_ZENNY_UPDATE_REQ {	// 교환창에 제니 등록 및 변경
HOBJECT				hTarget;			// TargetHandle
DWORD				dwZenny;			// 옮길 만큼의 제니 (자기가 갖고 있는 제니 한도 내 {
};
//------------------------------------------------------------------
struct sUG_TRADE_END_REQ {			// 교환 완료 버튼 클릭
HOBJECT				hTarget;			// 타겟 핸들
DWORD				dwPacketCount;		// 상대방의 변경 카운트 ( 상대방이 물건을 올려놓거나 삭제 혹은 변경 등 패킷받은 개수  {
bool				bIsSet;				// false : 확인풀기 true: 확인잠금
};
//------------------------------------------------------------------
struct sUG_TRADE_CANCEL_REQ {			// 교환 취소 혹은 캐릭종료 거리 이탈시 사용
HOBJECT				hTarget;			// 타겟 핸들
};
//------------------------------------------------------------------
struct sUG_TRADE_DENY_REQ {			// 교환 취소 혹은 캐릭종료 거리 이탈시 사용
bool				bIsDeny;			// TRUE: 거절 하도록 FALSE: 해제 원상태
};
//------------------------------------------------------------------	
struct sUG_GUILD_CREATE_REQ {
HOBJECT				hGuildManagerNpc;
WCHAR				wszGuildName[MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUG_GUILD_INVITE_REQ {
HOBJECT				hTarget;
};
//------------------------------------------------------------------
struct sUG_TUTORIAL_HINT_UPDATE_REQ {
DWORD				dwTutorialHint;
};
//------------------------------------------------------------------
struct sUG_TUTORIAL_WAIT_CANCEL_REQ {

};
//------------------------------------------------------------------
struct sUG_TUTORIAL_PLAY_QUIT_REQ {

};
//------------------------------------------------------------------
struct sUG_TIMEQUEST_ROOM_LIST_REQ {
HOBJECT				hTimeQuestNpc;		// 해당 타임머신퀘스트 NPC의 핸들 
};
//------------------------------------------------------------------
struct sUG_TIMEQUEST_ROOM_INFO_REQ {
};
//------------------------------------------------------------------
struct sUG_TIMEQUEST_ROOM_JOIN_REQ {
HOBJECT				hTimeQuestNpc;		// 해당 타임머신퀘스트 NPC의 핸들
BYTE				byTimeQuestMode;	// 개인 or Party ( eTIMEQUEST_MODE  {
bool				bIsRetry;			// 재신청인지 아닌지를 나타냄
};
//------------------------------------------------------------------
struct sUG_TIMEQUEST_ROOM_LEAVE_REQ {
};
//------------------------------------------------------------------
struct sUG_TIMEQUEST_ROOM_TELEPORT_REQ {
};
//------------------------------------------------------------------
struct sUG_RANKBATTLE_INFO_REQ {
BYTE					byBattleMode;		// eRANKBATTLE_MODE
};
//------------------------------------------------------------------
struct sUG_RANKBATTLE_JOIN_REQ {
HOBJECT					hBoardObject;
TBLIDX					rankBattleTblidx;
};
//------------------------------------------------------------------
struct sUG_RANKBATTLE_LEAVE_REQ {
TBLIDX					rankBattleTblidx;
};
//------------------------------------------------------------------
struct sUG_RANKBATTLE_ROOM_LIST_REQ {
HOBJECT				hRankBattleObject;	// 게시판 Object의 핸들
WORD				wPage;				// 게시판의 출력 Page
};
//------------------------------------------------------------------
struct sUG_RANKBATTLE_ROOM_INFO_REQ {
HOBJECT				hRankBattleObject;	// 게시판 Object의 핸들
ROOMID				roomId;
};
//------------------------------------------------------------------
struct sUG_RANKBATTLE_ROOM_CREATE_REQ {
HOBJECT				hRankBattleObject;	// 게시판 Object의 핸들
};
//------------------------------------------------------------------
struct sUG_RANKBATTLE_ROOM_LEAVE_REQ {
};
//------------------------------------------------------------------
struct sUG_RANKBATTLE_ROOM_CHALLENGE_REQ {
HOBJECT				hRankBattleObject;	// 게시판 Object의 핸들
ROOMID				roomId;				// 방 번호
};
//------------------------------------------------------------------
struct sUG_RANKBATTLE_ROOM_MATCH_CANCEL_REQ {
};
//------------------------------------------------------------------
struct sUG_DRAGONBALL_CHECK_REQ {
HOBJECT				hObject;						  // TS Object 제단	 
sITEM_POSITION_DATA sData[ITEM_MAX_DRAGONBALL];   // 인벤상의 드래곤볼아이템
};
//------------------------------------------------------------------
struct sUG_DRAGONBALL_REWARD_REQ {
HOBJECT				hObject;						  // TS Object 제단	
TBLIDX				rewardTblidx;					  // 선택 보상 테이블 인덱스
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_CREATE_REQ {
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_EXIT_REQ {
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_OPEN_REQ {
WCHAR					wcPrivateShopName[MAX_PRIVATESHOP_NAME_IN_UNICODE + 1];
bool					bIsOwnerEmpty; //true이면 주인이 자리를 비운것
BYTE					byNoticeSize;
WCHAR					wcNotice[MAX_PRIVATESHOP_NOTICE_IN_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_CLOSE_REQ {
};
//------------------------------------------------------------------
//아직 미정 (사용하지 마세요 - 삭제 가능성 있음 {
struct sUG_PRIVATESHOP_ITEM_GET_REQ {
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_ITEM_INSERT_REQ {
BYTE							byPrivateShopInventorySlotPos;
BYTE							byInventoryPlace;
BYTE							byInventoryPos;
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_ITEM_UPDATE_REQ {
BYTE							byPrivateShopInventorySlotPos;
DWORD							dwZenny;
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_ITEM_DELETE_REQ {
BYTE							byPrivateShopInventorySlotPos;
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_ITEM_BUYING_REQ {
HOBJECT						hOwner;
BYTE						byPrivateShopInventorySlotPos[MAX_BUY_SHOPPING_CART];
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_ENTER_REQ {
HOBJECT						hOwner;
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_LEAVE_REQ {
HOBJECT						hOwner;
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_ITEM_SELECT_REQ {
HOBJECT						hOwner;
BYTE						byPrivateShopInventorySlotPos;
BYTE						byItemState;//eITEMSTATE 값을 갖는다
};
//------------------------------------------------------------------
struct sUG_MAIL_START_REQ {
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT  {
};
//------------------------------------------------------------------
struct sUG_MAIL_SEND_REQ {
HOBJECT		hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT  {
BYTE		byMailType;	// eMAIL_TYPE	
sITEM_POSITION_DATA sItemData;	// 아이템포지션
DWORD		dwZenny;		// Req or Give Zenny
BYTE		byDay;		// 유효만료날짜 최대 10일
WCHAR		wszTargetName[MAX_SIZE_CHAR_NAME_UNICODE + 1];	// 받을 캐릭 이름
BYTE		byTextSize;	// 가변길이 패킷용 텍스트 사이즈
WCHAR		wszText[MAX_LENGTH_OF_MAIL_MESSAGE + 1];	// 메일내용
};
//------------------------------------------------------------------
struct sUG_MAIL_READ_REQ {
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT  {
MAILID	mailID;	// 메일 아이디
};
//------------------------------------------------------------------
struct sUG_MAIL_DEL_REQ {
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT  {
MAILID	mailID;	// 메일 아이디
};
//------------------------------------------------------------------
struct sUG_MAIL_RETURN_REQ {
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT  {
MAILID	mailID;	// 메일 아이디	
};
//------------------------------------------------------------------
struct sUG_MAIL_RELOAD_REQ {
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT  {
};
//------------------------------------------------------------------
struct sUG_MAIL_LOAD_REQ {
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT  {
BYTE	byCount;
//MAILID	aMailID[MAX_MAIL_SLOT_COUNT];	// 메일 아이디 // TODO
};
//------------------------------------------------------------------
struct sUG_MAIL_ITEM_RECEIVE_REQ {
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT  {
MAILID	mailID;	// 메일 아이디
};
//------------------------------------------------------------------
struct sUG_MAIL_LOCK_REQ {
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT  {
MAILID	mailID;	// 메일 아이디
bool	bIsLock;		// Lock 1: Unlock: 0
};
//------------------------------------------------------------------
struct sUG_MAIL_MULTI_DEL_REQ {
HOBJECT	hObject;								// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT  {
BYTE	byCount;
MAILID	aMailID[MAX_COUNT_OF_MULTI_DEL];		// 메일 아이디
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_BUSINESS_REQUEST_REQ {
HOBJECT						hOwner;
BYTE						byPrivateShopInventorySlotPos;
TBLIDX						itemNo;//클라이언트와 서버에 아이템이 동일한지 검사하기 위함
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_BUSINESS_CONSENT_RES {
bool						bResult;
TBLIDX						itemNo;//클라이언트와 서버에 아이템이 동일한지 검사하기 위함
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_BUSINESS_WAITTIMEOUT_NFY {
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_REQ {
DWORD						dwPriceFluctuationsZenny;
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_REQ {
HOBJECT						hOwner;
unsigned __int16			nPriceFluctuationsCounter;
};
//------------------------------------------------------------------
struct sUG_PRIVATESHOP_BUSINESS_CANCEL_REQ {
HOBJECT						hOwner;
};
//------------------------------------------------------------------
struct sUG_PORTAL_START_REQ {
HOBJECT				handle;			// 해당 NPC 검사후 포탈 정보 로딩
};
//------------------------------------------------------------------
struct sUG_PORTAL_ADD_REQ {
HOBJECT				handle;
};
//------------------------------------------------------------------
struct sUG_PORTAL_REQ {
HOBJECT				handle;
BYTE				byPoint;		// 0~7까지 선택된 인덱스
};
//------------------------------------------------------------------
struct sUG_PING {
};
//------------------------------------------------------------------
struct sUG_WAR_FOG_UPDATE_REQ {
HOBJECT				hObject;			// Object Handle		
};
//------------------------------------------------------------------
struct sUG_GUILD_FUNCTION_ADD_REQ {
HOBJECT				hGuildManagerNpc;
BYTE				byFunction;			// 추가할 기능 번호 eDBO_GUILD_FUNCTION
};
//------------------------------------------------------------------
struct sUG_GUILD_GIVE_ZENNY {
HOBJECT				hGuildManagerNpc;
DWORD				dwZenny;
};
//------------------------------------------------------------------
struct sUG_GUILD_BANK_START_REQ {
HOBJECT				handle;			// 창고 NpcHandle
};
//------------------------------------------------------------------
struct sUG_GUILD_BANK_MOVE_REQ {
HOBJECT				handle;			// 창고 NpcHandle	
BYTE				bySrcPlace;
BYTE				bySrcPos;
BYTE				byDestPlace;
BYTE				byDestPos;
};
//------------------------------------------------------------------
struct sUG_GUILD_BANK_MOVE_STACK_REQ {
HOBJECT				handle;			// 창고 NpcHandle
BYTE				bySrcPlace;
BYTE				bySrcPos;
BYTE				byDestPlace;
BYTE				byDestPos;
BYTE				byStackCount;
};
//------------------------------------------------------------------
struct sUG_GUILD_BANK_END_REQ {
};
//------------------------------------------------------------------
struct sUG_GUILD_BANK_ZENNY_REQ {
HOBJECT				handle;			// NpcHandle
DWORD				dwZenny;		// 빼거나 넣을 액수
bool				bIsSave;		// 1 은 넣을 경우 0 은 빼는경우
};
//------------------------------------------------------------------
struct sUG_CROSSFIRE_REQ {
HOBJECT				hAnotherUser;		//유져가 선택한 User 핸들
};
//------------------------------------------------------------------
struct sUG_GUILD_CREATE_MARK_REQ {
sDBO_GUILD_MARK		sMark;
};
//------------------------------------------------------------------
struct sUG_GUILD_CHANGE_MARK_REQ {
sDBO_GUILD_MARK		sMark;
};
//------------------------------------------------------------------
struct sUG_BANK_LOAD_REQ {
HOBJECT				handle;			// NpcHandle
};
//------------------------------------------------------------------
struct sUG_GUILD_CHANGE_NAME_REQ {
HOBJECT				hGuildManagerNpc;
WCHAR				wszGuildName[MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUG_PARTY_SHARETARGET_REQ {
BYTE				bySlot;
HOBJECT				hTarget;
};
//------------------------------------------------------------------
struct sUG_RIDE_ON_BUS_REQ {
HOBJECT				hTarget;			// NpcHandle
};
//------------------------------------------------------------------
struct sUG_RIDE_OFF_BUS_REQ {
};
//------------------------------------------------------------------
struct sUG_TRANSFORM_CANCEL_REQ {
};
//------------------------------------------------------------------
struct sUG_SHOP_ITEM_IDENTIFY_REQ {
HOBJECT				hNpchandle;		// NpcHandle
BYTE				byPlace;
BYTE				byPos;
};
//------------------------------------------------------------------
struct sUG_DICE_ROLL_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_JOIN_INDIVIDUAL_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_LEAVE_INDIVIDUAL_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_JOIN_TEAM_INFO_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_JOIN_TEAM_REQ {
WCHAR				wszTeamName[MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1];
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_LEAVE_TEAM_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_LEAVE_TEAM_MEMBER_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_JOIN_INFO_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_JOIN_STATE_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_MUDOSA_INFO_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_MUDOSA_TELEPORT_REQ {
BYTE			byMudosaIndex;				// 무도사 인덱스
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_PARTY_MAKER_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_SOCIAL_ACTION {
ANIMATIONID			socialAction;
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_PRIZEWINNER_NAME_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_PRIZEWINNER_TEAM_NAME_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_GM_BUDOKAI_SERVER_ENTER_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_GM_BUDOKAI_SERVER_LEAVE_REQ {
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_GM_MATCH_PROGRESS_INFO_REQ {
BYTE				byMatchType;	// eBUDOKAI_MATCH_TYPE
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_GM_MATCH_ARENA_ENTER_REQ {
BYTE				byMatchType;		// eBUDOKAI_MATCH_TYPE
BYTE				byMatchWorldType;	// eMATCHWORLD_TYPE
BYTE				byMatchDepth;		// eBUDOKAI_MATCH_DEPTH
BYTE				byMatchIndex;
};
//------------------------------------------------------------------
struct sUG_BUDOKAI_GM_MATCH_ARENA_LEAVE_REQ {
};
//------------------------------------------------------------------
struct sUG_SCOUTER_TURN_ON {
};
//------------------------------------------------------------------
struct sUG_SCOUTER_TURN_OFF {
};
//------------------------------------------------------------------
struct sUG_SCOUTER_ITEM_SELL_REQ {
BYTE			byPlace;
BYTE			byPos;
};
//------------------------------------------------------------------
struct sUG_SHOP_EVENTITEM_START_REQ {
HOBJECT				handle;
};
//------------------------------------------------------------------
struct sUG_SHOP_EVENTITEM_BUY_REQ {
HOBJECT				handle;
BYTE				byBuyCount;
sSHOP_BUY_CART		sBuyData[MAX_BUY_SHOPPING_CART];
};
//------------------------------------------------------------------
struct sUG_SHOP_EVENTITEM_END_REQ {
};
//------------------------------------------------------------------
struct sUG_SHOP_GAMBLE_BUY_REQ {
HOBJECT				handle;
};
//------------------------------------------------------------------
struct sUG_PARTY_DIFF_CHANGE_REQ {
ePARTY_DUNGEON_STATE eDiff;
};
//------------------------------------------------------------------
struct sUG_PARTY_DUNGEON_INIT_REQ {
};
//------------------------------------------------------------------
struct sUG_SKILL_INIT_REQ {
HOBJECT				handle;
};
//------------------------------------------------------------------
struct sUG_PARTY_CHARM_DICE_ROLL_REQ {
};
//------------------------------------------------------------------
struct sUG_PARTY_INVEN_LOCK_REQ {
bool				bIsOpen;	// 1: Open 0:Close
};
//------------------------------------------------------------------
struct sUG_PARTY_INVEN_RESET_REQ {
};
//------------------------------------------------------------------
struct sUG_PARTY_INVEN_ACCEPTED_REQ {
BYTE				byItemSlot;	// 파티인벤 해당 슬롯 아이템 낙찰
};
//------------------------------------------------------------------
struct sUG_PARTY_INVEN_GIVE_REQ {
BYTE				byItemSlot;		// 파티인벤 해당 슬롯 아이템 
HOBJECT				hTarget;
};
//------------------------------------------------------------------
struct sUG_PARTY_INVEN_DICE_START_REQ {
BYTE				byItemSlot;		// 파티인벤 해당 슬롯 아이템	
};
//------------------------------------------------------------------
struct sUG_PARTY_INVEN_DICE_ROLL_REQ {
};
//------------------------------------------------------------------
struct sUG_TELEPORT_CONFIRM_REQ {
bool				bTeleport;		// true : 확인, false : 취소
BYTE				byTeleportIndex;
};
//------------------------------------------------------------------
struct sUG_HOIPOIMIX_ITEM_CHECK_REQ {			// 만들아이템 선택 (필요한 아이템 수량 체크 {
HOBJECT				objHandle;
TBLIDX				recipeTblidx;
};
//------------------------------------------------------------------
struct sUG_HOIPOIMIX_ITEM_MAKE_REQ {			// 아이템 만들기
HOBJECT				objHandle;
TBLIDX				recipeTblidx;
bool				bIsEPUseSuccess;			// EP 사용유무
};
//------------------------------------------------------------------			
struct sUG_HOIPOIMIX_ITEM_MAKE_EP_REQ {		// 아이템 만들기 중 EP 넣기
TBLIDX				recipeTblidx;
};
//------------------------------------------------------------------	
struct sUG_HOIPOIMIX_ITEM_MACHINE_DEL_REQ {			// 머신 삭제
HOBJECT				objHandle;
};
//------------------------------------------------------------------
struct sUG_HOIPOIMIX_JOB_SET_REQ {			// 잡 세팅
HOBJECT				hNpchandle;
BYTE				byRecipeType;
};
//------------------------------------------------------------------
struct sUG_HOIPOIMIX_JOB_RESET_REQ {			// 잡 리셋
HOBJECT				hNpchandle;
BYTE				byRecipeType;
};
//------------------------------------------------------------------
struct sUG_VEHICLE_DIRECT_PLAY_CANCEL_NFY {
};
//------------------------------------------------------------------
struct sUG_VEHICLE_ENGINE_START_REQ {
TBLIDX				idFuelItemTblidx;
};
//------------------------------------------------------------------
struct sUG_VEHICLE_ENGINE_STOP_REQ {
};
//------------------------------------------------------------------
struct sUG_VEHICLE_END_REQ {
};
//------------------------------------------------------------------
struct sUG_VEHICLE_STUNT_NFY {
};
//------------------------------------------------------------------
struct sUG_VEHICLE_FUEL_REMOVE_NFY {
TBLIDX				idFuelItemTblidx;
};
//------------------------------------------------------------------
struct sUG_DOJO_CREATE_REQ {
HOBJECT				hObject;
};
//------------------------------------------------------------------
struct sUG_DOJO_DELETE_REQ {
HOBJECT				hObject;
TBLIDX				dojoTblidx;
};
//------------------------------------------------------------------
struct sUG_DOJO_FUNCTION_ADD_REQ {
HOBJECT				hGuildManagerNpc;
BYTE				byFunction;			// 추가할 기능 번호 eDBO_GUILD_FUNCTION
BYTE				byPlace;			// 호이포이락이 필요시 인벤위치 불필요시 INVALID_BYTE
BYTE				byPos;				// 호이포이락이 필요시 인벤위치 불필요시 INVALID_BYTE
};
//------------------------------------------------------------------
struct sUG_DOJO_BANK_HISTORY_REQ {
HOBJECT				hObject;
};
//------------------------------------------------------------------
struct sUG_DOGI_CREATE_REQ {
	HOBJECT				hObject;
	sDBO_DOGI_DATA		sData;
};
//------------------------------------------------------------------
struct sUG_DOGI_CHANGE_REQ {
	HOBJECT				hObject;
	sDBO_DOGI_DATA		sData;
};
//------------------------------------------------------------------
struct sUG_GUILD_DOGI_CREATE_REQ {
	HOBJECT				hObject;
	sDBO_DOGI_DATA		sData;
};
//------------------------------------------------------------------
struct sUG_GUILD_DOGI_CHANGE_REQ {
	HOBJECT				hObject;
	sDBO_DOGI_DATA		sData;
};
//------------------------------------------------------------------
struct sUG_DOJO_SCRAMBLE_REQ {			// 도장쟁탈전 신청 (도전자 {
	HOBJECT				hNpcHandle;				// 도장관리인
};
//------------------------------------------------------------------
struct sUG_DOJO_SCRAMBLE_RESPONSE_REQ {		// 도장쟁탈전 신청에 대한 응답 (도장주인 {
bool				bIsAccept;				// 신청에 대한 응답 1:받기 0:거절
};
//------------------------------------------------------------------						
struct sUG_SHOP_NETPYITEM_START_REQ {
};
//------------------------------------------------------------------
struct sUG_SHOP_NETPYITEM_BUY_REQ {
	BYTE				byBuyCount;
	sSHOP_BUY_CART		sBuyData[MAX_BUY_SHOPPING_CART];
	DWORD				totalCost; 
};
//------------------------------------------------------------------
struct sUG_SHOP_NETPYITEM_END_REQ {
};
//------------------------------------------------------------------
struct sUG_WORLD_MAP_STATUS {
bool				bIsWorldMapOpen;
};
//------------------------------------------------------------------
struct sUG_DOJO_NPC_INFO_REQ {
	HOBJECT				hNpcHandle;
};
//------------------------------------------------------------------
struct sUG_GAMEGUARD_AUTH_ANSWER_RES {
	BYTE				byDataSize;
	BYTE				abyData[UCHAR_MAX];
};
//------------------------------------------------------------------
struct sUG_GAMEGUARD_HACK_INFO_NFY {
	WORD				wDataSize;
	BYTE				abyData[USHRT_MAX];
};
//------------------------------------------------------------------
struct sUG_SKILL_CASTING_CANCELED_NFY {
	WORD				wResultCode;
};
//------------------------------------------------------------------
struct sUG_PET_ATTACK_TARGET_NFY {
	BYTE				byAvatarType;
};
//------------------------------------------------------------------
struct sUG_DURATION_ITEM_BUY_REQ {
	TBLIDX				merchantTblidx;
	BYTE				byPos;
};
//------------------------------------------------------------------
struct sUG_DURATION_RENEW_REQ {
	HOBJECT				hItemHandle;
};
//------------------------------------------------------------------
struct sUG_CASHITEM_START_REQ {
};
//------------------------------------------------------------------
struct sUG_CASHITEM_END_REQ {
};
//------------------------------------------------------------------
struct sUG_CASHITEM_MOVE_REQ {
	DWORD				dwProductId;
};
//------------------------------------------------------------------
struct sUG_CASHITEM_USE_REQ {
	DWORD				dwProductId;
};
//------------------------------------------------------------------
struct sUG_CASHITEM_HLSHOP_START_REQ {
};
//------------------------------------------------------------------
struct sUG_CASHITEM_HLSHOP_END_REQ {
};
//------------------------------------------------------------------
struct sUG_CASHITEM_BUY_REQ {
	BYTE				byBuyCount;
	DWORD				adwIdxHlsTable[MAX_BUY_HLSSHOP_CART];
};
//------------------------------------------------------------------
struct sUG_GMT_UPDATE_REQ {
	//sGAME_MANIA_TIME	sNext; // TODO
};
//------------------------------------------------------------------
struct sUG_CHAR_LOC_AFTER_KNOCKDOWN_NFY {
	Vector3			vCurLoc;
	Vector2			vCurDir;
};
//------------------------------------------------------------------
struct sUG_CHAR_LOC_AFTER_SLIDING_NFY {
	Vector3			vCurLoc;
	Vector2			vCurDir;
};
//------------------------------------------------------------------
struct sUG_CHAR_LOC_AFTER_PUSH_NFY {
	Vector3			vCurLoc;
	Vector2			vCurDir;
};
//------------------------------------------------------------------
#pragma pack()
const char * GetPacketName_UG(WORD wOpCode);
#endif //_GAMEUG_H_