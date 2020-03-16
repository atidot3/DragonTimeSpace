name = mail_cmd.proto

package mail;

message mail_item {
    optional string mailid = 1;
    optional string fromid = 2;
    optional string fromname = 3;
    optional string title = 4;
    optional string text = 5;
    optional string createtime = 6;
    optional string deltime = 7;
    optional uint32 state = 8;
    optional uint32 itemgot = 9;
    repeated t_Object obj_list = 10;    // type_name = .Obj.t_Object
    repeated Hero hero_list = 11;    // type_name = .hero.Hero
}

message MSG_Req_MailList_CS {
null
}

message MSG_Ret_MailList_SC {
    repeated mail_item items = 1;    // type_name = .mail.mail_item
}

message MSG_Ret_RefreshMail_SC {
    optional mail_item item = 1;    // type_name = .mail.mail_item
}

message MSG_Ret_RefreshMailState_SC {
    optional uint64 mailid = 1;
    optional uint32 state = 2;
}

message MSG_Req_OpenMail_CS {
    optional uint64 mailid = 1;
}

message MSG_Req_GetAttachment_CS {
    optional string mailid = 1;
}

message MSG_Ret_GetAttachment_SC {
    optional uint64 mailid = 1;
    optional bool ret = 2;
}

message MSG_Req_GetAllAttachment_CS {
null
}

message MSG_Req_DeleteMail_CS {
    optional uint64 mailid = 1;
}

message MSG_Ret_DeleteMail_SC {
    repeated string mailid = 1;
    optional bool ret = 2;
}

message MSG_Req_DeleteAllMail_CS {
null
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "MailState",
        ["value"] = {
            [1] = {
                ["name"] = "MAIL_STATE_UNREAD",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "MAIL_STATE_DEL",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "MAIL_STATE_DELAY",
                ["number"] = 3
            },
            [4] = {
                ["name"] = "MAIL_STATE_OPEN",
                ["number"] = 4
            }
        }
    },
    [2] = {
        ["name"] = "MailAttachState",
        ["value"] = {
            [1] = {
                ["name"] = "MAIL_NO_ATTACH",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "MAIL_HAS_ATTACH_DRAWN",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "MAIL_ATTACH_CAN_DRAW",
                ["number"] = 2
            }
        }
    }
},
["package"] = "mail",
["name"] = "mail_cmd.proto",
["dependency"] = {
    [1] = "object.proto",
    [2] = "hero.proto"
},
["message_type"] = {
    [1] = {
        ["name"] = "mail_item",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "mailid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "fromid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "fromname",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_STRING",
                ["name"] = "title",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "text",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_STRING",
                ["name"] = "createtime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_STRING",
                ["name"] = "deltime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_UINT32",
                ["name"] = "state",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_UINT32",
                ["name"] = "itemgot",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Obj.t_Object",
                ["name"] = "obj_list"
            },
            [11] = {
                ["number"] = 11,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".hero.Hero",
                ["name"] = "hero_list"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_Req_MailList_CS"
    },
    [3] = {
        ["name"] = "MSG_Ret_MailList_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".mail.mail_item",
                ["name"] = "items"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Ret_RefreshMail_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".mail.mail_item",
                ["name"] = "item"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_Ret_RefreshMailState_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "mailid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "state",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Req_OpenMail_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "mailid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_Req_GetAttachment_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "mailid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Ret_GetAttachment_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "mailid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "ret",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_Req_GetAllAttachment_CS"
    },
    [10] = {
        ["name"] = "MSG_Req_DeleteMail_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT64",
                ["name"] = "mailid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "MSG_Ret_DeleteMail_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "mailid",
                ["label"] = "LABEL_REPEATED"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "ret",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_Req_DeleteAllMail_CS"
    }
}

----- end of proto -----
