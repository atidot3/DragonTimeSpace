name = mobapk.proto

package mobapk;

message MSG_UserMatchReq_CS {
    optional bool is_match = 1;
}

message MSG_MatchInfo_SC {
    optional uint32 num = 1;
    optional uint32 ready_num = 2;
    optional uint64 id = 3;
}

message MSG_MatchReady_CS {
    optional uint64 id = 1;
}

message MSG_DismissGroup_SC {
null
}

message TeamUser {
    optional uint64 uid = 1;
    optional string name = 2;
    optional uint32 level = 3;
    optional uint32 x = 4;
    optional uint32 y = 5;
    optional bool online = 6;
    optional uint32 hairstyle = 7;
    optional uint32 haircolor = 8;
    optional uint32 headstyle = 9;
    optional uint32 bodystyle = 10;
    optional uint32 antenna = 11;
    optional uint32 coat = 12;
    optional uint32 avatarid = 13;
    optional uint32 maxhp = 14;
    optional uint32 hp = 15;
    optional uint32 heroid = 16;
    optional uint32 exp = 17;
}

message MSG_MyTeamInfo_SC {
    repeated TeamUser users = 1;    // type_name = .mobapk.TeamUser
    optional uint32 create_time = 2;
    optional string teamid = 3;
}

message PowerItem {
    optional string color = 1;
    optional uint32 power = 2;
}

message MSG_RefreshPowerRank_SC {
    repeated PowerItem items = 1;    // type_name = .mobapk.PowerItem
}

message RadarPos {
    optional uint32 x = 1;
    optional uint32 y = 2;
    optional uint32 num = 3;
    optional uint32 uid = 4;
}

message MSG_RefreshRadarPos_CSC {
    repeated RadarPos pos = 1;    // type_name = .mobapk.RadarPos
    optional uint32 radius = 2;
}

message MSG_StartPray_SC {
    repeated string hopes = 1;
}

message MSG_SelectHopes_CS {
    optional uint32 idx_1st = 1;
    optional uint32 idx_2nd = 2;
    optional uint32 idx_3rd = 3;
}

message MSG_ServerTimer_SC {
    optional ServerTimer id = 1;    // type_name = .mobapk.ServerTimer
    optional string caption = 2;
    optional uint32 resttime = 3;
    optional uint32 style = 4;
}

message UserTeamInfo {
    optional uint64 uid = 1;
    optional string team_color = 2;
}

message MSG_BstUserTeamInfo_SC {
    repeated UserTeamInfo infos = 1;    // type_name = .mobapk.UserTeamInfo
}

message MSG_UseSpecialCapsule_CS {
    optional string thisid = 1;
    optional uint32 x = 2;
    optional uint32 y = 3;
}

message MSG_GameOver_SC {
    optional uint32 rank = 1;
}

message MSG_UserGetAwardReq_CS {
    optional uint32 idx = 1;
}

message GetBagInfo {
    optional uint32 idx = 1;
    optional uint64 uid = 2;
    optional string name = 3;
    optional uint32 objectid = 4;
    optional uint32 count = 5;
}

message MSG_RewardBagInfo_SC {
    repeated GetBagInfo infos = 1;    // type_name = .mobapk.GetBagInfo
}

message MSG_MobaLevelUp_SC {
    optional uint32 oldlevel = 1;
    optional uint32 newlevel = 2;
    optional uint64 uid = 3;
    optional uint32 type = 4;
}

message MSG_ClientEffect_SC {
    optional uint64 uid = 1;
    optional uint32 effectid = 2;
    optional uint32 posx = 3;
    optional uint32 posy = 4;
    optional uint32 r = 5;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "ServerTimer",
        ["value"] = {
            [1] = {
                ["name"] = "MobaPk_Confirm_RestTime",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "MobaPk_Start_RestTime",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "MobaPk_Relive_RestTime",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "MobaPk_KickoutLastOne_RestTime",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "MobaPk_Pray_RestTime",
                ["number"] = 5
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "MSG_UserMatchReq_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "is_match",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_MatchInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "ready_num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT64",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_MatchReady_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_DismissGroup_SC"
    },
    [5] = {
        ["name"] = "TeamUser",
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
                ["name"] = "x",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "y",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_BOOL",
                ["name"] = "online",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hairstyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "haircolor",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "headstyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bodystyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "antenna",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT32",
                ["name"] = "coat",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 13,
                ["type"] = "TYPE_UINT32",
                ["name"] = "avatarid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [14] = {
                ["number"] = 14,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxhp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [15] = {
                ["number"] = 15,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [16] = {
                ["number"] = 16,
                ["type"] = "TYPE_UINT32",
                ["name"] = "heroid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [17] = {
                ["number"] = 17,
                ["type"] = "TYPE_UINT32",
                ["name"] = "exp",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_MyTeamInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".mobapk.TeamUser",
                ["name"] = "users"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "create_time",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "teamid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "PowerItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "color",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "power",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_RefreshPowerRank_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".mobapk.PowerItem",
                ["name"] = "items"
            }
        }
    },
    [9] = {
        ["name"] = "RadarPos",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "x",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "y",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "uid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_RefreshRadarPos_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".mobapk.RadarPos",
                ["name"] = "pos"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "radius",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_StartPray_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "hopes",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_SelectHopes_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "idx_1st",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "idx_2nd",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "idx_3rd",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_ServerTimer_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".mobapk.ServerTimer",
                ["name"] = "id"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "caption",
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
                ["name"] = "style",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "UserTeamInfo",
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
                ["name"] = "team_color",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_BstUserTeamInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".mobapk.UserTeamInfo",
                ["name"] = "infos"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_UseSpecialCapsule_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
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
            }
        }
    },
    [17] = {
        ["name"] = "MSG_GameOver_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "rank",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_UserGetAwardReq_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "idx",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [19] = {
        ["name"] = "GetBagInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "idx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "uid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objectid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "count",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_RewardBagInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".mobapk.GetBagInfo",
                ["name"] = "infos"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_MobaLevelUp_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "oldlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "newlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT64",
                ["name"] = "uid",
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
    [22] = {
        ["name"] = "MSG_ClientEffect_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "uid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "effectid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posy",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "r",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "mobapk.proto",
["package"] = "mobapk"

----- end of proto -----
