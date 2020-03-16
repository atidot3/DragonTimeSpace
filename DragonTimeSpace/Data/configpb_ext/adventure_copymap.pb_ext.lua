name = adventure_copymap.proto

package pb;

message adventure_copymap {
    repeated t_adventure_copymap datas = 1;    // type_name = .pb.adventure_copymap.t_adventure_copymap

    message t_adventure_copymap {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required string name = 3;
        required string heros = 4;
        required string copymaps = 5;
        required string icon = 6;
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
                ["type_name"] = ".pb.adventure_copymap.t_adventure_copymap",
                ["name"] = "datas"
            }
        },
        ["name"] = "adventure_copymap",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_adventure_copymap",
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
                        ["name"] = "heros",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "copymaps",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "icon",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "adventure_copymap.proto",
["package"] = "pb"

----- end of proto -----
