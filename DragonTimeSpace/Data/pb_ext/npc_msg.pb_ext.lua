name = npc_msg.proto

package npc;

message MSG_NPC_Death_SC {
    optional uint64 tempid = 1;
    optional uint64 attid = 2;
    optional uint32 lasthitskill = 3;
    optional uint32 atttype = 4;
}

message MSG_Req_Holdon_CS {
    optional uint64 thisid = 1;
    optional uint32 npctype = 2;
    optional uint32 type = 3;
}

message MSG_Ret_Holdon_SC {
    optional uint64 thisid = 1;
    optional uint32 npctype = 2;
    optional uint32 needtime = 3;
    optional uint32 retcode = 4;
    optional uint32 type = 5;
}

message MSG_Ret_Holdon_Interrupt_SC {
    optional uint32 baseid = 1;
    optional uint32 npctype = 2;
}

message HoldNpcData {
    optional uint64 npc_tempid = 1;
    optional string npc_name = 2;
    optional uint32 resttime = 3;
    optional uint32 distance = 4;
    optional uint64 holduser = 5;
    optional uint64 holdteam = 6;
    optional uint64 holdguild = 7;
}

message MSG_Ret_AddHoldNpcData_SC {
    optional HoldNpcData data = 1;    // type_name = .npc.HoldNpcData
}

message MSG_Ret_BatchAddHoldNpcData_SC {
    repeated HoldNpcData datas = 1;    // type_name = .npc.HoldNpcData
}

message MSG_Ret_RemoveHoldNpcData_SC {
    optional uint64 npc_tempid = 1;
}

message MSG_Ret_HoldonSuccess {
    optional uint64 npc_tempid = 1;
    optional uint32 type = 2;
}

message MSG_ReqWatchSceneBag_CS {
    optional uint64 tempid = 1;
}

message MSG_ReqPickObjFromSceneBag_CS {
    repeated uint32 thisids = 1;
    optional uint64 tempid = 2;
}

message MSG_ReqPickAllSceneBag_CS {
    optional uint64 tempid = 1;
}

message ObjItem {
    optional uint32 thisid = 1;
    optional t_Object obj = 2;    // type_name = .Obj.t_Object
}

message MSG_RefreshSceneBag_SC {
    optional uint64 tempid = 1;
    repeated ObjItem items = 2;    // type_name = .npc.ObjItem
    optional bool isrefresh = 3;
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "MSG_NPC_Death_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "attid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lasthitskill",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "atttype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Req_Holdon_CS",
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
                ["name"] = "npctype",
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
    [3] = {
        ["name"] = "MSG_Ret_Holdon_SC",
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
                ["name"] = "npctype",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "needtime",
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
    [4] = {
        ["name"] = "MSG_Ret_Holdon_Interrupt_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "baseid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "npctype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "HoldNpcData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "npc_tempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "npc_name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "resttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "distance",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT64",
                ["name"] = "holduser",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT64",
                ["name"] = "holdteam",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT64",
                ["name"] = "holdguild",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Ret_AddHoldNpcData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".npc.HoldNpcData",
                ["name"] = "data"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_Ret_BatchAddHoldNpcData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".npc.HoldNpcData",
                ["name"] = "datas"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Ret_RemoveHoldNpcData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "npc_tempid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_Ret_HoldonSuccess",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "npc_tempid",
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
    [10] = {
        ["name"] = "MSG_ReqWatchSceneBag_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_ReqPickObjFromSceneBag_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "thisids",
                ["label"] = "LABEL_REPEATED"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_ReqPickAllSceneBag_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "ObjItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.t_Object",
                ["name"] = "obj"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_RefreshSceneBag_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".npc.ObjItem",
                ["name"] = "items"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isrefresh",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["dependency"] = {
    [1] = "object.proto"
},
["name"] = "npc_msg.proto",
["package"] = "npc"

----- end of proto -----
