name = object.proto

package Obj;

message EquipData {
    optional uint32 weaponatt = 1;
    optional uint32 pdam = 2;
    optional uint32 mdam = 3;
    optional uint32 pdef = 4;
    optional uint32 mdef = 5;
    optional uint32 maxhp = 6;
    optional uint32 str = 7;
    optional uint32 dex = 8;
    optional uint32 intel = 9;
    optional uint32 phy = 10;
    optional uint32 bang = 11;
    optional uint32 toughness = 12;
    optional uint32 block = 13;
    optional uint32 penetrate = 14;
    optional uint32 accurate = 15;
    optional uint32 hold = 16;
    optional uint32 deflect = 17;
    optional uint32 bangextradamage = 18;
    optional uint32 toughnessreducedamage = 19;
    optional uint32 blockreducedamage = 20;
    optional uint32 penetrateextradamage = 21;
    optional uint32 accurateextradamage = 22;
    optional uint32 holdreducedamage = 23;
    optional uint32 deflectreducedamage = 24;
    optional uint32 maxmp = 25;
    optional uint32 miss = 26;
    optional uint32 hit = 27;
    optional uint32 firemastery = 28;
    optional uint32 icemastery = 29;
    optional uint32 lightningmastery = 30;
    optional uint32 brightmastery = 31;
    optional uint32 darkmastery = 32;
    optional uint32 fireresist = 33;
    optional uint32 iceresist = 34;
    optional uint32 lightningresist = 35;
    optional uint32 brightresist = 36;
    optional uint32 darkresist = 37;
    optional uint32 firepen = 38;
    optional uint32 icepen = 39;
    optional uint32 lightningpen = 40;
    optional uint32 brightpen = 41;
    optional uint32 darkpen = 42;
    optional uint32 blowint = 43;
    optional uint32 knockint = 44;
    optional uint32 floatint = 45;
    optional uint32 superhitint = 46;
    optional uint32 blowresist = 47;
    optional uint32 knockresist = 48;
    optional uint32 floatresist = 49;
    optional uint32 superhitresist = 50;
    optional uint32 stiffaddtime = 51;
    optional uint32 stiffdectime = 52;
    optional uint32 blowdectime = 53;
    optional uint32 knockdectime = 54;
    optional uint32 floatdectime = 55;
    optional uint32 superhitdectime = 56;
}

message EquipRandInfo {
    optional Equip8Prop type = 1;    // type_name = .Obj.Equip8Prop
    optional uint32 id = 2;
    optional uint32 value = 3;
}

message CardEffectItem {
    optional uint32 id = 1;
    optional uint32 trigger = 2;
    optional uint32 value = 3;
    optional string varname = 4;
}

message CardData {
    optional uint32 cardtype = 1;
    optional uint32 cardstar = 2;
    optional uint32 cardgroup = 3;
    repeated CardEffectItem base_effect = 4;    // type_name = .Obj.CardEffectItem
    repeated CardEffectItem rand_effect = 5;    // type_name = .Obj.CardEffectItem
    optional uint32 durability = 6;
}

message t_Object {
    optional uint32 baseid = 1;
    optional string thisid = 2;
    optional ObjectType type = 3;    // type_name = .Obj.ObjectType
    optional PackType packtype = 4;    // type_name = .Obj.PackType
    optional string name = 5;
    optional uint32 num = 6;
    optional uint32 bind = 7;
    optional uint32 grid_x = 8;
    optional uint32 grid_y = 9;
    optional uint32 quality = 10;
    optional uint32 level = 11;
    optional uint32 timer = 12;
    optional EquipData equipprop = 13;    // type_name = .Obj.EquipData
    repeated EquipRandInfo equiprand = 14;    // type_name = .Obj.EquipRandInfo
    optional uint32 nextusetime = 15;
    optional CardData card_data = 16;    // type_name = .Obj.CardData
    optional uint32 lock_end_time = 17;
    optional uint32 tradetime = 18;
}

message PrizeBase {
    optional uint32 id = 1;
    optional uint32 quantity = 2;
}

message VIPCardInfo {
    optional uint64 remaintime = 1;
    optional uint32 raffcount = 2;
    optional uint32 total_raffcount = 3;
    optional uint32 dayprize_state = 4;
    repeated PrizeBase arrprize = 5;    // type_name = .Obj.PrizeBase
    optional uint32 objraffcount = 6;
}

message MSG_RefreshObjs_SC {
    repeated t_Object objs = 1;    // type_name = .Obj.t_Object
    optional bool show_addnew_anim = 2 [default = true];
}

message MSG_PackData_SC {
    required PackType packtype = 1;    // type_name = .Obj.PackType
    optional uint32 width = 2;
    optional uint32 height = 3;
    optional uint32 validsize = 4;
    optional MSG_RefreshObjs_SC objects = 5;    // type_name = .Obj.MSG_RefreshObjs_SC
    optional uint32 unlockcount = 6;
}

message MSG_WearEquip_CS {
    optional string thisid = 1;
}

message MSG_WearEquip_SC {
    optional string thisid = 1;
}

message MSG_RemoveObject_SC {
    repeated string ids = 1;
}

message MSG_UnwearEquip_CS {
    optional string thisid = 1;
}

message MSG_UnwearEquip_SC {
    optional string thisid = 1;
}

message MSG_ReqCheckItemDueTime_CS {
null
}

message MSG_ReqUseObject_CS {
    optional string thisid = 1;
    optional uint32 num = 2 [default = 1];
}

message MSG_ReqUseObject_Special_CS {
    optional string thisid = 1;
    optional uint32 num = 2 [default = 1];
    optional uint64 npcid = 3;
    optional float posx = 4;
    optional float posy = 5;
}

message MSG_PackUnlock_CS {
    required PackType packtype = 1;    // type_name = .Obj.PackType
}

message MSG_PackUnlock_SC {
    required PackType packtype = 1;    // type_name = .Obj.PackType
    optional uint32 unlockcount = 2;
    optional uint32 maxsize = 3;
    optional bool result = 4;
}

message MSG_MergeObjs_CS {
    required PackType packtype = 1;    // type_name = .Obj.PackType
    repeated string srcthisids = 2;
    repeated string dstthisids = 3;
    optional PackType dst_packtype = 4;    // type_name = .Obj.PackType
}

message MSG_MergeObjs_SC {
    required PackType packtype = 1;    // type_name = .Obj.PackType
    optional bool result = 2;
    optional PackType dst_packtype = 3;    // type_name = .Obj.PackType
}

message t_TidyPackInfo {
    optional string thisid = 1;
    optional uint32 grid_x = 2;
    optional uint32 grid_y = 3;
}

message MSG_TidyPack_CS {
    required PackType packtype = 1;    // type_name = .Obj.PackType
    repeated t_TidyPackInfo infos = 2;    // type_name = .Obj.t_TidyPackInfo
}

message MSG_TidyPack_SC {
    required PackType packtype = 1;    // type_name = .Obj.PackType
    optional bool result = 2;
}

message MSG_ReqSellObject_CS {
    optional string thisid = 1;
    optional uint32 num = 2 [default = 1];
    optional string passwd = 3;
}

message MSG_ReqMoveObject_CS {
    optional string thisid = 1;
    optional uint32 grid_x = 2;
    optional uint32 grid_y = 3;
    required PackType packtype = 4;    // type_name = .Obj.PackType
    optional PackType dst_packtype = 5;    // type_name = .Obj.PackType
}

message MSG_ReqSwapObject_CS {
    optional string src_thisid = 1;
    optional string dst_thisid = 2;
    optional PackType dst_packtype = 3;    // type_name = .Obj.PackType
    required PackType packtype = 4;    // type_name = .Obj.PackType
}

message MSG_ReqDestroyObject_CS {
    optional string thisid = 1;
    required PackType packtype = 2;    // type_name = .Obj.PackType
    optional string passwd = 3;
}

message MSG_ReqPutOnCard_CS {
    optional string thisid = 1;
    optional uint32 grid_x = 2;
    optional uint32 grid_y = 3;
    optional PackType packtype = 4;    // type_name = .Obj.PackType
}

message MSG_ReqPutOffCard_CS {
    optional string thisid = 1;
    optional uint32 grid_x = 2;
    optional uint32 grid_y = 3;
}

message MSG_ReqSwapCard_CS {
    optional string src_thisid = 1;
    optional string dst_thisid = 2;
}

message MSG_ReqCardPackInfo_CS {
null
}

message CardPackInfo {
    optional uint32 gold_opened_num = 1;
    optional uint32 wood_opened_num = 2;
    optional uint32 water_opened_num = 3;
    optional uint32 fire_opened_num = 4;
    optional uint32 earth_opened_num = 5;
    optional uint32 hero_baseid = 6;
    repeated t_Object objs = 7;    // type_name = .Obj.t_Object
}

message MSG_RetCardPackInfo_SC {
    optional CardPackInfo data = 1;    // type_name = .Obj.CardPackInfo
}

message MSG_ReqSplitObject_CS {
    optional string thisid = 1;
    optional uint32 num = 2;
    optional PackType packtype = 3;    // type_name = .Obj.PackType
}

message MSG_ReqOpItemLock_CS {
    optional string thisid = 1;
    optional PackType packtype = 2;    // type_name = .Obj.PackType
    optional uint32 opcode = 3;
    optional string passwd = 4;
}

message MSG_ReqGetVIPCardInfo_CS {
null
}

message MSG_RetGetVIPCardInfo_SC {
    optional VIPCardInfo vipcardinfo = 1;    // type_name = .Obj.VIPCardInfo
}

message MSG_ReqBuyVIPCard_CS {
    optional uint32 cardid = 1;
    optional uint32 count = 2 [default = 1];
}

message MSG_RetBuyVIPCard_SC {
    optional VIPCardInfo vipcardinfo = 1;    // type_name = .Obj.VIPCardInfo
}

message MSG_ReqAcepVIPCardPrize_CS {
null
}

message MSG_RetAcepVIPCardPrize_SC {
    optional VIPCardInfo vipcardinfo = 1;    // type_name = .Obj.VIPCardInfo
}

message MSG_ReqRaffVIPCardPrize_CS {
    optional RaffUseType usetype = 1;    // type_name = .Obj.RaffUseType
}

message MSG_RetRaffVIPCardPrize_SC {
    optional VIPCardInfo vipcardinfo = 1;    // type_name = .Obj.VIPCardInfo
    optional uint32 id = 2;
    optional uint32 quantity = 3;
}

message MSG_ReqCurrencyExchange_CS {
    optional uint32 usequantity = 1;
}

message MSG_RetCurrencyExchange_SC {
    optional uint32 result = 1;
}

message MSG_ReqTransMoney_CS {
    optional PackType packtype = 1;    // type_name = .Obj.PackType
    optional PackType dst_packtype = 2;    // type_name = .Obj.PackType
    optional uint32 resourceID = 3;
    optional uint32 quantity = 4;
}

message MSG_ReqFixUpDurability_CS {
    optional PackType packtype = 1;    // type_name = .Obj.PackType
    optional string thisid = 2;
}

message MSG_ReqUseCapsule_CS {
    optional string thisid = 1;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "PackType",
        ["value"] = {
            [1] = {
                ["name"] = "PACK_TYPE_NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "PACK_TYPE_MAIN",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "PACK_TYPE_EQUIP",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "PACK_TYPE_QUEST",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "PACK_TYPE_HERO_CARD",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "PACK_TYPE_WAREHOUSE1",
                ["number"] = 5
            },
            [7] = {
                ["name"] = "PACK_TYPE_WAREHOUSE2",
                ["number"] = 6
            },
            [8] = {
                ["name"] = "PACK_TYPE_WAREHOUSE3",
                ["number"] = 7
            },
            [9] = {
                ["name"] = "PACK_TYPE_WAREHOUSE4",
                ["number"] = 8
            },
            [10] = {
                ["name"] = "PACK_TYPE_CPASULE",
                ["number"] = 9
            },
            [11] = {
                ["name"] = "PACK_TYPE_MAX",
                ["number"] = 10
            }
        }
    },
    [2] = {
        ["name"] = "SpecialType",
        ["value"] = {
            [1] = {
                ["name"] = "EQUIP_CAREER_NOLIMIT",
                ["number"] = 999
            }
        }
    },
    [3] = {
        ["options"] = {
            ["allow_alias"] = true
        },
        ["name"] = "ObjectType",
        ["value"] = {
            [1] = {
                ["name"] = "OBJTYPE_WEAPON_NPC",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "OBJTYPE_WEAPON_MIN",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "OBJTYPE_SINGLE_SWORD",
                ["number"] = 1
            },
            [4] = {
                ["name"] = "OBJTYPE_TWO_DAGGER",
                ["number"] = 2
            },
            [5] = {
                ["name"] = "OBJTYPE_DOUBLE_GREATSWORD",
                ["number"] = 3
            },
            [6] = {
                ["name"] = "OBJTYPE_MAGIC_BALL",
                ["number"] = 4
            },
            [7] = {
                ["name"] = "OBJTYPE_WEAPON_MAX",
                ["number"] = 20
            },
            [8] = {
                ["name"] = "OBJTYPE_EQUIP_MIN",
                ["number"] = 21
            },
            [9] = {
                ["name"] = "OBJTYPE_EQUIP_HEAD",
                ["number"] = 21
            },
            [10] = {
                ["name"] = "OBJTYPE_EQUIP_SHOULDER",
                ["number"] = 22
            },
            [11] = {
                ["name"] = "OBJTYPE_EQUIP_CHEST",
                ["number"] = 23
            },
            [12] = {
                ["name"] = "OBJTYPE_EQUIP_HAND",
                ["number"] = 24
            },
            [13] = {
                ["name"] = "OBJTYPE_EQUIP_WAIST",
                ["number"] = 25
            },
            [14] = {
                ["name"] = "OBJTYPE_EQUIP_LEG",
                ["number"] = 26
            },
            [15] = {
                ["name"] = "OBJTYPE_EQUIP_FOOT",
                ["number"] = 27
            },
            [16] = {
                ["name"] = "OBJTYPE_EQUIP_NECK",
                ["number"] = 28
            },
            [17] = {
                ["name"] = "OBJTYPE_EQUIP_ACCESSORY",
                ["number"] = 29
            },
            [18] = {
                ["name"] = "OBJTYPE_EQUIP_WEAPON",
                ["number"] = 30
            },
            [19] = {
                ["name"] = "OBJTYPE_EQUIP_MAX",
                ["number"] = 31
            },
            [20] = {
                ["name"] = "OBJTYPE_RES",
                ["number"] = 41
            },
            [21] = {
                ["name"] = "OBJTYPE_SPET_EXP",
                ["number"] = 42
            },
            [22] = {
                ["name"] = "OBJTYPE_FRIENDOATH",
                ["number"] = 43
            },
            [23] = {
                ["name"] = "OBJTYPE_QUEST",
                ["number"] = 45
            },
            [24] = {
                ["name"] = "OBJTYPE_PET",
                ["number"] = 46
            },
            [25] = {
                ["name"] = "OBJTYPE_GIFT_BAG",
                ["number"] = 47
            },
            [26] = {
                ["name"] = "OBJTYPE_CAN_USE",
                ["number"] = 48
            },
            [27] = {
                ["name"] = "OBJTYPE_HERO",
                ["number"] = 49
            },
            [28] = {
                ["name"] = "OBJTYPE_RUNE",
                ["number"] = 50
            },
            [29] = {
                ["name"] = "OBJTYPE_RING_QUEST",
                ["number"] = 51
            },
            [30] = {
                ["name"] = "OBJTYPE_TREASURE_RADAR",
                ["number"] = 52
            },
            [31] = {
                ["name"] = "OBJTYPE_CARD",
                ["number"] = 53
            },
            [32] = {
                ["name"] = "OBJTYPE_QUEST2",
                ["number"] = 60
            },
            [33] = {
                ["name"] = "OBJTYPE_DNA",
                ["number"] = 61
            },
            [34] = {
                ["name"] = "OBJTYPE_DNA2",
                ["number"] = 62
            },
            [35] = {
                ["name"] = "OBJTYPE_CLEAR_BATTLESTATE",
                ["number"] = 63
            },
            [36] = {
                ["name"] = "OBJTYPE_SKILL",
                ["number"] = 64
            },
            [37] = {
                ["name"] = "OBJTYPE_EVOLUTION",
                ["number"] = 65
            },
            [38] = {
                ["name"] = "OBJTYPE_AVATAR",
                ["number"] = 66
            },
            [39] = {
                ["name"] = "OBJTYPE_NORMAL_ITEM_QUEST",
                ["number"] = 67
            },
            [40] = {
                ["name"] = "OBJTYPE_CAPSULE",
                ["number"] = 68
            },
            [41] = {
                ["name"] = "OBJTYPE_MAX",
                ["number"] = 69
            }
        }
    },
    [4] = {
        ["name"] = "ObjectId",
        ["value"] = {
            [1] = {
                ["name"] = "APPRENT_LETTER",
                ["number"] = 103
            },
            [2] = {
                ["name"] = "VATALITY_PILL",
                ["number"] = 108
            },
            [3] = {
                ["name"] = "REMOVE_ERROR_CAPSULE",
                ["number"] = 109
            },
            [4] = {
                ["name"] = "INTELLECTUALITY_CAPSULE",
                ["number"] = 110
            },
            [5] = {
                ["name"] = "TIME_CAPSULE",
                ["number"] = 111
            }
        }
    },
    [5] = {
        ["name"] = "EquipType",
        ["value"] = {
            [1] = {
                ["name"] = "EQUIP_HEAD",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "EQUIP_SHOULDER",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "EQUIP_CHEST",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "EQUIP_HAND",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "EQUIP_WAIST",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "EQUIP_LEG",
                ["number"] = 5
            },
            [7] = {
                ["name"] = "EQUIP_FOOT",
                ["number"] = 6
            },
            [8] = {
                ["name"] = "EQUIP_NECK",
                ["number"] = 7
            },
            [9] = {
                ["name"] = "EQUIP_ACCESSORY_1",
                ["number"] = 8
            },
            [10] = {
                ["name"] = "EQUIP_ACCESSORY_2",
                ["number"] = 9
            },
            [11] = {
                ["name"] = "EQUIP_WEAPON",
                ["number"] = 10
            },
            [12] = {
                ["name"] = "EQUIP_INVALID_POS",
                ["number"] = 11
            }
        }
    },
    [6] = {
        ["name"] = "RaffUseType",
        ["value"] = {
            [1] = {
                ["name"] = "RAFFUSETYPE_FREETIMES",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "RAFFUSETYPE_OBJECT",
                ["number"] = 1
            }
        }
    },
    [7] = {
        ["name"] = "Equip8Prop",
        ["value"] = {
            [1] = {
                ["name"] = "BASIC_PROP",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "PROP_1",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "PROP_2",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "SUFFIX_1",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "SUFFIX_2",
                ["number"] = 5
            },
            [6] = {
                ["name"] = "SUFFIX_3",
                ["number"] = 6
            },
            [7] = {
                ["name"] = "SUFFIX_4",
                ["number"] = 7
            },
            [8] = {
                ["name"] = "FIXED_PROP",
                ["number"] = 8
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "EquipData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "weaponatt",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pdam",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mdam",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pdef",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mdef",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxhp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "str",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dex",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "intel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "phy",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bang",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT32",
                ["name"] = "toughness",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 13,
                ["type"] = "TYPE_UINT32",
                ["name"] = "block",
                ["label"] = "LABEL_OPTIONAL"
            },
            [14] = {
                ["number"] = 14,
                ["type"] = "TYPE_UINT32",
                ["name"] = "penetrate",
                ["label"] = "LABEL_OPTIONAL"
            },
            [15] = {
                ["number"] = 15,
                ["type"] = "TYPE_UINT32",
                ["name"] = "accurate",
                ["label"] = "LABEL_OPTIONAL"
            },
            [16] = {
                ["number"] = 16,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hold",
                ["label"] = "LABEL_OPTIONAL"
            },
            [17] = {
                ["number"] = 17,
                ["type"] = "TYPE_UINT32",
                ["name"] = "deflect",
                ["label"] = "LABEL_OPTIONAL"
            },
            [18] = {
                ["number"] = 18,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bangextradamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [19] = {
                ["number"] = 19,
                ["type"] = "TYPE_UINT32",
                ["name"] = "toughnessreducedamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [20] = {
                ["number"] = 20,
                ["type"] = "TYPE_UINT32",
                ["name"] = "blockreducedamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [21] = {
                ["number"] = 21,
                ["type"] = "TYPE_UINT32",
                ["name"] = "penetrateextradamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [22] = {
                ["number"] = 22,
                ["type"] = "TYPE_UINT32",
                ["name"] = "accurateextradamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [23] = {
                ["number"] = 23,
                ["type"] = "TYPE_UINT32",
                ["name"] = "holdreducedamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [24] = {
                ["number"] = 24,
                ["type"] = "TYPE_UINT32",
                ["name"] = "deflectreducedamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [25] = {
                ["number"] = 25,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxmp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [26] = {
                ["number"] = 26,
                ["type"] = "TYPE_UINT32",
                ["name"] = "miss",
                ["label"] = "LABEL_OPTIONAL"
            },
            [27] = {
                ["number"] = 27,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hit",
                ["label"] = "LABEL_OPTIONAL"
            },
            [28] = {
                ["number"] = 28,
                ["type"] = "TYPE_UINT32",
                ["name"] = "firemastery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [29] = {
                ["number"] = 29,
                ["type"] = "TYPE_UINT32",
                ["name"] = "icemastery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [30] = {
                ["number"] = 30,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lightningmastery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [31] = {
                ["number"] = 31,
                ["type"] = "TYPE_UINT32",
                ["name"] = "brightmastery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [32] = {
                ["number"] = 32,
                ["type"] = "TYPE_UINT32",
                ["name"] = "darkmastery",
                ["label"] = "LABEL_OPTIONAL"
            },
            [33] = {
                ["number"] = 33,
                ["type"] = "TYPE_UINT32",
                ["name"] = "fireresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [34] = {
                ["number"] = 34,
                ["type"] = "TYPE_UINT32",
                ["name"] = "iceresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [35] = {
                ["number"] = 35,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lightningresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [36] = {
                ["number"] = 36,
                ["type"] = "TYPE_UINT32",
                ["name"] = "brightresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [37] = {
                ["number"] = 37,
                ["type"] = "TYPE_UINT32",
                ["name"] = "darkresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [38] = {
                ["number"] = 38,
                ["type"] = "TYPE_UINT32",
                ["name"] = "firepen",
                ["label"] = "LABEL_OPTIONAL"
            },
            [39] = {
                ["number"] = 39,
                ["type"] = "TYPE_UINT32",
                ["name"] = "icepen",
                ["label"] = "LABEL_OPTIONAL"
            },
            [40] = {
                ["number"] = 40,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lightningpen",
                ["label"] = "LABEL_OPTIONAL"
            },
            [41] = {
                ["number"] = 41,
                ["type"] = "TYPE_UINT32",
                ["name"] = "brightpen",
                ["label"] = "LABEL_OPTIONAL"
            },
            [42] = {
                ["number"] = 42,
                ["type"] = "TYPE_UINT32",
                ["name"] = "darkpen",
                ["label"] = "LABEL_OPTIONAL"
            },
            [43] = {
                ["number"] = 43,
                ["type"] = "TYPE_UINT32",
                ["name"] = "blowint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [44] = {
                ["number"] = 44,
                ["type"] = "TYPE_UINT32",
                ["name"] = "knockint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [45] = {
                ["number"] = 45,
                ["type"] = "TYPE_UINT32",
                ["name"] = "floatint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [46] = {
                ["number"] = 46,
                ["type"] = "TYPE_UINT32",
                ["name"] = "superhitint",
                ["label"] = "LABEL_OPTIONAL"
            },
            [47] = {
                ["number"] = 47,
                ["type"] = "TYPE_UINT32",
                ["name"] = "blowresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [48] = {
                ["number"] = 48,
                ["type"] = "TYPE_UINT32",
                ["name"] = "knockresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [49] = {
                ["number"] = 49,
                ["type"] = "TYPE_UINT32",
                ["name"] = "floatresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [50] = {
                ["number"] = 50,
                ["type"] = "TYPE_UINT32",
                ["name"] = "superhitresist",
                ["label"] = "LABEL_OPTIONAL"
            },
            [51] = {
                ["number"] = 51,
                ["type"] = "TYPE_UINT32",
                ["name"] = "stiffaddtime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [52] = {
                ["number"] = 52,
                ["type"] = "TYPE_UINT32",
                ["name"] = "stiffdectime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [53] = {
                ["number"] = 53,
                ["type"] = "TYPE_UINT32",
                ["name"] = "blowdectime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [54] = {
                ["number"] = 54,
                ["type"] = "TYPE_UINT32",
                ["name"] = "knockdectime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [55] = {
                ["number"] = 55,
                ["type"] = "TYPE_UINT32",
                ["name"] = "floatdectime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [56] = {
                ["number"] = 56,
                ["type"] = "TYPE_UINT32",
                ["name"] = "superhitdectime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "EquipRandInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.Equip8Prop",
                ["name"] = "type"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "value",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "CardEffectItem",
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
                ["name"] = "trigger",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "value",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_STRING",
                ["name"] = "varname",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "CardData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cardtype",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cardstar",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cardgroup",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.CardEffectItem",
                ["name"] = "base_effect"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.CardEffectItem",
                ["name"] = "rand_effect"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "durability",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "t_Object",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "baseid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.ObjectType",
                ["name"] = "type"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bind",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "grid_x",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "grid_y",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "quality",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT32",
                ["name"] = "timer",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 13,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.EquipData",
                ["name"] = "equipprop"
            },
            [14] = {
                ["number"] = 14,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.EquipRandInfo",
                ["name"] = "equiprand"
            },
            [15] = {
                ["number"] = 15,
                ["type"] = "TYPE_UINT32",
                ["name"] = "nextusetime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [16] = {
                ["number"] = 16,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.CardData",
                ["name"] = "card_data"
            },
            [17] = {
                ["number"] = 17,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lock_end_time",
                ["label"] = "LABEL_OPTIONAL"
            },
            [18] = {
                ["number"] = 18,
                ["type"] = "TYPE_UINT32",
                ["name"] = "tradetime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "PrizeBase",
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
                ["name"] = "quantity",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "VIPCardInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "remaintime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "raffcount",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "total_raffcount",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dayprize_state",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.PrizeBase",
                ["name"] = "arrprize"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objraffcount",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_RefreshObjs_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.t_Object",
                ["name"] = "objs"
            },
            [2] = {
                ["number"] = 2,
                ["default_value"] = "true",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "show_addnew_anim"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_PackData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "width",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "height",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "validsize",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.MSG_RefreshObjs_SC",
                ["name"] = "objects"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "unlockcount",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_WearEquip_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_WearEquip_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_RemoveObject_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "ids",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_UnwearEquip_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_UnwearEquip_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_ReqCheckItemDueTime_CS"
    },
    [16] = {
        ["name"] = "MSG_ReqUseObject_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["default_value"] = "1",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_UINT32",
                ["name"] = "num"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_ReqUseObject_Special_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["default_value"] = "1",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_UINT32",
                ["name"] = "num"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT64",
                ["name"] = "npcid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "posx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "posy",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_PackUnlock_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_PackUnlock_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "unlockcount",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxsize",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_MergeObjs_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "srcthisids",
                ["label"] = "LABEL_REPEATED"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "dstthisids",
                ["label"] = "LABEL_REPEATED"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "dst_packtype"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_MergeObjs_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "dst_packtype"
            }
        }
    },
    [22] = {
        ["name"] = "t_TidyPackInfo",
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
                ["name"] = "grid_x",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "grid_y",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [23] = {
        ["name"] = "MSG_TidyPack_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.t_TidyPackInfo",
                ["name"] = "infos"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_TidyPack_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [25] = {
        ["name"] = "MSG_ReqSellObject_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["default_value"] = "1",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_UINT32",
                ["name"] = "num"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "passwd",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [26] = {
        ["name"] = "MSG_ReqMoveObject_CS",
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
                ["name"] = "grid_x",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "grid_y",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "dst_packtype"
            }
        }
    },
    [27] = {
        ["name"] = "MSG_ReqSwapObject_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "src_thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "dst_thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "dst_packtype"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            }
        }
    },
    [28] = {
        ["name"] = "MSG_ReqDestroyObject_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "passwd",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [29] = {
        ["name"] = "MSG_ReqPutOnCard_CS",
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
                ["name"] = "grid_x",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "grid_y",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            }
        }
    },
    [30] = {
        ["name"] = "MSG_ReqPutOffCard_CS",
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
                ["name"] = "grid_x",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "grid_y",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [31] = {
        ["name"] = "MSG_ReqSwapCard_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "src_thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "dst_thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [32] = {
        ["name"] = "MSG_ReqCardPackInfo_CS"
    },
    [33] = {
        ["name"] = "CardPackInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "gold_opened_num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "wood_opened_num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "water_opened_num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "fire_opened_num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "earth_opened_num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hero_baseid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.t_Object",
                ["name"] = "objs"
            }
        }
    },
    [34] = {
        ["name"] = "MSG_RetCardPackInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.CardPackInfo",
                ["name"] = "data"
            }
        }
    },
    [35] = {
        ["name"] = "MSG_ReqSplitObject_CS",
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
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            }
        }
    },
    [36] = {
        ["name"] = "MSG_ReqOpItemLock_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "opcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_STRING",
                ["name"] = "passwd",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [37] = {
        ["name"] = "MSG_ReqGetVIPCardInfo_CS"
    },
    [38] = {
        ["name"] = "MSG_RetGetVIPCardInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.VIPCardInfo",
                ["name"] = "vipcardinfo"
            }
        }
    },
    [39] = {
        ["name"] = "MSG_ReqBuyVIPCard_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cardid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["default_value"] = "1",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_UINT32",
                ["name"] = "count"
            }
        }
    },
    [40] = {
        ["name"] = "MSG_RetBuyVIPCard_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.VIPCardInfo",
                ["name"] = "vipcardinfo"
            }
        }
    },
    [41] = {
        ["name"] = "MSG_ReqAcepVIPCardPrize_CS"
    },
    [42] = {
        ["name"] = "MSG_RetAcepVIPCardPrize_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.VIPCardInfo",
                ["name"] = "vipcardinfo"
            }
        }
    },
    [43] = {
        ["name"] = "MSG_ReqRaffVIPCardPrize_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.RaffUseType",
                ["name"] = "usetype"
            }
        }
    },
    [44] = {
        ["name"] = "MSG_RetRaffVIPCardPrize_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.VIPCardInfo",
                ["name"] = "vipcardinfo"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "quantity",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [45] = {
        ["name"] = "MSG_ReqCurrencyExchange_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "usequantity",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [46] = {
        ["name"] = "MSG_RetCurrencyExchange_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [47] = {
        ["name"] = "MSG_ReqTransMoney_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "dst_packtype"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "resourceID",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "quantity",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [48] = {
        ["name"] = "MSG_ReqFixUpDurability_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Obj.PackType",
                ["name"] = "packtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [49] = {
        ["name"] = "MSG_ReqUseCapsule_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "object.proto",
["package"] = "Obj"

----- end of proto -----
