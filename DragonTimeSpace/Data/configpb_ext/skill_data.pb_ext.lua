name = skill_data.proto

package pb;

message skill_data {
    repeated t_skill_lv_config datas = 1;    // type_name = .pb.skill_data.t_skill_lv_config

    message t_skill_lv_config {
        required uint64 tbxid = 1 [default = 0];
        required uint64 id = 2 [default = 0];
        required uint32 skillid = 3;
        required string skillname = 4;
        required string hero = 5;
        required uint32 unlocklevel = 6;
        required string unlockevolution = 7;
        required uint32 dtime = 8;
        required uint32 maxoverlaytimes = 9;
        required uint32 canbe_passive = 10;
        required uint32 good = 11;
        required uint32 releasetype = 12;
        required uint32 chanttime = 13;
        required uint32 usetype = 14;
        required bool canbe_breakattack = 15;
        required uint32 level = 16;
        required string desc = 17;
        required string skillstatus = 18;
        required uint32 magiccost = 19;
        required string skillicon = 20;
        required uint32 belongcareer = 21;
        required uint32 careerunlocklevel = 22;
        required uint32 createproficiency = 23;
        required bool NeedTarget = 24;
        required string SkillRange = 25;
        required string extskill = 26;
        required uint32 publicCD = 27;
        required bool MoveBreakComb = 28;
        required bool SkillBreakComb = 29;
        required bool multiskill = 30;
        required uint32 SearchType = 31;
        required uint32 CastBeyondType = 32;
        required uint32 SearchRange = 33;
        required uint32 relyon_state = 34;
        required uint32 levelup_type = 35;
        required uint32 nextskillid = 36;
        required string levelupcost = 37;
    }
}

----- table version -----
["message_type"] = {
    [1] = {
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".pb.skill_data.t_skill_lv_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "skill_data",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_skill_lv_config",
                ["field"] = {
                    [1] = {
                        ["number"] = 1,
                        ["default_value"] = "0",
                        ["label"] = "LABEL_REQUIRED",
                        ["type"] = "TYPE_UINT64",
                        ["name"] = "tbxid"
                    },
                    [2] = {
                        ["number"] = 2,
                        ["default_value"] = "0",
                        ["label"] = "LABEL_REQUIRED",
                        ["type"] = "TYPE_UINT64",
                        ["name"] = "id"
                    },
                    [3] = {
                        ["number"] = 3,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "skillid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "skillname",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "hero",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "unlocklevel",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "unlockevolution",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "dtime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "maxoverlaytimes",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "canbe_passive",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "good",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "releasetype",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [13] = {
                        ["number"] = 13,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "chanttime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [14] = {
                        ["number"] = 14,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "usetype",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [15] = {
                        ["number"] = 15,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "canbe_breakattack",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [16] = {
                        ["number"] = 16,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "level",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [17] = {
                        ["number"] = 17,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "desc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [18] = {
                        ["number"] = 18,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "skillstatus",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [19] = {
                        ["number"] = 19,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "magiccost",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [20] = {
                        ["number"] = 20,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "skillicon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [21] = {
                        ["number"] = 21,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "belongcareer",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [22] = {
                        ["number"] = 22,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "careerunlocklevel",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [23] = {
                        ["number"] = 23,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "createproficiency",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [24] = {
                        ["number"] = 24,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "NeedTarget",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [25] = {
                        ["number"] = 25,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "SkillRange",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [26] = {
                        ["number"] = 26,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "extskill",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [27] = {
                        ["number"] = 27,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "publicCD",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [28] = {
                        ["number"] = 28,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "MoveBreakComb",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [29] = {
                        ["number"] = 29,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "SkillBreakComb",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [30] = {
                        ["number"] = 30,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "multiskill",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [31] = {
                        ["number"] = 31,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "SearchType",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [32] = {
                        ["number"] = 32,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "CastBeyondType",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [33] = {
                        ["number"] = 33,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "SearchRange",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [34] = {
                        ["number"] = 34,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "relyon_state",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [35] = {
                        ["number"] = 35,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "levelup_type",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [36] = {
                        ["number"] = 36,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "nextskillid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [37] = {
                        ["number"] = 37,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "levelupcost",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "skill_data.proto",
["package"] = "pb"

----- end of proto -----
