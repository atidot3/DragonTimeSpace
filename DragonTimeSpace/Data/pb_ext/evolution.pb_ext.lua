name = evolution.proto

package evolution;

message MSG_RetUserEvolution_SC {
    repeated uint32 evolutions = 1;
}

message MSG_ReqUserEvolution_CS {
    optional uint32 evolutionId = 1;
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "MSG_RetUserEvolution_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "evolutions",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_ReqUserEvolution_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "evolutionId",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "evolution.proto",
["package"] = "evolution"

----- end of proto -----
