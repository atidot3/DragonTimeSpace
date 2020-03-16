name = magic_msg.proto

package magic;

message SkillData {
    optional uint32 skillid = 1;
    optional uint32 level = 2;
    optional uint64 lastusetime = 3;
    optional uint32 onoff = 4;
    optional uint64 lastupdatetime = 5;
    optional uint32 overlaytimes = 6;
    optional uint32 active_stages = 7;
    optional uint32 maxmultitimes = 8;
    optional uint32 skillcd = 9;
}

message ExtSkillData {
    optional uint32 id = 1;
    optional uint32 level = 2;
    optional uint32 masterskill = 3;
}

message MSG_Req_MagicAttack_CS {
    optional EntryIDType target = 1;    // type_name = .msg.EntryIDType
    optional uint32 magictype = 2;
    optional float desx = 3;
    optional float desy = 4;
    optional uint32 attdir = 5;
    optional uint32 userdir = 6;
}

message MSG_Ret_StartMagicAttack_SC {
    optional EntryIDType att = 1;    // type_name = .msg.EntryIDType
    optional float desx = 2;
    optional float desy = 3;
    optional uint32 attdir = 4;
    optional uint32 userdir = 5;
    optional uint32 skillid = 6;
}

message PKResult {
    optional EntryIDType def = 1;    // type_name = .msg.EntryIDType
    optional uint32 hp = 2;
    optional int32 changehp = 3;
    repeated ATTACKRESULT attcode = 4;    // type_name = .magic.ATTACKRESULT
}

message MSG_Ret_MagicAttack_SC {
    optional EntryIDType att = 1;    // type_name = .msg.EntryIDType
    optional EntryIDType def = 2;    // type_name = .msg.EntryIDType
    optional float desx = 3;
    optional float desy = 4;
    optional uint32 attdir = 5;
    optional uint32 userdir = 6;
    optional uint64 skillstage = 7;
    repeated PKResult pklist = 8;    // type_name = .magic.PKResult
}

message MSG_Ret_HpMpPop_SC {
    optional EntryIDType target = 1;    // type_name = .msg.EntryIDType
    optional uint32 hp = 2;
    optional int32 hp_change = 3;
    optional uint32 mp = 4;
    optional uint32 mp_change = 5;
    optional bool force = 6;
    optional uint64 skillstage = 7;
    optional uint64 state_id = 8;
    optional EntryIDType att = 9;    // type_name = .msg.EntryIDType
}

message MSG_Req_SyncSkillStage_CS {
    optional EntryIDType target = 1;    // type_name = .msg.EntryIDType
    optional uint64 skillstage = 2;
    optional float desx = 3;
    optional float desy = 4;
    optional uint32 attdir = 5;
    optional uint32 userdir = 6;
    optional uint32 stagetype = 7;
}

message MSG_Ret_SyncSkillStage_SC {
    optional EntryIDType att = 1;    // type_name = .msg.EntryIDType
    optional EntryIDType def = 2;    // type_name = .msg.EntryIDType
    optional uint64 skillstage = 3;
    optional float desx = 4;
    optional float desy = 5;
    optional uint32 attdir = 6;
    optional uint32 userdir = 7;
    optional uint32 stagetype = 8;
}

message MSG_Ret_InterruptSkill_SC {
    optional EntryIDType att = 1;    // type_name = .msg.EntryIDType
    optional uint64 skillstage = 2;
}

message MSG_Ret_MainUserDeath_SC {
    optional string charid = 1;
    optional uint32 relivecostid = 2;
    optional uint32 relivecostnum = 3;
    optional uint32 canreliveorigin = 4;
    optional bool canrelive = 5 [default = true];
    optional uint32 relivetime = 6;
    optional bool autorelive = 7;
    optional uint32 relive_type = 8;
}

message MSG_Ret_UserDeath_SC {
    optional uint64 tempid = 1;
    optional uint64 attid = 2;
    optional uint32 lasthitskill = 3;
    optional uint32 atttype = 4;
}

message MSG_Req_MainUserRelive_CS {
    optional uint32 relivetype = 1;
}

message MSG_Ret_MainUserRelive_SC {
    optional uint64 userid = 1;
    optional uint32 x = 2;
    optional uint32 y = 3;
    required ReliveType relivetype = 4;    // type_name = .msg.ReliveType
}

message MSG_Ret_SwitchPKMode_SC {
    required PKMode newmode = 1;    // type_name = .msg.PKMode
}

message MSG_RetRefreshSkill_SC {
    repeated SkillData skills = 1;    // type_name = .magic.SkillData
}

message MSG_Req_OffSkill_CS {
    optional uint32 skillid = 1;
}

message AttWarning {
    optional uint32 lasttime = 1;
    optional Position pos = 2;    // type_name = .msg.Position
    optional uint32 dir = 3;
    optional uint32 rangetype = 4;
    optional uint32 rangep1 = 5;
    optional uint32 rangep2 = 6;
}

message MSG_Ret_AttWarning_SC {
    optional EntryIDType attacker = 1;    // type_name = .msg.EntryIDType
    repeated AttWarning warning = 2;    // type_name = .magic.AttWarning
}

message MSG_ReqTriggerQTESkill_CS {
    optional uint64 bosstempid = 1;
    optional Position warppos = 2;    // type_name = .msg.Position
    optional uint32 dir = 3;
}

message MSG_RetTriggerQTESkill_SC {
    optional uint32 errcode = 1;
}

message MSG_ReqDrinkBloodSkill_CS {
    optional uint64 npctempid = 1;
}

message MSG_RetDrinkBloodSkill_SC {
    optional uint32 errcode = 1 [default = 1];
}

message MSG_Ret_UserSkillRelive_SC {
    optional string from_name = 1;
    optional uint32 relive_type = 2;
    optional uint32 relivetime = 3;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "ATTACKRESULT",
        ["value"] = {
            [1] = {
                ["name"] = "ATTACKRESULT_NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "ATTACKRESULT_MISS",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "ATTACKRESULT_NORMAL",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "ATTACKRESULT_BANG",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "ATTACKRESULT_HOLD",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "ATTACKRESULT_BLOCK",
                ["number"] = 5
            },
            [7] = {
                ["name"] = "ATTACKRESULT_DEFLECT",
                ["number"] = 6
            },
            [8] = {
                ["name"] = "ATTACKRESULT_HIT",
                ["number"] = 8
            }
        }
    }
},
["package"] = "magic",
["name"] = "magic_msg.proto",
["dependency"] = {
    [1] = "msg_enum.proto"
},
["message_type"] = {
    [1] = {
        ["name"] = "SkillData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillid",
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
                ["type"] = "TYPE_UINT64",
                ["name"] = "lastusetime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "onoff",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT64",
                ["name"] = "lastupdatetime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "overlaytimes",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "active_stages",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxmultitimes",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillcd",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "ExtSkillData",
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
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "masterskill",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_Req_MagicAttack_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "target"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "magictype",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "desx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "desy",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "attdir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "userdir",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Ret_StartMagicAttack_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "att"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "desx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "desy",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "attdir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "userdir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "PKResult",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "def"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_INT32",
                ["name"] = "changehp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".magic.ATTACKRESULT",
                ["name"] = "attcode"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Ret_MagicAttack_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "att"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "def"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "desx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "desy",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "attdir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "userdir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT64",
                ["name"] = "skillstage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".magic.PKResult",
                ["name"] = "pklist"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_Ret_HpMpPop_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "target"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_INT32",
                ["name"] = "hp_change",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mp_change",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_BOOL",
                ["name"] = "force",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT64",
                ["name"] = "skillstage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT64",
                ["name"] = "state_id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "att"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Req_SyncSkillStage_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "target"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "skillstage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "desx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "desy",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "attdir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "userdir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "stagetype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_Ret_SyncSkillStage_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "att"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "def"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT64",
                ["name"] = "skillstage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "desx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "desy",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "attdir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "userdir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "stagetype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_Ret_InterruptSkill_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "att"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "skillstage",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_Ret_MainUserDeath_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "relivecostid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "relivecostnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "canreliveorigin",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["default_value"] = "true",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "canrelive"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "relivetime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_BOOL",
                ["name"] = "autorelive",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "relive_type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_Ret_UserDeath_SC",
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
    [13] = {
        ["name"] = "MSG_Req_MainUserRelive_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "relivetype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_Ret_MainUserRelive_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "userid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "x",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "y",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.ReliveType",
                ["name"] = "relivetype"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_Ret_SwitchPKMode_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.PKMode",
                ["name"] = "newmode"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_RetRefreshSkill_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".magic.SkillData",
                ["name"] = "skills"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_Req_OffSkill_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [18] = {
        ["name"] = "AttWarning",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lasttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.Position",
                ["name"] = "pos"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dir",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rangetype",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rangep1",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rangep2",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_Ret_AttWarning_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.EntryIDType",
                ["name"] = "attacker"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".magic.AttWarning",
                ["name"] = "warning"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_ReqTriggerQTESkill_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "bosstempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".msg.Position",
                ["name"] = "warppos"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dir",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_RetTriggerQTESkill_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_ReqDrinkBloodSkill_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "npctempid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [23] = {
        ["name"] = "MSG_RetDrinkBloodSkill_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["default_value"] = "1",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_Ret_UserSkillRelive_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "from_name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "relive_type",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "relivetime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
}

----- end of proto -----
