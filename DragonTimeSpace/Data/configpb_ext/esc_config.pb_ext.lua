name = esc_config.proto

package pb;

message esc_config {
    repeated t_esc_config datas = 1;    // type_name = .pb.esc_config.t_esc_config

    message t_esc_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required string name = 3;
        required string template = 4;
        required uint32 open = 5;
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
                ["type_name"] = ".pb.esc_config.t_esc_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "esc_config",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_esc_config",
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
                        ["type"] = "TYPE_STRING",
                        ["name"] = "template",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "open",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "esc_config.proto",
["package"] = "pb"

----- end of proto -----
