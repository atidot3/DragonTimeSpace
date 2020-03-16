name = relation.proto

package relation;

message relation_item {
    optional uint64 relationid = 1;
    optional string relationname = 2;
    optional uint32 level = 3;
    optional uint32 career = 4;
    optional uint32 type = 5;
    optional uint32 status = 6;
    optional uint32 love_degree = 7;
    optional uint32 lastchattime = 8;
    optional string page = 9;
    optional string nickName = 10;
    optional uint32 offlineTime = 11;
    optional uint32 headPic = 12;
    optional uint32 viplevel = 13;
    optional uint32 power = 14;
    optional uint32 friendrate = 15;
    optional uint32 createTime = 16;
}

message MSG_Ret_RelationList_SC {
    repeated relation_item relations = 1;    // type_name = .relation.relation_item
    optional uint32 type = 2;
}

message MSG_Ret_RefreshRelation_SC {
    optional relation_item data = 1;    // type_name = .relation.relation_item
}

message MSG_Req_ApplyRelation_CS {
    optional uint64 relationid = 1;
}

message MSG_Req_AnswerApplyRelation_CS {
    optional uint64 relationid = 1;
    optional uint32 type = 2;
}

message MSG_Ret_AnswerApplyRelation_SC {
    optional uint64 relationid = 1;
    optional bool issucc = 2;
}

message MSG_Req_DeleteRelation_CS {
    optional uint64 relationid = 1;
}

message MSG_Ret_DeleteRelation_SC {
    optional uint64 relationid = 1;
    optional bool issucc = 2;
}

message MSG_Req_OfflineInteractive_CS {
null
}

message MSG_Ret_AddInteractive_SC {
    repeated relation_item data = 1;    // type_name = .relation.relation_item
}

message MSG_Req_SearchRelation_CS {
    optional string condition = 1;
}

message MSG_Ret_SearchRelation_SC {
    optional relation_item relation = 1;    // type_name = .relation.relation_item
}

message MSG_ModifyPageName_CSC {
    optional string page = 1;
    optional string new_page = 2;
    optional uint32 opcode = 3;
    optional bool success = 4;
}

message MSG_MoveFriendToPage_CSC {
    optional uint64 charid = 1;
    optional string page = 2;
    optional bool success = 3;
}

message PageItem {
    optional string page_name = 1;
    optional uint32 createtime = 2;
}

message MSG_AllFriendPage_CSC {
    repeated PageItem pages = 1;    // type_name = .relation.PageItem
}

message BlackItem {
    optional uint64 charid = 1;
    optional string name = 2;
    optional uint32 level = 3;
    optional uint32 viplevel = 4;
}

message MSG_BlackList_CSC {
    repeated BlackItem blackList = 1;    // type_name = .relation.BlackItem
}

message MSG_OperateBlackList_CSC {
    optional uint64 charid = 1;
    optional uint32 opcode = 2;
    optional BlackItem data = 3;    // type_name = .relation.BlackItem
    optional bool success = 4;
}

message MSG_ChangeNickName_CSC {
    optional uint64 charid = 1;
    optional string nickname = 2;
    optional bool success = 3;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "RelationType",
        ["value"] = {
            [1] = {
                ["name"] = "RELATION_STRANGER",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "RELATION_FRIEND",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "RELATION_APPLY",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "RELATION_BE_APPLY",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "RELATION_BOTH_APPLY",
                ["number"] = 4
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "relation_item",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "relationid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "relationname",
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
                ["name"] = "career",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "status",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "love_degree",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "lastchattime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_STRING",
                ["name"] = "page",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_STRING",
                ["name"] = "nickName",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_UINT32",
                ["name"] = "offlineTime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_UINT32",
                ["name"] = "headPic",
                ["label"] = "LABEL_OPTIONAL"
            },
            [13] = {
                ["number"] = 13,
                ["type"] = "TYPE_UINT32",
                ["name"] = "viplevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [14] = {
                ["number"] = 14,
                ["type"] = "TYPE_UINT32",
                ["name"] = "power",
                ["label"] = "LABEL_OPTIONAL"
            },
            [15] = {
                ["number"] = 15,
                ["type"] = "TYPE_UINT32",
                ["name"] = "friendrate",
                ["label"] = "LABEL_OPTIONAL"
            },
            [16] = {
                ["number"] = 16,
                ["type"] = "TYPE_UINT32",
                ["name"] = "createTime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Ret_RelationList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".relation.relation_item",
                ["name"] = "relations"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_Ret_RefreshRelation_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".relation.relation_item",
                ["name"] = "data"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Req_ApplyRelation_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "relationid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_Req_AnswerApplyRelation_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "relationid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "type",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Ret_AnswerApplyRelation_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "relationid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "issucc",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_Req_DeleteRelation_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "relationid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Ret_DeleteRelation_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "relationid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "issucc",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_Req_OfflineInteractive_CS"
    },
    [10] = {
        ["name"] = "MSG_Ret_AddInteractive_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".relation.relation_item",
                ["name"] = "data"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_Req_SearchRelation_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "condition",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_Ret_SearchRelation_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".relation.relation_item",
                ["name"] = "relation"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_ModifyPageName_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "page",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "new_page",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "opcode",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_BOOL",
                ["name"] = "success",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_MoveFriendToPage_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "page",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "success",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "PageItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "page_name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "createtime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_AllFriendPage_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".relation.PageItem",
                ["name"] = "pages"
            }
        }
    },
    [17] = {
        ["name"] = "BlackItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
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
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "viplevel",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_BlackList_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".relation.BlackItem",
                ["name"] = "blackList"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_OperateBlackList_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
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
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".relation.BlackItem",
                ["name"] = "data"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_BOOL",
                ["name"] = "success",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_ChangeNickName_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "nickname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "success",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "relation.proto",
["package"] = "relation"

----- end of proto -----
