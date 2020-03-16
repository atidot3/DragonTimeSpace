name = pet.proto

package Pet;

message PropItem {
    optional uint32 pdamage = 1;
    optional uint32 pdefence = 2;
    optional uint32 maxhp = 3;
    optional uint32 toughness = 4;
    optional uint32 bang = 5;
    optional uint32 accurate = 6;
    optional uint32 hold = 7;
    optional uint32 hit = 8;
    optional uint32 miss = 9;
}

message PetBase {
    optional uint32 id = 1;
    optional string name = 2;
    optional uint64 tempid = 3;
    optional uint32 level = 4;
    optional uint32 exp = 5;
    optional uint32 hp = 6;
    optional uint32 quality = 7 [default = 0];
    optional PropItem prop = 8;    // type_name = .Pet.PropItem
    optional PropItem aptitude = 9;    // type_name = .Pet.PropItem
    repeated PetState state = 10;    // type_name = .Pet.PetState
    optional uint32 passivenum = 11;
    optional uint32 activeskillid = 12;
    optional uint32 talentskillid = 13;
}

message MSG_ReqSwitchPetState_CS {
    optional uint64 tempid = 1;
    optional PetState fromstate = 2;    // type_name = .Pet.PetState
    optional PetState tostate = 3;    // type_name = .Pet.PetState
}

message MSG_RetSwitchPetState_SC {
    optional uint32 errcode = 1;
    optional uint32 tempid = 2;
    repeated PetState curstate = 3;    // type_name = .Pet.PetState
}

message MSG_RetRefreshSummonPet_SC {
    repeated PetBase pet = 1;    // type_name = .Pet.PetBase
}

message MSG_RetUserPetInfo_SC {
    optional SummonPetUseInfo info = 1;    // type_name = .Pet.SummonPetUseInfo
}

message SummonPetUseInfo {
    optional uint32 num = 1;
    optional uint64 curpet = 2;
    repeated PetBase petlist = 3;    // type_name = .Pet.PetBase
    optional uint32 unlockcount = 4;
    optional uint64 curassist = 5;
}

message MSG_NotifyPetQTESkill_SC {
    optional uint32 onoff = 1;
    optional uint64 bosstempid = 2;
    optional uint32 leftlasttime = 3;
    optional uint32 totallasttime = 4;
    optional uint32 distancetomaster = 5;
    optional uint32 distanceratio = 6;
}

message MSG_ReqUnlockPetNum_CS {
    optional uint32 unlockcount = 1;
}

message MSG_RetUnlockPetNum_SC {
    optional uint32 retcode = 1;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "PetProp",
        ["value"] = {
            [1] = {
                ["name"] = "PDAM",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "PDEF",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "MAXHP",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "BANG",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "TOUGHNESS",
                ["number"] = 5
            },
            [6] = {
                ["name"] = "ACCURATE",
                ["number"] = 6
            },
            [7] = {
                ["name"] = "HOLD",
                ["number"] = 7
            },
            [8] = {
                ["name"] = "HIT",
                ["number"] = 8
            },
            [9] = {
                ["name"] = "MISS",
                ["number"] = 9
            }
        }
    },
    [2] = {
        ["name"] = "PetState",
        ["value"] = {
            [1] = {
                ["name"] = "PetState_None",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "PetState_Rest",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "PetState_Assist",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "PetState_Fight",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "PetState_Dying",
                ["number"] = 4
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "PropItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pdamage",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pdefence",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxhp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "toughness",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bang",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "accurate",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hold",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hit",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "miss",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "PetBase",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
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
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
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
                ["type"] = "TYPE_UINT32",
                ["name"] = "exp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "hp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["default_value"] = "0",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_UINT32",
                ["name"] = "quality"
            },
            [8] = {
                ["number"] = 8,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Pet.PropItem",
                ["name"] = "prop"
            },
            [9] = {
                ["number"] = 9,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Pet.PropItem",
                ["name"] = "aptitude"
            },
            [10] = {
                ["number"] = 10,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Pet.PetState",
                ["name"] = "state"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "passivenum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT32",
                ["name"] = "activeskillid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 13,
                ["type"] = "TYPE_UINT32",
                ["name"] = "talentskillid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_ReqSwitchPetState_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Pet.PetState",
                ["name"] = "fromstate"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Pet.PetState",
                ["name"] = "tostate"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_RetSwitchPetState_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "tempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Pet.PetState",
                ["name"] = "curstate"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_RetRefreshSummonPet_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Pet.PetBase",
                ["name"] = "pet"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_RetUserPetInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Pet.SummonPetUseInfo",
                ["name"] = "info"
            }
        }
    },
    [7] = {
        ["name"] = "SummonPetUseInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "curpet",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Pet.PetBase",
                ["name"] = "petlist"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "unlockcount",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT64",
                ["name"] = "curassist",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_NotifyPetQTESkill_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "onoff",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "bosstempid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "leftlasttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "totallasttime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "distancetomaster",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "distanceratio",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_ReqUnlockPetNum_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "unlockcount",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_RetUnlockPetNum_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "pet.proto",
["package"] = "Pet"

----- end of proto -----
