name = devicesetting.proto

package pb;

message devicesetting {
    repeated t_devicesetting_config datas = 1;    // type_name = .pb.devicesetting.t_devicesetting_config

    message t_devicesetting_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required string name = 3;
        required uint32 type = 4;
        required bool floodlight = 5;
        required bool shadow = 6;
        required bool dop = 7;
        required bool halo = 8;
        required bool antialiasing = 9;
        required uint32 sceneobjpriority = 10;
        required bool sceneeffect = 11;
        required bool uiclosescene = 12;
        required uint32 cameradis = 13;
        required uint32 maxtype = 14;
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
                ["type_name"] = ".pb.devicesetting.t_devicesetting_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "devicesetting",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_devicesetting_config",
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
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "floodlight",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "shadow",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "dop",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "halo",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "antialiasing",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "sceneobjpriority",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "sceneeffect",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_BOOL",
                        ["name"] = "uiclosescene",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [13] = {
                        ["number"] = 13,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "cameradis",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [14] = {
                        ["number"] = 14,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "maxtype",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "devicesetting.proto",
["package"] = "pb"

----- end of proto -----
