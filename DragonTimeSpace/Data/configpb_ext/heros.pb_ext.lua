name = heros.proto

package pb;

message heros {
    repeated t_hero_config datas = 1;    // type_name = .pb.heros.t_hero_config

    message t_hero_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required uint32 type = 3;
        required string typeicon = 4;
        required string desc = 5;
        required string evolution = 6;
        required string primecard = 7;
        required string maxcard = 8;
        required uint32 activeskill_1 = 9;
        required uint32 activeskill_2 = 10;
        required uint32 activeskill_3 = 11;
        required uint32 activeskill_4 = 12;
        required uint32 normalskill = 13;
        required uint32 passiveskill = 14;
        required string skill = 15;
        required string repeatget = 16;
        required string herochara = 17;
        required string trick = 18;
        required string modelact = 19;
        required uint32 maxhp = 20;
        required uint32 pdamage = 21;
        required uint32 mdamage = 22;
        required uint32 pdefence = 23;
        required uint32 mdefence = 24;
        required uint32 bang = 25;
        required uint32 toughness = 26;
        required uint32 block = 27;
        required uint32 penetrate = 28;
        required uint32 hit = 29;
        required uint32 miss = 30;
        required string getherodesc = 31;
        required uint32 getheropathway = 32;
        required string fetters = 33;
        required string recommandprice = 34;
        required uint32 addmpcfg = 35;
        required uint32 maxstar = 36;
        required string heroname = 37;
        required uint32 isshow = 38;
        required uint32 accurate = 39;
        required uint32 deflect = 40;
        required string avatar = 41;
        required uint32 newavatar = 42;
        required string exskill = 43;
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
                ["type_name"] = ".pb.heros.t_hero_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "heros",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_hero_config",
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
                        ["name"] = "type",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "typeicon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "desc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "evolution",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "primecard",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "maxcard",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "activeskill_1",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "activeskill_2",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "activeskill_3",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "activeskill_4",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [13] = {
                        ["number"] = 13,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "normalskill",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [14] = {
                        ["number"] = 14,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "passiveskill",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [15] = {
                        ["number"] = 15,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "skill",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [16] = {
                        ["number"] = 16,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "repeatget",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [17] = {
                        ["number"] = 17,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "herochara",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [18] = {
                        ["number"] = 18,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "trick",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [19] = {
                        ["number"] = 19,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "modelact",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [20] = {
                        ["number"] = 20,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "maxhp",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [21] = {
                        ["number"] = 21,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "pdamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [22] = {
                        ["number"] = 22,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "mdamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [23] = {
                        ["number"] = 23,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "pdefence",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [24] = {
                        ["number"] = 24,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "mdefence",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [25] = {
                        ["number"] = 25,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "bang",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [26] = {
                        ["number"] = 26,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "toughness",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [27] = {
                        ["number"] = 27,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "block",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [28] = {
                        ["number"] = 28,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "penetrate",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [29] = {
                        ["number"] = 29,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "hit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [30] = {
                        ["number"] = 30,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "miss",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [31] = {
                        ["number"] = 31,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "getherodesc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [32] = {
                        ["number"] = 32,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "getheropathway",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [33] = {
                        ["number"] = 33,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "fetters",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [34] = {
                        ["number"] = 34,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "recommandprice",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [35] = {
                        ["number"] = 35,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "addmpcfg",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [36] = {
                        ["number"] = 36,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "maxstar",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [37] = {
                        ["number"] = 37,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "heroname",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [38] = {
                        ["number"] = 38,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "isshow",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [39] = {
                        ["number"] = 39,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "accurate",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [40] = {
                        ["number"] = 40,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "deflect",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [41] = {
                        ["number"] = 41,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "avatar",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [42] = {
                        ["number"] = 42,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "newavatar",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [43] = {
                        ["number"] = 43,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "exskill",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "heros.proto",
["package"] = "pb"

----- end of proto -----
