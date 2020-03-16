name = npc_data.proto

package pb;

message npc_data {
    repeated t_npc_config datas = 1;    // type_name = .pb.npc_data.t_npc_config

    message t_npc_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required string name = 3;
        required uint32 kind = 4;
        required uint32 level = 5;
        required uint32 distance = 6;
        required string animatorcontroller = 7;
        required string model = 8;
        required string uimodelsize = 9;
        required uint32 uimodelrotation = 10;
        required string visiticon = 11;
        required string visitbtn = 12;
        required uint32 countryid = 13;
        required uint32 mapinfo = 14;
        required uint32 show_map = 15;
        required uint32 not_show_name = 16;
        required uint32 borntime = 17;
        required uint32 bornaction = 18;
        required string borneffect = 19;
        required bool not_beselect = 20;
        required string taskid = 21;
        required uint32 show_shadow = 22;
        required uint32 bodysize = 23;
        required uint32 hplayer = 24;
        required uint32 volume = 25;
        required uint32 appparentvolume = 26;
        required string heropainting = 27;
        required string herostate = 28;
        required uint32 pdamage = 29;
        required uint32 mdamage = 30;
        required uint32 pdefence = 31;
        required uint32 mdefence = 32;
        required uint32 maxhp = 33;
        required uint32 maxmp = 34;
        required uint32 bang = 35;
        required uint32 bangextradam = 36;
        required uint32 toughness = 37;
        required uint32 toughness_reducedam = 38;
        required uint32 block = 39;
        required uint32 block_reduce_dam = 40;
        required uint32 penetrate = 41;
        required uint32 penetrate_extra_dam = 42;
        required uint32 accurate = 43;
        required uint32 accurate_extra_dam = 44;
        required uint32 hold = 45;
        required uint32 hold_reduce_dam = 46;
        required uint32 deflect = 47;
        required uint32 deflect_reduce_dam = 48;
        required uint32 realdam = 49;
        required uint32 real_reduce_dam = 50;
        required uint32 hit = 51;
        required uint32 miss = 52;
        required uint32 firemastery = 53;
        required uint32 icemastery = 54;
        required uint32 lightningmastery = 55;
        required uint32 brightmastery = 56;
        required uint32 darkmastery = 57;
        required uint32 fireresist = 58;
        required uint32 iceresist = 59;
        required uint32 lightningresist = 60;
        required uint32 brightresist = 61;
        required uint32 darkresist = 62;
        required uint32 firepen = 63;
        required uint32 icepen = 64;
        required uint32 lightningpen = 65;
        required uint32 brightpen = 66;
        required uint32 darkpen = 67;
        required uint32 blowint = 68;
        required uint32 knockint = 69;
        required uint32 floatint = 70;
        required uint32 superhitint = 71;
        required uint32 blowresist = 72;
        required uint32 knockresist = 73;
        required uint32 floatresist = 74;
        required uint32 superhitresist = 75;
        required uint32 blowdectime = 76;
        required uint32 knockdectime = 77;
        required uint32 floatdectime = 78;
        required uint32 superhitdectime = 79;
        required uint32 stiffaddtime = 80;
        required uint32 stiffdectime = 81;
        required string icon = 82;
        required string bigicon = 83;
        required string UIicon = 84;
        required string modelsize = 85;
        required string show_conditions = 86;
        required string hide_conditions = 87;
        required string effect_appearance = 88;
        required string bipbind_excursion = 89;
        required string modelposfor3dicon = 90;
        required uint32 hatred_distance = 91;
        required uint32 guardRegion = 92;
        required uint32 visitfollow = 93;
        required uint32 lookat = 94;
        required string modelCon4Cha = 95;
        required string modelCon4Hero = 96;
        required string modelCon4Guide = 97;
        required string CapsuleCollider = 98;
        required string function = 99;
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
                ["type_name"] = ".pb.npc_data.t_npc_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "npc_data",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_npc_config",
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
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "kind",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "level",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "distance",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "animatorcontroller",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "model",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "uimodelsize",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "uimodelrotation",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "visiticon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "visitbtn",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [13] = {
                        ["number"] = 13,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "countryid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [14] = {
                        ["number"] = 14,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "mapinfo",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [15] = {
                        ["number"] = 15,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "show_map",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [16] = {
                        ["number"] = 16,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "not_show_name",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [17] = {
                        ["number"] = 17,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "borntime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [18] = {
                        ["number"] = 18,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "bornaction",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [19] = {
                        ["number"] = 19,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "borneffect",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [20] = {
                        ["number"] = 20,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "not_beselect",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [21] = {
                        ["number"] = 21,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "taskid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [22] = {
                        ["number"] = 22,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "show_shadow",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [23] = {
                        ["number"] = 23,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "bodysize",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [24] = {
                        ["number"] = 24,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "hplayer",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [25] = {
                        ["number"] = 25,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "volume",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [26] = {
                        ["number"] = 26,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "appparentvolume",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [27] = {
                        ["number"] = 27,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "heropainting",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [28] = {
                        ["number"] = 28,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "herostate",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [29] = {
                        ["number"] = 29,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "pdamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [30] = {
                        ["number"] = 30,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "mdamage",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [31] = {
                        ["number"] = 31,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "pdefence",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [32] = {
                        ["number"] = 32,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "mdefence",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [33] = {
                        ["number"] = 33,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "maxhp",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [34] = {
                        ["number"] = 34,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "maxmp",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [35] = {
                        ["number"] = 35,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "bang",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [36] = {
                        ["number"] = 36,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "bangextradam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [37] = {
                        ["number"] = 37,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "toughness",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [38] = {
                        ["number"] = 38,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "toughness_reducedam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [39] = {
                        ["number"] = 39,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "block",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [40] = {
                        ["number"] = 40,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "block_reduce_dam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [41] = {
                        ["number"] = 41,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "penetrate",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [42] = {
                        ["number"] = 42,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "penetrate_extra_dam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [43] = {
                        ["number"] = 43,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "accurate",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [44] = {
                        ["number"] = 44,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "accurate_extra_dam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [45] = {
                        ["number"] = 45,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "hold",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [46] = {
                        ["number"] = 46,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "hold_reduce_dam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [47] = {
                        ["number"] = 47,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "deflect",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [48] = {
                        ["number"] = 48,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "deflect_reduce_dam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [49] = {
                        ["number"] = 49,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "realdam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [50] = {
                        ["number"] = 50,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "real_reduce_dam",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [51] = {
                        ["number"] = 51,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "hit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [52] = {
                        ["number"] = 52,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "miss",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [53] = {
                        ["number"] = 53,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "firemastery",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [54] = {
                        ["number"] = 54,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "icemastery",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [55] = {
                        ["number"] = 55,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "lightningmastery",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [56] = {
                        ["number"] = 56,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "brightmastery",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [57] = {
                        ["number"] = 57,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "darkmastery",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [58] = {
                        ["number"] = 58,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "fireresist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [59] = {
                        ["number"] = 59,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "iceresist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [60] = {
                        ["number"] = 60,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "lightningresist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [61] = {
                        ["number"] = 61,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "brightresist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [62] = {
                        ["number"] = 62,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "darkresist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [63] = {
                        ["number"] = 63,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "firepen",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [64] = {
                        ["number"] = 64,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "icepen",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [65] = {
                        ["number"] = 65,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "lightningpen",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [66] = {
                        ["number"] = 66,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "brightpen",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [67] = {
                        ["number"] = 67,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "darkpen",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [68] = {
                        ["number"] = 68,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "blowint",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [69] = {
                        ["number"] = 69,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "knockint",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [70] = {
                        ["number"] = 70,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "floatint",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [71] = {
                        ["number"] = 71,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "superhitint",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [72] = {
                        ["number"] = 72,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "blowresist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [73] = {
                        ["number"] = 73,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "knockresist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [74] = {
                        ["number"] = 74,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "floatresist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [75] = {
                        ["number"] = 75,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "superhitresist",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [76] = {
                        ["number"] = 76,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "blowdectime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [77] = {
                        ["number"] = 77,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "knockdectime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [78] = {
                        ["number"] = 78,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "floatdectime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [79] = {
                        ["number"] = 79,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "superhitdectime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [80] = {
                        ["number"] = 80,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "stiffaddtime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [81] = {
                        ["number"] = 81,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "stiffdectime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [82] = {
                        ["number"] = 82,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "icon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [83] = {
                        ["number"] = 83,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "bigicon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [84] = {
                        ["number"] = 84,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "UIicon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [85] = {
                        ["number"] = 85,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "modelsize",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [86] = {
                        ["number"] = 86,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "show_conditions",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [87] = {
                        ["number"] = 87,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "hide_conditions",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [88] = {
                        ["number"] = 88,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "effect_appearance",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [89] = {
                        ["number"] = 89,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "bipbind_excursion",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [90] = {
                        ["number"] = 90,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "modelposfor3dicon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [91] = {
                        ["number"] = 91,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "hatred_distance",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [92] = {
                        ["number"] = 92,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "guardRegion",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [93] = {
                        ["number"] = 93,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "visitfollow",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [94] = {
                        ["number"] = 94,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "lookat",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [95] = {
                        ["number"] = 95,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "modelCon4Cha",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [96] = {
                        ["number"] = 96,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "modelCon4Hero",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [97] = {
                        ["number"] = 97,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "modelCon4Guide",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [98] = {
                        ["number"] = 98,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "CapsuleCollider",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [99] = {
                        ["number"] = 99,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "function",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "npc_data.proto",
["package"] = "pb"

----- end of proto -----
