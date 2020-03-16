name = test.proto

package test;

message Test {
    required string name = 1;
    required int32 id = 2;
    optional string opt = 5;
    optional bytes testbytes = 6;
}

message MSG_Ret_Test1 {
null
}

message MSG_Ret_Test2 {
null
}

message MSG_Ret_Test3 {
null
}

message MSG_Ret_Test4 {
null
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "Test",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "name",
                ["label"] = "LABEL_REQUIRED"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_INT32",
                ["name"] = "id",
                ["label"] = "LABEL_REQUIRED"
            },
            [3] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "opt",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 6,
                ["type"] = "TYPE_BYTES",
                ["name"] = "testbytes",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Ret_Test1"
    },
    [3] = {
        ["name"] = "MSG_Ret_Test2"
    },
    [4] = {
        ["name"] = "MSG_Ret_Test3"
    },
    [5] = {
        ["name"] = "MSG_Ret_Test4"
    }
},
["name"] = "test.proto",
["package"] = "test"

----- end of proto -----
