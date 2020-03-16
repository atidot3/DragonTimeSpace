name = career.proto

package career;

message skillLevelItem {
    optional uint32 career = 1;
    optional uint32 level = 2;
}

message lineSkillItem {
    optional uint32 line = 1;
    optional uint32 skill = 2;
}

message proficiencyItem {
    optional uint32 career = 1;
    optional uint32 proficiency = 2;
}

message careerunlockItem {
    optional SkillData skill = 1;    // type_name = .magic.SkillData
    repeated ExtSkillData extskill = 2;    // type_name = .magic.ExtSkillData
}

message careerCurrentSkill {
    optional uint32 career = 1;
    repeated lineSkillItem item = 2;    // type_name = .career.lineSkillItem
}

message MSG_ReqCareerSkillInfo_CS {
null
}

message MSG_RetCareerSkillInfo_SC {
    optional CareerSkillInfo skillinfo = 1;    // type_name = .career.CareerSkillInfo
}

message CareerSkillInfo {
    repeated careerunlockItem unlockskills = 1;    // type_name = .career.careerunlockItem
    repeated lineSkillItem curskills = 2;    // type_name = .career.lineSkillItem
    optional uint32 curcareer = 3;
}

message MSG_ReqRepalceSkill_CS {
    optional uint32 career = 1;
    optional uint32 lineid = 2;
    optional uint32 newskill = 3;
}

message MSG_RetReplaceSkill_SC {
    optional uint32 errcode = 1;
}

message MSG_ReqUpgradeExtSkill_CS {
    optional uint32 extskillid = 1;
}

message MSG_RetUpgradeExtSkill_SC {
    optional uint32 errcode = 1;
}

message MSG_NoneChantSkill_SC {
    repeated uint32 arrskill = 1;
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "skillLevelItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "career",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "lineSkillItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "line",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skill",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "proficiencyItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "career",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "proficiency",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "careerunlockItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".magic.SkillData",
                ["name"] = "skill"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".magic.ExtSkillData",
                ["name"] = "extskill"
            }
        }
    },
    [5] = {
        ["name"] = "careerCurrentSkill",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "career",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".career.lineSkillItem",
                ["name"] = "item"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_ReqCareerSkillInfo_CS"
    },
    [7] = {
        ["name"] = "MSG_RetCareerSkillInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".career.CareerSkillInfo",
                ["name"] = "skillinfo"
            }
        }
    },
    [8] = {
        ["name"] = "CareerSkillInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".career.careerunlockItem",
                ["name"] = "unlockskills"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".career.lineSkillItem",
                ["name"] = "curskills"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curcareer",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_ReqRepalceSkill_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "career",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lineid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "newskill",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_RetReplaceSkill_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_ReqUpgradeExtSkill_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "extskillid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_RetUpgradeExtSkill_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_NoneChantSkill_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "arrskill",
                ["label"] = "LABEL_REPEATED"
            }
        }
    }
},
["dependency"] = {
    [1] = "magic_msg.proto"
},
["name"] = "career.proto",
["package"] = "career"

----- end of proto -----
