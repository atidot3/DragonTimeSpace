name = apprentice.proto

package apprentice;

message UserInfo {
    optional uint64 charid = 1;
    optional string name = 2;
    optional uint32 level = 3;
    optional string guildname = 4;
    optional uint32 education = 5;
    optional uint32 jointime = 6;
    optional uint32 maxfight = 7;
    optional uint32 career = 8;
    optional uint64 quit_charid = 9;
    optional uint32 quit_endtime = 10;
}

message SearchUserInfo {
    optional UserInfo data = 1;    // type_name = .apprentice.UserInfo
    optional uint32 condition_online = 2;
    optional uint32 condition_attitude = 3;
    optional string condition_notify = 4;
}

message MasterApprenticeInfo {
    optional UserInfo master = 1;    // type_name = .apprentice.UserInfo
    repeated UserInfo apprentice = 2;    // type_name = .apprentice.UserInfo
}

message MSG_Req_MasterApprenticeInfo_CS {
null
}

message MSG_Ret_MasterApprenticeInfo_SC {
    repeated MasterApprenticeInfo data = 1;    // type_name = .apprentice.MasterApprenticeInfo
    optional bool taking_master = 2;
}

message MSG_Req_ApprenticeList_CS {
null
}

message MSG_Ret_ApprenticeList_SC {
    repeated UserInfo data = 1;    // type_name = .apprentice.UserInfo
    optional bool taking_apprentice = 2;
}

message MSG_Req_MasterApprenticeCount_CS {
null
}

message MSG_Ret_MasterApprenticeCount_SC {
    optional uint32 max_master_count = 1;
    optional uint32 cur_master_count = 2 [default = 0];
    optional uint32 max_apprentice_count = 3;
    optional uint32 cur_apprentice_count = 4 [default = 0];
    optional uint32 punish_endtime = 5;
}

message MSG_Req_TakeMaster_CS {
    optional uint64 charid = 1;
}

message MSG_Ret_ApplyTakeMaster_SC {
    optional UserInfo applyer = 1;    // type_name = .apprentice.UserInfo
}

message MSG_Req_AnswerTakeMaster_CS {
    optional bool agree = 1;
    optional uint64 applyer = 2;
}

message MSG_Ret_TakeMaster_SC {
    optional bool agree = 1;
    optional uint32 retcode = 2;
    optional bool clear = 3 [default = true];
    optional uint64 clear_charid = 4;
}

message MSG_Req_TakeApprentice_CS {
    optional uint64 charid = 1;
}

message MSG_Ret_ApplyTakeApprentice_SC {
    optional UserInfo applyer = 1;    // type_name = .apprentice.UserInfo
}

message MSG_Req_AnswerTakeApprentice_CS {
    optional bool agree = 1;
    optional uint64 applyer = 2;
}

message MSG_Ret_TakeApprentice_SC {
    optional bool agree = 1;
    optional uint32 retcode = 2;
    optional bool clear = 3 [default = true];
    optional uint64 clear_charid = 4;
}

message MSG_Req_StartTakeApprentice_CS {
    optional uint32 condition_online = 1;
    optional uint32 condition_attitude = 2;
    optional string condition_notify = 3;
}

message MSG_Ret_StartTakeApprentice_SC {
    optional uint32 retcode = 1;
}

message MSG_Req_StartTakeMaster_CS {
    optional uint32 condition_online = 1;
    optional uint32 condition_attitude = 2;
    optional string condition_notify = 3;
}

message MSG_Ret_StartTakeMaster_SC {
    optional uint32 retcode = 1;
}

message MSG_Req_unpublishTakeMaster_CS {
    optional uint32 pub_type = 1;
}

message MSG_Ret_unpublishTakeMaster_SC {
    optional uint32 pub_type = 1;
    optional uint32 retcode = 2;
}

message MSG_Req_SearchMaster_CS {
    optional uint32 condition_online = 1;
    optional uint32 condition_attitude = 2;
}

message MSG_Ret_SearchMaster_SC {
    repeated SearchUserInfo data = 1;    // type_name = .apprentice.SearchUserInfo
}

message MSG_Req_SearchApprentice_CS {
    optional uint32 condition_online = 1;
    optional uint32 condition_attitude = 2;
}

message MSG_Ret_SearchApprentice_SC {
    repeated SearchUserInfo data = 1;    // type_name = .apprentice.SearchUserInfo
}

message MSG_Req_UserApprenticeInfo_CS {
    optional uint64 charid = 1;
    optional uint32 pub_type = 2;
}

message MSG_Ret_UserApprenticeInfo_SC {
    optional SearchUserInfo data = 1;    // type_name = .apprentice.SearchUserInfo
    optional uint32 pub_type = 2;
}

message MSG_Req_preQuitApprentice_CS {
    optional uint64 targetid = 1;
}

message MSG_Ret_preQuitApprentice_SC {
    optional uint64 targetid = 1;
    optional uint32 retcode = 2;
    optional uint32 quittime = 3;
    optional uint32 offlinetime = 4;
    optional uint32 punishtime = 5;
}

message MSG_Req_applyQuitApprentice_CS {
    optional uint64 targetid = 1;
}

message MSG_Ret_applyQuitApprentice_SC {
    optional uint64 targetid = 1;
    optional uint32 retcode = 2;
    optional uint32 quit_endtime = 3;
}

message MSG_Req_unQuitApprentice_CS {
    optional uint64 targetid = 1;
}

message MSG_Ret_unQuitApprentice_SC {
    optional uint64 targetid = 1;
    optional uint32 retcode = 2;
}

message MSG_Req_FinishApprentice_CS {
    optional uint64 apprentid = 1;
}

message MSG_Ret_FinishApprentice_SC {
    optional uint32 retcode = 1;
    optional uint64 apprentid = 2;
}

message MSG_Ret_ApprenticeChange_SC {
    optional ChangeType changetype = 1;    // type_name = .apprentice.ChangeType
    optional string otherid = 2;
}

message MSG_Req_OperateClientDatas_CS {
    optional uint32 op = 1;
    optional string key = 2;
    optional string value = 3;
    optional uint32 retcode = 4;
    optional uint32 type = 5;
}

message ClientSetInfo {
    optional string key = 1;
    optional uint32 value = 2;
}

message MassiveClientSetInfo {
    repeated ClientSetInfo data = 1;    // type_name = .apprentice.ClientSetInfo
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "ChangeType",
        ["value"] = {
            [1] = {
                ["name"] = "BE_MY_APPRENT",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "BE_MY_MASTER",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "QUIT",
                ["number"] = 3
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "UserInfo",
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
                ["type"] = "TYPE_STRING",
                ["name"] = "guildname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "education",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "jointime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxfight",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "career",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT64",
                ["name"] = "quit_charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "quit_endtime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "SearchUserInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.UserInfo",
                ["name"] = "data"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "condition_online",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "condition_attitude",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_STRING",
                ["name"] = "condition_notify",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MasterApprenticeInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.UserInfo",
                ["name"] = "master"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.UserInfo",
                ["name"] = "apprentice"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Req_MasterApprenticeInfo_CS"
    },
    [5] = {
        ["name"] = "MSG_Ret_MasterApprenticeInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.MasterApprenticeInfo",
                ["name"] = "data"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "taking_master",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Req_ApprenticeList_CS"
    },
    [7] = {
        ["name"] = "MSG_Ret_ApprenticeList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.UserInfo",
                ["name"] = "data"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "taking_apprentice",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Req_MasterApprenticeCount_CS"
    },
    [9] = {
        ["name"] = "MSG_Ret_MasterApprenticeCount_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "max_master_count",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["default_value"] = "0",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_UINT32",
                ["name"] = "cur_master_count"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "max_apprentice_count",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["default_value"] = "0",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_UINT32",
                ["name"] = "cur_apprentice_count"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "punish_endtime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_Req_TakeMaster_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_Ret_ApplyTakeMaster_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.UserInfo",
                ["name"] = "applyer"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_Req_AnswerTakeMaster_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "agree",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "applyer",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_Ret_TakeMaster_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "agree",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["default_value"] = "true",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "clear"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT64",
                ["name"] = "clear_charid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_Req_TakeApprentice_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_Ret_ApplyTakeApprentice_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.UserInfo",
                ["name"] = "applyer"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_Req_AnswerTakeApprentice_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "agree",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "applyer",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_Ret_TakeApprentice_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "agree",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["default_value"] = "true",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "clear"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT64",
                ["name"] = "clear_charid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_Req_StartTakeApprentice_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "condition_online",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "condition_attitude",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "condition_notify",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_Ret_StartTakeApprentice_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_Req_StartTakeMaster_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "condition_online",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "condition_attitude",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "condition_notify",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_Ret_StartTakeMaster_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_Req_unpublishTakeMaster_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pub_type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [23] = {
        ["name"] = "MSG_Ret_unpublishTakeMaster_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pub_type",
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
    [24] = {
        ["name"] = "MSG_Req_SearchMaster_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "condition_online",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "condition_attitude",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [25] = {
        ["name"] = "MSG_Ret_SearchMaster_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.SearchUserInfo",
                ["name"] = "data"
            }
        }
    },
    [26] = {
        ["name"] = "MSG_Req_SearchApprentice_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "condition_online",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "condition_attitude",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [27] = {
        ["name"] = "MSG_Ret_SearchApprentice_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.SearchUserInfo",
                ["name"] = "data"
            }
        }
    },
    [28] = {
        ["name"] = "MSG_Req_UserApprenticeInfo_CS",
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
                ["name"] = "pub_type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [29] = {
        ["name"] = "MSG_Ret_UserApprenticeInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.SearchUserInfo",
                ["name"] = "data"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pub_type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [30] = {
        ["name"] = "MSG_Req_preQuitApprentice_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "targetid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [31] = {
        ["name"] = "MSG_Ret_preQuitApprentice_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "targetid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "quittime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "offlinetime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "punishtime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [32] = {
        ["name"] = "MSG_Req_applyQuitApprentice_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "targetid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [33] = {
        ["name"] = "MSG_Ret_applyQuitApprentice_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "targetid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "quit_endtime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [34] = {
        ["name"] = "MSG_Req_unQuitApprentice_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "targetid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [35] = {
        ["name"] = "MSG_Ret_unQuitApprentice_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "targetid",
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
    [36] = {
        ["name"] = "MSG_Req_FinishApprentice_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "apprentid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [37] = {
        ["name"] = "MSG_Ret_FinishApprentice_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "apprentid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [38] = {
        ["name"] = "MSG_Ret_ApprenticeChange_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".apprentice.ChangeType",
                ["name"] = "changetype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "otherid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [39] = {
        ["name"] = "MSG_Req_OperateClientDatas_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "op",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "key",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "value",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [40] = {
        ["name"] = "ClientSetInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "key",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "value",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [41] = {
        ["name"] = "MassiveClientSetInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".apprentice.ClientSetInfo",
                ["name"] = "data"
            }
        }
    }
},
["name"] = "apprentice.proto",
["package"] = "apprentice"

----- end of proto -----
