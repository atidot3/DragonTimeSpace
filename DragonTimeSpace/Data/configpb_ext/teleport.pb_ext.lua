name = teleport.proto

package pb;

message teleport {
    repeated t_teleport datas = 1;    // type_name = .pb.teleport.t_teleport

    message t_teleport {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required uint32 npcid = 3;
        required string Desc = 4;
        required uint32 mapid = 5;
        required string coordinate = 6;
        required string cost = 7;
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
                ["type_name"] = ".pb.teleport.t_teleport",
                ["name"] = "datas"
            }
        },
        ["name"] = "teleport",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_teleport",
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
                        ["name"] = "npcid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "Desc",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "mapid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "coordinate",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "cost",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "teleport.proto",
["package"] = "pb"

----- end of proto -----
