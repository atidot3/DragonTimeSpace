name = quiz.proto

package quiz;

message QuizData {
    optional uint32 questionnum = 1;
    optional uint32 questionid = 2;
    optional uint32 correctid = 3;
}

message AnswerRewards {
    optional uint32 objid = 1;
    optional uint32 objnum = 2;
}

message MSG_Req_QuizPrivilege_CS {
    optional bool onlycheck = 1;
}

message MSG_Ret_QuizPrivilege_SC {
    optional QuizStage stageid = 1;    // type_name = .quiz.QuizStage
}

message MSG_Req_StartQuiz_CS {
    optional QuizStage stageid = 1;    // type_name = .quiz.QuizStage
}

message MSG_Ret_QuestionsData_SC {
    optional QuizStage stageid = 1;    // type_name = .quiz.QuizStage
    repeated QuizData quizdatas = 2;    // type_name = .quiz.QuizData
    optional uint32 curquestionnum = 3;
    optional uint32 correctnum = 4;
    optional uint32 remaintime = 5;
    optional uint32 errorid = 6;
}

message MSG_AnswerQuestion_CS {
    optional QuizStage stageid = 1;    // type_name = .quiz.QuizStage
    optional QuizData quizdata = 2;    // type_name = .quiz.QuizData
}

message MSG_Ret_QuestionResult_SC {
    optional QuizStage stageid = 1;    // type_name = .quiz.QuizStage
    optional QuizData quizdata = 2;    // type_name = .quiz.QuizData
    repeated AnswerRewards rewards = 3;    // type_name = .quiz.AnswerRewards
    optional bool result = 4;
}

message MSG_Req_UseHelpItem_CS {
    optional QuizStage stageid = 1;    // type_name = .quiz.QuizStage
    optional uint32 objid = 2;
    optional uint32 questionnum = 3;
}

message MSG_Ret_HelpItemEffect_SC {
    optional QuizStage stageid = 1;    // type_name = .quiz.QuizStage
    optional uint32 objid = 2;
    optional uint32 questionnum = 3;
    optional uint32 effectvalue = 4;
}

message Day7ActivityInfo {
    optional uint32 dayid = 1;
    optional ActivityState state = 2;    // type_name = .quiz.ActivityState
}

message MSG_Ret_Day7ActivityInfo_SC {
    repeated Day7ActivityInfo data = 1;    // type_name = .quiz.Day7ActivityInfo
}

message MSG_Req_RecvDay7ActivityPrize_CS {
null
}

message MSG_Req_SeekActivityInfo_CS {
null
}

message MSG_Ret_SeekActivityInfo_SC {
    optional ActivityState state = 1;    // type_name = .quiz.ActivityState
    optional uint32 id = 2;
}

message MSG_Req_RecvSeekActivityPrize_CS {
    optional uint32 id = 1;
}

----- table version -----
["enum_type"] = {
    [1] = {
        ["name"] = "QuizStage",
        ["value"] = {
            [1] = {
                ["name"] = "QUIZ_STAGE_NULL",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "QUIZ_STAGE_FIRST",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "QUIZ_STAGE_SECOND",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "QUIZ_STAGE_FINAL",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "QUIZ_STAGE_MAX",
                ["number"] = 4
            }
        }
    },
    [2] = {
        ["name"] = "ActivityState",
        ["value"] = {
            [1] = {
                ["name"] = "ACTIVITY_STATE_UNOPEN",
                ["number"] = 0
            },
            [2] = {
                ["name"] = "ACTIVITY_STATE_OPEN",
                ["number"] = 1
            },
            [3] = {
                ["name"] = "ACTIVITY_STATE_COMPLETE",
                ["number"] = 2
            },
            [4] = {
                ["name"] = "ACTIVITY_STATE_GOTPRIZE",
                ["number"] = 3
            },
            [5] = {
                ["name"] = "ACTIVITY_STATE_UNCOMPLETE",
                ["number"] = 4
            }
        }
    }
},
["message_type"] = {
    [1] = {
        ["name"] = "QuizData",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questionnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questionid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "correctid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [2] = {
        ["name"] = "AnswerRewards",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [3] = {
        ["name"] = "MSG_Req_QuizPrivilege_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_BOOL",
                ["name"] = "onlycheck",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [4] = {
        ["name"] = "MSG_Ret_QuizPrivilege_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".quiz.QuizStage",
                ["name"] = "stageid"
            }
        }
    },
    [5] = {
        ["name"] = "MSG_Req_StartQuiz_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".quiz.QuizStage",
                ["name"] = "stageid"
            }
        }
    },
    [6] = {
        ["name"] = "MSG_Ret_QuestionsData_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".quiz.QuizStage",
                ["name"] = "stageid"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quiz.QuizData",
                ["name"] = "quizdatas"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "curquestionnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "correctnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [5] = {
                ["number"] = 5,
                ["type"] = "TYPE_UINT32",
                ["name"] = "remaintime",
                ["label"] = "LABEL_OPTIONAL"
            },
            [6] = {
                ["number"] = 6,
                ["type"] = "TYPE_UINT32",
                ["name"] = "errorid",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [7] = {
        ["name"] = "MSG_AnswerQuestion_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".quiz.QuizStage",
                ["name"] = "stageid"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quiz.QuizData",
                ["name"] = "quizdata"
            }
        }
    },
    [8] = {
        ["name"] = "MSG_Ret_QuestionResult_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".quiz.QuizStage",
                ["name"] = "stageid"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quiz.QuizData",
                ["name"] = "quizdata"
            },
            [3] = {
                ["number"] = 3,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quiz.AnswerRewards",
                ["name"] = "rewards"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_BOOL",
                ["name"] = "result",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [9] = {
        ["name"] = "MSG_Req_UseHelpItem_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".quiz.QuizStage",
                ["name"] = "stageid"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questionnum",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [10] = {
        ["name"] = "MSG_Ret_HelpItemEffect_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".quiz.QuizStage",
                ["name"] = "stageid"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "objid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [3] = {
                ["number"] = 3,
                ["type"] = "TYPE_UINT32",
                ["name"] = "questionnum",
                ["label"] = "LABEL_OPTIONAL"
            },
            [4] = {
                ["number"] = 4,
                ["type"] = "TYPE_UINT32",
                ["name"] = "effectvalue",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [11] = {
        ["name"] = "Day7ActivityInfo",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "dayid",
                ["label"] = "LABEL_OPTIONAL"
            },
            [2] = {
                ["number"] = 2,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".quiz.ActivityState",
                ["name"] = "state"
            }
        }
    },
    [12] = {
        ["name"] = "MSG_Ret_Day7ActivityInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_REPEATED",
                ["type"] = "TYPE_MESSAGE",
                ["type_name"] = ".quiz.Day7ActivityInfo",
                ["name"] = "data"
            }
        }
    },
    [13] = {
        ["name"] = "MSG_Req_RecvDay7ActivityPrize_CS"
    },
    [14] = {
        ["name"] = "MSG_Req_SeekActivityInfo_CS"
    },
    [15] = {
        ["name"] = "MSG_Ret_SeekActivityInfo_SC",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["label"] = "LABEL_OPTIONAL",
                ["type"] = "TYPE_ENUM",
                ["type_name"] = ".quiz.ActivityState",
                ["name"] = "state"
            },
            [2] = {
                ["number"] = 2,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    },
    [16] = {
        ["name"] = "MSG_Req_RecvSeekActivityPrize_CS",
        ["field"] = {
            [1] = {
                ["number"] = 1,
                ["type"] = "TYPE_UINT32",
                ["name"] = "id",
                ["label"] = "LABEL_OPTIONAL"
            }
        }
    }
},
["name"] = "quiz.proto",
["package"] = "quiz"

----- end of proto -----
