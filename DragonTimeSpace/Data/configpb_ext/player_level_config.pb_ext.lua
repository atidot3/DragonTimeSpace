name = player_level_config.proto

package pb;

message player_level_config {
    repeated t_player_level_config datas = 1;    // type_name = .pb.player_level_config.t_player_level_config

    message t_player_level_config {
        required uint32 tbxid = 1 [default = 0];
        required uint32 id = 2 [default = 0];
        required uint32 exp = 3;
        required uint32 phy_power_limit = 4;
        required uint32 hero_bag_limit = 5;
        required uint32 leadership_limit = 6;
        required uint32 buddy_limit = 7;
        required uint32 phy_power_award = 8;
        required uint32 item_bag_limit = 9;
        required uint32 fairy_air_limit = 10;
        required uint32 morale = 11;
        required uint32 equip_bag_limit = 12;
        required uint32 buy_silver = 13;
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
                ["type_name"] = ".pb.player_level_config.t_player_level_config",
                ["name"] = "datas"
            }
        },
        ["name"] = "player_level_config",
        ["nested_type"] = {
            [1] = {
                ["name"] = "t_player_level_config",
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
                        ["name"] = "exp",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [4] = {
                        ["number"] = 4,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "phy_power_limit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [5] = {
                        ["number"] = 5,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "hero_bag_limit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [6] = {
                        ["number"] = 6,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "leadership_limit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [7] = {
                        ["number"] = 7,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "buddy_limit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [8] = {
                        ["number"] = 8,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "phy_power_award",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [9] = {
                        ["number"] = 9,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "item_bag_limit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [10] = {
                        ["number"] = 10,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "fairy_air_limit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [11] = {
                        ["number"] = 11,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "morale",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [12] = {
                        ["number"] = 12,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "equip_bag_limit",
                        ["label"] = "LABEL_REQUIRED"
                    },
                    [13] = {
                        ["number"] = 13,
                        ["type"] = "TYPE_UINT32",
                        ["name"] = "buy_silver",
                        ["label"] = "LABEL_REQUIRED"
                    }
                }
            }
        }
    }
},
["name"] = "player_level_config.proto",
["package"] = "pb"

----- end of proto -----
