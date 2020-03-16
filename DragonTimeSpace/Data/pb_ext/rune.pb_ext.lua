name = rune.proto

package rune;

message RuneItem {
    optional uint32 uniqid = 1;
    optional uint32 baseid = 2;
    optional uint32 level = 3;
    optional uint32 exp = 4;
    optional uint32 insertcount = 5;
}

message RuneGrooveItem {
    optional uint32 uniqid = 1;
    optional uint32 posid = 2;
}

message RunePageData {
    repeated RuneGrooveItem item = 1;    // type_name = .rune.RuneGrooveItem
    optional uint32 pageid = 2;
    optional string pagename = 3;
    optional uint32 score = 4;
}

message MSG_Req_RuneActiveData_CS {
null
}

message MSG_Ret_RuneActiveData_SC {
    repeated RuneItem runeitems = 1;    // type_name = .rune.RuneItem
}

message MSG_Req_RunePageData_CS {
null
}

message MSG_Ret_RunePageData_SC {
    repeated RunePageData pagedatas = 1;    // type_name = .rune.RunePageData
}

message MSG_Req_ActiveRune_CS {
    optional string thisid = 1;
}

message MSG_Ret_ActiveRune_SC {
    optional RuneItem runeitem = 1;    // type_name = .rune.RuneItem
    optional bool result = 2;
}

message MSG_Req_InsertRune_CS {
    optional uint32 uniqid = 1;
    optional uint32 posid = 2;
    optional uint32 pageid = 3;
}

message MSG_Ret_InsertRune_SC {
    optional RuneGrooveItem pageitem = 1;    // type_name = .rune.RuneGrooveItem
    optional uint32 pageid = 2;
    optional uint32 score = 3;
    optional bool result = 4;
}

message MSG_Req_UnloadRune_CS {
    optional uint32 posid = 1;
    optional uint32 pageid = 2;
}

message MSG_Ret_UnloadRune_SC {
    optional uint32 posid = 1;
    optional uint32 pageid = 2;
    optional uint32 score = 3;
    optional bool result = 4;
}

message MSG_Req_UnloadAllRune_CS {
    optional uint32 pageid = 1;
}

message MSG_Ret_UnloadAllRune_SC {
    optional uint32 pageid = 1;
    optional bool result = 2;
}

message MSG_Req_LevelupRune_CS {
    optional uint32 levelupid = 1;
    repeated uint32 costuniqids = 2;
    repeated string costthisids = 3;
}

message MSG_Ret_LevelupRune_SC {
    optional RuneItem runeitem = 1;    // type_name = .rune.RuneItem
    optional bool result = 2;
}

message MSG_Req_RunePageNameModify_CS {
    optional uint32 pageid = 1;
    optional string pagename = 2;
}

message MSG_Ret_RunePageNameModify_SC {
    optional uint32 pageid = 1;
    optional string pagename = 2;
    optional bool result = 3;
}

message MSG_Req_RuneSwitch_CS {
    optional uint32 pageid = 1;
    optional string herothisid = 2;
}

message MSG_Ret_RuneSwitch_SC {
    optional uint32 errcode = 1;
    optional string herothisid = 2;
    optional uint32 pageid = 3;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "RuneType",
        ["value"] = {
            [1] = {
                ["name"] = "RUNE_TYPE_NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "RUNE_TYPE_CIRCLE",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "RUNE_TYPE_DIAMOND",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "RUNE_TYPE_TRIANGLE",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "RUNE_TYPE_SQUARE",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "RUNE_TYPE_MAX",
                ["number"] = 5
            }
        }
    },
    [2] = {
        ["name"] = "RuneEffect",
        ["value"] = {
            [1] = {
                ["name"] = "RUNE_EFFECT_NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "RUNE_EFFECT_MAXHP",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "RUNE_EFFECT_PDEF",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "RUNE_EFFECT_MDEF",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "RUNE_EFFECT_PDAM",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "RUNE_EFFECT_MDAM",
                ["number"] = 5
            },
            [7] = {
                ["name"] = "RUNE_EFFECT_BANG",
                ["number"] = 6
            },
            [8] = {
                ["name"] = "RUNE_EFFECT_BLOCK",
                ["number"] = 7
            },
            [9] = {
                ["name"] = "RUNE_EFFECT_TOUGHNESS",
                ["number"] = 8
            },
            [10] = {
                ["name"] = "RUNE_EFFECT_PENETRATE",
                ["number"] = 9
            },
            [11] = {
                ["name"] = "RUNE_EFFECT_MAX",
                ["number"] = 10
            }
        }
    },
    [3] = {
        ["name"] = "RuneQuality",
        ["value"] = {
            [1] = {
                ["name"] = "RUNE_QUALITY_NONE",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "RUNE_QUALITY_WHITE",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "RUNE_QUALITY_GREEN",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "RUNE_QUALITY_BLUE",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "RUNE_QUALITY_PURPLE",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "RUNE_QUALITY_MAX",
                ["number"] = 5
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "RuneItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "uniqid",
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
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "exp",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "insertcount",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "RuneGrooveItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "uniqid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "RunePageData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rune.RuneGrooveItem",
                ["name"] = "item"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "pagename",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "score",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Req_RuneActiveData_CS"
    },
    [5] = {
        ["name"] = "MSG_Ret_RuneActiveData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rune.RuneItem",
                ["name"] = "runeitems"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Req_RunePageData_CS"
    },
    [7] = {
        ["name"] = "MSG_Ret_RunePageData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rune.RunePageData",
                ["name"] = "pagedatas"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Req_ActiveRune_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_Ret_ActiveRune_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rune.RuneItem",
                ["name"] = "runeitem"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_Req_InsertRune_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "uniqid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_Ret_InsertRune_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rune.RuneGrooveItem",
                ["name"] = "pageitem"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "score",
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
    [12] = {
        ["name"] = "MSG_Req_UnloadRune_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_Ret_UnloadRune_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "score",
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
    [14] = {
        ["name"] = "MSG_Req_UnloadAllRune_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_Ret_UnloadAllRune_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_Req_LevelupRune_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "levelupid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "costuniqids",
                ["label"] = "LABEL_REPEATED"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "costthisids",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_Ret_LevelupRune_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".rune.RuneItem",
                ["name"] = "runeitem"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_Req_RunePageNameModify_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "pagename",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_Ret_RunePageNameModify_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "pagename",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_Req_RuneSwitch_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_Ret_RuneSwitch_SC",
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
                ["name"] = "herothisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "pageid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "rune.proto",
["package"] = "rune"

----- end of proto -----
