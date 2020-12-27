#pragma once

#include <Tables/Definitions/adventure_copymap.pb.h>
#include <Tables/Definitions/allaction.pb.h>
#include <Tables/Definitions/attribute_config.pb.h>
#include <Tables/Definitions/avatar_config.pb.h>
#include <Tables/Definitions/battle_config.pb.h>
#include <Tables/Definitions/building_data.pb.h>
#include <Tables/Definitions/carddata_config.pb.h>
#include <Tables/Definitions/cardeffect_config.pb.h>
#include <Tables/Definitions/careerLv.pb.h>
#include <Tables/Definitions/charstate.pb.h>
#include <Tables/Definitions/chatchannel.pb.h>
#include <Tables/Definitions/convenient.pb.h>
#include <Tables/Definitions/coordinates_arena_config.pb.h>
#include <Tables/Definitions/copymapEvent.pb.h>
#include <Tables/Definitions/copymapinfo.pb.h>
#include <Tables/Definitions/copymapmaster.pb.h>
#include <Tables/Definitions/cutscene.pb.h>
#include <Tables/Definitions/devicesetting.pb.h>
#include <Tables/Definitions/dialogueconfig.pb.h>
#include <Tables/Definitions/dnachip_config.pb.h>
#include <Tables/Definitions/dnaslot_config.pb.h>
#include <Tables/Definitions/dynamictext.pb.h>
#include <Tables/Definitions/entanglement_config.pb.h>
#include <Tables/Definitions/equips.pb.h>
#include <Tables/Definitions/equip_suffix.pb.h>
#include <Tables/Definitions/esc_config.pb.h>
#include <Tables/Definitions/event_config.pb.h>
#include <Tables/Definitions/evolution_config.pb.h>
#include <Tables/Definitions/faceconfig.pb.h>
#include <Tables/Definitions/gene_remake.pb.h>
#include <Tables/Definitions/growtarget_config.pb.h>
#include <Tables/Definitions/guide.pb.h>
#include <Tables/Definitions/heropanel_maximum.pb.h>
#include <Tables/Definitions/heros.pb.h>
#include <Tables/Definitions/illegalword.pb.h>
#include <Tables/Definitions/key.pb.h>
#include <Tables/Definitions/levelconfig.pb.h>
#include <Tables/Definitions/loadingtips.pb.h>
#include <Tables/Definitions/looksconfig.pb.h>
#include <Tables/Definitions/manufacture.pb.h>
#include <Tables/Definitions/namepool.pb.h>
#include <Tables/Definitions/newUser.pb.h>
#include <Tables/Definitions/npc_data.pb.h>
#include <Tables/Definitions/objects.pb.h>
#include <Tables/Definitions/pathway.pb.h>
#include <Tables/Definitions/player_level_config.pb.h>
#include <Tables/Definitions/questconfig.pb.h>
#include <Tables/Definitions/quizdataConfig.pb.h>
#include <Tables/Definitions/rankpk_level.pb.h>
#include <Tables/Definitions/relation_tbx.pb.h>
#include <Tables/Definitions/reward_level.pb.h>
#include <Tables/Definitions/runeConfig.pb.h>
#include <Tables/Definitions/screensetting.pb.h>
#include <Tables/Definitions/seventarget_config.pb.h>
#include <Tables/Definitions/skillshow.pb.h>
#include <Tables/Definitions/skill_data.pb.h>
#include <Tables/Definitions/skill_guild.pb.h>
#include <Tables/Definitions/skill_stage.pb.h>
#include <Tables/Definitions/summonpet.pb.h>
#include <Tables/Definitions/summonpetLevelUp.pb.h>
#include <Tables/Definitions/survey_config.pb.h>
#include <Tables/Definitions/teleport.pb.h>
#include <Tables/Definitions/textconfig.pb.h>
#include <Tables/Definitions/uimapinfo.pb.h>
#include <Tables/Definitions/unlock_config.pb.h>
#include <Tables/Definitions/vipcard_config.pb.h>
#include <Tables/Definitions/fetters_config.pb.h>

class TableContainer
{
private:
	~TableContainer()
	{
		for (auto c : _vect)
		{
			delete c;
			c = nullptr;
		}
	}
public:
	static TableContainer& instance();
	void load(const std::string& path);

	template<typename T>
	const T& get_table() const
	{
		for (auto c : _vect)
		{
			if (typeid(T) == typeid(*c))
			{
				return (const T&)*c;
			}
		}
		// -- we never should get here since we store everything
		LOG_FATAL << "WOOOW WOOOOOOOOOOW CALM YOU TITS";
		T t;
		return t;
	}
private:
	std::vector<google::protobuf::Message*> _vect;
};

#define sTBL TableContainer::instance()