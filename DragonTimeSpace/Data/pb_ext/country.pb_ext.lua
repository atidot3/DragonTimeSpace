name = country.proto

package country;

message MSG_Req_JoinCountry_CS {
    optional uint32 countryid = 1;
}

message MSG_Ret_JoinCountry_SC {
    optional uint32 retcode = 1;
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "MSG_Req_JoinCountry_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "countryid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Ret_JoinCountry_SC",
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
["name"] = "country.proto",
["package"] = "country"

----- end of proto -----
