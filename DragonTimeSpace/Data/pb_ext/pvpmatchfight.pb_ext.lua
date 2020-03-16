name = pvpmatchfight.proto

package pvpmatchfight;

message MSG_Req_StartPvPMatch_CS {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
}

message MSG_Ret_StartPvPMatch_SC {
    optional uint32 retcode = 1;
    required MATCHFIGHT matchtype = 2;    // type_name = .msg.MATCHFIGHT
}

message MSG_Req_CancelPvPMatch_CS {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
}

message MSG_Ret_CancelPvPMatch_SC {
    optional uint32 retcode = 1;
    required MATCHFIGHT matchtype = 2;    // type_name = .msg.MATCHFIGHT
}

message MSG_Ret_PvPMatchResult_SC {
    optional uint32 retcode = 1;
    required MATCHFIGHT matchtype = 2;    // type_name = .msg.MATCHFIGHT
}

message MSG_Req_GotoPvPBattle_CS {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
}

message MSG_ReqChoosePvPPrepared_CS {
null
}

message MSG_RetChoosePvPPrepared_SC {
    optional uint32 errcode = 1;
}

message MSG_RetStartPvPPrepare_SC {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
    optional uint32 duration = 2;
}

message MSG_RetPvPFightCountDown_SC {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
    optional uint32 duration = 2;
}

message MSG_RetPvPFightPreFight_SC {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
    optional uint32 duration = 2;
}

message MSG_RetStartPvPFight_SC {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
    optional uint32 duration = 2;
}

message MSG_RetPvPSpeedupFight_SC {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
    optional uint32 duration = 2;
}

message MSG_RetPvPFightFinish_SC {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
    optional uint32 duration = 2;
    required FIGHTRESULT result = 3;    // type_name = .msg.FIGHTRESULT
    optional PvPAwardItem award = 4;    // type_name = .pvpmatchfight.PvPAwardItem
}

message MSG_ReqPvPFightCurStage_CS {
null
}

message MSG_RetPvPFightCurStage_SC {
    required StageType curstage = 1;    // type_name = .msg.StageType
    optional uint32 leftsecs = 2;
    optional MSG_RetPvPTeamCurScore_SC scoreinfo = 3;    // type_name = .pvpmatchfight.MSG_RetPvPTeamCurScore_SC
    optional MSG_RetPvPMatchFightCurLive_SC liveinfo = 4;    // type_name = .pvpmatchfight.MSG_RetPvPMatchFightCurLive_SC
}

message MSG_RetPvPTeamCurScore_SC {
    optional uint32 team1id = 1;
    optional uint32 team1score = 2;
    optional uint32 team2id = 3;
    optional uint32 team2score = 4;
}

message MSG_RetPvPPreparedNum_SC {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
    optional uint32 curnum = 2;
    optional uint32 allnum = 3;
}

message PvPAwardItem {
    required FIGHTRESULT result = 1;    // type_name = .msg.FIGHTRESULT
    repeated ObjectItem item = 2;    // type_name = .basic.ObjectItem
    optional uint32 heroid = 3;
}

message MSG_ReqPvPDailyAwards_CS {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
}

message MSG_RetPvPDailyAwards_SC {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
    repeated PvPAwardItem rewardlist = 2;    // type_name = .pvpmatchfight.PvPAwardItem
}

message MSG_RetPvPPKGeneralConfig_SC {
    required MATCHFIGHT matchtype = 1;    // type_name = .msg.MATCHFIGHT
    optional uint32 teampknum = 2;
}

message onePlayerLive {
    optional string memid = 1;
    optional uint32 heroid = 2;
    optional bool isdead = 3;
    optional uint32 reliveleftsecs = 4;
}

message MSG_RetPvPMatchFightCurLive_SC {
    repeated onePlayerLive oneplayer = 1;    // type_name = .pvpmatchfight.onePlayerLive
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "MSG_Req_StartPvPMatch_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Ret_StartPvPMatch_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_Req_CancelPvPMatch_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Ret_CancelPvPMatch_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_Ret_PvPMatchResult_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Req_GotoPvPBattle_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_ReqChoosePvPPrepared_CS"
    },
    [8] = {
        ["name"] = "MSG_RetChoosePvPPrepared_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_RetStartPvPPrepare_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_RetPvPFightCountDown_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_RetPvPFightPreFight_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_RetStartPvPFight_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_RetPvPSpeedupFight_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_RetPvPFightFinish_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.FIGHTRESULT",
                ["name"] = "result"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".pvpmatchfight.PvPAwardItem",
                ["name"] = "award"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_ReqPvPFightCurStage_CS"
    },
    [16] = {
        ["name"] = "MSG_RetPvPFightCurStage_SC",
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
                ["name"] = "leftsecs",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".pvpmatchfight.MSG_RetPvPTeamCurScore_SC",
                ["name"] = "scoreinfo"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".pvpmatchfight.MSG_RetPvPMatchFightCurLive_SC",
                ["name"] = "liveinfo"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_RetPvPTeamCurScore_SC",
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
    [18] = {
        ["name"] = "MSG_RetPvPPreparedNum_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "allnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [19] = {
        ["name"] = "PvPAwardItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.FIGHTRESULT",
                ["name"] = "result"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".basic.ObjectItem",
                ["name"] = "item"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_ReqPvPDailyAwards_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_RetPvPDailyAwards_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".pvpmatchfight.PvPAwardItem",
                ["name"] = "rewardlist"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_RetPvPPKGeneralConfig_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.MATCHFIGHT",
                ["name"] = "matchtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "teampknum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [23] = {
        ["name"] = "onePlayerLive",
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
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isdead",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "reliveleftsecs",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_RetPvPMatchFightCurLive_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".pvpmatchfight.onePlayerLive",
                ["name"] = "oneplayer"
            }
        }
    }
},
["dependency"] = {
    [1] = "msg_enum.proto",
    [2] = "basic.proto"
},
["name"] = "pvpmatchfight.proto",
["package"] = "pvpmatchfight"

----- end of proto -----
