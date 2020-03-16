name = massive.proto

package massive;

message MSG_Ret_GuideHistory_SC {
    repeated uint32 guideids = 1;
}

message MSG_Req_GuideStart_CS {
    optional uint32 guideid = 1;
}

message MSG_Ret_GuideStart_SC {
    optional uint32 guideid = 1;
}

message MSG_Req_GuideOver_CS {
    optional uint32 guideid = 1;
}

message MSG_Ret_GuideOver_SC {
    optional uint32 guideid = 1;
}

message MSG_RetCurrencyChange_SC {
    optional uint32 currencyid = 1;
    optional uint32 changenum = 2;
    optional bool isadd = 3;
    optional uint32 everydaynum = 4;
}

message MSG_ReqCrystalNumToday_CS {
null
}

message MSG_RetCrystalNumToday_SC {
    optional uint32 bluecrystal = 1;
    optional uint32 purplecrystal = 2;
}

message MSG_ReqStartAIRunning_CS {
null
}

message MSG_RetStartAIRunning_SC {
null
}

message MSG_RetUserSysSetting_SC {
    optional string setting = 1;
}

message MSG_ReqUserSysSetting_CS {
    optional uint32 id = 1;
    optional bool set = 2;
}

message GiftItem {
    optional uint32 objid = 1;
    optional uint32 num = 2;
    optional uint32 bind = 3;
}

message MSG_Ret_SuccessOpenGift_SC {
    optional uint32 giftid = 1;
    repeated GiftItem objs = 2;    // type_name = .massive.GiftItem
}

message MSG_ReqVitalityDegree_CS {
null
}

message VitalityItem {
    optional uint32 id = 1;
    optional uint32 attendtimes = 2;
    optional uint32 vitalitydegree = 3;
}

message VitalityReward {
    optional uint32 degree = 1;
    optional uint32 state = 2;
}

message VitalityUserInfo {
    optional uint32 totaldegree = 1;
    repeated VitalityItem item = 2;    // type_name = .massive.VitalityItem
    repeated VitalityReward reward = 3;    // type_name = .massive.VitalityReward
    optional uint32 attendtime = 4;
}

message MSG_RetVitalityDegree_SC {
    optional VitalityUserInfo info = 1;    // type_name = .massive.VitalityUserInfo
}

message MSG_ReqGetVitalityAward_CS {
    optional uint32 degree = 1;
}

message MSG_RetGetVitalityAward_SC {
    optional uint32 degree = 1;
    optional uint32 errcode = 2;
}

message MSG_ReqGeneRemakeInfo_CS {
null
}

message GeneRemakeItem {
    optional uint32 genetype = 1;
    optional uint32 level = 2;
    optional uint32 exp = 3;
    optional uint32 value = 4;
}

message MSG_RetGeneRemakeInfo_SC {
    repeated GeneRemakeItem data = 1;    // type_name = .massive.GeneRemakeItem
}

message MSG_ReqStrengthenGene_CS {
    optional uint32 genetype = 1;
    optional uint32 type = 2;
}

message MSG_RetStrengthenGene_SC {
    optional uint32 retcode = 1;
    optional GeneRemakeItem data = 2;    // type_name = .massive.GeneRemakeItem
}

message MSG_Req_HoldonUser_CS {
    optional uint64 thisid = 1;
    optional uint32 type = 2;
}

message MSG_Ret_HoldonUser_SC {
    optional uint64 thisid = 1;
    optional uint32 needtime = 2;
    optional uint32 retcode = 3;
    optional uint32 type = 4;
}

message MSG_Ret_HoldonUser_Interrupt_SC {
    optional uint64 thisid = 1;
}

message MSG_ReqMakingItem_CS {
    optional uint32 making_itemid = 1;
}

message MSG_RetMakingItem_SC {
    optional uint32 result = 1;
    optional uint32 making_itemid = 2;
    optional uint32 objid = 3;
}

message MSG_Req_StruggleShape_CS {
null
}

message MSG_Req_DivorceStuck_CS {
null
}

message MSG_Req_Survey_Info_CS {
null
}

message MSG_Ret_Survey_Info_SC {
    repeated uint32 survey_id = 1;
}

message MSG_Req_GetSurveyReward_CS {
    optional uint32 survey_id = 1;
}

message MSG_Ret_GetSurveyReward_SC {
    optional uint32 survey_id = 1;
    optional uint32 retcode = 2;
}

message MSG_Ret_Wegame_Fcm_Info {
    optional uint32 ratio = 1;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "GetSurveyRewardResult",
        ["value"] = {
            [1] = {
                ["name"] = "GET_SURVEY_REWARD_SUCCESS",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "GET_SURVEY_REWARD_PROCLOCK",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "GET_SURVEY_REWARD_NOT_MEET_LIMIT",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "GET_SURVEY_REWARD_HAS_GOT",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "GET_SURVEY_REWARD_SURVEY_NOT_EXIST",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "GET_SURVEY_REWARD_UNKNOW_ERROR",
                ["number"] = 5
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "MSG_Ret_GuideHistory_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "guideids",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Req_GuideStart_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "guideid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_Ret_GuideStart_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "guideid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Req_GuideOver_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "guideid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_Ret_GuideOver_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "guideid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_RetCurrencyChange_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "currencyid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "changenum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isadd",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "everydaynum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_ReqCrystalNumToday_CS"
    },
    [8] = {
        ["name"] = "MSG_RetCrystalNumToday_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bluecrystal",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "purplecrystal",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_ReqStartAIRunning_CS"
    },
    [10] = {
        ["name"] = "MSG_RetStartAIRunning_SC"
    },
    [11] = {
        ["name"] = "MSG_RetUserSysSetting_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "setting",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_ReqUserSysSetting_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "set",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "GiftItem",
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
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bind",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_Ret_SuccessOpenGift_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "giftid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".massive.GiftItem",
                ["name"] = "objs"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_ReqVitalityDegree_CS"
    },
    [16] = {
        ["name"] = "VitalityItem",
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
                ["name"] = "attendtimes",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "vitalitydegree",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [17] = {
        ["name"] = "VitalityReward",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "degree",
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
    [18] = {
        ["name"] = "VitalityUserInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "totaldegree",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".massive.VitalityItem",
                ["name"] = "item"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".massive.VitalityReward",
                ["name"] = "reward"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "attendtime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_RetVitalityDegree_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".massive.VitalityUserInfo",
                ["name"] = "info"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_ReqGetVitalityAward_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "degree",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_RetGetVitalityAward_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "degree",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_ReqGeneRemakeInfo_CS"
    },
    [23] = {
        ["name"] = "GeneRemakeItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "genetype",
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
                ["name"] = "exp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "value",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_RetGeneRemakeInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".massive.GeneRemakeItem",
                ["name"] = "data"
            }
        }
    },
    [25] = {
        ["name"] = "MSG_ReqStrengthenGene_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "genetype",
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
    [26] = {
        ["name"] = "MSG_RetStrengthenGene_SC",
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
                ["type_name"] = ".massive.GeneRemakeItem",
                ["name"] = "data"
            }
        }
    },
    [27] = {
        ["name"] = "MSG_Req_HoldonUser_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "thisid",
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
    [28] = {
        ["name"] = "MSG_Ret_HoldonUser_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "thisid",
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
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [29] = {
        ["name"] = "MSG_Ret_HoldonUser_Interrupt_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [30] = {
        ["name"] = "MSG_ReqMakingItem_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "making_itemid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [31] = {
        ["name"] = "MSG_RetMakingItem_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "making_itemid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [32] = {
        ["name"] = "MSG_Req_StruggleShape_CS"
    },
    [33] = {
        ["name"] = "MSG_Req_DivorceStuck_CS"
    },
    [34] = {
        ["name"] = "MSG_Req_Survey_Info_CS"
    },
    [35] = {
        ["name"] = "MSG_Ret_Survey_Info_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "survey_id",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [36] = {
        ["name"] = "MSG_Req_GetSurveyReward_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "survey_id",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [37] = {
        ["name"] = "MSG_Ret_GetSurveyReward_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "survey_id",
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
    [38] = {
        ["name"] = "MSG_Ret_Wegame_Fcm_Info",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "ratio",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "massive.proto",
["package"] = "massive"

----- end of proto -----
