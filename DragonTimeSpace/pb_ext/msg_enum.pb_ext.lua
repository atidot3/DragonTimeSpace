name = msg_enum.proto

package msg;

message EntryIDType {
    optional uint64 id = 1;
    optional uint32 type = 2;
}

message Position {
    optional float x = 1;
    optional float y = 2;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "MapDataType",
        ["value"] = {
            [1] = {
                ["name"] = "MAP_DATATYPE_USER",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "MAP_DATATYPE_NPC",
                ["number"] = 1
            }
        }
    },
    [2] = {
        ["name"] = "UserCharbaseState",
        ["value"] = {
            [1] = {
                ["name"] = "CHARBASE_OK",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "CHARBASE_FORBID",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "CHARBASE_FORBID_NAME",
                ["number"] = 4
            }
        }
    },
    [3] = {
        ["name"] = "LoginRetCode",
        ["value"] = {
            [1] = {
                ["name"] = "LOGIN_RETURN_UNKNOWN",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "LOGIN_RETURN_VERSIONERROR",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "LOGIN_RETURN_UUID",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "LOGIN_RETURN_DB",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "LOGIN_RETURN_PASSWORDERROR",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "LOGIN_RETURN_CHANGEPASSWORD",
                ["number"] = 5
            },
            [7] = {
                ["name"] = "LOGIN_RETURN_IDINUSE",
                ["number"] = 6
            },
            [8] = {
                ["name"] = "LOGIN_RETURN_IDINCLOSE",
                ["number"] = 7
            },
            [9] = {
                ["name"] = "LOGIN_RETURN_GATEWAYNOTAVAILABLE",
                ["number"] = 8
            },
            [10] = {
                ["name"] = "LOGIN_RETURN_USERMAX",
                ["number"] = 9
            },
            [11] = {
                ["name"] = "LOGIN_RETURN_ACCOUNTEXIST",
                ["number"] = 10
            },
            [12] = {
                ["name"] = "LOGIN_RETURN_ACCOUNTSUCCESS",
                ["number"] = 11
            },
            [13] = {
                ["name"] = "LOGIN_RETURN_CHARNAMEREPEAT",
                ["number"] = 12
            },
            [14] = {
                ["name"] = "LOGIN_RETURN_USERDATANOEXIST",
                ["number"] = 13
            },
            [15] = {
                ["name"] = "LOGIN_RETURN_USERNAMEREPEAT",
                ["number"] = 14
            },
            [16] = {
                ["name"] = "LOGIN_RETURN_TIMEOUT",
                ["number"] = 15
            },
            [17] = {
                ["name"] = "LOGIN_RETURN_PAYFAILED",
                ["number"] = 16
            },
            [18] = {
                ["name"] = "LOGIN_RETURN_JPEG_PASSPORT",
                ["number"] = 17
            },
            [19] = {
                ["name"] = "LOGIN_RETURN_LOCK",
                ["number"] = 18
            },
            [20] = {
                ["name"] = "LOGIN_RETURN_WAITACTIVE",
                ["number"] = 19
            },
            [21] = {
                ["name"] = "LOGIN_RETURN_NEWUSER_OLDZONE",
                ["number"] = 20
            },
            [22] = {
                ["name"] = "LOGIN_RETURN_UUID_ERROR",
                ["number"] = 21
            },
            [23] = {
                ["name"] = "LOGIN_RETURN_USER_TOZONE",
                ["number"] = 22
            },
            [24] = {
                ["name"] = "LOGIN_RETURN_CHANGE_LOGIN",
                ["number"] = 23
            },
            [25] = {
                ["name"] = "LOGIN_RETURN_MATRIX_ERROR",
                ["number"] = 24
            },
            [26] = {
                ["name"] = "LOGIN_RETURN_MATRIX_NEED",
                ["number"] = 25
            },
            [27] = {
                ["name"] = "LOGIN_RETURN_MATRIX_LOCK",
                ["number"] = 26
            },
            [28] = {
                ["name"] = "LOGIN_RETURN_MATRIX_DOWN",
                ["number"] = 27
            },
            [29] = {
                ["name"] = "LOGIN_RETURN_OLDUSER_NEWZONE",
                ["number"] = 28
            },
            [30] = {
                ["name"] = "LOGIN_RETURN_IMG_LOCK",
                ["number"] = 29
            },
            [31] = {
                ["name"] = "LOGIN_RETURN_PASSPOD_PASSWORDERROR",
                ["number"] = 30
            },
            [32] = {
                ["name"] = "LOGIN_RETURN_PASSPOD_DOWN",
                ["number"] = 31
            },
            [33] = {
                ["name"] = "LOGIN_RETURN_BUSY",
                ["number"] = 32
            },
            [34] = {
                ["name"] = "LOGIN_RETURN_FORBID",
                ["number"] = 33
            },
            [35] = {
                ["name"] = "LOGIN_RETURN_IMG_LOCK2",
                ["number"] = 34
            },
            [36] = {
                ["name"] = "LOGIN_RETURN_MAINTAIN",
                ["number"] = 35
            },
            [37] = {
                ["name"] = "LOGIN_RETURN_TDCODE_GEN_ERROR",
                ["number"] = 36
            },
            [38] = {
                ["name"] = "LOGIN_RETURN_TDCODE_DOWN",
                ["number"] = 37
            },
            [39] = {
                ["name"] = "LOGIN_RETURN_TOKEN_ERROR",
                ["number"] = 38
            },
            [40] = {
                ["name"] = "LOGIN_RETURN_TOKEN_TOO_QUICK",
                ["number"] = 39
            },
            [41] = {
                ["name"] = "LOGIN_RETURN_TOKEN_TIMEOUT",
                ["number"] = 40
            },
            [42] = {
                ["name"] = "LOGIN_RETURN_SHOW_MSG",
                ["number"] = 41
            },
            [43] = {
                ["name"] = "LOGIN_RETURN_USERINLOGIN",
                ["number"] = 42
            },
            [44] = {
                ["name"] = "LOGIN_RETURN_CHARNAME_INVALID",
                ["number"] = 43
            },
            [45] = {
                ["name"] = "LOGIN_RETURN_GATEWAY_ID_INVALID",
                ["number"] = 44
            },
            [46] = {
                ["name"] = "LOGIN_RETURN_CHARNAME_LEN_ERR",
                ["number"] = 45
            },
            [47] = {
                ["name"] = "LOGIN_RETURN_ROLEMAX",
                ["number"] = 46
            },
            [48] = {
                ["name"] = "LOGIN_RETURN_ROLE_FORBID",
                ["number"] = 47
            }
        }
    },
    [4] = {
        ["name"] = "Occupation",
        ["value"] = {
            [1] = {
                ["name"] = "Occu_Dema",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "Occu_Yaohu",
                ["number"] = 2
            }
        }
    },
    [5] = {
        ["name"] = "QuestCrcRet",
        ["value"] = {
            [1] = {
                ["name"] = "CrcRet_Same",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "CrcRet_Diff",
                ["number"] = 2
            }
        }
    },
    [6] = {
        ["name"] = "ZonedefType",
        ["value"] = {
            [1] = {
                ["name"] = "ZONE_NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "ZONE_PK_SAFE",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "ZONE_ABSOLUTE_SAFE",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "ZONE_RELIVE",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "ZONE_NEWBIE",
                ["number"] = 8
            },
            [6] = {
                ["name"] = "ZONE_FOREIGN_RELIVE",
                ["number"] = 16
            },
            [7] = {
                ["name"] = "ZONE_GUILD",
                ["number"] = 32
            },
            [8] = {
                ["name"] = "ZONE_TRANSPORT",
                ["number"] = 64
            },
            [9] = {
                ["name"] = "ZONE_ENTER_COPYMAP",
                ["number"] = 128
            },
            [10] = {
                ["name"] = "ZONE_QUIT_COPYMAP",
                ["number"] = 256
            },
            [11] = {
                ["name"] = "ZONE_PVP_CAMP_RED",
                ["number"] = 512
            },
            [12] = {
                ["name"] = "ZONE_PVP_CAMP_BLUE",
                ["number"] = 1024
            },
            [13] = {
                ["name"] = "ZONE_PVP_COMMIT_RED",
                ["number"] = 2048
            },
            [14] = {
                ["name"] = "ZONE_PVP_COMMIT_BLUE",
                ["number"] = 4096
            },
            [15] = {
                ["name"] = "ZONE_PVP_RELIVE_RED",
                ["number"] = 8192
            },
            [16] = {
                ["name"] = "ZONE_PVP_RELIVE_BLUE",
                ["number"] = 16384
            }
        }
    },
    [7] = {
        ["name"] = "ReliveType",
        ["value"] = {
            [1] = {
                ["name"] = "RELIVE_NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "RELIVE_HOME",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "RELIVE_ORIGIN",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "RELIVE_GUILD",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "RELIVE_PKRAND",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "RELIVE_COUNTRY",
                ["number"] = 5
            },
            [7] = {
                ["name"] = "RELIVE_NEAREST",
                ["number"] = 6
            },
            [8] = {
                ["name"] = "RELIVE_BATTLE",
                ["number"] = 7
            },
            [9] = {
                ["name"] = "RELIVE_SKILL",
                ["number"] = 8
            }
        }
    },
    [8] = {
        ["name"] = "PKMode",
        ["value"] = {
            [1] = {
                ["name"] = "PKMode_None",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "PKMode_Peace",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "PKMode_Personal",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "PKMode_Guild",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "PKMode_Team",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "PKMode_Normal",
                ["number"] = 5
            }
        }
    },
    [9] = {
        ["name"] = "QuestState",
        ["value"] = {
            [1] = {
                ["name"] = "UNACCEPT",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "DOING",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "ACCEPTABLE",
                ["number"] = 99
            },
            [4] = {
                ["name"] = "FINISHED",
                ["number"] = 100
            },
            [5] = {
                ["name"] = "FINISHED_SAVE",
                ["number"] = 101
            },
            [6] = {
                ["name"] = "FINISHED_NOT_SAVE",
                ["number"] = 102
            }
        }
    },
    [10] = {
        ["name"] = "RefreshType",
        ["value"] = {
            [1] = {
                ["name"] = "RefreshType_None",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "RefreshType_DaxSix",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "RefreshType_MondaySix",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "RefreshType_MonthFirstSix",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "RefreshType_DayMany",
                ["number"] = 4
            }
        }
    },
    [11] = {
        ["name"] = "MATCHFIGHT",
        ["value"] = {
            [1] = {
                ["name"] = "FIGHT_NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "FIGHT_RANKPK",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "FIGHT_TILLDIE",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "FIGHT_RANDOM",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "FIGHT_MAX",
                ["number"] = 4
            }
        }
    },
    [12] = {
        ["name"] = "StageType",
        ["value"] = {
            [1] = {
                ["name"] = "None_Stage",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "Match",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "Login",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "Prepare",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "PreFight",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "CountDown",
                ["number"] = 5
            },
            [7] = {
                ["name"] = "Fight",
                ["number"] = 6
            },
            [8] = {
                ["name"] = "Speedup",
                ["number"] = 7
            },
            [9] = {
                ["name"] = "Finish",
                ["number"] = 8
            },
            [10] = {
                ["name"] = "Max_Stage",
                ["number"] = 9
            }
        }
    },
    [13] = {
        ["name"] = "MATCHFIGHTTEAMMODE",
        ["value"] = {
            [1] = {
                ["name"] = "SOLO",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "TEAM",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "BOTH",
                ["number"] = 3
            }
        }
    },
    [14] = {
        ["name"] = "MATCHFIGHTTEAM",
        ["value"] = {
            [1] = {
                ["name"] = "BLUE",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "RED",
                ["number"] = 2
            }
        }
    },
    [15] = {
        ["name"] = "FIGHTRESULT",
        ["value"] = {
            [1] = {
                ["name"] = "WIN",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "LOSE",
                ["number"] = 2
            }
        }
    },
    [16] = {
        ["name"] = "RISESTAR",
        ["value"] = {
            [1] = {
                ["name"] = "RISESTAR_SUCCESS",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "RISESTAR_THISIDERR",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "RISESTAR_BASEIDERR",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "RISESTAR_MAXSTARERR",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "RISESTAR_LOCKEDERR",
                ["number"] = 5
            }
        }
    },
    [17] = {
        ["name"] = "SEX",
        ["value"] = {
            [1] = {
                ["name"] = "NONE",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "MALE",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "FEMALE",
                ["number"] = 3
            }
        }
    },
    [18] = {
        ["name"] = "SELLTYPE",
        ["value"] = {
            [1] = {
                ["name"] = "SELLNONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "OBJECT",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "HERO",
                ["number"] = 2
            }
        }
    },
    [19] = {
        ["name"] = "CreateRoleLookType",
        ["value"] = {
            [1] = {
                ["name"] = "CREATE_ROLE_LOOK_TYPE_HAIR_COLOR",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "CREATE_ROLE_LOOK_TYPE_HAIR_STYLE",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "CREATE_ROLE_LOOK_TYPE_FACE_STYLE",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "CREATE_ROLE_LOOK_TYPE_ANTENNA",
                ["number"] = 4
            }
        }
    },
    [20] = {
        ["name"] = "AnswerShareQuestRetCode",
        ["value"] = {
            [1] = {
                ["name"] = "ANSWER_SHARE_QUEST_RET_CODE_SUCCESS",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "ANSWER_SHARE_QUEST_RET_CODE_NOT_EXIST",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "ANSWER_SHARE_QUEST_RET_CODE_LEVEL",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "ANSWER_SHARE_QUEST_RET_CODE_PREQUEST",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "ANSWER_SHARE_QUEST_RET_CODE_DOING",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "ANSWER_SHARE_QUEST_RET_CODE_DAILY_QUEST",
                ["number"] = 5
            },
            [7] = {
                ["name"] = "ANSWER_SHARE_QUEST_RET_CODE_OTHER",
                ["number"] = 6
            }
        }
    },
    [21] = {
        ["name"] = "ERechargeReturnCode",
        ["value"] = {
            [1] = {
                ["name"] = "ERECHARGE_RETURN_CODE_SUCCESS",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "ERECHARGE_RETURN_CODE_SERVICE_LOST",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "ERECHARGE_RETURN_CODE_ACCOUNT_NOT_FOUND",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "ERECHARGE_RETURN_CODE_NOT_ENOUGH",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "ERECHARGE_RETURN_CODE_CARD_NOT_FOUND",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "ERECHARGE_RETURN_CODE_CARD_CAN_NOT_USER",
                ["number"] = 5
            },
            [7] = {
                ["name"] = "ERECHARGE_RETURN_CODE_CARD_CAN_USE_MULTY",
                ["number"] = 6
            },
            [8] = {
                ["name"] = "ERECHARGE_RETURN_CODE_CARD_ERROR_NUMBER",
                ["number"] = 7
            },
            [9] = {
                ["name"] = "ERECHARGE_RETURN_CODE_CARD_ERROR_PSWD",
                ["number"] = 8
            },
            [10] = {
                ["name"] = "ERECHARGE_RETURN_CODE_DATABASE_ERROR",
                ["number"] = 9
            },
            [11] = {
                ["name"] = "ERECHARGE_RETURN_CODE_IN_PROCESSING",
                ["number"] = 10
            },
            [12] = {
                ["name"] = "ERECHARGE_RETURN_CODE_UNKNOWN_ERROR",
                ["number"] = 11
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "EntryIDType",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "id",
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
    [2] = {
        ["name"] = "Position",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "x",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "y",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "msg_enum.proto",
["package"] = "msg"

----- end of proto -----
