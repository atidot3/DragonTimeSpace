name = rankpk_msg.proto

package rankpk_msg;

message UserRankPkInfo {
    optional uint32 charid = 1;
    optional string name = 2;
    optional uint32 heroid = 3;
    optional uint32 fight = 4;
    optional uint32 rank_level = 5;
    optional uint32 rank_star = 6;
    optional uint32 rank = 7;
    optional uint32 hide_score = 8;
    optional uint32 all_battles = 9;
    optional uint32 success_battles = 10;
    optional uint32 battle_score = 11;
    optional uint32 seanson_battles = 12;
    optional uint32 best_rank_level = 13;
    optional uint32 best_rank = 14;
}

message MSG_Req_MatchMemberInfo_CS {
null
}

message MSG_Ret_MatchMemberInfo_SC {
    repeated UserRankPkInfo members = 1;    // type_name = .rankpk_msg.UserRankPkInfo
    optional uint64 leaderid = 2;
    optional uint32 season_id = 3;
    optional uint32 start_time = 4;
    optional uint32 end_time = 5;
    optional uint32 leftdays = 6;
}

message MSG_Req_StartMatch_CS {
null
}

message MSG_Ret_StartMatch_SC {
    optional uint32 retcode = 1;
}

message MSG_Req_CancelMatch_CS {
null
}

message MSG_Ret_CancelMatch_SC {
    optional uint32 retcode = 1;
}

message MSG_RankPkReqPrepare_CS {
null
}

message MSG_RankPkReqPrepare_SC {
    required uint32 readystate = 1;
    required uint32 readynum = 2;
    required uint32 totalnum = 3;
    optional uint32 lefttime = 4;
    optional uint32 enemyreadynum = 5;
    optional uint32 enemytotalnum = 6;
}

message MSG_GoToBattle_SC {
    optional uint32 retcode = 1;
}

message MSG_Ret_MatchResult_SC {
    optional uint32 retcode = 1;
    optional uint32 lefttime = 2;
    optional uint32 totalnum = 3;
}

message MSG_Req_GotoBattle_CS {
null
}

message MSG_RetStartPrepare_SC {
    optional uint32 duration = 1;
}

message MSG_ReqChoosePrepared_CS {
null
}

message MSG_RetChoosePrepared_SC {
    optional uint32 errcode = 1;
}

message MSG_RetFightCountDown_SC {
    optional uint32 duration = 1;
}

message MSG_RetStartFight_SC {
    optional uint32 duration = 1;
    optional MSG_RetTeamCurScore_SC score = 2;    // type_name = .rankpk_msg.MSG_RetTeamCurScore_SC
}

message MSG_RetSpeedupFight_SC {
    optional uint32 duration = 1;
}

message RankPKResult {
    optional uint32 charid = 1;
    optional string name = 2;
    optional uint32 heroid = 3;
    optional uint32 cure = 4;
    optional uint32 hurt = 5;
    optional uint32 dead = 6;
    optional uint32 kill = 7;
}

message MSG_RetFightFinish_SC {
    optional uint32 duration = 1;
    optional uint32 winteamid = 2;
    repeated RewardsNumber rewards = 3;    // type_name = .rankpk_msg.RewardsNumber
    repeated RankPKResult MeRankPKResult = 4;    // type_name = .rankpk_msg.RankPKResult
    repeated RankPKResult EnemyRankPKResult = 5;    // type_name = .rankpk_msg.RankPKResult
}

message MSG_ReqGetSeasonRewards_CS {
null
}

message MSG_RetGetSeasonRewards_SC {
    optional bool season_rewards_received = 1;
}

message MSG_RetRewardsEveryday_SC {
    optional uint32 battle_number = 1;
    optional uint32 success_number = 2;
    repeated PkRewards pkrewards = 3;    // type_name = .rankpk_msg.PkRewards
    optional uint32 remainder_day = 4;
    optional uint32 rank_level = 5;
    optional bool rewards_received = 6;
}

message MSG_ReqRewardsEveryday_CS {
null
}

message PkRewards {
    optional uint32 heroid = 1;
    optional uint32 time = 2;
    repeated RewardsNumber rewards = 3;    // type_name = .rankpk_msg.RewardsNumber
    optional bool pkresult = 4;
}

message RewardsNumber {
    optional uint32 objectid = 1;
    optional uint32 number = 2;
}

message RankPKHero {
    optional uint32 heroid = 1;
    optional uint32 lastusetime = 2;
}

message MSG_RetRankPKHeroHistory_SC {
    repeated RankPKHero heros = 1;    // type_name = .rankpk_msg.RankPKHero
}

message MSG_RetUserRankStar_SC {
    optional uint64 uid = 1;
    optional uint32 rank = 2;
}

message MSG_RetTeamLeftMemSize_SC {
    optional uint32 team1id = 1;
    optional uint32 team1left = 2;
    optional uint32 team2id = 3;
    optional uint32 team2left = 4;
}

message MSG_ReqRankPKCurStage_CS {
null
}

message MSG_RetRankPKCurStage_SC {
    required StageType curstage = 1;    // type_name = .msg.StageType
    optional uint32 duration = 2;
    optional MSG_RetTeamCurScore_SC score = 3;    // type_name = .rankpk_msg.MSG_RetTeamCurScore_SC
}

message MSG_RetPreparedNum_SC {
    optional uint32 curnum = 1;
    optional uint32 allnum = 2;
}

message MSG_RetMemPkPrepared_SC {
    optional uint64 memid = 1;
    optional uint32 heroid = 2;
}

message MSG_RetPKGeneralConfig_SC {
    optional uint32 teampknum = 1;
}

message MSG_RetTeamCurScore_SC {
    optional uint32 team1id = 1;
    optional uint32 team1score = 2;
    optional uint32 team2id = 3;
    optional uint32 team2score = 4;
}

message RankPKListItem {
    optional uint32 position = 1;
    optional uint64 charid = 2;
    optional string name = 3;
    optional uint32 ranklevel = 4;
    optional string guildname = 5;
    optional uint32 winbattle = 6;
    optional uint32 winrate = 7;
}

message MSG_ReqRankPKList_CS {
    optional RankPKListType type = 1;    // type_name = .rankpk_msg.RankPKListType
}

message MSG_RetRankPKList_SC {
    optional RankPKListType type = 1;    // type_name = .rankpk_msg.RankPKListType
    optional uint32 myposition = 2;
    repeated RankPKListItem data = 3;    // type_name = .rankpk_msg.RankPKListItem
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "RankPKListType",
        ["value"] = {
            [1] = {
                ["name"] = "RankPKListType_All",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "RankPKListType_Friend",
                ["number"] = 1
            }
        }
    }
},
["package"] = "rankpk_msg",
["name"] = "rankpk_msg.proto",
["dependency"] = {
    [1] = "msg_enum.proto"
},
["message_type"] = {
    [1] = {
        ["name"] = "UserRankPkInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
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
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "fight",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rank_level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rank_star",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rank",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hide_score",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "all_battles",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "success_battles",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "battle_score",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT32",
                ["name"] = "seanson_battles",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 13,
                ["type"] = "TYPE_UINT32",
                ["name"] = "best_rank_level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [14] = {
                ["number"] = 14,
                ["type"] = "TYPE_UINT32",
                ["name"] = "best_rank",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Req_MatchMemberInfo_CS"
    },
    [3] = {
        ["name"] = "MSG_Ret_MatchMemberInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rankpk_msg.UserRankPkInfo",
                ["name"] = "members"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "leaderid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "season_id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "start_time",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "end_time",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "leftdays",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Req_StartMatch_CS"
    },
    [5] = {
        ["name"] = "MSG_Ret_StartMatch_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Req_CancelMatch_CS"
    },
    [7] = {
        ["name"] = "MSG_Ret_CancelMatch_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_RankPkReqPrepare_CS"
    },
    [9] = {
        ["name"] = "MSG_RankPkReqPrepare_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "readystate",
                ["label"] = "LABEL_REQUIRED"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "readynum",
                ["label"] = "LABEL_REQUIRED"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "totalnum",
                ["label"] = "LABEL_REQUIRED"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lefttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "enemyreadynum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "enemytotalnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_GoToBattle_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_Ret_MatchResult_SC",
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
                ["name"] = "lefttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "totalnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_Req_GotoBattle_CS"
    },
    [13] = {
        ["name"] = "MSG_RetStartPrepare_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_ReqChoosePrepared_CS"
    },
    [15] = {
        ["name"] = "MSG_RetChoosePrepared_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_RetFightCountDown_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_RetStartFight_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rankpk_msg.MSG_RetTeamCurScore_SC",
                ["name"] = "score"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_RetSpeedupFight_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [19] = {
        ["name"] = "RankPKResult",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
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
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cure",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hurt",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dead",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "kill",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_RetFightFinish_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "winteamid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rankpk_msg.RewardsNumber",
                ["name"] = "rewards"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rankpk_msg.RankPKResult",
                ["name"] = "MeRankPKResult"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rankpk_msg.RankPKResult",
                ["name"] = "EnemyRankPKResult"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_ReqGetSeasonRewards_CS"
    },
    [22] = {
        ["name"] = "MSG_RetGetSeasonRewards_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "season_rewards_received",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [23] = {
        ["name"] = "MSG_RetRewardsEveryday_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "battle_number",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "success_number",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rankpk_msg.PkRewards",
                ["name"] = "pkrewards"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "remainder_day",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rank_level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_BOOL",
                ["name"] = "rewards_received",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_ReqRewardsEveryday_CS"
    },
    [25] = {
        ["name"] = "PkRewards",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "time",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rankpk_msg.RewardsNumber",
                ["name"] = "rewards"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_BOOL",
                ["name"] = "pkresult",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [26] = {
        ["name"] = "RewardsNumber",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objectid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "number",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [27] = {
        ["name"] = "RankPKHero",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lastusetime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [28] = {
        ["name"] = "MSG_RetRankPKHeroHistory_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rankpk_msg.RankPKHero",
                ["name"] = "heros"
            }
        }
    },
    [29] = {
        ["name"] = "MSG_RetUserRankStar_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "uid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rank",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [30] = {
        ["name"] = "MSG_RetTeamLeftMemSize_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "team1id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "team1left",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "team2id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "team2left",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [31] = {
        ["name"] = "MSG_ReqRankPKCurStage_CS"
    },
    [32] = {
        ["name"] = "MSG_RetRankPKCurStage_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.StageType",
                ["name"] = "curstage"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rankpk_msg.MSG_RetTeamCurScore_SC",
                ["name"] = "score"
            }
        }
    },
    [33] = {
        ["name"] = "MSG_RetPreparedNum_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "allnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [34] = {
        ["name"] = "MSG_RetMemPkPrepared_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
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
    [35] = {
        ["name"] = "MSG_RetPKGeneralConfig_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "teampknum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [36] = {
        ["name"] = "MSG_RetTeamCurScore_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "team1id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "team1score",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "team2id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "team2score",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [37] = {
        ["name"] = "RankPKListItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "position",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
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
                ["name"] = "ranklevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "guildname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "winbattle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "winrate",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [38] = {
        ["name"] = "MSG_ReqRankPKList_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".rankpk_msg.RankPKListType",
                ["name"] = "type"
            }
        }
    },
    [39] = {
        ["name"] = "MSG_RetRankPKList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".rankpk_msg.RankPKListType",
                ["name"] = "type"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "myposition",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rankpk_msg.RankPKListItem",
                ["name"] = "data"
            }
        }
    }
}

----- end of proto -----
