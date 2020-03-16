name = screensetting.proto

package pb;

message screensetting {
    repeated t_screensetting_config datas = 1;    // type_name = .pb.screensetting.t_screensetting_config

    message t_screensetting_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required uint32 type = 3;
        required bool floodlight = 4;
        required bool shadow = 5;
        required bool dop = 6;
        required bool halo = 7;
        required bool antialiasing = 8;
        required uint32 sceneobjpriority = 9;
        required bool sceneeffect = 10;
        required bool uiclosescene = 11;
        required uint32 cameradis = 12;
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
                ["type_name"] = ".pb.screensetting.t_screensetting_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "screensetting",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_screensetting_config",
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
                        ["name"] = "type",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "floodlight",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "shadow",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "dop",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "halo",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "antialiasing",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "sceneobjpriority",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "sceneeffect",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "uiclosescene",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "cameradis",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "screensetting.proto",
["package"] = "pb"

----- end of proto -----
