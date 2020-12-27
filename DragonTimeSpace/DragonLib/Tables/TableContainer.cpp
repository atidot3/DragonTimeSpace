#include "TableContainer.h"

#include <Utils/Logger/Logger.h>

#include <string>
#include <iostream>
#include <string.h>
#include <stdio.h>

#include <fcntl.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <io.h>  
#include <algorithm>
#include <fstream>

#include <boost/regex.hpp>


#undef max

TableContainer& TableContainer::instance()
{
	static TableContainer tbContainer;
	return tbContainer;
}

void TableContainer::load(const std::string& path)
{
	_vect.push_back(new pb::pathway());
	_vect.push_back(new pb::adventure_copymap());
	_vect.push_back(new pb::attribute_config());
	_vect.push_back(new pb::allaction());
	_vect.push_back(new pb::avatar_config());
	_vect.push_back(new pb::battle_config());
	_vect.push_back(new pb::building_data());
	_vect.push_back(new pb::carddata_config());
	_vect.push_back(new pb::cardeffect_config());
	_vect.push_back(new pb::careerLv());
	_vect.push_back(new pb::charstate());
	_vect.push_back(new pb::chatchannel());
	_vect.push_back(new pb::convenient());
	_vect.push_back(new pb::coordinates_arena_config());
	_vect.push_back(new pb::copymapEvent());
	_vect.push_back(new pb::copymapinfo());
	_vect.push_back(new pb::copymapmaster());
	_vect.push_back(new pb::cutscene());
	_vect.push_back(new pb::devicesetting());
	_vect.push_back(new pb::dialogueconfig());
	_vect.push_back(new pb::dnachip_config());
	_vect.push_back(new pb::dnaslot_config());
	_vect.push_back(new pb::dynamictext());
	_vect.push_back(new pb::entanglement_config());
	_vect.push_back(new pb::equips());
	_vect.push_back(new pb::equip_suffix());
	_vect.push_back(new pb::esc_config());
	_vect.push_back(new pb::event_config());
	_vect.push_back(new pb::evolution_config());
	_vect.push_back(new pb::faceconfig());
	_vect.push_back(new pb::gene_remake());
	_vect.push_back(new pb::growtarget_config());
	_vect.push_back(new pb::guide());
	_vect.push_back(new pb::heropanel_maximum());
	_vect.push_back(new pb::heros());
	_vect.push_back(new pb::illegalword());
	_vect.push_back(new pb::key());
	_vect.push_back(new pb::levelconfig());
	_vect.push_back(new pb::loadingtips());
	_vect.push_back(new pb::looksconfig());
	_vect.push_back(new pb::manufacture());
	_vect.push_back(new pb::namepool());
	_vect.push_back(new pb::newUser());
	_vect.push_back(new pb::npc_data());
	_vect.push_back(new pb::objects());
	_vect.push_back(new pb::pathway());
	_vect.push_back(new pb::player_level_config());
	_vect.push_back(new pb::questconfig());
	_vect.push_back(new pb::quizdataConfig());
	_vect.push_back(new pb::rankpk_level());
	_vect.push_back(new pb::relation_tbx());
	_vect.push_back(new pb::reward_level());
	_vect.push_back(new pb::runeConfig());
	_vect.push_back(new pb::screensetting());
	_vect.push_back(new pb::seventarget_config());
	_vect.push_back(new pb::skillshow());
	_vect.push_back(new pb::skill_data());
	_vect.push_back(new pb::skill_guild());
	_vect.push_back(new pb::skill_stage());
	_vect.push_back(new pb::summonpet());
	_vect.push_back(new pb::summonpetLevelUp());
	_vect.push_back(new pb::survey_config());
	_vect.push_back(new pb::teleport());
	_vect.push_back(new pb::textconfig());
	_vect.push_back(new pb::uimapinfo());
	_vect.push_back(new pb::unlock_config());
	_vect.push_back(new pb::vipcard_config());
	_vect.push_back(new pb::fetters_config());

	for (auto& c : _vect)
	{
		std::string final_name(typeid(*c).name());
		boost::regex reg("::?(.*)");
		boost::smatch what;
		if (boost::regex_search(final_name, what, reg, boost::match_default))
		{
			std::filebuf fb;
			const std::string file(path + what[1] + ".tbx");
			std::fstream input(file, std::ios::in | std::ios::binary);

			if (input.is_open())
			{

				if (c->ParseFromIstream(&input))
				{
					LOG_DEBUG << file << " loaded";
				}
				fb.close();
			}
			else
			{
				throw std::runtime_error("Unable to parse: " + final_name);
			}
		}
	}
}