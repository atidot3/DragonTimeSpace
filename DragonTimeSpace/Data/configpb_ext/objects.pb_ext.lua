name = objects.proto

package pb;

message objects {
    repeated t_objects_config datas = 1;    // type_name = .pb.objects.t_objects_config

    message t_objects_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required string name = 3;
        required uint32 type = 4;
        required uint32 subtype = 5;
        required uint32 quality = 6;
        required uint32 level = 7;
        required uint32 uselevel = 8;
        required string icon = 9;
        required string appearance = 10;
        required string small_icon = 11;
        required uint32 maxnum = 12;
        required uint32 lasttype = 13;
        required string lasttime = 14;
        required string desc = 15;
        required string refence_desc = 16;
        required string type_desc = 17;
        required uint32 promptuse = 18;
        required uint32 isusebind = 19;
        required uint32 cdgroup = 20;
        required uint32 cdgrouptime = 21;
        required uint32 cdtime = 22;
        required uint32 sell_price = 23;
        required string state_limit = 24;
        required uint32 treasure = 25;
        required string recommandprice = 26;
        required uint32 isdelete = 27;
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
                ["type_name"] = ".pb.objects.t_objects_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "objects",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_objects_config",
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
                        ["name"] = "type",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "subtype",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "quality",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "level",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "uselevel",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "icon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "appearance",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "small_icon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "maxnum",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [13] = {
                        ["number"] = 13,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "lasttype",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [14] = {
                        ["number"] = 14,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "lasttime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [15] = {
                        ["number"] = 15,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "desc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [16] = {
                        ["number"] = 16,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "refence_desc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [17] = {
                        ["number"] = 17,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "type_desc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [18] = {
                        ["number"] = 18,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "promptuse",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [19] = {
                        ["number"] = 19,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "isusebind",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [20] = {
                        ["number"] = 20,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "cdgroup",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [21] = {
                        ["number"] = 21,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "cdgrouptime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [22] = {
                        ["number"] = 22,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "cdtime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [23] = {
                        ["number"] = 23,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "sell_price",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [24] = {
                        ["number"] = 24,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "state_limit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [25] = {
                        ["number"] = 25,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "treasure",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [26] = {
                        ["number"] = 26,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "recommandprice",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [27] = {
                        ["number"] = 27,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "isdelete",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "objects.proto",
["package"] = "pb"

----- end of proto -----
