#pragma once

// Token: 0x02000CBF RID: 3263
enum CommandID
{
	// Token: 0x04003FEF RID: 16367
	MIN_ID = 2000,
	// Token: 0x04003FF0 RID: 16368
	MING2SCENE,
	// Token: 0x04003FF1 RID: 16369
	MAXG2SCENE = 8000,
	// Token: 0x04003FF2 RID: 16370
	MING2SESSION = 40001,
	// Token: 0x04003FF3 RID: 16371
	MAXG2SESSION = 42000,
	// Token: 0x04003FF4 RID: 16372
	MING2SUPER = 50001,
	// Token: 0x04003FF5 RID: 16373
	MAXG2SUPER = 52000,
	// Token: 0x04003FF6 RID: 16374
	MING2FUNCTION = 60001,
	// Token: 0x04003FF7 RID: 16375
	MAXG2FUNCTION = 62000,
	// Token: 0x04003FF8 RID: 16376
	MING2MAIL = 63001,
	// Token: 0x04003FF9 RID: 16377
	MAXG2MAIL = 64000,
	// Token: 0x04003FFA RID: 16378
	UserVerifyVerCmd_CS = 2002,
	// Token: 0x04003FFB RID: 16379
	ServerReturnLoginFailedCmd_SC,
	// Token: 0x04003FFC RID: 16380
	IphoneLoginUserCmd_CS,
	// Token: 0x04003FFD RID: 16381
	CreateNewRoleUserCmd_CS,
	// Token: 0x04003FFE RID: 16382
	BindAccountUserCmd_CS,
	// Token: 0x04003FFF RID: 16383
	ReqReceiveWorldChatCmd_CSC,
	// Token: 0x04004000 RID: 16384
	ReqCloseWorldChatCmd_CSC,
	// Token: 0x04004001 RID: 16385
	NotifyUserKickOut_SC,
	// Token: 0x04004002 RID: 16386
	AttackMagicUserCmd,
	// Token: 0x04004003 RID: 16387
	BackOffMagicUserCmd,
	// Token: 0x04004004 RID: 16388
	PopHpMagicUserCmd,
	// Token: 0x04004005 RID: 16389
	RTMagicUserCmd,
	// Token: 0x04004006 RID: 16390
	RTOtherMagicUserCmd,
	// Token: 0x04004007 RID: 16391
	reflectDamage,
	// Token: 0x04004008 RID: 16392
	ObtainExpUserCmd,
	// Token: 0x04004009 RID: 16393
	SubExpUserCmd,
	// Token: 0x0400400A RID: 16394
	SettingSkillCmd,
	// Token: 0x0400400B RID: 16395
	ReturnSettingSkillCmd,
	// Token: 0x0400400C RID: 16396
	SkillBookCompoundCmd,
	// Token: 0x0400400D RID: 16397
	SkillBollCompoundRetCmd,
	// Token: 0x0400400E RID: 16398
	SkillBookUpCmd,
	// Token: 0x0400400F RID: 16399
	SkillBookUpRetCmd,
	// Token: 0x04004010 RID: 16400
	TalentSkillEnableCmd,
	// Token: 0x04004011 RID: 16401
	ReleaseTalentSkillCmd,
	// Token: 0x04004012 RID: 16402
	MainUserDeathReliveUserCmd,
	// Token: 0x04004013 RID: 16403
	OKReliveUserCmd,
	// Token: 0x04004014 RID: 16404
	MainUserReliveReliveUserCmd,
	// Token: 0x04004015 RID: 16405
	ReliveSuccessUserCmd,
	// Token: 0x04004016 RID: 16406
	DelScreenMagicUserCmd,
	// Token: 0x04004017 RID: 16407
	SetSkillCooldownUserCmd,
	// Token: 0x04004018 RID: 16408
	PKModeUserCmd,
	// Token: 0x04004019 RID: 16409
	ObjectHpMpPopUserCmd,
	// Token: 0x0400401A RID: 16410
	RTSelectedHpMpPropertyUserCmd,
	// Token: 0x0400401B RID: 16411
	SelectPropertyUserCmd,
	// Token: 0x0400401C RID: 16412
	SelectReturnStatesPropertyUserCmd,
	// Token: 0x0400401D RID: 16413
	SetHPAndMPDataUserCmd,
	// Token: 0x0400401E RID: 16414
	CharacterMoveDest,
	// Token: 0x0400401F RID: 16415
	StartGather,
	// Token: 0x04004020 RID: 16416
	EndGather,
	// Token: 0x04004021 RID: 16417
	ReqAddOperateList,
	// Token: 0x04004022 RID: 16418
	ReturnAddOperateList,
	// Token: 0x04004023 RID: 16419
	DataMapScreenInfo,
	// Token: 0x04004024 RID: 16420
	NineScreenRefreshPlayer,
	// Token: 0x04004025 RID: 16421
	MapScreenRefreshCharacter,
	// Token: 0x04004026 RID: 16422
	MapScreenRemoveCharacter,
	// Token: 0x04004027 RID: 16423
	MapScreenBatchRemoveCharacter,
	// Token: 0x04004028 RID: 16424
	MapScreenMoveCharacter,
	// Token: 0x04004029 RID: 16425
	MapScreenRefreshShowFunNpc,
	// Token: 0x0400402A RID: 16426
	MapScreenNineScreenRefreshNpc,
	// Token: 0x0400402B RID: 16427
	MapScreenBatchRemoveNpc,
	// Token: 0x0400402C RID: 16428
	NpcMoveMoveUserCmd,
	// Token: 0x0400402D RID: 16429
	NpcWarpMoveUserCmd,
	// Token: 0x0400402E RID: 16430
	AddMapNpcMapScreenUserCmd,
	// Token: 0x0400402F RID: 16431
	RemoveMapNpcMapScreenUserCmd,
	// Token: 0x04004030 RID: 16432
	NpcDeathUserCmd,
	// Token: 0x04004031 RID: 16433
	MagicEffectUserCmd,
	// Token: 0x04004032 RID: 16434
	ReqRoleNameUserCmd,
	// Token: 0x04004033 RID: 16435
	ResponseRoleNameUserCmd,
	// Token: 0x04004034 RID: 16436
	SetStateMapScreenUserCmd,
	// Token: 0x04004035 RID: 16437
	ClearStateMapScreenUserCmd,
	// Token: 0x04004036 RID: 16438
	NPCHPMapScreenUserCmd,
	// Token: 0x04004037 RID: 16439
	UserInitOkCmd,
	// Token: 0x04004038 RID: 16440
	NpcASpeedRate,
	// Token: 0x04004039 RID: 16441
	ReqPlayerLevelExpUserCmd_CS,
	// Token: 0x0400403A RID: 16442
	RetPlayerLevelExpUserCmd_SC,
	// Token: 0x0400403B RID: 16443
	ReqPlayerLevelExpBackCmd_CS,
	// Token: 0x0400403C RID: 16444
	RetPlayerLevelExpBackCmd_SC,
	// Token: 0x0400403D RID: 16445
	ReqHandleAllClientCS,
	// Token: 0x0400403E RID: 16446
	RetHandleAllClientSC,
	// Token: 0x0400403F RID: 16447
	TestAddRes_CS,
	// Token: 0x04004040 RID: 16448
	RetErrorOperationUserCmd_SC,
	// Token: 0x04004041 RID: 16449
	ReqAddAndDecUserCmd_CS,
	// Token: 0x04004042 RID: 16450
	ReqFriendListUserCmd_CS,
	// Token: 0x04004043 RID: 16451
	RetFriendListInfoUserCmd_SC,
	// Token: 0x04004044 RID: 16452
	ReqFriendInfo_CS,
	// Token: 0x04004045 RID: 16453
	ReqOtherRoleInfo_CS,
	// Token: 0x04004046 RID: 16454
	ReqOnlineFriend_CS,
	// Token: 0x04004047 RID: 16455
	ReqFriendStatus_CS,
	// Token: 0x04004048 RID: 16456
	RetFriendStatus_SC,
	// Token: 0x04004049 RID: 16457
	ReqFriendPowerUpdateUserCmd_CS,
	// Token: 0x0400404A RID: 16458
	RetFriendPowerUpdateResult_SC,
	// Token: 0x0400404B RID: 16459
	ReqGiveFriendPowerUserCmd_CS,
	// Token: 0x0400404C RID: 16460
	RetGiveFriendPowerResultUserCmd_SC,
	// Token: 0x0400404D RID: 16461
	ReqAcceptFriendPowerUserCmd_CS,
	// Token: 0x0400404E RID: 16462
	RetAcceptFriendPowerResultUserCmd_SC,
	// Token: 0x0400404F RID: 16463
	ReqBeginAddFriendUserCmd_CS,
	// Token: 0x04004050 RID: 16464
	ReqBeginAddFriendResultUserCmd_SC,
	// Token: 0x04004051 RID: 16465
	ReqDelFriendUserCmd_CS,
	// Token: 0x04004052 RID: 16466
	RetDelFriendResultUserCmd_SC,
	// Token: 0x04004053 RID: 16467
	ReqFriendStrangerListIDUserCmd_CS,
	// Token: 0x04004054 RID: 16468
	ReqAttendBattleFriendUserCmd_CS,
	// Token: 0x04004055 RID: 16469
	ReqSeekFriendUserCmd_CS,
	// Token: 0x04004056 RID: 16470
	ReqFriendRefreshInfo_CS,
	// Token: 0x04004057 RID: 16471
	RetFriendRefreshInfo_SC,
	// Token: 0x04004058 RID: 16472
	RetNoUserUserCmd_SC,
	// Token: 0x04004059 RID: 16473
	RetCommonError_SC,
	// Token: 0x0400405A RID: 16474
	ReqAllAwardUserCmd_CS,
	// Token: 0x0400405B RID: 16475
	ReqPushMessageUserCmd_CS,
	// Token: 0x0400405C RID: 16476
	RetPushMessageUserCmd_SC,
	// Token: 0x0400405D RID: 16477
	ReqSystemAnnouncement_CS,
	// Token: 0x0400405E RID: 16478
	RetSystemAnnouncement_SC,
	// Token: 0x0400405F RID: 16479
	ReqGiantCoinUserCmd_CS,
	// Token: 0x04004060 RID: 16480
	RetGiantCoinUserCmd_SC,
	// Token: 0x04004061 RID: 16481
	ReqGetPowerRecoverTime_CS,
	// Token: 0x04004062 RID: 16482
	ReqGetPowerRecoverTime_SC,
	// Token: 0x04004063 RID: 16483
	ReqTestNetwork_CS,
	// Token: 0x04004064 RID: 16484
	ReqCareerSkillInfo_CS,
	// Token: 0x04004065 RID: 16485
	RetCareerSkillInfo_SC,
	// Token: 0x04004066 RID: 16486
	ReqRepalceSkill_CS,
	// Token: 0x04004067 RID: 16487
	RetReplaceSkill_SC,
	// Token: 0x04004068 RID: 16488
	ReqUpgradeExtSkill_CS,
	// Token: 0x04004069 RID: 16489
	RetUpgradeExtSkill_SC,
	// Token: 0x0400406A RID: 16490
	Req_ChannleChat_CS,
	// Token: 0x0400406B RID: 16491
	Ret_ChannelChat_SC,
	// Token: 0x0400406C RID: 16492
	Req_Chat_CS,
	// Token: 0x0400406D RID: 16493
	Ret_Chat_SC,
	// Token: 0x0400406E RID: 16494
	Req_CopymapEnterInfo_CS,
	// Token: 0x0400406F RID: 16495
	Ret_CopymapEnterInfo_SC,
	// Token: 0x04004070 RID: 16496
	Req_EnterCopymap_CS,
	// Token: 0x04004071 RID: 16497
	Req_ExitCopymap_SC,
	// Token: 0x04004072 RID: 16498
	Ret_TriggerEnter_SC,
	// Token: 0x04004073 RID: 16499
	ReqBackCopymap_CS,
	// Token: 0x04004074 RID: 16500
	Ret_CopymapOver_SC,
	// Token: 0x04004075 RID: 16501
	RetAwardQuest_SC,
	// Token: 0x04004076 RID: 16502
	Req_CopymapLottery_CS,
	// Token: 0x04004077 RID: 16503
	Ret_CopymapLottery_SC,
	// Token: 0x04004078 RID: 16504
	Req_CopymapGather_CS,
	// Token: 0x04004079 RID: 16505
	Ret_CopymapGatherReq_SC,
	// Token: 0x0400407A RID: 16506
	Ret_CopymapGatherData_SC,
	// Token: 0x0400407B RID: 16507
	Ret_CopymapReGather_SC,
	// Token: 0x0400407C RID: 16508
	Ret_CopymapBossTempID_SC,
	// Token: 0x0400407D RID: 16509
	Req_AdventureCopymapGroup_CS,
	// Token: 0x0400407E RID: 16510
	Ret_AdventureCopymapGroup_SC,
	// Token: 0x0400407F RID: 16511
	Req_AdventureCopymapInfo_CS,
	// Token: 0x04004080 RID: 16512
	Ret_AdventureCopymapInfo_SC,
	// Token: 0x04004081 RID: 16513
	Req_AdventureHeros_CS,
	// Token: 0x04004082 RID: 16514
	Ret_AdventureHeros_SC,
	// Token: 0x04004083 RID: 16515
	Req_EnterAdventureCopymap_CS,
	// Token: 0x04004084 RID: 16516
	Ret_TrainData_SC,
	// Token: 0x04004085 RID: 16517
	Ret_PlayEventData_SC,
	// Token: 0x04004086 RID: 16518
	Ret_CurMonsterGroup_SC,
	// Token: 0x04004087 RID: 16519
	Req_IntoGuildMap_CS,
	// Token: 0x04004088 RID: 16520
	Req_IntoCiTanEnemyGuild_CS,
	// Token: 0x04004089 RID: 16521
	Req_CiTanBacktoMyGuild_CS,
	// Token: 0x0400408A RID: 16522
	Ret_CheckDayWelfare_SC,
	// Token: 0x0400408B RID: 16523
	Req_GuildGoods_CS,
	// Token: 0x0400408C RID: 16524
	Ret_GuildGoods_SC,
	// Token: 0x0400408D RID: 16525
	Req_SubmitGuildGoods_CS,
	// Token: 0x0400408E RID: 16526
	Ret_SubmitGuildGoods_SC,
	// Token: 0x0400408F RID: 16527
	Ret_QuitGuild_SC,
	// Token: 0x04004090 RID: 16528
	Ret_FireGuildMember_SC,
	// Token: 0x04004091 RID: 16529
	Ret_GuildInvite_SC,
	// Token: 0x04004092 RID: 16530
	Ret_GuildInviteConfirm_SC,
	// Token: 0x04004093 RID: 16531
	Ret_DismissGuild_SC,
	// Token: 0x04004094 RID: 16532
	Ret_ChangeGuildMaster_SC,
	// Token: 0x04004095 RID: 16533
	Ret_GuildViceMaster_SC,
	// Token: 0x04004096 RID: 16534
	Req_GuildExtension_CS,
	// Token: 0x04004097 RID: 16535
	Ret_GuildExtension_SC,
	// Token: 0x04004098 RID: 16536
	Req_OneKeyApply_CS,
	// Token: 0x04004099 RID: 16537
	Ret_OneKeyApply_SC,
	// Token: 0x0400409A RID: 16538
	Req_RecrutCondition_CS,
	// Token: 0x0400409B RID: 16539
	RetRecrutCondition_SC,
	// Token: 0x0400409C RID: 16540
	Req_ModifyRecrutCondition_CS,
	// Token: 0x0400409D RID: 16541
	Req_GuildTechnique_CS,
	// Token: 0x0400409E RID: 16542
	Ret_GuildTechnique_SC,
	// Token: 0x0400409F RID: 16543
	Req_TechniqueUpGrade_CS,
	// Token: 0x040040A0 RID: 16544
	Ret_TechniqueUpGrade_SC,
	// Token: 0x040040A1 RID: 16545
	Ret_RefreshTechniqueInfo_SC,
	// Token: 0x040040A2 RID: 16546
	Req_TechniqueDevelop_CS,
	// Token: 0x040040A3 RID: 16547
	Ret_TechniqueDevelop_SC,
	// Token: 0x040040A4 RID: 16548
	Req_GuildPartyActivityInfo_CS,
	// Token: 0x040040A5 RID: 16549
	Ret_GuildPartyActivityInfo_SC,
	// Token: 0x040040A6 RID: 16550
	Req_StartGuildParty_CS,
	// Token: 0x040040A7 RID: 16551
	Ret_GuildPartyActivityData_SC,
	// Token: 0x040040A8 RID: 16552
	Ret_FellowshipSurvey_SC,
	// Token: 0x040040A9 RID: 16553
	Req_SubmitFellowshipSurvey_CS,
	// Token: 0x040040AA RID: 16554
	ReqDonateSalary_CS,
	// Token: 0x040040AB RID: 16555
	ReqUserCntData_CSC,
	// Token: 0x040040AC RID: 16556
	ReqSwitchHero_CS,
	// Token: 0x040040AD RID: 16557
	RetSwitchHero_SC,
	// Token: 0x040040AE RID: 16558
	NotifyAllHeros_SC,
	// Token: 0x040040AF RID: 16559
	NotifyHeroChange_SC,
	// Token: 0x040040B0 RID: 16560
	ReqHeroTrain_CS,
	// Token: 0x040040B1 RID: 16561
	RetHeroTrain_SC,
	// Token: 0x040040B2 RID: 16562
	ReqLockUnlockHero_CS,
	// Token: 0x040040B3 RID: 16563
	RetLockUnlockHero_SC,
	// Token: 0x040040B4 RID: 16564
	ReqLevelupHeroSkill_CS,
	// Token: 0x040040B5 RID: 16565
	RetLevelupHeroSkill_SC,
	// Token: 0x040040B6 RID: 16566
	notifyRefreshHero_SC,
	// Token: 0x040040B7 RID: 16567
	ReqRiseStar_CS,
	// Token: 0x040040B8 RID: 16568
	RetRiseStar_SC,
	// Token: 0x040040B9 RID: 16569
	DnaBagInfo_CSC,
	// Token: 0x040040BA RID: 16570
	DnaPageInfo_CSC,
	// Token: 0x040040BB RID: 16571
	ReqPutOnDna_CS,
	// Token: 0x040040BC RID: 16572
	ReqPutOffDna_CS,
	// Token: 0x040040BD RID: 16573
	ReqCombineDna_CS,
	// Token: 0x040040BE RID: 16574
	ReqChangeCurDnaPage_CS,
	// Token: 0x040040BF RID: 16575
	ReqCombineDnaInBag_CS,
	// Token: 0x040040C0 RID: 16576
	ReqBuySlot_SC,
	// Token: 0x040040C1 RID: 16577
	ResponseSlotOpened_SC,
	// Token: 0x040040C2 RID: 16578
	AllDnaPageInfo_CSC,
	// Token: 0x040040C3 RID: 16579
	SetMainHero_CSC,
	// Token: 0x040040C4 RID: 16580
	Req_MagicAttack_CS,
	// Token: 0x040040C5 RID: 16581
	Ret_StartMagicAttack_SC,
	// Token: 0x040040C6 RID: 16582
	Ret_MagicAttack_SC,
	// Token: 0x040040C7 RID: 16583
	Ret_HpMpPop_SC,
	// Token: 0x040040C8 RID: 16584
	Req_SyncSkillStage_CS,
	// Token: 0x040040C9 RID: 16585
	Ret_SyncSkillStage_SC,
	// Token: 0x040040CA RID: 16586
	Ret_InterruptSkill_SC,
	// Token: 0x040040CB RID: 16587
	Ret_MainUserDeath_SC,
	// Token: 0x040040CC RID: 16588
	Ret_UserDeath_SC,
	// Token: 0x040040CD RID: 16589
	Req_MainUserRelive_CS,
	// Token: 0x040040CE RID: 16590
	Ret_MainUserRelive_SC,
	// Token: 0x040040CF RID: 16591
	Ret_SwitchPKMode_SC,
	// Token: 0x040040D0 RID: 16592
	RetRefreshSkill_SC,
	// Token: 0x040040D1 RID: 16593
	Req_OffSkill_CS,
	// Token: 0x040040D2 RID: 16594
	Ret_AttWarning_SC,
	// Token: 0x040040D3 RID: 16595
	ReqTriggerQTESkill_CS,
	// Token: 0x040040D4 RID: 16596
	RetTriggerQTESkill_SC,
	// Token: 0x040040D5 RID: 16597
	ReqDrinkBloodSkill_CS,
	// Token: 0x040040D6 RID: 16598
	RetDrinkBloodSkill_SC,
	// Token: 0x040040D7 RID: 16599
	ReqMarketItemList_CS,
	// Token: 0x040040D8 RID: 16600
	RetMarketItemList_SC,
	// Token: 0x040040D9 RID: 16601
	ReqBuyMarketItem_CS,
	// Token: 0x040040DA RID: 16602
	RetBuyMarketItem_SC,
	// Token: 0x040040DB RID: 16603
	UserSelledItemList_CSC,
	// Token: 0x040040DC RID: 16604
	ReqBuySelledItem_CS,
	// Token: 0x040040DD RID: 16605
	RetBuySelledItem_SC,
	// Token: 0x040040DE RID: 16606
	ReqSellItem_CS,
	// Token: 0x040040DF RID: 16607
	RetSellItem_SC,
	// Token: 0x040040E0 RID: 16608
	Ret_GuideHistory_SC,
	// Token: 0x040040E1 RID: 16609
	Ret_GuideStart_SC,
	// Token: 0x040040E2 RID: 16610
	Req_GuideOver_CS,
	// Token: 0x040040E3 RID: 16611
	Ret_GuideOver_SC,
	// Token: 0x040040E4 RID: 16612
	RetCurrencyChange_SC,
	// Token: 0x040040E5 RID: 16613
	ReqCrystalNumToday_CS,
	// Token: 0x040040E6 RID: 16614
	RetCrystalNumToday_SC,
	// Token: 0x040040E7 RID: 16615
	ReqStartAIRunning_CS,
	// Token: 0x040040E8 RID: 16616
	RetStartAIRunning_SC,
	// Token: 0x040040E9 RID: 16617
	RetUserSysSetting_SC,
	// Token: 0x040040EA RID: 16618
	ReqUserSysSetting_CS,
	// Token: 0x040040EB RID: 16619
	Ret_SuccessOpenGift_SC,
	// Token: 0x040040EC RID: 16620
	ReqVitalityDegree_CS,
	// Token: 0x040040ED RID: 16621
	RetVitalityDegree_SC,
	// Token: 0x040040EE RID: 16622
	ReqGetVitalityAward_CS,
	// Token: 0x040040EF RID: 16623
	RetGetVitalityAward_SC,
	// Token: 0x040040F0 RID: 16624
	ReqGeneRemakeInfo_CS,
	// Token: 0x040040F1 RID: 16625
	RetGeneRemakeInfo_SC,
	// Token: 0x040040F2 RID: 16626
	ReqStrengthenGene_CS,
	// Token: 0x040040F3 RID: 16627
	RetStrengthenGene_SC,
	// Token: 0x040040F4 RID: 16628
	Req_HoldonUser_CS,
	// Token: 0x040040F5 RID: 16629
	Ret_HoldonUser_SC,
	// Token: 0x040040F6 RID: 16630
	Ret_HoldonUser_Interrupt_SC,
	// Token: 0x040040F7 RID: 16631
	ReqMakingItem_CS,
	// Token: 0x040040F8 RID: 16632
	RetMakingItem_SC,
	// Token: 0x040040F9 RID: 16633
	Req_StruggleShape_CS,
	// Token: 0x040040FA RID: 16634
	Create_Role_CS,
	// Token: 0x040040FB RID: 16635
	ChangeName_CS,
	// Token: 0x040040FC RID: 16636
	Ret_ChangeName_SC,
	// Token: 0x040040FD RID: 16637
	DataCharacterMain_SC,
	// Token: 0x040040FE RID: 16638
	Req_Use_GM_CS,
	// Token: 0x040040FF RID: 16639
	Ret_Common_Error_SC,
	// Token: 0x04004100 RID: 16640
	Ret_Common_Tips_SC,
	// Token: 0x04004101 RID: 16641
	Req_Main_Data_CS,
	// Token: 0x04004102 RID: 16642
	Req_Test_Network_CS,
	// Token: 0x04004103 RID: 16643
	Ret_GameTime_SC,
	// Token: 0x04004104 RID: 16644
	Req_UserGameTime_SC,
	// Token: 0x04004105 RID: 16645
	Ret_UserGameTime_CS,
	// Token: 0x04004106 RID: 16646
	Ret_ServerTime_SC,
	// Token: 0x04004107 RID: 16647
	Ret_NotifyUserKickout_SC,
	// Token: 0x04004108 RID: 16648
	Ret_ServerLoginFailed_SC,
	// Token: 0x04004109 RID: 16649
	Ret_UserMapInfo_SC,
	// Token: 0x0400410A RID: 16650
	Ret_NineScreenRefreshPlayer_SC,
	// Token: 0x0400410B RID: 16651
	Ret_MapScreenRefreshCharacter_SC,
	// Token: 0x0400410C RID: 16652
	Ret_MapScreenRemoveCharacter_SC,
	// Token: 0x0400410D RID: 16653
	Ret_MapScreenBatchRemoveCharacter_SC,
	// Token: 0x0400410E RID: 16654
	Ret_StateList_SC,
	// Token: 0x0400410F RID: 16655
	Req_Move_CS,
	// Token: 0x04004110 RID: 16656
	Ret_Move_SC,
	// Token: 0x04004111 RID: 16657
	Req_TELE_PORT_CS,
	// Token: 0x04004112 RID: 16658
	Server_Force_Move_SC,
	// Token: 0x04004113 RID: 16659
	Ret_Move_Failed_SC,
	// Token: 0x04004114 RID: 16660
	Ret_SetState_SC,
	// Token: 0x04004115 RID: 16661
	Ret_ClearState_SC,
	// Token: 0x04004116 RID: 16662
	Ret_MapScreenBatchRefreshNpc_SC,
	// Token: 0x04004117 RID: 16663
	Ret_MapScreenBatchRemoveNpc_SC,
	// Token: 0x04004118 RID: 16664
	Ret_MapScreenRefreshNpc_SC,
	// Token: 0x04004119 RID: 16665
	Ret_MapScreenRemoveNpc_SC,
	// Token: 0x0400411A RID: 16666
	Ret_MapScreenFuncNpc_SC,
	// Token: 0x0400411B RID: 16667
	Ret_RetNpcMove_SC,
	// Token: 0x0400411C RID: 16668
	RetNpcWarpMove_SC,
	// Token: 0x0400411D RID: 16669
	RetNpcDir_SC,
	// Token: 0x0400411E RID: 16670
	Req_Summon_Npc_CS,
	// Token: 0x0400411F RID: 16671
	Ret_setTimeState_SC,
	// Token: 0x04004120 RID: 16672
	Req_Ping_CS,
	// Token: 0x04004121 RID: 16673
	Ret_VisibleNpcList_SC,
	// Token: 0x04004122 RID: 16674
	RetNinePlayerLevelUp_SC,
	// Token: 0x04004123 RID: 16675
	UpdateExpLevel_SC,
	// Token: 0x04004124 RID: 16676
	NotifyAntiAddict_SC,
	// Token: 0x04004125 RID: 16677
	ReqEntrySelectState_CS,
	// Token: 0x04004126 RID: 16678
	RetEntrySelectState_SC,
	// Token: 0x04004127 RID: 16679
	RetHpMpToSelects_SC,
	// Token: 0x04004128 RID: 16680
	ReqHeroAttributeData_CS,
	// Token: 0x04004129 RID: 16681
	RetHeroAttributeData_SC,
	// Token: 0x0400412A RID: 16682
	RetDiffLineOfLeader_SC,
	// Token: 0x0400412B RID: 16683
	ReqJumptoLeaderLine_CS,
	// Token: 0x0400412C RID: 16684
	Ret_LoginOnReturnCharList_SC,
	// Token: 0x0400412D RID: 16685
	Req_SelectCharToLogin_CS,
	// Token: 0x0400412E RID: 16686
	Req_IS_NICKNAME_REPEATED_CSC,
	// Token: 0x0400412F RID: 16687
	Req_Back_to_Select_CS,
	// Token: 0x04004130 RID: 16688
	Req_Delete_Char_CSC,
	// Token: 0x04004131 RID: 16689
	Req_Syn_MoveState_CS,
	// Token: 0x04004132 RID: 16690
	Ret_Find_Path_SC,
	// Token: 0x04004133 RID: 16691
	Ret_Rondom_Way_SC,
	// Token: 0x04004134 RID: 16692
	Ret_Find_Path_End_SC,
	// Token: 0x04004135 RID: 16693
	Show_Path_Way_End_CS,
	// Token: 0x04004136 RID: 16694
	NoticeClientAllLines_SC,
	// Token: 0x04004137 RID: 16695
	UserReqChangeLine_CS,
	// Token: 0x04004138 RID: 16696
	OnUserJump_CSC,
	// Token: 0x04004139 RID: 16697
	NPCHatredList_SC,
	// Token: 0x0400413A RID: 16698
	ACCOUNT_SEC_PASSWD_SC,
	// Token: 0x0400413B RID: 16699
	USER_REQ_SETPASSWD_CS,
	// Token: 0x0400413C RID: 16700
	NEW_ROLE_CUTSCENE_SCS,
	// Token: 0x0400413D RID: 16701
	NPC_Death_SC,
	// Token: 0x0400413E RID: 16702
	Req_Holdon_CS,
	// Token: 0x0400413F RID: 16703
	Ret_Holdon_SC,
	// Token: 0x04004140 RID: 16704
	Ret_Holdon_Interrupt_SC,
	// Token: 0x04004141 RID: 16705
	Ret_AddHoldNpcData_SC,
	// Token: 0x04004142 RID: 16706
	Ret_BatchAddHoldNpcData_SC,
	// Token: 0x04004143 RID: 16707
	Ret_RemoveHoldNpcData_SC,
	// Token: 0x04004144 RID: 16708
	Ret_HoldonSuccess,
	// Token: 0x04004145 RID: 16709
	ReqWatchSceneBag_CS,
	// Token: 0x04004146 RID: 16710
	ReqPickObjFromSceneBag_CS,
	// Token: 0x04004147 RID: 16711
	ReqPickAllSceneBag_CS,
	// Token: 0x04004148 RID: 16712
	RefreshSceneBag_SC,
	// Token: 0x04004149 RID: 16713
	RefreshObjs_SC,
	// Token: 0x0400414A RID: 16714
	PackData_SC,
	// Token: 0x0400414B RID: 16715
	WearEquip_CS,
	// Token: 0x0400414C RID: 16716
	WearEquip_SC,
	// Token: 0x0400414D RID: 16717
	RemoveObject_SC,
	// Token: 0x0400414E RID: 16718
	UnwearEquip_CS,
	// Token: 0x0400414F RID: 16719
	UnwearEquip_SC,
	// Token: 0x04004150 RID: 16720
	ReqCheckItemDueTime_CS,
	// Token: 0x04004151 RID: 16721
	ReqUseObject_CS,
	// Token: 0x04004152 RID: 16722
	PackUnlock_CS,
	// Token: 0x04004153 RID: 16723
	PackUnlock_SC,
	// Token: 0x04004154 RID: 16724
	MergeObjs_CS,
	// Token: 0x04004155 RID: 16725
	MergeObjs_SC,
	// Token: 0x04004156 RID: 16726
	TidyPack_CS,
	// Token: 0x04004157 RID: 16727
	TidyPack_SC,
	// Token: 0x04004158 RID: 16728
	ReqSellObject_CS,
	// Token: 0x04004159 RID: 16729
	ReqMoveObject_CS,
	// Token: 0x0400415A RID: 16730
	ReqSwapObject_CS,
	// Token: 0x0400415B RID: 16731
	ReqDestroyObject_CS,
	// Token: 0x0400415C RID: 16732
	ReqPutOnCard_CS,
	// Token: 0x0400415D RID: 16733
	ReqPutOffCard_CS,
	// Token: 0x0400415E RID: 16734
	ReqSwapCard_CS,
	// Token: 0x0400415F RID: 16735
	ReqCardPackInfo_CS,
	// Token: 0x04004160 RID: 16736
	RetCardPackInfo_SC,
	// Token: 0x04004161 RID: 16737
	ReqSplitObject_CS,
	// Token: 0x04004162 RID: 16738
	ReqOpItemLock_CS,
	// Token: 0x04004163 RID: 16739
	ReqSwitchPetState_CS,
	// Token: 0x04004164 RID: 16740
	RetSwitchPetState_SC,
	// Token: 0x04004165 RID: 16741
	RetRefreshSummonPet_SC,
	// Token: 0x04004166 RID: 16742
	RetUserPetInfo_SC,
	// Token: 0x04004167 RID: 16743
	NotifyPetQTESkill_SC,
	// Token: 0x04004168 RID: 16744
	ReqUnlockPetNum_CS,
	// Token: 0x04004169 RID: 16745
	RetUnlockPetNum_SC,
	// Token: 0x0400416A RID: 16746
	Req_StartPvPMatch_CS,
	// Token: 0x0400416B RID: 16747
	Ret_StartPvPMatch_SC,
	// Token: 0x0400416C RID: 16748
	Req_CancelPvPMatch_CS,
	// Token: 0x0400416D RID: 16749
	Ret_CancelPvPMatch_SC,
	// Token: 0x0400416E RID: 16750
	Ret_PvPMatchResult_SC,
	// Token: 0x0400416F RID: 16751
	Req_GotoPvPBattle_CS,
	// Token: 0x04004170 RID: 16752
	ReqChoosePvPPrepared_CS,
	// Token: 0x04004171 RID: 16753
	RetChoosePvPPrepared_SC,
	// Token: 0x04004172 RID: 16754
	RetStartPvPPrepare_SC,
	// Token: 0x04004173 RID: 16755
	RetPvPFightCountDown_SC,
	// Token: 0x04004174 RID: 16756
	RetPvPFightPreFight_SC,
	// Token: 0x04004175 RID: 16757
	RetStartPvPFight_SC,
	// Token: 0x04004176 RID: 16758
	RetPvPSpeedupFight_SC,
	// Token: 0x04004177 RID: 16759
	RetPvPFightFinish_SC,
	// Token: 0x04004178 RID: 16760
	ReqPvPFightCurStage_CS,
	// Token: 0x04004179 RID: 16761
	RetPvPFightCurStage_SC,
	// Token: 0x0400417A RID: 16762
	RetPvPTeamCurScore_SC,
	// Token: 0x0400417B RID: 16763
	RetPvPPreparedNum_SC,
	// Token: 0x0400417C RID: 16764
	ReqPvPDailyAwards_CS,
	// Token: 0x0400417D RID: 16765
	RetPvPDailyAwards_SC,
	// Token: 0x0400417E RID: 16766
	RetPvPPKGeneralConfig_SC,
	// Token: 0x0400417F RID: 16767
	RetPvPMatchFightCurLive_SC,
	// Token: 0x04004180 RID: 16768
	Req_VisitNpcTrade_CS,
	// Token: 0x04004181 RID: 16769
	Ret_VisitNpcTrade_SC,
	// Token: 0x04004182 RID: 16770
	Req_QuestInfo_CS,
	// Token: 0x04004183 RID: 16771
	Ret_QuestInfo_SC,
	// Token: 0x04004184 RID: 16772
	ReqExecuteQuest_CS,
	// Token: 0x04004185 RID: 16773
	ReqValidQuests_CS,
	// Token: 0x04004186 RID: 16774
	RetValidQuests_SC,
	// Token: 0x04004187 RID: 16775
	ReqRetQuestState_CSC,
	// Token: 0x04004188 RID: 16776
	ReqAbandonQuest_CS,
	// Token: 0x04004189 RID: 16777
	RetAbandonQuest_SC,
	// Token: 0x0400418A RID: 16778
	ReqMapQuestInfo_CS,
	// Token: 0x0400418B RID: 16779
	RetMapQuestInfo_SC,
	// Token: 0x0400418C RID: 16780
	ReqCurActiveQuest_CS,
	// Token: 0x0400418D RID: 16781
	RetCurActiveQuest_SC,
	// Token: 0x0400418E RID: 16782
	ReqChangeMapFindPath_CS,
	// Token: 0x0400418F RID: 16783
	RetChangeMapFindPath_SC,
	// Token: 0x04004190 RID: 16784
	RetPlotTalkID_SC,
	// Token: 0x04004191 RID: 16785
	CartoonCompleteNotify_SC,
	// Token: 0x04004192 RID: 16786
	PlayCartoonAndGoMap_SC,
	// Token: 0x04004193 RID: 16787
	ReqSubmitObjs_CS,
	// Token: 0x04004194 RID: 16788
	RetSubmitObjs_SC,
	// Token: 0x04004195 RID: 16789
	RetRingQuestRingCount_SC,
	// Token: 0x04004196 RID: 16790
	notifyRefreshQuestInfo_SC,
	// Token: 0x04004197 RID: 16791
	PlayBellQTE_SC,
	// Token: 0x04004198 RID: 16792
	PlayBellQTEResult_CS,
	// Token: 0x04004199 RID: 16793
	Req_SetQuestNeedShow_CS,
	// Token: 0x0400419A RID: 16794
	Ret_SetQuestNeedShow_SC,
	// Token: 0x0400419B RID: 16795
	Req_ShareQuestToTeamMember_CS,
	// Token: 0x0400419C RID: 16796
	Ret_NotifyShareQuest_SC,
	// Token: 0x0400419D RID: 16797
	Req_AnswerShareQuest_CS,
	// Token: 0x0400419E RID: 16798
	Ret_AnswerShareQuest_SC,
	// Token: 0x0400419F RID: 16799
	Ret_NotifyCountDown_SC,
	// Token: 0x040041A0 RID: 16800
	NotifyClientOptional_SC,
	// Token: 0x040041A1 RID: 16801
	Req_QuizPrivilege_CS,
	// Token: 0x040041A2 RID: 16802
	Ret_QuizPrivilege_SC,
	// Token: 0x040041A3 RID: 16803
	Req_StartQuiz_CS,
	// Token: 0x040041A4 RID: 16804
	Ret_QuestionsData_SC,
	// Token: 0x040041A5 RID: 16805
	AnswerQuestion_CS,
	// Token: 0x040041A6 RID: 16806
	Ret_QuestionResult_SC,
	// Token: 0x040041A7 RID: 16807
	Req_UseHelpItem_CS,
	// Token: 0x040041A8 RID: 16808
	Ret_HelpItemEffect_SC,
	// Token: 0x040041A9 RID: 16809
	Req_MatchMemberInfo_CS,
	// Token: 0x040041AA RID: 16810
	Ret_MatchMemberInfo_SC,
	// Token: 0x040041AB RID: 16811
	Req_StartMatch_CS,
	// Token: 0x040041AC RID: 16812
	Ret_StartMatch_SC,
	// Token: 0x040041AD RID: 16813
	Req_CancelMatch_CS,
	// Token: 0x040041AE RID: 16814
	Ret_CancelMatch_SC,
	// Token: 0x040041AF RID: 16815
	GoToBattle_SC,
	// Token: 0x040041B0 RID: 16816
	Ret_MatchResult_SC,
	// Token: 0x040041B1 RID: 16817
	Req_GotoBattle_CS,
	// Token: 0x040041B2 RID: 16818
	RetStartPrepare_SC,
	// Token: 0x040041B3 RID: 16819
	ReqChoosePrepared_CS,
	// Token: 0x040041B4 RID: 16820
	RetChoosePrepared_SC,
	// Token: 0x040041B5 RID: 16821
	RetFightCountDown_SC,
	// Token: 0x040041B6 RID: 16822
	RetStartFight_SC,
	// Token: 0x040041B7 RID: 16823
	RetSpeedupFight_SC,
	// Token: 0x040041B8 RID: 16824
	RetFightFinish_SC,
	// Token: 0x040041B9 RID: 16825
	ReqGetSeasonRewards_CS,
	// Token: 0x040041BA RID: 16826
	RetGetSeasonRewards_SC,
	// Token: 0x040041BB RID: 16827
	RetRewardsEveryday_SC,
	// Token: 0x040041BC RID: 16828
	ReqRewardsEveryday_CS,
	// Token: 0x040041BD RID: 16829
	RetRankPKHeroHistory_SC,
	// Token: 0x040041BE RID: 16830
	RetUserRankStar_SC,
	// Token: 0x040041BF RID: 16831
	RetTeamLeftMemSize_SC,
	// Token: 0x040041C0 RID: 16832
	ReqRankPKCurStage_CS,
	// Token: 0x040041C1 RID: 16833
	RetRankPKCurStage_SC,
	// Token: 0x040041C2 RID: 16834
	RetPreparedNum_SC,
	// Token: 0x040041C3 RID: 16835
	RetMemPkPrepared_SC,
	// Token: 0x040041C4 RID: 16836
	RetPKGeneralConfig_SC,
	// Token: 0x040041C5 RID: 16837
	RetTeamCurScore_SC,
	// Token: 0x040041C6 RID: 16838
	Req_RuneActiveData_CS,
	// Token: 0x040041C7 RID: 16839
	Ret_RuneActiveData_SC,
	// Token: 0x040041C8 RID: 16840
	Req_RunePageData_CS,
	// Token: 0x040041C9 RID: 16841
	Ret_RunePageData_SC,
	// Token: 0x040041CA RID: 16842
	Req_ActiveRune_CS,
	// Token: 0x040041CB RID: 16843
	Ret_ActiveRune_SC,
	// Token: 0x040041CC RID: 16844
	Req_InsertRune_CS,
	// Token: 0x040041CD RID: 16845
	Ret_InsertRune_SC,
	// Token: 0x040041CE RID: 16846
	Req_UnloadRune_CS,
	// Token: 0x040041CF RID: 16847
	Ret_UnloadRune_SC,
	// Token: 0x040041D0 RID: 16848
	Req_UnloadAllRune_CS,
	// Token: 0x040041D1 RID: 16849
	Ret_UnloadAllRune_SC,
	// Token: 0x040041D2 RID: 16850
	Req_LevelupRune_CS,
	// Token: 0x040041D3 RID: 16851
	Ret_LevelupRune_SC,
	// Token: 0x040041D4 RID: 16852
	Req_RunePageNameModify_CS,
	// Token: 0x040041D5 RID: 16853
	Ret_RunePageNameModify_SC,
	// Token: 0x040041D6 RID: 16854
	Req_RuneSwitch_CS,
	// Token: 0x040041D7 RID: 16855
	Ret_RuneSwitch_SC,
	// Token: 0x040041D8 RID: 16856
	ReqNearByUnteamedPlayer_CS,
	// Token: 0x040041D9 RID: 16857
	ReqNearByUnteamedPlayer_SC,
	// Token: 0x040041DA RID: 16858
	AddMemember_SC,
	// Token: 0x040041DB RID: 16859
	updateTeamMememberHp_SC,
	// Token: 0x040041DC RID: 16860
	updateTeamMememberCareer_SC,
	// Token: 0x040041DD RID: 16861
	updateTeamMemeberHero_SC,
	// Token: 0x040041DE RID: 16862
	updateTeamMememberLevel_SC,
	// Token: 0x040041DF RID: 16863
	updateTeamMemberFight_SC,
	// Token: 0x040041E0 RID: 16864
	ReqTeamMemberPos_CS,
	// Token: 0x040041E1 RID: 16865
	RetTeamMemberPos_SC,
	// Token: 0x040041E2 RID: 16866
	RetNewApply_SC,
	// Token: 0x040041E3 RID: 16867
	RetTeamPublicDrop_SC,
	// Token: 0x040041E4 RID: 16868
	ReqChooseTeamDrop_CS,
	// Token: 0x040041E5 RID: 16869
	RetChooseTeamDrop_SC,
	// Token: 0x040041E6 RID: 16870
	updateMemStateToTeam_SC,
	// Token: 0x040041E7 RID: 16871
	ReqLeaderMapPos_CS,
	// Token: 0x040041E8 RID: 16872
	RetLeaderMapPos_SC,
	// Token: 0x040041E9 RID: 16873
	ReqChangeMapToLeader_CS,
	// Token: 0x040041EA RID: 16874
	RetChangeMapToLeader_SC,
	// Token: 0x040041EB RID: 16875
	ReqLeaderAttackTarget_CS,
	// Token: 0x040041EC RID: 16876
	RetLeaderAttackTarget_SC,
	// Token: 0x040041ED RID: 16877
	notifyMemberLeaderIntoPublic_SC,
	// Token: 0x040041EE RID: 16878
	notifyMemberOfflineHosting_SC,
	// Token: 0x040041EF RID: 16879
	updateTeamMemberPrivilege_SC,
	// Token: 0x040041F0 RID: 16880
	Ret_checkUserTeamInfo_SC,
	// Token: 0x040041F1 RID: 16881
	NotifyTeamDismiss_SC,
	// Token: 0x040041F2 RID: 16882
	Ret_TreasurePos_SC,
	// Token: 0x040041F3 RID: 16883
	ReqChangeMapHuntTreasure_CS,
	// Token: 0x040041F4 RID: 16884
	RetChangeMapHuntTreasure_SC,
	// Token: 0x040041F5 RID: 16885
	User_Drop_SCS,
	// Token: 0x040041F6 RID: 16886
	ART_CUTSCENE_SC,
	// Token: 0x040041F7 RID: 16887
	ReqGetVIPCardInfo_CS,
	// Token: 0x040041F8 RID: 16888
	RetGetVIPCardInfo_SC,
	// Token: 0x040041F9 RID: 16889
	ReqBuyVIPCard_CS,
	// Token: 0x040041FA RID: 16890
	RetBuyVIPCard_SC,
	// Token: 0x040041FB RID: 16891
	ReqAcepVIPCardPrize_CS,
	// Token: 0x040041FC RID: 16892
	RetAcepVIPCardPrize_SC,
	// Token: 0x040041FD RID: 16893
	ReqRaffVIPCardPrize_CS,
	// Token: 0x040041FE RID: 16894
	RetRaffVIPCardPrize_SC,
	// Token: 0x040041FF RID: 16895
	ReqCurrencyExchange_CS,
	// Token: 0x04004200 RID: 16896
	RetCurrencyExchange_SC,
	// Token: 0x04004201 RID: 16897
	UserLoadingOk_CS,
	// Token: 0x04004202 RID: 16898
	RetQueryBalance_SC,
	// Token: 0x04004203 RID: 16899
	RetRecharge_SC,
	// Token: 0x04004204 RID: 16900
	ExchangeRatio_CSC,
	// Token: 0x04004205 RID: 16901
	Ret_MapScreenRemoveCharacterShowCorpse_SC,
	// Token: 0x04004206 RID: 16902
	Req_OperateClientDataNew_CS,
	// Token: 0x04004207 RID: 16903
	Req_OperateClientDataNew_CSC,
	// Token: 0x04004208 RID: 16904
	SetChooseTarget_CS,
	// Token: 0x04004209 RID: 16905
	AttackTargetCharge_SC,
	// Token: 0x0400420A RID: 16906
	RetUserAvatars_SC,
	// Token: 0x0400420B RID: 16907
	AttackTargetChange_SC,
	// Token: 0x0400420C RID: 16908
	ReqEquipAvatar_CS,
	// Token: 0x0400420D RID: 16909
	NotifyClientHeroScore_SC,
	// Token: 0x0400420E RID: 16910
	notifyQuestStateEffect_SC,
	// Token: 0x0400420F RID: 16911
	RetUserEvolution_SC,
	// Token: 0x04004210 RID: 16912
	ReqTransMoney_CS,
	// Token: 0x04004211 RID: 16913
	ReqUserEvolution_CS,
	// Token: 0x04004212 RID: 16914
	NotifyAccountReuse,
	// Token: 0x04004213 RID: 16915
	RefreshMarketItem_SC,
	// Token: 0x04004214 RID: 16916
	Req_GuildPkEnroll_CS,
	// Token: 0x04004215 RID: 16917
	Req_PlayGameData_CS,
	// Token: 0x04004216 RID: 16918
	Req_PlayGameRetry_CS,
	// Token: 0x04004217 RID: 16919
	RealTime_GuildPkTeam_Rank_SC,
	// Token: 0x04004218 RID: 16920
	Req_EnterGuildPk_CS,
	// Token: 0x04004219 RID: 16921
	Ret_GuildPkCountDown_SC,
	// Token: 0x0400421A RID: 16922
	Ret_GuildPkFight_SC,
	// Token: 0x0400421B RID: 16923
	GuildPk_FinalResult_SC,
	// Token: 0x0400421C RID: 16924
	ReqUseObject_Special_CS,
	// Token: 0x0400421D RID: 16925
	Req_CommitYQDData_CS,
	// Token: 0x0400421E RID: 16926
	Req_PlayYQDRetry_CS,
	// Token: 0x0400421F RID: 16927
	Notify_SceneLoaded_CS,
	// Token: 0x04004220 RID: 16928
	ReqFixUpDurability_CS,
	// Token: 0x04004221 RID: 16929
	retEnterBattle_SC,
	// Token: 0x04004222 RID: 16930
	RetHoldFlagTeamScore_SC,
	// Token: 0x04004223 RID: 16931
	ReqHoldFlagReport_CS,
	// Token: 0x04004224 RID: 16932
	RetHoldFlagReport_SC,
	// Token: 0x04004225 RID: 16933
	RetHoldFlagDBState_SC,
	// Token: 0x04004226 RID: 16934
	RetHoldFlagAccount_SC,
	// Token: 0x04004227 RID: 16935
	ReqHoldFlagCaptureDB_CS,
	// Token: 0x04004228 RID: 16936
	ReqHoldFlagPutDownDB_CS,
	// Token: 0x04004229 RID: 16937
	RetHoldFlagCountDown_SC,
	// Token: 0x0400422A RID: 16938
	NoneChantSkill_SC,
	// Token: 0x0400422B RID: 16939
	Ret_GuildPkEnroll_Finish_SC,
	// Token: 0x0400422C RID: 16940
	Ret_BeFiredGuildMember_SC,
	// Token: 0x0400422D RID: 16941
	RetHoldFlagEvent_SC,
	// Token: 0x0400422E RID: 16942
	ReqUpdateAntiAddict_CS,
	// Token: 0x0400422F RID: 16943
	ReqBattleTimes_CS,
	// Token: 0x04004230 RID: 16944
	RetBattleTimes_SC,
	// Token: 0x04004231 RID: 16945
	Ret_Day7ActivityInfo_SC,
	// Token: 0x04004232 RID: 16946
	Req_RecvDay7ActivityPrize_CS,
	// Token: 0x04004233 RID: 16947
	Ret_SeekActivityInfo_SC,
	// Token: 0x04004234 RID: 16948
	Req_RecvSeekActivityPrize_CS,
	// Token: 0x04004235 RID: 16949
	Req_SeekActivityInfo_CS,
	// Token: 0x04004236 RID: 16950
	Ret_UserSkillRelive_SC,
	// Token: 0x04004237 RID: 16951
	updateTeamMemberAvatar_SC,
	// Token: 0x04004238 RID: 16952
	MatchInfo_SC,
	// Token: 0x04004239 RID: 16953
	DismissGroup_SC,
	// Token: 0x0400423A RID: 16954
	MyTeamInfo_SC,
	// Token: 0x0400423B RID: 16955
	RefreshPowerRank_SC,
	// Token: 0x0400423C RID: 16956
	RefreshRadarPos_SC,
	// Token: 0x0400423D RID: 16957
	artPray_SC,
	// Token: 0x0400423E RID: 16958
	ServerTimer_SC,
	// Token: 0x0400423F RID: 16959
	RefreshRadarPos_CSC,
	// Token: 0x04004240 RID: 16960
	SelectHopes_CS,
	// Token: 0x04004241 RID: 16961
	BstUserTeamInfo_SC,
	// Token: 0x04004242 RID: 16962
	ReqUseCapsule_CS,
	// Token: 0x04004243 RID: 16963
	UseSpecialCapsule_CS,
	// Token: 0x04004244 RID: 16964
	GameOver_SC,
	// Token: 0x04004245 RID: 16965
	UserGetAwardReq_CS,
	// Token: 0x04004246 RID: 16966
	RewardBagInfo_SC,
	// Token: 0x04004247 RID: 16967
	MobaLevelUp_SC,
	// Token: 0x04004248 RID: 16968
	ClientEffect_SC,
	// Token: 0x04004249 RID: 16969
	Req_DivorceStuck_CS,
	// Token: 0x0400424A RID: 16970
	Ret_QueueInfo_SC,
	// Token: 0x0400424B RID: 16971
	Req_Survey_Info_CS,
	// Token: 0x0400424C RID: 16972
	Ret_Survey_Info_SC,
	// Token: 0x0400424D RID: 16973
	Req_GetSurveyReward_CS,
	// Token: 0x0400424E RID: 16974
	Ret_GetSurveyReward_SC,
	// Token: 0x0400424F RID: 16975
	Upload_Crash_Info,
	// Token: 0x04004250 RID: 16976
	Req_GuideStart_CS,
	// Token: 0x04004251 RID: 16977
	Ret_Wegame_Fcm_Info,
	// Token: 0x04004252 RID: 16978
	Ret_Test1 = 40002,
	// Token: 0x04004253 RID: 16979
	Ret_Test2,
	// Token: 0x04004254 RID: 16980
	Ret_Test3 = 50002,
	// Token: 0x04004255 RID: 16981
	Ret_Test4,
	// Token: 0x04004256 RID: 16982
	Req_MasterApprenticeInfo_CS = 60002,
	// Token: 0x04004257 RID: 16983
	Ret_MasterApprenticeInfo_SC,
	// Token: 0x04004258 RID: 16984
	Req_ApprenticeList_CS,
	// Token: 0x04004259 RID: 16985
	Ret_ApprenticeList_SC,
	// Token: 0x0400425A RID: 16986
	Req_MasterApprenticeCount_CS,
	// Token: 0x0400425B RID: 16987
	Ret_MasterApprenticeCount_SC,
	// Token: 0x0400425C RID: 16988
	Req_TakeMaster_CS,
	// Token: 0x0400425D RID: 16989
	Ret_ApplyTakeMaster_SC,
	// Token: 0x0400425E RID: 16990
	Req_AnswerTakeMaster_CS,
	// Token: 0x0400425F RID: 16991
	Ret_TakeMaster_SC,
	// Token: 0x04004260 RID: 16992
	Req_TakeApprentice_CS,
	// Token: 0x04004261 RID: 16993
	Ret_ApplyTakeApprentice_SC,
	// Token: 0x04004262 RID: 16994
	Req_AnswerTakeApprentice_CS,
	// Token: 0x04004263 RID: 16995
	Ret_TakeApprentice_SC,
	// Token: 0x04004264 RID: 16996
	Req_StartTakeApprentice_CS,
	// Token: 0x04004265 RID: 16997
	Ret_StartTakeApprentice_SC,
	// Token: 0x04004266 RID: 16998
	Req_StartTakeMaster_CS,
	// Token: 0x04004267 RID: 16999
	Ret_StartTakeMaster_SC,
	// Token: 0x04004268 RID: 17000
	Req_unpublishTakeMaster_CS,
	// Token: 0x04004269 RID: 17001
	Ret_unpublishTakeMaster_SC,
	// Token: 0x0400426A RID: 17002
	Req_SearchMaster_CS,
	// Token: 0x0400426B RID: 17003
	Ret_SearchMaster_SC,
	// Token: 0x0400426C RID: 17004
	Req_SearchApprentice_CS,
	// Token: 0x0400426D RID: 17005
	Ret_SearchApprentice_SC,
	// Token: 0x0400426E RID: 17006
	Req_UserApprenticeInfo_CS,
	// Token: 0x0400426F RID: 17007
	Ret_UserApprenticeInfo_SC,
	// Token: 0x04004270 RID: 17008
	Req_preQuitApprentice_CS,
	// Token: 0x04004271 RID: 17009
	Ret_preQuitApprentice_SC,
	// Token: 0x04004272 RID: 17010
	Req_applyQuitApprentice_CS,
	// Token: 0x04004273 RID: 17011
	Ret_applyQuitApprentice_SC,
	// Token: 0x04004274 RID: 17012
	Req_unQuitApprentice_CS,
	// Token: 0x04004275 RID: 17013
	Ret_unQuitApprentice_SC,
	// Token: 0x04004276 RID: 17014
	Req_FinishApprentice_CS,
	// Token: 0x04004277 RID: 17015
	Ret_FinishApprentice_SC,
	// Token: 0x04004278 RID: 17016
	Ret_ApprenticeChange_SC,
	// Token: 0x04004279 RID: 17017
	Req_OperateClientDatas_CS,
	// Token: 0x0400427A RID: 17018
	Req_ChatUserInfo_CS,
	// Token: 0x0400427B RID: 17019
	Ret_ChatUserInfo_SC,
	// Token: 0x0400427C RID: 17020
	Req_OfflineChat_CS,
	// Token: 0x0400427D RID: 17021
	Ret_OfflineChat_SC,
	// Token: 0x0400427E RID: 17022
	Req_CopymapAnswerGather_CS,
	// Token: 0x0400427F RID: 17023
	Req_CopymapGatherQuickEnter_CS,
	// Token: 0x04004280 RID: 17024
	Req_CopymapReGather_CS,
	// Token: 0x04004281 RID: 17025
	Req_JoinCountry_CS,
	// Token: 0x04004282 RID: 17026
	Ret_JoinCountry_SC,
	// Token: 0x04004283 RID: 17027
	Req_PreCreateGuild_CS,
	// Token: 0x04004284 RID: 17028
	Ret_PreCreateGuild_SC,
	// Token: 0x04004285 RID: 17029
	Req_CreateGuild_CS,
	// Token: 0x04004286 RID: 17030
	Ret_CreateGuild_SC,
	// Token: 0x04004287 RID: 17031
	Req_SetGuildNotify_CS,
	// Token: 0x04004288 RID: 17032
	Ret_SetGuildNotify_SC,
	// Token: 0x04004289 RID: 17033
	Req_GuildInfo_CS,
	// Token: 0x0400428A RID: 17034
	Ret_GuildInfo_SC,
	// Token: 0x0400428B RID: 17035
	Req_GuildList_CS,
	// Token: 0x0400428C RID: 17036
	Ret_GuildList_SC,
	// Token: 0x0400428D RID: 17037
	Req_ApplyForGuild_CS,
	// Token: 0x0400428E RID: 17038
	Ret_ApplyForGuild_SC,
	// Token: 0x0400428F RID: 17039
	Req_AnswerApplyForGuild_CS,
	// Token: 0x04004290 RID: 17040
	Ret_AnswerApplyForGuild_SC,
	// Token: 0x04004291 RID: 17041
	Req_GuildMemberList_CS,
	// Token: 0x04004292 RID: 17042
	Ret_GuildMemberList_SC,
	// Token: 0x04004293 RID: 17043
	Req_CiTanEnemyGuildList_CS,
	// Token: 0x04004294 RID: 17044
	Ret_CiTanEnemyGuildList_SC,
	// Token: 0x04004295 RID: 17045
	Req_ChooseCiTanEnemyGuild_CS,
	// Token: 0x04004296 RID: 17046
	Req_TargetCiTanEnemyGuild_CS,
	// Token: 0x04004297 RID: 17047
	Ret_ChoosedCiTanEnemyGuild_SC,
	// Token: 0x04004298 RID: 17048
	Req_AddGuildPosition_CS,
	// Token: 0x04004299 RID: 17049
	Req_DeleteGuildPosition_CS,
	// Token: 0x0400429A RID: 17050
	Req_SwapGuildPosOrder_CS,
	// Token: 0x0400429B RID: 17051
	Req_ChangePositionName_CS,
	// Token: 0x0400429C RID: 17052
	Req_ChangePositionPri_CS,
	// Token: 0x0400429D RID: 17053
	Req_AssignPosition_CS,
	// Token: 0x0400429E RID: 17054
	Ret_AssignPosition_SC,
	// Token: 0x0400429F RID: 17055
	Ret_PositionInfo_SC,
	// Token: 0x040042A0 RID: 17056
	Req_GuildLevelup_CS,
	// Token: 0x040042A1 RID: 17057
	Ret_GuildLevelup_SC,
	// Token: 0x040042A2 RID: 17058
	Req_GuildSetInfo_CS,
	// Token: 0x040042A3 RID: 17059
	Ret_GuildSetInfo_SC,
	// Token: 0x040042A4 RID: 17060
	Req_GetDayWelfare_CS,
	// Token: 0x040042A5 RID: 17061
	Ret_GetDayWelfare_SC,
	// Token: 0x040042A6 RID: 17062
	Req_QuitGuild_CS,
	// Token: 0x040042A7 RID: 17063
	Req_FireGuildMember_CS,
	// Token: 0x040042A8 RID: 17064
	Req_GuildInvite_CS,
	// Token: 0x040042A9 RID: 17065
	Req_GuildInviteConfirm_CS,
	// Token: 0x040042AA RID: 17066
	Req_DismissGuild_CS,
	// Token: 0x040042AB RID: 17067
	Req_ChangeGuildMaster_CS,
	// Token: 0x040042AC RID: 17068
	Req_GuildViceMaster_CS,
	// Token: 0x040042AD RID: 17069
	RankPkReqPrepare_CS,
	// Token: 0x040042AE RID: 17070
	RankPkReqPrepare_SC,
	// Token: 0x040042AF RID: 17071
	Ret_RelationList_SC,
	// Token: 0x040042B0 RID: 17072
	Ret_RefreshRelation_SC,
	// Token: 0x040042B1 RID: 17073
	Req_ApplyRelation_CS,
	// Token: 0x040042B2 RID: 17074
	Req_AnswerApplyRelation_CS,
	// Token: 0x040042B3 RID: 17075
	Ret_AnswerApplyRelation_SC,
	// Token: 0x040042B4 RID: 17076
	Req_DeleteRelation_CS,
	// Token: 0x040042B5 RID: 17077
	Ret_DeleteRelation_SC,
	// Token: 0x040042B6 RID: 17078
	Req_OfflineInteractive_CS,
	// Token: 0x040042B7 RID: 17079
	Ret_AddInteractive_SC,
	// Token: 0x040042B8 RID: 17080
	Req_SearchRelation_CS,
	// Token: 0x040042B9 RID: 17081
	Ret_SearchRelation_SC,
	// Token: 0x040042BA RID: 17082
	ModifyPageName_CSC,
	// Token: 0x040042BB RID: 17083
	MoveFriendToPage_CSC,
	// Token: 0x040042BC RID: 17084
	AllFriendPage_CSC,
	// Token: 0x040042BD RID: 17085
	BlackList_CSC,
	// Token: 0x040042BE RID: 17086
	OperateBlackList_CSC,
	// Token: 0x040042BF RID: 17087
	ChangeNickName_CSC,
	// Token: 0x040042C0 RID: 17088
	CreateTeam_CS,
	// Token: 0x040042C1 RID: 17089
	TeamMemeberList_CS,
	// Token: 0x040042C2 RID: 17090
	TeamMemeberList_SC,
	// Token: 0x040042C3 RID: 17091
	Team_List_CS,
	// Token: 0x040042C4 RID: 17092
	Team_List_SC,
	// Token: 0x040042C5 RID: 17093
	Join_Team_CS,
	// Token: 0x040042C6 RID: 17094
	Join_Team_SC,
	// Token: 0x040042C7 RID: 17095
	ReqJoinTeamNotifyLeader_SC,
	// Token: 0x040042C8 RID: 17096
	AnswerJoinTeam_CS,
	// Token: 0x040042C9 RID: 17097
	AnswerJoinTeam_SC,
	// Token: 0x040042CA RID: 17098
	ReqApplyList_CS,
	// Token: 0x040042CB RID: 17099
	ReqApplyList_SC,
	// Token: 0x040042CC RID: 17100
	ReqDelMemember_CS,
	// Token: 0x040042CD RID: 17101
	ReqDelMemember_SC,
	// Token: 0x040042CE RID: 17102
	ReqLanchVoteOut_CS,
	// Token: 0x040042CF RID: 17103
	ReqLanchVoteOut_SC,
	// Token: 0x040042D0 RID: 17104
	ReqVote_CS,
	// Token: 0x040042D1 RID: 17105
	ReqChangeLeader_CS,
	// Token: 0x040042D2 RID: 17106
	ReqChangeLeader_SC,
	// Token: 0x040042D3 RID: 17107
	InviteIntoTeam_CS,
	// Token: 0x040042D4 RID: 17108
	InviteIntoTeam_SC,
	// Token: 0x040042D5 RID: 17109
	AnswerInviteTeam_CS,
	// Token: 0x040042D6 RID: 17110
	LeaderIgnoreNotice_CS,
	// Token: 0x040042D7 RID: 17111
	RetNearByUnteamedInvite_SC,
	// Token: 0x040042D8 RID: 17112
	ReqSearchTeam_CS,
	// Token: 0x040042D9 RID: 17113
	ReqSearchTeamByPage_CS,
	// Token: 0x040042DA RID: 17114
	RetSearchTeam_SC,
	// Token: 0x040042DB RID: 17115
	ReqChangeActivityTarget_CS,
	// Token: 0x040042DC RID: 17116
	RetChangeActivityTarget_SC,
	// Token: 0x040042DD RID: 17117
	ReqMatch_CS,
	// Token: 0x040042DE RID: 17118
	RetMatch_SC,
	// Token: 0x040042DF RID: 17119
	ReqUnmatch_CS,
	// Token: 0x040042E0 RID: 17120
	RetUnmatch_SC,
	// Token: 0x040042E1 RID: 17121
	RetNotifyMatchSuccess_SC,
	// Token: 0x040042E2 RID: 17122
	ReqMemberBackTeam_CS,
	// Token: 0x040042E3 RID: 17123
	RetMemberBackTeam_SC,
	// Token: 0x040042E4 RID: 17124
	Req_SetMemberPrivilege_CS,
	// Token: 0x040042E5 RID: 17125
	Req_checkUserTeamInfo_CS,
	// Token: 0x040042E6 RID: 17126
	Req_DismissTeam_CS,
	// Token: 0x040042E7 RID: 17127
	ReqQueryBalance_CS,
	// Token: 0x040042E8 RID: 17128
	ReqRecharge_CS,
	// Token: 0x040042E9 RID: 17129
	Ret_MyGuildApply_Result_SC,
	// Token: 0x040042EA RID: 17130
	Ret_GuildPkEnroll_SC = 60151,
	// Token: 0x040042EB RID: 17131
	Ret_GuildPkInfo_SC,
	// Token: 0x040042EC RID: 17132
	Req_GuildPkInfo_CS,
	// Token: 0x040042ED RID: 17133
	Req_GuildPkJoinTeam_CS,
	// Token: 0x040042EE RID: 17134
	Req_GuildPkQuitTeam_CS,
	// Token: 0x040042EF RID: 17135
	Req_GuildPkRank_CS,
	// Token: 0x040042F0 RID: 17136
	Ret_GuildPkRank_SC,
	// Token: 0x040042F1 RID: 17137
	Req_GuildPkWinList_CS,
	// Token: 0x040042F2 RID: 17138
	Ret_GuildPkWinList_SC,
	// Token: 0x040042F3 RID: 17139
	Req_GuildSkill_CS,
	// Token: 0x040042F4 RID: 17140
	Ret_GuildSkill_SC,
	// Token: 0x040042F5 RID: 17141
	Req_LearnGuildSkill_CSC,
	// Token: 0x040042F6 RID: 17142
	ReqRankPKList_CS,
	// Token: 0x040042F7 RID: 17143
	RetRankPKList_SC,
	// Token: 0x040042F8 RID: 17144
	Refresh_GuildPkMemberInfo_SC,
	// Token: 0x040042F9 RID: 17145
	Ret_GuildPkMatchResult_SC,
	// Token: 0x040042FA RID: 17146
	ReqBattleMatch_CS,
	// Token: 0x040042FB RID: 17147
	ReqBattleMatch_SC,
	// Token: 0x040042FC RID: 17148
	ReqBattleCancelMatch_CS,
	// Token: 0x040042FD RID: 17149
	ReqBattleCancelMatch_SC,
	// Token: 0x040042FE RID: 17150
	RetMatchMember_SC,
	// Token: 0x040042FF RID: 17151
	RetBattleValid_SC,
	// Token: 0x04004300 RID: 17152
	ReqEnterBattle_CS,
	// Token: 0x04004301 RID: 17153
	ReqChangeGroupLeader_CS,
	// Token: 0x04004302 RID: 17154
	UserMatchReq_CS,
	// Token: 0x04004303 RID: 17155
	MatchReady_CS,
	// Token: 0x04004304 RID: 17156
	Req_ImportantBroadcast_CS,
	// Token: 0x04004305 RID: 17157
	Req_MailList_CS = 63002,
	// Token: 0x04004306 RID: 17158
	Ret_MailList_SC,
	// Token: 0x04004307 RID: 17159
	Ret_RefreshMail_SC,
	// Token: 0x04004308 RID: 17160
	Ret_RefreshMailState_SC,
	// Token: 0x04004309 RID: 17161
	Req_OpenMail_CS,
	// Token: 0x0400430A RID: 17162
	Req_GetAttachment_CS,
	// Token: 0x0400430B RID: 17163
	Ret_GetAttachment_SC,
	// Token: 0x0400430C RID: 17164
	Req_GetAllAttachment_CS,
	// Token: 0x0400430D RID: 17165
	Req_DeleteMail_CS,
	// Token: 0x0400430E RID: 17166
	Ret_DeleteMail_SC,
	// Token: 0x0400430F RID: 17167
	Req_DeleteAllMail_CS,
	// Token: 0x04004310 RID: 17168
	ReqSellStaff_CS,
	// Token: 0x04004311 RID: 17169
	RetSellStaff_SC,
	// Token: 0x04004312 RID: 17170
	ReqSellingStaff_CS,
	// Token: 0x04004313 RID: 17171
	RetSellingStaff_SC,
	// Token: 0x04004314 RID: 17172
	ReqRecommandPrice_CS,
	// Token: 0x04004315 RID: 17173
	RetRecommandPrice_SC,
	// Token: 0x04004316 RID: 17174
	ReqStopSellStaff_CS,
	// Token: 0x04004317 RID: 17175
	RetStopSellStaff_SC,
	// Token: 0x04004318 RID: 17176
	ReqSubSellingList_CS,
	// Token: 0x04004319 RID: 17177
	RetSubSellingList_SC,
	// Token: 0x0400431A RID: 17178
	ReqBuyItem_CS,
	// Token: 0x0400431B RID: 17179
	RetBuyItem_SC,
	// Token: 0x0400431C RID: 17180
	ReqTradeItemHistory_CS,
	// Token: 0x0400431D RID: 17181
	RetTradeItemHistory_SC,
	// Token: 0x0400431E RID: 17182
	ReqSublistPage_CS,
	// Token: 0x0400431F RID: 17183
	RetSublistPage_SC,
	// Token: 0x04004320 RID: 17184
	ReqWatchTradeItem_CS,
	// Token: 0x04004321 RID: 17185
	RetWatchTradeItem_SC,
	// Token: 0x04004322 RID: 17186
	ReqWatchList_CS,
	// Token: 0x04004323 RID: 17187
	RetWatchList_SC,
	// Token: 0x04004324 RID: 17188
	ReqUserTradeHistory_CS,
	// Token: 0x04004325 RID: 17189
	RetUserTradeHistory_SC,
	// Token: 0x04004326 RID: 17190
	ReqGetNewestStaff_CS,
	// Token: 0x04004327 RID: 17191
	RetGetNewestStaff_SC = 63035,
	// Token: 0x04004328 RID: 17192
	MAX_ID
};