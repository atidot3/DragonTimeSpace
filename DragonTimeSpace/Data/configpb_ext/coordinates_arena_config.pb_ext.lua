name = coordinates_arena_config.proto

package pb;

message coordinates_arena_config {
    repeated t_coordinates_arena_config datas = 1;    // type_name = .pb.coordinates_arena_config.t_coordinates_arena_config

    message t_coordinates_arena_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required uint32 coordinatetype = 3;
        required uint32 coordinatex = 4;
        required uint32 coordinatey = 5;
        required uint32 radius = 6;
        required uint32 transgroup = 7;
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
                ["type_name"] = ".pb.coordinates_arena_config.t_coordinates_arena_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "coordinates_arena_config",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_coordinates_arena_config",
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
                        ["name"] = "coordinatetype",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "coordinatex",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "coordinatey",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "radius",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "transgroup",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "coordinates_arena_config.proto",
["package"] = "pb"

----- end of proto -----
