name = rankpk_level.proto

package pb;

message rankpk_level {
    repeated t_rankpk_level datas = 1;    // type_name = .pb.rankpk_level.t_rankpk_level

    message t_rankpk_level {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required string name = 3;
        required uint32 max_star = 4;
        required string icon = 5;
        required string icon_small = 6;
        required string rank_awards = 7;
        required string histroy_rank_reward = 8;
        required uint32 continue_win_reward_star = 9;
        required string season_reward = 10;
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
                ["type_name"] = ".pb.rankpk_level.t_rankpk_level",
                ["name"] = "datas"
            }
        },
        ["name"] = "rankpk_level",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_rankpk_level",
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
                        ["name"] = "max_star",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "icon",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "icon_small",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "rank_awards",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "histroy_rank_reward",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "continue_win_reward_star",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_STRING",
                        ["name"] = "season_reward",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "rankpk_level.proto",
["package"] = "pb"

----- end of proto -----
