name = textmodel.proto

package TextModelpackage;

message TextModelContentProto {
    optional string modelBegin = 1;
    optional string modelEnd = 2;
    optional uint32 fontSize = 3;
    optional string fontName = 4;
}

message TextModelContentListProto {
    repeated string key = 1;
    repeated TextModelContentProto modelList = 2;    // type_name = .TextModelpackage.TextModelContentProto
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "TextModelContentProto",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "modelBegin",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "modelEnd",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "fontSize",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_STRING",
                ["name"] = "fontName",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "TextModelContentListProto",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "key",
                ["label"] = "LABEL_REPEATED"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".TextModelpackage.TextModelContentProto",
                ["name"] = "modelList"
            }
        }
    }
},
["name"] = "textmodel.proto",
["package"] = "TextModelpackage"

----- end of proto -----
