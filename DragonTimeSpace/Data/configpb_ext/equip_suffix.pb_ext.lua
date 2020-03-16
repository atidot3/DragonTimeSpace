name = equip_suffix.proto

package pb;

message equip_suffix {
    repeated t_equips_suffix datas = 1;    // type_name = .pb.equip_suffix.t_equips_suffix

    message t_equips_suffix {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required string name = 3;
        required string property_explain = 4;
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
                ["type_name"] = ".pb.equip_suffix.t_equips_suffix",
                ["name"] = "datas"
            }
        },
        ["name"] = "equip_suffix",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_equips_suffix",
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
                        ["name"] = "property_explain",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "equip_suffix.proto",
["package"] = "pb"

----- end of proto -----
