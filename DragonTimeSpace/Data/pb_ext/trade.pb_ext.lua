name = trade.proto

package trade;

message MSG_ReqSellStaff_CS {
    required SELLTYPE itemtype = 1;    // type_name = .msg.SELLTYPE
    optional string thisid = 2;
    optional uint32 baseid = 3;
    optional uint32 price = 4;
    optional uint32 num = 5;
}

message MSG_RetSellStaff_SC {
    optional uint32 retcode = 1;
}

message TradeItemData {
    required SELLTYPE itemtype = 1;    // type_name = .msg.SELLTYPE
    optional t_Object objdata = 2;    // type_name = .Obj.t_Object
    optional Hero herodata = 3;    // type_name = .hero.Hero
}

message TradeItem {
    optional string thisid = 1;
    optional uint32 price = 2;
    optional uint32 selltime = 3;
    optional TradeItemData data = 4;    // type_name = .trade.TradeItemData
    optional bool isshow = 5;
}

message MSG_ReqSellingStaff_CS {
null
}

message MSG_RetSellingStaff_SC {
    repeated TradeItem itemlist = 1;    // type_name = .trade.TradeItem
}

message MSG_ReqRecommandPrice_CS {
    required SELLTYPE itemtype = 1;    // type_name = .msg.SELLTYPE
    optional uint32 baseid = 2;
}

message MSG_RetRecommandPrice_SC {
    required SELLTYPE itemtype = 1;    // type_name = .msg.SELLTYPE
    optional uint32 baseid = 2;
    optional uint32 price = 3;
}

message MSG_ReqStopSellStaff_CS {
    optional string thisid = 1;
}

message MSG_RetStopSellStaff_SC {
    optional uint32 retcode = 1;
}

message MSG_ReqSubSellingList_CS {
    required SELLTYPE itemtype = 1;    // type_name = .msg.SELLTYPE
    optional uint32 levelstar = 2;
    repeated uint32 idlist = 3;
    optional bool checkshow = 4;
}

message MSG_RetSubSellingList_SC {
    optional uint32 totalpage = 1;
}

message MSG_ReqBuyItem_CS {
    required SELLTYPE itemtype = 1;    // type_name = .msg.SELLTYPE
    optional uint32 baseid = 2;
    optional uint32 levelstar = 3;
    optional uint32 num = 4;
    optional string thisid = 5;
}

message MSG_RetBuyItem_SC {
    optional uint32 retcode = 1;
}

message MSG_ReqTradeItemHistory_CS {
    required SELLTYPE itemtype = 1;    // type_name = .msg.SELLTYPE
    optional uint32 baseid = 2;
}

message TradeHistoryItem {
    optional TradeItemData data = 1;    // type_name = .trade.TradeItemData
    optional uint32 price = 2;
    optional uint32 tradetime = 3;
}

message MSG_RetTradeItemHistory_SC {
    repeated TradeHistoryItem item = 1;    // type_name = .trade.TradeHistoryItem
}

message MSG_ReqSublistPage_CS {
    optional uint32 page = 1;
}

message MSG_RetSublistPage_SC {
    repeated TradeItem item = 1;    // type_name = .trade.TradeItem
}

message MSG_ReqWatchTradeItem_CS {
    optional string thisid = 1;
    optional bool ison = 2;
    optional bool isshow = 3;
}

message MSG_RetWatchTradeItem_SC {
    optional uint32 retcode = 1;
    optional string thisid = 2;
    optional bool ison = 3;
    optional bool isshow = 4;
}

message MSG_ReqWatchList_CS {
    optional bool isshow = 1;
}

message MSG_RetWatchList_SC {
    optional bool isshow = 1;
    repeated TradeItem item = 2;    // type_name = .trade.TradeItem
}

message MSG_ReqUserTradeHistory_CS {
null
}

message UserTradeItem {
    optional TradeOP op = 1;    // type_name = .trade.TradeOP
    optional TradeHistoryItem item = 2;    // type_name = .trade.TradeHistoryItem
    optional uint32 judgeduetime = 3;
}

message MSG_RetUserTradeHistory_SC {
    repeated UserTradeItem one = 1;    // type_name = .trade.UserTradeItem
}

message MSG_ReqGetNewestStaff_CS {
null
}

message MSG_RetGetNewestStaff_SC {
    repeated TradeItem itemlist = 1;    // type_name = .trade.TradeItem
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "TradeOP",
        ["value"] = {
            [1] = {
                ["name"] = "SELL",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "BUY",
                ["number"] = 2
            }
        }
    }
},
["package"] = "trade",
["name"] = "trade.proto",
["dependency"] = {
    [1] = "msg_enum.proto",
    [2] = "object.proto",
    [3] = "hero.proto"
},
["message_type"] = {
    [1] = {
        ["name"] = "MSG_ReqSellStaff_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.SELLTYPE",
                ["name"] = "itemtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "baseid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "price",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_RetSellStaff_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "TradeItemData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.SELLTYPE",
                ["name"] = "itemtype"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.t_Object",
                ["name"] = "objdata"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.Hero",
                ["name"] = "herodata"
            }
        }
    },
    [4] = {
        ["name"] = "TradeItem",
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
                ["name"] = "price",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "selltime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".trade.TradeItemData",
                ["name"] = "data"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isshow",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_ReqSellingStaff_CS"
    },
    [6] = {
        ["name"] = "MSG_RetSellingStaff_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".trade.TradeItem",
                ["name"] = "itemlist"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_ReqRecommandPrice_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.SELLTYPE",
                ["name"] = "itemtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "baseid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_RetRecommandPrice_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.SELLTYPE",
                ["name"] = "itemtype"
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
                ["name"] = "price",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_ReqStopSellStaff_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_RetStopSellStaff_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_ReqSubSellingList_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.SELLTYPE",
                ["name"] = "itemtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "levelstar",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "idlist",
                ["label"] = "LABEL_REPEATED"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_BOOL",
                ["name"] = "checkshow",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_RetSubSellingList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "totalpage",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_ReqBuyItem_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.SELLTYPE",
                ["name"] = "itemtype"
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
                ["name"] = "levelstar",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_RetBuyItem_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [15] = {
        ["name"] = "MSG_ReqTradeItemHistory_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REQUIRED",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".msg.SELLTYPE",
                ["name"] = "itemtype"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "baseid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "TradeHistoryItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".trade.TradeItemData",
                ["name"] = "data"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "price",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "tradetime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [17] = {
        ["name"] = "MSG_RetTradeItemHistory_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".trade.TradeHistoryItem",
                ["name"] = "item"
            }
        }
    },
    [18] = {
        ["name"] = "MSG_ReqSublistPage_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "page",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [19] = {
        ["name"] = "MSG_RetSublistPage_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".trade.TradeItem",
                ["name"] = "item"
            }
        }
    },
    [20] = {
        ["name"] = "MSG_ReqWatchTradeItem_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "ison",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isshow",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [21] = {
        ["name"] = "MSG_RetWatchTradeItem_SC",
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
                ["name"] = "thisid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_BOOL",
                ["name"] = "ison",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isshow",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [22] = {
        ["name"] = "MSG_ReqWatchList_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isshow",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [23] = {
        ["name"] = "MSG_RetWatchList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "isshow",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".trade.TradeItem",
                ["name"] = "item"
            }
        }
    },
    [24] = {
        ["name"] = "MSG_ReqUserTradeHistory_CS"
    },
    [25] = {
        ["name"] = "UserTradeItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".trade.TradeOP",
                ["name"] = "op"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".trade.TradeHistoryItem",
                ["name"] = "item"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "judgeduetime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [26] = {
        ["name"] = "MSG_RetUserTradeHistory_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".trade.UserTradeItem",
                ["name"] = "one"
            }
        }
    },
    [27] = {
        ["name"] = "MSG_ReqGetNewestStaff_CS"
    },
    [28] = {
        ["name"] = "MSG_RetGetNewestStaff_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".trade.TradeItem",
                ["name"] = "itemlist"
            }
        }
    }
}

----- end of proto -----
