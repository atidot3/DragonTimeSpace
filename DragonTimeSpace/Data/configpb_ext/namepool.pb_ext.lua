name = namepool.proto

package pb;

message namepool {
    repeated t_namepool_config datas = 1;    // type_name = .pb.namepool.t_namepool_config

    message t_namepool_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required string firstname = 3;
        required string enmalename = 4;
        required string enfemalename = 5;
        required string cnmalename = 6;
        required string cnfemalename = 7;
        required string adjective = 8;
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
                ["type_name"] = ".pb.namepool.t_namepool_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "namepool",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_namepool_config",
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
                        ["name"] = "firstname",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "enmalename",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "enfemalename",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "cnmalename",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "cnfemalename",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "adjective",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "namepool.proto",
["package"] = "pb"

----- end of proto -----
