name = team.proto

package Team;

message MSG_CreateTeam_CS {
    required string name = 1;
    optional uint32 activityid = 2;
}

message Memember {
    optional uint32 mark = 1;
    optional string name = 2;
    optional uint32 occupation = 3;
    optional uint32 level = 4;
    repeated uint32 skill = 5;
    optional string mememberid = 6;
    optional uint32 hp = 7;
    optional uint32 maxhp = 8;
    optional uint32 occupationlevel = 9;
    optional uint32 heroid = 10;
    optional uint32 fight = 11;
    optional string sceneid = 12;
    optional MemState state = 13;    // type_name = .Team.MemState
    optional uint32 privilege = 14;
    optional uint32 hairstyle = 15;
    optional uint32 haircolor = 16;
    optional uint32 headstyle = 17;
    optional uint32 bodystyle = 18;
    optional uint32 antenna = 19;
    optional uint32 avatarid = 20;
}

message MSG_TeamMemeberList_CS {
null
}

message MSG_TeamMemeberList_SC {
    optional uint32 id = 1;
    optional string name = 2;
    optional string leaderid = 3;
    repeated Memember mem = 4;    // type_name = .Team.Memember
    optional RewardMode mode = 5;    // type_name = .Team.RewardMode
    optional CapacityType cap_type = 6;    // type_name = .Team.CapacityType
    optional uint32 maxmember = 7;
    optional string note = 8;
    optional uint32 activityid = 9;
    optional uint32 curmember = 10;
}

message OneTeam {
    optional uint32 id = 1;
    optional string name = 2;
    optional uint32 size = 3;
    optional uint32 capacity = 4;
    optional RewardMode mode = 5;    // type_name = .Team.RewardMode
    optional string note = 6;
}

message MSG_Team_List_CS {
null
}

message MSG_Team_List_SC {
    repeated MSG_TeamMemeberList_SC oneteam = 1;    // type_name = .Team.MSG_TeamMemeberList_SC
}

message MSG_Join_Team_CS {
    required uint32 teamid = 1;
}

message MSG_Join_Team_SC {
    optional uint32 retcode = 1;
}

message MSG_ReqJoinTeamNotifyLeader_SC {
    required string requesterid = 1;
    optional string requestername = 2;
}

message MSG_AnswerJoinTeam_CS {
    required string requesterid = 1;
    required AnswerType answer_type = 2;    // type_name = .Team.AnswerType
}

message MSG_AnswerJoinTeam_SC {
    optional uint32 errcode = 1;
    optional AnswerType answer_type = 2;    // type_name = .Team.AnswerType
    optional MSG_TeamMemeberList_SC teaminfo = 3;    // type_name = .Team.MSG_TeamMemeberList_SC
}

message MSG_ReqApplyList_CS {
null
}

message MSG_ReqApplyList_SC {
    repeated Memember applyer = 1;    // type_name = .Team.Memember
    optional string leaderid = 2;
}

message MSG_ReqDelMemember_CS {
    required string charid = 1;
}

message MSG_ReqDelMemember_SC {
    required string charid = 1;
    required OutType outtype = 2;    // type_name = .Team.OutType
    optional string name = 3;
}

message MSG_ReqLanchVoteOut_CS {
    required string outid = 1;
}

message MSG_ReqLanchVoteOut_SC {
    required uint32 errcode = 1 [default = 0];
    optional string lancherid = 2;
    required string lanchername = 3;
    optional string outerid = 4;
    required string outername = 5;
    required string duration = 6;
}

message MSG_ReqVote_CS {
    required bool yesorno = 1 [default = false];
}

message MSG_ReqChangeLeader_CS {
    required string toid = 1;
}

message MSG_ReqChangeLeader_SC {
    required string newid = 1;
    optional string newname = 2;
}

message MSG_ReqNearByUnteamedPlayer_CS {
null
}

message MSG_ReqNearByUnteamedPlayer_SC {
    repeated Memember mem = 1;    // type_name = .Team.Memember
}

message MSG_InviteIntoTeam_CS {
    optional string inviteeid = 1;
}

message MSG_InviteIntoTeam_SC {
    optional uint32 errcode = 1 [default = 0];
}

message MSG_AnswerInviteTeam_CS {
    optional bool yesorno = 1 [default = false];
    optional string inviterid = 2;
    optional string inviteeid = 3;
    optional uint32 teamid = 4;
}

message MSG_AddMemember_SC {
    optional Memember mem = 1;    // type_name = .Team.Memember
}

message MSG_LeaderIgnoreNotice_CS {
null
}

message MSG_updateTeamMememberHp_SC {
    optional string memid = 1;
    optional uint32 hp = 2;
    optional uint32 maxhp = 3;
    optional bool isdead = 4 [default = false];
}

message MSG_updateTeamMememberCareer_SC {
    optional string mememberid = 1;
    optional uint32 career = 2;
    optional uint32 careerlevel = 3;
}

message MSG_updateTeamMemeberHero_SC {
    optional string memid = 1;
    optional uint32 heroid = 2;
}

message MSG_updateTeamMememberLevel_SC {
    optional string mememberid = 1;
    optional uint32 level = 2;
    optional string membername = 3;
}

message MSG_updateTeamMemberFight_SC {
    optional string mememberid = 1;
    optional uint32 fight = 2;
    optional uint32 heroid = 3;
}

message MSG_ReqTeamMemberPos_CS {
null
}

message MemberPos {
    optional string memberid = 1;
    optional string sceneid = 2;
    optional uint32 x = 3;
    optional uint32 y = 4;
}

message MSG_RetTeamMemberPos_SC {
    repeated MemberPos members = 1;    // type_name = .Team.MemberPos
}

message MSG_RetNearByUnteamedInvite_SC {
    optional Memember inviter = 1;    // type_name = .Team.Memember
    optional string invitername = 2;
    optional string inviterid = 3;
    optional string inviteename = 4;
    optional string inviteeid = 5;
    optional string teamname = 6;
    optional uint32 teamid = 7;
}

message MSG_RetNewApply_SC {
    optional uint32 count = 1;
}

message teamDropItem {
    optional string thisid = 1;
    optional uint32 objid = 2;
    optional uint32 num = 3;
    optional uint32 bind = 4;
    optional uint32 duetime = 5;
}

message MSG_RetTeamPublicDrop_SC {
    repeated teamDropItem oneitem = 1;    // type_name = .Team.teamDropItem
}

message ChooseTeamDropItem {
    optional string thisid = 1;
    optional ChooseType choose = 2;    // type_name = .Team.ChooseType
    optional uint32 errcode = 3;
}

message MSG_ReqChooseTeamDrop_CS {
    repeated ChooseTeamDropItem item = 1;    // type_name = .Team.ChooseTeamDropItem
}

message MSG_RetChooseTeamDrop_SC {
    repeated ChooseTeamDropItem item = 1;    // type_name = .Team.ChooseTeamDropItem
}

message MSG_ReqSearchTeam_CS {
    optional uint32 teamid = 1;
    optional uint32 activityid = 2;
    optional bool nearby = 3;
}

message MSG_ReqSearchTeamByPage_CS {
    optional uint32 page = 1;
    optional bool nearby = 2;
}

message MSG_RetSearchTeam_SC {
    optional uint32 totalpage = 1;
    optional uint32 page = 2;
    repeated MSG_TeamMemeberList_SC teamlist = 3;    // type_name = .Team.MSG_TeamMemeberList_SC
}

message MSG_ReqChangeActivityTarget_CS {
    optional uint32 activityid = 1;
}

message MSG_RetChangeActivityTarget_SC {
    optional uint32 retcode = 1;
    optional uint32 activityid = 2;
}

message MSG_ReqMatch_CS {
    optional uint32 activityid = 1;
    optional uint32 minlevel = 2;
    optional uint32 maxlevel = 3;
}

message MSG_RetMatch_SC {
    optional uint32 retcode = 1;
    optional uint32 needtime = 2;
    optional uint32 starttime = 3;
}

message MSG_ReqUnmatch_CS {
null
}

message MSG_RetUnmatch_SC {
    optional uint32 retcode = 1;
}

message MSG_RetNotifyMatchSuccess_SC {
null
}

message MSG_ReqMemberBackTeam_CS {
null
}

message MSG_RetMemberBackTeam_SC {
    optional uint32 rettype = 1;
}

message MSG_updateMemStateToTeam_SC {
    optional string memid = 1;
    optional string sceneid = 2;
    optional MemState state = 3;    // type_name = .Team.MemState
}

message MSG_ReqLeaderMapPos_CS {
null
}

message MSG_RetLeaderMapPos_SC {
    optional uint32 retcode = 1;
    optional LeaderPosInfo pos = 2;    // type_name = .Team.LeaderPosInfo
}

message LeaderPosInfo {
    optional bool valid = 1 [default = false];
    optional string sceneid = 2;
    optional MemberPos pos = 3;    // type_name = .Team.MemberPos
}

message MSG_ReqChangeMapToLeader_CS {
    optional string sceneid = 1;
    optional MemberPos leaderpos = 2;    // type_name = .Team.MemberPos
}

message MSG_RetChangeMapToLeader_SC {
    optional uint32 retcode = 1;
    optional LeaderPosInfo info = 2;    // type_name = .Team.LeaderPosInfo
}

message MSG_ReqLeaderAttackTarget_CS {
null
}

message MSG_RetLeaderAttackTarget_SC {
    optional EntryIDType target = 1;    // type_name = .msg.EntryIDType
}

message MSG_notifyMemberLeaderIntoPublic_SC {
null
}

message MSG_notifyMemberOfflineHosting_SC {
null
}

message MSG_Req_SetMemberPrivilege_CS {
    optional uint64 memberid = 1;
    optional TeamPrivilege privilege = 2;    // type_name = .Team.TeamPrivilege
    optional bool set = 3;
}

message MSG_updateTeamMemberPrivilege_SC {
    optional uint64 memberid = 1;
    optional uint32 privilege = 2;
}

message MSG_Req_checkUserTeamInfo_CS {
    optional uint64 memberid = 1;
}

message MSG_Ret_checkUserTeamInfo_SC {
    optional uint64 memberid = 1;
    optional uint64 teamid = 2;
    optional bool online = 3;
}

message MSG_Req_DismissTeam_CS {
null
}

message MSG_NotifyTeamDismiss_SC {
    optional bool suc = 1;
}

message MSG_updateTeamMemberAvatar_SC {
    optional string mememberid = 1;
    optional uint32 hairstyle = 2;
    optional uint32 haircolor = 3;
    optional uint32 headstyle = 4;
    optional uint32 bodystyle = 5;
    optional uint32 antenna = 6;
    optional uint32 coat = 7;
    optional uint32 avatarid = 8;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "CapacityType",
        ["value"] = {
            [1] = {
                ["name"] = "Capacity_Small",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "Capacity_Big",
                ["number"] = 2
            }
        }
    },
    [2] = {
        ["name"] = "RewardMode",
        ["value"] = {
            [1] = {
                ["name"] = "Mode_Roll",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "Mode_Dispath",
                ["number"] = 2
            }
        }
    },
    [3] = {
        ["name"] = "OutType",
        ["value"] = {
            [1] = {
                ["name"] = "OutType_Quit",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "OutType_Fire",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "OutType_VoteOut",
                ["number"] = 3
            }
        }
    },
    [4] = {
        ["name"] = "TeamPrivilege",
        ["value"] = {
            [1] = {
                ["name"] = "TeamPrivilege_Invite",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "TeamPrivilege_RemoveMember",
                ["number"] = 2
            }
        }
    },
    [5] = {
        ["name"] = "AnswerType",
        ["value"] = {
            [1] = {
                ["name"] = "AnswerType_Yes",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "AnswerType_No",
                ["number"] = 2
            }
        }
    },
    [6] = {
        ["name"] = "ChooseType",
        ["value"] = {
            [1] = {
                ["name"] = "ChooseType_Need",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "ChooseType_Greed",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "ChooseType_Giveup",
                ["number"] = 3
            }
        }
    },
    [7] = {
        ["name"] = "MemState",
        ["value"] = {
            [1] = {
                ["name"] = "NORMAL",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "AWAY",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "OFFLINE",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "HOSTING",
                ["number"] = 3
            }
        }
    }
},
["package"] = "Team",
["name"] = "team.proto",
["dependency"] = {
    [1] = "msg_enum.proto"
},
["message_type"] = {
    [1] = {
        ["name"] = "MSG_CreateTeam_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_REQUIRED"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "activityid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "Memember",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mark",
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
                ["name"] = "occupation",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skill",
                ["label"] = "LABEL_REPEATED"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_STRING",
                ["name"] = "mememberid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxhp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "occupationlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "fight",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_STRING",
                ["name"] = "sceneid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 13,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Team.MemState",
                ["name"] = "state"
            },
            [14] = {
                ["number"] = 14,
                ["type"] = "TYPE_UINT32",
                ["name"] = "privilege",
                ["label"] = "LABEL_OPTIONAL"
            },
            [15] = {
                ["number"] = 15,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hairstyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [16] = {
                ["number"] = 16,
                ["type"] = "TYPE_UINT32",
                ["name"] = "haircolor",
                ["label"] = "LABEL_OPTIONAL"
            },
            [17] = {
                ["number"] = 17,
                ["type"] = "TYPE_UINT32",
                ["name"] = "headstyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [18] = {
                ["number"] = 18,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bodystyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [19] = {
                ["number"] = 19,
                ["type"] = "TYPE_UINT32",
                ["name"] = "antenna",
                ["label"] = "LABEL_OPTIONAL"
            },
            [20] = {
                ["number"] = 20,
                ["type"] = "TYPE_UINT32",
                ["name"] = "avatarid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_TeamMemeberList_CS"
    },
    [4] = {
        ["name"] = "MSG_TeamMemeberList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
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
                ["type"] = "TYPE_STRING",
                ["name"] = "leaderid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.Memember",
                ["name"] = "mem"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Team.RewardMode",
                ["name"] = "mode"
            },
            [6] = {
                ["number"] = 6,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Team.CapacityType",
                ["name"] = "cap_type"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxmember",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_STRING",
                ["name"] = "note",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "activityid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curmember",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "OneTeam",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
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
                ["name"] = "size",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "capacity",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Team.RewardMode",
                ["name"] = "mode"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_STRING",
                ["name"] = "note",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Team_List_CS"
    },
    [7] = {
        ["name"] = "MSG_Team_List_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.MSG_TeamMemeberList_SC",
                ["name"] = "oneteam"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Join_Team_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "teamid",
                ["label"] = "LABEL_REQUIRED"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_Join_Team_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_ReqJoinTeamNotifyLeader_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "requesterid",
                ["label"] = "LABEL_REQUIRED"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "requestername",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_AnswerJoinTeam_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "requesterid",
                ["label"] = "LABEL_REQUIRED"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Team.AnswerType",
                ["name"] = "answer_type"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_AnswerJoinTeam_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Team.AnswerType",
                ["name"] = "answer_type"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.MSG_TeamMemeberList_SC",
                ["name"] = "teaminfo"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_ReqApplyList_CS"
    },
    [14] = {
        ["name"] = "MSG_ReqApplyList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.Memember",
                ["name"] = "applyer"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "leaderid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_ReqDelMemember_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "charid",
                ["label"] = "LABEL_REQUIRED"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_ReqDelMemember_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "charid",
                ["label"] = "LABEL_REQUIRED"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Team.OutType",
                ["name"] = "outtype"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_ReqLanchVoteOut_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "outid",
                ["label"] = "LABEL_REQUIRED"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_ReqLanchVoteOut_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["default_value"] = "0",
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "lancherid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "lanchername",
                ["label"] = "LABEL_REQUIRED"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_STRING",
                ["name"] = "outerid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "outername",
                ["label"] = "LABEL_REQUIRED"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_STRING",
                ["name"] = "duration",
                ["label"] = "LABEL_REQUIRED"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_ReqVote_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["default_value"] = "false",
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_BOOL",
                ["name"] = "yesorno"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_ReqChangeLeader_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "toid",
                ["label"] = "LABEL_REQUIRED"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_ReqChangeLeader_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "newid",
                ["label"] = "LABEL_REQUIRED"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "newname",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_ReqNearByUnteamedPlayer_CS"
    },
    [23] = {
        ["name"] = "MSG_ReqNearByUnteamedPlayer_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.Memember",
                ["name"] = "mem"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_InviteIntoTeam_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "inviteeid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [25] = {
        ["name"] = "MSG_InviteIntoTeam_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["default_value"] = "0",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode"
            }
        }
    },
    [26] = {
        ["name"] = "MSG_AnswerInviteTeam_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["default_value"] = "false",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "yesorno"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "inviterid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "inviteeid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "teamid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [27] = {
        ["name"] = "MSG_AddMemember_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.Memember",
                ["name"] = "mem"
            }
        }
    },
    [28] = {
        ["name"] = "MSG_LeaderIgnoreNotice_CS"
    },
    [29] = {
        ["name"] = "MSG_updateTeamMememberHp_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "memid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hp",
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
                ["default_value"] = "false",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "isdead"
            }
        }
    },
    [30] = {
        ["name"] = "MSG_updateTeamMememberCareer_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "mememberid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "career",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "careerlevel",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [31] = {
        ["name"] = "MSG_updateTeamMemeberHero_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "memid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [32] = {
        ["name"] = "MSG_updateTeamMememberLevel_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "mememberid",
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
                ["type"] = "TYPE_STRING",
                ["name"] = "membername",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [33] = {
        ["name"] = "MSG_updateTeamMemberFight_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "mememberid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "fight",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [34] = {
        ["name"] = "MSG_ReqTeamMemberPos_CS"
    },
    [35] = {
        ["name"] = "MemberPos",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "memberid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "sceneid",
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
    [36] = {
        ["name"] = "MSG_RetTeamMemberPos_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.MemberPos",
                ["name"] = "members"
            }
        }
    },
    [37] = {
        ["name"] = "MSG_RetNearByUnteamedInvite_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.Memember",
                ["name"] = "inviter"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "invitername",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "inviterid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_STRING",
                ["name"] = "inviteename",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "inviteeid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_STRING",
                ["name"] = "teamname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "teamid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [38] = {
        ["name"] = "MSG_RetNewApply_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "count",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [39] = {
        ["name"] = "teamDropItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bind",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duetime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [40] = {
        ["name"] = "MSG_RetTeamPublicDrop_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.teamDropItem",
                ["name"] = "oneitem"
            }
        }
    },
    [41] = {
        ["name"] = "ChooseTeamDropItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Team.ChooseType",
                ["name"] = "choose"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [42] = {
        ["name"] = "MSG_ReqChooseTeamDrop_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.ChooseTeamDropItem",
                ["name"] = "item"
            }
        }
    },
    [43] = {
        ["name"] = "MSG_RetChooseTeamDrop_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.ChooseTeamDropItem",
                ["name"] = "item"
            }
        }
    },
    [44] = {
        ["name"] = "MSG_ReqSearchTeam_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "teamid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "activityid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "nearby",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [45] = {
        ["name"] = "MSG_ReqSearchTeamByPage_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "page",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "nearby",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [46] = {
        ["name"] = "MSG_RetSearchTeam_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "totalpage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "page",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.MSG_TeamMemeberList_SC",
                ["name"] = "teamlist"
            }
        }
    },
    [47] = {
        ["name"] = "MSG_ReqChangeActivityTarget_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "activityid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [48] = {
        ["name"] = "MSG_RetChangeActivityTarget_SC",
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
                ["name"] = "activityid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [49] = {
        ["name"] = "MSG_ReqMatch_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "activityid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "minlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxlevel",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [50] = {
        ["name"] = "MSG_RetMatch_SC",
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
                ["name"] = "needtime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "starttime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [51] = {
        ["name"] = "MSG_ReqUnmatch_CS"
    },
    [52] = {
        ["name"] = "MSG_RetUnmatch_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [53] = {
        ["name"] = "MSG_RetNotifyMatchSuccess_SC"
    },
    [54] = {
        ["name"] = "MSG_ReqMemberBackTeam_CS"
    },
    [55] = {
        ["name"] = "MSG_RetMemberBackTeam_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rettype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [56] = {
        ["name"] = "MSG_updateMemStateToTeam_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "memid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "sceneid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Team.MemState",
                ["name"] = "state"
            }
        }
    },
    [57] = {
        ["name"] = "MSG_ReqLeaderMapPos_CS"
    },
    [58] = {
        ["name"] = "MSG_RetLeaderMapPos_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.LeaderPosInfo",
                ["name"] = "pos"
            }
        }
    },
    [59] = {
        ["name"] = "LeaderPosInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["default_value"] = "false",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "valid"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "sceneid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.MemberPos",
                ["name"] = "pos"
            }
        }
    },
    [60] = {
        ["name"] = "MSG_ReqChangeMapToLeader_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "sceneid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.MemberPos",
                ["name"] = "leaderpos"
            }
        }
    },
    [61] = {
        ["name"] = "MSG_RetChangeMapToLeader_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Team.LeaderPosInfo",
                ["name"] = "info"
            }
        }
    },
    [62] = {
        ["name"] = "MSG_ReqLeaderAttackTarget_CS"
    },
    [63] = {
        ["name"] = "MSG_RetLeaderAttackTarget_SC",
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
    [64] = {
        ["name"] = "MSG_notifyMemberLeaderIntoPublic_SC"
    },
    [65] = {
        ["name"] = "MSG_notifyMemberOfflineHosting_SC"
    },
    [66] = {
        ["name"] = "MSG_Req_SetMemberPrivilege_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "memberid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Team.TeamPrivilege",
                ["name"] = "privilege"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "set",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [67] = {
        ["name"] = "MSG_updateTeamMemberPrivilege_SC",
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
                ["name"] = "privilege",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [68] = {
        ["name"] = "MSG_Req_checkUserTeamInfo_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "memberid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [69] = {
        ["name"] = "MSG_Ret_checkUserTeamInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "memberid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "teamid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "online",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [70] = {
        ["name"] = "MSG_Req_DismissTeam_CS"
    },
    [71] = {
        ["name"] = "MSG_NotifyTeamDismiss_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "suc",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [72] = {
        ["name"] = "MSG_updateTeamMemberAvatar_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "mememberid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hairstyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "haircolor",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "headstyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bodystyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "antenna",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "coat",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "avatarid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
}

----- end of proto -----
