#ifndef _GAMEGU_H
#define _GAMEGU_H

#pragma once

#include "../Auth/Auth.h"

#include <Tables\TableContainer.h>

#include <Network\Packet\Packet.h>

#include <Game\Entity\Character\Character.h>
#include <Game\Entity\Skill\Skill.h>
#include <Game\Guilde\Dojo\Dojo.h>
#include <Game\Entity\Object.h>
#include <Game\Mail\Mail.h>

struct DELAYED_SKILL
{
public:
	DELAYED_SKILL()
		: skillId{ INVALID_TBLIDX }
		, byTargetHandle{ INVALID_TBLIDX }
		, fCastingTimeRemaining{ 0}
		, fCastingTimeInMilliSecs{ 0 }
	{

	}
	DELAYED_SKILL(TBLIDX id, HOBJECT target, float castingTimeRemaining, float castingTime)
		: skillId{ id }
		, byTargetHandle{ target }
		, fCastingTimeRemaining{ castingTimeRemaining }
		, fCastingTimeInMilliSecs{ castingTime }
	{
	}
	TBLIDX		skillId;
	HOBJECT		byTargetHandle;
	float		fCastingTimeRemaining;
	float		fCastingTimeInMilliSecs;
};

#pragma pack(push, 1)
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PONG)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SESSION_STATE_WRONG)
WORD			wPrevOPCode;	// 이전에 보냈던 코드번호
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_STATE_WRONG)
WORD			wPrevOPCode; // 이전에 보냈던 코드번호
HOBJECT			handle; // 캐릭터 핸들
BYTE			byStateID; // 현재 캐릭터 상태
						   //sCHARSTATE		sCharState; // 현재 캐릭터 상태
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAME_ENTER_RES)
WORD			wResultCode;
char			achCommunityServerIP[MAX_LENGTH_OF_IP + 1];
WORD			wCommunityServerPort;
DBOTIME			timeDBOEnter;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAME_LEAVE_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ENTER_WORLD_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ENTER_WORLD_COMPLETE)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AUTH_KEY_FOR_COMMUNITY_SERVER_RES)
WORD			wResultCode;
BYTE			abyAuthKey[MAX_SIZE_AUTH_KEY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_CHAR_INFO)
HOBJECT			handle;
sPC_PROFILE		sPcProfile;
WORD			wCharStateSize; //-[9/7/2006 zeroera] : 설명 : 클라이언트를 위한 캐릭터상태 사이즈 정보 
sCHARSTATE		sCharState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_ITEM_INFO)
BYTE			byBeginCount;
BYTE			byItemCount;
sITEM_PROFILE	aItemProfile[MAX_COUNT_USER_HAVE_INVEN_ITEM];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_SKILL_INFO)
BYTE			bySkillCount;
sSKILL_INFO		aSkillInfo[MAX_PC_HAVE_SKILL];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_HTB_INFO)
BYTE			byHTBSkillCount; // HTB 스킬 개수
sHTB_SKILL_INFO	aHTBSkillnfo[HTB_MAX_PC_HAVE_HTB_SKILL]; // HTB 스킬 정보
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_BUFF_INFO)
BYTE			byBuffCount;
sBUFF_INFO		aBuffInfo[MAX_BLESS_BUFF_CHARACTER_HAS + MAX_CURSE_BUFF_CHARACTER_HAS];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_WORLD_INFO)
Vector3			vCurLoc;
Vector3			vCurDir;
sWORLD_INFO		worldInfo;
BYTE			byDojoCount;
sDBO_DOJO_BRIEF sDojoData[DBO_MAX_COUNT_DOJO_IN_WORLD];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_ZONE_INFO)
sWORLD_ZONE_INFO		zoneInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_QUEST_COMPLETE_INFO)
sQUEST_COMPLETE_INFO	completeInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_QUEST_PROGRESS_INFO)
BYTE					byProgressCount; // 현재 진행하고 있는 퀘스트 개수
sQUEST_PROGRESS_INFO	progressInfo[20]; // 진행 퀘스트 데이타
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_QUEST_INVENTORY_INFO)
BYTE					byItemCount;
//sQUEST_INVENTORY_INFO	aInventoryInfo[1]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_INFO_END)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_ATTRIBUTE_UPDATE)
HOBJECT			hHandle;
BYTE			byAttributeTotalCount;
BYTE			abyFlexibleField[((UCHAR_MAX - 1) / 8 + 1) + sizeof(sAVATAR_ATTRIBUTE)];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_OBJECT_CREATE)
HOBJECT			handle;
sOBJECT_INFO	sObjectInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DESTROY_ALL_OBJECTS_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_OBJECT_DESTROY)
HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_MOVE)
HOBJECT			handle;
//- yoshiki : Do we use dwTimeStamp or not?
DWORD			dwTimeStamp;
Vector3			vCurLoc;
Vector3			vCurDir;
BYTE			byMoveDirection;
BYTE			byMoveFlag;		// 뛰기 혹은 걷기(ENtlMovementFlag 참조)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_DEST_MOVE)
HOBJECT			handle;
//- yoshiki : Do we use dwTimeStamp or not?
DWORD			dwTimeStamp;
Vector3			vCurLoc;
BYTE			byMoveFlag;		// 뛰기 혹은 걷기(ENtlMovementFlag 참조)
bool			bHaveSecondDestLoc;
Vector3			vSecondDestLoc;
BYTE			byDestLocCount;
Vector3			avDestLoc[DBO_MAX_NEXT_DEST_LOC_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CHANGE_HEADING)
HOBJECT			handle;
//- yoshiki : Do we use dwTimeStamp or not?
DWORD			dwTimeStamp;
Vector3		vNewHeading;
Vector3		vNewLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_MOVE_SYNC)
HOBJECT			handle;
DWORD			dwTimeStamp;
Vector3		vCurLoc;
Vector3		vCurDir;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CHANGE_JUMP_DIRECTION)
HOBJECT			handle;
//- yoshiki : Do we use dwTimeStamp or not?
DWORD			dwTimeStamp;
Vector3		vJumpDir;
//	BYTE			byMoveFlag;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CHANGE_DIRECTION_ON_FLOATING)
HOBJECT				hSubject;
//- yoshiki : Do we use dwTimeStamp or not?
DWORD				dwTimeStamp;
Vector3			vCurDir;
BYTE				byMoveDirection;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_FOLLOW_MOVE)
HOBJECT			handle;
//- yoshiki : Do we use dwTimeStamp or not?
DWORD			dwTimeStamp;
HOBJECT			hTarget;
float			fDistance;
BYTE			byMovementReason;
BYTE			byMoveFlag;		// 뛰기 혹은 걷기(ENtlMovementFlag 참조)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_JUMP)
HOBJECT			handle;
Vector3		vCurrentHeading;
Vector3		vJumpDir;
BYTE			byMoveDirection;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_JUMP_END)
HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_PUSHED_NFY)
HOBJECT			hSubject;
BYTE			byAttackResult;		// eBATTLE_ATTACK_RESULT
WORD			wAttackResultValue;
Vector3		vDestLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_SITDOWN)
HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_STANDUP)
HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_FIGHTMODE)
HOBJECT			handle;
bool			bFightMode; // 전투 자세 On/Off
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_GUARD_MODE_COOL_TIME_NFY)
DWORD			dwCoolTimeRemaining;		// in Millisecs.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_FAINT)
HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_KNOCKDOWN)
HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_SLIDING)
HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CAMPING)
HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CONVERT_CLASS)
HOBJECT			hTarget;
BYTE			byClass;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_DIALOG)
HOBJECT				hSubject;				// 대화 하는 캐릭터 핸들
BYTE				byDialogType;			// 대화 종류 ( eCHAR_DIALOG_TYPE )
TBLIDX				textTblidx;				// 대화 내용 테이블 번호 ( INVALID 가 아니면 해당 텍스트를 찾아 출력하고, INVALID면 아래의 텍스트를 출력해 줄 것)
bool				bIsRefSpeechTable;		// speech table( NPCSpeechTable 을 참조하는가? )
WORD				wTextLen;				// 대화내용의 길이
WCHAR				awchText[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1]; // 대화내용
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_DIRECT_PLAY)
HOBJECT				hSubject;				// 연출 캐릭터 핸들
BYTE				byPlayMode;				// 연출 모드
TBLIDX				directTblidx;			// 연출 번호
bool				bSynchronize;			// 서버 클라이언트 동기화
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_DIRECT_PLAY_END)

END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_AWAY_RES)
bool	bIsAway;		// AwayOn 1: Awayoff: 0
WORD 	wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_MAIL_INFO)
BYTE	byMailCount;		// 현재 전체메일 카운트 
BYTE	byManagerCount;		// 읽지 않은 매니져 메일 카운트
BYTE	byNormalCount;		// 읽지 않은 노멀 메일 카운트
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_KEY_INFO)
BYTE			byCount;
sSHORTCUT_DATA  asData[SHORTCUT_MAX_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_RANKBATTLE_SCORE)
//sRANKBATTLE_SCORE_INFO	sScoreInfo; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_KEY_UPDATE_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_ACTION_ATTACK)
HOBJECT			hSubject; // 액션 주체 캐릭터 핸들
HOBJECT			hTarget; // 액션 타겟 캐릭터 핸들
DWORD			dwLpEpEventId;
BYTE			bChainAttack : 1; // 체인어택여부
BYTE			byAttackResult : 7; // 액션 결과 ( eBATTLE_ATTACK_RESULT )
WORD			wAttackResultValue; // 액션의 결과 값 ( 데미지 )
BYTE			byAttackSequence; // 어택 시퀀스 번호 (체인어택)
float			fReflectedDamage; // 타겟으로부터 반사되어 입은 피해
BYTE			byBlockedAction;		// eDBO_GUARD_TYPE
Vector3			vShift; // 어택으로 인한 이동 벡터
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_ACTION_SKILL)
HOBJECT				handle;
WORD				wResultCode;
DWORD				dwLpEpEventId;
TBLIDX				skillId;
BYTE				byRpBonusType;		// eDBO_RP_BONUS_TYPE
HOBJECT				hAppointedTarget;
bool				bIsSkillHarmful;
BYTE				bySkillResultCount;
sSKILL_RESULT		aSkillResult[MAX_NUMBER_OF_SKILL_TARGET];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_ACTION_ITEM)
HOBJECT				handle;
WORD				wResultCode;
DWORD				dwLpEpEventId;
TBLIDX				itemTblidx;
BYTE				bySkillResultCount;
sSKILL_RESULT		aSkillResult[MAX_NUMBER_OF_SKILL_TARGET];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_REVIVAL_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_TELEPORT_RES)
WORD			wResultCode;
Vector3			vNewLoc;
Vector3			vNewDir;
bool			bIsToMoveAnotherServer;
// Data in 'sWorldInfo' will not be sent if the character moves within the current world.
// 현재 월드 안에서의 이동일 경우에는 sWorldInfo 데이타를 보내지 않는다.
// by YOSHIKI(2007-10-25)
sWORLD_INFO				sWorldInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_BIND_RES)
WORD			wResultCode;
BYTE			byBindType;		// eDBO_BIND_TYPE
WORLDID			bindWorldId;
TBLIDX			bindObjectTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_SERVER_CHANGE_RES)
WORD					wResultCode;
char					achAuthKey[MAX_SIZE_AUTH_KEY];
sSERVER_INFO			serverInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CHANNEL_CHANGE_RES)
WORD					wResultCode;
char					achAuthKey[MAX_SIZE_AUTH_KEY];
sSERVER_INFO			serverInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_EXIT_RES)
WORD					wResultCode;
char					achAuthKey[MAX_SIZE_AUTH_KEY];
BYTE					byServerInfoCount;
sSERVER_INFO			aServerInfo[DBO_MAX_CHARACTER_SERVER_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_SKILL_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAME_EXIT_RES)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAME_KICK_NFY)
WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_EFFECT_AFFECTED)
HOBJECT			handle;
HOBJECT			hCaster;
TBLIDX			effectTblidx;
WORD			wResultCode;
float			fActualArgument1;
float			fActualArgument2;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_CASTING_CANCELED_NFY)
HOBJECT			handle;
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_CASTING_DELAYED_NFY)
HOBJECT			handle;
WORD			wResultCode;
DWORD			dwCastingTime;
DWORD			dwCastingTimeRemaining;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_AFFECTING_CANCELED_NFY)
HOBJECT			hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_TARGET_LIST_REQ)
BYTE			byAvatarType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_LEARN_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_LEARNED_NFY)
TBLIDX			skillId;
BYTE			bySlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_UPGRADE_RES)
WORD			wResultCode;
TBLIDX			skillId;
BYTE			bySlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_RP_BONUS_SETTING_RES)
WORD			wResultCode;
TBLIDX			skillId;
BYTE			bySlotIndex;
BYTE			byRpBonusType;		// eDBO_RP_BONUS_TYPE
bool			bIsRpBonusAuto;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_NOTIFY_EXP)
BYTE			bySlotIndex;
WORD			wSkillExp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_AFTEREFFECT_REMAINING_TIME_NFY)
DWORD			dwTimeRemaining;		// in Millisecs.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_COOL_TIME_STARTED_NFY)
HOBJECT			hSubject;
TBLIDX			skillTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUFF_REGISTERED)
HOBJECT			hHandle;
BYTE			bySourceType;		// eDBO_OBJECT_SOURCE
TBLIDX			tblidx;
float			afEffectValue[MAX_EFFECT_IN_SKILL];
DWORD			dwDurationTime;		// In Millisecs.
DWORD			dwTimeRemaining;		// in millisecs.
bool			bNeedToDisplayMessage;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUFF_DROPPED)
HOBJECT			hHandle;
BYTE			bySourceType;		// eDBO_OBJECT_SOURCE
TBLIDX			tblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUFF_REFRESH_ALL)
HOBJECT			hHandle;
BYTE			byCount;
sBUFF_INFO		aBuffInfo[DBO_MAX_BUFF_CHARACTER_HAS];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUFF_DROP_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_START_RES)
WORD			wResultCode;
BYTE			bySkillSlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_LEARN_RES)
WORD			wResultCode;
TBLIDX			skillId;
BYTE			bySkillSlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_FORWARD_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_RP_BALL_USE_RES)
WORD			wResultCode;
BYTE			byRpBallCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_RP_BALL_USED_NFY)
HOBJECT			hSubject;
BYTE			byRpBallCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_RP_BALL_RESULT_DECIDED_NFY)
HOBJECT			hAttacker;
HOBJECT			hWinner;
bool			bHasSubjectRpBallUsed;
bool			bHasTargetRpBallUsed;
BYTE			bySubjectRpBallUsed;
BYTE			byTargetRpBallUsed;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_CREATE)
HOBJECT			handle;
sITEM_DATA      sItemData;
bool			bIsNew;		// Effect 추가 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_UPDATE)
HOBJECT			handle;
sITEM_DATA      sItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_MOVE_RES)
WORD			wResultCode;
HOBJECT			hSrcItem;
HOBJECT			hDestItem;
BYTE			bySrcPlace;
BYTE			bySrcPos;
BYTE			byDestPlace;
BYTE			byDestPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_MOVE_STACK_RES)
WORD			wResultCode;
HOBJECT			hSrcItem;
HOBJECT			hDestItem;
BYTE			bySrcPlace;
BYTE			bySrcPos;
BYTE			byDestPlace;
BYTE			byDestPos;
BYTE			byStackCount1;//결과적으로 놓여질값 SOURCE
BYTE			byStackCount2;//결과적으로 놓여질값 DESTINATION
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_DELETE)
HOBJECT			hSrcItem;
BYTE			bySrcPlace;
BYTE			bySrcPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_DELETE_RES)
WORD			wResultCode;
BYTE			byPlace;
BYTE			byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_EQUIP_REPAIR_RES)
HOBJECT			handle;			// hNpchandle
WORD			wResultCode;
DWORD			dwSpendedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_REPAIR_RES)
HOBJECT				hNpchandle;
WORD				wResultCode;
HOBJECT				hItem;
DWORD				dwSpendedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_USE_RES)
WORD			wResultCode;
TBLIDX			tblidxItem;
BYTE			byPlace;
BYTE			byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_CASTING_CANCELED)
HOBJECT			handle;
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_CASTING_DELAYED_NFY)
HOBJECT			handle;
WORD			wResultCode;
DWORD			dwCastingTime;
DWORD			dwCastingTimeRemaining;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_DUR_DOWN)
BYTE			byDur[MAX_EQUIP_ITEM_SLOT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_DUR_UPDATE)
HOBJECT			hItemHandle;
BYTE			byDur;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_STACK_UPDATE)
HOBJECT			hItemHandle;
BYTE			byStack;
bool			bIsNew;		// Effect 추가 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_UPGRADE_RES)
WORD			wResultCode;
BYTE			byStack;			// 스톤 사용후 스택갯수					-> 변경될 스택
BYTE			byGrade;			// 변경될 그레이드						-> 변경될 그레이드
BYTE			byItemPlace;		// 업그레이드 할 아이템의 컨테이너 위치
BYTE			byItemPos;			// 업그레이드 할 아이템의 위치
BYTE			byStonPlace;		// 호이포이스톤 컨테이너 위치
BYTE			byStonPos;			// 호이포이스톤 위치
BYTE			byBattleAttribute;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_IDENTIFY_RES)
HOBJECT			hItemHandle;
WORD			wResultCode;
sITEM_DATA      sItemData;			// 성공시에만 세팅
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_PICK_RES)
TBLIDX			itemTblidx;
WORD			wResultCode;
// Any message doesn't need to be displayed if 'bByPartyHunting' is true.
// (If a party member picks up an item, the message is displayed by another type of packet.)
// bByPartyHunting이 true이면 클라이언트에서 메세지를 출력할 필요가 없다.
// (파티 상태에서 drop된 아이템을 얻는 경우에는 다른 packet에 의해 메세지가 출력된다.)
bool			bByPartyHunting;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ZENNY_PICK_RES)
WORD			wResultCode;
bool			bSharedInParty;
DWORD			dwZenny;
DWORD			dwAcquisitionZenny;
DWORD			dwBonusZenny;
// 'dwOriginalZenny' MUST NOT be referred if 'bSharedInParty' is false.
DWORD			dwOriginalZenny; //Drop Zenny
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_STATE)
HOBJECT			handle;
sCHARSTATE		sCharState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_ASPECT_STATE)
HOBJECT			handle;
sASPECTSTATE	aspectState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_CONDITION)
HOBJECT			handle;
DWORD			dwConditionFlag;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_EXP)
HOBJECT			handle;
DWORD			dwCurExp;
DWORD			dwIncreasedExp;
DWORD			dwAcquisitionExp;
DWORD			dwBonusExp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_LEVEL)
HOBJECT			handle;
BYTE			byPrevLevel;
BYTE			byCurLevel;
DWORD			dwMaxExpInThisLevel;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_SPEED)
HOBJECT			handle;
float			fLastWalkingSpeed;
float			fLastRunningSpeed;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_ATTACK_SPEEDRATE)
HOBJECT			handle;
WORD			wAttackSpeedRate;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_ITEM_EQUIP)
HOBJECT			handle;
BYTE			byPos;
sITEM_BRIEF		sItemBrief;		// 장착 해제 되었을 경우 INVALID VALUE가 들어 온다.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_ITEM_DELETED)
HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_TARGET_INFO)
HOBJECT			handle;
WORD			wCurLP;
WORD			wMaxLP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_LP)
HOBJECT			handle;
DWORD			dwLpEpEventId;
WORD			wCurLP;
WORD			wMaxLP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_EP)
HOBJECT			handle;
DWORD			dwLpEpEventId;
WORD			wCurEP;
WORD			wMaxEP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_RP)
HOBJECT			handle;
WORD			wCurRP;
WORD			wMaxRP;
bool			bHitDelay;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_LP_EP)
HOBJECT			handle;
DWORD			dwLpEpEventId;
WORD			wCurLP;
WORD			wMaxLP;
WORD			wCurEP;
WORD			wMaxEP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_ZENNY)
HOBJECT			handle;
DWORD			dwZenny;
bool			bIsNew;		// Effect 추가
BYTE			byChangeType; // eZENNY_CHANGE_TYPE - NtlCharacter.h
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_MUDOSA_POINT)
DWORD			dwMudosaPoint;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SYSTEM_DISPLAY_TEXT)
WCHAR			awGMChar[MAX_SIZE_CHAR_NAME_UNICODE + 1];
BYTE			byDisplayType;				// eSERVER_TEXT_TYPE
WORD			wMessageLengthInUnicode;
WCHAR			awchMessage[MAX_LENGTH_OF_CHAT_MESSAGE_UNICODE + 1]; // 내용
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SYSTEM_DISPLAY_RESULTCODE)
BYTE			byDisplayType;				// eSERVER_TEXT_TYPE
WORD			wResultCode;				// 출력할 ResultCode
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_START_RES)
HOBJECT			handle;
BYTE			byType; //	0: 기본  1:한정수량 판매 이벤트 NPC 
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_BUY_RES)
HOBJECT			handle;
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_SELL_RES)
HOBJECT			handle;
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_END_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_SKILL_BUY_RES)
HOBJECT				hNpchandle;
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CREATE_RES)
WORD			wResultCode;
WCHAR			wszPartyName[MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DISBAND_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DISBANDED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVITE_RES)
WORD			wResultCode;
WCHAR			wszTargetName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVITE_NFY)
bool			bFromPc;
union
{
	WCHAR				wszInvitorPcName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
	WCHAR				wszInvitorPartyName[MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
};
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_RESPONSE_INVITATION_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_JOINED_NFY)
sPARTY_MEMBER_INFO		memberInfo;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INFO)
WCHAR					awchPartyName[MAX_SIZE_PARTY_NAME_IN_UNICODE + 1];
HOBJECT					hLeader;
BYTE					byItemLootingMethod;
BYTE					byZennyLootingMethod;
TBLIDX					registeredCharmTblidx[PARTY_CHARM_INVENTORY_COUNT];
DWORD					adwRemainingTime[PARTY_CHARM_INVENTORY_COUNT];
sSHARETARGET_INFO		sharetargetInfo[MAX_SHARETARGET_COUNT];// 공유타겟데이타 [3/28/2008 SGpro]
ePARTY_DUNGEON_STATE	eDiff; // ePARTY_DUNGEON_STATE
BYTE					byItemRank;			// 파티인벤에 넣을 아이템의 eITEM_RANK 추가
BYTE					byMemberInfoCount;
sPARTY_MEMBER_INFO		memberInfo[MAX_MEMBER_IN_PARTY - 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVENTORY_INFO)
BYTE								bySlotInfoCount;
//sDBO_PARTY_INVENTORY_SLOT_INFO		inventorySlotInfo[PARTY_INVENTORY_SLOT_COUNT]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_OPENED_CHARM_INVENTORY_INFO)
BYTE							byCharmInventoryIndex;
//sDBO_PARTY_VICTIM_ITEM_INFO		victimItemInfo; // TODO
DWORD							dwTotalVictimZenny;
BYTE							byVictimInfoCount;
//sDBO_VICTIM_INFO				aVictimInfo[MAX_MEMBER_IN_PARTY - 1]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVITATION_DECLINED_NFY)
WCHAR			wszPlayerName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVITATION_EXPIRED_NFY)
WCHAR			wszPlayerName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_LEAVE_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_LEFT_NFY)
HOBJECT			hMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_KICK_OUT_RES)
WORD			wResultCode;
HOBJECT			hTargetMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_KICKED_OUT_NFY)
HOBJECT			hMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHANGE_LEADER_RES)
WORD			wResultCode;
HOBJECT			hNewLeader;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_LEADER_CHANGED_NFY)
HOBJECT					hNewLeader;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_LEVELED_UP_NFY)
HOBJECT			hMember;
BYTE			byLevel;
WORD			wMaxLP;
WORD			wMaxEP;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_CLASS_CHANGED_NFY)
HOBJECT			hMember;
BYTE			byNewClass;		// ePC_CLASS
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_OPEN_CHARM_SLOT_RES)
WORD			wResultCode;
BYTE			byCharmInventoryIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_SLOT_OPENED_NFY)
BYTE			byCharmInventoryIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CLOSE_CHARM_SLOT_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_SLOT_CLOSED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_REGISTER_VICTIM_ITEM_RES)
WORD			wResultCode;
BYTE			bySrcPlace;
BYTE			bySrcPos;
BYTE			byDestSlotIndex;
DWORD			dwTotalVictimItemScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_VICTIM_ITEM_REGISTERED_NFY)
HOBJECT			hMember;
//sDBO_PARTY_VICTIM_ITEM_INFO		itemInfo; // TODO
DWORD			dwTotalVictimItemScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_UNREGISTER_VICTIM_ITEM_RES)
WORD			wResultCode;
BYTE			byDestSlotIndex;
DWORD			dwTotalVictimItemScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_VICTIM_ITEM_UNREGISTERED_NFY)
HOBJECT			hMember;
TBLIDX			itemTblidx;
BYTE			byDestSlotIndex;
DWORD			dwTotalVictimItemScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_REGISTER_VICTIM_ZENNY_RES)
WORD			wResultCode;
DWORD			dwRegisteredZenny;
DWORD			dwReturningZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_VICTIM_ZENNY_REGISTERED_NFY)
HOBJECT			hMember;
DWORD			dwIncreasedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_UNREGISTER_VICTIM_ZENNY_RES)
WORD			wResultCode;
DWORD			dwUnregisteredZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_VICTIM_ZENNY_UNREGISTERED_NFY)
HOBJECT			hMember;
DWORD			dwDecreasedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DECLARE_ZENNY_RES)
WORD							wResultCode;

DWORD							dwInitialZenny;
DWORD							dwFinalDeclaredZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DECLARED_ZENNY_CHANGED_NFY)
HOBJECT							hMember;
DWORD							dwDeclaredZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_ACTIVATION_FAILED_NFY)
WORD							wResultCode;
HOBJECT							hMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ACTIVATE_CHARM_RES)
WORD			wResultCode;
BYTE							byCharmInventoryIndex;
TBLIDX							registeredCharmTblidx;
DWORD							dwRemainingTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_ACTIVATED_NFY)
BYTE							byCharmInventoryIndex;
TBLIDX							registeredCharmTblidx;
DWORD							dwRemainingTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DEACTIVATE_CHARM_RES)
WORD							wResultCode;
BYTE							byCharmInventoryIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_DEACTIVATED_NFY)
BYTE							byCharmInventoryIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHANGE_ZENNY_LOOTING_METHOD_RES)
WORD							wResultCode;
BYTE							byNewLootingMethod;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ZENNY_LOOTING_METHOD_CHANGED_NFY)
BYTE							byNewLootingMethod;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHANGE_ITEM_LOOTING_METHOD_RES)
WORD							wResultCode;
BYTE							byNewLootingMethod;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ITEM_LOOTING_METHOD_CHANGED_NFY)
BYTE							byNewLootingMethod;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ZENNY_LOOTING_METHOD_UNLOCKED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ITEM_LOOTING_METHOD_UNLOCKED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_ZENNY_UPDATED_NFY)
BYTE byMemberCount;
sINVEST_ZENNY_INFO aZennyInfo[MAX_MEMBER_IN_PARTY];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVENTORY_ITEM_ADDED_NFY)
BYTE							bySlotIndex;
sPARTY_INVENTORY_ITEM_INFO		newLoot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVENTORY_ITEM_REMOVED_NFY)
BYTE					byPos;
bool					bIsYourItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_GAINED_ITEM_NFY)
HOBJECT					hMember;
// If itemTblidx is INVALID_TBLIDX, this means an unidentified item.
// itemTblidx가 INVALID_TBLIDX일 경우, 감정이 필요한 아이템임을 뜻한다.
// by YOSHIKI(2006-11-02)
TBLIDX					itemTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_GAINED_ZENNY_NFY)
HOBJECT					hMember;
bool					bIsShared;
DWORD					dwZenny; //dwAcquisitionZenny + dwBonusZenny
DWORD					dwAcquisitionZenny;
DWORD					dwBonusZenny;

// 'dwOriginalZenny' MUST NOT be referred if 'bSharedInParty' is false.
// bSharedInParty가 false이면 dwOriginalZenny값은 참조해서는 안 된다.
// by YOSHIKI(2007-10-02)
DWORD					dwOriginalZenny; //Mob이 Drop한 Zenny
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEST_ZENNY_RES)
WORD					wResultCode;
BYTE					byPos;
DWORD					dwInvestedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEST_ZENNY_NFY)
BYTE					byPos;
DWORD					dwInvestedZenny;
HOBJECT					hMember;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVENTORY_ITEM_WINNER_CHANGED_NFY)
BYTE					byPos;
HOBJECT					hWinner;
DWORD					dwInvestedZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_MEMBER_LOCATION_NFY)
HOBJECT					hMember;
TBLIDX					worldTblidx;
WORLDID					worldId;
Vector3				vCurLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_START_RES)
HOBJECT			handle;			// Npc handle
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_MOVE_RES)
HOBJECT			handle;
HOBJECT			hSrcItem;
HOBJECT			hDstItem;
BYTE			bySrcPlace;
BYTE			bySrcPos;
BYTE			byDestPlace;
BYTE			byDestPos;
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_MOVE_STACK_RES)
HOBJECT			handle;
HOBJECT			hSrcItem;
HOBJECT			hDestItem;
BYTE			bySrcPlace;
BYTE			bySrcPos;
BYTE			byDestPlace;
BYTE			byDestPos;
BYTE			byStackCount1;
BYTE			byStackCount2;
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_END_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_ZENNY_INFO)
DWORD			dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_ITEM_INFO)
BYTE			byBeginCount;
BYTE			byItemCount;
sITEM_PROFILE	aBankProfile[MAX_COUNT_USER_HAVE_BANK_ITEM];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_ZENNY_RES)
HOBJECT				handle;
WORD				wResultCode;
DWORD				dwZenny;
bool				bIsSave;		// 1: saving 0: withdraw
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_BUY_RES)
HOBJECT				hNpchandle;
WORD				wResultCode;
HOBJECT				hItemhandle;
sITEM_DATA			sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_ITEM_DELETE_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SOCIAL_ACTION)
HOBJECT			hSubject;
TBLIDX			socialActionId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_INDICATOR_RES)
HOBJECT			hTarget;
WORD			wResultCode;
DWORD			dwRetValue;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_PREDICT_RES)
BYTE			byPusNum;
WORD			wResultCode;
BYTE			byRetRate;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_EQUIP_CHECK_RES)
HOBJECT			hTarget;
WORD			wResultCode;
BYTE			byItemCount;
sITEM_PROFILE	aItemProfile[MAX_EQUIP_ITEM_SLOT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_CHIP_REMOVE_ALL_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_CONFIRM_STEP_RES)
BYTE				byTsType; // 트리거 타입
WORD				wResultCode;
TS_T_ID				tId;
TS_TC_ID			tcCurId;
TS_TC_ID			tcNextId;
DWORD				dwParam;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_UPDATE_SYNC_NFY)
BYTE				byTsType; // 트리거 타입
TS_T_ID				tId;
TS_TC_ID			tcId;
TS_TA_ID			taId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_UPDATE_STATE)
BYTE				byTsType; // 트리거 타입
TS_T_ID				tId;
BYTE				byType;
WORD				wTSState;
DWORD				dwParam;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_UPDATE_EVENT_NFY)
BYTE				byTsType; // 트리거 타입
TS_EVENT_ID			teid;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_EXCUTE_TRIGGER)
BYTE				byTsType; // 트리거 타입
TS_T_ID			tId; // 트리거 아이디
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_EXCUTE_TRIGGER_OBJECT_RES)
WORD				wResultCode;
HOBJECT				hTriggerObject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_TRIGGER_OBJECT_DIALOG_NFY)
HOBJECT				hTriggerObject;
BYTE				byDialogType;		// eNPCCONV_TYPE
TBLIDX				textTblidx;			// text
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_PC_DIALOG_NFY)
TBLIDX				textTblidx;			// text
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TS_SKIP_CONTAINER)
TS_T_ID			tId;
TS_TC_ID		tcId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_ITEM_CREATE_NFY)
BYTE				byPos;
TBLIDX				qItemTblidx;
BYTE				byCurCount;			// 현재 카운트
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_ITEM_DELETE_NFY)
BYTE				byDeletePos;		// 삭제한 아이템의 위치
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_ITEM_UPDATE_NFY)
BYTE				byPos;
BYTE				byCurCount;			// 현재 카운트
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_ITEM_MOVE_RES)
WORD				wResultCode;
BYTE				bySrcPos;
TBLIDX				dwSrcTblidx;
BYTE				byDestPos;
TBLIDX				dwDestTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_ITEM_DELETE_RES)
WORD				wResultCode;
BYTE				byDeletePos;		// 삭제한 아이템의 위치
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_SVREVT_START_NFY)
TS_T_ID				tId;
TS_TC_ID			tcId;
TS_TA_ID			taId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_SVREVT_END_NFY)
TS_T_ID				tId;
TS_TC_ID			tcId;
TS_TA_ID			taId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_SVREVT_UPDATE_NFY)
TS_T_ID				tId;
TS_TC_ID			tcId;
TS_TA_ID			taId;
BYTE					bySvrEvtType;		// eSTOC_EVT_DATA_TYPE
BYTE					bySlot;
uSTOC_EVT_UPDATE_DATA	uEvtData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_GIVEUP_RES)
TS_T_ID			tId;
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_SHARE_NFY)				// 퀘스트 공유
WORD				wResultCode;
TS_T_ID			tId;
HOBJECT				hActor;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_RESET_NFY)			// 퀘스트의 지정된 범위만큼 진행 정보와 완료 정보를 삭제한다.
QUESTID				startResetQID;		// 범위 지정
QUESTID				endResetQID;		// 범위 지정
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_OBJECT_VISIT_RES)
WORD				wResultCode;

QUESTID				qId;
WORLDID				worldId;
BYTE				byObjType;
TBLIDX				objectTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUEST_FORCED_COMPLETION_NFY)
QUESTID				questId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_CHALLENGE_RES)
HOBJECT				hTarget; // 대전을 요청했던 타겟의 핸들
WORD				wResultCode; // 응답 코드
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_ACCEPT_REQ)
HOBJECT				hChallenger; // 대전을 요청한 캐릭터의 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_CANCEL_NFY)
WORD				wResultCode; // 대전취소에 대한 이유
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_START_NFY)
HOBJECT				hTarget; // 대전상대 핸들
Vector3				vRefreeLoc;	// 심판 위치
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_OUTSIDE_NFY)

END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_INSIDE_NFY)

END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_FREEBATTLE_END_NFY)
BYTE				byFreeBattleResult; // eFREEBATTLE_RESULT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_WORLD_FREE_PVP_ZONE_ENTERED_NFY)
HOBJECT				handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_WORLD_FREE_PVP_ZONE_LEFT_NFY)
HOBJECT				handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUICK_SLOT_UPDATE_RES)
WORD				wResultCode;
TBLIDX				tblidx;
BYTE				bySlotID;
BYTE				byType;
BYTE				byPlace;
BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUICK_SLOT_DEL_NFY)
BYTE				bySlotID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_QUICK_SLOT_INFO)
BYTE				byQuickSlotCount;
sQUICK_SLOT_PROFILE	asQuickSlotData[CHAR_QUICK_SLOT_MAX_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PET_CHAR_INFO)
HOBJECT				handle;
BYTE				byObjectType;		// eOBJTYPE
union
{
	sSUMMON_PET_PROFILE		sSummonPetProfile;
	sITEM_PET_PROFILE		sItemPetProfile;
};
WORD				wCharStateSize; //-[9/7/2006 zeroera] : 설명 : 클라이언트를 위한 캐릭터상태 사이즈 정보
sCHARSTATE			sCharState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PET_SKILL_INFO)
BYTE				bySkillCount;
sSKILL_INFO_PET		aSkillInfo[MAX_NPC_HAVE_SKILL];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PET_INFO_END)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PET_DESPAWNED_NFY)
BYTE				byAvatarType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PET_DISMISS_PET_RES)
WORD				wResultCode;
BYTE				byAvatarType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ACTION_REPORT_MESSAGE)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_START_NFY)
HOBJECT				handle;			// Requestor handle
HOBJECT				hTarget;		// The target handle (yourself)
WORD				wResultCode;	// 타겟의 응답및 가능 유무 에 따른 여러가지 결과값
BYTE				byEmptyInven;	// 상대의 인벤의 빈공간	(만약 최대칸보다 작으면 비활성칸수 표시)	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_START_RES)
HOBJECT				handle;			// Requestor handle
HOBJECT				hTarget;		// Target handle
WORD				wResultCode;	// 타겟의 응답및 가능 유무 에 따른 여러가지 결과값
BYTE				byEmptyInven;	// 상대의 인벤의 빈공간	(만약 최대칸보다 작으면 비활성칸수 표시)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_OK_REQ)
HOBJECT				handle;			// 요청자의 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_ADD_NFY)			// 성공일 때만
											//HOBJECT				hTarget;			// 타겟 핸들
HOBJECT				hItem;				// 상대 아이템 핸들
sITEM_DATA			sItem;				// 상대가 올려 놓을 아이템의 정보
BYTE				byCount;			// 겹쳐있는 아이템중 몇개인가? Default 1개
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_ADD_RES)
//HOBJECT				hTarget;			// 타겟 핸들
HOBJECT				hItem;				// 내 아이템 핸들
BYTE				byCount;			// 겹쳐있는 아이템중 몇개인가? Default 1개
WORD				wResultCode;		// 타겟의 응답및 가능 유무 에 따른 여러가지 결과값
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_DEL_NFY)			// 성공일 때만
											//HOBJECT				hTarget;			// 타겟 핸들
	HOBJECT				hItem;				// 상대 아이템 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_DEL_RES)
//HOBJECT				hTarget;			// 타겟 핸들
HOBJECT				hItem;				// 내 아이템 핸들
WORD				wResultCode;		// 타겟의 응답및 가능 유무 에 따른 여러가지 결과값
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_MODIFY_NFY)
HOBJECT				hTarget;			// 타겟 핸들
HOBJECT				hItem;				// 내 아이템 핸들
BYTE				byCount;			// 겹쳐있는 아이템중 몇개인가? Default 1개
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_MODIFY_RES)
HOBJECT				hTarget;			// 타겟 핸들
HOBJECT				hItem;				// 내 아이템 핸들
BYTE				byCount;			// 겹쳐있는 아이템중 몇개인가? Default 1개
WORD				wResultCode;		// 타겟의 응답및 가능 유무 에 따른 여러가지 결과값
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_ZENNY_UPDATE_NFY)	// 성공일 때만
HOBJECT				hTarget;			// 타겟 핸들
DWORD				dwZenny;			// 옮길 만큼의 제니 (자기가 갖고 있는 제니 한도 내)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_ZENNY_UPDATE_RES)
HOBJECT				hTarget;			// 타겟 핸들
DWORD				dwZenny;			// 옮길 만큼의 제니 (자기가 갖고 있는 제니 한도 내 상대의 제니가 오버 되면 자동 실패)
WORD				wResultCode;		// 타겟의 응답및 가능 유무 에 따른 여러가지 결과값
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_END_NFY)
HOBJECT				hTarget;			// 타겟 핸들
WORD				wResultCode;		// 타겟의 응답및 가능 유무 에 따른 여러가지 결과값
bool				bIsSet;				// false: 풀림 true: 잠김
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_END_RES)
HOBJECT				hTarget;			// 타겟 핸들
DWORD				dwPacketCount;		// 상대방의 변경 카운트 ( 상대방이 물건을 올려놓거나 삭제 혹은 변경 등 패킷받은 개수 )
WORD				wResultCode;		// 타겟의 응답및 가능 유무 에 따른 여러가지 결과값
bool				bIsSet;				// false: 풀림 true: 잠김
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_CANCEL_NFY)
HOBJECT				hTarget;			// 타겟 핸들
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_CANCEL_RES)
HOBJECT				hTarget;			// 타겟 핸들
WORD				wResultCode;		// 타겟의 응답및 가능 유무 에 따른 여러가지 결과값
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRADE_DENY_RES)
bool				bIsDeny;			// 거절 프레그 
WORD				wResultCode;		// 만약 교환중이라면 실패한다. 그외 성공 및 결과
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_NAME_CHANGED_NFY)
HOBJECT				hSubject;
WCHAR				wszGuildName[MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_CREATE_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_INVITE_RES)
WORD				wResultCode;
WCHAR				wszTargetName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TOBJECT_UPDATE_STATE)
HOBJECT				handle;
sTOBJECT_BRIEF		tobjectBrief;
sTOBJECT_STATE		tobjectState;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TOBJECT_ACTION_ATTACK)
HOBJECT				hSubject;				// 액션 주체 캐릭터 핸들
HOBJECT				hTarget;				// 액션 타겟 캐릭터 핸들
BYTE				byAttackType;			// 액션 결과 ( eBATTLE_ATTACK_RESULT )
BYTE				byAttackResult;			// 액션 결과 ( eBATTLE_ATTACK_RESULT )
WORD				wAttackResultValue;		// 액션의 결과 값 ( 데미지 )
Vector3			vShift;					// 어택으로 인한 이동 벡터
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TUTORIAL_HINT_UPDATE_RES)
WORD				wResultCode;
DWORD				dwTutorialHint;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_ROOM_LIST_RES)
WORD					wResultCode;			// 응답코드
//sTIMEQUEST_ROOM_TMQ_INFO	sTMQInfo; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_ROOM_INFO_RES)
WORD					wResultCode;			// 응답코드
BYTE						byRoomState;			// eTIMEQUEST_ROOM_STATE
//uTIMEQUEST_ROOM_ICON_INFO	sIconInfo; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_ROOM_JOIN_RES)
WORD					wResultCode;			// 응답코드
//sTIMEQUEST_ROOM_JOIN_INFO	sJoinInfo; // TODO
HOBJECT						hTroubleMember;			// join이 실패한 pc의 핸들
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_ROOM_JOIN_NFY)
//sTIMEQUEST_ROOM_JOIN_INFO	sJoinInfo; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_ROOM_LEAVE_RES)
WORD					wResultCode;			// 응답코드
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_ROOM_LEAVE_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_ROOM_SELECTION_NFY)
bool							bIsSecondWinner;
//uTIMEQUEST_ROOM_SELECTION_INFO	uSelectionInfo; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_ROOM_TELEPORT_RES)
WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_START_NFY)
WORD					wResultCode;			// 결과 코드 ( 실패 할 수도 있음, 반드시 확인할 것)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_START_EXCEPTION_NFY)
WORD					wResultCode;			// 결과 코드
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_LEAVE_NFY)
HOBJECT					handle;					// 퇴장한 멤버의 핸들
WORD					wResultCode;			// 이유를 나타내는 응답 코드
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_COUNTDOWN_NFY)
bool					bCountDown;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_REWARD_NFY)
BYTE					byTriggerType;			// 보상 관련 ts타입 정보
TS_EVENT_ID			teid;					// 보상 관련 ts이벤트 정보
DWORD					dwWaitTime;				// Reward Wait 시간
DWORD					dwClearTime;			// 클리어 시간
DWORD					dwBonusTime;			// 보너스 시간
bool					bIsDayRecord : 1;			// DayRecord를 세웠을 경우 true
bool					bIsBestRecord : 1;			// 베스트 레코드를 세웠을 경우에는 true
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_INFORMATION_NFY)
BYTE					byInfoType;				// 정보 타입 eTIMEQUEST_INFORMATION_TYPE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TELECAST_MESSAGE_BEG_NFY)
TBLIDX					npcTblidx;				// 방송을 하는 NPC 테이블 인덱스
BYTE					byTelecastType;			// 방송 타입 eTELECAST_MESSAGE_TYPE
TBLIDX					speechTblidx;			// 방송내용을 담은 Speech 테이블 인덱스
DWORD					dwDisplayTime;			// 방송시간을 나타내는 millisec ( INVALID_DWORD 이면 telecast를 계속 띄우고, 아니면 이 시간이 지나면 없앨 것 )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TELECAST_MESSAGE_END_NFY)

END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BROAD_MESSAGE_BEG_NFY)
BYTE byUIDirType;			// eBROAD_MSG_UI_DIR_TYPE
BYTE byUIShowHideTypel;		// eBROAD_MSG_UI_SHOWHIDE_DIR_TYPE
BYTE byUIBalloonShapeType;	// eBROAD_MSG_UI_BALLOON_SHAPE_TYPE
BYTE byUISpeechDirType;		// eBROAD_MSG_UI_SPEECH_DIR_TYPE
BYTE byOwnerCondition;		// eBROAD_MSG_OWNER_CONDITION
BYTE byOwnerType;			// eBROAD_MSG_OWNER_TYPE
unsigned int uiOwnerTblIdx;
unsigned int uiQuestTextTblidx;
float fDisplayTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BROAD_MESSAGE_END_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MINI_NARRATION_NFY)
unsigned int uiNarrtionTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PROGRESS_MESSAGE_NFY)
BYTE					byProgressType;			// 진행 타입 ePROGRESS_MESSAGE_TYPE
BYTE					byMessageType;			// 메시지 타입 eTIMEQUEST_MESSAGE_TYPE
BYTE					byMessageValue;			// 메시지의 값 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DIRECTION_INDICATE_NFY)
bool					bIndicate;				// true : Arrow On, false : Arrow Off
Vector3				vLoc;					// 지정위치 ( Off 일경우 Access하지 말것 )
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_UPDATE_GAME_STATE)
//sTIMEQUEST_STATE		sTimeQuestState; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_UPDATE_KILL_COUNT)
HOBJECT					handle;					// 타임 퀘스트 중에 기절한 
BYTE					byKillCount;			// 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_UPDATE_COUPON_COUNT)
BYTE					byCouponCount;			// 타임 퀘스트 쿠폰 개수
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_UPDATE_TMQ_POINT)
WORD					wTmqPoint;				// 타임 퀘스트 TMQ 포인트
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TIMEQUEST_UPDATE_GAME_TIME)
DWORD					dwClearTime;			// 타임 퀘스트 클리어 시간 ( 증가되는 시간 )
DWORD					dwBonusTime;			// 타임 퀘스트 보너스 시간
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_INFO_RES)
WORD					wResultCode;

BYTE					byBattleMode;		// eRANKBATTLE_MODE
DWORD					dwRemainTime;		// 남은 시간
BYTE					byArenaCount;
//sRANKBATTLE_ARENA_INFO	asArenaInfo[1]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_JOIN_RES)
WORD					wResultCode;

HOBJECT					hBoardObject;
TBLIDX					rankBattleTblidx;
DWORD					dwRemainTime;		// 남은 시간
BYTE					byArenaCount;
//sRANKBATTLE_ARENA_INFO	asArenaInfo[1]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_JOIN_NFY)
TBLIDX					rankBattleTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_LEAVE_RES)
WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_LEAVE_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_MATCH_START_NFY)
WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_MATCH_CANCELED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_LIST_RES)
WORD					wResultCode;

TBLIDX					rankBattleTblidx;	// RankBattle Tblidx

WORD					wTotalPage;			// 게시판 총 페이지
WORD					wCurPage;			// 게시판 출력 Page

BYTE					byRoomMode;			// RankBattle 모드 : eRANKBATTLE_MODE
BYTE					byRoomCount;		// 전송하는 Room의 갯수

//uRANKBATTLE_ROOMINFO_LIST	uRoomList;		// Room List // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_INFO_RES)
WORD						wResultCode;

// 패킷 사이즈 계산에 주의한다.
// if( RANKBATTLE_MODE_INDIVIDUAL == byBattleMode )
// {
//		wMsgSize = sizeof(sGU_RANKBATTLE_ROOM_INFO_RES) - sizeof(uRANKBATTLE_ROOMINFO) + sizeof(sRANKBATTLE_ROOMINFO_INDIVIDUAL);
// }
// else if (RANKBATTLE_MODE_PARTY == byBattleMode )
// {
//		wMsgSize = sizeof(sGU_RANKBATTLE_ROOM_INFO_RES) - sizeof(uRANKBATTLE_ROOMINFO) + sizeof(sRANKBATTLE_ROOMINFO_PARTY) + sizeof(sRANKBATTLE_ROOMINFO_MEMBER) * (msg->uRoom.sParty.byMemberCount - 1);
// }

BYTE						byRoomMode;		// eRANKBATTLE_MODE
//uRANKBATTLE_ROOMINFO		uRoom; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_CREATE_RES)
WORD						wResultCode;
TBLIDX						rankBattleTblidx;	// RankBattle Tblidx
ROOMID						roomId;
BYTE						byTroubleCount;		// 문제를 가지는 멤버의 수
//sRANKBATTLE_MEMBER_RESULT	asTroublePc[1];		// 문제를 가지는 멤버 정보 // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_CREATE_NFY)
WORD				wResultCode;
TBLIDX				rankBattleTblidx;	// RankBattle Tblidx
ROOMID				roomId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_LEAVE_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_LEAVE_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_JOIN_INFO_NFY)
TBLIDX				rankBattleTblidx;	// RankBattle Tblidx
ROOMID				roomId;
BYTE				byTeamType;			// eRANKBATTLE_TEAM_TYPE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_CHALLENGE_RES)
WORD						wResultCode;
TBLIDX						rankBattleTblidx;	// RankBattle Tblidx
ROOMID						roomId;				// 방 번호
BYTE						byTroubleCount;		// 문제를 가지는 멤버의 수
//sRANKBATTLE_MEMBER_RESULT	asTroublePc[1];		// 문제를 가지는 멤버 정보 // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_CHALLENGE_NFY)
WORD				wResultCode;
TBLIDX				rankBattleTblidx;	// RankBattle Tblidx
ROOMID				roomId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_MATCH_READY_NFY)
WORD						wResultCode;
BYTE						byMemberCount;		// 멤버 수
//sRANKBATTLE_MEMBER_RESULT	asMemberResult[1];	// 멤버 정보 // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_MATCH_START_NFY)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_MATCH_CANCEL_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_ROOM_MATCH_CANCELED_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_BATTLE_STATE_UPDATE_NFY)
BYTE				byBattleState;
BYTE				byStage;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_BATTLE_TEAM_INFO_NFY)
WORD				wStraightWinCount;		// 연승 카운트
WORD				wStraightKOWinCount;	// KO 연승 카운트
BYTE				byCount;				// 인원
WORD				wMemberInfo;			// sRANKBATTLE_MATCH_MEMBER_INFO [byCount]
WORD				wOwnerPartyName;		// WCHAR [MAX_SIZE_PARTY_NAME_IN_UNICODE]
WORD				wChallengerPartyName;	// WCHAR [MAX_SIZE_PARTY_NAME_IN_UNICODE]
//sVARIABLE_DATA		sData; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_BATTLE_PLAYER_STATE_NFY)
HOBJECT				hPc;
BYTE				byPCState;	// eRANKBATTLE_MEMBER_STATE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_BATTLE_KILLSCORE_UPDATE_NFY)
BYTE				byOwnerKillScore;
BYTE				byChallengerKillScore;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_BATTLE_STAGE_FINISH_NFY)
BYTE				byBattleResult;			// eRANKBATTLE_MATCH_RESULT
//sRANKBATTLE_SCORE	sStageScore; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_BATTLE_MATCH_FINISH_NFY)
//sRANKBATTLE_MATCH_FINISH_INFO	sMatchResult; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_BATTLE_END_NFY)
BYTE					byMatchWinner;		// eRANKBATTLE_MATCH_RESULT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_BATTLE_FORCED_LEAVE_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RANKBATTLE_TOTAL_SCORE_UPDATE_NFY)
BYTE					byBattlemode;
//sRANKBATTLE_SCORE_INFO	sTotalScore; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DRAGONBALL_CHECK_RES)// 드래곤볼 UI 7개 배치OK
HOBJECT				hObject;			// TS Object 제단	
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DRAGONBALL_REWARD_RES)// 드래곤볼 다 모음에 대한 보상 선택 요청
HOBJECT				hObject;			// TS Object 제단
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DRAGONBALL_COLLECT_NFY) // 서버의 일방적인 통보
HOBJECT				hObject;			// TS Object 제단
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DRAGONBALL_SCHEDULE_INFO)
bool						bIsAlive;			// 기간 유무 false: 기간이 아니다
BYTE						byEventType;		// eSCHEDULE_EVENT_TYPE
__int64						nStartTime;			// What time of day it starts
__int64						nEndTime;           // What time of day it ends (how far away from start time)
DWORD						dwMainTerm;			// Month/Day/Hour Based on Term Type
DWORD						dwSubTerm;			// Expires on Month/Day/Hour based on Term Type
BYTE						byTermType;			// 0: Month 1: Day 2: Hour
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_CREATE_RES)
WORD		 				wResultCode;
sPACKET_PRIVATESHOP_SHOP_DATA		sPrivateShopData;
//Private Shop Item들은 GU_PRIVATESHOP_ITEM_DATA_INFO로 보낸다
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_CREATE_NFY)
HOBJECT							hOwner;
sSUMMARY_PRIVATESHOP_SHOP_DATA	sSummaryPrivateShopData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_EXIT_RES)
WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_OPEN_RES)
WORD						wResultCode;
sSUMMARY_PRIVATESHOP_SHOP_DATA	sSummaryPrivateShopData;
BYTE							byNoticeSize;
WCHAR							wcNotice[MAX_PRIVATESHOP_NOTICE_IN_UNICODE + 1];
//wcNotice가 가변이기 때문에 wcNotice 밑에다 새로운 변수를 설정하면 절대로 안된다.
//반드시 byNoticeSize위에 변수 선언을 할것.[10/2/2007 SGpro]
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_OPEN_NFY)
HOBJECT							hOwner;//상점 주인 CharacterID
sSUMMARY_PRIVATESHOP_SHOP_DATA	sSummaryPrivateShopData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_CLOSE_RES)
WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_CLOSE_NFY)
HOBJECT						hOwner;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ITEM_INSERT_RES)
WORD						wResultCode;
sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ITEM_UPDATE_RES)
WORD						wResultCode;
DWORD						dwZenny;
BYTE						byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ITEM_DELETE_RES)
WORD						wResultCode;
sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ITEM_BUYING_RES)
WORD						wResultCode;
sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData[MAX_BUY_SHOPPING_CART];
BYTE						byBuyItemCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ITEM_BUYING_NFY)
HOBJECT						hPrivateShopOwner;
sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData[MAX_BUY_SHOPPING_CART];
BYTE						byBuyItemCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ENTER_RES)
WORD						wResultCode;
sPACKET_PRIVATESHOP_SHOP_DATA		sPrivateShopData;
//Private Shop Item들은 GU_PRIVATESHOP_ITEM_DATA_INFO로 보낸다
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_LEAVE_RES)
WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ITEM_DATA_INFO)
WORD						wResultCode;
HOBJECT						hOwnerID;
sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ITEM_SELECT_RES)
WORD				wResultCode;
//HOBJECT				hOwner;
BYTE				byPrivateShopInventorySlotPos;
BYTE				byItemState;//eITEMSTATE 값을 갖는다
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ITEM_SELECT_NFY)
//HOBJECT				hOwner;
BYTE				byPrivateShopInventorySlotPos;
BYTE				byItemState;//eITEMSTATE 값을 갖는다
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_ITEM_STATE_NFY)
//HOBJECT				hOwner;
BYTE				abyPrivateShopItemState[MAX_PRIVATESHOP_INVENTORY];
int					nPrivateShopItemStateCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_LEAVE_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_REQUEST_RES)
WORD						wResultCode;
BYTE						byPrivateShopInventorySlotPos;
BYTE						byItemState;//eITEMSTATE 값을 갖는다
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_REQUEST_NFY)
HOBJECT						hOwner;
BYTE						byPrivateShopInventorySlotPos;
BYTE						byItemState;//eITEMSTATE 값을 갖는다
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_CONSENT_REQ)
HOBJECT						hVisitorID;
BYTE						byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_CONSENT_NFY)
HOBJECT						hOwner;
BYTE						byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_WAITTIMEOUT_NFY)
HOBJECT						hOwner;
BYTE						byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_RES)
WORD						wResultCode;
BYTE						byPrivateShopInventorySlotPos;
DWORD						dwBeforeZenny;
DWORD						dwAfterZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_PRICEFLUCTUATIONS_NFY)
HOBJECT						hOwner;
BYTE						byPrivateShopInventorySlotPos;
DWORD						dwBeforeZenny;
DWORD						dwAfterZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_RES)
WORD						wResultCode;
sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_IMMEDIATE_ITEM_BUYING_NFY)
HOBJECT						hPrivateShopOwner;
sPRIVATESHOP_ITEM_DATA		sPrivateShopItemData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_WINDOWCLOSE_NFY)
HOBJECT						hPrivateShopOwner;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_CANCEL_RES)
WORD				wResultCode;
BYTE				byCancelType;
BYTE				byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PRIVATESHOP_BUSINESS_CANCEL_NFY)
HOBJECT						hOwner;
BYTE						byCancelType;//1: 흥정대기때 취소, 2: 흥정때 취소
BYTE						byPrivateShopInventorySlotPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TUTORIAL_WAIT_NFY)
WORD						wWaitingCount; // 현재 자신앞의 대기수
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TUTORIAL_WAIT_CANCEL_RES)
WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TUTORIAL_PLAY_QUIT_RES)
WORD						wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_START_RES)
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
WORD 	wResultCode;	// 결과
bool	bIsAway;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_SEND_RES)
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
WCHAR wszTargetName[MAX_SIZE_CHAR_NAME_UNICODE + 1];	// 받을 캐릭 이름
WORD wResultCode;	// 성공유무
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_READ_RES)
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
MAILID	mailID;	// 메일 아이디
WORD	wResultCode;	// 메일이 이미 삭제 되었을 때는 실패 
BYTE	byRemainDay;
DBOTIME endTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_DEL_RES)
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
MAILID	mailID;	// 메일 아이디
WORD	wResultCode;	// 메일이 이미 삭제 되었을 때는 실패 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_RETURN_RES)
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
MAILID	mailID;	// 메일 아이디
WORD	wResultCode;	// 메일이 이미 삭제 되었을 때는 실패 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_RELOAD_RES)
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
WORD	wResultCode;	// 성공유무
BYTE	byMailCount;		// 현재 전체메일 카운트 
BYTE	byManagerCount;		// 읽지 않은 매니져 메일 카운트
BYTE	byNormalCount;		// 읽지 않은 노멀 메일 카운트
MAILID  aMailID[MAX_MAIL_SLOT_COUNT];	// 카운트에 해당하는 저장된 메일 아이디
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_RELOAD_NFY)		// 스케줄에 의해 일정시간에 따라 자동 송신
BYTE	byMailCount;		// 현재 전체메일 카운트 
BYTE	byManagerCount;		// 읽지 않은 매니져 메일 카운트
BYTE	byNormalCount;		// 읽지 않은 노멀 메일 카운트
MAILID  aMailID[MAX_MAIL_SLOT_COUNT];	// 카운트에 해당하는 저장된 메일 아이디
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_LOAD_RES)
HOBJECT	hObject;		// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
WORD	wResultCode;	// 성공유무
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_LOAD_DATA)
//sMAIL_NEW_PROFILE sData; // TODO
BYTE	byTextSize;
WCHAR	wszText[MAX_LENGTH_OF_MAIL_MESSAGE_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_LOAD_INFO)
sMAIL_NEW_PROFILE sData;
BYTE	byTextSize;
WCHAR	wszText[MAX_LENGTH_OF_MAIL_MESSAGE_IN_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_ITEM_RECEIVE_RES)
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
WORD wResultCode;	// 성공유무
MAILID	mailID;	// 메일 아이디
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_LOCK_RES)
HOBJECT	hObject;	// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
MAILID	mailID;	// 메일 아이디
bool	bIsLock;		// Lock 1: Unlock: 0
WORD 	wResultCode;	// 메일이 이미 삭제 되었을 때는 실패
BYTE	byExpiredDay;	// 남은날짜
DBOTIME	endTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_CLOSE_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MAIL_MULTI_DEL_RES)
HOBJECT	hObject;		// 메일송수신탑 오브젝트 (스카우트파츠 착용시 INVALID_OBJECT )
WORD	wResultCode;	// 메일이 이미 삭제 되었을 때는 실패
BYTE	byCount;
MAILID	aMailID[MAX_COUNT_OF_MULTI_DEL];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PORTAL_START_RES)
WORD			wResultCode;
HOBJECT			hNpcHandle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PORTAL_INFO)
BYTE			byCount;
PORTALID		aPortalID[PORTAL_MAX_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PORTAL_ADD_RES)
WORD			wResultCode;
HOBJECT			hNpcHandle;
PORTALID		PortalID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PORTAL_RES)
WORD			wResultCode;
HOBJECT			hNpcHandle;
BYTE			byPoint;		// 0~7까지 선택된 인덱스
Vector			vLoc;
Vector			vDir;
WORLDID			worldID;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_WAR_FOG_INFO)
BYTE			abyWarFogInfo[MAX_SIZE_WAR_FOG];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_WAR_FOG_UPDATE_RES)
WORD			wResultCode;
HOBJECT			handle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MOB_LUCKY_DROP_NFY)
HOBJECT			hMobhandle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_UPGRADE_ALL_NFY)
BYTE			abyGrade[ITEM_UPGRADE_EQUIP_COUNT];  // 배열 인덱스는 해당 Pos, Value는 해당 결과 그레이드( 255 INVALID는 아이템이 없는 경우)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BOT_BOTCAUTION_NFY)		//  [2/20/2008 SGpro]
HOBJECT			hBot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_REPUTATION)
HOBJECT			handle;
DWORD			dwReputation;
END_PROTOCOL()
//-----------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_FUNCTION_ADD_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_GIVE_ZENNY_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_START_RES)
HOBJECT			handle;			// Npc handle
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_MOVE_RES)
HOBJECT			handle;
HOBJECT			hSrcItem;
HOBJECT			hDstItem;
BYTE			bySrcPlace;
BYTE			bySrcPos;
BYTE			byDestPlace;
BYTE			byDestPos;
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_MOVE_STACK_RES)
HOBJECT			handle;
HOBJECT			hSrcItem;
HOBJECT			hDestItem;
BYTE			bySrcPlace;
BYTE			bySrcPos;
BYTE			byDestPlace;
BYTE			byDestPos;
BYTE			byStackCount1;
BYTE			byStackCount2;
ITEMID			splitItemId;
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_END_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_ZENNY_INFO)
DWORD			dwZenny;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_ITEM_INFO)
BYTE            byPlace;
BYTE			byItemCount;
sITEM_PROFILE	aItemProfile[MAX_BANK_ITEM_SLOT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_BANK_ZENNY_RES)
HOBJECT			handle;
WORD			wResultCode;
DWORD			dwZenny;
bool			bIsSave;		// 1: 저금 0: 인출
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CROSSFIRE_RES)
HOBJECT			hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_CREATE_MARK_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_CHANGE_MARK_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_MARK_CHANGED_NFY)
HOBJECT				hSubject;
sDBO_GUILD_MARK		sMark;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BANK_LOAD_RES)
HOBJECT				handle;			// Npc handle
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_CHANGE_NAME_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_SHARETARGET_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_SHARETARGET_NFY)
sSHARETARGET_INFO		sharetargetInfo[MAX_SHARETARGET_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RIDE_ON_BUS_RES)
HOBJECT				hTarget;			// Npc handle
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_RIDE_OFF_BUS_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TRANSFORM_CANCEL_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_ITEM_IDENTIFY_RES)
WORD			wResultCode;
HOBJECT			hNpchandle;		// NpcHandle
BYTE			byPlace;
BYTE			byPos;
sITEM_DATA      sItemData;			// 성공시에만 세팅
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_STATE_UPDATE_NFY)
BYTE			byMatchState;		// eBUDOKAI_MAJORMATCH_STATE
bool			bIsEnter;			// true : Enter, false : exit
BYTE			byStage;
DWORD			dwRemainTime;		// 밀리세컨드 단위
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_TEAM_INFO_NFY)
BYTE			byMatchIndex;		// 몇번째 경기인지?[개인:0~31, 팀:0~15]
BYTE			byTeamCount;
WORD			wTeamInfo_var;		// sMATCH_MINORMATCH_TEAM_INFO_VAR [MAX_MINORMATCH_TEAM_COUNT];
//sVARIABLE_DATA	sData; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_PLAYER_STATE_NFY)
HOBJECT			hPc;
BYTE			byPcState;			// eMATCH_MEMBER_STATE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_UPDATE_SCORE_NFY)
TEAMTYPE		wTeamType;
BYTE			byScore;
HOBJECT			hSlayer;			// 기절시킨 character
HOBJECT			hFainter;			// 기절한 character
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_TEAM_SCORE_NFY)
BYTE							byCount;
//sMATCH_MINORMATCH_TEAM_SCORE	aTeamScore[BUDOKAI_MAX_MINORMATCH_TEAM_COUNT]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_SELECTION_NFY)
TEAMTYPE		teamWinner;
BYTE			byTeamCount;
//sMINORMATCH_SELECTION_DATA	aSelection[BUDOKAI_MAX_MINORMATCH_TEAM_COUNT]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_STAGE_FINISH_NFY)
BYTE			byStageResult;		// eMATCH_RESULT
WORD			wStageWinner;		// Stage Winner TeamType
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MINORMATCH_MATCH_FINISH_NFY)
BYTE			byMatchResult;
WORD			wMatchWinner;
BYTE			byKillCount;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_STATE_UPDATE_NFY)
BYTE			byMatchState;		// eBUDOKAI_MAJORMATCH_STATE
bool			bIsEnter;			// true : Enter, false : exit
BYTE			byStage;
DWORD			dwRemainTime;		// 밀리세컨드 단위
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_TEAM_INFO_NFY)
BYTE			byMatchDepth;	// 개인[8강~32강] 팀[8강~16강]
BYTE			byMatchIndex;	// depth에 따른 경기 위치

BYTE			byTeamCount;
WORD			wTeamInfo_var;		// sMATCH_MINORMATCH_TEAM_INFO_VAR [2];
//sVARIABLE_DATA	sData; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_PLAYER_STATE_NFY)
HOBJECT			hPc;
BYTE			byPcState;			// eMATCH_MEMBER_STATE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_UPDATE_SCORE_NFY)
//sMATCH_SCORE	sStageScore;		// 스테이지 스코어 // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_STAGE_FINISH_NFY)
BYTE			byStageResult;		// eMATCH_RESULT
WORD			wStageWinner;		// Stage Winner TeamType
//sMATCH_SCORE	sMatchScore;		// 경기 스코어 // TODO
bool			bIsObserver;		// 옵져버 모드에서 사용
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_MAJORMATCH_MATCH_FINISH_NFY)
BYTE			byMatchResult;		// eMATCH_RESULT
WORD			wMatchWinner;		// Match Winner TeamType
//sMATCH_SCORE	sMatchScore;		// 경기 스코어 // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_STATE_UPDATE_NFY)
BYTE			byMatchState;		// eBUDOKAI_MAJORMATCH_STATE
bool			bIsEnter;			// true : Enter, false : exit
BYTE			byStage;
DWORD			dwRemainTime;		// 밀리세컨드 단위
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_TEAM_INFO_NFY)
BYTE			byMatchDepth;
BYTE			byMatchIndex;

BYTE			byTeamCount;
WORD			wTeamInfo_var;		// sMATCH_FINALMATCH_TEAM_INFO_VAR [4];
//sVARIABLE_DATA	sData; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_PLAYER_STATE_NFY)
HOBJECT			hPc;
BYTE			byPcState;			// eMATCH_MEMBER_STATE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_UPDATE_SCORE_NFY)
//sMATCH_SCORE	sStageScore;		// 스테이지 스코어 // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_STAGE_FINISH_NFY)
BYTE			byStageResult;		// eMATCH_RESULT
WORD			wStageWinner;		// Stage Winner TeamType
//sMATCH_SCORE	sMatchScore;		// 경기 스코어 // TODO
bool			bIsObserver;		// 옵져버 모드에서 사용
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_FINALMATCH_MATCH_FINISH_NFY)
BYTE			byMatchResult;		// eMATCH_RESULT
WORD			wMatchWinner;		// Match Winner TeamType
//sMATCH_SCORE	sMatchScore;		// 경기 스코어 // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MATCH_AWARDING_NFY)
//WORD			awTeamName[MAX_FINALMATCH_RESULT]; // TODO
//sVARIABLE_DATA	sData;	// WCHAR wszTeamName[MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1]; : 저장된 값은 NULL을 포함하지 않는다. // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_CONFUSE_TARGET_NFY)
HOBJECT			hSubject;
HOBJECT			hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_TERROR_COURSE_CHANGE_NFY)
HOBJECT			hSubject;
HOBJECT			hAttacker;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DICE_ROLL_RES)
WORD			wResultCode;
WORD			wDiceResult;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DICE_ROLLED_NFY)
HOBJECT			hSubject;
WORD			wDiceResult;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_STATE_INFO_NFY)
BUDOKAITIME							tmDefaultOpenTime;
bool								bRankbattleAllow;

//sBUDOKAI_UPDATE_STATE_INFO			sStateInfo; // TODO
//sBUDOKAI_UPDATE_MATCH_STATE_INFO	aMatchStateInfo[MAX_BUDOKAI_MATCH_TYPE]; // TODO

//sBUDOKAI_JOIN_INFO					sJoinInfo; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_UPDATE_STATE_NFY)
//sBUDOKAI_UPDATE_STATE_INFO			sStateInfo; // TODO
bool								bRankbattleAllow;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_UPDATE_MATCH_STATE_NFY)
BYTE								byMatchType;	// eBUDOKAI_MATCH_TYPE
//sBUDOKAI_UPDATE_MATCH_STATE_INFO	sStateInfo; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_INDIVIDUAL_RES)
WORD			wResultCode;
WORD			wJoinId;			// 참가 번호
bool			bDojoRecommender;	// 도장추천자인지?
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_LEAVE_INDIVIDUAL_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_TEAM_INFO_RES)
WORD						wResultCode;

BYTE						byMemberCount;
//sBUDOKAI_TEAM_POINT_INFO	asPointInfo[1]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_TEAM_RES)
WORD			wResultCode;
HOBJECT			hTroublePc;
float			fTotalRankPoint;
WORD			wJoinId;
WCHAR			wszTeamName[MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1];

// 
BYTE						byMemberCount;
//sBUDOKAI_TEAM_POINT_INFO	aTeamInfo[MAX_MEMBER_IN_PARTY]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_TEAM_NFY)
float			fTotalRankPoint;
WORD			wJoinId;
WCHAR			wszTeamName[MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1];

// 
BYTE						byMemberCount;
//sBUDOKAI_TEAM_POINT_INFO	aTeamInfo[MAX_MEMBER_IN_PARTY]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_LEAVE_TEAM_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_LEAVE_TEAM_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_LEAVE_TEAM_MEMBER_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_LEAVE_TEAM_MEMBER_NFY)
WCHAR			wszMemberName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_INFO_RES)
WORD					wResultCode;

BYTE					byMatchType;		// eBUDOKAI_MATCH_TYPE

											// 추후 다음 데이터 압축 필요
union
{
	//sBUDOKAI_REGISTER_INDIVIDUAL_INFO	sIndividualInfo; // TODO
	//sBUDOKAI_REGISTER_TEAM_INFO			sTeamInfo; // TODO
};
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_STATE_RES)
WORD			wResultCode;
BYTE			byMatchType;		// eBUDOKAI_MATCH_TYPE
BYTE			byJoinState;		// eBUDOKAI_JOIN_STATE
BYTE			byJoinResult;		// 참가 결과

									// 정보가 없을 경우
									// byMatchType = INVALID_BUDOKAI_MATCH_TYPE
									// byJoinState = INVALID_BUDOKAI_JOIN_STATE
									// byJoinResult = INVALID_BUDOKAI_JOIN_RESULT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_JOIN_STATE_NFY)
BYTE			byMatchType;		// eBUDOKAI_MATCH_TYPE
BYTE			byJoinState;		// eBUDOKAI_JOIN_STATE
BYTE			byJoinResult;		// eBUDOKAI_JOIN_RESULT
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DISCONNECTED_NFY)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BOT_BOTCAUTION_HELPME_NFY)
HOBJECT			hBot;
bool			bIsRequester; // true : SOS를 요청한 자
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_MUDOSA_INFO_RES)
WORD					wResultCode;
BYTE					byMudosaCount;
//sBUDOKAI_MUDOSA_INFO	aMudosaInfo[BUDOKAI_MAX_MUDOSA_INFO_COUNT]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_MUDOSA_TELEPORT_RES)
WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_PROGRESS_MESSAGE_NFY)
BYTE					byMsgId;			// eBUDOKAI_PROGRESS_MESSAGE
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_SOCIAL_ACTION_NFY)
HOBJECT				hSubject;
ANIMATIONID			socialAction;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_PRIZEWINNER_NAME_RES)
WORD				wResultCode;

// BUDOKAI_MATCH_TYPE_INDIVIDUAL
//- WCHAR		wszName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
WORD				wWinner;
WORD				wSecondWinner;

//sVARIABLE_DATA		sData; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_PRIZEWINNER_TEAM_NAME_RES)
WORD				wResultCode;

// BUDOKAI_MATCH_TYPE_TEAM
//- WCHAR		wszTeamName[MAX_LENGTH_BUDOKAI_TEAM_NAME_IN_UNICODE + 1];
WORD				wWinner;
WORD				wSecondWinner;

//sVARIABLE_DATA		sData; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_GM_BUDOKAI_SERVER_ENTER_RES)
WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_GM_BUDOKAI_SERVER_LEAVE_RES)
WORD					wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_GM_MATCH_PROGRESS_INFO_RES)
WORD								wResultCode;

BYTE								byMatchType;		// eBUDOKAI_MATCH_TYPE
BYTE								byMatchWorldType;	// eMATCHWORLD_TYPE;
BYTE								byMatchDepth;		// eBUDOKAI_MATCH_DEPTH

BYTE								byStateCount;
//sBUDOKAI_GM_MATCH_PROGRESS_STATE	aStateList[BUDOKAI_MAX_MATCH_COUNT];	// 가변 // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_GM_MATCH_ARENA_ENTER_RES)
WORD								wResultCode;

BYTE								byMatchType;		// eBUDOKAI_MATCH_TYPE
BYTE								byMatchWorldType;	// eMATCHWORLD_TYPE
BYTE								byMatchDepth;		// eBUDOKAI_MATCH_DEPTH
BYTE								byMatchIndex;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUDOKAI_GM_MATCH_ARENA_LEAVE_RES)
WORD								wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_TURN_ON_NFY)
HOBJECT			hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_TURN_OFF_NFY)
HOBJECT			hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_BROKEN_NFY)
HOBJECT			hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SCOUTER_ITEM_SELL_RES)
TBLIDX				itemTblidx;
BYTE				byPlace;
BYTE				byPos;
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_EVENTITEM_START_RES)
HOBJECT			handle;
BYTE			byType; //	0: 기본  1:한정수량 판매 이벤트 NPC 
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_EVENTITEM_BUY_RES)
HOBJECT			handle;
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_EVENTITEM_END_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_REPLACE)
HOBJECT			hDeleteItem;
HOBJECT			hCreateItem;
BYTE			byDeleteItemPlace;
BYTE			byDeleteItemPos;
sITEM_DATA      sCreateItemData;
bool			bIsNew;		// Effect 추가 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_GAMBLE_BUY_RES)
WORD			wResultCode;
HOBJECT			handle;
HOBJECT			hItem;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DUNGEON_DIFF_NFY)
ePARTY_DUNGEON_STATE eDiff;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DUNGEON_DIFF_RES)
WORD			wResultCode;
ePARTY_DUNGEON_STATE		eDiff;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DUNGEON_INIT_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_DUNGEON_INIT_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_SP)
DWORD			dwSpPoint;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_INIT_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_REMOVE_NFY)
TBLIDX			skillId;
BYTE			bySlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_REMOVE_NFY)
TBLIDX			skillId;
BYTE			bySlot;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_MARKING_NFY)
HOBJECT			handle;
sMARKING		sMarking;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_DICE_START_NFY)
DWORD			dwWaitTick;		//ms
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_DICE_ROLLED_NFY)
HOBJECT			handle;	// 해당 캐릭터 핸들
DWORD			dwRet;	// 결과값
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_DICE_ROLLED_RES)
DWORD			dwRet;	// 결과값
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_CHARM_DICE_END_NFY)
bool			bIsSuccess;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_ITEM_RANK_SET_RES)
WORD			wResultCode;
BYTE			byItemRank; // eITEM_RANK 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_ITEM_RANK_SET_NFY)
BYTE			byItemRank; // eITEM_RANK 
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_LOCK_NFY)
bool				bIsOpen;	// 1: Open 0:Close
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_LOCK_RES)
WORD				wResultCode;
bool				bIsOpen;	// 1: Open 0:Close
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_RESET_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_RESET_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_ACCEPTED_RES)
BYTE				byItemSlot;	// 파티인벤 해당 슬롯 아이템 낙찰
WORD				wResultCode;
HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_ACCEPTED_NFY)
BYTE				byItemSlot;	// 파티인벤 해당 슬롯 아이템 낙찰
HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_GIVE_RES)
WORD				wResultCode;
BYTE				byItemSlot;		// 파티인벤 해당 슬롯 아이템 
HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_GIVE_NFY)
BYTE				byItemSlot;		// 파티인벤 해당 슬롯 아이템 
HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_DICE_START_RES)
WORD				wResultCode;
BYTE				byItemSlot;		// 파티인벤 해당 슬롯 아이템	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_DICE_START_NFY)
BYTE				byItemSlot;		// 파티인벤 해당 슬롯 아이템	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_DICE_ROLL_RES)
WORD				wResultCode;
BYTE				byRet;		// 주사위결과전송	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_DICE_ROLL_NFY)
HOBJECT				handle;			// 주사위주체
BYTE				byRet;			// 주사위결과전송	
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PARTY_INVEN_DICE_END_NFY)
HOBJECT				hTarget;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TELEPORT_PROPOSAL_NFY)
BYTE				byTeleportType;
BYTE				byInfoIndex;		// 서버에서 텔레포트 정보를 참조하기위한 인덱스
WORD				wWaitTime;
TBLIDX				worldTblidx;		// 월드 테이블 인덱스 : 정보를 좀더 상세하게 출력하기 위한 용도.

union
{
	DWORD			dwReserve;
	BYTE			byBudokaiMatchDepth;	// 천하제일무도회 XX강
};

BYTE				bySummonerNameLength;
WCHAR				wszSummonnerName[MAX_SIZE_CHAR_NAME_UNICODE + 1];	// 가변
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_TELEPORT_CONFIRM_RES)
WORD				wResultCode;

BYTE				byTeleportIndex;
bool				bTeleport;			// 클라이언트에서 받은 값
bool				bClearInterface;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_PETITION_INFO)
//PETITIONID			petitionID; // TODO
//WCHAR				awchQuestionContent[MAX_SIZE_QUESTION_CONTENT_UNICODE + 1]; // TODO
//PETITIONCATEGORY	nCategory1;//ePETITIONSYSTEM_CATEGORY_1 // TODO
//PETITIONCATEGORY	nCategory2;//ePETITIONSYSTEM_CATEGORY_2 // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAME_COMMON_MSG_NFY)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_NICKNAME_CHANGED_NFY)
HOBJECT				hSubject;
TBLIDX				nicknameTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_RECIPE_REG_NFY)			// 레시피등록
TBLIDX				recipeTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_CHECK_RES)			// 만들아이템 선택 (필요한 아이템 수량 체크)
WORD				wResultCode;
HOBJECT				objHandle;
TBLIDX				recipeTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_MAKE_RES)			// 아이템 만들기
WORD				wResultCode;
BYTE				bySuccessResult;			// eITEM_MIX_RESULT_TYPE
HOBJECT				objHandle;
TBLIDX				recipeTblidx;
HOBJECT				itemHandle;
END_PROTOCOL()
//------------------------------------------------------------------			
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_MAKE_EP_RES)		// 아이템 만들기 중 EP 넣기
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------	
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_RECIPE_INFO)
BYTE				byCount;
sRECIPE_DATA		asRecipeData[ITEM_RECIPE_MAX_COUNT];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DYNAMIC_OBJECT_UPDATE_STATE)
HOBJECT				handle;
//sDYNAMIC_OBJECT_BRIEF		dynamicObjBrief; // TODO
//sDYNAMIC_OBJECT_STATE		dynamicObjState; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_MACHINE_MAKE_RES)			// 머신 필드 등록
WORD				wResultCode;
BYTE				byPlace;
BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_MACHINE_DEL_RES)			// 머신 필드 삭제
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_ITEM_MAKE_EXP_NFY)
DWORD				dwCurExp;
BYTE				byCurLevel;
bool				bIsNormal; // recipe type이 eRECIPE_NORMAL 인가 아닌가.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_TARGET_LOST_NFY)
HOBJECT						hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_GUARD_CRASHED_NFY)
HOBJECT						hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_RP_BALL)
HOBJECT			handle;
BYTE			byCurRPBall;
bool			bDropByTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_RP_BALL_MAX)
HOBJECT			handle;
BYTE			byMaxRPBall;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_JOB_SET_RES)
WORD				wResultCode;
HOBJECT				hNpchandle;
BYTE				byRecipeType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HOIPOIMIX_JOB_RESET_RES)
WORD				wResultCode;
HOBJECT				hNpchandle;
BYTE				byRecipeType;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_RP_INCREASE_START_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_RP_DECREASE_START_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_RP_INCREASE_STOP_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_HTB_LAST_STEP_CHANGED_NFY)
HOBJECT			hSubject;
BYTE			byLastStep;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_CHARGE_CANCELED_NFY)
HOBJECT			hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_REFRESH_LP_EP)
HOBJECT			hSubject;
WORD			wCurLp;
WORD			wMaxLp;
WORD			wCurEp;
WORD			wMaxEp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_NONBATTLEACTIONPATTERNSET_UNITIDX_NFY)
HOBJECT				hBotHandle;
//ACTIONPATTERN_FIELD unitIdx; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_VEHICLE_START_NFY)
HOBJECT				hDriverHandle;
Vector3				vStartPosition;
TBLIDX				idFuelItemTblidx;
HOBJECT				hVehicleItem;
TBLIDX				idVehicleItemTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_VEHICLE_ENGINE_START_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_VEHICLE_ENGINE_START_NFY)
HOBJECT				hDriverHandle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_VEHICLE_ENGINE_STOP_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_VEHICLE_ENGINE_STOP_NFY)
HOBJECT				hDriverHandle;
DWORD				dwFuelRemain;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_VEHICLE_FUEL_UPDATE_NFY)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_VEHICLE_END_NFY)
HOBJECT				hDriverHandle;
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_VEHICLE_END_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_VEHICLE_STUNT_NFY)
HOBJECT			hDriverHandle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SKILL_PASSIVE_EFFECT_APPLIED_NFY)
TBLIDX			skillTblidx;
BYTE			bySlotIndex;
sDBO_UPDATED_SKILL_DATA		sUpdatedSkillData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_AVATAR_UPDATED_SKILL_DATA_INFO)
TBLIDX			skillTblidx;
BYTE			bySlotIndex;
sDBO_UPDATED_SKILL_DATA		sUpdatedSkillData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_MONSTER_TRANSFORMED_NFY)
HOBJECT			hSubject;
TBLIDX			newTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_CREATE_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_DELETE_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_FUNCTION_ADD_RES)
WORD				wResultCode;
BYTE				byFunction;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_BANK_HISTORY_RES)
WORD				wResultCode;
DWORD				dwBalance;
BYTE				byCount;
//sDBO_DOJO_BANK_HISTORY_INFO asData[DBO_MAX_COUNT_DOJO_BANK_HISTORY]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOGI_CREATE_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOGI_CHANGE_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOGI_UPDATE_NFY)
HOBJECT				handle;
sDBO_DOGI_DATA		sData;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_DOGI_CREATE_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GUILD_DOGI_CHANGE_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHILD_ADULT_SWITCHED_NFY)
HOBJECT				hSubject;
bool				bIsAdult;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHANGE_CLASS_AUTHORITY_CHANGED_NFY)
bool				bCanChangeClass;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PLAY_BGM)
bool				bPlay;
bool				bLoop;
DWORD				dwDelay;
BYTE				byLength;
char				szName[MAX_LENGTH_CLICK_SOUND_NAME +1];		// null 을 포함해서 보낸다.
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_PLAY_SFX)
bool				bPlay;
bool				bLoop;
DWORD				dwDelay;
BYTE				byLength;
char				szName[64 + 1];		// null 을 포함해서 보낸다.
HOBJECT				originHandle;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_MARK_CHANGED_NFY)
TBLIDX				dojoTblidx;
GUILDID				guildId;
sDBO_GUILD_MARK		sMark;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_LEVEL_CHANGED_NFY)
TBLIDX				dojoTblidx;
BYTE				byLevel;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_NETP)
WORD				wResultCode;
NETP				netP;
NETP				dwBonusNetP;
NETP				dwAccumulationNetP;
DWORD				timeNextGainTime;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SCRAMBLE_RES)			// 도장쟁탈전 신청에 대한 응답 (도전자)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SCRAMBLE_RESPONSE_RES)
WORD				wResultCode;
WCHAR				wszGuildName[MAX_SIZE_GUILD_NAME_IN_UNICODE + 1];
bool				bIsRetry; // true면 다시 확인해야한다
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_NETMARBLEMEMBERIP_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUS_LOCATION_NFY)
HOBJECT				hSubject;
TBLIDX				busTblidx;
Vector2			vCurLoc;
Vector2			vCurDir;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUS_LOCATION_ERASED_NFY)
HOBJECT				hSubject;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_BUS_LOCATION_RESET_ALL_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_ITEM_EXPIRED_NFY)
HOBJECT				hItem;
BYTE				byPlace;
BYTE				byPos;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_NETPYITEM_START_RES)
BYTE			byType; //	0: 기본  1:한정수량 판매 이벤트 NPC 
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_NETPYITEM_BUY_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_SHOP_NETPYITEM_END_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_REFRESH_BATTLE_ATTRIBUTE_MODIFIER)
HOBJECT				hSubject;
float				fHonestOffenceModifier;
float				fHonestDefenceModifier;
float				fStrangeOffenceModifier;
float				fStrangeDefenceModifier;
float				fWildOffenceModifier;
float				fWildDefenceModifier;
float				fEleganceOffenceModifier;
float				fEleganceDefenceModifier;
float				fFunnyOffenceModifier;
float				fFunnyDefenceModifier;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CHAR_RANKBATTLE_ALLOW_NFY)
bool				bAllow;
WORD				wReasonCode;
END_PROTOCOL()
//------------------------------------------------------------------

BEGIN_PROTOCOL(GU_CHAR_RANKPOINT_RESET_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_NPC_INFO_RES)
WORD					wResultCode;
//sDBO_DOJO_NPC_INFO		sData; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GAMEGUARD_AUTH_ANSWER_REQ)
BYTE				byDataSize;
BYTE				abyData[UCHAR_MAX];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SEAL_ATTACK_BEGIN_NFY)
TBLIDX				sealObjectTblidx;
bool				bIsBeingStolen;
Vector2			vLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SEAL_ATTACK_END_NFY)
TBLIDX				sealObjectTblidx;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SEAL_CURRENT_STATE_NFY)
TBLIDX				sealObjectTblidx;
BYTE				byState;		// eTOBJECT_STATE_TYPE_C
Vector2			vLoc;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_INVENTORY_CAPSULE_UNLOCK_NFY)
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DOJO_SCRAMBLE_SHIFT_SEAL_STATE_NFY)
TBLIDX						dojoTblidx;
TBLIDX						objectTblidx;
GUILDID						guildId;
WCHAR						wszName[MAX_SIZE_CHAR_NAME_UNICODE + 1];
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_LP_STATUS_NFY)
HOBJECT			handle;
bool			bEmergency;	// true: Emergency false: General
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DURATION_ITEM_BUY_RES)
TBLIDX				merchantTblidx;
BYTE				byPos;
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_DURATION_RENEW_RES)
HOBJECT				hItemHandle;
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_START_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_INFO_NFY)
BYTE				byCount;
//sCASHITEM_BRIEF		aInfo[1]; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_END_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_MOVE_RES)
WORD				wResultCode;
DWORD				dwProductId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_USE_RES)
WORD				wResultCode;
DWORD				dwProductId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_HLSHOP_START_RES)
WORD				wResultCode;
DWORD				dwRemainAmount;							// 현재잔액
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_HLSHOP_END_RES)
WORD				wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_BUY_RES)
WORD			wResultCode;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GMT_INFO_NFY)
BYTE					byGMTResetCount;
sGAME_MANIA_TIME_DATA	sCurrent;
sGAME_MANIA_TIME_DATA	sNext;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GMT_UPDATE_RES)
WORD				wResultCode;
sGAME_MANIA_TIME	sNext;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_GMT_CHANGED_NFY)
sGAME_MANIA_TIME	sCurrent;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_ADD_NFY)
//sCASHITEM_BRIEF		sInfo; // TODO
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_CASHITEM_DEL_NFY)
DWORD				dwProductId;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_MAX_LP)
HOBJECT			hSubject;
WORD			wMaxLp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_MAX_EP)
HOBJECT			hSubject;
WORD			wMaxEp;
END_PROTOCOL()
//------------------------------------------------------------------
BEGIN_PROTOCOL(GU_UPDATE_CHAR_MAX_RP)
HOBJECT			hSubject;
WORD			wMaxRp;
END_PROTOCOL()
//------------------------------------------------------------------

#pragma pack(pop)

#endif /*_GAMEGU_H*/
