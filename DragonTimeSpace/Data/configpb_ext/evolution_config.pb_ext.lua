name = evolution_config.proto

package pb;

message evolution_config {
    repeated t_evolution_config datas = 1;    // type_name = .pb.evolution_config.t_evolution_config

    message t_evolution_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required string name = 3;
        required string icon = 4;
        required uint32 avatar = 5;
        required string evolutioncost = 6;
        required string addprimecard = 7;
        required string desc = 8;
        required uint32 pdam = 9;
        required uint32 mdam = 10;
        required uint32 pdef = 11;
        required uint32 mdef = 12;
        required uint32 maxhp = 13;
        required uint32 bang = 14;
        required uint32 bangextradamage = 15;
        required uint32 toughness = 16;
        required uint32 toughnessreducedamage = 17;
        required uint32 block = 18;
        required uint32 blockreducedamage = 19;
        required uint32 penetrate = 20;
        required uint32 penetrateextradamage = 21;
        required uint32 accurate = 22;
        required uint32 accurateextradamage = 23;
        required uint32 hold = 24;
        required uint32 holdreducedamage = 25;
        required uint32 deflect = 26;
        required uint32 deflectreducedamage = 27;
        required uint32 hit = 28;
        required uint32 miss = 29;
        required string skillid = 30;
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
                ["type_name"] = ".pb.evolution_config.t_evolution_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "evolution_config",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_evolution_config",
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
                        ["type"] = "TYPE_STRING",
                        ["name"] = "name",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "icon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "avatar",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "evolutioncost",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "addprimecard",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "desc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "pdam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "mdam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "pdef",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "mdef",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [13] = {
                        ["number"] = 13,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "maxhp",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [14] = {
                        ["number"] = 14,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "bang",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [15] = {
                        ["number"] = 15,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "bangextradamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [16] = {
                        ["number"] = 16,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "toughness",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [17] = {
                        ["number"] = 17,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "toughnessreducedamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [18] = {
                        ["number"] = 18,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "block",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [19] = {
                        ["number"] = 19,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "blockreducedamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [20] = {
                        ["number"] = 20,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "penetrate",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [21] = {
                        ["number"] = 21,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "penetrateextradamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [22] = {
                        ["number"] = 22,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "accurate",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [23] = {
                        ["number"] = 23,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "accurateextradamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [24] = {
                        ["number"] = 24,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "hold",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [25] = {
                        ["number"] = 25,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "holdreducedamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [26] = {
                        ["number"] = 26,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "deflect",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [27] = {
                        ["number"] = 27,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "deflectreducedamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [28] = {
                        ["number"] = 28,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "hit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [29] = {
                        ["number"] = 29,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "miss",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [30] = {
                        ["number"] = 30,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "skillid",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "evolution_config.proto",
["package"] = "pb"

----- end of proto -----
