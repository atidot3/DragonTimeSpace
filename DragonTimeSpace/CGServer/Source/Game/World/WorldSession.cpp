#include "WorldSession.h"
#include "Map/MapManager.h"

#include "../../Network/CGSocket.h"

#include <Utils/Logger/Logger.h>
#include <Database/Repository/RepositoryManager.h>
#include <Configuration/Configuration.h>

#include <Network/Packet/Char/Char.h>
#include <Network/Messages/CommandID.h>
#include <Network/Packet/ProtobufPacket.h>
#include <Network/Messages/ParseProto.h>

#include <Tables/TableContainer.h>

uint32_t skill_id;

//----------------------------------------
//	WorldSession constructor
//	This class handle all data related to the player
//----------------------------------------
WorldSession::WorldSession(Socket* gameSock, std::function<void()> destruct_handler)
	: _account_id{ 0 }
	, _socket{ gameSock }
	//, _player{ nullptr }
	, _firstLogging{ true }
	, _ip{ "" }
	, methodList{}
	, _destruct_handler{ destruct_handler }
{
	// -- unsafe packet
	{
		methodList.emplace(CommandID::Req_Back_to_Select_CS, std::make_tuple(std::bind(&WorldSession::onReceiveReturnToChar, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::SetChooseTarget_CS, std::make_tuple(std::bind(&WorldSession::onReceiveSetChooseTarget, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::TeamMemeberList_CS, std::make_tuple(std::bind(&WorldSession::onReceiveTeamMemberReq, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::ReqCardPackInfo_CS, std::make_tuple(std::bind(&WorldSession::onReceiveCardPackInfo, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::ReqHeroAttributeData_CS, std::make_tuple(std::bind(&WorldSession::onReceiveMyHeroAttrData, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::DnaBagInfo_CSC, std::make_tuple(std::bind(&WorldSession::onReceiveDNABagInfo, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::AllDnaPageInfo_CSC, std::make_tuple(std::bind(&WorldSession::onReceiveAllDNAPageInfo, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::Req_VisitNpcTrade_CS, std::make_tuple(std::bind(&WorldSession::onReceiveVisitNpcTrade, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::RefreshRadarPos_CSC, std::make_tuple(std::bind(&WorldSession::onReceiveRefreshRadar, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::ReqMapQuestInfo_CS, std::make_tuple(std::bind(&WorldSession::onReceiveRefreshMapQuestInfo, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::ReqEntrySelectState_CS, std::make_tuple(std::bind(&WorldSession::onReceiveEntrySelectState, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::Req_MagicAttack_CS, std::make_tuple(std::bind(&WorldSession::onRecieveSyncSkillStage, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
		methodList.emplace(CommandID::Req_SyncSkillStage_CS, std::make_tuple(std::bind(&WorldSession::onReceiveMagicAttack, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));

		// -- Chat
		methodList.emplace(CommandID::Req_Chat_CS, std::make_tuple(std::bind(&WorldSession::onRecieveChat, this, std::placeholders::_1), THREAD_METHOD::THREAD_UNSAFE));
	}
	// -- safe packet
	{
		methodList.emplace(CommandID::SetMainHero_CSC, std::make_tuple(std::bind(&WorldSession::onReceiveMainHero, this, std::placeholders::_1), THREAD_METHOD::THREAD_SAFE));
		methodList.emplace(CommandID::Notify_SceneLoaded_CS, std::make_tuple(std::bind(&WorldSession::onSceneLoaded, this, std::placeholders::_1), THREAD_METHOD::THREAD_SAFE));
		methodList.emplace(CommandID::Req_OperateClientDatas_CS, std::make_tuple(std::bind(&WorldSession::onReceiveOperateDatasReq, this, std::placeholders::_1), THREAD_METHOD::THREAD_SAFE));
		methodList.emplace(CommandID::BlackList_CSC, std::make_tuple(std::bind(&WorldSession::onReceiveBlacklist, this, std::placeholders::_1), THREAD_METHOD::THREAD_SAFE));
		methodList.emplace(CommandID::NEW_ROLE_CUTSCENE_SCS, std::make_tuple(std::bind(&WorldSession::onNewRoleCutScene, this, std::placeholders::_1), THREAD_METHOD::THREAD_SAFE));

		methodList.emplace(CommandID::Req_OfflineChat_CS, std::make_tuple(std::bind(&WorldSession::onReceiveOfflineChat, this, std::placeholders::_1), THREAD_METHOD::THREAD_SAFE));
		methodList.emplace(CommandID::Req_MailList_CS, std::make_tuple(std::bind(&WorldSession::onReceiveMailList, this, std::placeholders::_1), THREAD_METHOD::THREAD_SAFE));
	}
}
//----------------------------------------
//	WorldSession destructor
//	This is responsive to remove player propely
//----------------------------------------
WorldSession::~WorldSession()
{
	_socket = nullptr;
	LOG_TRACE << "WorldSession destructed";
}
//----------------------------------------
//	Trigger at socket close
//----------------------------------------
void WorldSession::OnDisconnect()
{
	_socket = nullptr;
}

//----------------------------------------
//	Process our packet safe / unsafe way
//----------------------------------------
void WorldSession::ProcessUnSafe()
{
	Packet packet;
	_packets.pop(packet);

	char_packet* p = (char_packet*)packet.GetPacketData();

	auto it = methodList.find(p->CMD);
	if (it != methodList.end())
	{
		std::function<bool(const Packet&)> _method = std::get<0>(it->second);
		THREAD_METHOD thr = std::get<1>(it->second);

		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

		if (_method(packet) == false)
		{
			// ?
		}

		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		const auto elapsedDurationMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		const auto elapsedDurationS = std::chrono::duration_cast<std::chrono::seconds> (end - begin).count();

		if (elapsedDurationMS > 500)
		{
			LOG_WARNING << "Packet: " << std::string(GetPacketName(p->CMD));
			LOG_DEBUG << "Time difference = " << elapsedDurationMS << " ms";
			LOG_DEBUG << "Time difference = " << elapsedDurationS << " s";
		}
	}
}

bool WorldSession::_ProcessGamePacket(const Packet& packet)
{
	char_packet* p = (char_packet*)packet.GetPacketData();

	auto it = methodList.find(p->CMD);
	if (it != methodList.end())
	{
		std::function<bool(const Packet&)> _method = std::get<0>(it->second);
		THREAD_METHOD thr = std::get<1>(it->second);

		switch (thr)
		{
		case THREAD_METHOD::THREAD_UNSAFE:
		{
			/*if (_player && _player->GetMap())
			{
				_packets.push(std::move(packet));
				_player->GetMap()->GetStrand().post([t = shared_from_this()]
					{
						t->ProcessUnSafe();
					});
			}*/
			// -- to remove
			if (_method(packet) == false)
			{
				// ?
			}
			break;
		}
		case THREAD_METHOD::THREAD_SAFE:
		{
			std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

			if (_method(packet) == false)
			{
				// ?
			}

			std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
			const auto elapsedDurationMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
			const auto elapsedDurationS = std::chrono::duration_cast<std::chrono::milliseconds> (end - begin).count();

			if (elapsedDurationMS > 500)
			{
				LOG_WARNING << "Packet: " << std::string(GetPacketName(p->CMD));
				LOG_DEBUG << "Time difference = " << elapsedDurationMS << " ms";
				LOG_DEBUG << "Time difference = " << elapsedDurationS << " s";
			}

			break;
		}
		}
		return true;
	}
	else
	{
		LOG_WARNING << "Get an unexpected Game packet: [" << std::string(GetPacketName(p->CMD)) << "]";
		return false;
	}
}

//----------------------------------------
//	WorldSession kick the player from our server
//----------------------------------------
void WorldSession::Kick()
{
	if (_socket && !_socket->IsClosed())
		_socket->Close();
}
//----------------------------------------
//	WorldSession retrive our player account id
//----------------------------------------
const uint32_t& WorldSession::GetAccountID() const
{
	return _account_id;
}
//----------------------------------------
//	WorldSession create the player data before sending it to the world
//----------------------------------------
bool WorldSession::CreatePlayer(const uint32_t& char_id)
{
	msg::FloatMovePos pos;

	auto hero_table = sTBL.get_table<pb::heros>();
	auto avatar_table = sTBL.get_table<pb::avatar_config>();
	auto evolution_table = sTBL.get_table<pb::evolution_config>();
	auto level_table = sTBL.get_table<pb::levelconfig>();

	const pb::heros_t_hero_config* hero = nullptr;
	const pb::evolution_config_t_evolution_config* evolution = nullptr;
	const pb::avatar_config_t_avatar_config* avatar = nullptr;
	const pb::levelconfig_t_level_config* level = nullptr;


	// -- mysql select

	bool ret = false;
	auto result = sQueryRepository.GetCGServerRepository().GetCharacterByCharId(char_id, ret);
	if (!ret)
	{
		LOG_FATAL << "query were null: " << char_id;
		auto error = ProtobufPacket<msg::MSG_Ret_Common_Error_SC>(CommandID::Ret_Common_Error_SC);
		{
			error.get_protobuff().set_errorcode(msg::LoginRetCode::LOGIN_RETURN_DB);
			error.compute();
			SendPacket(error.get_buffer());
			return false;
		}
	}
	if (result->rowsCount() <= 0)
	{
		LOG_FATAL << "Unable to retreive characterid: " << char_id;
		auto error = ProtobufPacket<msg::MSG_Ret_Common_Error_SC>(CommandID::Ret_Common_Error_SC);
		{
			error.get_protobuff().set_errorcode(msg::LoginRetCode::LOGIN_RETURN_DB);
			error.compute();
			SendPacket(error.get_buffer());
			return false;
		}
	}
	result->next();

	// this->player = new std::make_shared<Player>([...]);

	for (auto it = hero_table.datas().begin(); it != hero_table.datas().end(); ++it)
	{
		if (it->id() == result->getUInt("HeroID"))
		{
			hero = &(*it);
		}
	}
	if (hero != nullptr)
	{
		for (auto it = avatar_table.datas().begin(); it != avatar_table.datas().end(); ++it)
			if (it->id() == hero->newavatar())
			{
				avatar = &(*it);
				break;
			}

		for (auto it = evolution_table.datas().begin(); it != evolution_table.datas().end(); ++it)
		{
			if (it->avatar() == hero->newavatar() || std::abs(int(it->avatar() - hero->newavatar())) <= 3)
			{
				evolution = &(*it);
				break;
			}
		}

		for (auto it = level_table.datas().begin(); it != level_table.datas().end(); ++it)
			if (it->level() == result->getUInt("CurrentLevel"))
			{
				level = &(*it);
				break;
			}
	}

	if (hero == nullptr || evolution == nullptr || avatar == nullptr || level == nullptr)
	{
		LOG_FATAL << "One table were null";
		auto error = ProtobufPacket<msg::MSG_Ret_Common_Error_SC>(CommandID::Ret_Common_Error_SC);
		{
			error.get_protobuff().set_errorcode(msg::LoginRetCode::LOGIN_RETURN_DB);
			error.compute();
			SendPacket(error.get_buffer());
		}
		return false;
	}

	skill_id = hero->normalskill();

	pos.set_fx(result->getFloat("Position_X"));
	pos.set_fy(result->getFloat("Position_Y"));

	ProtobufPacket<msg::MSG_Ret_UserMapInfo_SC> mapInfo(CommandID::Ret_UserMapInfo_SC);
	{
		mapInfo.get_protobuff().set_mapid(result->getUInt("MapID"));
		mapInfo.get_protobuff().set_lineid(sConfig.GetGameServerServerId());
		mapInfo.get_protobuff().set_sceneid(0);
		mapInfo.get_protobuff().set_allocated_pos(&pos);
		mapInfo.get_protobuff().set_copymapidx(0);
		mapInfo.get_protobuff().set_subcopymapidx(0);

		mapInfo.compute();

		SendPacket(mapInfo.get_buffer());
	}

	//Set Main Char
	msg::AttributeData* attrData = new msg::AttributeData();
	{
		attrData->set_hp(evolution->maxhp());
		attrData->set_maxhp(evolution->maxhp());
		attrData->set_mdef(evolution->mdef());
		attrData->set_pdef(evolution->pdef());
		attrData->set_bang(evolution->bang());
		attrData->set_bangextradamage(evolution->bangextradamage());
		attrData->set_toughness(evolution->toughness());
		attrData->set_toughnessreducedamage(evolution->toughnessreducedamage());
		attrData->set_penetrate(evolution->penetrate());
		attrData->set_hit(evolution->hit());
		attrData->set_penetrateextradamage(evolution->penetrateextradamage());
		attrData->set_block(evolution->block());
		attrData->set_blockreducedamage(evolution->blockreducedamage());
		attrData->set_accurate(evolution->accurate());
		attrData->set_accurateextradamage(evolution->accurateextradamage());
		attrData->set_hold(evolution->hold());
		attrData->set_holdreducedamage(evolution->holdreducedamage());
		attrData->set_deflect(evolution->deflect());
		attrData->set_deflectreducedamage(evolution->deflectreducedamage());

		attrData->set_mp(10);
		attrData->set_maxmp(10);
		attrData->set_str(0);
		attrData->set_dex(10);
		attrData->set_intel(10);
		attrData->set_phy(10);
		attrData->set_matt(10);
		attrData->set_patt(10);
		attrData->set_dodge(0);
		attrData->set_weaponatt(0);
		attrData->set_firemastery(0);
		attrData->set_icemastery(10);
		attrData->set_lightningmastery(10);
		attrData->set_brightmastery(10);
		attrData->set_darkmastery(10);
		attrData->set_fireresist(10);
		attrData->set_iceresist(10);
		attrData->set_lightningresist(10);
		attrData->set_brightresist(10);
		attrData->set_darkresist(10);
		attrData->set_firepen(10);
		attrData->set_icepen(10);
		attrData->set_lightningpen(10);
		attrData->set_brightpen(10);
		attrData->set_darkpen(10);
		attrData->set_blowint(10);
		attrData->set_knockint(10);
		attrData->set_floatint(10);
		attrData->set_superhitint(10);
		attrData->set_blowresist(10);
		attrData->set_knockresist(10);
		attrData->set_floatresist(10);
		attrData->set_superhitresist(10);
		attrData->set_blowdectime(10);
		attrData->set_knockdectime(10);
		attrData->set_floatdectime(10);
		attrData->set_superhitdectime(10);
		attrData->set_stiffaddtime(10);
		attrData->set_stiffdectime(10);
	}
	msg::CharacterBaseData* charBase = new msg::CharacterBaseData();
	{
		charBase->set_exp(result->getUInt("CurrentExp"));
		charBase->set_welpoint(result->getUInt("Welpoint"));
		charBase->set_money(result->getUInt("Money"));
		charBase->set_stone(result->getUInt("Stone"));
		charBase->set_tilizhi(result->getUInt("Tilizhi"));
		charBase->set_type(msg::MapDataType::MAP_DATATYPE_USER);
		charBase->set_famelevel(0);
		charBase->set_position(0);
		charBase->set_viplevel(1);
		charBase->set_port(0);
		charBase->set_laststage(msg::StageType::None_Stage);
		charBase->set_nextexp(level->levelupexp());
		charBase->set_pkmode(msg::PKMode::PKMode_Normal);
		charBase->set_edupoint(result->getUInt("Edupoint"));
		charBase->set_cooppoint(result->getUInt("Cooppoint"));
		charBase->set_bluecrystal(result->getUInt("Bluecrystal"));
		charBase->set_purplecrystal(result->getUInt("Purplecrystal"));
		charBase->set_vigourpoint(result->getUInt("Vigourpoint"));
		charBase->set_doublepoint(result->getUInt("Doublepoint"));
		charBase->set_bluecrystalincnum(result->getUInt("Bluecrystalincnum"));
		charBase->set_purplecrystalincnum(result->getUInt("Purplecrystalincnum"));
		charBase->set_familyatt(0);
		charBase->set_herothisid(std::to_string(hero->tbxid()));
	}
	msg::CharacterMapData* mapdata = new msg::CharacterMapData();
	{
		mapdata->set_hp(evolution->maxhp());
		mapdata->set_maxhp(evolution->maxhp());
		mapdata->set_level(result->getUInt("CurrentLevel"));

		mapdata->set_allocated_pos(&pos);
		mapdata->set_movespeed(120);
		mapdata->set_country(1);

		mapdata->set_dir(180);
	}
	msg::CharacterMapShow* mapshow = new msg::CharacterMapShow();
	{
		mapshow->set_weapon(0);
		mapshow->set_heroid(hero->tbxid());
		mapshow->set_avatarid(hero->newavatar());
		mapshow->set_occupation(msg::Occupation::Occu_Yaohu);
		mapshow->set_hairstyle(result->getUInt("Hairstyle"));
		mapshow->set_haircolor(result->getUInt("Haircolor"));
		mapshow->set_facestyle(result->getUInt("Facestyle"));
		mapshow->set_bodystyle(0);
		mapshow->set_antenna(result->getUInt("Antenna"));
	}
	msg::CharacterFightData* fightBase = new msg::CharacterFightData();
	{
		fightBase->set_curfightvalue(1000);
	}
	msg::MapUserData* mapBase = new msg::MapUserData();
	{
		mapBase->set_charid(result->getUInt("CharacterID"));
		mapBase->set_name(result->getString("Name"));

		mapBase->set_allocated_mapdata(mapdata);
		mapBase->set_allocated_mapshow(mapshow);
		mapBase->set_allocated_bakhero(mapshow);
	}
	msg::CharacterMainData *charMain = new msg::CharacterMainData();
	{
		charMain->set_allocated_attridata(attrData);
		charMain->set_allocated_basedata(charBase);
		charMain->set_allocated_fightdata(fightBase);
		charMain->set_allocated_mapdata(mapBase);
	}
	ProtobufPacket<msg::MSG_DataCharacterMain_SC> pktMain(CommandID::DataCharacterMain_SC);
	{
		pktMain.get_protobuff().set_allocated_data(charMain);

		pktMain.compute();

		SendPacket(pktMain.get_buffer());
	}

	// -- do_fucking_matter
	{
		mapdata->release_pos();
		mapBase->release_bakhero();
		mapInfo.get_protobuff().release_pos();
	}

	hero::HeroAvatar *heroavatar = new hero::HeroAvatar();
	{
		heroavatar->add_avatars(hero->newavatar());
		heroavatar->set_activeavatar(hero->newavatar());
	}
	ProtobufPacket<hero::MSG_NotifyAllHeros_SC> notifyHero(CommandID::NotifyAllHeros_SC);
	{
		auto it = notifyHero.get_protobuff().add_heroinfo();
		it->set_baseid(hero->tbxid());
		it->set_thisid(std::to_string(hero->tbxid()));
		it->set_self_created(true);
		it->set_exp(result->getUInt("CurrentExp"));
		it->set_level(result->getUInt("CurrentLevel"));
		it->set_score(0);
		it->set_allocated_avatar(heroavatar);
	}
	notifyHero.compute();
	SendPacket(notifyHero.get_buffer());

	/*auto skills = ProtobufPacket<magic::MSG_RetRefreshSkill_SC>(CommandID::RetRefreshSkill_SC);
	{
		const std::list<uint32_t> _storage_skills = { 100101, 100102,100103,100104,100105,100106,100107,100108,100109,100110,100112,100113, 100114 };
		for (auto& c : _storage_skills)
		{
			auto skill = skills.get_protobuff().add_skills();
			skill->set_skillid(c);
			skill->set_active_stages(0);
			skill->set_lastupdatetime(0);
			skill->set_lastusetime(0);
			skill->set_level(1);
			skill->set_maxmultitimes(0);
			skill->set_onoff(0);
			skill->set_overlaytimes(0);
			skill->set_skillcd(0);
		}
		skills.compute();
		SendPacket(skills.get_buffer());
	}*/

	auto career_skill = ProtobufPacket<career::MSG_RetCareerSkillInfo_SC>(CommandID::RetCareerSkillInfo_SC);
	{
		career::CareerSkillInfo info;

		/*const std::vector<uint32_t> _storage_skills = { 100101, 100102,100103,100104,100105,100106,100107,100108,100109,100110,100112,100113, 100114 };
		for (int i = 0; i < _storage_skills.size(); ++i)
		{
			auto line_skill = info.add_curskills();
			line_skill->set_line(i);
			line_skill->set_skill(_storage_skills.at(i));
		}*/

		magic::SkillData _allocated_skill;
		auto unlock_skill = info.add_unlockskills();
		{
			_allocated_skill.set_skillid(skill_id);
			_allocated_skill.set_active_stages(0);
			_allocated_skill.set_lastupdatetime(0);
			_allocated_skill.set_lastusetime(0);
			_allocated_skill.set_level(1);
			_allocated_skill.set_maxmultitimes(0);
			_allocated_skill.set_onoff(0);
			_allocated_skill.set_overlaytimes(0);
			_allocated_skill.set_skillcd(0);
		}

		unlock_skill->set_allocated_skill(&_allocated_skill);
		career_skill.get_protobuff().set_allocated_skillinfo(&info);
		career_skill.compute();
		unlock_skill->release_skill();
		career_skill.get_protobuff().release_skillinfo();
		SendPacket(career_skill.get_buffer());
	}

	ProtobufPacket<msg::MSG_Ret_MapScreenBatchRefreshNpc_SC> npc_info(CommandID::Ret_MapScreenBatchRefreshNpc_SC);
	{
		auto const_map = sMapMgr.get_map(result->getUInt("MapID"));
		auto const_map_info = const_map->get_map_info();

		auto npc = sTBL.get_table<pb::npc_data>();
		for (auto& is_ou_npc : npc.datas())
		{
			for (auto& const_npc : const_map_info._npc)
			{
				if (is_ou_npc.tbxid() == const_npc.id)
				{
					msg::FloatMovePos* pos = new msg::FloatMovePos();
					{
						pos->set_fx(const_npc.x);
						pos->set_fy(const_npc.y);
					}
					msg::EntryIDType* myType = new msg::EntryIDType();
					{
						myType->set_id(is_ou_npc.id());
						myType->set_type(msg::MapDataType::MAP_DATATYPE_NPC);
					}
					msg::MasterData* master = new msg::MasterData();
					{
						//master.set_country(1);
						//master.set_allocated_idtype(&myType);
						//master.set_name(std::move(std::string(is_ou_npc.name())));
						//master.set_teamid(0);
					}
					msg::CharacterMapShow* cmshow = new msg::CharacterMapShow();
					{
						//cmshow.set_avatarid(80);
						//cmshow.set_heroid(80);
						//cmshow.set_occupation(1);
					}
					msg::NPC_HatredList* list = new msg::NPC_HatredList();
					{
						// -- what am i doing
						if (is_ou_npc.hatred_distance() > 0)
						{
							list->add_enemytempid(is_ou_npc.id());
						}
						else
						{
							list->set_npctempid(is_ou_npc.id());
						}
					}

					auto npcs = npc_info.get_protobuff().add_data();
					npcs->set_tempid(const_npc.id);
					npcs->set_allocated_hatredlist(list);
					npcs->set_allocated_master(master);
					npcs->set_allocated_pos(pos);
					npcs->set_allocated_showdata(cmshow);
					npcs->set_attspeed(0);
					npcs->set_baseid(const_npc.id);
					npcs->set_birth(false);
					npcs->set_dir(const_npc.dir);
					npcs->set_hp(is_ou_npc.maxhp());
					npcs->set_maxhp(is_ou_npc.maxhp());
					npcs->set_movespeed(0);
					npcs->set_name(std::move(std::string(is_ou_npc.name())));
					//npcs->set_titlename();
					npcs->set_visit(0);
				}
			}
		}

		npc_info.compute();
		SendPacket(npc_info.get_buffer());
	}

	auto lines = ProtobufPacket<msg::MSG_NoticeClientAllLines_SC>(CommandID::NoticeClientAllLines_SC);
	{
		lines.get_protobuff().set_your_line(sConfig.GetGameServerServerId());

		/*
			SELECT * FROM REAMLIST;
		for (int i = 0; i < 3; ++i)
		{
			auto other_lines = lines.get_protobuff().add_lines();
			other_lines->set_index(i);
			other_lines->set_user_num(0);

		}
		*/
		lines.compute();
		SendPacket(lines.get_buffer());
	}

	return true;
}

bool WorldSession::onReceiveMainHero(const Packet& packet)
{
	LOG_DEBUG << "onReceiveMainHero";

	auto _hero = ProtobufPacket<hero::MSG_SetMainHero_CSC>(packet);
	ProtobufPacket<hero::MSG_SetMainHero_CSC> hero(CommandID::SetMainHero_CSC);

	LOG_DEBUG << _hero.get_protobuff().DebugString();

	hero.get_protobuff().set_errorcode(_hero.get_protobuff().errorcode());
	hero.get_protobuff().set_opcode(_hero.get_protobuff().opcode());
	hero.get_protobuff().set_herothisid(hero.get_protobuff().herothisid());

	hero.compute();
	
	SendPacket(hero.get_buffer());

	return true;
}

bool WorldSession::onSceneLoaded(const Packet& packet)
{
	LOG_DEBUG << "on scene loaded request received";

	return true;
}

bool WorldSession::onNewRoleCutScene(const Packet& packet)
{
	LOG_DEBUG << "on new role scenecut request received";

	auto req = ProtobufPacket<msg::MSG_Create_Role_CS>(packet);
	// This make infinit looping cutscene
	/*auto res = ProtobufPacket<msg::MSG_START_CUTSCENE_SC>(CommandID::NEW_ROLE_CUTSCENE_SCS);
	{
		res.get_protobuff().set_cutsceneid(req.cutsceneid());
		res.get_protobuff().set_onfinish(std::move(std::string(req.onfinish())));
	}
	res.compute();
	SendPacket(res.get_buffer());*/

	return true;
}

bool WorldSession::onReceiveTeamMemberReq(const Packet& packet)
{
	LOG_DEBUG << "onReceiveTeamMemberReq";

	ProtobufPacket<Team::MSG_TeamMemeberList_SC> team(CommandID::TeamMemeberList_SC);
	auto _team = ProtobufPacket<Team::MSG_TeamMemeberList_CS>(packet);

	LOG_DEBUG << _team.get_protobuff().DebugString();

	team.get_protobuff().set_id(70024);
	team.get_protobuff().set_curmember(0);

	team.compute();

	SendPacket(team.get_buffer());

	return true;
}

bool WorldSession::onReceiveCardPackInfo(const Packet& packet)
{
	LOG_DEBUG << "onReceiveCardPackInfo";

	auto req = ProtobufPacket<Obj::MSG_ReqCardPackInfo_CS>(packet);
	
	LOG_DEBUG << req.get_protobuff().DebugString();

	ProtobufPacket<Obj::CardPackInfo> pack(CommandID::RetCommonError_SC);
	{
		pack.get_protobuff().set_earth_opened_num(0);
		pack.get_protobuff().set_fire_opened_num(0);
		pack.get_protobuff().set_gold_opened_num(0);
		pack.get_protobuff().set_hero_baseid(70024);
		pack.get_protobuff().set_water_opened_num(0);
		pack.get_protobuff().set_wood_opened_num(0);

		pack.compute();
	}

	ProtobufPacket<Obj::MSG_RetCardPackInfo_SC > res(CommandID::RetCardPackInfo_SC);
	{
		res.get_protobuff().set_allocated_data(&pack.get_protobuff());
	}
	res.compute();
	SendPacket(res.get_buffer());

	res.get_protobuff().release_data();
	return true;
}

bool WorldSession::onReceiveMyHeroAttrData(const Packet& packet)
{
	LOG_DEBUG << "onReceiveMyHeroAttrData";

	auto req = ProtobufPacket<msg::MSG_ReqHeroAttributeData_CS>(packet);

	LOG_DEBUG << req.get_protobuff().DebugString();

	msg::AttributeData* attrData = new msg::AttributeData();
	{
		attrData->set_hp(10);
		attrData->set_maxhp(10);
		attrData->set_mp(10);
		attrData->set_maxmp(10);
		attrData->set_str(10);
		attrData->set_dex(10);
		attrData->set_intel(10);
		attrData->set_phy(10);
		attrData->set_matt(10);
		attrData->set_patt(10);
		attrData->set_mdef(10);
		attrData->set_pdef(10);
		attrData->set_bang(10);
		attrData->set_bangextradamage(10);
		attrData->set_toughness(10);
		attrData->set_toughnessreducedamage(10);
		attrData->set_penetrate(10);
		attrData->set_hit(10);
		attrData->set_penetrateextradamage(10);
		attrData->set_block(10);
		attrData->set_blockreducedamage(10);
		attrData->set_accurate(10);
		attrData->set_accurateextradamage(10);
		attrData->set_hold(10);
		attrData->set_holdreducedamage(10);
		attrData->set_deflect(10);
		attrData->set_deflectreducedamage(10);
		attrData->set_dodge(10);
		attrData->set_weaponatt(10);
		attrData->set_firemastery(10);
		attrData->set_icemastery(10);
		attrData->set_lightningmastery(10);
		attrData->set_brightmastery(10);
		attrData->set_darkmastery(10);
		attrData->set_fireresist(10);
		attrData->set_iceresist(10);
		attrData->set_lightningresist(10);
		attrData->set_brightresist(10);
		attrData->set_darkresist(10);
		attrData->set_firepen(10);
		attrData->set_icepen(10);
		attrData->set_lightningpen(10);
		attrData->set_brightpen(10);
		attrData->set_darkpen(10);
		attrData->set_blowint(10);
		attrData->set_knockint(10);
		attrData->set_floatint(10);
		attrData->set_superhitint(10);
		attrData->set_blowresist(10);
		attrData->set_knockresist(10);
		attrData->set_floatresist(10);
		attrData->set_superhitresist(10);
		attrData->set_blowdectime(10);
		attrData->set_knockdectime(10);
		attrData->set_floatdectime(10);
		attrData->set_superhitdectime(10);
		attrData->set_stiffaddtime(10);
		attrData->set_stiffdectime(10);
	}

	ProtobufPacket<msg::MSG_RetHeroAttributeData_SC> attr(CommandID::RetHeroAttributeData_SC);
	{
		attr.get_protobuff().set_allocated_data(attrData);
		attr.get_protobuff().set_fightvalue(10000);
		attr.get_protobuff().set_herothisid(std::move(std::string("70024")));
	}

	attr.compute();
	SendPacket(attr.get_buffer());

	return true;
}

bool WorldSession::onReceiveDNABagInfo(const Packet& packet)
{
	LOG_DEBUG << "onReceiveDNABagInfo";

	/*auto req = ProtobufPacket<hero::MSG_AllDnaPageInfo_CSC>(packet);

	LOG_DEBUG << req.get_protobuff().DebugString();
	ProtobufPacket<hero::MSG_AllDnaPageInfo_CSC> res(CommandID::AllDnaPageInfo_CSC);
	{
		auto it = res.get_protobuff().add_pages();
		it->set_page(hero::DNAPage::PAGE1);
		auto attHoles = it->add_att_holes();
		it->set_att_opened_num(0);
		it->add_def_holes();
		it->set_def_opened_num(0);
	}

	res.compute();
	SendPacket(res.get_buffer());*/

	return true;
}

bool WorldSession::onReceiveVisitNpcTrade(const Packet& packet)
{
	LOG_DEBUG << "onReceiveVisitNpcTrade";

	/*auto req = ProtobufPacket<quest::MSG_Req_VisitNpcTrade_CS>(packet);

	LOG_DEBUG << req.get_protobuff().DebugString();
	ProtobufPacket<quest::MSG_Ret_VisitNpcTrade_SC> res(CommandID::Ret_VisitNpcTrade_SC);
	{

		for (int i = 0; i < req.get_protobuff().allcrc().size(); i++)
		{
			auto it = res.get_protobuff().add_allcrc();
			it->set_branch_id(req.get_protobuff().allcrc().Get(i).branch_id());
			it->set_quest_id(req.get_protobuff().allcrc().Get(i).quest_id());
			it->set_crc(req.get_protobuff().allcrc().Get(i).crc());
		}
		res.get_protobuff().set_action(0);
		res.get_protobuff().set_type(msg::MapDataType::MAP_DATATYPE_NPC);
		res.get_protobuff().set_npc_temp_id(req.get_protobuff().npc_temp_id());
		res.get_protobuff().set_show_type(0);
	}

	res.compute();
	SendPacket(res.get_buffer());*/

	return true;
}

bool WorldSession::onReceiveAllDNAPageInfo(const Packet& packet)
{
	LOG_DEBUG << "onReceiveAllDNAPageInfo";

	/*auto req = ProtobufPacket<hero::MSG_DnaBagInfo_CSC>(packet);

	LOG_DEBUG << req.get_protobuff().DebugString();
	ProtobufPacket<hero::MSG_DnaBagInfo_CSC> res(CommandID::DnaBagInfo_CSC);
	{
		auto it = res.get_protobuff().add_datas();
		it->set_id(100101);
		it->set_level(1);
		it->set_num(1);
		res.get_protobuff().set_cur_page(hero::DNAPage::PAGE1);
	}

	res.compute();
	SendPacket(res.get_buffer());*/

	return true;
}

bool WorldSession::onReceiveRefreshRadar(const Packet& packet)
{
	LOG_DEBUG << "onReceiveRefreshRadar";

	/*auto req = ProtobufPacket<mobapk::MSG_RefreshRadarPos_CSC>(packet);

	LOG_DEBUG << req.get_protobuff().DebugString();
	ProtobufPacket<mobapk::MSG_RefreshRadarPos_CSC> res(CommandID::RefreshRadarPos_CSC);
	{
		auto it = res.get_protobuff().add_pos();
		it->set_num(0);
		it->set_uid(70022);
		it->set_x(200);
		it->set_y(200);
	}

	res.compute();
	SendPacket(res.get_buffer());*/
	return true;
}

bool WorldSession::onReceiveRefreshMapQuestInfo(const Packet& packet)
{
	LOG_DEBUG << "onReceiveRefreshMapQuestInfo";

	auto req = ProtobufPacket<quest::MSG_ReqMapQuestInfo_CS>(packet);

	LOG_DEBUG << req.get_protobuff().DebugString();
	ProtobufPacket<quest::MSG_RetMapQuestInfo_SC> res(CommandID::RetMapQuestInfo_SC);
	{
		auto it = res.get_protobuff().add_npclists();
	}
	
	return true;
}


bool WorldSession::onReceiveEntrySelectState(const Packet& packet)
{
	LOG_DEBUG << "onReceiveEntrySelectState";

	/*auto req = ProtobufPacket<msg::MSG_ReqEntrySelectState_CS>(packet);

	LOG_DEBUG << req.get_protobuff().DebugString();
	ProtobufPacket<msg::MSG_RetEntrySelectState_SC> res(CommandID::RetEntrySelectState_SC);
	{
		auto it = res.get_protobuff().add_states();
		//res.get_protobuff().set_allocated_choosen(&req.get_protobuff().oldone());
	}

	res.compute();
	SendPacket(res.get_buffer());*/
	return true;
}

bool WorldSession::onReceiveSetChooseTarget(const Packet& packet)
{
	LOG_DEBUG << "onReceiveSetChooseTarget";

	/*auto req = ProtobufPacket<msg::MSG_SetChooseTarget_CS>(packet);

	LOG_DEBUG << req.get_protobuff().DebugString();
	ProtobufPacket<msg::MSG_AttackTargetChange_SC> res(CommandID::AttackTargetChange_SC);
	{
		res.get_protobuff().set_choosetype(req.get_protobuff().choosetype());
		res.get_protobuff().set_charid(req.get_protobuff().charid());
		res.get_protobuff().set_hp(0);
		res.get_protobuff().set_level(1);
		res.get_protobuff().set_relation(0);
		//res.get_protobuff().set_name("");
	}

	res.compute();
	SendPacket(res.get_buffer());*/
	return true;
}

bool WorldSession::onReceiveOfflineChat(const Packet& packet)
{
	//TODO: Make Offline Chat save handler and loader for this function	
	/*ProtobufPacket<Chat::MSG_Ret_OfflineChat_SC> chat(CommandID::Ret_OfflineChat_SC);

	auto it = chat.get_protobuff().add_datas();
	chat.compute();

	SendPacket(chat.get_buffer());*/
	return true;
}

bool WorldSession::onReceiveOperateDatasReq(const Packet& packet)
{
	auto req = ProtobufPacket<apprentice::MSG_Req_OperateClientDatas_CS>(packet);

	LOG_DEBUG << "OperateData request: key[" << req.get_protobuff().key() << "] op[" << req.get_protobuff().op() << "] retcode[" << req.get_protobuff().retcode() << "] type[" << req.get_protobuff().type() << "]";
	LOG_DEBUG << req.get_protobuff().value();
	ProtobufPacket<apprentice::MSG_Req_OperateClientDatas_CS> opdat(CommandID::Req_OperateClientDatas_CS);
	//known keys for opdats
	/*
		storage_Shortcuts,
		storage_ChatTab, => custom chat tab name / configs (composed as: NAME_id-id-id,NAME_id,)
		storage_CharacterBottom,
		storage_UISkillIndex, => 70024&1:0"|2:0|3:0|4:0|5:0|6:0|7:0|8:0|9:0|10:0|11:0|12:0
		storage_GenePageName,
		storage_SystemData,
		storage_ShortKey_Config, => are shortcut as Z to walk forward, space jump etc
		storage_SkillSlotSort,
		storage_FRIEND_IDS,
		storage_AbattoirShortcuts,
		storage_AutoFight
	*/
	//Opcodes are as follows
	/*
		DeleteAll = 0,
		AddUpdate = 1,
		Delete = 2,
		Get = 3
	*/

	opdat.get_protobuff().set_key(req.get_protobuff().key());
	opdat.get_protobuff().set_op(req.get_protobuff().op());
	opdat.get_protobuff().set_retcode(req.get_protobuff().retcode());
	opdat.get_protobuff().set_type(req.get_protobuff().type());
	opdat.get_protobuff().set_value(req.get_protobuff().value());

	if (opdat.get_protobuff().key() == "ShortKey_Config" && req.get_protobuff().op() == 3)
	{
	/*	LOG_DEBUG << "Testing atidote azerty keyboard";
		opdat.get_protobuff().set_value(std::move(std::string("{\"0\":{\"key\":\"99\"},\"1\":{\"key\":\"107\"},\"2\":{\"key\":\"\"},\"3\":{\"key\":\"98\"},\"4\":{\"key\":\"108\"},\"5\":{\"key\":\"103\"},\"6\":{\"key\":\"117\"},\"7\":{\"key\":\"106\"},\"8\":{\"key\":\"111\"},\"9\":{\"key\":\"109\"},\"11\":{\"key\":\"122\"},\"12\":{\"key\":\"115\"},\"13\":{\"key\":\"113\"},\"14\":{\"key\":\"100\"},\"15\":{\"key\":\"32\"},\"16\":{\"key\":\"9\"},\"17\":{\"key\":\"304,49\"},\"18\":{\"key\":\"304,50\"},\"19\":{\"key\":\"304,51\"},\"20\":{\"key\":\"304,52\"},\"21\":{\"key\":\"96\"},\"22\":{\"key\":\"101\"},\"23\":{\"key\":\"119\"},\"24\":{\"key\":\"306,290\"},\"25\":{\"key\":\"306,291\"},\"26\":{\"key\":\"306,288\"},\"27\":{\"key\":\"306,289\"},\"28\":{\"key\":\"306,292\"},\"101\":{\"key\":\"282\"},\"102\":{\"key\":\"283\"},\"103\":{\"key\":\"284\"},\"104\":{\"key\":\"285\"},\"105\":{\"key\":\"286\"},\"106\":{\"key\":\"287\"},\"107\":{\"key\":\"288\"},\"108\":{\"key\":\"289\"},\"109\":{\"key\":\"290\"},\"110\":{\"key\":\"291\"},\"111\":{\"key\":\"292\"},\"112\":{\"key\":\"293\"},\"201\":{\"key\":\"\"},\"202\":{\"key\":\"\"},\"203\":{\"key\":\"\"},\"204\":{\"key\":\"\"},\"205\":{\"key\":\"\"},\"206\":{\"key\":\"\"},\"207\":{\"key\":\"\"},\"208\":{\"key\":\"\"},\"209\":{\"key\":\"\"},\"210\":{\"key\":\"\"},\"211\":{\"key\":\"\"},\"212\":{\"key\":\"\"},\"301\":{\"key\":\"\"},\"302\":{\"key\":\"\"},\"303\":{\"key\":\"\"},\"304\":{\"key\":\"\"},\"305\":{\"key\":\"\"},\"306\":{\"key\":\"\"},\"307\":{\"key\":\"\"},\"308\":{\"key\":\"\"},\"309\":{\"key\":\"\"},\"310\":{\"key\":\"\"},\"311\":{\"key\":\"\"},\"312\":{\"key\":\"\"},\"401\":{\"key\":\"\"},\"402\":{\"key\":\"\"},\"403\":{\"key\":\"\"},\"404\":{\"key\":\"\"},\"405\":{\"key\":\"\"},\"406\":{\"key\":\"\"},\"407\":{\"key\":\"\"},\"408\":{\"key\":\"\"},\"409\":{\"key\":\"\"},\"410\":{\"key\":\"\"},\"411\":{\"key\":\"\"},\"412\":{\"key\":\"\"},\"501\":{\"key\":\"49\"},\"502\":{\"key\":\"50\"},\"503\":{\"key\":\"51\"},\"504\":{\"key\":\"52\"},\"505\":{\"key\":\"53\"},\"506\":{\"key\":\"54\"},\"507\":{\"key\":\"55\"},\"508\":{\"key\":\"56\"},\"509\":{\"key\":\"57\"},\"510\":{\"key\":\"48\"},\"511\":{\"key\":\"45\"},\"512\":{\"key\":\"61\"},\"513\":{\"key\":\"\"}}")));
		*/
	}
	else if (opdat.get_protobuff().key() == "ShortKey_Config" && req.get_protobuff().op() == 1)
	{
		// this is working but we dont need to execute it for now
		/*Query query("UPDATE `shortcuts` SET `shortcut` = '?' WHERE `AccountId` = '?'");
		query.setValue(req.get_protobuff().value());
		query.setValue(_account_id);
		sDB.DirectExecute(query.GetQuery());*/
	}
	else if (opdat.get_protobuff().key().find("ChatTab") != std::string::npos && req.get_protobuff().op() == 3)
	{
		opdat.get_protobuff().set_value(std::move(std::string("All_1-2-3-4-5-6-10,Party_2,")));
	}
	else if (opdat.get_protobuff().key() == "storage_1_SkillSlotSort70024" && req.get_protobuff().op() == 3)
	{
		opdat.get_protobuff().set_value(std::move(std::string("70024&1:"+std::to_string(skill_id )+"|2:0|3:0|4:0|5:0|6:0|7:0|8:0|9:0|10:0|11:0|12:0")));
	}

	opdat.compute();

	SendPacket(opdat.get_buffer());
	return true;
}


bool WorldSession::onReceiveMailList(const Packet& packet)
{
	auto _mail = ProtobufPacket<mail::MSG_Req_MailList_CS>(packet);
	ProtobufPacket<mail::MSG_Ret_MailList_SC> mail(CommandID::Ret_MailList_SC);

	LOG_DEBUG << _mail.get_protobuff().DebugString();

	auto it = mail.get_protobuff().add_items();
	it->set_createtime("0");
	it->set_deltime("9999999");
	it->set_fromname("Jesus");
	it->set_mailid("0");
	it->set_state(0);
	it->set_text("This is a gift to you atidot3");
	it->set_title("To Ati from Jesus");


	mail.compute();

	SendPacket(mail.get_buffer());
	return true;
}

bool WorldSession::onReceiveBlacklist(const Packet& packet)
{
	LOG_DEBUG << "Dont forget to do this one dumb doggo";
	return true;
}

bool WorldSession::onReceiveReturnToChar(const Packet& packet)
{
	//Save Character when returning to char select

	bool ret;
	auto result = sQueryRepository.GetCGServerRepository().GetCharacterlistByAccountId(_account_id, ret);
	if (!ret)
	{
		LOG_FATAL << "Query error";
		return false;
	}

	ProtobufPacket<msg::MSG_Ret_LoginOnReturnCharList_SC> characterList(CommandID::Ret_LoginOnReturnCharList_SC);
	while (result->next())
	{
		auto it = characterList.get_protobuff().add_charlist();
		it->set_charid(result->getUInt("CharacterID"));
		it->set_level(result->getUInt("CurrentLevel"));
		it->set_sex((msg::SEX)result->getByte("Gender"));
		it->set_heroid(result->getUInt("HeroID"));
		it->set_curheroid(result->getUInt("HeroID"));
		it->set_facestyle(result->getUInt("Facestyle"));
		it->set_haircolor(result->getUInt("Haircolor"));
		it->set_hairstyle(result->getUInt("Hairstyle"));
		it->set_antenna(result->getUInt("Antenna"));
		it->set_avatarid(result->getUInt("AvatarID"));
		it->set_mapname(std::move(std::string("Time and space city")));
		it->set_name(std::move(std::string(result->getString("Name"))));
	}

	characterList.compute();
	SendPacket(characterList.get_buffer());

	// -- call delete this
	_destruct_handler();

	return true;
}

bool WorldSession::onRecieveChat(const Packet& packet)
{
	LOG_DEBUG << "onRecieveChat";

	auto _chat = ProtobufPacket<Chat::MSG_Req_Chat_CS>(packet);
	msg::FloatMovePos pos;

	LOG_DEBUG << _chat.get_protobuff().DebugString();
	ProtobufPacket<Chat::MSG_Ret_Chat_SC> chat(CommandID::Ret_Chat_SC);
	Chat::ChatData data = _chat.get_protobuff().data();
	chat.get_protobuff().set_allocated_data(&data);

	chat.compute();

	SendPacket(chat.get_buffer());
	chat.get_protobuff().release_data();
	return true;
}

bool WorldSession::onRecieveSyncSkillStage(const Packet& packet)
{
	LOG_DEBUG << "onRecieveSyncSkillStage";
	auto _sync_skill = ProtobufPacket<magic::MSG_Req_SyncSkillStage_CS>(packet);

	return true;
}
bool WorldSession::onReceiveMagicAttack(const Packet& packet)
{
	LOG_DEBUG << "onReceiveMagicAttack";
	auto _magic_skill = ProtobufPacket<magic::MSG_Req_MagicAttack_CS>(packet);

	msg::EntryIDType* att = new msg::EntryIDType();
	{
		att->set_id(_magic_skill.get_protobuff().target().id());
		att->set_type(_magic_skill.get_protobuff().target().type());
	}
	auto _magic_skill_res = ProtobufPacket<magic::MSG_Ret_MagicAttack_SC>(CommandID::Ret_MagicAttack_SC);
	{
		auto pkresult = _magic_skill_res.get_protobuff().add_pklist();
		{
			msg::EntryIDType* att2 = new msg::EntryIDType();
			{
				att2->set_id(_magic_skill.get_protobuff().target().id());
				att2->set_type(_magic_skill.get_protobuff().target().type());
			}
			pkresult->add_attcode(magic::ATTACKRESULT::ATTACKRESULT_HIT);
			pkresult->set_changehp(100);
			pkresult->set_hp(500);
			pkresult->set_allocated_def(att2);
			pkresult->set_attcode(0, magic::ATTACKRESULT::ATTACKRESULT_HIT);
		}
		_magic_skill_res.get_protobuff().set_attdir(_magic_skill.get_protobuff().attdir());
		_magic_skill_res.get_protobuff().set_desx(_magic_skill.get_protobuff().desx());
		_magic_skill_res.get_protobuff().set_desy(_magic_skill.get_protobuff().desy());
		_magic_skill_res.get_protobuff().set_skillstage(0);
		_magic_skill_res.get_protobuff().set_userdir(_magic_skill.get_protobuff().userdir());
		
		_magic_skill_res.get_protobuff().set_allocated_def(att);
		msg::EntryIDType* att3 = new msg::EntryIDType();
		{
			att3->set_id(1);
			att3->set_type(msg::MapDataType::MAP_DATATYPE_USER);
		}
		_magic_skill_res.get_protobuff().set_allocated_att(att3);
	}
	_magic_skill_res.compute();
	_magic_skill_res.get_protobuff().release_def();
	SendPacket(_magic_skill_res.get_buffer());


	//auto start_attack = ProtobufPacket<magic::MSG_Ret_StartMagicAttack_SC>(CommandID::Ret_StartMagicAttack_SC);
	//{
	//	start_attack.get_protobuff().set_skillid(skill_id);
	//	start_attack.get_protobuff().set_attdir(_magic_skill.get_protobuff().attdir());
	//	start_attack.get_protobuff().set_desx(_magic_skill.get_protobuff().desx());
	//	start_attack.get_protobuff().set_desy(_magic_skill.get_protobuff().desy());
	//	start_attack.get_protobuff().set_allocated_att(att);
	//	start_attack.get_protobuff().set_userdir(_magic_skill.get_protobuff().userdir());
	//}
	//start_attack.compute();
	//SendPacket(start_attack.get_buffer());
	//start_attack.get_protobuff().release_att();

	return true;
}