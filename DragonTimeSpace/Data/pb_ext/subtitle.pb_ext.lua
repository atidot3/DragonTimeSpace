name = subtitle.proto

package Subtitle;

message SubtitleContent {
    optional float showTime = 1;
    optional string subtitle = 2;
    optional float duration = 3;
}

message CutSceneSubTitle {
    optional string key = 1;
    repeated SubtitleContent subtitlelist = 2;    // type_name = .Subtitle.SubtitleContent
}

message TotalCutSceneSubTitle {
    repeated CutSceneSubTitle subtitlelist = 1;    // type_name = .Subtitle.CutSceneSubTitle
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "SubtitleContent",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "showTime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_STRING",
                ["name"] = "subtitle",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_FLOAT",
                ["name"] = "duration",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "CutSceneSubTitle",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "key",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Subtitle.SubtitleContent",
                ["name"] = "subtitlelist"
            }
        }
    },
    [3] = {
        ["name"] = "TotalCutSceneSubTitle",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".Subtitle.CutSceneSubTitle",
                ["name"] = "subtitlelist"
            }
        }
    }
},
["name"] = "subtitle.proto",
["package"] = "Subtitle"

----- end of proto -----
