name = avatar.proto

package avatar;

message AvatarPair {
    optional AvatarPart part = 1;    // type_name = .avatar.AvatarPart
    optional uint32 avatarid = 2;
}

message MSG_RetUserAvatars_SC {
    repeated uint32 avatars = 1;
    optional uint32 equipId = 2;
    optional uint64 tranSkillid = 3;
}

message MSG_ReqEquipAvatar_CS {
    optional uint32 avatarId = 1;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "AvatarPart",
        ["value"] = {
            [1] = {
                ["name"] = "AVATAR_HEAD",
                ["number"] = 1
            },
            [2] = {
                ["name"] = "AVATAR_HAIR",
                ["number"] = 2
            },
            [3] = {
                ["name"] = "AVATAR_BODY",
                ["number"] = 3
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "AvatarPair",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".avatar.AvatarPart",
                ["name"] = "part"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "avatarid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "MSG_RetUserAvatars_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "avatars",
                ["label"] = "LABEL_REPEATED"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "equipId",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT64",
                ["name"] = "tranSkillid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_ReqEquipAvatar_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "avatarId",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "avatar.proto",
["package"] = "avatar"

----- end of proto -----
