name = heropanel_maximum.proto

package pb;

message heropanel_maximum {
    repeated t_heropanel_maximum datas = 1;    // type_name = .pb.heropanel_maximum.t_heropanel_maximum

    message t_heropanel_maximum {
        required uint32 tbxid = 1 [default = 0];
        required uint32 level = 2 [default = 0];
        required uint32 damagelimit = 3;
        required uint32 pdefencelimit = 4;
        required uint32 mdefencelimit = 5;
        required uint32 lifelimit = 6;
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
                ["type_name"] = ".pb.heropanel_maximum.t_heropanel_maximum",
                ["name"] = "datas"
            }
        },
        ["name"] = "heropanel_maximum",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_heropanel_maximum",
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
                        ["name"] = "level"
                    },
                    [3] = {
                        ["number"] = 3,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "damagelimit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "pdefencelimit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "mdefencelimit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "lifelimit",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "heropanel_maximum.proto",
["package"] = "pb"

----- end of proto -----
