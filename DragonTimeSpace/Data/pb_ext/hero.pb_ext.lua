name = hero.proto

package hero;

message Hero {
    optional string thisid = 1;
    optional uint32 baseid = 2;
    optional uint32 star = 3;
    optional uint32 bind = 4;
    optional uint32 lock = 5;
    optional uint32 runepageid = 6;
    optional uint32 score = 7;
    optional HeroTrain train = 8;    // type_name = .hero.HeroTrain
    optional HeroSkill skill = 9;    // type_name = .hero.HeroSkill
    optional HeroAvatar avatar = 10;    // type_name = .hero.HeroAvatar
    optional HeroEvolution evolution = 11;    // type_name = .hero.HeroEvolution
    optional HeroShow show = 12;    // type_name = .hero.HeroShow
    optional CardPackInfo cardpack = 13;    // type_name = .Obj.CardPackInfo
    optional uint32 tradetime = 14;
    optional uint32 level = 15;
    optional uint64 exp = 16;
    optional bool self_created = 17;
}

message HeroShow {
    optional uint32 facestyle = 1;
    optional uint32 hairstyle = 2;
    optional uint32 bodystyle = 3;
    optional uint32 haircolor = 4;
    optional uint32 antenna = 5;
}

message HeroTrain {
    optional uint32 pdamage = 2;
    optional uint32 mdamage = 3;
    optional uint32 pdefence = 4;
    optional uint32 mdefence = 5;
    optional uint32 maxhp = 6;
}

message HeroSkillItem {
    optional uint32 skillbaseid = 1;
    optional uint32 skilllevel = 2;
    optional uint32 skillorgid = 3;
}

message HeroSkill {
    repeated HeroSkillItem skill = 1;    // type_name = .hero.HeroSkillItem
}

message HeroAvatar {
    repeated uint32 avatars = 1;
    repeated AvatarPair equAvatars = 2;    // type_name = .avatar.AvatarPair
    optional uint32 attrAvatar = 3;
    optional uint32 activeAvatar = 4;
    optional uint32 tranSkill = 5;
}

message HeroEvolution {
    repeated uint32 evolutions = 1;
}

message MSG_ReqSwitchHero_CS {
    optional string toherothisid = 1;
}

message MSG_RetSwitchHero_SC {
    optional uint32 errcode = 1;
    optional string curhero = 2;
}

message MSG_NotifyAllHeros_SC {
    repeated Hero heroinfo = 1;    // type_name = .hero.Hero
}

message MSG_NotifyHeroChange_SC {
    optional uint32 changetype = 1;
    repeated Hero herolist = 2;    // type_name = .hero.Hero
}

message MSG_ReqHeroTrain_CS {
    optional string herothisid = 1;
    optional uint32 traintimes = 2;
    optional bool isusewater = 3;
}

message MSG_RetHeroTrain_SC {
    optional uint32 errcode = 1;
    optional Hero herocurinfo = 2;    // type_name = .hero.Hero
}

message MSG_ReqLockUnlockHero_CS {
    optional string herothisid = 1;
    optional uint32 locktype = 2;
}

message MSG_RetLockUnlockHero_SC {
    optional uint32 retcode = 1;
    optional string herothisid = 2;
    optional uint32 locktype = 3;
}

message MSG_ReqLevelupHeroSkill_CS {
    optional string herothisid = 1;
    optional uint32 skillbaseid = 2;
    optional uint32 skilllevel = 3;
}

message MSG_RetLevelupHeroSkill_SC {
    optional uint32 retcode = 1;
    optional string herothisid = 2;
    optional uint32 skillbaseid = 3;
    optional uint32 skilllevel = 4;
    optional uint32 skillorgid = 5;
}

message MSG_notifyRefreshHero_SC {
    optional Hero heroinfo = 1;    // type_name = .hero.Hero
}

message MSG_ReqRiseStar_CS {
    optional string sourcethisid = 1;
    optional string costthisid = 2;
}

message MSG_RetRiseStar_SC {
    optional uint32 retcode = 1;
    optional string sourcethisid = 2;
    optional string costthisid = 3;
}

message DnaItem {
    optional uint32 id = 1;
    optional uint32 level = 2;
    optional uint32 num = 3;
}

message MSG_DnaBagInfo_CSC {
    repeated DnaItem datas = 1;    // type_name = .hero.DnaItem
    optional DNAPage cur_page = 2;    // type_name = .hero.DNAPage
}

message Hole {
    optional uint32 pos = 1;
    optional uint32 id = 2;
    optional uint32 level = 3;
    optional DNAPage page = 4;    // type_name = .hero.DNAPage
    optional DNASlotType type = 5;    // type_name = .hero.DNASlotType
}

message MSG_DnaPageInfo_CSC {
    optional DNAPage page = 1;    // type_name = .hero.DNAPage
    repeated Hole att_holes = 2;    // type_name = .hero.Hole
    repeated Hole def_holes = 3;    // type_name = .hero.Hole
    optional uint32 att_opened_num = 4;
    optional uint32 def_opened_num = 5;
}

message MSG_ReqPutOnDna_CS {
    optional DNAPage page = 1;    // type_name = .hero.DNAPage
    optional uint32 pos = 2;
    optional uint32 id = 3;
    optional uint32 level = 4;
    optional DNASlotType type = 5;    // type_name = .hero.DNASlotType
}

message MSG_ReqPutOffDna_CS {
    optional DNAPage page = 1;    // type_name = .hero.DNAPage
    optional uint32 pos = 2;
    optional DNASlotType type = 3;    // type_name = .hero.DNASlotType
}

message MSG_ReqCombineDna_CS {
    optional DNAPage page = 1;    // type_name = .hero.DNAPage
    optional uint32 pos = 2;
    optional DNASlotType type = 3;    // type_name = .hero.DNASlotType
    optional uint32 num = 4;
}

message MSG_ReqChangeCurDnaPage_CS {
    optional DNAPage page = 1;    // type_name = .hero.DNAPage
}

message MSG_ReqCombineDnaInBag_CS {
    optional uint32 id = 1;
    optional uint32 level = 2;
    optional uint32 num = 3;
}

message MSG_ReqBuySlot_SC {
    optional DNAPage page = 1;    // type_name = .hero.DNAPage
    optional DNASlotType type = 2;    // type_name = .hero.DNASlotType
}

message MSG_ResponseSlotOpened_SC {
    optional DNAPage page = 1;    // type_name = .hero.DNAPage
    optional DNASlotType type = 2;    // type_name = .hero.DNASlotType
    optional uint32 cur_num = 3;
}

message MSG_AllDnaPageInfo_CSC {
    repeated MSG_DnaPageInfo_CSC pages = 1;    // type_name = .hero.MSG_DnaPageInfo_CSC
}

message MSG_SetMainHero_CSC {
    optional uint64 herothisid = 1;
    optional uint32 opcode = 2;
    optional uint32 errorcode = 3;
}

message HeroScore {
    optional uint64 thisid = 1;
    optional uint32 score = 2;
}

message MSG_NotifyClientHeroScore_SC {
    repeated HeroScore scores = 1;    // type_name = .hero.HeroScore
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "DNAPage",
        ["value"] = {
            [1] = {
                ["name"] = "NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "PAGE1",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "PAGE2",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "PAGE3",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "PAGE4",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "MAX",
                ["number"] = 5
            }
        }
    },
    [2] = {
        ["name"] = "DNASlotType",
        ["value"] = {
            [1] = {
                ["name"] = "ATT",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "DEF",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "ALL",
                ["number"] = 2
            }
        }
    }
},
["package"] = "hero",
["name"] = "hero.proto",
["dependency"] = {
    [1] = "object.proto",
    [2] = "avatar.proto"
},
["message_type"] = {
    [1] = {
        ["name"] = "Hero",
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
                ["name"] = "baseid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "star",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bind",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lock",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "runepageid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "score",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.HeroTrain",
                ["name"] = "train"
            },
            [9] = {
                ["number"] = 9,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.HeroSkill",
                ["name"] = "skill"
            },
            [10] = {
                ["number"] = 10,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.HeroAvatar",
                ["name"] = "avatar"
            },
            [11] = {
                ["number"] = 11,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.HeroEvolution",
                ["name"] = "evolution"
            },
            [12] = {
                ["number"] = 12,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.HeroShow",
                ["name"] = "show"
            },
            [13] = {
                ["number"] = 13,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.CardPackInfo",
                ["name"] = "cardpack"
            },
            [14] = {
                ["number"] = 14,
                ["type"] = "TYPE_UINT32",
                ["name"] = "tradetime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [15] = {
                ["number"] = 15,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [16] = {
                ["number"] = 16,
                ["type"] = "TYPE_UINT64",
                ["name"] = "exp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [17] = {
                ["number"] = 17,
                ["type"] = "TYPE_BOOL",
                ["name"] = "self_created",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "HeroShow",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "facestyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hairstyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bodystyle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "haircolor",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "antenna",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "HeroTrain",
        ["field"] = {
            [1] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pdamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mdamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pdefence",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mdefence",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxhp",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "HeroSkillItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillbaseid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skilllevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillorgid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "HeroSkill",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.HeroSkillItem",
                ["name"] = "skill"
            }
        }
    },
    [6] = {
        ["name"] = "HeroAvatar",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "avatars",
                ["label"] = "LABEL_REPEATED"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".avatar.AvatarPair",
                ["name"] = "equAvatars"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "attrAvatar",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "activeAvatar",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "tranSkill",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "HeroEvolution",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "evolutions",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_ReqSwitchHero_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "toherothisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_RetSwitchHero_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "curhero",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_NotifyAllHeros_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.Hero",
                ["name"] = "heroinfo"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_NotifyHeroChange_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "changetype",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.Hero",
                ["name"] = "herolist"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_ReqHeroTrain_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "traintimes",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isusewater",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_RetHeroTrain_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.Hero",
                ["name"] = "herocurinfo"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_ReqLockUnlockHero_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "locktype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_RetLockUnlockHero_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "locktype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_ReqLevelupHeroSkill_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillbaseid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skilllevel",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_RetLevelupHeroSkill_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillbaseid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skilllevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillorgid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_notifyRefreshHero_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.Hero",
                ["name"] = "heroinfo"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_ReqRiseStar_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "sourcethisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "costthisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_RetRiseStar_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "sourcethisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "costthisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [21] = {
        ["name"] = "DnaItem",
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
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_DnaBagInfo_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.DnaItem",
                ["name"] = "datas"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNAPage",
                ["name"] = "cur_page"
            }
        }
    },
    [23] = {
        ["name"] = "Hole",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pos",
                ["label"] = "LABEL_OPTIONAL"
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
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNAPage",
                ["name"] = "page"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNASlotType",
                ["name"] = "type"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_DnaPageInfo_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNAPage",
                ["name"] = "page"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.Hole",
                ["name"] = "att_holes"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.Hole",
                ["name"] = "def_holes"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "att_opened_num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "def_opened_num",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [25] = {
        ["name"] = "MSG_ReqPutOnDna_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNAPage",
                ["name"] = "page"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pos",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNASlotType",
                ["name"] = "type"
            }
        }
    },
    [26] = {
        ["name"] = "MSG_ReqPutOffDna_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNAPage",
                ["name"] = "page"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pos",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNASlotType",
                ["name"] = "type"
            }
        }
    },
    [27] = {
        ["name"] = "MSG_ReqCombineDna_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNAPage",
                ["name"] = "page"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pos",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNASlotType",
                ["name"] = "type"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [28] = {
        ["name"] = "MSG_ReqChangeCurDnaPage_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNAPage",
                ["name"] = "page"
            }
        }
    },
    [29] = {
        ["name"] = "MSG_ReqCombineDnaInBag_CS",
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
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [30] = {
        ["name"] = "MSG_ReqBuySlot_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNAPage",
                ["name"] = "page"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNASlotType",
                ["name"] = "type"
            }
        }
    },
    [31] = {
        ["name"] = "MSG_ResponseSlotOpened_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNAPage",
                ["name"] = "page"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".hero.DNASlotType",
                ["name"] = "type"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "cur_num",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [32] = {
        ["name"] = "MSG_AllDnaPageInfo_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.MSG_DnaPageInfo_CSC",
                ["name"] = "pages"
            }
        }
    },
    [33] = {
        ["name"] = "MSG_SetMainHero_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "opcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errorcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [34] = {
        ["name"] = "HeroScore",
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
                ["name"] = "score",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [35] = {
        ["name"] = "MSG_NotifyClientHeroScore_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.HeroScore",
                ["name"] = "scores"
            }
        }
    }
}

----- end of proto -----
