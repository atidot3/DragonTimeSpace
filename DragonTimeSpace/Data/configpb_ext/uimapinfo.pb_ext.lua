name = uimapinfo.proto

package pb;

message uimapinfo {
    repeated t_uimapinfo datas = 1;    // type_name = .pb.uimapinfo.t_uimapinfo

    message t_uimapinfo {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required string IconName = 3;
        required string Nickname = 4;
        required uint32 PathWayId = 5;
        required uint32 Order = 6;
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
                ["type_name"] = ".pb.uimapinfo.t_uimapinfo",
                ["name"] = "datas"
            }
        },
        ["name"] = "uimapinfo",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_uimapinfo",
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
                        ["name"] = "IconName",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "Nickname",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "PathWayId",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "Order",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "uimapinfo.proto",
["package"] = "pb"

----- end of proto -----
