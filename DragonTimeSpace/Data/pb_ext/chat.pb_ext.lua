name = chat.proto

package Chat;

message MSG_Req_ChannleChat_CS {
    optional string str_chat = 1;
    optional string src_name = 2;
    optional ChannelType channel_type = 3;    // type_name = .Chat.ChannelType
}

message MSG_Ret_ChannelChat_SC {
    optional string str_chat = 1;
    optional string src_name = 2;
    optional uint32 textid = 3;
    optional ChannelType channel_type = 4;    // type_name = .Chat.ChannelType
}

message ChatLink {
    optional uint32 linktype = 1;
    repeated string data_args = 2;
}

message ChatData {
    optional uint32 channel = 1;
    optional uint64 charid = 2;
    optional string charname = 3;
    optional uint32 charcountry = 4;
    optional uint32 chattime = 5;
    optional string content = 6;
    repeated ChatLink link = 7;    // type_name = .Chat.ChatLink
    optional uint32 show_type = 8;
    optional uint64 tocharid = 9;
    optional string toname = 10;
}

message MSG_Req_Chat_CS {
    optional ChatData data = 1;    // type_name = .Chat.ChatData
    optional bool shake = 2;
}

message MSG_Ret_Chat_SC {
    optional ChatData data = 1;    // type_name = .Chat.ChatData
    optional bool shake = 2;
}

message MSG_Req_ChatUserInfo_CS {
    optional uint64 otherid = 1;
}

message MSG_Ret_ChatUserInfo_SC {
    optional uint64 charid = 1;
    optional string charname = 2;
    optional uint32 level = 3;
    optional uint32 occupation = 4;
    optional uint32 occupationlevel = 5;
    optional bool can_take_master = 6 [default = false];
    optional bool can_take_apprent = 7 [default = false];
}

message MSG_Req_OfflineChat_CS {
null
}

message MSG_Ret_OfflineChat_SC {
    repeated ChatData datas = 1;    // type_name = .Chat.ChatData
}

message MSG_Req_ImportantBroadcast_CS {
null
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "ChannelType",
        ["value"] = {
            [1] = {
                ["name"] = "ChannelType_None",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "ChannelType_Sys",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "ChannelType_Team",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "ChannelType_Guild",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "ChannelType_Camp",
                ["number"] = 4
            },
            [6] = {
                ["name"] = "ChannelType_World",
                ["number"] = 5
            },
            [7] = {
                ["name"] = "ChannelType_Scene",
                ["number"] = 6
            },
            [8] = {
                ["name"] = "ChannelType_Private",
                ["number"] = 7
            },
            [9] = {
                ["name"] = "ChannelType_GmTool",
                ["number"] = 8
            },
            [10] = {
                ["name"] = "ChannelType_Moba",
                ["number"] = 9
            },
            [11] = {
                ["name"] = "ChannelType_Secret",
                ["number"] = 10
            }
        }
    },
    [2] = {
        ["name"] = "ChatShowType",
        ["value"] = {
            [1] = {
                ["name"] = "ChatShowType_MessageBox",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "ChatShowType_Sys",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "ChatShowType_Tips_Red",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "ChatShowType_Tips_Green",
                ["number"] = 4
            },
            [5] = {
                ["name"] = "ChatShowType_Tips_BossPk",
                ["number"] = 5
            },
            [6] = {
                ["name"] = "ChatShowType_Tips_Task",
                ["number"] = 6
            },
            [7] = {
                ["name"] = "ChatShowType_TimerTips",
                ["number"] = 7
            }
        }
    },
    [3] = {
        ["name"] = "ChatTextType",
        ["value"] = {
            [1] = {
                ["name"] = "ChatTextType_Plain",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "ChatTextType_Rich",
                ["number"] = 2
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "MSG_Req_ChannleChat_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "str_chat",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "src_name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Chat.ChannelType",
                ["name"] = "channel_type"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Ret_ChannelChat_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "str_chat",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "src_name",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "textid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".Chat.ChannelType",
                ["name"] = "channel_type"
            }
        }
    },
    [3] = {
        ["name"] = "ChatLink",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "linktype",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "data_args",
                ["label"] = "LABEL_REPEATED"
            }
        }
    },
    [4] = {
        ["name"] = "ChatData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "channel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "charname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "charcountry",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "chattime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_STRING",
                ["name"] = "content",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Chat.ChatLink",
                ["name"] = "link"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "show_type",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tocharid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_STRING",
                ["name"] = "toname",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_Req_Chat_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Chat.ChatData",
                ["name"] = "data"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "shake",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Ret_Chat_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Chat.ChatData",
                ["name"] = "data"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "shake",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_Req_ChatUserInfo_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "otherid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Ret_ChatUserInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "charid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "charname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "level",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "occupation",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "occupationlevel",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["default_value"] = "false",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "can_take_master"
            },
            [7] = {
                ["number"] = 7,
                ["default_value"] = "false",
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_BOOL",
                ["name"] = "can_take_apprent"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_Req_OfflineChat_CS"
    },
    [10] = {
        ["name"] = "MSG_Ret_OfflineChat_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Chat.ChatData",
                ["name"] = "datas"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_Req_ImportantBroadcast_CS"
    }
},
["name"] = "chat.proto",
["package"] = "Chat"

----- end of proto -----
