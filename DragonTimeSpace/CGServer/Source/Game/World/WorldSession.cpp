#include "WorldSession.h"
#include "Map/map.h"

#include "../../Network/CGSocket.h"

#include <Utils/Logger/Logger.h>
#include <Database/Repository/RepositoryManager.h>
#include <Configuration/Configuration.h>

#include <Network/Packet/Char/Char.h>
#include <Network/Messages/CommandID.h>
#include <Network/Packet/ProtobufPacket.h>
#include <Network/Messages/ParseProto.h>

#include <Tables/TableContainer.h>

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
			if (it->level() == 1)
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
	ProtobufPacket<msg::AttributeData> attrData(CommandID::RetCommonError_SC);
	{
		attrData.get_protobuff().set_hp(evolution->maxhp());
		attrData.get_protobuff().set_maxhp(evolution->maxhp());
		attrData.get_protobuff().set_mdef(evolution->mdef());
		attrData.get_protobuff().set_pdef(evolution->pdef());
		attrData.get_protobuff().set_bang(evolution->bang());
		attrData.get_protobuff().set_bangextradamage(evolution->bangextradamage());
		attrData.get_protobuff().set_toughness(evolution->toughness());
		attrData.get_protobuff().set_toughnessreducedamage(evolution->toughnessreducedamage());
		attrData.get_protobuff().set_penetrate(evolution->penetrate());
		attrData.get_protobuff().set_hit(evolution->hit());
		attrData.get_protobuff().set_penetrateextradamage(evolution->penetrateextradamage());
		attrData.get_protobuff().set_block(evolution->block());
		attrData.get_protobuff().set_blockreducedamage(evolution->blockreducedamage());
		attrData.get_protobuff().set_accurate(evolution->accurate());
		attrData.get_protobuff().set_accurateextradamage(evolution->accurateextradamage());
		attrData.get_protobuff().set_hold(evolution->hold());
		attrData.get_protobuff().set_holdreducedamage(evolution->holdreducedamage());
		attrData.get_protobuff().set_deflect(evolution->deflect());
		attrData.get_protobuff().set_deflectreducedamage(evolution->deflectreducedamage());

		attrData.get_protobuff().set_mp(10);
		attrData.get_protobuff().set_maxmp(10);
		attrData.get_protobuff().set_str(0);
		attrData.get_protobuff().set_dex(10);
		attrData.get_protobuff().set_intel(10);
		attrData.get_protobuff().set_phy(10);
		attrData.get_protobuff().set_matt(10);
		attrData.get_protobuff().set_patt(10);
		attrData.get_protobuff().set_dodge(0);
		attrData.get_protobuff().set_weaponatt(0);
		attrData.get_protobuff().set_firemastery(0);
		attrData.get_protobuff().set_icemastery(10);
		attrData.get_protobuff().set_lightningmastery(10);
		attrData.get_protobuff().set_brightmastery(10);
		attrData.get_protobuff().set_darkmastery(10);
		attrData.get_protobuff().set_fireresist(10);
		attrData.get_protobuff().set_iceresist(10);
		attrData.get_protobuff().set_lightningresist(10);
		attrData.get_protobuff().set_brightresist(10);
		attrData.get_protobuff().set_darkresist(10);
		attrData.get_protobuff().set_firepen(10);
		attrData.get_protobuff().set_icepen(10);
		attrData.get_protobuff().set_lightningpen(10);
		attrData.get_protobuff().set_brightpen(10);
		attrData.get_protobuff().set_darkpen(10);
		attrData.get_protobuff().set_blowint(10);
		attrData.get_protobuff().set_knockint(10);
		attrData.get_protobuff().set_floatint(10);
		attrData.get_protobuff().set_superhitint(10);
		attrData.get_protobuff().set_blowresist(10);
		attrData.get_protobuff().set_knockresist(10);
		attrData.get_protobuff().set_floatresist(10);
		attrData.get_protobuff().set_superhitresist(10);
		attrData.get_protobuff().set_blowdectime(10);
		attrData.get_protobuff().set_knockdectime(10);
		attrData.get_protobuff().set_floatdectime(10);
		attrData.get_protobuff().set_superhitdectime(10);
		attrData.get_protobuff().set_stiffaddtime(10);
		attrData.get_protobuff().set_stiffdectime(10);
	}
	ProtobufPacket<msg::CharacterBaseData> charBase(CommandID::RetCommonError_SC);
	{
		charBase.get_protobuff().set_exp(result->getUInt("CurrentExp"));
		charBase.get_protobuff().set_welpoint(result->getUInt("Welpoint"));
		charBase.get_protobuff().set_money(result->getUInt("Money"));
		charBase.get_protobuff().set_stone(result->getUInt("Stone"));
		charBase.get_protobuff().set_tilizhi(result->getUInt("Tilizhi"));
		charBase.get_protobuff().set_type(msg::MapDataType::MAP_DATATYPE_USER);
		charBase.get_protobuff().set_famelevel(50);
		charBase.get_protobuff().set_position(0);
		charBase.get_protobuff().set_viplevel(1);
		charBase.get_protobuff().set_port(0);
		charBase.get_protobuff().set_laststage(0);
		charBase.get_protobuff().set_nextexp(level->levelupexp());
		charBase.get_protobuff().set_pkmode(msg::PKMode::PKMode_Normal);
		charBase.get_protobuff().set_edupoint(result->getUInt("Edupoint"));
		charBase.get_protobuff().set_cooppoint(result->getUInt("Cooppoint"));
		charBase.get_protobuff().set_bluecrystal(result->getUInt("Bluecrystal"));
		charBase.get_protobuff().set_purplecrystal(result->getUInt("Purplecrystal"));
		charBase.get_protobuff().set_vigourpoint(result->getUInt("Vigourpoint"));
		charBase.get_protobuff().set_doublepoint(result->getUInt("Doublepoint"));
		charBase.get_protobuff().set_bluecrystalincnum(result->getUInt("Bluecrystalincnum"));
		charBase.get_protobuff().set_purplecrystalincnum(result->getUInt("Purplecrystalincnum"));
		charBase.get_protobuff().set_familyatt(0);
		charBase.get_protobuff().set_herothisid(std::to_string(hero->tbxid()));
	}
	ProtobufPacket<msg::CharacterMapData> mapdata(CommandID::RetCommonError_SC);
	{
		mapdata.get_protobuff().set_hp(evolution->maxhp());
		mapdata.get_protobuff().set_maxhp(evolution->maxhp());
		mapdata.get_protobuff().set_level(result->getUInt("CurrentLevel"));

		mapdata.get_protobuff().set_allocated_pos(&pos);
		mapdata.get_protobuff().set_movespeed(120);
		mapdata.get_protobuff().set_country(1);

		mapdata.get_protobuff().set_dir(180);
	}
	ProtobufPacket<msg::CharacterMapShow> mapshow(CommandID::RetCommonError_SC);
	{
		mapshow.get_protobuff().set_weapon(0);
		mapshow.get_protobuff().set_heroid(hero->tbxid());
		mapshow.get_protobuff().set_avatarid(hero->newavatar());
		mapshow.get_protobuff().set_occupation(msg::Occupation::Occu_Yaohu);
		mapshow.get_protobuff().set_hairstyle(result->getUInt("Hairstyle"));
		mapshow.get_protobuff().set_haircolor(result->getUInt("Haircolor"));
		mapshow.get_protobuff().set_facestyle(result->getUInt("Facestyle"));
		mapshow.get_protobuff().set_bodystyle(0);
		mapshow.get_protobuff().set_antenna(result->getUInt("Antenna"));
	}
	ProtobufPacket<msg::CharacterFightData> fightBase(CommandID::RetCommonError_SC);
	{
		fightBase.get_protobuff().set_curfightvalue(1000);
	}
	ProtobufPacket<msg::MapUserData> mapBase(CommandID::RetCommonError_SC);
	{
		mapBase.get_protobuff().set_charid(result->getUInt("CharacterID"));
		mapBase.get_protobuff().set_name(result->getString("Name"));

		mapBase.get_protobuff().set_allocated_mapdata(&mapdata.get_protobuff());
		mapBase.get_protobuff().set_allocated_mapshow(&mapshow.get_protobuff());
		mapBase.get_protobuff().set_allocated_bakhero(&mapshow.get_protobuff());
	}
	ProtobufPacket<msg::CharacterMainData> charMain(CommandID::RetCommonError_SC);
	{
		charMain.get_protobuff().set_allocated_attridata(&attrData.get_protobuff());
		charMain.get_protobuff().set_allocated_basedata(&charBase.get_protobuff());
		charMain.get_protobuff().set_allocated_fightdata(&fightBase.get_protobuff());
		charMain.get_protobuff().set_allocated_mapdata(&mapBase.get_protobuff());
	}
	ProtobufPacket<msg::MSG_DataCharacterMain_SC> pktMain(CommandID::DataCharacterMain_SC);
	{
		pktMain.get_protobuff().set_allocated_data(&charMain.get_protobuff());

		pktMain.compute();

		SendPacket(pktMain.get_buffer());
	}

	// -- do_fucking_matter
	{
		mapBase.get_protobuff().release_bakhero();
		mapBase.get_protobuff().release_mapdata();
		mapBase.get_protobuff().release_mapshow();

		charMain.get_protobuff().release_attridata();
		charMain.get_protobuff().release_basedata();
		charMain.get_protobuff().release_fightdata();
		charMain.get_protobuff().release_mapdata();

		mapInfo.get_protobuff().release_pos();
		mapdata.get_protobuff().release_pos();

		pktMain.get_protobuff().release_data();
	}

	auto skills = ProtobufPacket<magic::MSG_RetRefreshSkill_SC>(CommandID::RetRefreshSkill_SC);
	auto skill = skills.get_protobuff().add_skills();

	skill->set_skillid(100101);
	skill->set_active_stages(100101);
	skill->set_lastupdatetime(1);
	skill->set_lastusetime(1000);
	skill->set_level(1);
	skill->set_maxmultitimes(0);
	skill->set_onoff(1);
	skill->set_overlaytimes(1);
	skill->set_skillcd(1000);
	
	skills.compute();
	SendPacket(skills.get_buffer());

	ProtobufPacket<msg::MSG_Ret_MapScreenBatchRefreshNpc_SC> npc_info(CommandID::Ret_MapScreenBatchRefreshNpc_SC);
	{
		auto const_map = sMapMgr.get_map(result->getUInt("MapID"));
		auto const_map_info = const_map.get_map_info();

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
					msg::EntryIDType myType;
					{
						myType.set_id(is_ou_npc.id());
						myType.set_type(msg::MapDataType::MAP_DATATYPE_NPC);
					}
					msg::MasterData master;
					{
						//master.set_country(1);
						//master.set_allocated_idtype(&myType);
						//master.set_name(std::move(std::string(is_ou_npc.name())));
						//master.set_teamid(0);
					}
					msg::CharacterMapShow cmshow;
					{
						//cmshow.set_avatarid(80);
						//cmshow.set_heroid(80);
						//cmshow.set_occupation(1);
					}
					msg::NPC_HatredList list;
					{
						// -- what am i doing
						if (is_ou_npc.hatred_distance() > 0)
						{
							list.add_enemytempid(is_ou_npc.id());
						}
						else
						{
							list.set_npctempid(is_ou_npc.id());
						}
					}

					auto npcs = npc_info.get_protobuff().add_data();
					npcs->set_tempid(const_npc.id);
					npcs->set_allocated_hatredlist(&list);
					npcs->set_allocated_master(&master);
					npcs->set_allocated_pos(pos);
					npcs->set_allocated_showdata(&cmshow);
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

		for (auto npcs = npc_info.get_protobuff().mutable_data()->begin(); npcs != npc_info.get_protobuff().mutable_data()->end(); ++npcs)
		{
			npcs->release_hatredlist();
			npcs->release_master();
			//npcs->release_pos();
			npcs->release_showdata();
		}
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
	hero.get_protobuff().set_herothisid(71001);

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

	team.get_protobuff().set_id(70022);
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
		pack.get_protobuff().set_hero_baseid(70022);
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

	ProtobufPacket<msg::AttributeData> attrData(CommandID::RetCommonError_SC);
	{
		attrData.get_protobuff().set_hp(10);
		attrData.get_protobuff().set_maxhp(10);
		attrData.get_protobuff().set_mp(10);
		attrData.get_protobuff().set_maxmp(10);
		attrData.get_protobuff().set_str(10);
		attrData.get_protobuff().set_dex(10);
		attrData.get_protobuff().set_intel(10);
		attrData.get_protobuff().set_phy(10);
		attrData.get_protobuff().set_matt(10);
		attrData.get_protobuff().set_patt(10);
		attrData.get_protobuff().set_mdef(10);
		attrData.get_protobuff().set_pdef(10);
		attrData.get_protobuff().set_bang(10);
		attrData.get_protobuff().set_bangextradamage(10);
		attrData.get_protobuff().set_toughness(10);
		attrData.get_protobuff().set_toughnessreducedamage(10);
		attrData.get_protobuff().set_penetrate(10);
		attrData.get_protobuff().set_hit(10);
		attrData.get_protobuff().set_penetrateextradamage(10);
		attrData.get_protobuff().set_block(10);
		attrData.get_protobuff().set_blockreducedamage(10);
		attrData.get_protobuff().set_accurate(10);
		attrData.get_protobuff().set_accurateextradamage(10);
		attrData.get_protobuff().set_hold(10);
		attrData.get_protobuff().set_holdreducedamage(10);
		attrData.get_protobuff().set_deflect(10);
		attrData.get_protobuff().set_deflectreducedamage(10);
		attrData.get_protobuff().set_dodge(10);
		attrData.get_protobuff().set_weaponatt(10);
		attrData.get_protobuff().set_firemastery(10);
		attrData.get_protobuff().set_icemastery(10);
		attrData.get_protobuff().set_lightningmastery(10);
		attrData.get_protobuff().set_brightmastery(10);
		attrData.get_protobuff().set_darkmastery(10);
		attrData.get_protobuff().set_fireresist(10);
		attrData.get_protobuff().set_iceresist(10);
		attrData.get_protobuff().set_lightningresist(10);
		attrData.get_protobuff().set_brightresist(10);
		attrData.get_protobuff().set_darkresist(10);
		attrData.get_protobuff().set_firepen(10);
		attrData.get_protobuff().set_icepen(10);
		attrData.get_protobuff().set_lightningpen(10);
		attrData.get_protobuff().set_brightpen(10);
		attrData.get_protobuff().set_darkpen(10);
		attrData.get_protobuff().set_blowint(10);
		attrData.get_protobuff().set_knockint(10);
		attrData.get_protobuff().set_floatint(10);
		attrData.get_protobuff().set_superhitint(10);
		attrData.get_protobuff().set_blowresist(10);
		attrData.get_protobuff().set_knockresist(10);
		attrData.get_protobuff().set_floatresist(10);
		attrData.get_protobuff().set_superhitresist(10);
		attrData.get_protobuff().set_blowdectime(10);
		attrData.get_protobuff().set_knockdectime(10);
		attrData.get_protobuff().set_floatdectime(10);
		attrData.get_protobuff().set_superhitdectime(10);
		attrData.get_protobuff().set_stiffaddtime(10);
		attrData.get_protobuff().set_stiffdectime(10);

		attrData.compute();
	}

	ProtobufPacket<msg::MSG_RetHeroAttributeData_SC> attr(CommandID::RetHeroAttributeData_SC);
	{

		attr.get_protobuff().set_allocated_data(&attrData.get_protobuff());
		attr.get_protobuff().set_fightvalue(10000);
	}

	attr.compute();
	SendPacket(attr.get_buffer());

	attr.get_protobuff().release_data();


	return true;
}

bool WorldSession::onReceiveDNABagInfo(const Packet& packet)
{
	LOG_DEBUG << "onReceiveDNABagInfo";

	auto req = ProtobufPacket<hero::MSG_AllDnaPageInfo_CSC>(packet);

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
	SendPacket(res.get_buffer());

	return true;
}

bool WorldSession::onReceiveVisitNpcTrade(const Packet& packet)
{
	LOG_DEBUG << "onReceiveVisitNpcTrade";

	auto req = ProtobufPacket<quest::MSG_Req_VisitNpcTrade_CS>(packet);

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
	SendPacket(res.get_buffer());

	return true;
}

bool WorldSession::onReceiveAllDNAPageInfo(const Packet& packet)
{
	LOG_DEBUG << "onReceiveAllDNAPageInfo";

	auto req = ProtobufPacket<hero::MSG_DnaBagInfo_CSC>(packet);

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
	SendPacket(res.get_buffer());

	return true;
}

bool WorldSession::onReceiveRefreshRadar(const Packet& packet)
{
	LOG_DEBUG << "onReceiveRefreshRadar";

	auto req = ProtobufPacket<mobapk::MSG_RefreshRadarPos_CSC>(packet);

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
	SendPacket(res.get_buffer());
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

	res.compute();
	SendPacket(res.get_buffer());
	return true;
}


bool WorldSession::onReceiveEntrySelectState(const Packet& packet)
{
	LOG_DEBUG << "onReceiveEntrySelectState";

	auto req = ProtobufPacket<msg::MSG_ReqEntrySelectState_CS>(packet);

	LOG_DEBUG << req.get_protobuff().DebugString();
	ProtobufPacket<msg::MSG_RetEntrySelectState_SC> res(CommandID::RetEntrySelectState_SC);
	{
		auto it = res.get_protobuff().add_states();
		//res.get_protobuff().set_allocated_choosen(&req.get_protobuff().oldone());
	}

	res.compute();
	SendPacket(res.get_buffer());
	return true;
}

bool WorldSession::onReceiveSetChooseTarget(const Packet& packet)
{
	LOG_DEBUG << "onReceiveSetChooseTarget";

	auto req = ProtobufPacket<msg::MSG_SetChooseTarget_CS>(packet);

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
	SendPacket(res.get_buffer());
	return true;
}

bool WorldSession::onReceiveOfflineChat(const Packet& packet)
{
	//TODO: Make Offline Chat save handler and loader for this function	
	ProtobufPacket<Chat::MSG_Ret_OfflineChat_SC> chat(CommandID::Ret_OfflineChat_SC);

	auto it = chat.get_protobuff().add_datas();
	chat.compute();

	SendPacket(chat.get_buffer());
	return true;
}


bool WorldSession::onReceiveOperateDatasReq(const Packet& packet)
{
	auto req = ProtobufPacket<apprentice::MSG_Req_OperateClientDatas_CS>(packet);

	LOG_DEBUG << "OperateData request: key[" << req.get_protobuff().key() << "] op[" << req.get_protobuff().op() << "] retcode[" << req.get_protobuff().retcode() << "] type[" << req.get_protobuff().type() << "]";

	ProtobufPacket<apprentice::MSG_Req_OperateClientDatas_CS> opdat(CommandID::Req_OperateClientDatas_CS);
	//known keys for opdats
	/*
		storage_Shortcuts,
		storage_ChatTab,
		storage_CharacterBottom,
		storage_UISkillIndex,
		storage_GenePageName,
		storage_SystemData,
		storage_ShortKey_Config,
		storage_SkillSlotSort,
		storage_FRIEND_IDS,
		storage_AbattoirShortcuts,
		storage_AutoFight
	*/
	//Opcodes are as follows
	/*
		DeleteAll,
		AddUpdate,
		Delete,
		Get
	*/
	opdat.get_protobuff().set_key(req.get_protobuff().key());
	opdat.get_protobuff().set_op(req.get_protobuff().op());
	opdat.get_protobuff().set_retcode(req.get_protobuff().retcode());
	opdat.get_protobuff().set_type(req.get_protobuff().type());
	opdat.get_protobuff().set_value(req.get_protobuff().value());
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
