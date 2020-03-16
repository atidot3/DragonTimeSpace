name = guide.proto

package pb;

message guide {
    repeated t_guide datas = 1;    // type_name = .pb.guide.t_guide

    message t_guide {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required uint32 guideid = 3;
        required uint32 triggertype = 4;
        required string condition = 5;
        required string hightlightcomponent = 6;
        required uint32 disappeartype = 7;
        required uint32 width = 8;
        required uint32 hight = 9;
        required string guidetext = 10;
        required string describe = 11;
        required bool needfreezetime = 12;
        required uint32 direction = 13;
        required uint32 trignpc = 14;
        required string trigquest = 15;
        required string triglimit = 16;
        required uint32 iffreeze = 17;
        required uint32 showbuff = 18;
        required uint32 shownpc = 19;
        required string posarrow = 20;
        required string posdialogue = 21;
        required string pospainting = 22;
        required string positionsquare = 23;
        required uint32 lasttime = 24;
        required float steptime = 25;
        required uint32 stateid = 26;
        required uint32 ifbtn = 27;
        required uint32 highlighttype = 28;
        required string UIbond = 29;
        required string UIbonus = 30;
        required string positionbonus = 31;
        required string positionorigin = 32;
        required string UInumber = 33;
        required uint32 enddistance = 34;
        required string zoom = 35;
        required string Uiinitial = 36;
        required uint32 itemid = 37;
        required uint32 avatarid = 38;
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
                ["type_name"] = ".pb.guide.t_guide",
                ["name"] = "datas"
            }
        },
        ["name"] = "guide",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_guide",
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
                        ["name"] = "guideid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "triggertype",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "condition",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "hightlightcomponent",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "disappeartype",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "width",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "hight",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "guidetext",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "describe",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "needfreezetime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [13] = {
                        ["number"] = 13,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "direction",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [14] = {
                        ["number"] = 14,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "trignpc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [15] = {
                        ["number"] = 15,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "trigquest",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [16] = {
                        ["number"] = 16,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "triglimit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [17] = {
                        ["number"] = 17,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "iffreeze",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [18] = {
                        ["number"] = 18,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "showbuff",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [19] = {
                        ["number"] = 19,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "shownpc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [20] = {
                        ["number"] = 20,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "posarrow",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [21] = {
                        ["number"] = 21,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "posdialogue",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [22] = {
                        ["number"] = 22,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "pospainting",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [23] = {
                        ["number"] = 23,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "positionsquare",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [24] = {
                        ["number"] = 24,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "lasttime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [25] = {
                        ["number"] = 25,
                        ["type"] = "TYPE_FLOAT",
                        ["name"] = "steptime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [26] = {
                        ["number"] = 26,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "stateid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [27] = {
                        ["number"] = 27,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "ifbtn",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [28] = {
                        ["number"] = 28,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "highlighttype",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [29] = {
                        ["number"] = 29,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "UIbond",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [30] = {
                        ["number"] = 30,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "UIbonus",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [31] = {
                        ["number"] = 31,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "positionbonus",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [32] = {
                        ["number"] = 32,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "positionorigin",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [33] = {
                        ["number"] = 33,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "UInumber",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [34] = {
                        ["number"] = 34,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "enddistance",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [35] = {
                        ["number"] = 35,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "zoom",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [36] = {
                        ["number"] = 36,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "Uiinitial",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [37] = {
                        ["number"] = 37,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "itemid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [38] = {
                        ["number"] = 38,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "avatarid",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "guide.proto",
["package"] = "pb"

----- end of proto -----
