name = quest.proto

package quest;

message questCRC {
    optional uint32 quest_id = 1;
    optional uint32 branch_id = 2;
    optional uint32 crc = 3;
}

message validQuest {
    optional uint32 quest_id = 1;
    optional uint32 branch_id = 2;
}

message npcValidQuest {
    optional uint32 npcid = 1;
    optional uint32 questid = 2;
}

message MSG_Req_VisitNpcTrade_CS {
    optional uint64 npc_temp_id = 1;
    repeated questCRC allcrc = 2;    // type_name = .quest.questCRC
}

message MSG_Ret_VisitNpcTrade_SC {
    optional uint32 action = 1;
    optional uint32 retcode = 2;
    optional uint32 flag = 3;
    optional uint64 npc_temp_id = 4;
    optional uint32 type = 5;
    optional uint32 conv_exchange = 6;
    optional uint32 show_type = 7;
    optional uint32 crc_ret = 8;
    optional string user_menu = 9;
    optional string npc_menu = 10;
    repeated questCRC allcrc = 11;    // type_name = .quest.questCRC
    optional uint32 source = 12;
}

message MSG_Req_QuestInfo_CS {
    optional uint32 id = 1;
}

message UnorderQuestBranchInfo {
    optional string degreevar = 1;
    optional uint32 curvalue = 2;
    optional uint32 maxvalue = 3;
}

message MSG_Ret_QuestInfo_SC {
    optional uint32 id = 1;
    optional uint32 state = 2;
    optional uint32 score = 3;
    optional uint32 curvalue = 4;
    optional uint32 maxvalue = 5;
    optional uint32 starttime = 6;
    optional uint32 cur_extvalue = 7;
    optional uint32 max_extvalue = 8;
    optional int32 leftsecs = 9;
    repeated UnorderQuestBranchInfo extinfo = 10;    // type_name = .quest.UnorderQuestBranchInfo
    optional bool show = 11;
}

message MSG_ReqExecuteQuest_CS {
    optional uint32 id = 1;
    optional string target = 2;
    optional uint32 offset = 3;
    optional uint32 questdesccrc = 4;
    optional uint64 chartarget = 5;
}

message MSG_ReqValidQuests_CS {
null
}

message MSG_RetValidQuests_SC {
    repeated npcValidQuest onequest = 1;    // type_name = .quest.npcValidQuest
}

message MSG_ReqRetQuestState_CSC {
    optional uint32 id = 1;
    optional uint32 state = 2;
}

message MSG_ReqAbandonQuest_CS {
    optional uint32 id = 1;
}

message MSG_RetAbandonQuest_SC {
    optional uint32 id = 1;
}

message QuestStateInfo {
    optional uint32 questid = 1;
    optional uint32 state = 2;
}

message npcQuestList {
    optional uint32 npcid = 1;
    repeated QuestStateInfo quests = 2;    // type_name = .quest.QuestStateInfo
    optional int32 state = 3;
}

message MSG_ReqMapQuestInfo_CS {
null
}

message MSG_RetMapQuestInfo_SC {
    repeated npcQuestList npclists = 1;    // type_name = .quest.npcQuestList
}

message MSG_ReqCurActiveQuest_CS {
null
}

message ringQuestInfo {
    optional uint32 mainquestid = 1;
    optional uint32 finishringnum = 2;
}

message MSG_RetCurActiveQuest_SC {
    repeated MSG_Ret_QuestInfo_SC item = 1;    // type_name = .quest.MSG_Ret_QuestInfo_SC
    repeated npcValidQuest newaccept = 2;    // type_name = .quest.npcValidQuest
    optional string dayvar = 3;
    repeated ringQuestInfo ringinfo = 4;    // type_name = .quest.ringQuestInfo
}

message MSG_ReqChangeMapFindPath_CS {
    optional uint32 pathwayid = 1;
    optional uint32 questid = 2;
    optional uint32 destx = 3;
    optional uint32 desty = 4;
}

message MSG_RetChangeMapFindPath_SC {
    optional ChangeMapFindWayInfo info = 1;    // type_name = .quest.ChangeMapFindWayInfo
}

message ChangeMapFindWayInfo {
    optional uint32 errcode = 1;
    optional uint32 pathwayid = 2;
    optional uint32 destmapid = 3;
    optional bool findingway = 4 [default = false];
}

message MSG_RetPlotTalkID_SC {
    optional uint32 groupid = 1;
}

message MSG_CartoonCompleteNotify_SC {
    optional uint32 groupid = 1;
    optional string command = 2;
    optional uint32 delay = 3;
}

message MSG_PlayCartoonAndGoMap_SC {
    optional uint32 groupid = 1;
    optional string command = 2;
    optional uint32 delay = 3;
    optional uint32 callbackid = 4;
}

message MSG_ReqSubmitObjs_CS {
    repeated string thisid = 1;
    optional uint32 bagid = 2;
}

message MSG_RetSubmitObjs_SC {
    optional uint32 retcode = 1;
}

message RingQuestRingCount {
    optional uint32 questtype = 1;
    optional uint32 ring_count = 2;
}

message MSG_RetRingQuestRingCount_SC {
    repeated RingQuestRingCount ringcount = 1;    // type_name = .quest.RingQuestRingCount
}

message MSG_notifyRefreshQuestInfo_SC {
    repeated MSG_Ret_QuestInfo_SC item = 1;    // type_name = .quest.MSG_Ret_QuestInfo_SC
}

message MSG_PlayBellQTE_SC {
    optional uint32 qtelevel = 1;
}

message MSG_PlayBellQTEResult_CS {
    optional uint32 qtelevel = 1;
    optional uint32 result = 2;
}

message MSG_Req_SetQuestNeedShow_CS {
    optional uint32 questid = 1;
    optional bool show = 2;
}

message MSG_Ret_SetQuestNeedShow_SC {
    optional uint32 questid = 1;
    optional bool result = 2;
    optional bool code = 3;
}

message MSG_Req_ShareQuestToTeamMember_CS {
    optional uint32 questid = 1;
}

message MSG_Ret_NotifyShareQuest_SC {
    optional string name = 1;
    optional uint32 questid = 2;
}

message MSG_Req_AnswerShareQuest_CS {
    optional uint32 questid = 1;
    optional bool accept = 2;
}

message MSG_Ret_AnswerShareQuest_SC {
    optional uint32 code = 1;
}

message MSG_Ret_NotifyCountDown_SC {
    optional bool bset = 1;
    optional uint32 delay = 2;
    optional uint32 seconds = 3;
}

message MSG_NotifyClientOptional_SC {
    optional uint32 type = 1;
    optional string setting = 2;
}

message MSG_notifyQuestStateEffect_SC {
    optional uint32 questid = 1;
    optional uint32 state = 2;
}

message MSG_Req_CommitYQDData_CS {
    optional uint32 step = 1;
    optional uint32 success = 2;
    optional uint32 type = 3;
}

message MSG_Req_PlayYQDRetry_CS {
    optional uint32 type = 1;
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "questCRC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "quest_id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "branch_id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "crc",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "validQuest",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "quest_id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "branch_id",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "npcValidQuest",
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
                ["name"] = "questid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Req_VisitNpcTrade_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "npc_temp_id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.questCRC",
                ["name"] = "allcrc"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_Ret_VisitNpcTrade_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "action",
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
                ["name"] = "flag",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT64",
                ["name"] = "npc_temp_id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "conv_exchange",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "show_type",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "crc_ret",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_STRING",
                ["name"] = "user_menu",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_STRING",
                ["name"] = "npc_menu",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.questCRC",
                ["name"] = "allcrc"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT32",
                ["name"] = "source",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Req_QuestInfo_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "UnorderQuestBranchInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "degreevar",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curvalue",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxvalue",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Ret_QuestInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
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
                ["name"] = "score",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curvalue",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxvalue",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "starttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cur_extvalue",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "max_extvalue",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_INT32",
                ["name"] = "leftsecs",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.UnorderQuestBranchInfo",
                ["name"] = "extinfo"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_BOOL",
                ["name"] = "show",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_ReqExecuteQuest_CS",
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
                ["name"] = "target",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "offset",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questdesccrc",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT64",
                ["name"] = "chartarget",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_ReqValidQuests_CS"
    },
    [11] = {
        ["name"] = "MSG_RetValidQuests_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.npcValidQuest",
                ["name"] = "onequest"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_ReqRetQuestState_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "state",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_ReqAbandonQuest_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_RetAbandonQuest_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "QuestStateInfo",
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
                ["name"] = "state",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "npcQuestList",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "npcid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.QuestStateInfo",
                ["name"] = "quests"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_INT32",
                ["name"] = "state",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_ReqMapQuestInfo_CS"
    },
    [18] = {
        ["name"] = "MSG_RetMapQuestInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.npcQuestList",
                ["name"] = "npclists"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_ReqCurActiveQuest_CS"
    },
    [20] = {
        ["name"] = "ringQuestInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mainquestid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "finishringnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_RetCurActiveQuest_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.MSG_Ret_QuestInfo_SC",
                ["name"] = "item"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.npcValidQuest",
                ["name"] = "newaccept"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "dayvar",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.ringQuestInfo",
                ["name"] = "ringinfo"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_ReqChangeMapFindPath_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pathwayid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questid",
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
            }
        }
    },
    [23] = {
        ["name"] = "MSG_RetChangeMapFindPath_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.ChangeMapFindWayInfo",
                ["name"] = "info"
            }
        }
    },
    [24] = {
        ["name"] = "ChangeMapFindWayInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pathwayid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "destmapid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["default_value"] = "false",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "findingway"
            }
        }
    },
    [25] = {
        ["name"] = "MSG_RetPlotTalkID_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "groupid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [26] = {
        ["name"] = "MSG_CartoonCompleteNotify_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "groupid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "command",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "delay",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [27] = {
        ["name"] = "MSG_PlayCartoonAndGoMap_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "groupid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "command",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "delay",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "callbackid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [28] = {
        ["name"] = "MSG_ReqSubmitObjs_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_REPEATED"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bagid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [29] = {
        ["name"] = "MSG_RetSubmitObjs_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [30] = {
        ["name"] = "RingQuestRingCount",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questtype",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "ring_count",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [31] = {
        ["name"] = "MSG_RetRingQuestRingCount_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.RingQuestRingCount",
                ["name"] = "ringcount"
            }
        }
    },
    [32] = {
        ["name"] = "MSG_notifyRefreshQuestInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quest.MSG_Ret_QuestInfo_SC",
                ["name"] = "item"
            }
        }
    },
    [33] = {
        ["name"] = "MSG_PlayBellQTE_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "qtelevel",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [34] = {
        ["name"] = "MSG_PlayBellQTEResult_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "qtelevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [35] = {
        ["name"] = "MSG_Req_SetQuestNeedShow_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "show",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [36] = {
        ["name"] = "MSG_Ret_SetQuestNeedShow_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "code",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [37] = {
        ["name"] = "MSG_Req_ShareQuestToTeamMember_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [38] = {
        ["name"] = "MSG_Ret_NotifyShareQuest_SC",
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
                ["name"] = "questid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [39] = {
        ["name"] = "MSG_Req_AnswerShareQuest_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "accept",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [40] = {
        ["name"] = "MSG_Ret_AnswerShareQuest_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "code",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [41] = {
        ["name"] = "MSG_Ret_NotifyCountDown_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "bset",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "delay",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "seconds",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [42] = {
        ["name"] = "MSG_NotifyClientOptional_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "setting",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [43] = {
        ["name"] = "MSG_notifyQuestStateEffect_SC",
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
                ["name"] = "state",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [44] = {
        ["name"] = "MSG_Req_CommitYQDData_CS",
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
    [45] = {
        ["name"] = "MSG_Req_PlayYQDRetry_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "quest.proto",
["package"] = "quest"

----- end of proto -----
