name = careerLv.proto

package pb;

message careerLv {
    repeated t_career_lv_config datas = 1;    // type_name = .pb.careerLv.t_career_lv_config

    message t_career_lv_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 level = 2 [default = 0];
        required uint32 proficiency = 3;
        required string careerback = 4;
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
                ["type_name"] = ".pb.careerLv.t_career_lv_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "careerLv",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_career_lv_config",
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
                        ["name"] = "proficiency",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "careerback",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "careerLv.proto",
["package"] = "pb"

----- end of proto -----
