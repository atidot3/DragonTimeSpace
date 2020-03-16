name = skill_stage.proto

package pb;

message skill_stage {
    repeated t_skill_stage_config datas = 1;    // type_name = .pb.skill_stage.t_skill_stage_config

    message t_skill_stage_config {
        required uint64 tbxid = 1 [default = 0];
        required uint64 id = 2 [default = 0];
        required uint32 skillid = 3;
        required string ClipName = 4;
        required uint32 ActionID = 5;
        required uint32 EffectId = 6;
        required string MoveDis = 7;
        required string Moveeffect = 8;
        required float PoseTime = 9;
        required bool CanCancelPreFist = 10;
        required bool CanCancelCloseFist = 11;
        required bool MoveCancelCloseFist = 12;
        required bool NeedFaceTarget = 13;
        required string SightType = 14;
        required uint32 SkillSpeed = 15;
        required string SkillPortrait = 16;
        required uint32 Checkfail = 17;
        required string AttackWarn = 18;
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
                ["type_name"] = ".pb.skill_stage.t_skill_stage_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "skill_stage",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_skill_stage_config",
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
                        ["name"] = "ClipName",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "ActionID",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "EffectId",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "MoveDis",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "Moveeffect",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_FLOAT",
                        ["name"] = "PoseTime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "CanCancelPreFist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "CanCancelCloseFist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "MoveCancelCloseFist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [13] = {
                        ["number"] = 13,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "NeedFaceTarget",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [14] = {
                        ["number"] = 14,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "SightType",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [15] = {
                        ["number"] = 15,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "SkillSpeed",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [16] = {
                        ["number"] = 16,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "SkillPortrait",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [17] = {
                        ["number"] = 17,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "Checkfail",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [18] = {
                        ["number"] = 18,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "AttackWarn",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "skill_stage.proto",
["package"] = "pb"

----- end of proto -----
