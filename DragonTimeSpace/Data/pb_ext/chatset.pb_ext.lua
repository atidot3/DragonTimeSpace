name = chatset.proto

package Chat;

message LocalChatInfo {
    optional uint64 id = 1;
    optional uint32 unread_num = 2;
    repeated ChatData dataList = 3;    // type_name = .Chat.ChatData
}

message LocalChatSet {
    repeated LocalChatInfo list = 1;    // type_name = .Chat.LocalChatInfo
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "LocalChatInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "unread_num",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Chat.ChatData",
                ["name"] = "dataList"
            }
        }
    },
    [2] = {
        ["name"] = "LocalChatSet",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Chat.LocalChatInfo",
                ["name"] = "list"
            }
        }
    }
},
["dependency"] = {
    [1] = "chat.proto"
},
["name"] = "chatset.proto",
["package"] = "Chat"

----- end of proto -----
