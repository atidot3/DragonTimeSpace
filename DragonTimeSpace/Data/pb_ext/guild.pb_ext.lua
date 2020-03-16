name = guild.proto

package guild;

message guildMember {
    optional uint64 memberid = 1;
    optional string membername = 2;
    optional uint32 memberlevel = 3;
    optional uint32 memberstatus = 4;
    optional uint32 contribute = 5;
    optional uint32 donatesalary = 6;
    optional bool isonline = 7;
    optional uint32 lastonlinetime = 8;
    optional uint32 career = 9;
    optional uint32 positionid = 10;
    optional uint32 applytime = 11;
}

message guildInfo {
    optional uint64 guildid = 1;
    optional string guildname = 2;
    optional uint32 guildlevel = 3;
    optional uint32 active = 4;
    optional string mastername = 5;
    optional uint32 exp = 6;
    optional uint32 nextexp = 7;
    optional uint32 salary = 8;
    optional uint32 sumcount = 9;
    optional uint32 onlinecount = 10;
    optional uint32 countlimit = 11;
    optional string notify = 12;
    optional uint32 countryid = 13;
    optional uint32 rank = 14;
    repeated GuildPositionInfo posinfo = 15;    // type_name = .guild.GuildPositionInfo
    optional string guildsetinfo = 16;
    optional uint32 lastactive = 17;
    optional uint32 lastcountlimit = 18;
    optional string icon = 19;
    optional uint32 salary_rest_day = 20;
}

message MSG_Req_PreCreateGuild_CS {
null
}

message MSG_Ret_PreCreateGuild_SC {
    optional uint32 cost_objid = 1;
    optional uint32 cost_objnum = 2;
}

message MSG_Req_CreateGuild_CS {
    optional string guildname = 1;
    optional string icon = 2;
}

message MSG_Ret_CreateGuild_SC {
    optional string guildname = 1;
    optional bool issucc = 2;
}

message MSG_Req_SetGuildNotify_CS {
    optional string notify = 3;
}

message MSG_Ret_SetGuildNotify_SC {
    optional bool issucc = 1;
}

message MSG_Req_GuildInfo_CS {
    optional uint64 guildid = 1;
}

message MSG_Ret_GuildInfo_SC {
    optional guildInfo guildinfo = 1;    // type_name = .guild.guildInfo
    optional guildMember myinfo = 2;    // type_name = .guild.guildMember
}

message MSG_Req_GuildList_CS {
    required uint32 page = 1;
    optional uint32 countryid = 2;
}

message guildListItem {
    optional guildInfo guild = 1;    // type_name = .guild.guildInfo
    optional uint32 guildtype = 2;
}

message MSG_Ret_GuildList_SC {
    repeated guildListItem guildList = 1;    // type_name = .guild.guildListItem
    optional uint32 allpage = 2;
    optional uint32 page = 3;
    optional uint32 countryid = 4;
}

message MSG_Req_ApplyForGuild_CS {
    optional uint64 guildid = 1;
    optional bool flag = 2;
}

message MSG_Ret_ApplyForGuild_SC {
    optional uint64 guildid = 1;
    optional bool issucc = 2;
    optional bool flag = 3;
}

message stApplyForItem {
    optional uint64 applyid = 1;
    optional string applyname = 2;
    optional bool issucc = 3 [default = false];
}

message MSG_Req_AnswerApplyForGuild_CS {
    repeated stApplyForItem applyinfo = 1;    // type_name = .guild.stApplyForItem
    optional bool accept = 2;
}

message MSG_Ret_AnswerApplyForGuild_SC {
    repeated stApplyForItem retlist = 1;    // type_name = .guild.stApplyForItem
}

message MSG_Ret_MyGuildApply_Result_SC {
    optional stApplyForItem result = 1;    // type_name = .guild.stApplyForItem
}

message MSG_Req_GuildMemberList_CS {
    required uint32 page = 1;
    optional ReqMemberListType reqtype = 2;    // type_name = .guild.ReqMemberListType
}

message MSG_Ret_GuildMemberList_SC {
    optional guildInfo guildinfo = 1;    // type_name = .guild.guildInfo
    repeated guildMember members = 2;    // type_name = .guild.guildMember
    optional ReqMemberListType reqtype = 3;    // type_name = .guild.ReqMemberListType
    optional uint32 page = 4;
    optional uint32 allpage = 5;
}

message MSG_Req_IntoGuildMap_CS {
null
}

message MSG_Req_CiTanEnemyGuildList_CS {
null
}

message CiTanEnemyGuildItem {
    optional uint64 guildid = 1;
    optional uint32 guildlevel = 2;
    optional string guildname = 3;
    optional string mastername = 4;
    optional uint32 isvalid = 5;
}

message MSG_Ret_CiTanEnemyGuildList_SC {
    repeated CiTanEnemyGuildItem guildlist = 1;    // type_name = .guild.CiTanEnemyGuildItem
}

message MSG_Req_ChooseCiTanEnemyGuild_CS {
    optional uint64 guildid = 1;
}

message MSG_Req_TargetCiTanEnemyGuild_CS {
null
}

message MSG_Ret_ChoosedCiTanEnemyGuild_SC {
    optional CiTanEnemyGuildItem guild = 1;    // type_name = .guild.CiTanEnemyGuildItem
}

message MSG_Req_IntoCiTanEnemyGuild_CS {
null
}

message MSG_Req_CiTanBacktoMyGuild_CS {
null
}

message GuildPositionInfo {
    optional uint32 positionid = 1;
    optional string name = 2;
    optional uint32 orderid = 3;
    optional uint32 privilege = 4;
}

message MSG_Req_AddGuildPosition_CS {
    optional GuildPositionInfo posinfo = 1;    // type_name = .guild.GuildPositionInfo
}

message MSG_Req_DeleteGuildPosition_CS {
    optional uint32 positionid = 1;
}

message SwapGuildPosInfo {
    optional uint32 posidfrom = 1;
    optional uint32 posidto = 2;
}

message MSG_Req_SwapGuildPosOrder_CS {
    optional SwapGuildPosInfo swapinfo = 1;    // type_name = .guild.SwapGuildPosInfo
}

message MSG_Req_ChangePositionName_CS {
    optional uint32 positionid = 1;
    optional string name = 2;
}

message MSG_Req_ChangePositionPri_CS {
    optional uint32 positionid = 1;
    optional uint32 privilege = 2;
}

message MSG_Req_AssignPosition_CS {
    optional uint64 memberid = 1;
    optional uint32 positionid = 2;
}

message MSG_Ret_AssignPosition_SC {
    optional uint64 memberid = 1;
    optional uint32 positionid = 2;
}

message MSG_Ret_PositionInfo_SC {
    repeated GuildPositionInfo posinfos = 1;    // type_name = .guild.GuildPositionInfo
}

message MSG_Req_GuildLevelup_CS {
null
}

message MSG_Ret_GuildLevelup_SC {
    optional uint32 retcode = 1;
}

message MSG_Req_GuildSetInfo_CS {
    optional string guildsetinfo = 1;
}

message MSG_Ret_GuildSetInfo_SC {
    optional uint32 retcode = 1;
}

message MSG_Ret_CheckDayWelfare_SC {
    optional bool canreceive = 1;
}

message MSG_Req_GetDayWelfare_CS {
null
}

message MSG_Ret_GetDayWelfare_SC {
    optional uint32 retcode = 1;
}

message MSG_Req_GuildGoods_CS {
    optional uint32 goodstype = 1;
}

message GoodsInfo {
    optional uint32 tagid = 1;
    optional uint32 itemid = 2;
    optional uint32 submitnum = 3;
    optional uint32 award = 4;
}

message MSG_Ret_GuildGoods_SC {
    repeated GoodsInfo items = 1;    // type_name = .guild.GoodsInfo
    optional uint32 multireward = 2;
    optional uint32 remain = 3;
    optional uint32 nexttime = 4;
    optional uint32 goodstype = 5;
}

message MSG_Req_SubmitGuildGoods_CS {
    optional uint32 tagid = 1;
    optional uint32 goodstype = 2;
}

message MSG_Ret_SubmitGuildGoods_SC {
    optional uint32 retcode = 1;
    optional uint32 goodstype = 2;
}

message MSG_Req_QuitGuild_CS {
null
}

message MSG_Ret_QuitGuild_SC {
    optional uint32 retcode = 1;
}

message MSG_Req_FireGuildMember_CS {
    optional string leavememberid = 1;
}

message MSG_Ret_FireGuildMember_SC {
    optional uint32 retcode = 1;
    optional string leavememberid = 2;
}

message MSG_Ret_BeFiredGuildMember_SC {
null
}

message MSG_Req_GuildInvite_CS {
    optional string joinmemberid = 1;
}

message MSG_Ret_GuildInvite_SC {
    optional uint32 retcode = 1;
    optional string id = 2;
    optional string name = 3;
    optional string guildname = 4;
}

message MSG_Req_GuildInviteConfirm_CS {
    optional string inviterid = 1;
}

message MSG_Ret_GuildInviteConfirm_SC {
    optional uint32 retcode = 1;
}

message MSG_Req_DismissGuild_CS {
null
}

message MSG_Ret_DismissGuild_SC {
    optional uint32 retcode = 1;
}

message MSG_Req_ChangeGuildMaster_CS {
    optional string newmasterid = 1;
}

message MSG_Ret_ChangeGuildMaster_SC {
    optional uint32 retcode = 1;
}

message ViceMaster {
    optional string id = 1;
    optional uint32 level = 2;
    optional uint32 fightvalue = 3;
    optional string name = 4;
    optional string headicon = 5;
}

message MSG_Req_GuildViceMaster_CS {
null
}

message MSG_Ret_GuildViceMaster_SC {
    repeated ViceMaster vicemaster = 1;    // type_name = .guild.ViceMaster
}

message MSG_Req_GuildExtension_CS {
    optional bool isfree = 1;
}

message MSG_Ret_GuildExtension_SC {
    optional uint32 extensionover = 1;
    optional uint32 retcode = 2;
}

message MSG_Req_OneKeyApply_CS {
null
}

message MSG_Ret_OneKeyApply_SC {
    optional uint32 retcode = 1;
}

message MSG_Req_RecrutCondition_CS {
null
}

message MSG_RetRecrutCondition_SC {
    optional bool levelvalid = 1;
    optional bool fightvalid = 2;
    optional uint32 level = 3;
    optional uint32 fight = 4;
}

message MSG_Req_ModifyRecrutCondition_CS {
    optional bool levelvalid = 1;
    optional bool fightvalid = 2;
    optional uint32 level = 3;
    optional uint32 fight = 4;
}

message MSG_Req_GuildTechnique_CS {
null
}

message TechniqueInfo {
    optional uint32 techid = 1;
    optional uint32 personallevel = 2;
    optional uint32 developlevel = 3;
    optional uint32 validlevel = 4;
    optional bool unlock = 5;
}

message MSG_Ret_GuildTechnique_SC {
    repeated TechniqueInfo info = 1;    // type_name = .guild.TechniqueInfo
}

message MSG_Req_TechniqueUpGrade_CS {
    optional uint32 techid = 1;
}

message MSG_Ret_TechniqueUpGrade_SC {
    optional uint32 retcode = 1;
}

message MSG_Ret_RefreshTechniqueInfo_SC {
    optional TechniqueInfo info = 1;    // type_name = .guild.TechniqueInfo
}

message MSG_Req_TechniqueDevelop_CS {
    optional uint32 techid = 1;
}

message MSG_Ret_TechniqueDevelop_SC {
    optional uint32 salary = 1;
}

message MSG_Req_GuildPartyActivityInfo_CS {
null
}

message MSG_Ret_GuildPartyActivityInfo_SC {
    optional uint32 lefttimes = 1;
}

message MSG_Req_StartGuildParty_CS {
null
}

message MSG_Ret_GuildPartyActivityData_SC {
    optional uint32 endtime = 1;
}

message MSG_Ret_FellowshipSurvey_SC {
    optional uint32 question_a = 1;
    optional uint32 question_b = 2;
    optional uint32 question_c = 3;
}

message MSG_Req_SubmitFellowshipSurvey_CS {
    optional uint32 question_a = 1;
    optional uint32 question_b = 2;
    optional uint32 question_c = 3;
    optional uint32 answer_a = 4;
    optional uint32 answer_b = 5;
    optional string answer_c = 6;
}

message MSG_ReqDonateSalary_CS {
    optional uint32 value = 1;
}

message MSG_ReqUserCntData_CSC {
    optional UserDataType type = 1;    // type_name = .guild.UserDataType
    optional uint32 value = 2;
}

message guildSkill {
    optional uint32 skillid = 1;
    optional uint32 skilllv = 2;
}

message MSG_Req_GuildSkill_CS {
null
}

message MSG_Ret_GuildSkill_SC {
    repeated guildSkill skillinfo = 1;    // type_name = .guild.guildSkill
}

message MSG_Req_LearnGuildSkill_CSC {
    optional guildSkill skillinfo = 1;    // type_name = .guild.guildSkill
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "GuildValueType",
        ["value"] = {
            [1] = {
                ["name"] = "GUILD_VALUE_CONTRIBUTE",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "GUILD_VALUE_SALARY",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "GUILD_VALUE_VITALITY",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "GUILD_VALUE_EXP",
                ["number"] = 4
            }
        }
    },
    [2] = {
        ["name"] = "GuildMemberPosition",
        ["value"] = {
            [1] = {
                ["name"] = "GUILD_POSITION_MASTER",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "GUILD_POSITION_VICEMASTER",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "GUILD_POSITION_NORMAL",
                ["number"] = 99
            }
        }
    },
    [3] = {
        ["name"] = "GuildStatus",
        ["value"] = {
            [1] = {
                ["name"] = "GUILD_STATUS_APPLY",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "GUILD_STATUS_NORMAL",
                ["number"] = 2
            }
        }
    },
    [4] = {
        ["name"] = "GuildPrivilege",
        ["value"] = {
            [1] = {
                ["name"] = "GUILDPRI_MANAGE_POSITION",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "GUILDPRI_REMOVE_MEMBER",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "GUILDPRI_MODIFY_POSITIONNAME",
                ["number"] = 4
            },
            [4] = {
                ["name"] = "GUILDPRI_MODIFY_NOTIFY",
                ["number"] = 8
            },
            [5] = {
                ["name"] = "GUILDPRI_MANAGE_BUILDINGDEV",
                ["number"] = 16
            },
            [6] = {
                ["name"] = "GUILDPRI_ACCEPT_JOIN",
                ["number"] = 32
            },
            [7] = {
                ["name"] = "GUILDPRI_ASSIGN_POSITION",
                ["number"] = 64
            }
        }
    },
    [5] = {
        ["name"] = "UserDataType",
        ["value"] = {
            [1] = {
                ["name"] = "GUILD_DAILY_COUNTRIBUTE",
                ["number"] = 1
            }
        }
    },
    [6] = {
        ["name"] = "ReqMemberListType",
        ["value"] = {
            [1] = {
                ["name"] = "NORMAL",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "APPLYFOR",
                ["number"] = 2
            }
        }
    },
    [7] = {
        ["name"] = "GuildBuildingType",
        ["value"] = {
            [1] = {
                ["name"] = "GuildBuildingType_Main",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "GuildBuildingType_DaTing",
                ["number"] = 2
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "guildMember",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "memberid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "membername",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "memberlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "memberstatus",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "contribute",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "donatesalary",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isonline",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lastonlinetime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "career",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "positionid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "applytime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "guildInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "guildid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "guildname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "guildlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "active",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "mastername",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "exp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "nextexp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "salary",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "sumcount",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "onlinecount",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "countlimit",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_STRING",
                ["name"] = "notify",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 13,
                ["type"] = "TYPE_UINT32",
                ["name"] = "countryid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [14] = {
                ["number"] = 14,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rank",
                ["label"] = "LABEL_OPTIONAL"
            },
            [15] = {
                ["number"] = 15,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.GuildPositionInfo",
                ["name"] = "posinfo"
            },
            [16] = {
                ["number"] = 16,
                ["type"] = "TYPE_STRING",
                ["name"] = "guildsetinfo",
                ["label"] = "LABEL_OPTIONAL"
            },
            [17] = {
                ["number"] = 17,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lastactive",
                ["label"] = "LABEL_OPTIONAL"
            },
            [18] = {
                ["number"] = 18,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lastcountlimit",
                ["label"] = "LABEL_OPTIONAL"
            },
            [19] = {
                ["number"] = 19,
                ["type"] = "TYPE_STRING",
                ["name"] = "icon",
                ["label"] = "LABEL_OPTIONAL"
            },
            [20] = {
                ["number"] = 20,
                ["type"] = "TYPE_UINT32",
                ["name"] = "salary_rest_day",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_Req_PreCreateGuild_CS"
    },
    [4] = {
        ["name"] = "MSG_Ret_PreCreateGuild_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cost_objid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cost_objnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_Req_CreateGuild_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "guildname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "icon",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Ret_CreateGuild_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "guildname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "issucc",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_Req_SetGuildNotify_CS",
        ["field"] = {
            [1] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "notify",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Ret_SetGuildNotify_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "issucc",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_Req_GuildInfo_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "guildid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_Ret_GuildInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.guildInfo",
                ["name"] = "guildinfo"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.guildMember",
                ["name"] = "myinfo"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_Req_GuildList_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "page",
                ["label"] = "LABEL_REQUIRED"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "countryid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "guildListItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.guildInfo",
                ["name"] = "guild"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "guildtype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_Ret_GuildList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.guildListItem",
                ["name"] = "guildList"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "allpage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "page",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "countryid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_Req_ApplyForGuild_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "guildid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "flag",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_Ret_ApplyForGuild_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "guildid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "issucc",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "flag",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "stApplyForItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "applyid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "applyname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["default_value"] = "false",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "issucc"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_Req_AnswerApplyForGuild_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.stApplyForItem",
                ["name"] = "applyinfo"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "accept",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_Ret_AnswerApplyForGuild_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.stApplyForItem",
                ["name"] = "retlist"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_Ret_MyGuildApply_Result_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.stApplyForItem",
                ["name"] = "result"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_Req_GuildMemberList_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "page",
                ["label"] = "LABEL_REQUIRED"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".guild.ReqMemberListType",
                ["name"] = "reqtype"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_Ret_GuildMemberList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.guildInfo",
                ["name"] = "guildinfo"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.guildMember",
                ["name"] = "members"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".guild.ReqMemberListType",
                ["name"] = "reqtype"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "page",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "allpage",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_Req_IntoGuildMap_CS"
    },
    [23] = {
        ["name"] = "MSG_Req_CiTanEnemyGuildList_CS"
    },
    [24] = {
        ["name"] = "CiTanEnemyGuildItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "guildid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "guildlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "guildname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_STRING",
                ["name"] = "mastername",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "isvalid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [25] = {
        ["name"] = "MSG_Ret_CiTanEnemyGuildList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.CiTanEnemyGuildItem",
                ["name"] = "guildlist"
            }
        }
    },
    [26] = {
        ["name"] = "MSG_Req_ChooseCiTanEnemyGuild_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "guildid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [27] = {
        ["name"] = "MSG_Req_TargetCiTanEnemyGuild_CS"
    },
    [28] = {
        ["name"] = "MSG_Ret_ChoosedCiTanEnemyGuild_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.CiTanEnemyGuildItem",
                ["name"] = "guild"
            }
        }
    },
    [29] = {
        ["name"] = "MSG_Req_IntoCiTanEnemyGuild_CS"
    },
    [30] = {
        ["name"] = "MSG_Req_CiTanBacktoMyGuild_CS"
    },
    [31] = {
        ["name"] = "GuildPositionInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "positionid",
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
                ["name"] = "orderid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "privilege",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [32] = {
        ["name"] = "MSG_Req_AddGuildPosition_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.GuildPositionInfo",
                ["name"] = "posinfo"
            }
        }
    },
    [33] = {
        ["name"] = "MSG_Req_DeleteGuildPosition_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "positionid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [34] = {
        ["name"] = "SwapGuildPosInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posidfrom",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posidto",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [35] = {
        ["name"] = "MSG_Req_SwapGuildPosOrder_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.SwapGuildPosInfo",
                ["name"] = "swapinfo"
            }
        }
    },
    [36] = {
        ["name"] = "MSG_Req_ChangePositionName_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "positionid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [37] = {
        ["name"] = "MSG_Req_ChangePositionPri_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "positionid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "privilege",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [38] = {
        ["name"] = "MSG_Req_AssignPosition_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "memberid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "positionid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [39] = {
        ["name"] = "MSG_Ret_AssignPosition_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "memberid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "positionid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [40] = {
        ["name"] = "MSG_Ret_PositionInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.GuildPositionInfo",
                ["name"] = "posinfos"
            }
        }
    },
    [41] = {
        ["name"] = "MSG_Req_GuildLevelup_CS"
    },
    [42] = {
        ["name"] = "MSG_Ret_GuildLevelup_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [43] = {
        ["name"] = "MSG_Req_GuildSetInfo_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "guildsetinfo",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [44] = {
        ["name"] = "MSG_Ret_GuildSetInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [45] = {
        ["name"] = "MSG_Ret_CheckDayWelfare_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "canreceive",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [46] = {
        ["name"] = "MSG_Req_GetDayWelfare_CS"
    },
    [47] = {
        ["name"] = "MSG_Ret_GetDayWelfare_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [48] = {
        ["name"] = "MSG_Req_GuildGoods_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "goodstype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [49] = {
        ["name"] = "GoodsInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "tagid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "itemid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "submitnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "award",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [50] = {
        ["name"] = "MSG_Ret_GuildGoods_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.GoodsInfo",
                ["name"] = "items"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "multireward",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "remain",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "nexttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "goodstype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [51] = {
        ["name"] = "MSG_Req_SubmitGuildGoods_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "tagid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "goodstype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [52] = {
        ["name"] = "MSG_Ret_SubmitGuildGoods_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "goodstype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [53] = {
        ["name"] = "MSG_Req_QuitGuild_CS"
    },
    [54] = {
        ["name"] = "MSG_Ret_QuitGuild_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [55] = {
        ["name"] = "MSG_Req_FireGuildMember_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "leavememberid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [56] = {
        ["name"] = "MSG_Ret_FireGuildMember_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "leavememberid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [57] = {
        ["name"] = "MSG_Ret_BeFiredGuildMember_SC"
    },
    [58] = {
        ["name"] = "MSG_Req_GuildInvite_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "joinmemberid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [59] = {
        ["name"] = "MSG_Ret_GuildInvite_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "id",
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
                ["type"] = "TYPE_STRING",
                ["name"] = "guildname",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [60] = {
        ["name"] = "MSG_Req_GuildInviteConfirm_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "inviterid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [61] = {
        ["name"] = "MSG_Ret_GuildInviteConfirm_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [62] = {
        ["name"] = "MSG_Req_DismissGuild_CS"
    },
    [63] = {
        ["name"] = "MSG_Ret_DismissGuild_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [64] = {
        ["name"] = "MSG_Req_ChangeGuildMaster_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "newmasterid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [65] = {
        ["name"] = "MSG_Ret_ChangeGuildMaster_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [66] = {
        ["name"] = "ViceMaster",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "fightvalue",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "headicon",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [67] = {
        ["name"] = "MSG_Req_GuildViceMaster_CS"
    },
    [68] = {
        ["name"] = "MSG_Ret_GuildViceMaster_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.ViceMaster",
                ["name"] = "vicemaster"
            }
        }
    },
    [69] = {
        ["name"] = "MSG_Req_GuildExtension_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isfree",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [70] = {
        ["name"] = "MSG_Ret_GuildExtension_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "extensionover",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [71] = {
        ["name"] = "MSG_Req_OneKeyApply_CS"
    },
    [72] = {
        ["name"] = "MSG_Ret_OneKeyApply_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [73] = {
        ["name"] = "MSG_Req_RecrutCondition_CS"
    },
    [74] = {
        ["name"] = "MSG_RetRecrutCondition_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "levelvalid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "fightvalid",
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
                ["name"] = "fight",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [75] = {
        ["name"] = "MSG_Req_ModifyRecrutCondition_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "levelvalid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "fightvalid",
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
                ["name"] = "fight",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [76] = {
        ["name"] = "MSG_Req_GuildTechnique_CS"
    },
    [77] = {
        ["name"] = "TechniqueInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "techid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "personallevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "developlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "validlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_BOOL",
                ["name"] = "unlock",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [78] = {
        ["name"] = "MSG_Ret_GuildTechnique_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.TechniqueInfo",
                ["name"] = "info"
            }
        }
    },
    [79] = {
        ["name"] = "MSG_Req_TechniqueUpGrade_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "techid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [80] = {
        ["name"] = "MSG_Ret_TechniqueUpGrade_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [81] = {
        ["name"] = "MSG_Ret_RefreshTechniqueInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.TechniqueInfo",
                ["name"] = "info"
            }
        }
    },
    [82] = {
        ["name"] = "MSG_Req_TechniqueDevelop_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "techid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [83] = {
        ["name"] = "MSG_Ret_TechniqueDevelop_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "salary",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [84] = {
        ["name"] = "MSG_Req_GuildPartyActivityInfo_CS"
    },
    [85] = {
        ["name"] = "MSG_Ret_GuildPartyActivityInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lefttimes",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [86] = {
        ["name"] = "MSG_Req_StartGuildParty_CS"
    },
    [87] = {
        ["name"] = "MSG_Ret_GuildPartyActivityData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "endtime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [88] = {
        ["name"] = "MSG_Ret_FellowshipSurvey_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "question_a",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "question_b",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "question_c",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [89] = {
        ["name"] = "MSG_Req_SubmitFellowshipSurvey_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "question_a",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "question_b",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "question_c",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "answer_a",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "answer_b",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_STRING",
                ["name"] = "answer_c",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [90] = {
        ["name"] = "MSG_ReqDonateSalary_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "value",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [91] = {
        ["name"] = "MSG_ReqUserCntData_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".guild.UserDataType",
                ["name"] = "type"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "value",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [92] = {
        ["name"] = "guildSkill",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skilllv",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [93] = {
        ["name"] = "MSG_Req_GuildSkill_CS"
    },
    [94] = {
        ["name"] = "MSG_Ret_GuildSkill_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.guildSkill",
                ["name"] = "skillinfo"
            }
        }
    },
    [95] = {
        ["name"] = "MSG_Req_LearnGuildSkill_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guild.guildSkill",
                ["name"] = "skillinfo"
            }
        }
    }
},
["name"] = "guild.proto",
["package"] = "guild"

----- end of proto -----
