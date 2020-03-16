#include "CharSocket.h"

#include <Network/Packet/Packet.h>
#include <Network/Packet/ProtobufPacket.h>
#include <Network\Packet\Char\Char.h>
//#include <Utils/Opcodes.h>
//#include <Utils/ResultCode.h>
#include <Utils/Logger/Logger.h>
#include <Utils\Utils.h>

#include <Configuration\Configuration.h>
#include <Database\Repository\RepositoryManager.h>
#include <Configuration\Configuration.h>

#include <Network/Messages/ParseProto.h>

//----------------------------------------
//	Called when we open the socket
//----------------------------------------
CharSocket::CharSocket(boost::asio::io_context &service)
	: Socket{ service }
{
	methodList.emplace_back(CommandID::UserVerifyVerCmd_CS, std::bind(&CharSocket::onCheckGatewayVer, this, std::placeholders::_1));
	methodList.emplace_back(CommandID::IphoneLoginUserCmd_CS, std::bind(&CharSocket::onReceiveUserInfo, this, std::placeholders::_1));

	methodList.emplace_back(CommandID::SetMainHero_CSC, std::bind(&CharSocket::onReceiveMainHero, this, std::placeholders::_1));
	methodList.emplace_back(CommandID::Notify_SceneLoaded_CS, std::bind(&CharSocket::onSceneLoaded, this, std::placeholders::_1));
	methodList.emplace_back(CommandID::Create_Role_CS, std::bind(&CharSocket::onReceiveCharCreate, this, std::placeholders::_1));
	methodList.emplace_back(CommandID::TeamMemeberList_CS, std::bind(&CharSocket::onReceiveTeamMemberReq, this, std::placeholders::_1));
	methodList.emplace_back(CommandID::Req_SelectCharToLogin_CS, std::bind(&CharSocket::onSelectCharToLogin, this, std::placeholders::_1));

	// debug test
	//methodList.emplace_back(2273, std::bind(&CharSocket::onReceiveProtobuf, this, std::placeholders::_1));
}

//----------------------------------------
//	Called when we open the socket
//----------------------------------------
CharSocket::~CharSocket()
{
	LOG_TRACE << "CharSocket connection close: [" << GetRemoteEndPoint() << "]";
}
void CharSocket::OnConnected()
{
	LOG_DEBUG << "New Connection from: " << this->GetAddress();
}

//----------------------------------------
//	We got incomming data from our player
//	Return false in case we was not able to parse data
//	Set internalError = ResultCodes::RESULT_FAIL in case of something unexpected to kick the connection
//----------------------------------------
bool CharSocket::ProcessIncomingData(const Packet& packet)
{
	char_packet* p = (char_packet*)packet.GetPacketData();
	LOG_WARNING << "Get packet: command type [" << GetPacketName(p->CMD) << "]";
	for (const auto& method : methodList)
	{
		if (std::get<0>(method) == p->CMD)
		{
			auto _method = std::get<1>(method);
			_method(packet);
			return true;
		}
	}
	LOG_WARNING << "Get an unexpected packet: [" << GetPacketName(p->CMD) << "]";
	internalError = 1000;
	return false;
}

bool CharSocket::onCheckGatewayVer(const Packet& packet)
{
	LOG_DEBUG << "Received gateway check version";

	gateway_version* data = (gateway_version*)packet.GetPacketData();
	LOG_DEBUG << "version : " << data->version;

	return true;
}

template<class T>
void fill_my_data(T& t, const unsigned char* data, const WORD& size)
{
	MessageBuffer buffer;
	buffer.Resize(size - 8);
	buffer.Write(&data[8], size - 8);

	bool isOk = ParseProtoMsg<T>((const char*)buffer.GetReadPointer(), (size - 8), t);
}

void log_data(const unsigned char* data, const int32_t& size)
{
	std::cout << std::hex << std::setfill('0');  // needs to be set only once
	auto* ptr = data;
	for (int i = 0; i < size; i++, ptr++)
	{
		std::cout << std::setw(2) << static_cast<unsigned>(*ptr) << " ";
	}
	std::cout << std::endl;
}

bool CharSocket::onReceiveUserInfo(const Packet& packet)
{
	LOG_DEBUG << "MSG_Ret_LoginOnReturnCharList_SC";

	ProtobufPacket<msg::MSG_Ret_LoginOnReturnCharList_SC> characterList(CommandID::Ret_LoginOnReturnCharList_SC);

	auto it = characterList.get_protobuff().add_charlist();
	it->set_charid(70022);
	it->set_level(1);
	it->set_sex(msg::SEX::FEMALE);
	it->set_heroid(70022);
	it->set_curheroid(70022);
	it->set_facestyle(49);
	it->set_haircolor(116);
	it->set_hairstyle(45);
	it->set_avatarid(4001);
	it->set_mapname(std::move(std::string("Time and space city")));
	it->set_name(std::move(std::string("Sangawku")));

	characterList.compute();
	LOG_DEBUG << "MSG_Ret_LoginOnReturnCharList_SC packet to send HEX: ";
	characterList.log_data();

	ms_Write(characterList.get_buffer());

	return true;
}

bool CharSocket::onReceiveCharCreate(const Packet& packet)
{
	LOG_DEBUG << "NEW_ROLE_CUTSCENE_SCS";

	msg::MSG_Create_Role_CS _hero;
	msg::FloatMovePos pos;

	fill_my_data(_hero, (unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);
	pos.set_fx(801.f);
	pos.set_fy(908.f);

	ProtobufPacket<msg::MSG_Ret_UserMapInfo_SC> mapInfo(CommandID::Ret_UserMapInfo_SC);
	{
		mapInfo.get_protobuff().set_mapid(695);
		mapInfo.get_protobuff().set_filename(std::move(std::string("Pc_sgc")));
		mapInfo.get_protobuff().set_mapname(std::move(std::string("Time and space city")));
		mapInfo.get_protobuff().set_lineid(0);
		mapInfo.get_protobuff().set_sceneid(0);
		mapInfo.get_protobuff().set_allocated_pos(&pos);
		mapInfo.get_protobuff().set_copymapidx(0);
		mapInfo.get_protobuff().set_subcopymapidx(0);

		mapInfo.compute();

		LOG_DEBUG << "Protobuff packet to send HEX: ";
		mapInfo.log_data();

		ms_Write(mapInfo.get_buffer());
	}

	ProtobufPacket<msg::MSG_START_CUTSCENE_SC> cutscene(CommandID::NEW_ROLE_CUTSCENE_SCS);
	{
		cutscene.get_protobuff().set_cutsceneid(2);

		cutscene.compute();

		LOG_DEBUG << "Protobuff packet to send HEX: ";
		cutscene.log_data();
		
		ms_Write(cutscene.get_buffer());
	}

	//Set Main Char
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
	}
	ProtobufPacket<msg::CharacterBaseData> charBase(CommandID::RetCommonError_SC);
	{
		charBase.get_protobuff().set_exp(1);
		charBase.get_protobuff().set_welpoint(1);
		charBase.get_protobuff().set_money(1);
		charBase.get_protobuff().set_stone(1);
		charBase.get_protobuff().set_tilizhi(1);
		charBase.get_protobuff().set_type(1);
		charBase.get_protobuff().set_famelevel(1);
		charBase.get_protobuff().set_position(0);
		charBase.get_protobuff().set_viplevel(1);
		charBase.get_protobuff().set_port(0);
		charBase.get_protobuff().set_laststage(1);
		charBase.get_protobuff().set_nextexp(1000);
		charBase.get_protobuff().set_pkmode(0);
		charBase.get_protobuff().set_edupoint(1);
		charBase.get_protobuff().set_cooppoint(1);
		charBase.get_protobuff().set_bluecrystal(1);
		charBase.get_protobuff().set_purplecrystal(1);
		charBase.get_protobuff().set_vigourpoint(1);
		charBase.get_protobuff().set_doublepoint(1);
		charBase.get_protobuff().set_bluecrystalincnum(1);
		charBase.get_protobuff().set_purplecrystalincnum(1);
		charBase.get_protobuff().set_familyatt(0);
		charBase.get_protobuff().set_herothisid((std::string)"70022");
	}
	ProtobufPacket<msg::CharacterMapData> mapdata(CommandID::RetCommonError_SC);
	{
		mapdata.get_protobuff().set_hp(100);
		mapdata.get_protobuff().set_maxhp(100);
		mapdata.get_protobuff().set_level(10);

		mapdata.get_protobuff().set_allocated_pos(&pos);
		mapdata.get_protobuff().set_movespeed(80);
		mapdata.get_protobuff().set_country(1);
		

		mapdata.get_protobuff().set_dir(0);
	}
	ProtobufPacket<msg::CharacterMapShow> mapshow(CommandID::RetCommonError_SC);
	{
		mapshow.get_protobuff().set_weapon(0);
		mapshow.get_protobuff().set_heroid(70022);
		mapshow.get_protobuff().set_avatarid(70022);
		mapshow.get_protobuff().set_occupation(0);
		mapshow.get_protobuff().set_hairstyle(43);
		mapshow.get_protobuff().set_haircolor(86);
		mapshow.get_protobuff().set_facestyle(49);
		mapshow.get_protobuff().set_bodystyle(0);
	}
	ProtobufPacket<msg::CharacterFightData> fightBase(CommandID::RetCommonError_SC);
	{
		fightBase.get_protobuff().set_curfightvalue(0);
	}
	ProtobufPacket<msg::MapUserData> mapBase(CommandID::RetCommonError_SC);
	{
		mapBase.get_protobuff().set_charid(70022);
		mapBase.get_protobuff().set_name(std::string("SanGawku"));

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
		
		LOG_DEBUG << "MSG_DataCharacterMain_SC HEX:";
		pktMain.log_data();

		ms_Write(pktMain.get_buffer());
	}

	// -- do_fucking_matter
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

	return true;
}


bool CharSocket::onReceiveMainHero(const Packet& packet)
{
	LOG_DEBUG << "on main hero request received";
	hero::MSG_SetMainHero_CSC _hero;
	ProtobufPacket<hero::MSG_SetMainHero_CSC> hero(CommandID::SetMainHero_CSC);

	fill_my_data(_hero, (unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);
	LOG_DEBUG << _hero.DebugString();
	
	hero.get_protobuff().set_errorcode(0);
	hero.get_protobuff().set_opcode(1);
	hero.get_protobuff().set_herothisid(_hero.herothisid());

	hero.compute();

	LOG_DEBUG << "MSG_SetMainHero_CSC HEX:";
	hero.log_data();

	ms_Write(hero.get_buffer());

	return true;
}

bool CharSocket::onSceneLoaded(const Packet& packet)
{
	LOG_DEBUG << "on scene loaded request received";
	return true;
}

bool CharSocket::onReceiveTeamMemberReq(const Packet& packet)
{
	ProtobufPacket<Team::MSG_TeamMemeberList_SC> team(CommandID::TeamMemeberList_SC);
	Team::MSG_TeamMemeberList_CS _team;

	fill_my_data(_team, (unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);
	LOG_DEBUG << _team.DebugString();
	
	team.get_protobuff().set_id(70022);
	team.get_protobuff().set_curmember(0);

	team.compute();

	LOG_DEBUG << "MSG_TeamMemeberList_SC HEX:";
	team.log_data();

	ms_Write(team.get_buffer());

	return true;
}

bool CharSocket::onSelectCharToLogin(const Packet& packet)
{
	LOG_DEBUG << "on Select Char to Login";
	msg::MSG_Req_SelectCharToLogin_CS _hero;
	msg::FloatMovePos pos;

	fill_my_data(_hero, (unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);
	LOG_DEBUG << _hero.DebugString();

	pos.set_fx(795.f);
	pos.set_fy(1089.f);

	ProtobufPacket<msg::MSG_Ret_UserMapInfo_SC> mapInfo(CommandID::Ret_UserMapInfo_SC);
	{
		mapInfo.get_protobuff().set_mapid(695);
		mapInfo.get_protobuff().set_filename(std::move(std::string("Pc_sgc")));
		mapInfo.get_protobuff().set_mapname(std::move(std::string("Time and space city")));
		mapInfo.get_protobuff().set_lineid(0);
		mapInfo.get_protobuff().set_sceneid(0);
		mapInfo.get_protobuff().set_allocated_pos(&pos);
		mapInfo.get_protobuff().set_copymapidx(0);
		mapInfo.get_protobuff().set_subcopymapidx(0);

		mapInfo.compute();

		LOG_DEBUG << "Protobuff packet to send HEX: ";
		mapInfo.log_data();

		ms_Write(mapInfo.get_buffer());
	}

	//Set Main Char
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
	ProtobufPacket<msg::CharacterBaseData> charBase(CommandID::RetCommonError_SC);
	{
		charBase.get_protobuff().set_exp(1);
		charBase.get_protobuff().set_welpoint(1);
		charBase.get_protobuff().set_money(1);
		charBase.get_protobuff().set_stone(1);
		charBase.get_protobuff().set_tilizhi(1);
		charBase.get_protobuff().set_type(1);
		charBase.get_protobuff().set_famelevel(1);
		charBase.get_protobuff().set_position(0);
		charBase.get_protobuff().set_viplevel(1);
		charBase.get_protobuff().set_port(0);
		charBase.get_protobuff().set_laststage(1);
		charBase.get_protobuff().set_nextexp(1000);
		charBase.get_protobuff().set_pkmode(0);
		charBase.get_protobuff().set_edupoint(1);
		charBase.get_protobuff().set_cooppoint(1);
		charBase.get_protobuff().set_bluecrystal(1);
		charBase.get_protobuff().set_purplecrystal(1);
		charBase.get_protobuff().set_vigourpoint(1);
		charBase.get_protobuff().set_doublepoint(1);
		charBase.get_protobuff().set_bluecrystalincnum(1);
		charBase.get_protobuff().set_purplecrystalincnum(1);
		charBase.get_protobuff().set_familyatt(0);
		charBase.get_protobuff().set_herothisid((std::string)"70022");

		charBase.compute();
	}
	ProtobufPacket<msg::CharacterMapData> mapdata(CommandID::RetCommonError_SC);
	{
		mapdata.get_protobuff().set_hp(100);
		mapdata.get_protobuff().set_maxhp(100);
		mapdata.get_protobuff().set_level(10);
		mapdata.get_protobuff().set_allocated_pos(&pos);
		mapdata.get_protobuff().set_movespeed(80);
		mapdata.get_protobuff().set_country(1);
		mapdata.get_protobuff().set_dir(0);

		mapdata.compute();
	}
	ProtobufPacket<msg::CharacterMapShow> mapshow(CommandID::RetCommonError_SC);
	{
		mapshow.get_protobuff().set_weapon(0);
		mapshow.get_protobuff().set_heroid(70022);
		mapshow.get_protobuff().set_avatarid(70022);
		mapshow.get_protobuff().set_occupation(0);
		mapshow.get_protobuff().set_hairstyle(43);
		mapshow.get_protobuff().set_haircolor(86);
		mapshow.get_protobuff().set_facestyle(49);
		mapshow.get_protobuff().set_bodystyle(0);

		mapshow.compute();
	}
	ProtobufPacket<msg::CharacterFightData> fightBase(CommandID::RetCommonError_SC);
	{
		fightBase.get_protobuff().set_curfightvalue(0);

		fightBase.compute();
	}
	ProtobufPacket<msg::MapUserData> mapBase(CommandID::RetCommonError_SC);
	{
		mapBase.get_protobuff().set_charid(70022);
		mapBase.get_protobuff().set_name(std::string("SanGawku"));

		mapBase.get_protobuff().set_allocated_mapdata(&mapdata.get_protobuff());
		mapBase.get_protobuff().set_allocated_mapshow(&mapshow.get_protobuff());
		mapBase.get_protobuff().set_allocated_bakhero(&mapshow.get_protobuff());

		mapBase.compute();
	}
	ProtobufPacket<msg::CharacterMainData> charMain(CommandID::RetCommonError_SC);
	{
		charMain.get_protobuff().set_allocated_attridata(&attrData.get_protobuff());
		charMain.get_protobuff().set_allocated_basedata(&charBase.get_protobuff());
		charMain.get_protobuff().set_allocated_fightdata(&fightBase.get_protobuff());
		charMain.get_protobuff().set_allocated_mapdata(&mapBase.get_protobuff());

		charMain.compute();
	}
	ProtobufPacket<msg::MSG_DataCharacterMain_SC> pktMain(CommandID::DataCharacterMain_SC);
	{
		pktMain.get_protobuff().set_allocated_data(&charMain.get_protobuff());

		pktMain.compute();

		LOG_DEBUG << "MSG_DataCharacterMain_SC HEX:";
		pktMain.log_data();

		ms_Write(pktMain.get_buffer());
	}

	// -- do_fucking_matter
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


	//msg::MSG_Ret_MapScreenBatchRefreshNpc_SC refresh;
	//auto npc = refresh.add_data();
	//npc->set
	ProtobufPacket<msg::MSG_Ret_MapScreenRefreshNpc_SC> npc_info(CommandID::Ret_MapScreenRefreshNpc_SC);

	msg::MapNpcData npcs;

	msg::MasterData master;
	{
		master.set_country(1);
		master.set_guildid(1);
		master.set_idtype(msg::EntryIDType::id);
		master.set_name(std::move(std::string("Atidote")));
		master.set_teamid(1);
	}

	{
		pos.set_fx(827);
		pos.set_fy(843);
	}
	msg::CharacterMapShow cmshow;
	{
		cmshow.set_antenna(0);
		cmshow.set_avatarid(0);
		cmshow.set_bodystyle(0);
		cmshow.set_coat(0);
		cmshow.set_face(0);
		cmshow.set_facestyle(0);
		cmshow.set_haircolor(0);
		cmshow.set_hairstyle(0);
		cmshow.set_heroid(0);
		cmshow.set_occupation(0);
		cmshow.set_weapon(0);
	}
	msg::NPC_HatredList list;
	{
		list.set_npctempid(80);
	}

	npcs.set_tempid(80);
	npcs.set_allocated_hatredlist(&list);
	npcs.set_allocated_master(&master);
	npcs.set_allocated_pos(&pos);
	npcs.set_allocated_showdata(&cmshow);
	npcs.set_attspeed(0);
	npcs.set_baseid(80);
	npcs.set_birth(true);
	npcs.set_dir(0);
	npcs.set_hp(10);
	npcs.set_maxhp(10);
	npcs.set_movespeed(80);
	npcs.set_name(std::move(std::string("Atidote")));
	npcs.set_titlename(std::move(std::string("Atidote")));
	npcs.set_visit(0);

	npc_info.get_protobuff().set_allocated_data(&npcs);
	npc_info.compute();

	LOG_DEBUG << "MSG_Ret_MapScreenRefreshNpc_SC HEX: ";
	npc_info.log_data();

	ms_Write(npc_info.get_buffer());

	npc_info.get_protobuff().release_data();
	npcs.release_hatredlist();
	npcs.release_master();
	npcs.release_pos();
	npcs.release_showdata();

	return true;
}

bool CharSocket::onReceiveProtobuf(const Packet& packet)
{
	LOG_DEBUG << "on protobuf received";

	// -- Protobuf packet recv :
	/*
		4 bytes header

		2 bytes commande id
		4 bytes unknown
		2 bytes protobuf data lenght
	
		x bytes data
	*/

	LOG_DEBUG << "PACKET HEX: ";
	//log_data((unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);

	LOG_DEBUG << "USERMAP HEX[from 8]: ";
	//log_data((unsigned char*)&packet.GetPacketData()[8], (packet.GetPacketHeader().size - 8));

	msg::MSG_Ret_UserMapInfo_SC mapInfo;
	fill_my_data(mapInfo, (unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);

	LOG_DEBUG << "mapid " << mapInfo.mapid();
	LOG_DEBUG << "filename " << mapInfo.filename();
	LOG_DEBUG << "mapname " << mapInfo.mapname();
	LOG_DEBUG << "copymapidx " << mapInfo.copymapidx();
	LOG_DEBUG << "subcopymapidx " << mapInfo.subcopymapidx();
	LOG_DEBUG << "lineid " << mapInfo.lineid();
	LOG_DEBUG << "mapInfo ByteSizeLong: " << mapInfo.ByteSizeLong();
	
	return true;
}