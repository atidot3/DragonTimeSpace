name = dnaslot_config.proto

package pb;

message dnaslot_config {
    repeated t_dnaslot_config datas = 1;    // type_name = .pb.dnaslot_config.t_dnaslot_config

    message t_dnaslot_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 level = 2 [default = 0];
        required uint32 attslotpage1 = 3;
        required uint32 defslotpage1 = 4;
        required uint32 attslotpage2 = 5;
        required uint32 defslotpage2 = 6;
        required uint32 attslotpage3 = 7;
        required uint32 defslotpage3 = 8;
        required uint32 attslotpage4 = 9;
        required uint32 defslotpage4 = 10;
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
                ["type_name"] = ".pb.dnaslot_config.t_dnaslot_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "dnaslot_config",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_dnaslot_config",
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
                        ["name"] = "attslotpage1",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "defslotpage1",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "attslotpage2",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "defslotpage2",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "attslotpage3",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "defslotpage3",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "attslotpage4",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "defslotpage4",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "dnaslot_config.proto",
["package"] = "pb"

----- end of proto -----
