name = reward_level.proto

package pb;

message reward_level {
    repeated t_reward_level datas = 1;    // type_name = .pb.reward_level.t_reward_level

    message t_reward_level {
        required uint32 tbxid = 1 [default = 0];
        required uint32 level = 2 [default = 0];
        required string rewards = 3;
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
                ["type_name"] = ".pb.reward_level.t_reward_level",
                ["name"] = "datas"
            }
        },
        ["name"] = "reward_level",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_reward_level",
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
                        ["type"] = "TYPE_STRING",
                        ["name"] = "rewards",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "reward_level.proto",
["package"] = "pb"

----- end of proto -----
