name = questconfig.proto

package pb;

message questconfig {
    repeated t_quest_config datas = 1;    // type_name = .pb.questconfig.t_quest_config

    message t_quest_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required uint32 AcceptNpcId = 3;
        required uint32 CommitNpcId = 4;
        required string name = 5;
        required string desc = 6;
        required uint32 group = 7;
        required uint32 type = 8;
        required string levellimit = 9;
        required string goal = 10;
        required string degreename = 11;
        required string award = 12;
        required bool canabandon = 13;
        required string objects = 14;
        required bool can_cycle = 15;
        required uint32 pathfindstate = 16;
        required string pathwaydoing = 17;
        required string useobject = 18;
        required uint32 gatherid = 19;
        required string pathwaydone = 20;
        required string pathwaypre = 21;
        required string predesc = 22;
        required uint32 afterquestnpcid = 23;
        required uint32 levelaward = 24;
        required uint32 objaward = 25;
        required uint32 show_copy_id = 26;
        required uint32 show_common_map = 27;
        required uint32 lastsecs = 28;
        required string degree = 29;
        required string commitdesc = 30;
        required string VisitNpcId = 31;
        required string prequestlimit = 32;
        required uint32 can_share = 33;
        required uint32 auto_share = 34;
        required uint32 timelimit = 35;
        required uint32 if_ring = 36;
        required uint32 state_show = 37;
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
                ["type_name"] = ".pb.questconfig.t_quest_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "questconfig",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_quest_config",
                ["field"] = {
                    [1] = {
                        ["number"] = 1,
                        ["default_value"] = "0",
                        ["label"] = "LABEL_REQUIRED",
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "tbxid"
                    },
                    [2] = {
                        ["number"] = 2,
                        ["default_value"] = "0",
                        ["label"] = "LABEL_REQUIRED",
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "id"
                    },
                    [3] = {
                        ["number"] = 3,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "AcceptNpcId",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "CommitNpcId",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "name",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "desc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "group",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "type",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "levellimit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "goal",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "degreename",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "award",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [13] = {
                        ["number"] = 13,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "canabandon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [14] = {
                        ["number"] = 14,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "objects",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [15] = {
                        ["number"] = 15,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "can_cycle",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [16] = {
                        ["number"] = 16,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "pathfindstate",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [17] = {
                        ["number"] = 17,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "pathwaydoing",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [18] = {
                        ["number"] = 18,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "useobject",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [19] = {
                        ["number"] = 19,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "gatherid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [20] = {
                        ["number"] = 20,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "pathwaydone",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [21] = {
                        ["number"] = 21,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "pathwaypre",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [22] = {
                        ["number"] = 22,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "predesc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [23] = {
                        ["number"] = 23,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "afterquestnpcid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [24] = {
                        ["number"] = 24,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "levelaward",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [25] = {
                        ["number"] = 25,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "objaward",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [26] = {
                        ["number"] = 26,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "show_copy_id",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [27] = {
                        ["number"] = 27,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "show_common_map",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [28] = {
                        ["number"] = 28,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "lastsecs",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [29] = {
                        ["number"] = 29,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "degree",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [30] = {
                        ["number"] = 30,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "commitdesc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [31] = {
                        ["number"] = 31,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "VisitNpcId",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [32] = {
                        ["number"] = 32,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "prequestlimit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [33] = {
                        ["number"] = 33,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "can_share",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [34] = {
                        ["number"] = 34,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "auto_share",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [35] = {
                        ["number"] = 35,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "timelimit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [36] = {
                        ["number"] = 36,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "if_ring",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [37] = {
                        ["number"] = 37,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "state_show",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "questconfig.proto",
["package"] = "pb"

----- end of proto -----
