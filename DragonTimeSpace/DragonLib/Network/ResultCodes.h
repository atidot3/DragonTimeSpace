#pragma once

enum WTF_Code
{
	// {0}Insufficient quantity
	INSUFFICIENT_QUANTITY = 1,

	// Receive：{0}
	RECEIVE_UNSUED,

	// Receive：{0}x{1}
	RECEIVE_UNSUED_TOO,

	// Your inventory is full, please clean it up as soon as possible
	INVENTORY_FULL,

	// {0}You've already reached the maximum limited and can't be continued!
	MAXIMUM_COUNT_REACH,

	// Can't find a target!
	TARGET_NOT_FOUND,

	// Today’s experience has reached the upper limit! ???? wtf
	EXPERIENCE_REACHED_LIMIT,

	// The number of purchases run out! ??? wtf
	PURSHASES_RUN_OUT,

	// Buy at most {0} each time ??? wtf
	BUY_AT_MOST_REQUIRED,

	// You've exceeded the quantity limit of purchases
	PURCHASES_QUANTITY_MAXIMUM_REACH,

	// Not enough level!
	INSUFFICIENT_LEVEL,

	// You've reached the highest level!
	HIGHEST_LEVEL_REACH,

	// Welcome to the world of Dragon Ball, pick a hero to participate in Budokai ??? WTF
	ANNOUNCE_PICK_A_HERO_BUDOKAI,

	// Unknown error
	UNKNOWN_ERROR,

	// The location cannot be automatically tracked
	AUTO_WALK_FAILED,

	// Insufficient quantity, cannot be synthesized
	SYNTHESIZED_INSUFFICIENT_QUANTITY,

	// The fixed viewing angle can't be adjusted
	VIEW_ANGLE_ADJUST_FAILED,

	// The angle of view can't be adjusted while tracking the target
	VIEW_ANGLE_ADJUST_FAILED_DURING_TRACKING,

	// That's already the minimum quantity
	ALREADY_MINIMUM_QUANTITY,

	// That's already the maximum quantity
	ALREADY_MAXIMUM_QUANTITY,

	// This item is not for sale
	ITEM_IS_NOT_ON_SALE,

	// The place you're heading to is too mysterious, please ask the teleporter for some help!
	ASK_TELEPORTER_HELP_MYSTERIOUS,

	// Please, ask the teleporter for some help
	ASK_TELEPORTER_HELP,

	// You can't get the quest reward in the stage, please go to the official website to improve your user information as soon as possible!
	QUEST_REWARD_FAILED_CURRENT_STAGE,

	// Every thursday and Friday the guild wars will start at 3 pm, please ask your guildmates to sign up from the guild warfare administrator in the Time and Space City and get wonderful rewards!
	ANNOUNCE_GUILD_WARS_GLOBAL,

	// Every night from 19:00 to 19:30 Beijing time zone, you can answer questions at Mr. Satan's quiz bot. Players who perform well during the weeked will receive a generous reward!
	ANNOUNCE_GUILD_WARS_LOCATION_BEIJING,

	// Guild wars can be registred in 30 min, please prepare your forces!
	ANNOUNCE_30_MINUTES_BEFORE_GUILD_WARS,

	// Every thursday、and friday 3:00 PM will be the fight for the guild, please ask the guild members to sign up for the guild warfare administrator at Time and Space City! You'll get great rewards!
	ANNOUNCE_GUILD_WARS_GLOBAL_2

};

// -- Client result code use result_code + 300
enum ResultCode
{
	// Version error
	VERSION_ERROR = 1,

	// Smart UUID log in method has not been implemented
	SMART_UUID_LOGIN_NOT_IMPLEMENTED,

	// database error
	DATABASE_ERROR,

	// Wrong user/pass
	CREDENTIALS_FAILED,

	// password has been updated
	PASSWORD_UPDATED,

	// Account used, refresh
	ACCOUNT_IN_USE_REFRESH,

	// Account has been banned
	ACCOUNT_BANNED,

	// Gateway closed
	CGSERVER_CLOSED,

	// Auth is full
	AUTH_SERVER_FULL,

	// Account is already in use
	ACCOUNT_ALREADY_IN_USE,

	// Registration success
	REGISTRATION_SUCCESS,

	// This nickname is already in use,
	NAME_ALREADY_USED,

	// User doesn't exist
	USER_DO_NOT_EXIST,

	// Username duplicated
	USERNAME_DUPLICATED,

	// connection time out
	CONNECTION_TIMEOUT,

	// Accounting failure
	ACCOUNTING_FAILURE,

	// Graphic verification code input error
	GRAPHIC_CODE_ERROR,

	// Account is locked
	ACCOUNT_LOCKED,

	// Account needs to be activated
	ACCOUNT_NOT_ACTIVATED,

	// New accounts are not allowed to log in to the old game area
	NEW_ACCOUNT_CANT_LOG_OLD_AREA,

	// UUID log in error
	UUID_LOGIN_ERROR,

	// This class is registred in the character selection, creation of this role is not allowed
	WRONG_CLASS_RACE_COMBINAISON,

	// Cross-region login verification failed
	CROSS_REGION_LOGIN_FAILED,

	// Log in error, please use the password card to log in
	CARD_LOGIN_FAILED,

	// Prompt players need to enter the code of the password card
	CARD_ENTER_PASSWORD,

	// Prompt player using wrong code from password card so it's locked (unlocked after six hours)
	CARD_LOCKED_6_DAYS,

	// Verification with password card has lost the connection to the server
	CARD_PASSWORD_VERIFICATION_CONNECTION_LOST,

	// Old account is not allowed to log in to the new site
	OLD_ACCOUNT_CANT_ACCESS_NEW_SITE,

	// Graphic verification got 3 consecutive errors, your character has been banned
	GRAPHICS_VERIFICATION_ERROR_3_TIMES_CHARACTER_BANNED,

	// Can't log in, please head to Giant's password management, unlock your account and try again
	ACCOUNT_NEED_UNLOCK,

	// Lost connection to the server in fail-safe mode
	SAFE_MODE_SERVER_CONNECTION_LOST,

	// Server is busy
	SERVER_IS_BUSY,

	// Account blocked
	ACCOUNT_BLOCKED,

	// Graphic verification got 9 continous errors, your character has been locked
	GRAPHICS_VERIFICATION_FAILED_9_TIMES_CHARACTERS_LOCKED,

	// Game region is under maintenance
	CGSERVER_MAINTENANCE,

	// Failed to get QR code
	FAILED_GET_QRCODE,

	// QR code service is not available, please enter the account password to login
	QR_CODE_SERVICE_DOWN,

	// Token verification failed
	TOKEN_CHECK_FAILED,

	// TOKEN redeem code entered too fast
	TOKEN_ENTERED_TOO_FAST,

	// TOKEN verification timeout
	TOEK_CHECK_TIMEOUT,

	// Show the following error message
	SHOW_THE_FOLLOWING_ERROR_MESSAGE,

	// User has already logged in
	USER_ALREADY_LOGGED_IN,

	// Nickname contains sensitive words
	NICKNAME_CONTAINS_SENSITIVE_WORD,

	// Gateway not available
	CGSERVER_DOWN,

	// Nickname can't have special characters
	NICKNAME_CONTAIS_SPECIAL_CHARACTERS,

	// Character has been suspended
	CHARACTER_SUPPENDED,

	// Color name cannot be empty
	COLOR_CANT_BE_EMPTY
};