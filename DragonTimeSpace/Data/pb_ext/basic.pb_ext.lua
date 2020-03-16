name = basic.proto

package basic;

message ObjectItem {
    optional uint32 id = 1;
    optional uint32 num = 2;
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "ObjectItem",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "num",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "basic.proto",
["package"] = "basic"

----- end of proto -----
