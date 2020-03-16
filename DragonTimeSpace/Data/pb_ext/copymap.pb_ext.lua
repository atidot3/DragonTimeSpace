name = copymap.proto

package copymap;

message MSG_Req_CopymapEnterInfo_CS {
    optional uint32 copymapidx = 1;
}

message MSG_Ret_CopymapEnterInfo_SC {
    optional uint32 copymapidx = 1;
    optional uint32 remain_times = 2;
}

message MSG_Req_EnterCopymap_CS {
    optional uint32 copymapidx = 1;
}

message MSG_Req_ExitCopymap_SC {
null
}

message MSG_Ret_TriggerEnter_SC {
    optional string userid = 1;
    optional uint32 copymapid = 2;
}

message MSG_ReqBackCopymap_CS {
null
}

message RewardsObjectInfo {
    repeated t_Object objs = 1;    // type_name = .Obj.t_Object
    optional uint32 userid = 2;
}

message MSG_Ret_CopymapOver_SC {
    optional OverType type = 1;    // type_name = .copymap.OverType
    optional uint32 kickusertime = 2;
    optional uint32 exp = 3;
    repeated MSG_RetCurrencyChange_SC money = 4;    // type_name = .massive.MSG_RetCurrencyChange_SC
    optional RewardsObjectInfo items = 5;    // type_name = .copymap.RewardsObjectInfo
}

message MSG_RetAwardQuest_SC {
    optional uint32 questid = 1;
    optional uint32 scorevar = 2;
    optional RewardsObjectInfo items = 3;    // type_name = .copymap.RewardsObjectInfo
}

message MSG_Req_CopymapLottery_CS {
null
}

message MSG_Ret_CopymapLottery_SC {
    repeated RewardsObjectInfo items = 1;    // type_name = .copymap.RewardsObjectInfo
}

message MSG_Req_CopymapGather_CS {
    optional uint32 copymapidx = 1;
}

message MSG_Ret_CopymapGatherReq_SC {
    optional string leader = 1;
    optional uint32 leader_career = 2;
    optional uint32 copymapidx = 3;
    optional uint32 countdown = 4;
}

message MSG_Req_CopymapAnswerGather_CS {
    optional bool agree = 1;
}

message CopymapGatherItem {
    optional string name = 1;
    optional string charid = 2;
    optional MemberGatherState state = 3;    // type_name = .copymap.MemberGatherState
    optional uint32 heroid = 4;
}

message MSG_Ret_CopymapGatherData_SC {
    repeated CopymapGatherItem data = 1;    // type_name = .copymap.CopymapGatherItem
    optional GatherState state = 2;    // type_name = .copymap.GatherState
    optional uint32 countdown = 3;
    optional uint32 copymapidx = 4;
}

message MSG_Req_CopymapGatherQuickEnter_CS {
null
}

message MSG_Req_CopymapReGather_CS {
null
}

message MSG_Ret_CopymapReGather_SC {
    optional uint32 copymapidx = 1;
}

message MSG_Ret_CopymapBossTempID_SC {
    repeated string tempid = 1;
}

message AdventureCopymapGroup {
    optional uint32 adventureid = 1;
    optional uint32 complete_rate = 2;
    optional bool unlock = 3;
}

message MSG_Req_AdventureCopymapGroup_CS {
null
}

message MSG_Ret_AdventureCopymapGroup_SC {
    repeated AdventureCopymapGroup groups = 1;    // type_name = .copymap.AdventureCopymapGroup
}

message AdventureCopymap {
    optional uint32 copymapidx = 1;
    optional bool unlock = 2;
    optional uint32 star = 3;
    optional bool first_success = 4;
}

message MSG_Req_AdventureCopymapInfo_CS {
    optional uint32 adventureid = 1;
}

message MSG_Ret_AdventureCopymapInfo_SC {
    repeated AdventureCopymap copymaps = 1;    // type_name = .copymap.AdventureCopymap
}

message MSG_Req_AdventureHeros_CS {
    optional uint32 adventureid = 1;
}

message MSG_Ret_AdventureHeros_SC {
    repeated uint32 heros = 1;
    optional uint32 retcode = 2 [default = 0];
}

message MSG_Req_EnterAdventureCopymap_CS {
    optional uint32 heroid = 1;
    optional uint32 copymapidx = 2;
}

message ObjectData {
    optional uint32 objid = 1;
    optional uint32 objnum = 2;
}

message MSG_Ret_TrainData_SC {
    optional uint32 starttime = 1;
    optional uint32 endtime = 2;
    repeated ObjectData reward = 3;    // type_name = .copymap.ObjectData
}

message MSG_Ret_PlayEventData_SC {
    optional uint32 eventid = 1;
    optional uint32 starttime = 2;
    optional uint32 endtime = 3;
}

message MSG_Ret_CurMonsterGroup_SC {
    optional uint32 groupid = 1;
}

message MSG_Req_PlayGameData_CS {
    optional uint32 step = 1;
    optional uint32 success = 2;
    optional uint32 type = 3;
}

message MSG_Req_PlayGameRetry_CS {
    optional uint32 type = 1;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "OverType",
        ["value"] = {
            [1] = {
                ["name"] = "OVERMAP_ALLUSER_DEATH",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "OVERMAP_KILL_ONEBOSS",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "OVERMAP_KILL_ALLBOSS",
                ["number"] = 4
            },
            [4] = {
                ["name"] = "OVERMAP_TIME_OVER",
                ["number"] = 8
            }
        }
    },
    [2] = {
        ["name"] = "MemberGatherState",
        ["value"] = {
            [1] = {
                ["name"] = "Gather_None",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "Gather_Agree",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "Gather_Deny",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "Gather_Times_NotEnough",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "Gather_Offline_Deny",
                ["number"] = 4
            }
        }
    },
    [3] = {
        ["name"] = "GatherState",
        ["value"] = {
            [1] = {
                ["name"] = "CPGather_None",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "CPGather_Start",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "CPGather_Success",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "CPGather_Failed",
                ["number"] = 3
            }
        }
    }
},
["package"] = "copymap",
["name"] = "copymap.proto",
["dependency"] = {
    [1] = "massive.proto",
    [2] = "object.proto"
},
["message_type"] = {
    [1] = {
        ["name"] = "MSG_Req_CopymapEnterInfo_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "copymapidx",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Ret_CopymapEnterInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "copymapidx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "remain_times",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_Req_EnterCopymap_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "copymapidx",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Req_ExitCopymap_SC"
    },
    [5] = {
        ["name"] = "MSG_Ret_TriggerEnter_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "userid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "copymapid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_ReqBackCopymap_CS"
    },
    [7] = {
        ["name"] = "RewardsObjectInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.t_Object",
                ["name"] = "objs"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "userid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Ret_CopymapOver_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".copymap.OverType",
                ["name"] = "type"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "kickusertime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "exp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".massive.MSG_RetCurrencyChange_SC",
                ["name"] = "money"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".copymap.RewardsObjectInfo",
                ["name"] = "items"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_RetAwardQuest_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "scorevar",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".copymap.RewardsObjectInfo",
                ["name"] = "items"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_Req_CopymapLottery_CS"
    },
    [11] = {
        ["name"] = "MSG_Ret_CopymapLottery_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".copymap.RewardsObjectInfo",
                ["name"] = "items"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_Req_CopymapGather_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "copymapidx",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_Ret_CopymapGatherReq_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "leader",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "leader_career",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "copymapidx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "countdown",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_Req_CopymapAnswerGather_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "agree",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "CopymapGatherItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".copymap.MemberGatherState",
                ["name"] = "state"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_Ret_CopymapGatherData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".copymap.CopymapGatherItem",
                ["name"] = "data"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".copymap.GatherState",
                ["name"] = "state"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "countdown",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "copymapidx",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_Req_CopymapGatherQuickEnter_CS"
    },
    [18] = {
        ["name"] = "MSG_Req_CopymapReGather_CS"
    },
    [19] = {
        ["name"] = "MSG_Ret_CopymapReGather_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "copymapidx",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_Ret_CopymapBossTempID_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "tempid",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [21] = {
        ["name"] = "AdventureCopymapGroup",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "adventureid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "complete_rate",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "unlock",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_Req_AdventureCopymapGroup_CS"
    },
    [23] = {
        ["name"] = "MSG_Ret_AdventureCopymapGroup_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".copymap.AdventureCopymapGroup",
                ["name"] = "groups"
            }
        }
    },
    [24] = {
        ["name"] = "AdventureCopymap",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "copymapidx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "unlock",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "star",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_BOOL",
                ["name"] = "first_success",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [25] = {
        ["name"] = "MSG_Req_AdventureCopymapInfo_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "adventureid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [26] = {
        ["name"] = "MSG_Ret_AdventureCopymapInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".copymap.AdventureCopymap",
                ["name"] = "copymaps"
            }
        }
    },
    [27] = {
        ["name"] = "MSG_Req_AdventureHeros_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "adventureid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [28] = {
        ["name"] = "MSG_Ret_AdventureHeros_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heros",
                ["label"] = "LABEL_REPEATED"
            },
            [2] = {
                ["number"] = 2,
                ["default_value"] = "0",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode"
            }
        }
    },
    [29] = {
        ["name"] = "MSG_Req_EnterAdventureCopymap_CS",
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
                ["name"] = "copymapidx",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [30] = {
        ["name"] = "ObjectData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [31] = {
        ["name"] = "MSG_Ret_TrainData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "starttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "endtime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".copymap.ObjectData",
                ["name"] = "reward"
            }
        }
    },
    [32] = {
        ["name"] = "MSG_Ret_PlayEventData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "eventid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "starttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "endtime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [33] = {
        ["name"] = "MSG_Ret_CurMonsterGroup_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "groupid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [34] = {
        ["name"] = "MSG_Req_PlayGameData_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "step",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "success",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [35] = {
        ["name"] = "MSG_Req_PlayGameRetry_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
}

----- end of proto -----
