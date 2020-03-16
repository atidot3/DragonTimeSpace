name = triggersounddata.proto

package triggersounddata;

message TriggerSoundData {
    optional string path = 1;
    optional bool ButtonSound = 2;
    optional string ButtonClickEvent = 3;
    optional bool ToggleSound = 4;
    optional string ToggleClickEvent = 5;
    optional bool SetActive = 6;
    optional string SetActiveEvent = 7;
    optional bool SetDisActive = 8;
    optional string SetDisActiveEvent = 9;
    optional bool EffectSound = 10;
    optional string EffectBeginEvent = 11;
    optional string EffectEndEvent = 12;
}

message TriggerSoundDataList {
    repeated TriggerSoundData tsd = 1;    // type_name = .triggersounddata.TriggerSoundData
}

----- table version -----
["message_type"] = {
    [1] = {
        ["name"] = "TriggerSoundData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_STRING",
                ["name"] = "path",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_BOOL",
                ["name"] = "ButtonSound",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_STRING",
                ["name"] = "ButtonClickEvent",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_BOOL",
                ["name"] = "ToggleSound",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_STRING",
                ["name"] = "ToggleClickEvent",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_BOOL",
                ["name"] = "SetActive",
                ["label"] = "LABEL_OPTIONAL"
            },
            [7] = {
                ["number"] = 7,
                ["type"] = "TYPE_STRING",
                ["name"] = "SetActiveEvent",
                ["label"] = "LABEL_OPTIONAL"
            },
            [8] = {
                ["number"] = 8,
                ["type"] = "TYPE_BOOL",
                ["name"] = "SetDisActive",
                ["label"] = "LABEL_OPTIONAL"
            },
            [9] = {
                ["number"] = 9,
                ["type"] = "TYPE_STRING",
                ["name"] = "SetDisActiveEvent",
                ["label"] = "LABEL_OPTIONAL"
            },
            [10] = {
                ["number"] = 10,
                ["type"] = "TYPE_BOOL",
                ["name"] = "EffectSound",
                ["label"] = "LABEL_OPTIONAL"
            },
            [11] = {
                ["number"] = 11,
                ["type"] = "TYPE_STRING",
                ["name"] = "EffectBeginEvent",
                ["label"] = "LABEL_OPTIONAL"
            },
            [12] = {
                ["number"] = 12,
                ["type"] = "TYPE_STRING",
                ["name"] = "EffectEndEvent",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "TriggerSoundDataList",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".triggersounddata.TriggerSoundData",
                ["name"] = "tsd"
            }
        }
    }
},
["name"] = "triggersounddata.proto",
["package"] = "triggersounddata"

----- end of proto -----
