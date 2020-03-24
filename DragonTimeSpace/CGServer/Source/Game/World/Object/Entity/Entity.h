#pragma once

#include <Utils/Define.h>

#include "../Object.h"

class Health
{
public:
	Health();
	const uint32_t& get_max_health() const;
	const uint32_t& get_cur_health() const;

	void set_max_health(const uint32_t& max);
	void set_cur_health(const uint32_t& cur);
private:
	uint32_t _max_hp, _cur_hp;
};

class Entity : public Object
{
public:
	enum UserState
	{
		USTATE_NOSTATE = 0,
		USTATE_DEATH,
		USTATE_KNOCK_DOWN,
		USTATE_TEAM_MEMBER,
		USTATE_TEAM_LEADER,
		USTATE_HOLD_NPC,
		USTATE_TIPS,
		USTATE_QUEST_START,
		USTATE_QUEST_DOING,
		USTATE_QUEST_FINISH,
		USTATE_SUPPRESS,
		USTATE_HOLD_TRANSFORM,
		USTATE_HOLD_DONE,
		USTATE_BATTLE,
		USTATE_GATHER,
		USTATE_SPY,
		USTATE_DOGWATCHED,
		USTATE_REAL_DAMAGE,
		USTATE_XIANG_WEI,
		USTATE_REDUCE_DAMAGE,
		USTATE_CRAZY_BAO,
		USTATE_AUTO_ATT,
		USTATE_RUN,
		USTATE_PEACE,
		USTATE_HIDE_ME,
		USTATE_PROTECT,
		USTATE_COOPERATE_NOMOVESKILL,
		USTATE_WEAK,
		USTATE_DOOR_OPEN,
		USTATE_NOHURT,
		USTATE_QUESTBAR,
		USTATE_EXP_DAY_FULL,
		USTATE_FLY,
		USTATE_PEACE_BACK,
		USTATE_QUEST_FINISH_SHOWNPC,
		USTATE_PVP,
		USTATE_SOUL,
		USTATE_QUEST_TALK,
		USTATE_ATTACK = 1001,
		USTATE_NOT_MOVE,
		USTATE_DIRECT_PHY_DAM = 1004,
		USTATE_DIRECT_MAG_DAM,
		USTATE_MAG_DEF,
		USTATE_PHY_DEF,
		USTATE_UPDAM,
		USTATE_UPDAMP,
		USTATE_KNOCK_DOWN_NEW,
		USTATE_RUSH,
		USTATE_DAMRATE,
		USTATE_EXTRA_DAMRATE,
		USTATE_SUPPRESS_NEW,
		USTATE_REAL_DAMRATE,
		USTATE_REDUCE_DAMRATE,
		USTATE_UMAXHPNUMP,
		USTATE_DMAXHPNUMP,
		USTATE_UMOVESPEED,
		USTATE_DMOVESPEED,
		USTATE_UBANG,
		USTATE_DBANG,
		USTATE_UHPNUMP,
		USTATE_DHPNUMP,
		USTATE_UMP,
		USTATE_DMP,
		USTATE_IGNORE_DMOVESPEED,
		USTATE_SKILL_GOD,
		USTATE_CLEAR_CD,
		USTATE_SKILL_ON_OFF,
		USTATE_SUMMON,
		USTATE_UCHANGE_HP,
		USTATE_DCHANGE_HP,
		USTATE_SUB_DAMRATE_PER_TARGET,
		USTATE_HIDE,
		USTATE_LOOP_SKILL,
		USTATE_CLEAR_STATE,
		USTATE_FORWARD_STATE,
		USTATE_CHECKBUFF_STATE,
		USTATE_CHECKDOSKILL_STATE,
		USTATE_DOSKILL_STATE,
		USTATE_ASATTACK_BLEEDING,
		USTATE_ASATTACK_ADDDAMAGE,
		USTATE_BURNING_STATE,
		USTATE_EXTRABANG_STATE,
		USTATE_ASHIDE_SLOW = 1050,
		USTATE_ASHIDE_ADDDAMAGE,
		USTATE_ASHIDE_REGENERATION,
		USTATE_ASSTAB_SHOW,
		USTATE_ASSTAB_REDUCTION,
		USTATE_ASDART_SLOW,
		USTATE_ASDART_BOOM,
		USTATE_STIFF_STATE,
		USTATE_BLOW_STATE,
		USTATE_KNOCK_STATE,
		USTATE_FLOAT_STATE,
		USTATE_SUPERHIT_STATE,
		USTATE_GODGEXDAMAGE_STATE,
		USTATE_VGTEXDAMAGE_STATE,
		USTATE_LOWHPEXTRAHURT_STATE,
		USTATE_CHANGE_SHAPE,
		USTATE_BULFAKEDEAD_STATE,
		USTATE_BULSTANDSKILL_STATE,
		USTATE_BULCONFUSE_STATE,
		USTATE_BULABSORB_STATE,
		USTATE_BULWEAK_STATE,
		USTATE_FOOD_STATE,
		USTATE_BOSSBUL_REDUCEMAGICHURT_STATE,
		USTATE_BOSSBUL_REDUCEPHYSICHURT_STATE,
		USTATE_BOSSBUL_ADDMAGICHURT_STATE,
		USTATE_BOSSBUL_ADDPHYSICHURT_STATE,
		USTATE_CL_CONTINUE_SKILL_STATE,
		USTATE_TEMP_SKILL_BY_NPCID_STATE,
		USTATE_RECORD_DAMAGE,
		USTATE_AVERAGE_ADD_HP,
		USTATE_SUMMON_ASSIST_NPC,
		USTATE_KILL_SELF,
		USTATE_ADD_HP_BY_CURHP,
		USTATE_SUB_HP_BY_CURHP,
		USTATE_DELAY_SKILL,
		USTATE_IN_PIC_PANEL,
		USTATE_SUMMON_TOTEM,
		USTATE_HIDE_TO_MASTER,
		USTATE_FOOD_MOVE_STATE,
		USTATE_CL3_STOPPET_STATE,
		USTATE_MGOD_RANDSKILLRATE_STATE,
		USTATE_BLM_HEALBYPHY_STATE,
		USTATE_BLM_HEALBYMAG_STATE,
		USTATE_BLM_ROLLING_STATE,
		USTATE_BLM_CHECKROLLING_STATE,
		USTATE_KL_HIDELIMIT_STATE,
		USTATE_KL_OFFSETCONTROL_STATE,
		USTATE_RKING_CARROT_STATE,
		USTATE_YMC_FAKEDEATH_STATE,
		USTATE_YMC_HEALSIGN_STATE,
		USTATE_TORTOISE_SHIELD,
		USTATE_TORTOISE_STRONG,
		USTATE_USE_TORTOISE_ATT,
		USTATE_CHECK_TORTOISE_BROKEN,
		USTATE_YMC_HEALSELF_STATE,
		USTATE_ZELAS_COMBO,
		USTATE_CHANGE_HP_BY_CFG,
		USTATE_HP2ATTDEF,
		USTATE_JIAOZI_FLAG,
		USTATE_MAXHP2ATT,
		USTATE_CHANGE_HP_BY_MY_ATT,
		USTATE_HITRATE_STATE,
		USTATE_CHANGEDEF_STATE,
		USTATE_LANQI_CHANGE_STATE,
		USTATE_LANQI_GOLDENHAIR_STATE,
		USTATE_LANQI_DOADDHPSKILL_STATE,
		USTATE_LANQI_DOADDATTACKSKILL_STATE,
		USTATE_LANQI_ADDHP_STATE,
		USTATE_LANQI_ADDATTACK_STATE,
		USTATE_INSTEADSKILL_STATE,
		USTATE_INSTEADTIMES_STATE,
		USTATE_BLM_FROZEN_STATE = 1130,
		USTATE_BLM_FREEZE_STATE,
		USTATE_EXPOSE_WEAKNESS_STATE,
		USTATE_TBB_FINGER_STATE,
		USTATE_PATT_DHP_STATE,
		USTATE_GARLIC_STATE,
		USTATE_NORMALSLOW_STATE,
		USTATE_NORMALUSESKILL_STATE,
		USTATE_NORMALFIRM_STATE,
		USTATE_DEMONEYE_STATE,
		USTATE_BULFROZEN_STATE,
		USTATE_ADDHP_BY_PATT_NO_PKRESULT,
		USTATE_ADDHP_BY_MATT_NO_PKRESULT,
		USTATE_BULSHEILD_STATE,
		USTATE_ADDPHYDAMAGE_STATE,
		USTATE_CONSTANT_PDAMAGE,
		USTATE_CONSTANT_MDAMAGE,
		USTATE_BOSSWEAK_STATE,
		USTATE_TRANSPARENT_STATE,
		USTATE_DIRECT_TRANSPARENT_STATE,
		USTATE_JIAOZI_HEARTCONTROL,
		USTATE_JIAOZI_DURATION_DAMAGE,
		USTATE_JIAOZI_DELAY_DAMAGE,
		USTATE_CONSTANT_DODGE,
		USTATE_BOSSCALL,
		USTATE_GODJIEWANGQUAN_STATE,
		USTATE_VGTFIGHTIDEA_STATE,
		USTATE_QQHEAL_STATE,
		USTATE_QQSHEILD_STATE,
		USTATE_NMWFIRESHEILD_STATE,
		USTATE_AURASADDPATT_STATE,
		USTATE_AURASADDMATT_STATE,
		USTATE_RECOVERYHPDEC_STATE,
		USTATE_DIZZINESS_STATE = 1165,
		USTATE_JUMP_TO_STATE = 1178,
		USTATE_HAVE_TURTLE_SHELL,
		USTATE_FLY_FLOWER,
		USTATE_ZHENQI,
		USTATE_COST_BUFFSTATE,
		USTATE_COUNT_SKILL_USE,
		USTATE_COST_COUNT_USE_SKILL,
		USTATE_COST_BUFF_USE_SKILL,
		USTATE_QUICK_MOVE,
		USTATE_ADD_BUFF_LASTTIME,
		USTATE_ADD_COUNT_SKILL,
		USTATE_BREATH_MESSY,
		USTATE_POWER_ECODE,
		USTATE_CHECK_NEXT_SKILL,
		USTATE_CHECK_SKILL_BUFF,
		USTATE_ABSOLB_SHEILD,
		USTATE_FIRE_CRIT,
		USTATE_HIT_BACK,
		USTATE_DEF_BROKE,
		USTATE_KAIO_KEN,
		USTATE_ZHENQI_PROTECT,
		USTATE_AREA_CIRCLE,
		USTATE_RECORD_BUFF,
		USTATE_ENERGY_STORM,
		USTATE_DEC_FIRE_CD,
		USTATE_BELL_QTE,
		USTATE_CYTOTHESIS,
		USTATE_DEAD_CHECK,
		USTATE_MAJIN_ABSORB,
		USTATE_COPY_DAMANGE,
		USTATE_BUFF_FEAR,
		USTATE_DRINK_BLOOD,
		USTATE_SPREAD,
		USTATE_STAMP,
		USTATE_MAJIN_ANGRY,
		USTATE_NO_ENEMY,
		USTATE_MASTER_MOVE,
		USTATE_CALL_MASTER_MOVE,
		USTATE_CURE_RATE,
		USTATE_BE_SILENCE,
		USTATE_LOST_HP_ONCE,
		USTATE_BLESS,
		USTATE_MAGIC_LIGHT,
		USTATE_CHECK_MAGIC_LIGHT,
		USTATE_HIGHT_SPIRIT,
		USTATE_CLEAR_ALL_BUFF,
		USTATE_VISIT_NPC_HOLDING,
		USTATE_CURE_RAIN,
		USTATE_FRUSTRATE_TO_COURAGE,
		USTATE_CLEAR_SKILL_CD,
		USTATE_CURE_SELF,
		USTATE_OCCUR_DEATH,
		USTATE_PRETEND_DEATH,
		USTATE_STRONG_ATTACK,
		USTATE_DEEP_THINK,
		USTATE_UNBLENDING_CHECK,
		USTATE_BE_STONE,
		USTATE_VIOLENTW,
		USTATE_INVESTGATE,
		USTATE_UNCONTROL,
		USTATE_CURE_DRUG,
		USTATE_ESCAPE_CHECK,
		USTATE_FATAL_SPREAD,
		USTATE_ACCURATE_STRIKE,
		USTATE_LOST_HP_TO_ATT,
		USTATE_NEWER_ARROW,
		USTATE_TORTOISE_SHEILD,
		USTATE_CRUSHING_BLOW,
		USTATE_MAGIC_FINGER_CHECK,
		USTATE_CRANE_MARK,
		USTATE_IMMORTAL_MARK,
		USTATE_TOLERANCE,
		USTATE_TOLERANCE_CHECK,
		USTATE_FEEBLE,
		USTATE_DRUNKEN_FIST,
		USTATE_STRONG_BODY,
		USTATE_UNBLENDING,
		USTATE_TRANSFER_POINT,
		USTATE_BANDAGE_TIWNED,
		USTATE_EVIL_LIGHT,
		USTATE_DOWN_MOVE_SPEED,
		USTATE_UP_BANG,
		USTATE_MUSCLE_MAX,
		USTATE_ESCAPE,
		USTATE_FREEZE,
		USTATE_HOLLOW_MAN,
		USTATE_LOCK_KEYBOARD,
		USTATE_STONE_FALL,
		USTATE_EVIL_TOILET,
		USTATE_RUSH_FREEZE,
		USTATE_SHIFT_STATE,
		USTATE_QIGONG_ENERGY,
		USTATE_MIND_PRESENCE,
		USTATE_BARRIER,
		USTATE_DISCERN,
		USTATE_NAMEIKE_SHEILD,
		USTATE_UNDERCURRENTS,
		USTATE_TURTLE_SHEILD,
		USTATE_PURIFY_EVIL,
		USTATE_CLEAR_BUFF,
		USTATE_HEARTY_MEAL,
		USTATE_EVOLUTION_SKILL,
		USTATE_IMPACT_WAVE,
		USTATE_MIND_DISTURBANCE,
		USTATE_TIME_DOWN_SPEED,
		USTATE_FOUR_DEMON_FIST,
		USTATE_ADV_FOUR_DEMON_FIST,
		USTATE_IN_SKILL_RANGE,
		USTATE_OUT_SKILL_RANGE,
		USTATE_QUEST_KAIO_KEN,
		USTATE_QUEST_KAIO_STAR,
		USTATE_ENDURE,
		USTATE_THEWS_MAX,
		USTATE_BRAVE_SWORD,
		USTATE_SYR_ANGRY,
		USTATE_UBANG1,
		USTATE_ALL_DEAD,
		USTATE_TIME_FLAG,
		USTATE_DEEP_IN_TROUBLE,
		USTATE_ANCESTRY,
		USTATE_POWER_PROFICIENT,
		USTATE_DEFEND_SHEILD,
		USTATE_FAMILY_SHEILD_COLOR,
		USTATE_FAMILY_SHEILD,
		USTATE_TEN_LOW_SPEED1,
		USTATE_TEN_LOW_SPEED2,
		USTATE_TWENTY_LOW_SPEED1,
		USTATE_TWENTY_LOW_SPEED2,
		USTATE_THIRTY_LOW_SPEED1,
		USTATE_THIRTY_LOW_SPEED2,
		USTATE_THIRTY_LOW_SPEED3,
		USTATE_FIT_GRAVITY,
		USTATE_TEAR_STRIKE,
		USTATE_HOT_BLOOD,
		USTATE_ANGRY_BLOOD,
		USTATE_PRETEND,
		USTATE_PAUSE_TIME,
		USTATE_FIGHT_POSE,
		USTATE_CHECK_STRENG_SYQ,
		USTATE_MASK_ME,
		USTATE_DRAGONBALL_TASK,
		USTATE_SYQ_EXTRADMG,
		USTATE_MOFENGGUO,
		USTATE_SKILL_CHECK_DISTANCE,
		USTATE_DAMUP_ATTDOWN,
		USTATE_IMMU_HURT_CTRL,
		USTATE_GAS_BOMB_BURSTS,
		USTATE_EXCITATION,
		USTATE_INVINCIBLE,
		USTATE_SHED_BLOOD,
		USTATE_PYHSICAL_OVERDDRFT,
		USTATE_FORCE_OF_DETERRENCE,
		USTATE_LIGHT_SPEED,
		USTATE_CANNOT_HOLD,
		USTATE_WORLD_OF_LEGEND,
		USTATE_ENERGY_SHIELD,
		USTATE_LIMITLESS_ENERGY,
		USTATE_ARTIFICAL_HEART,
		USTATE_FAST_ATTACH,
		USTATE_IMMUNE_HURT_CTRL,
		USTATE_FIXED_BODY,
		USTATE_RELIVE_FRIEND,
		USTATE_MOVE_SPEEDUP,
		USTATE_WORLD_NO1,
		USTATE_ENERGY_UP_RATE,
		USTATE_BURN_MUST_BANG,
		USTATE_LOCK_HP,
		USTATE_ANTI_CONTROL,
		USTATE_NPC_SUB_SKILL,
		USTATE_MOBA_BALL,
		USTATE_MOBA_PRAY_HOPE11,
		USTATE_MOBA_PRAY_HOPE12,
		USTATE_MOBA_PRAY_HOPE13,
		USTATE_MOBA_PRAY_HOPE21,
		USTATE_MOBA_PRAY_HOPE22,
		USTATE_MOBA_PRAY_HOPE23,
		USTATE_MOBA_PRAY_HOPE31,
		USTATE_MOBA_PRAY_HOPE32,
		USTATE_MOBA_PRAY_HOPE33,
		USTATE_MOBA_PRAY,
		USTATE_MOBA_NODAM,
		USTATE_MOBA_DIZZY,
		USTATE_MOBA_SPDUP,
		USTATE_MOBA_SUPER_RADAR,
		USTATE_MOBA_KICKOUT,
		USTATE_SMALLCELL_AIEFFECT,
		USTATE_SMALLCELL_AIEFFECT2,
		USTATE_QUICK_MOVE_QUEST,
		USTATE_ANGRY_YOUNG,
		USTATE_MAXHP_UP = 3001,
		USTATE_MAXHP_DOWN,
		USTATE_BANG_UP = 3019,
		USTATE_BANG_DOWN,
		USTATE_BANGRATE_UP,
		USTATE_MOVESPEED_UP,
		USTATE_MOVESPEED_DOWN,
		USTATE_EXTRADAMRATE,
		USTATE_EXTRAHURT,
		USTATE_DOWNDAMRATE,
		USTATE_DEFDAMRATE,
		USTATE_CALLTRIGGER = 9000,
		USTATE_NORMAL_SIYA = 10000,
		USTATE_SUPER_SIYA_1,
		USTATE_SUPER_SIYA_2,
		USTATE_SUPER_SIYA_3,
		USTATE_SUPER_SIYA_GOD,
		USTATE_SUPER_SIYA_BLUE,
		USTATE_SUPER_SIYA_BLUE_ALL,
		USTATE_MAX
	};
public:
	Entity();
	// -- CONST GETTER
	const Object& get_object() const;
	const Health& get_health() const;
	const std::string get_name() const;

	// GETTER EDITABLE
	Object& get_object();
	Health& get_health();
	std::string& get_name();

	// -- SETTER
	void set_name(const std::string& name);
	void update_health(const uint32_t& cur_health);
	void update_max_health(const uint32_t& max_health);

	//--
	static uint64_t GenernateBuffHash(const uint64_t& entryID, const uint64_t& userState, const uint64_t& entrytype, const uint64_t& uniqueID);

private:
	Health			_health;
	std::string		_name;
};
