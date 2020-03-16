name = copymapinfo.proto

package pb;

message copymapinfo {
    repeated t_copymap datas = 1;    // type_name = .pb.copymapinfo.t_copymap

    message t_copymap {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required uint32 mapid = 3;
        required string TaskID = 4;
        required string copyblock = 5;
        required string mappath = 6;
        required uint32 showinvite = 7;
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
                ["type_name"] = ".pb.copymapinfo.t_copymap",
                ["name"] = "datas"
            }
        },
        ["name"] = "copymapinfo",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_copymap",
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
                        ["name"] = "mapid",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "TaskID",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "copyblock",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "mappath",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "showinvite",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "copymapinfo.proto",
["package"] = "pb"

----- end of proto -----
