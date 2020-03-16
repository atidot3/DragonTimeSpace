name = battle.proto

package battle;

message MatchMember {
    optional uint64 userid = 1;
    optional uint64 captain = 2;
    optional uint32 heroid = 3;
    optional string name = 4;
    optional uint32 level = 5;
    optional uint32 camp = 6;
    optional uint64 gid = 7;
}

message MSG_ReqBattleTimes_CS {
    optional uint32 battleId = 1;
}

message MSG_RetBattleTimes_SC {
    optional uint32 winBattleTimes = 1;
}

message MSG_ReqBattleMatch_CS {
    optional uint32 battleId = 1;
}

message MSG_ReqBattleMatch_SC {
    optional BatteMatchCode errorCode = 1;    // type_name = .battle.BatteMatchCode
    optional uint64 averWaitTime = 2;
}

message MSG_ReqBattleCancelMatch_CS {
    optional uint32 battleId = 1;
}

message MSG_ReqBattleCancelMatch_SC {
    optional CancelBatteMatchCode errorCode = 1;    // type_name = .battle.CancelBatteMatchCode
}

message MSG_RetMatchMember_SC {
    repeated MatchMember members = 1;    // type_name = .battle.MatchMember
}

message MSG_RetBattleValid_SC {
    optional uint32 endTimeStamp = 1;
}

message MSG_ReqEnterBattle_CS {
null
}

message MSG_retEnterBattle_SC {
    optional EnterBattleCode errorCode = 1;    // type_name = .battle.EnterBattleCode
}

message MSG_ReqChangeGroupLeader_CS {
    optional uint64 newCaptain = 1;
}

message HoldFlagReport {
    optional string name = 1;
    optional uint32 campId = 2;
    optional uint32 teamId = 3;
    optional uint64 userid = 4;
    optional uint32 hurtNum = 5;
    optional uint32 cureNum = 6;
    optional uint32 killNum = 7;
    optional uint32 deadNum = 8;
    optional uint32 backDBNum = 9;
    optional uint32 captureDBNum = 10;
}

message HoldFlagCampScore {
    optional uint32 campId = 1;
    optional uint32 score = 2;
}

message HoldFlagDBState {
    optional uint64 tempId = 1;
    optional uint32 campId = 2;
    optional bool DBState = 3;
    optional uint64 capUserId = 4;
    optional bool isInBase = 5;
}

message MSG_RetHoldFlagTeamScore_SC {
    repeated HoldFlagCampScore campScore = 1;    // type_name = .battle.HoldFlagCampScore
}

message MSG_RetHoldFlagDBState_SC {
    repeated HoldFlagDBState DBStates = 1;    // type_name = .battle.HoldFlagDBState
}

message MSG_ReqHoldFlagReport_CS {
null
}

message MSG_ReqHoldFlagCaptureDB_CS {
    optional uint64 npcid = 1;
}

message MSG_ReqHoldFlagPutDownDB_CS {
null
}

message MSG_RetHoldFlagReport_SC {
    repeated HoldFlagReport reports = 1;    // type_name = .battle.HoldFlagReport
}

message MSG_RetHoldFlagAccount_SC {
    repeated HoldFlagReport reports = 1;    // type_name = .battle.HoldFlagReport
    optional uint32 winCampId = 2;
}

message MSG_RetHoldFlagCountDown_SC {
    optional HoldFlagStage stage = 1;    // type_name = .battle.HoldFlagStage
    optional uint32 endTimeStamp = 2;
}

message MSG_RetHoldFlagEvent_SC {
    optional uint32 tipId = 1;
    optional uint32 camp = 2;
    optional string userName = 3;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "BatteMatchCode",
        ["value"] = {
            [1] = {
                ["name"] = "BATTLE_MATCH_SUCCESS",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "BATTLE_MATCH_LEVEL_FAILED",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "BATTLE_MATCH_COPYMAP_FAILED",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "BATTLE_MATCH_MATCHING_FAILED",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "BATTLE_MATCH_TEAMLEVEL_FAILED",
                ["number"] = 5
            },
            [6] = {
                ["name"] = "BATTLE_MATCH_TEAMRIGHT_FAILED",
                ["number"] = 6
            },
            [7] = {
                ["name"] = "BATTLE_MATCH_MEMBEROFFLINE_FAILED",
                ["number"] = 7
            },
            [8] = {
                ["name"] = "BATTLE_MATCH_TIME_FAILED",
                ["number"] = 8
            }
        }
    },
    [2] = {
        ["name"] = "CancelBatteMatchCode",
        ["value"] = {
            [1] = {
                ["name"] = "BATTLE_CANCELMATCH_SUCCESS",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "BATTLE_CANCELMATCH_TEAMRIGHT_FAILED",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "BATTLE_CANCELMATCH_NOMATCH_FAILED",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "BATTLE_CANCELMATCH_INTER_FAILED",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "BATTLE_CANCELMATCH_MATCHOVER_FAILED",
                ["number"] = 5
            }
        }
    },
    [3] = {
        ["name"] = "CreateBattleCode",
        ["value"] = {
            [1] = {
                ["name"] = "BATTLE_CREATE_ALL_SUCCESS",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "BATTLE_CREATE_SESSION_NOSCENE_FAILED",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "BATTLE_CREATE_SESSION_CPMCREATE_FAILED",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "BATTLE_CREATE_SESSION_NOCPM_FAILED",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "BATTLE_CREATE_SESSION_SCENEEXIST_FAILED",
                ["number"] = 5
            },
            [6] = {
                ["name"] = "BATTLE_CREATE_SESSION_MEMERR_FAILED",
                ["number"] = 6
            },
            [7] = {
                ["name"] = "BATTLE_CREATE_SESSION_SCENEMGR_FAILED",
                ["number"] = 7
            },
            [8] = {
                ["name"] = "BATTLE_CREATE_SESSION_FINDSCENE_FAILED",
                ["number"] = 8
            },
            [9] = {
                ["name"] = "BATTLE_CREATE_SCENE_CPMCREATE_FAILED",
                ["number"] = 9
            },
            [10] = {
                ["name"] = "BATTLE_CREATE_SCENE_REG_FAILED",
                ["number"] = 10
            },
            [11] = {
                ["name"] = "BATTLE_CREATE_FUNCTION_CREATE_FAILED",
                ["number"] = 11
            },
            [12] = {
                ["name"] = "BATTLE_CREATE_FUNCTION_CREATEROOM_FAILED",
                ["number"] = 12
            }
        }
    },
    [4] = {
        ["name"] = "EnterBattleCode",
        ["value"] = {
            [1] = {
                ["name"] = "BATTLE_ENTER_SUCCESS",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "BATTLE_ENTER_INCOPYMAP_FAILED",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "BATTLE_ENTER_ENTERROOM_FAILED",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "BATTLE_ENTER_OVERTIME_FAILED",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "BATTLE_ENTER_NOROOM_FAILED",
                ["number"] = 5
            },
            [6] = {
                ["name"] = "BATTLE_ENTER_KICKED_FAILED",
                ["number"] = 6
            }
        }
    },
    [5] = {
        ["name"] = "Camp",
        ["value"] = {
            [1] = {
                ["name"] = "NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "RED",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "BLUE",
                ["number"] = 2
            }
        }
    },
    [6] = {
        ["name"] = "HoldFlagStage",
        ["value"] = {
            [1] = {
                ["name"] = "HOLD_FLAG_STAGE_NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "HOLD_FLAG_STAGE_ENTER",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "HOLD_FLAG_STAGE_PREPARE",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "HOLD_FLAG_STAGE_FIGHT",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "HOLD_FLAG_STAGE_ACCOUNT",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "HOLD_FLAG_STAGE_MAX",
                ["number"] = 5
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "MatchMember",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "userid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "captain",
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
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "camp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT64",
                ["name"] = "gid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_ReqBattleTimes_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "battleId",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_RetBattleTimes_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "winBattleTimes",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_ReqBattleMatch_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "battleId",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_ReqBattleMatch_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".battle.BatteMatchCode",
                ["name"] = "errorCode"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "averWaitTime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_ReqBattleCancelMatch_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "battleId",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_ReqBattleCancelMatch_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".battle.CancelBatteMatchCode",
                ["name"] = "errorCode"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_RetMatchMember_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".battle.MatchMember",
                ["name"] = "members"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_RetBattleValid_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "endTimeStamp",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_ReqEnterBattle_CS"
    },
    [11] = {
        ["name"] = "MSG_retEnterBattle_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".battle.EnterBattleCode",
                ["name"] = "errorCode"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_ReqChangeGroupLeader_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "newCaptain",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "HoldFlagReport",
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
                ["name"] = "campId",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "teamId",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT64",
                ["name"] = "userid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hurtNum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cureNum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "killNum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "deadNum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "backDBNum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "captureDBNum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "HoldFlagCampScore",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "campId",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "score",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "HoldFlagDBState",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempId",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "campId",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "DBState",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT64",
                ["name"] = "capUserId",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isInBase",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_RetHoldFlagTeamScore_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".battle.HoldFlagCampScore",
                ["name"] = "campScore"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_RetHoldFlagDBState_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".battle.HoldFlagDBState",
                ["name"] = "DBStates"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_ReqHoldFlagReport_CS"
    },
    [19] = {
        ["name"] = "MSG_ReqHoldFlagCaptureDB_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "npcid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_ReqHoldFlagPutDownDB_CS"
    },
    [21] = {
        ["name"] = "MSG_RetHoldFlagReport_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".battle.HoldFlagReport",
                ["name"] = "reports"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_RetHoldFlagAccount_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".battle.HoldFlagReport",
                ["name"] = "reports"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "winCampId",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [23] = {
        ["name"] = "MSG_RetHoldFlagCountDown_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".battle.HoldFlagStage",
                ["name"] = "stage"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "endTimeStamp",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_RetHoldFlagEvent_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "tipId",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "camp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "userName",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "battle.proto",
["package"] = "battle"

----- end of proto -----
