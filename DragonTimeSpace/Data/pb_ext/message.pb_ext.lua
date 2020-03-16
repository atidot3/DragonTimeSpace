name = message.proto

package msg;

message CharacterBaseData {
    optional uint64 exp = 2;
    optional uint32 money = 3;
    optional uint32 welpoint = 4;
    optional uint32 tilizhi = 5;
    optional uint32 type = 6;
    optional uint32 famelevel = 7;
    optional uint32 position = 8;
    optional uint32 viplevel = 9;
    optional uint32 port = 10;
    optional uint32 laststage = 11;
    optional uint64 nextexp = 12;
    optional uint32 pkmode = 13;
    optional uint32 level = 14;
    optional uint32 stone = 15;
    optional uint32 edupoint = 16;
    optional uint32 cooppoint = 17;
    optional uint32 bluecrystal = 18;
    optional uint32 bluecrystalincnum = 19;
    optional uint32 purplecrystal = 20;
    optional uint32 purplecrystalincnum = 21;
    optional uint32 vigourpoint = 22;
    optional uint32 doublepoint = 23;
    optional uint32 familyatt = 24;
    optional string herothisid = 25;
}

message AttributeData {
    optional uint32 hp = 1;
    optional uint32 maxhp = 2;
    optional uint32 str = 3;
    optional uint32 dex = 4;
    optional uint32 intel = 5;
    optional uint32 phy = 6;
    optional uint32 matt = 7;
    optional uint32 patt = 8;
    optional uint32 mdef = 9;
    optional uint32 pdef = 10;
    optional uint32 bang = 11;
    optional uint32 bangextradamage = 12;
    optional uint32 toughness = 13;
    optional uint32 toughnessreducedamage = 14;
    optional uint32 penetrate = 15;
    optional uint32 penetrateextradamage = 16;
    optional uint32 block = 17;
    optional uint32 blockreducedamage = 18;
    optional uint32 accurate = 19;
    optional uint32 accurateextradamage = 20;
    optional uint32 hold = 21;
    optional uint32 holdreducedamage = 22;
    optional uint32 deflect = 23;
    optional uint32 deflectreducedamage = 24;
    optional uint32 dodge = 25;
    optional uint32 weaponatt = 26;
    optional uint32 mp = 27;
    optional uint32 maxmp = 28;
    optional uint32 hit = 29;
    optional uint32 firemastery = 30;
    optional uint32 icemastery = 31;
    optional uint32 lightningmastery = 32;
    optional uint32 brightmastery = 33;
    optional uint32 darkmastery = 34;
    optional uint32 fireresist = 35;
    optional uint32 iceresist = 36;
    optional uint32 lightningresist = 37;
    optional uint32 brightresist = 38;
    optional uint32 darkresist = 39;
    optional uint32 firepen = 40;
    optional uint32 icepen = 41;
    optional uint32 lightningpen = 42;
    optional uint32 brightpen = 43;
    optional uint32 darkpen = 44;
    optional uint32 blowint = 45;
    optional uint32 knockint = 46;
    optional uint32 floatint = 47;
    optional uint32 superhitint = 48;
    optional uint32 blowresist = 49;
    optional uint32 knockresist = 50;
    optional uint32 floatresist = 51;
    optional uint32 superhitresist = 52;
    optional uint32 blowdectime = 53;
    optional uint32 knockdectime = 54;
    optional uint32 floatdectime = 55;
    optional uint32 superhitdectime = 56;
    optional uint32 stiffaddtime = 57;
    optional uint32 stiffdectime = 58;
}

message CharacterFightData {
    optional uint32 curfightvalue = 1;
}

message CharacterMainData {
    optional CharacterBaseData basedata = 1;    // type_name = .msg.CharacterBaseData
    optional AttributeData attridata = 2;    // type_name = .msg.AttributeData
    optional MapUserData mapdata = 3;    // type_name = .msg.MapUserData
    optional CharacterFightData fightdata = 4;    // type_name = .msg.CharacterFightData
}

message CharacterMapShow {
    optional uint32 face = 1;
    optional uint32 weapon = 2;
    optional uint32 coat = 3;
    optional uint32 occupation = 4;
    optional uint32 heroid = 5;
    optional uint32 facestyle = 6;
    optional uint32 hairstyle = 7;
    optional uint32 haircolor = 8;
    optional uint32 antenna = 9;
    optional uint32 bodystyle = 10;
    optional uint32 avatarId = 11;
}

message CharacterMapData {
    optional uint32 level = 1;
    optional FloatMovePos pos = 2;    // type_name = .msg.FloatMovePos
    optional uint32 dir = 3;
    optional uint32 movespeed = 4;
    optional uint32 hp = 5;
    optional uint32 maxhp = 6;
    repeated StateItem states = 7;    // type_name = .msg.StateItem
    optional uint32 teamid = 8;
    optional uint64 guildid = 9;
    optional uint32 country = 10;
    optional string guildname = 11;
}

message StateItem {
    optional uint64 uniqid = 1;
    optional uint64 lasttime = 2;
    optional uint64 overtime = 3;
    optional uint64 settime = 4;
    optional uint64 configtime = 5;
    optional uint64 skilluuid = 6;
    repeated uint64 effects = 7;
}

message MapUserData {
    optional uint64 charid = 1;
    optional string name = 2;
    optional CharacterMapShow mapshow = 3;    // type_name = .msg.CharacterMapShow
    optional CharacterMapShow bakhero = 4;    // type_name = .msg.CharacterMapShow
    optional CharacterMapData mapdata = 5;    // type_name = .msg.CharacterMapData
}

message MasterData {
    optional EntryIDType idtype = 1;    // type_name = .msg.EntryIDType
    optional string name = 2;
    optional uint32 country = 3;
    optional uint64 guildid = 4;
    optional uint32 teamid = 5;
}

message MapNpcData {
    optional uint32 baseid = 1;
    optional uint64 tempid = 2;
    optional string name = 3;
    optional uint32 hp = 4;
    optional uint32 maxhp = 5;
    optional FloatMovePos pos = 6;    // type_name = .msg.FloatMovePos
    optional uint32 dir = 8;
    optional uint32 movespeed = 9;
    optional uint32 attspeed = 10;
    optional MasterData master = 11;    // type_name = .msg.MasterData
    optional uint32 visit = 12;
    repeated StateItem states = 13;    // type_name = .msg.StateItem
    optional CharacterMapShow showdata = 14;    // type_name = .msg.CharacterMapShow
    optional string titlename = 15;
    optional bool birth = 16 [default = false];
    optional NPC_HatredList hatredlist = 17;    // type_name = .msg.NPC_HatredList
}

message MSG_Create_Role_CS {
    optional string name = 1;
    optional uint32 occupation = 2;
    optional uint32 heroid = 3;
    required SEX sex = 4;    // type_name = .msg.SEX
    optional uint32 facestyle = 5;
    optional uint32 hairstyle = 6;
    optional uint32 haircolor = 7;
    optional uint32 antenna = 8;
}

message MSG_ChangeName_CS {
    optional string name = 1;
}

message MSG_Ret_ChangeName_SC {
    optional string name = 1;
    optional bool result = 2;
}

message MSG_DataCharacterMain_SC {
    optional CharacterMainData data = 1;    // type_name = .msg.CharacterMainData
}

message MSG_Req_Use_GM_CS {
    optional string strcontent = 1;
}

message MSG_Ret_Common_Error_SC {
    optional uint32 errorcode = 1;
}

message MSG_Ret_Common_Tips_SC {
    optional string strcontent = 1;
}

message MSG_Req_Main_Data_CS {
null
}

message MSG_Req_Test_Network_CS {
    optional uint32 num = 1;
    optional string name = 2;
    repeated uint32 num2 = 3;
}

message MSG_Ret_GameTime_SC {
    optional uint64 gametime = 1;
}

message MSG_Req_UserGameTime_SC {
null
}

message MSG_Ret_UserGameTime_CS {
    optional uint32 usertempid = 1;
    optional uint64 gametime = 2;
}

message MSG_Ret_ServerTime_SC {
    optional uint64 servertime = 1;
}

message MSG_Ret_NotifyUserKickout_SC {
null
}

message MSG_Ret_ServerLoginFailed_SC {
    optional uint32 returncode = 1;
}

message MSG_Ret_QueueInfo_SC {
    optional uint32 queue_user_num = 1;
    optional uint32 queue_wait_time = 2;
}

message MSG_Ret_UserMapInfo_SC {
    optional uint32 mapid = 1;
    optional string mapname = 2;
    optional string filename = 3;
    optional FloatMovePos pos = 4;    // type_name = .msg.FloatMovePos
    optional uint32 lineid = 5;
    optional uint32 copymapidx = 6;
    optional uint32 subcopymapidx = 7;
    optional uint64 sceneid = 8;
}

message MSG_Ret_NineScreenRefreshPlayer_SC {
    repeated MapUserData data = 1;    // type_name = .msg.MapUserData
}

message MSG_Ret_MapScreenRefreshCharacter_SC {
    optional MapUserData data = 1;    // type_name = .msg.MapUserData
}

message MSG_Ret_MapScreenRemoveCharacter_SC {
    optional uint64 charid = 1;
}

message MSG_Ret_MapScreenRemoveCharacterShowCorpse_SC {
    optional uint64 charid = 1;
}

message MSG_Ret_MapScreenBatchRemoveCharacter_SC {
    repeated uint64 charids = 1;
}

message MSG_Ret_StateList_SC {
    repeated StateItem states = 1;    // type_name = .msg.StateItem
}

message FloatMovePos {
    optional float fx = 1;
    optional float fy = 2;
}

message MoveData {
    optional FloatMovePos pos = 1;    // type_name = .msg.FloatMovePos
    optional uint32 dir = 4;
}

message MSG_Req_Move_CS {
    optional uint64 charid = 1;
    repeated MoveData movedata = 2;    // type_name = .msg.MoveData
    optional uint32 steplenth = 3;
}

message MSG_Ret_Move_SC {
    optional uint64 charid = 1;
    repeated MoveData movedata = 2;    // type_name = .msg.MoveData
    optional uint32 steplength = 3;
}

message MSG_Req_TELE_PORT_CS {
    required uint64 teleportid = 1;
}

message MSG_Server_Force_Move_SC {
    optional uint64 charid = 1;
    repeated MoveData movedata = 2;    // type_name = .msg.MoveData
    optional uint32 steplength = 3;
}

message MSG_Ret_Move_Failed_SC {
    optional uint64 charid = 1;
    optional MoveData movedata = 2;    // type_name = .msg.MoveData
    optional uint32 steplength = 3;
}

message MSG_Ret_SetState_SC {
    optional uint32 type = 1;
    optional uint64 id = 2;
    repeated StateItem state = 3;    // type_name = .msg.StateItem
}

message MSG_Ret_ClearState_SC {
    optional uint32 type = 1;
    optional uint64 id = 2;
    optional StateItem state = 3;    // type_name = .msg.StateItem
}

message MSG_Ret_MapScreenBatchRefreshNpc_SC {
    repeated MapNpcData data = 1;    // type_name = .msg.MapNpcData
}

message MSG_Ret_MapScreenBatchRemoveNpc_SC {
    repeated uint64 tempids = 1;
}

message MSG_Ret_MapScreenRefreshNpc_SC {
    optional MapNpcData data = 1;    // type_name = .msg.MapNpcData
}

message MSG_Ret_MapScreenRemoveNpc_SC {
    optional uint64 tempid = 1;
}

message FuncNpcData {
    optional uint32 baseid = 1;
    optional uint64 tempid = 2;
    optional uint32 x = 3;
    optional uint32 y = 4;
}

message MSG_Ret_MapScreenFuncNpc_SC {
    repeated FuncNpcData data = 1;    // type_name = .msg.FuncNpcData
}

message MSG_Ret_RetNpcMove_SC {
    optional uint64 tempid = 1;
    repeated MoveData movedata = 2;    // type_name = .msg.MoveData
    optional uint32 speed = 3;
}

message MSG_RetNpcWarpMove_SC {
    optional uint64 tempid = 1;
    optional MoveData movedata = 2;    // type_name = .msg.MoveData
}

message MSG_RetNpcDir_SC {
    optional uint64 tempid = 1;
    optional uint32 dir = 2;
}

message TempNpcInfo {
    optional uint32 npcid = 1;
    optional uint32 num = 2;
    optional uint32 script = 3;
}

message MSG_Req_Summon_Npc_CS {
    repeated TempNpcInfo npcs = 1;    // type_name = .msg.TempNpcInfo
}

message MSG_Ret_setTimeState_SC {
    optional EntryIDType target = 1;    // type_name = .msg.EntryIDType
    optional uint32 state = 2;
    optional uint32 maxtime = 3;
    optional uint32 lefttime = 4;
}

message MSG_Req_Ping_CS {
null
}

message MSG_Ret_VisibleNpcList_SC {
    repeated uint32 npc = 1;
}

message MSG_RetNinePlayerLevelUp_SC {
    optional EntryIDType target = 1;    // type_name = .msg.EntryIDType
}

message MSG_UpdateExpLevel_SC {
    optional uint32 curexp = 1;
    optional uint32 curlevel = 2;
    optional uint64 mainhero_thisid = 3;
    optional uint64 mainhero_exp = 4;
    optional uint32 mainhero_lv = 5;
}

message MSG_NotifyAntiAddict_SC {
    optional uint32 onlinelasttime = 1;
    optional bool isAntiAddcit = 2;
    optional bool isLoginPush = 3;
}

message MSG_ReqUpdateAntiAddict_CS {
null
}

message MSG_ReqEntrySelectState_CS {
    optional EntryIDType oldone = 1;    // type_name = .msg.EntryIDType
    optional EntryIDType newone = 2;    // type_name = .msg.EntryIDType
}

message MSG_RetEntrySelectState_SC {
    optional EntryIDType choosen = 1;    // type_name = .msg.EntryIDType
    repeated StateItem states = 2;    // type_name = .msg.StateItem
}

message MSG_RetHpMpToSelects_SC {
    optional EntryIDType choosen = 1;    // type_name = .msg.EntryIDType
    optional uint32 curhp = 2;
    optional uint32 maxhp = 3;
    optional uint32 curmp = 4;
    optional uint32 maxmp = 5;
}

message MSG_ReqHeroAttributeData_CS {
    optional string herothisid = 1;
}

message MSG_RetHeroAttributeData_SC {
    optional string herothisid = 1;
    optional AttributeData data = 2;    // type_name = .msg.AttributeData
    optional uint32 fightvalue = 3;
}

message MSG_RetDiffLineOfLeader_SC {
null
}

message MSG_ReqJumptoLeaderLine_CS {
null
}

message SelectUserInfo {
    optional uint64 charid = 1;
    optional string name = 2;
    optional uint32 level = 3;
    required SEX sex = 4;    // type_name = .msg.SEX
    optional uint32 heroid = 5;
    optional uint32 curheroid = 6;
    optional uint32 delTime = 7;
    optional uint32 offlinetime = 8;
    optional uint32 facestyle = 9;
    optional uint32 hairstyle = 10;
    optional uint32 haircolor = 11;
    optional uint32 bodystyle = 12;
    optional uint32 antenna = 13;
    optional uint32 onlinelasttime = 14;
    optional uint32 addictpreuptime = 15;
    optional string mapname = 16;
    optional uint32 avatarid = 17;
}

message MSG_Ret_LoginOnReturnCharList_SC {
    repeated SelectUserInfo charList = 1;    // type_name = .msg.SelectUserInfo
}

message MSG_Req_SelectCharToLogin_CS {
    optional uint64 charid = 1;
}

message MSG_Req_IS_NICKNAME_REPEATED_CSC {
    optional string name = 1;
    optional uint32 ret = 2;
}

message MSG_Req_Back_to_Select_CS {
null
}

message MSG_Req_Delete_Char_CSC {
    optional uint64 charid = 1;
    optional uint32 opcode = 2;
    optional uint32 retcode = 3;
}

message MSG_Req_Syn_MoveState_CS {
    optional uint32 move_state = 1;
    optional uint32 dir = 2;
    optional uint32 destx = 3;
    optional uint32 desty = 4;
    optional uint32 movespeed = 5;
    optional uint32 step = 6;
    optional uint32 srcx = 7;
    optional uint32 srcy = 8;
    repeated FloatMovePos pos = 9;    // type_name = .msg.FloatMovePos
}

message MSG_Ret_Find_Path_SC {
    optional uint64 charid = 1;
    optional uint32 gridindex = 2;
    optional uint32 moveres = 3;
}

message MSG_Ret_Rondom_Way_SC {
    optional uint32 zonecenterx = 1;
    optional uint32 zonecentery = 2;
    optional uint32 zonewidth = 3;
    optional uint32 zoneheight = 4;
    optional uint32 gridwidth = 5;
    optional uint32 gridheight = 6;
    optional uint32 pathid = 7;
    optional string pathinfo = 8;
}

message MSG_Ret_Find_Path_End_SC {
    optional uint32 endcode = 1;
}

message MSG_Show_Path_Way_End_CS {
null
}

message LineItem {
    optional uint32 index = 1;
    optional uint32 user_num = 2;
}

message MSG_NoticeClientAllLines_SC {
    repeated LineItem lines = 1;    // type_name = .msg.LineItem
    optional uint32 your_line = 2;
}

message MSG_UserReqChangeLine_CS {
    optional uint32 lineid = 1;
}

message MSG_OnUserJump_CSC {
    optional MoveData data = 1;    // type_name = .msg.MoveData
    optional uint64 charid = 2;
}

message MSG_NPCHatredList_SC {
    optional uint64 npctempid = 1;
    repeated uint64 enemytempid = 2;
}

message NPC_HatredList {
    optional uint64 npctempid = 1;
    repeated uint64 enemytempid = 2;
}

message MSG_ACCOUNT_SEC_PASSWD_SC {
    optional string sec_passwd = 1;
    optional bool isonline = 2;
}

message MSG_USER_REQ_SETPASSWD_CS {
    optional string old_passwd = 1;
    optional string new_passwd = 2;
}

message MSG_NEW_ROLE_CUTSCENE_SCS {
null
}

message MSG_User_Drop_SCS {
    optional uint64 charid = 1;
}

message MSG_START_CUTSCENE_SC {
    optional uint32 cutsceneid = 1;
    optional string onfinish = 2;
}

message MSG_UserLoadingOk_CS {
null
}

message MSG_ReqQueryBalance_CS {
null
}

message MSG_RetQueryBalance_SC {
    required ERechargeReturnCode retcode = 1;    // type_name = .msg.ERechargeReturnCode
    optional uint32 balance = 2;
    optional uint32 bonus = 3;
    optional uint32 hadfilled = 4;
    optional uint32 point2tone = 5;
}

message MSG_ReqRecharge_CS {
    optional uint32 point = 1;
    optional uint32 type = 2;
}

message MSG_RetRecharge_SC {
    required ERechargeReturnCode retcode = 1;    // type_name = .msg.ERechargeReturnCode
    optional uint32 point = 2;
    optional uint32 balance = 3;
    optional uint32 bonus = 4;
    optional uint32 hadfilled = 5;
}

message MSG_SetChooseTarget_CS {
    optional uint64 charid = 1;
    optional ChooseTargetType choosetype = 2;    // type_name = .msg.ChooseTargetType
    required MapDataType mapdatatype = 3;    // type_name = .msg.MapDataType
}

message MSG_AttackTargetChange_SC {
    optional uint64 charid = 1;
    optional string name = 2;
    optional uint32 level = 3;
    optional uint32 HP = 4;
    optional uint32 relation = 5;
    optional ChooseTargetType choosetype = 6;    // type_name = .msg.ChooseTargetType
}

message MSG_NotifyAccountReuse {
null
}

message MSG_Notify_SceneLoaded_CS {
    optional uint64 sceneid = 1;
}

message MSG_Upload_Crash_Info {
    optional uint32 crashnum = 1;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "ChooseTargetType",
        ["value"] = {
            [1] = {
                ["name"] = "CHOOSE_TARGE_TTYPE_SET",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "CHOOSE_TARGE_TTYPE_CANCEL",
                ["number"] = 2
            }
        }
    }
},
["package"] = "msg",
["name"] = "message.proto",
["dependency"] = {
    [1] = "msg_enum.proto"
},
["message_type"] = {
    [1] = {
        ["name"] = "CharacterBaseData",
        ["field"] = {
            [1] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "exp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "money",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "welpoint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "tilizhi",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "famelevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "position",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "viplevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "port",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "laststage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT64",
                ["name"] = "nextexp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 13,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pkmode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 14,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [14] = {
                ["number"] = 15,
                ["type"] = "TYPE_UINT32",
                ["name"] = "stone",
                ["label"] = "LABEL_OPTIONAL"
            },
            [15] = {
                ["number"] = 16,
                ["type"] = "TYPE_UINT32",
                ["name"] = "edupoint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [16] = {
                ["number"] = 17,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cooppoint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [17] = {
                ["number"] = 18,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bluecrystal",
                ["label"] = "LABEL_OPTIONAL"
            },
            [18] = {
                ["number"] = 19,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bluecrystalincnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [19] = {
                ["number"] = 20,
                ["type"] = "TYPE_UINT32",
                ["name"] = "purplecrystal",
                ["label"] = "LABEL_OPTIONAL"
            },
            [20] = {
                ["number"] = 21,
                ["type"] = "TYPE_UINT32",
                ["name"] = "purplecrystalincnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [21] = {
                ["number"] = 22,
                ["type"] = "TYPE_UINT32",
                ["name"] = "vigourpoint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [22] = {
                ["number"] = 23,
                ["type"] = "TYPE_UINT32",
                ["name"] = "doublepoint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [23] = {
                ["number"] = 24,
                ["type"] = "TYPE_UINT32",
                ["name"] = "familyatt",
                ["label"] = "LABEL_OPTIONAL"
            },
            [24] = {
                ["number"] = 25,
                ["type"] = "TYPE_STRING",
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "AttributeData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxhp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "str",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dex",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "intel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "phy",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "matt",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "patt",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mdef",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pdef",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bang",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bangextradamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 13,
                ["type"] = "TYPE_UINT32",
                ["name"] = "toughness",
                ["label"] = "LABEL_OPTIONAL"
            },
            [14] = {
                ["number"] = 14,
                ["type"] = "TYPE_UINT32",
                ["name"] = "toughnessreducedamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [15] = {
                ["number"] = 15,
                ["type"] = "TYPE_UINT32",
                ["name"] = "penetrate",
                ["label"] = "LABEL_OPTIONAL"
            },
            [16] = {
                ["number"] = 16,
                ["type"] = "TYPE_UINT32",
                ["name"] = "penetrateextradamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [17] = {
                ["number"] = 17,
                ["type"] = "TYPE_UINT32",
                ["name"] = "block",
                ["label"] = "LABEL_OPTIONAL"
            },
            [18] = {
                ["number"] = 18,
                ["type"] = "TYPE_UINT32",
                ["name"] = "blockreducedamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [19] = {
                ["number"] = 19,
                ["type"] = "TYPE_UINT32",
                ["name"] = "accurate",
                ["label"] = "LABEL_OPTIONAL"
            },
            [20] = {
                ["number"] = 20,
                ["type"] = "TYPE_UINT32",
                ["name"] = "accurateextradamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [21] = {
                ["number"] = 21,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hold",
                ["label"] = "LABEL_OPTIONAL"
            },
            [22] = {
                ["number"] = 22,
                ["type"] = "TYPE_UINT32",
                ["name"] = "holdreducedamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [23] = {
                ["number"] = 23,
                ["type"] = "TYPE_UINT32",
                ["name"] = "deflect",
                ["label"] = "LABEL_OPTIONAL"
            },
            [24] = {
                ["number"] = 24,
                ["type"] = "TYPE_UINT32",
                ["name"] = "deflectreducedamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [25] = {
                ["number"] = 25,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dodge",
                ["label"] = "LABEL_OPTIONAL"
            },
            [26] = {
                ["number"] = 26,
                ["type"] = "TYPE_UINT32",
                ["name"] = "weaponatt",
                ["label"] = "LABEL_OPTIONAL"
            },
            [27] = {
                ["number"] = 27,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [28] = {
                ["number"] = 28,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxmp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [29] = {
                ["number"] = 29,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hit",
                ["label"] = "LABEL_OPTIONAL"
            },
            [30] = {
                ["number"] = 30,
                ["type"] = "TYPE_UINT32",
                ["name"] = "firemastery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [31] = {
                ["number"] = 31,
                ["type"] = "TYPE_UINT32",
                ["name"] = "icemastery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [32] = {
                ["number"] = 32,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lightningmastery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [33] = {
                ["number"] = 33,
                ["type"] = "TYPE_UINT32",
                ["name"] = "brightmastery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [34] = {
                ["number"] = 34,
                ["type"] = "TYPE_UINT32",
                ["name"] = "darkmastery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [35] = {
                ["number"] = 35,
                ["type"] = "TYPE_UINT32",
                ["name"] = "fireresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [36] = {
                ["number"] = 36,
                ["type"] = "TYPE_UINT32",
                ["name"] = "iceresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [37] = {
                ["number"] = 37,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lightningresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [38] = {
                ["number"] = 38,
                ["type"] = "TYPE_UINT32",
                ["name"] = "brightresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [39] = {
                ["number"] = 39,
                ["type"] = "TYPE_UINT32",
                ["name"] = "darkresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [40] = {
                ["number"] = 40,
                ["type"] = "TYPE_UINT32",
                ["name"] = "firepen",
                ["label"] = "LABEL_OPTIONAL"
            },
            [41] = {
                ["number"] = 41,
                ["type"] = "TYPE_UINT32",
                ["name"] = "icepen",
                ["label"] = "LABEL_OPTIONAL"
            },
            [42] = {
                ["number"] = 42,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lightningpen",
                ["label"] = "LABEL_OPTIONAL"
            },
            [43] = {
                ["number"] = 43,
                ["type"] = "TYPE_UINT32",
                ["name"] = "brightpen",
                ["label"] = "LABEL_OPTIONAL"
            },
            [44] = {
                ["number"] = 44,
                ["type"] = "TYPE_UINT32",
                ["name"] = "darkpen",
                ["label"] = "LABEL_OPTIONAL"
            },
            [45] = {
                ["number"] = 45,
                ["type"] = "TYPE_UINT32",
                ["name"] = "blowint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [46] = {
                ["number"] = 46,
                ["type"] = "TYPE_UINT32",
                ["name"] = "knockint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [47] = {
                ["number"] = 47,
                ["type"] = "TYPE_UINT32",
                ["name"] = "floatint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [48] = {
                ["number"] = 48,
                ["type"] = "TYPE_UINT32",
                ["name"] = "superhitint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [49] = {
                ["number"] = 49,
                ["type"] = "TYPE_UINT32",
                ["name"] = "blowresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [50] = {
                ["number"] = 50,
                ["type"] = "TYPE_UINT32",
                ["name"] = "knockresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [51] = {
                ["number"] = 51,
                ["type"] = "TYPE_UINT32",
                ["name"] = "floatresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [52] = {
                ["number"] = 52,
                ["type"] = "TYPE_UINT32",
                ["name"] = "superhitresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [53] = {
                ["number"] = 53,
                ["type"] = "TYPE_UINT32",
                ["name"] = "blowdectime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [54] = {
                ["number"] = 54,
                ["type"] = "TYPE_UINT32",
                ["name"] = "knockdectime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [55] = {
                ["number"] = 55,
                ["type"] = "TYPE_UINT32",
                ["name"] = "floatdectime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [56] = {
                ["number"] = 56,
                ["type"] = "TYPE_UINT32",
                ["name"] = "superhitdectime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [57] = {
                ["number"] = 57,
                ["type"] = "TYPE_UINT32",
                ["name"] = "stiffaddtime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [58] = {
                ["number"] = 58,
                ["type"] = "TYPE_UINT32",
                ["name"] = "stiffdectime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "CharacterFightData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curfightvalue",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "CharacterMainData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.CharacterBaseData",
                ["name"] = "basedata"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.AttributeData",
                ["name"] = "attridata"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MapUserData",
                ["name"] = "mapdata"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.CharacterFightData",
                ["name"] = "fightdata"
            }
        }
    },
    [5] = {
        ["name"] = "CharacterMapShow",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "face",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "weapon",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "coat",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "occupation",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "facestyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hairstyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "haircolor",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "antenna",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bodystyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "avatarId",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "CharacterMapData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.FloatMovePos",
                ["name"] = "pos"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "movespeed",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxhp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.StateItem",
                ["name"] = "states"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "teamid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT64",
                ["name"] = "guildid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "country",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_STRING",
                ["name"] = "guildname",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "StateItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "uniqid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "lasttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT64",
                ["name"] = "overtime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT64",
                ["name"] = "settime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT64",
                ["name"] = "configtime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT64",
                ["name"] = "skilluuid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT64",
                ["name"] = "effects",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [8] = {
        ["name"] = "MapUserData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.CharacterMapShow",
                ["name"] = "mapshow"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.CharacterMapShow",
                ["name"] = "bakhero"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.CharacterMapData",
                ["name"] = "mapdata"
            }
        }
    },
    [9] = {
        ["name"] = "MasterData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "idtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "country",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT64",
                ["name"] = "guildid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "teamid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MapNpcData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "baseid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxhp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.FloatMovePos",
                ["name"] = "pos"
            },
            [7] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "movespeed",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "attspeed",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 11,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MasterData",
                ["name"] = "master"
            },
            [11] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT32",
                ["name"] = "visit",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 13,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.StateItem",
                ["name"] = "states"
            },
            [13] = {
                ["number"] = 14,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.CharacterMapShow",
                ["name"] = "showdata"
            },
            [14] = {
                ["number"] = 15,
                ["type"] = "TYPE_STRING",
                ["name"] = "titlename",
                ["label"] = "LABEL_OPTIONAL"
            },
            [15] = {
                ["number"] = 16,
                ["default_value"] = "false",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "birth"
            },
            [16] = {
                ["number"] = 17,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.NPC_HatredList",
                ["name"] = "hatredlist"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_Create_Role_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "occupation",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.SEX",
                ["name"] = "sex"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "facestyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hairstyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "haircolor",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "antenna",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_ChangeName_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_Ret_ChangeName_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_DataCharacterMain_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.CharacterMainData",
                ["name"] = "data"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_Req_Use_GM_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "strcontent",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_Ret_Common_Error_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errorcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_Ret_Common_Tips_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "strcontent",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_Req_Main_Data_CS"
    },
    [19] = {
        ["name"] = "MSG_Req_Test_Network_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num2",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_Ret_GameTime_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "gametime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_Req_UserGameTime_SC"
    },
    [22] = {
        ["name"] = "MSG_Ret_UserGameTime_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "usertempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "gametime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [23] = {
        ["name"] = "MSG_Ret_ServerTime_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "servertime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_Ret_NotifyUserKickout_SC"
    },
    [25] = {
        ["name"] = "MSG_Ret_ServerLoginFailed_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "returncode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [26] = {
        ["name"] = "MSG_Ret_QueueInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "queue_user_num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "queue_wait_time",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [27] = {
        ["name"] = "MSG_Ret_UserMapInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mapid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "mapname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "filename",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.FloatMovePos",
                ["name"] = "pos"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lineid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "copymapidx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "subcopymapidx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT64",
                ["name"] = "sceneid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [28] = {
        ["name"] = "MSG_Ret_NineScreenRefreshPlayer_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MapUserData",
                ["name"] = "data"
            }
        }
    },
    [29] = {
        ["name"] = "MSG_Ret_MapScreenRefreshCharacter_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MapUserData",
                ["name"] = "data"
            }
        }
    },
    [30] = {
        ["name"] = "MSG_Ret_MapScreenRemoveCharacter_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [31] = {
        ["name"] = "MSG_Ret_MapScreenRemoveCharacterShowCorpse_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [32] = {
        ["name"] = "MSG_Ret_MapScreenBatchRemoveCharacter_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charids",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [33] = {
        ["name"] = "MSG_Ret_StateList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.StateItem",
                ["name"] = "states"
            }
        }
    },
    [34] = {
        ["name"] = "FloatMovePos",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "fx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "fy",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [35] = {
        ["name"] = "MoveData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.FloatMovePos",
                ["name"] = "pos"
            },
            [2] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dir",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [36] = {
        ["name"] = "MSG_Req_Move_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MoveData",
                ["name"] = "movedata"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "steplenth",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [37] = {
        ["name"] = "MSG_Ret_Move_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MoveData",
                ["name"] = "movedata"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "steplength",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [38] = {
        ["name"] = "MSG_Req_TELE_PORT_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "teleportid",
                ["label"] = "LABEL_REQUIRED"
            }
        }
    },
    [39] = {
        ["name"] = "MSG_Server_Force_Move_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MoveData",
                ["name"] = "movedata"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "steplength",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [40] = {
        ["name"] = "MSG_Ret_Move_Failed_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MoveData",
                ["name"] = "movedata"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "steplength",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [41] = {
        ["name"] = "MSG_Ret_SetState_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.StateItem",
                ["name"] = "state"
            }
        }
    },
    [42] = {
        ["name"] = "MSG_Ret_ClearState_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.StateItem",
                ["name"] = "state"
            }
        }
    },
    [43] = {
        ["name"] = "MSG_Ret_MapScreenBatchRefreshNpc_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MapNpcData",
                ["name"] = "data"
            }
        }
    },
    [44] = {
        ["name"] = "MSG_Ret_MapScreenBatchRemoveNpc_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempids",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [45] = {
        ["name"] = "MSG_Ret_MapScreenRefreshNpc_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MapNpcData",
                ["name"] = "data"
            }
        }
    },
    [46] = {
        ["name"] = "MSG_Ret_MapScreenRemoveNpc_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [47] = {
        ["name"] = "FuncNpcData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "baseid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "x",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "y",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [48] = {
        ["name"] = "MSG_Ret_MapScreenFuncNpc_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.FuncNpcData",
                ["name"] = "data"
            }
        }
    },
    [49] = {
        ["name"] = "MSG_Ret_RetNpcMove_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MoveData",
                ["name"] = "movedata"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "speed",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [50] = {
        ["name"] = "MSG_RetNpcWarpMove_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MoveData",
                ["name"] = "movedata"
            }
        }
    },
    [51] = {
        ["name"] = "MSG_RetNpcDir_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dir",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [52] = {
        ["name"] = "TempNpcInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "npcid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "script",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [53] = {
        ["name"] = "MSG_Req_Summon_Npc_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.TempNpcInfo",
                ["name"] = "npcs"
            }
        }
    },
    [54] = {
        ["name"] = "MSG_Ret_setTimeState_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "target"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "state",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxtime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lefttime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [55] = {
        ["name"] = "MSG_Req_Ping_CS"
    },
    [56] = {
        ["name"] = "MSG_Ret_VisibleNpcList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "npc",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [57] = {
        ["name"] = "MSG_RetNinePlayerLevelUp_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "target"
            }
        }
    },
    [58] = {
        ["name"] = "MSG_UpdateExpLevel_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curexp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT64",
                ["name"] = "mainhero_thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT64",
                ["name"] = "mainhero_exp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mainhero_lv",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [59] = {
        ["name"] = "MSG_NotifyAntiAddict_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "onlinelasttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isAntiAddcit",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isLoginPush",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [60] = {
        ["name"] = "MSG_ReqUpdateAntiAddict_CS"
    },
    [61] = {
        ["name"] = "MSG_ReqEntrySelectState_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "oldone"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "newone"
            }
        }
    },
    [62] = {
        ["name"] = "MSG_RetEntrySelectState_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "choosen"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.StateItem",
                ["name"] = "states"
            }
        }
    },
    [63] = {
        ["name"] = "MSG_RetHpMpToSelects_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "choosen"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curhp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxhp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curmp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxmp",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [64] = {
        ["name"] = "MSG_ReqHeroAttributeData_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [65] = {
        ["name"] = "MSG_RetHeroAttributeData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.AttributeData",
                ["name"] = "data"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "fightvalue",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [66] = {
        ["name"] = "MSG_RetDiffLineOfLeader_SC"
    },
    [67] = {
        ["name"] = "MSG_ReqJumptoLeaderLine_CS"
    },
    [68] = {
        ["name"] = "SelectUserInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.SEX",
                ["name"] = "sex"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curheroid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "delTime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "offlinetime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "facestyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hairstyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "haircolor",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bodystyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 13,
                ["type"] = "TYPE_UINT32",
                ["name"] = "antenna",
                ["label"] = "LABEL_OPTIONAL"
            },
            [14] = {
                ["number"] = 14,
                ["type"] = "TYPE_UINT32",
                ["name"] = "onlinelasttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [15] = {
                ["number"] = 15,
                ["type"] = "TYPE_UINT32",
                ["name"] = "addictpreuptime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [16] = {
                ["number"] = 16,
                ["type"] = "TYPE_STRING",
                ["name"] = "mapname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [17] = {
                ["number"] = 17,
                ["type"] = "TYPE_UINT32",
                ["name"] = "avatarid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [69] = {
        ["name"] = "MSG_Ret_LoginOnReturnCharList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.SelectUserInfo",
                ["name"] = "charList"
            }
        }
    },
    [70] = {
        ["name"] = "MSG_Req_SelectCharToLogin_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [71] = {
        ["name"] = "MSG_Req_IS_NICKNAME_REPEATED_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "ret",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [72] = {
        ["name"] = "MSG_Req_Back_to_Select_CS"
    },
    [73] = {
        ["name"] = "MSG_Req_Delete_Char_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "opcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [74] = {
        ["name"] = "MSG_Req_Syn_MoveState_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "move_state",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "destx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "desty",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "movespeed",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "step",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "srcx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "srcy",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.FloatMovePos",
                ["name"] = "pos"
            }
        }
    },
    [75] = {
        ["name"] = "MSG_Ret_Find_Path_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "gridindex",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "moveres",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [76] = {
        ["name"] = "MSG_Ret_Rondom_Way_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "zonecenterx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "zonecentery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "zonewidth",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "zoneheight",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "gridwidth",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "gridheight",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pathid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_STRING",
                ["name"] = "pathinfo",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [77] = {
        ["name"] = "MSG_Ret_Find_Path_End_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "endcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [78] = {
        ["name"] = "MSG_Show_Path_Way_End_CS"
    },
    [79] = {
        ["name"] = "LineItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "index",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "user_num",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [80] = {
        ["name"] = "MSG_NoticeClientAllLines_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.LineItem",
                ["name"] = "lines"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "your_line",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [81] = {
        ["name"] = "MSG_UserReqChangeLine_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lineid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [82] = {
        ["name"] = "MSG_OnUserJump_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.MoveData",
                ["name"] = "data"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [83] = {
        ["name"] = "MSG_NPCHatredList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "npctempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "enemytempid",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [84] = {
        ["name"] = "NPC_HatredList",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "npctempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "enemytempid",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [85] = {
        ["name"] = "MSG_ACCOUNT_SEC_PASSWD_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "sec_passwd",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isonline",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [86] = {
        ["name"] = "MSG_USER_REQ_SETPASSWD_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "old_passwd",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "new_passwd",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [87] = {
        ["name"] = "MSG_NEW_ROLE_CUTSCENE_SCS"
    },
    [88] = {
        ["name"] = "MSG_User_Drop_SCS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [89] = {
        ["name"] = "MSG_START_CUTSCENE_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cutsceneid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "onfinish",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [90] = {
        ["name"] = "MSG_UserLoadingOk_CS"
    },
    [91] = {
        ["name"] = "MSG_ReqQueryBalance_CS"
    },
    [92] = {
        ["name"] = "MSG_RetQueryBalance_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.ERechargeReturnCode",
                ["name"] = "retcode"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "balance",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bonus",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hadfilled",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "point2tone",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [93] = {
        ["name"] = "MSG_ReqRecharge_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "point",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [94] = {
        ["name"] = "MSG_RetRecharge_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.ERechargeReturnCode",
                ["name"] = "retcode"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "point",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "balance",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bonus",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hadfilled",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [95] = {
        ["name"] = "MSG_SetChooseTarget_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.ChooseTargetType",
                ["name"] = "choosetype"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MapDataType",
                ["name"] = "mapdatatype"
            }
        }
    },
    [96] = {
        ["name"] = "MSG_AttackTargetChange_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "HP",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "relation",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.ChooseTargetType",
                ["name"] = "choosetype"
            }
        }
    },
    [97] = {
        ["name"] = "MSG_NotifyAccountReuse"
    },
    [98] = {
        ["name"] = "MSG_Notify_SceneLoaded_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "sceneid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [99] = {
        ["name"] = "MSG_Upload_Crash_Info",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "crashnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
}

----- end of proto -----
