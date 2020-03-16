name = market.proto

package market;

message Item {
    optional uint32 id = 1;
    optional uint32 itemid = 2;
    optional uint32 discount = 3;
    optional uint32 curnum = 4;
    optional uint32 maxnum = 5;
    optional uint32 costid = 6;
    optional uint32 costnum = 7;
    optional uint32 bind = 8;
    optional uint32 skillid = 9;
    optional uint32 skilllv = 10;
}

message OneMarket {
    optional uint32 id = 1;
    optional MarketType type = 2;    // type_name = .market.MarketType
    repeated Item itemlist = 3;    // type_name = .market.Item
    optional uint32 refreshtype = 4;
    optional string refreshtime = 5;
    optional uint32 subtype = 6;
}

message MSG_ReqMarketItemList_CS {
    repeated uint32 marketid = 1;
}

message MSG_RetMarketItemList_SC {
    repeated OneMarket marketdetail = 1;    // type_name = .market.OneMarket
    optional uint32 guildskilllv = 2;
}

message MSG_ReqBuyMarketItem_CS {
    optional uint32 marketid = 1;
    optional uint32 id = 2;
    optional uint32 itemid = 3;
    optional uint32 itemnum = 4;
}

message MSG_RetBuyMarketItem_SC {
    optional uint32 errcode = 1;
}

message SelledItem {
    optional t_Object item = 1;    // type_name = .Obj.t_Object
    optional uint32 selltime = 2;
}

message MSG_UserSelledItemList_CSC {
    repeated SelledItem objs = 1;    // type_name = .market.SelledItem
}

message MSG_ReqBuySelledItem_CS {
    optional uint32 index = 1;
}

message MSG_RetBuySelledItem_SC {
    optional uint32 retcode = 1;
}

message MSG_ReqSellItem_CS {
    optional string thisid = 1;
}

message MSG_RetSellItem_SC {
    optional uint32 retcode = 1;
}

message MSG_ExchangeRatio_CSC {
    optional uint32 tone2nations = 1;
}

message MSG_RefreshMarketItem_SC {
    optional uint32 marketid = 1;
    optional uint32 id = 2;
    optional uint32 itemid = 3;
    optional uint32 curnum = 4;
    optional uint32 maxnum = 5;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "MarketType",
        ["value"] = {
            [1] = {
                ["name"] = "MarketType_1",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "MarketType_2",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "MarketType_3",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "MarketType_4",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "MarketType_5",
                ["number"] = 5
            },
            [6] = {
                ["name"] = "MarketType_6",
                ["number"] = 6
            },
            [7] = {
                ["name"] = "MarketType_7",
                ["number"] = 7
            }
        }
    }
},
["package"] = "market",
["name"] = "market.proto",
["dependency"] = {
    [1] = "object.proto"
},
["message_type"] = {
    [1] = {
        ["name"] = "Item",
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
                ["name"] = "itemid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "discount",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "costid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_UINT32",
                ["name"] = "costnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "bind",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skillid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_UINT32",
                ["name"] = "skilllv",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "OneMarket",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".market.MarketType",
                ["name"] = "type"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".market.Item",
                ["name"] = "itemlist"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "refreshtype",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "refreshtime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "subtype",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_ReqMarketItemList_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "marketid",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_RetMarketItemList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".market.OneMarket",
                ["name"] = "marketdetail"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "guildskilllv",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_ReqBuyMarketItem_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "marketid",
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
                ["name"] = "itemid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "itemnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_RetBuyMarketItem_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "SelledItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.t_Object",
                ["name"] = "item"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "selltime",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_UserSelledItemList_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".market.SelledItem",
                ["name"] = "objs"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_ReqBuySelledItem_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "index",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_RetBuySelledItem_SC",
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
        ["name"] = "MSG_ReqSellItem_CS",
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
        ["name"] = "MSG_RetSellItem_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_ExchangeRatio_CSC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "tone2nations",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [14] = {
        ["name"] = "MSG_RefreshMarketItem_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "marketid",
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
                ["name"] = "itemid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "maxnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
}

----- end of proto -----
