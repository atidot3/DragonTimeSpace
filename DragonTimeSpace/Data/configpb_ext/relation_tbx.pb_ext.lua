name = relation_tbx.proto

package pb;

message relation_tbx {
    repeated t_relation datas = 1;    // type_name = .pb.relation_tbx.t_relation

    message t_relation {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required uint32 valuetype = 3;
        required uint32 addvalue = 4;
        required uint32 subvalue = 5;
        required uint32 daytimes = 6;
        required uint32 lasttime = 7;
        required string rangelimit = 8;
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
                ["type_name"] = ".pb.relation_tbx.t_relation",
                ["name"] = "datas"
            }
        },
        ["name"] = "relation_tbx",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_relation",
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
                        ["name"] = "valuetype",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "addvalue",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "subvalue",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "daytimes",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "lasttime",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "rangelimit",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "relation_tbx.proto",
["package"] = "pb"

----- end of proto -----
