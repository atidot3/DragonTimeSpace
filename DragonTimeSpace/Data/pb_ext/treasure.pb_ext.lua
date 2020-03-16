name = treasure.proto

package treasure;

message PosData {
    optional uint32 posx = 1;
    optional uint32 posy = 2;
    optional uint32 mapid = 3;
}

message MSG_Ret_TreasurePos_SC {
    optional PosData posdata = 1;    // type_name = .treasure.PosData
}

message MSG_ReqChangeMapHuntTreasure_CS {
    optional PosData posdata = 1;    // type_name = .treasure.PosData
}

message MSG_RetChangeMapHuntTreasure_SC {
    optional uint32 retcode = 1;
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "PosData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posx",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "posy",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "mapid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Ret_TreasurePos_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".treasure.PosData",
                ["name"] = "posdata"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_ReqChangeMapHuntTreasure_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".treasure.PosData",
                ["name"] = "posdata"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_RetChangeMapHuntTreasure_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "retcode",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "treasure.proto",
["package"] = "treasure"

----- end of proto -----
