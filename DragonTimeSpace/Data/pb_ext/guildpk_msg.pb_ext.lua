name = guildpk_msg.proto

package guildpk_msg;

message MSG_Req_GuildPkEnroll_CS {
null
}

message MSG_Ret_GuildPkEnroll_SC {
    optional bool result = 1;
}

message GuildPkMemberInfo {
    optional uint64 charid = 1;
    optional string name = 2;
    optional uint32 level = 3;
    optional uint32 teamid = 4;
    optional uint32 posid = 5;
}

message GuildPkTeamInfo {
    optional uint32 teamid = 1;
    optional uint32 unlocklv = 2;
    repeated GuildPkMemberInfo members = 3;    // type_name = .guildpk_msg.GuildPkMemberInfo
}

message GuildPkGuildInfo {
    optional uint64 guildid = 1;
    optional string guildname = 2;
    optional uint32 teamlimit = 3;
    repeated GuildPkTeamInfo teaminfo = 4;    // type_name = .guildpk_msg.GuildPkTeamInfo
}

message MSG_Ret_GuildPkInfo_SC {
    optional GuildPkGuildInfo guildinfo = 1;    // type_name = .guildpk_msg.GuildPkGuildInfo
}

message MSG_Req_GuildPkInfo_CS {
null
}

message MSG_Req_GuildPkJoinTeam_CS {
    optional uint32 teamid = 1;
    optional uint32 posid = 2;
}

message MSG_Req_GuildPkQuitTeam_CS {
null
}

message MSG_Refresh_GuildPkMemberInfo_SC {
    optional GuildPkMemberInfo member = 1;    // type_name = .guildpk_msg.GuildPkMemberInfo
}

message MSG_Req_GuildPkRank_CS {
null
}

message GuildPkGuildScore {
    optional uint32 rank = 1;
    optional uint64 guildid = 2;
    optional string guildname = 3;
    optional uint32 score = 4;
}

message MSG_Ret_GuildPkRank_SC {
    repeated GuildPkGuildScore scorerank = 1;    // type_name = .guildpk_msg.GuildPkGuildScore
}

message MSG_Req_GuildPkWinList_CS {
null
}

message GuildPkWinInfo {
    optional uint64 uid = 1;
    optional string win_guild_name = 2;
    optional string win_leader_name = 3;
}

message MSG_Ret_GuildPkWinList_SC {
    repeated GuildPkWinInfo winers = 1;    // type_name = .guildpk_msg.GuildPkWinInfo
}

message MSG_Ret_GuildPkMatchResult_SC {
    optional uint32 retcode = 1;
    optional uint32 lefttime = 2;
}

message MSG_Req_EnterGuildPk_CS {
null
}

message MSG_Ret_GuildPkCountDown_SC {
    optional uint32 lefttime = 1;
}

message MSG_Ret_GuildPkFight_SC {
    optional uint32 lefttime = 1;
}

message realtime_guildteam_info {
    optional uint64 guildid = 1;
    optional string guildname = 2;
    optional uint32 leftnum = 3;
}

message MSG_RealTime_GuildPkTeam_Rank_SC {
    repeated realtime_guildteam_info teamrank = 1;    // type_name = .guildpk_msg.realtime_guildteam_info
}

message finalresult_guildteam_info {
    optional uint32 rank = 1;
    optional string name = 2;
    optional uint32 killnum = 3;
    optional uint32 totaldmg = 4;
}

message MSG_GuildPk_FinalResult_SC {
    optional bool iswin = 1;
    repeated finalresult_guildteam_info teamlist = 2;    // type_name = .guildpk_msg.finalresult_guildteam_info
}

message MSG_Ret_GuildPkEnroll_Finish_SC {
null
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "MSG_Req_GuildPkEnroll_CS"
    },
    [2] = {
        ["name"] = "MSG_Ret_GuildPkEnroll_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "GuildPkMemberInfo",
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
                ["name"] = "teamid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "GuildPkTeamInfo",
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
                ["name"] = "unlocklv",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guildpk_msg.GuildPkMemberInfo",
                ["name"] = "members"
            }
        }
    },
    [5] = {
        ["name"] = "GuildPkGuildInfo",
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
                ["name"] = "teamlimit",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guildpk_msg.GuildPkTeamInfo",
                ["name"] = "teaminfo"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Ret_GuildPkInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guildpk_msg.GuildPkGuildInfo",
                ["name"] = "guildinfo"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_Req_GuildPkInfo_CS"
    },
    [8] = {
        ["name"] = "MSG_Req_GuildPkJoinTeam_CS",
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
                ["name"] = "posid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_Req_GuildPkQuitTeam_CS"
    },
    [10] = {
        ["name"] = "MSG_Refresh_GuildPkMemberInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guildpk_msg.GuildPkMemberInfo",
                ["name"] = "member"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_Req_GuildPkRank_CS"
    },
    [12] = {
        ["name"] = "GuildPkGuildScore",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rank",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "guildid",
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
                ["type"] = "TYPE_UINT32",
                ["name"] = "score",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_Ret_GuildPkRank_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guildpk_msg.GuildPkGuildScore",
                ["name"] = "scorerank"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_Req_GuildPkWinList_CS"
    },
    [15] = {
        ["name"] = "GuildPkWinInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "uid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "win_guild_name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "win_leader_name",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_Ret_GuildPkWinList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guildpk_msg.GuildPkWinInfo",
                ["name"] = "winers"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_Ret_GuildPkMatchResult_SC",
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
            }
        }
    },
    [18] = {
        ["name"] = "MSG_Req_EnterGuildPk_CS"
    },
    [19] = {
        ["name"] = "MSG_Ret_GuildPkCountDown_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lefttime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_Ret_GuildPkFight_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lefttime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [21] = {
        ["name"] = "realtime_guildteam_info",
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
                ["name"] = "leftnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_RealTime_GuildPkTeam_Rank_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guildpk_msg.realtime_guildteam_info",
                ["name"] = "teamrank"
            }
        }
    },
    [23] = {
        ["name"] = "finalresult_guildteam_info",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rank",
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
                ["name"] = "killnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "totaldmg",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_GuildPk_FinalResult_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "iswin",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".guildpk_msg.finalresult_guildteam_info",
                ["name"] = "teamlist"
            }
        }
    },
    [25] = {
        ["name"] = "MSG_Ret_GuildPkEnroll_Finish_SC"
    }
},
["dependency"] = {
    [1] = "msg_enum.proto"
},
["name"] = "guildpk_msg.proto",
["package"] = "guildpk_msg"

----- end of proto -----
