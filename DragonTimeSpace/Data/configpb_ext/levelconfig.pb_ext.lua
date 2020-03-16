name = levelconfig.proto

package pb;

message levelconfig {
    repeated t_level_config datas = 1;    // type_name = .pb.levelconfig.t_level_config

    message t_level_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 level = 2 [default = 0];
        required uint32 levelupexp = 3;
        required uint32 del_protect_time = 4;
        required string unlockskill = 5;
        required uint32 guild_levelup_exp = 6;
        required uint32 guild_levelup_salary = 7;
        required string guild_daily_rewards = 8;
        required string guild_daily_leader_rewards = 9;
        required uint32 guild_daily_maintain_fund = 10;
        required uint32 guild_member_limit = 11;
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
                ["type_name"] = ".pb.levelconfig.t_level_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "levelconfig",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_level_config",
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
                        ["name"] = "levelupexp",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "del_protect_time",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "unlockskill",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "guild_levelup_exp",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "guild_levelup_salary",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "guild_daily_rewards",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "guild_daily_leader_rewards",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "guild_daily_maintain_fund",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "guild_member_limit",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "levelconfig.proto",
["package"] = "pb"

----- end of proto -----
