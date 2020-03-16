name = pathway.proto

package pb;

message pathway {
    repeated t_pathway_config datas = 1;    // type_name = .pb.pathway.t_pathway_config

    message t_pathway_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 pathwayid = 2 [default = 0];
        required string name = 3;
        required string coordinates = 4;
        required string mapname = 5;
        required uint32 mapid = 6;
        required uint32 npcid = 7;
        required uint32 propid = 8;
        required uint32 pathwaynull = 9;
        required uint32 iscopymap = 10;
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
                ["type_name"] = ".pb.pathway.t_pathway_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "pathway",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_pathway_config",
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
                        ["name"] = "pathwayid"
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
                        ["name"] = "coordinates",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "mapname",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "mapid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "npcid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "propid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "pathwaynull",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "iscopymap",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "pathway.proto",
["package"] = "pb"

----- end of proto -----
