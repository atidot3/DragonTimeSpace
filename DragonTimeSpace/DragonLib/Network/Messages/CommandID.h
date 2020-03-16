#pragma once
#include <utils/Utils.h>

enum CommandID
{
	
	MIN_ID = 2000,
	
	MING2SCENE,
	
	MAXG2SCENE = 8000,
	
	MING2SESSION = 40001,
	
	MAXG2SESSION = 42000,
	
	MING2SUPER = 50001,
	
	MAXG2SUPER = 52000,
	
	MING2FUNCTION = 60001,
	
	MAXG2FUNCTION = 62000,
	
	MING2MAIL = 63001,
	
	MAXG2MAIL = 64000,
	
	UserVerifyVerCmd_CS = 2002,
	
	ServerReturnLoginFailedCmd_SC,
	
	IphoneLoginUserCmd_CS,
	
	CreateNewRoleUserCmd_CS,
	
	BindAccountUserCmd_CS,
	
	ReqReceiveWorldChatCmd_CSC,
	
	ReqCloseWorldChatCmd_CSC,
	
	NotifyUserKickOut_SC,
	
	AttackMagicUserCmd,
	
	BackOffMagicUserCmd,
	
	PopHpMagicUserCmd,
	
	RTMagicUserCmd,
	
	RTOtherMagicUserCmd,
	
	reflectDamage,
	
	ObtainExpUserCmd,
	
	SubExpUserCmd,
	
	SettingSkillCmd,
	
	ReturnSettingSkillCmd,
	
	SkillBookCompoundCmd,
	
	SkillBollCompoundRetCmd,
	
	SkillBookUpCmd,
	
	SkillBookUpRetCmd,
	
	TalentSkillEnableCmd,
	
	ReleaseTalentSkillCmd,
	
	MainUserDeathReliveUserCmd,
	
	OKReliveUserCmd,
	
	MainUserReliveReliveUserCmd,
	
	ReliveSuccessUserCmd,
	
	DelScreenMagicUserCmd,
	
	SetSkillCooldownUserCmd,
	
	PKModeUserCmd,
	
	ObjectHpMpPopUserCmd,
	
	RTSelectedHpMpPropertyUserCmd,
	
	SelectPropertyUserCmd,
	
	SelectReturnStatesPropertyUserCmd,
	
	SetHPAndMPDataUserCmd,
	
	CharacterMoveDest,
	
	StartGather,
	
	EndGather,
	
	ReqAddOperateList,
	
	ReturnAddOperateList,
	
	DataMapScreenInfo,
	
	NineScreenRefreshPlayer,
	
	MapScreenRefreshCharacter,
	
	MapScreenRemoveCharacter,
	
	MapScreenBatchRemoveCharacter,
	
	MapScreenMoveCharacter,
	
	MapScreenRefreshShowFunNpc,
	
	MapScreenNineScreenRefreshNpc,
	
	MapScreenBatchRemoveNpc,
	
	NpcMoveMoveUserCmd,
	
	NpcWarpMoveUserCmd,
	
	AddMapNpcMapScreenUserCmd,
	
	RemoveMapNpcMapScreenUserCmd,
	
	NpcDeathUserCmd,
	
	MagicEffectUserCmd,
	
	ReqRoleNameUserCmd,

	ResponseRoleNameUserCmd,

	SetStateMapScreenUserCmd,

	ClearStateMapScreenUserCmd,

	NPCHPMapScreenUserCmd,

	UserInitOkCmd,

	NpcASpeedRate,

	ReqPlayerLevelExpUserCmd_CS,

	RetPlayerLevelExpUserCmd_SC,

	ReqPlayerLevelExpBackCmd_CS,

	RetPlayerLevelExpBackCmd_SC,

	ReqHandleAllClientCS,

	RetHandleAllClientSC,

	TestAddRes_CS,

	RetErrorOperationUserCmd_SC,

	ReqAddAndDecUserCmd_CS,

	ReqFriendListUserCmd_CS,
	
	RetFriendListInfoUserCmd_SC,
	
	ReqFriendInfo_CS,
	
	ReqOtherRoleInfo_CS,
	
	ReqOnlineFriend_CS,
	
	ReqFriendStatus_CS,
	
	RetFriendStatus_SC,
	
	ReqFriendPowerUpdateUserCmd_CS,
	
	RetFriendPowerUpdateResult_SC,
	
	ReqGiveFriendPowerUserCmd_CS,
	
	RetGiveFriendPowerResultUserCmd_SC,
	
	ReqAcceptFriendPowerUserCmd_CS,
	
	RetAcceptFriendPowerResultUserCmd_SC,
	
	ReqBeginAddFriendUserCmd_CS,
	
	ReqBeginAddFriendResultUserCmd_SC,
	
	ReqDelFriendUserCmd_CS,
	
	RetDelFriendResultUserCmd_SC,
	
	ReqFriendStrangerListIDUserCmd_CS,
	
	ReqAttendBattleFriendUserCmd_CS,
	
	ReqSeekFriendUserCmd_CS,
	
	ReqFriendRefreshInfo_CS,
	
	RetFriendRefreshInfo_SC,
	
	RetNoUserUserCmd_SC,
	
	RetCommonError_SC,
	
	ReqAllAwardUserCmd_CS,
	
	ReqPushMessageUserCmd_CS,
	
	RetPushMessageUserCmd_SC,
	
	ReqSystemAnnouncement_CS,
	
	RetSystemAnnouncement_SC,
	
	ReqGiantCoinUserCmd_CS,
	
	RetGiantCoinUserCmd_SC,
	
	ReqGetPowerRecoverTime_CS,
	
	ReqGetPowerRecoverTime_SC,
	
	ReqTestNetwork_CS,
	
	ReqCareerSkillInfo_CS,
	
	RetCareerSkillInfo_SC,
	
	ReqRepalceSkill_CS,
	
	RetReplaceSkill_SC,
	
	ReqUpgradeExtSkill_CS,
	
	RetUpgradeExtSkill_SC,
	
	Req_ChannleChat_CS,
	
	Ret_ChannelChat_SC,
	
	Req_Chat_CS,
	
	Ret_Chat_SC,
	
	Req_CopymapEnterInfo_CS,
	
	Ret_CopymapEnterInfo_SC,
	
	Req_EnterCopymap_CS,
	
	Req_ExitCopymap_SC,
	
	Ret_TriggerEnter_SC,
	
	ReqBackCopymap_CS,
	
	Ret_CopymapOver_SC,
	
	RetAwardQuest_SC,
	
	Req_CopymapLottery_CS,
	
	Ret_CopymapLottery_SC,
	
	Req_CopymapGather_CS,
	
	Ret_CopymapGatherReq_SC,
	
	Ret_CopymapGatherData_SC,
	
	Ret_CopymapReGather_SC,
	
	Ret_CopymapBossTempID_SC,
	
	Req_AdventureCopymapGroup_CS,
	
	Ret_AdventureCopymapGroup_SC,
	
	Req_AdventureCopymapInfo_CS,
	
	Ret_AdventureCopymapInfo_SC,
	
	Req_AdventureHeros_CS,
	
	Ret_AdventureHeros_SC,
	
	Req_EnterAdventureCopymap_CS,
	
	Ret_TrainData_SC,
	
	Ret_PlayEventData_SC,
	
	Ret_CurMonsterGroup_SC,
	
	Req_IntoGuildMap_CS,
	
	Req_IntoCiTanEnemyGuild_CS,
	
	Req_CiTanBacktoMyGuild_CS,
	
	Ret_CheckDayWelfare_SC,
	
	Req_GuildGoods_CS,
	
	Ret_GuildGoods_SC,
	
	Req_SubmitGuildGoods_CS,
	
	Ret_SubmitGuildGoods_SC,
	
	Ret_QuitGuild_SC,
	
	Ret_FireGuildMember_SC,

	Ret_GuildInvite_SC,

	Ret_GuildInviteConfirm_SC,
	
	Ret_DismissGuild_SC,
	
	Ret_ChangeGuildMaster_SC,
	
	Ret_GuildViceMaster_SC,
	
	Req_GuildExtension_CS,
	
	Ret_GuildExtension_SC,
	
	Req_OneKeyApply_CS,
	
	Ret_OneKeyApply_SC,
	
	Req_RecrutCondition_CS,
	
	RetRecrutCondition_SC,
	
	Req_ModifyRecrutCondition_CS,
	
	Req_GuildTechnique_CS,
	
	Ret_GuildTechnique_SC,
	
	Req_TechniqueUpGrade_CS,
	
	Ret_TechniqueUpGrade_SC,
	
	Ret_RefreshTechniqueInfo_SC,
	
	Req_TechniqueDevelop_CS,
	
	Ret_TechniqueDevelop_SC,
	
	Req_GuildPartyActivityInfo_CS,
	
	Ret_GuildPartyActivityInfo_SC,
	
	Req_StartGuildParty_CS,
	
	Ret_GuildPartyActivityData_SC,
	
	Ret_FellowshipSurvey_SC,
	
	Req_SubmitFellowshipSurvey_CS,
	
	ReqDonateSalary_CS,
	
	ReqUserCntData_CSC,
	
	ReqSwitchHero_CS,
	
	RetSwitchHero_SC,
	
	NotifyAllHeros_SC,
	
	NotifyHeroChange_SC,
	
	ReqHeroTrain_CS,
	
	RetHeroTrain_SC,
	
	ReqLockUnlockHero_CS,
	
	RetLockUnlockHero_SC,
	
	ReqLevelupHeroSkill_CS,
	
	RetLevelupHeroSkill_SC,
	
	notifyRefreshHero_SC,
	
	ReqRiseStar_CS,
	
	RetRiseStar_SC,
	
	DnaBagInfo_CSC,
	
	DnaPageInfo_CSC,
	
	ReqPutOnDna_CS,
	
	ReqPutOffDna_CS,
	
	ReqCombineDna_CS,
	
	ReqChangeCurDnaPage_CS,
	
	ReqCombineDnaInBag_CS,
	
	ReqBuySlot_SC,
	
	ResponseSlotOpened_SC,
	
	AllDnaPageInfo_CSC,
	
	SetMainHero_CSC,
	
	Req_MagicAttack_CS,
	
	Ret_StartMagicAttack_SC,
	
	Ret_MagicAttack_SC,
	
	Ret_HpMpPop_SC,
	
	Req_SyncSkillStage_CS,
	
	Ret_SyncSkillStage_SC,
	
	Ret_InterruptSkill_SC,
	
	Ret_MainUserDeath_SC,
	
	Ret_UserDeath_SC,
	
	Req_MainUserRelive_CS,
	
	Ret_MainUserRelive_SC,
	
	Ret_SwitchPKMode_SC,
	
	RetRefreshSkill_SC,
	
	Req_OffSkill_CS,
	
	Ret_AttWarning_SC,
	
	ReqTriggerQTESkill_CS,
	
	RetTriggerQTESkill_SC,
	
	ReqDrinkBloodSkill_CS,
	
	RetDrinkBloodSkill_SC,
	
	ReqMarketItemList_CS,
	
	RetMarketItemList_SC,
	
	ReqBuyMarketItem_CS,
	
	RetBuyMarketItem_SC,
	
	UserSelledItemList_CSC,
	
	ReqBuySelledItem_CS,
	
	RetBuySelledItem_SC,
	
	ReqSellItem_CS,
	
	RetSellItem_SC,
	
	Ret_GuideHistory_SC,
	
	Ret_GuideStart_SC,
	
	Req_GuideOver_CS,
	
	Ret_GuideOver_SC,
	
	RetCurrencyChange_SC,
	
	ReqCrystalNumToday_CS,
	
	RetCrystalNumToday_SC,
	
	ReqStartAIRunning_CS,
	
	RetStartAIRunning_SC,
	
	RetUserSysSetting_SC,
	
	ReqUserSysSetting_CS,
	
	Ret_SuccessOpenGift_SC,
	
	ReqVitalityDegree_CS,
	
	RetVitalityDegree_SC,
	
	ReqGetVitalityAward_CS,
	
	RetGetVitalityAward_SC,
	
	ReqGeneRemakeInfo_CS,
	
	RetGeneRemakeInfo_SC,
	
	ReqStrengthenGene_CS,
	
	RetStrengthenGene_SC,
	
	Req_HoldonUser_CS,
	
	Ret_HoldonUser_SC,
	
	Ret_HoldonUser_Interrupt_SC,
	
	ReqMakingItem_CS,
	
	RetMakingItem_SC,
	
	Req_StruggleShape_CS,
	
	Create_Role_CS,
	
	ChangeName_CS,
	
	Ret_ChangeName_SC,
	
	DataCharacterMain_SC,
	
	Req_Use_GM_CS,
	
	Ret_Common_Error_SC,
	
	Ret_Common_Tips_SC,
	
	Req_Main_Data_CS,
	
	Req_Test_Network_CS,
	
	Ret_GameTime_SC,
	
	Req_UserGameTime_SC,
	
	Ret_UserGameTime_CS,
	
	Ret_ServerTime_SC,
	
	Ret_NotifyUserKickout_SC,
	
	Ret_ServerLoginFailed_SC,
	
	Ret_UserMapInfo_SC,
	
	Ret_NineScreenRefreshPlayer_SC,
	
	Ret_MapScreenRefreshCharacter_SC,
	
	Ret_MapScreenRemoveCharacter_SC,
	
	Ret_MapScreenBatchRemoveCharacter_SC,
	
	Ret_StateList_SC,
	
	Req_Move_CS,
	
	Ret_Move_SC,
	
	Req_TELE_PORT_CS,
	
	Server_Force_Move_SC,
	
	Ret_Move_Failed_SC,
	
	Ret_SetState_SC,
	
	Ret_ClearState_SC,
	
	Ret_MapScreenBatchRefreshNpc_SC,
	
	Ret_MapScreenBatchRemoveNpc_SC,
	
	Ret_MapScreenRefreshNpc_SC,
	
	Ret_MapScreenRemoveNpc_SC,
	
	Ret_MapScreenFuncNpc_SC,
	
	Ret_RetNpcMove_SC,
	
	RetNpcWarpMove_SC,
	
	RetNpcDir_SC,
	
	Req_Summon_Npc_CS,
	
	Ret_setTimeState_SC,
	
	Req_Ping_CS,
	
	Ret_VisibleNpcList_SC,
	
	RetNinePlayerLevelUp_SC,
	
	UpdateExpLevel_SC,
	
	NotifyAntiAddict_SC,
	
	ReqEntrySelectState_CS,
	
	RetEntrySelectState_SC,
	
	RetHpMpToSelects_SC,
	
	ReqHeroAttributeData_CS,
	
	RetHeroAttributeData_SC,
	
	RetDiffLineOfLeader_SC,
	
	ReqJumptoLeaderLine_CS,
	
	Ret_LoginOnReturnCharList_SC,
	
	Req_SelectCharToLogin_CS,
	
	Req_IS_NICKNAME_REPEATED_CSC,
	
	Req_Back_to_Select_CS,
	
	Req_Delete_Char_CSC,
	
	Req_Syn_MoveState_CS,
	
	Ret_Find_Path_SC,
	
	Ret_Rondom_Way_SC,
	
	Ret_Find_Path_End_SC,
	
	Show_Path_Way_End_CS,
	
	NoticeClientAllLines_SC,
	
	UserReqChangeLine_CS,
	
	OnUserJump_CSC,
	
	NPCHatredList_SC,
	
	ACCOUNT_SEC_PASSWD_SC,
	
	USER_REQ_SETPASSWD_CS,
	
	NEW_ROLE_CUTSCENE_SCS,
	
	NPC_Death_SC,
	
	Req_Holdon_CS,
	
	Ret_Holdon_SC,
	
	Ret_Holdon_Interrupt_SC,
	
	Ret_AddHoldNpcData_SC,
	
	Ret_BatchAddHoldNpcData_SC,
	
	Ret_RemoveHoldNpcData_SC,
	
	Ret_HoldonSuccess,
	
	ReqWatchSceneBag_CS,
	
	ReqPickObjFromSceneBag_CS,
	
	ReqPickAllSceneBag_CS,
	
	RefreshSceneBag_SC,
	
	RefreshObjs_SC,
	
	PackData_SC,
	
	WearEquip_CS,
	
	WearEquip_SC,
	
	RemoveObject_SC,
	
	UnwearEquip_CS,
	
	UnwearEquip_SC,
	
	ReqCheckItemDueTime_CS,
	
	ReqUseObject_CS,
	
	PackUnlock_CS,
	
	PackUnlock_SC,
	
	MergeObjs_CS,
	
	MergeObjs_SC,
	
	TidyPack_CS,
	
	TidyPack_SC,
	
	ReqSellObject_CS,
	
	ReqMoveObject_CS,
	
	ReqSwapObject_CS,
	
	ReqDestroyObject_CS,
	
	ReqPutOnCard_CS,
	
	ReqPutOffCard_CS,
	
	ReqSwapCard_CS,
	
	ReqCardPackInfo_CS,
	
	RetCardPackInfo_SC,
	
	ReqSplitObject_CS,
	
	ReqOpItemLock_CS,
	
	ReqSwitchPetState_CS,
	
	RetSwitchPetState_SC,
	
	RetRefreshSummonPet_SC,
	
	RetUserPetInfo_SC,
	
	NotifyPetQTESkill_SC,
	
	ReqUnlockPetNum_CS,
	
	RetUnlockPetNum_SC,
	
	Req_StartPvPMatch_CS,
	
	Ret_StartPvPMatch_SC,
	
	Req_CancelPvPMatch_CS,
	
	Ret_CancelPvPMatch_SC,
	
	Ret_PvPMatchResult_SC,
	
	Req_GotoPvPBattle_CS,
	
	ReqChoosePvPPrepared_CS,
	
	RetChoosePvPPrepared_SC,
	
	RetStartPvPPrepare_SC,
	
	RetPvPFightCountDown_SC,
	
	RetPvPFightPreFight_SC,
	
	RetStartPvPFight_SC,
	
	RetPvPSpeedupFight_SC,
	
	RetPvPFightFinish_SC,
	
	ReqPvPFightCurStage_CS,
	
	RetPvPFightCurStage_SC,
	
	RetPvPTeamCurScore_SC,
	
	RetPvPPreparedNum_SC,
	
	ReqPvPDailyAwards_CS,
	
	RetPvPDailyAwards_SC,
	
	RetPvPPKGeneralConfig_SC,
	
	RetPvPMatchFightCurLive_SC,
	
	Req_VisitNpcTrade_CS,
	
	Ret_VisitNpcTrade_SC,
	
	Req_QuestInfo_CS,
	
	Ret_QuestInfo_SC,
	
	ReqExecuteQuest_CS,
	
	ReqValidQuests_CS,
	
	RetValidQuests_SC,
	
	ReqRetQuestState_CSC,
	
	ReqAbandonQuest_CS,
	
	RetAbandonQuest_SC,
	
	ReqMapQuestInfo_CS,
	
	RetMapQuestInfo_SC,
	
	ReqCurActiveQuest_CS,
	
	RetCurActiveQuest_SC,
	
	ReqChangeMapFindPath_CS,
	
	RetChangeMapFindPath_SC,
	
	RetPlotTalkID_SC,
	
	CartoonCompleteNotify_SC,
	
	PlayCartoonAndGoMap_SC,
	
	ReqSubmitObjs_CS,
	
	RetSubmitObjs_SC,
	
	RetRingQuestRingCount_SC,
	
	notifyRefreshQuestInfo_SC,
	
	PlayBellQTE_SC,
	
	PlayBellQTEResult_CS,
	
	Req_SetQuestNeedShow_CS,
	
	Ret_SetQuestNeedShow_SC,
	
	Req_ShareQuestToTeamMember_CS,
	
	Ret_NotifyShareQuest_SC,
	
	Req_AnswerShareQuest_CS,
	
	Ret_AnswerShareQuest_SC,
	
	Ret_NotifyCountDown_SC,
	
	NotifyClientOptional_SC,
	
	Req_QuizPrivilege_CS,
	
	Ret_QuizPrivilege_SC,
	
	Req_StartQuiz_CS,
	
	Ret_QuestionsData_SC,
	
	AnswerQuestion_CS,
	
	Ret_QuestionResult_SC,
	
	Req_UseHelpItem_CS,
	
	Ret_HelpItemEffect_SC,
	
	Req_MatchMemberInfo_CS,
	
	Ret_MatchMemberInfo_SC,
	
	Req_StartMatch_CS,
	
	Ret_StartMatch_SC,
	
	Req_CancelMatch_CS,
	
	Ret_CancelMatch_SC,
	
	GoToBattle_SC,
	
	Ret_MatchResult_SC,
	
	Req_GotoBattle_CS,
	
	RetStartPrepare_SC,
	
	ReqChoosePrepared_CS,
	
	RetChoosePrepared_SC,
	
	RetFightCountDown_SC,
	
	RetStartFight_SC,
	
	RetSpeedupFight_SC,
	
	RetFightFinish_SC,
	
	ReqGetSeasonRewards_CS,
	
	RetGetSeasonRewards_SC,
	
	RetRewardsEveryday_SC,
	
	ReqRewardsEveryday_CS,
	
	RetRankPKHeroHistory_SC,
	
	RetUserRankStar_SC,
	
	RetTeamLeftMemSize_SC,
	
	ReqRankPKCurStage_CS,
	
	RetRankPKCurStage_SC,
	
	RetPreparedNum_SC,
	
	RetMemPkPrepared_SC,
	
	RetPKGeneralConfig_SC,
	
	RetTeamCurScore_SC,
	
	Req_RuneActiveData_CS,
	
	Ret_RuneActiveData_SC,
	
	Req_RunePageData_CS,
	
	Ret_RunePageData_SC,
	
	Req_ActiveRune_CS,
	
	Ret_ActiveRune_SC,
	
	Req_InsertRune_CS,
	
	Ret_InsertRune_SC,
	
	Req_UnloadRune_CS,
	
	Ret_UnloadRune_SC,
	
	Req_UnloadAllRune_CS,
	
	Ret_UnloadAllRune_SC,
	
	Req_LevelupRune_CS,
	
	Ret_LevelupRune_SC,
	
	Req_RunePageNameModify_CS,
	
	Ret_RunePageNameModify_SC,
	
	Req_RuneSwitch_CS,
	
	Ret_RuneSwitch_SC,
	
	ReqNearByUnteamedPlayer_CS,
	
	ReqNearByUnteamedPlayer_SC,
	
	AddMemember_SC,
	
	updateTeamMememberHp_SC,
	
	updateTeamMememberCareer_SC,
	
	updateTeamMemeberHero_SC,
	
	updateTeamMememberLevel_SC,
	
	updateTeamMemberFight_SC,
	
	ReqTeamMemberPos_CS,
	
	RetTeamMemberPos_SC,
	
	RetNewApply_SC,
	
	RetTeamPublicDrop_SC,
	
	ReqChooseTeamDrop_CS,
	
	RetChooseTeamDrop_SC,
	
	updateMemStateToTeam_SC,
	
	ReqLeaderMapPos_CS,
	
	RetLeaderMapPos_SC,
	
	ReqChangeMapToLeader_CS,
	
	RetChangeMapToLeader_SC,
	
	ReqLeaderAttackTarget_CS,
	
	RetLeaderAttackTarget_SC,
	
	notifyMemberLeaderIntoPublic_SC,
	
	notifyMemberOfflineHosting_SC,
	
	updateTeamMemberPrivilege_SC,
	
	Ret_checkUserTeamInfo_SC,
	
	NotifyTeamDismiss_SC,
	
	Ret_TreasurePos_SC,
	
	ReqChangeMapHuntTreasure_CS,
	
	RetChangeMapHuntTreasure_SC,
	
	User_Drop_SCS,
	
	ART_CUTSCENE_SC,
	
	ReqGetVIPCardInfo_CS,
	
	RetGetVIPCardInfo_SC,
	
	ReqBuyVIPCard_CS,
	
	RetBuyVIPCard_SC,
	
	ReqAcepVIPCardPrize_CS,
	
	RetAcepVIPCardPrize_SC,
	
	ReqRaffVIPCardPrize_CS,
	
	RetRaffVIPCardPrize_SC,
	
	ReqCurrencyExchange_CS,
	
	RetCurrencyExchange_SC,
	
	UserLoadingOk_CS,
	
	RetQueryBalance_SC,
	
	RetRecharge_SC,
	
	ExchangeRatio_CSC,
	
	Ret_MapScreenRemoveCharacterShowCorpse_SC,
	
	Req_OperateClientDataNew_CS,
	
	Req_OperateClientDataNew_CSC,
	
	SetChooseTarget_CS,
	
	AttackTargetCharge_SC,
	
	RetUserAvatars_SC,
	
	AttackTargetChange_SC,
	
	ReqEquipAvatar_CS,
	
	NotifyClientHeroScore_SC,
	
	notifyQuestStateEffect_SC,
	
	RetUserEvolution_SC,
	
	ReqTransMoney_CS,
	
	ReqUserEvolution_CS,
	
	NotifyAccountReuse,
	
	RefreshMarketItem_SC,
	
	Req_GuildPkEnroll_CS,
	
	Req_PlayGameData_CS,
	
	Req_PlayGameRetry_CS,
	
	RealTime_GuildPkTeam_Rank_SC,
	
	Req_EnterGuildPk_CS,
	
	Ret_GuildPkCountDown_SC,
	
	Ret_GuildPkFight_SC,
	
	GuildPk_FinalResult_SC,
	
	ReqUseObject_Special_CS,
	
	Req_CommitYQDData_CS,
	
	Req_PlayYQDRetry_CS,
	
	Notify_SceneLoaded_CS,
	
	ReqFixUpDurability_CS,
	
	retEnterBattle_SC,
	
	RetHoldFlagTeamScore_SC,
	
	ReqHoldFlagReport_CS,
	
	RetHoldFlagReport_SC,
	
	RetHoldFlagDBState_SC,
	
	RetHoldFlagAccount_SC,
	
	ReqHoldFlagCaptureDB_CS,
	
	ReqHoldFlagPutDownDB_CS,
	
	RetHoldFlagCountDown_SC,
	
	NoneChantSkill_SC,
	
	Ret_GuildPkEnroll_Finish_SC,
	
	Ret_BeFiredGuildMember_SC,
	
	RetHoldFlagEvent_SC,
	
	ReqUpdateAntiAddict_CS,
	
	ReqBattleTimes_CS,
	
	RetBattleTimes_SC,
	
	Ret_Day7ActivityInfo_SC,
	
	Req_RecvDay7ActivityPrize_CS,
	
	Ret_SeekActivityInfo_SC,
	
	Req_RecvSeekActivityPrize_CS,
	
	Req_SeekActivityInfo_CS,
	
	Ret_UserSkillRelive_SC,
	
	updateTeamMemberAvatar_SC,
	
	MatchInfo_SC,
	
	DismissGroup_SC,
	
	MyTeamInfo_SC,
	
	RefreshPowerRank_SC,
	
	RefreshRadarPos_SC,
	
	artPray_SC,
	
	ServerTimer_SC,
	
	RefreshRadarPos_CSC,
	
	SelectHopes_CS,
	
	BstUserTeamInfo_SC,
	
	ReqUseCapsule_CS,
	
	UseSpecialCapsule_CS,
	
	GameOver_SC,
	
	UserGetAwardReq_CS,
	
	RewardBagInfo_SC,
	
	MobaLevelUp_SC,
	
	ClientEffect_SC,
	
	Req_DivorceStuck_CS,
	
	Ret_QueueInfo_SC,
	
	Req_Survey_Info_CS,
	
	Ret_Survey_Info_SC,
	
	Req_GetSurveyReward_CS,
	
	Ret_GetSurveyReward_SC,
	
	Upload_Crash_Info,
	
	Req_GuideStart_CS,
	
	Ret_Wegame_Fcm_Info,
	
	Ret_Test1 = 40002,
	
	Ret_Test2,
	
	Ret_Test3 = 50002,
	
	Ret_Test4,
	
	Req_MasterApprenticeInfo_CS = 60002,
	
	Ret_MasterApprenticeInfo_SC,
	
	Req_ApprenticeList_CS,
	
	Ret_ApprenticeList_SC,
	
	Req_MasterApprenticeCount_CS,
	
	Ret_MasterApprenticeCount_SC,
	
	Req_TakeMaster_CS,
	
	Ret_ApplyTakeMaster_SC,
	
	Req_AnswerTakeMaster_CS,
	
	Ret_TakeMaster_SC,
	
	Req_TakeApprentice_CS,
	
	Ret_ApplyTakeApprentice_SC,
	
	Req_AnswerTakeApprentice_CS,
	
	Ret_TakeApprentice_SC,
	
	Req_StartTakeApprentice_CS,
	
	Ret_StartTakeApprentice_SC,
	
	Req_StartTakeMaster_CS,
	
	Ret_StartTakeMaster_SC,
	
	Req_unpublishTakeMaster_CS,
	
	Ret_unpublishTakeMaster_SC,
	
	Req_SearchMaster_CS,
	
	Ret_SearchMaster_SC,
	
	Req_SearchApprentice_CS,
	
	Ret_SearchApprentice_SC,
	
	Req_UserApprenticeInfo_CS,
	
	Ret_UserApprenticeInfo_SC,
	
	Req_preQuitApprentice_CS,
	
	Ret_preQuitApprentice_SC,
	
	Req_applyQuitApprentice_CS,
	
	Ret_applyQuitApprentice_SC,
	
	Req_unQuitApprentice_CS,
	
	Ret_unQuitApprentice_SC,
	
	Req_FinishApprentice_CS,
	
	Ret_FinishApprentice_SC,
	
	Ret_ApprenticeChange_SC,
	
	Req_OperateClientDatas_CS,
	
	Req_ChatUserInfo_CS,
	
	Ret_ChatUserInfo_SC,
	
	Req_OfflineChat_CS,
	
	Ret_OfflineChat_SC,
	
	Req_CopymapAnswerGather_CS,
	
	Req_CopymapGatherQuickEnter_CS,
	
	Req_CopymapReGather_CS,
	
	Req_JoinCountry_CS,
	
	Ret_JoinCountry_SC,
	
	Req_PreCreateGuild_CS,
	
	Ret_PreCreateGuild_SC,
	
	Req_CreateGuild_CS,
	
	Ret_CreateGuild_SC,
	
	Req_SetGuildNotify_CS,
	
	Ret_SetGuildNotify_SC,
	
	Req_GuildInfo_CS,
	
	Ret_GuildInfo_SC,
	
	Req_GuildList_CS,
	
	Ret_GuildList_SC,
	
	Req_ApplyForGuild_CS,
	
	Ret_ApplyForGuild_SC,
	
	Req_AnswerApplyForGuild_CS,
	
	Ret_AnswerApplyForGuild_SC,
	
	Req_GuildMemberList_CS,
	
	Ret_GuildMemberList_SC,
	
	Req_CiTanEnemyGuildList_CS,
	
	Ret_CiTanEnemyGuildList_SC,
	
	Req_ChooseCiTanEnemyGuild_CS,
	
	Req_TargetCiTanEnemyGuild_CS,
	
	Ret_ChoosedCiTanEnemyGuild_SC,
	
	Req_AddGuildPosition_CS,
	
	Req_DeleteGuildPosition_CS,
	
	Req_SwapGuildPosOrder_CS,
	
	Req_ChangePositionName_CS,
	
	Req_ChangePositionPri_CS,
	
	Req_AssignPosition_CS,
	
	Ret_AssignPosition_SC,
	
	Ret_PositionInfo_SC,
	
	Req_GuildLevelup_CS,
	
	Ret_GuildLevelup_SC,
	
	Req_GuildSetInfo_CS,
	
	Ret_GuildSetInfo_SC,
	
	Req_GetDayWelfare_CS,
	
	Ret_GetDayWelfare_SC,
	
	Req_QuitGuild_CS,
	
	Req_FireGuildMember_CS,
	
	Req_GuildInvite_CS,
	
	Req_GuildInviteConfirm_CS,
	
	Req_DismissGuild_CS,
	
	Req_ChangeGuildMaster_CS,
	
	Req_GuildViceMaster_CS,
	
	RankPkReqPrepare_CS,
	
	RankPkReqPrepare_SC,
	
	Ret_RelationList_SC,
	
	Ret_RefreshRelation_SC,
	
	Req_ApplyRelation_CS,
	
	Req_AnswerApplyRelation_CS,
	
	Ret_AnswerApplyRelation_SC,
	
	Req_DeleteRelation_CS,
	
	Ret_DeleteRelation_SC,
	
	Req_OfflineInteractive_CS,
	
	Ret_AddInteractive_SC,
	
	Req_SearchRelation_CS,
	
	Ret_SearchRelation_SC,
	
	ModifyPageName_CSC,
	
	MoveFriendToPage_CSC,
	
	AllFriendPage_CSC,
	
	BlackList_CSC,
	
	OperateBlackList_CSC,
	
	ChangeNickName_CSC,
	
	CreateTeam_CS,
	
	TeamMemeberList_CS,
	
	TeamMemeberList_SC,
	
	Team_List_CS,
	
	Team_List_SC,
	
	Join_Team_CS,
	
	Join_Team_SC,
	
	ReqJoinTeamNotifyLeader_SC,
	
	AnswerJoinTeam_CS,
	
	AnswerJoinTeam_SC,
	
	ReqApplyList_CS,
	
	ReqApplyList_SC,
	
	ReqDelMemember_CS,
	
	ReqDelMemember_SC,
	
	ReqLanchVoteOut_CS,
	
	ReqLanchVoteOut_SC,
	
	ReqVote_CS,
	
	ReqChangeLeader_CS,
	
	ReqChangeLeader_SC,
	
	InviteIntoTeam_CS,
	
	InviteIntoTeam_SC,
	
	AnswerInviteTeam_CS,
	
	LeaderIgnoreNotice_CS,
	
	RetNearByUnteamedInvite_SC,
	
	ReqSearchTeam_CS,
	
	ReqSearchTeamByPage_CS,
	
	RetSearchTeam_SC,
	
	ReqChangeActivityTarget_CS,
	
	RetChangeActivityTarget_SC,
	
	ReqMatch_CS,
	
	RetMatch_SC,
	
	ReqUnmatch_CS,
	
	RetUnmatch_SC,
	
	RetNotifyMatchSuccess_SC,
	
	ReqMemberBackTeam_CS,
	
	RetMemberBackTeam_SC,
	
	Req_SetMemberPrivilege_CS,
	
	Req_checkUserTeamInfo_CS,
	
	Req_DismissTeam_CS,
	
	ReqQueryBalance_CS,
	
	ReqRecharge_CS,
	
	Ret_MyGuildApply_Result_SC,
	
	Ret_GuildPkEnroll_SC = 60151,
	
	Ret_GuildPkInfo_SC,
	
	Req_GuildPkInfo_CS,
	
	Req_GuildPkJoinTeam_CS,
	
	Req_GuildPkQuitTeam_CS,
	
	Req_GuildPkRank_CS,
	
	Ret_GuildPkRank_SC,
	
	Req_GuildPkWinList_CS,
	
	Ret_GuildPkWinList_SC,
	
	Req_GuildSkill_CS,
	
	Ret_GuildSkill_SC,
	
	Req_LearnGuildSkill_CSC,
	
	ReqRankPKList_CS,
	
	RetRankPKList_SC,
	
	Refresh_GuildPkMemberInfo_SC,
	
	Ret_GuildPkMatchResult_SC,
	
	ReqBattleMatch_CS,
	
	ReqBattleMatch_SC,
	
	ReqBattleCancelMatch_CS,
	
	ReqBattleCancelMatch_SC,
	
	RetMatchMember_SC,
	
	RetBattleValid_SC,
	
	ReqEnterBattle_CS,
	
	ReqChangeGroupLeader_CS,
	
	UserMatchReq_CS,
	
	MatchReady_CS,
	
	Req_ImportantBroadcast_CS,
	
	Req_MailList_CS = 63002,
	
	Ret_MailList_SC,
	
	Ret_RefreshMail_SC,
	
	Ret_RefreshMailState_SC,
	
	Req_OpenMail_CS,
	
	Req_GetAttachment_CS,
	
	Ret_GetAttachment_SC,
	
	Req_GetAllAttachment_CS,
	
	Req_DeleteMail_CS,
	
	Ret_DeleteMail_SC,
	
	Req_DeleteAllMail_CS,
	
	ReqSellStaff_CS,
	
	RetSellStaff_SC,
	
	ReqSellingStaff_CS,
	
	RetSellingStaff_SC,
	
	ReqRecommandPrice_CS,
	
	RetRecommandPrice_SC,
	
	ReqStopSellStaff_CS,
	
	RetStopSellStaff_SC,
	
	ReqSubSellingList_CS,
	
	RetSubSellingList_SC,
	
	ReqBuyItem_CS,
	
	RetBuyItem_SC,
	
	ReqTradeItemHistory_CS,
	
	RetTradeItemHistory_SC,
	
	ReqSublistPage_CS,
	
	RetSublistPage_SC,
	
	ReqWatchTradeItem_CS,
	
	RetWatchTradeItem_SC,
	
	ReqWatchList_CS,
	
	RetWatchList_SC,
	
	ReqUserTradeHistory_CS,
	
	RetUserTradeHistory_SC,
	
	ReqGetNewestStaff_CS,
	
	RetGetNewestStaff_SC = 63035,
	
	MAX_ID
};
static bool packetsLoaded = false;

std::string GetPacketName(unsigned short wOpCode);
void InitPacketNames();
