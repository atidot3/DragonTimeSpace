#include "CharSocket.h"

#include <Network/Packet/Packet.h>
#include <Network\Packet\Char\Char.h>
#include <Network\Messages\CommandID.h>
#include <Network\Messages\message.pb.h>
#include <Network\Messages\avatar.pb.h>
#include <Network\Messages\object.pb.h>
#include <Network\Messages\hero.pb.h>
#include <Network\Messages\team.pb.h>
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

	/*
			On connected received :

			opcode : (104 ? 120)
			version should be 2000

			uint_32 reserve;
			uint_32 version;

	*/
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
	//LOG_WARNING << "Get an unexpected packet: [" << std::to_string(packet._header.CMD_PARAM) << "]";
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

template<class T>
void fill_my_data(T& t, const unsigned char* data, const WORD& size)
{
	MessageBuffer buffer;
	buffer.Resize(size - 8);
	buffer.Write(&data[8], size - 8);

	bool isOk = ParseProtoMsg<T>((const char*)buffer.GetReadPointer(), (size - 8), t);
}

bool CharSocket::onReceiveUserInfo(const Packet& packet)
{
	msg::MSG_Ret_LoginOnReturnCharList_SC* characterList = new msg::MSG_Ret_LoginOnReturnCharList_SC();

	/*for (mysql->total_characters)
	{
		auto list = characterList->add_charlist();
		list->set_charid(mysql->charId);
	}*/

	
		auto it = characterList->add_charlist();
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

	const unsigned short protobuff_data_size = characterList->ByteSizeLong();
	std::vector<BYTE> protobuff_buffer(protobuff_data_size);
	characterList->SerializeToArray(protobuff_buffer.data(), protobuff_data_size);

	
	LOG_DEBUG << "MSG_Ret_LoginOnReturnCharList_SC packet to send HEX: ";
	log_data(protobuff_buffer.data(), protobuff_data_size);

	res_test resp;
	MessageBuffer buffer;

	buffer.Resize((sizeof(res_test) + protobuff_data_size));

	resp.size = (sizeof(res_test) - HEADER_SIZE) + protobuff_data_size;
	resp.CMD = 2308;
	resp.compress = 0;
	resp.encrypt = 0;
	resp.pad = 0x81;
	resp.pad1 = 0xde;
	resp.pad2 = 0x46;
	resp.pad3 = 0xdf;
	resp.protobuff_length = protobuff_data_size;


	buffer.Write(&resp, sizeof(res_test));
	buffer.Write(protobuff_buffer.data(), protobuff_data_size);
	LOG_DEBUG << "Before Padding Size " << buffer.GetBufferSize();
	// -- padding
	BYTE padding = 0;
	while (((sizeof(res_test) + protobuff_data_size) + padding) % 8 != 0 && padding < 10)
		buffer.Write(&++padding, 1);



	LOG_DEBUG << "PACKET TO SEND HEX:";
	log_data(buffer.GetReadPointer(), sizeof(res_test) + protobuff_data_size);
	LOG_DEBUG << "Packet Size True:" << buffer.GetBufferSize();

	_writeQueue.push(std::move(buffer));

	/*
	LOG_DEBUG << "Received user info";
	stIphoneLoginUserCmd_CS* data = (stIphoneLoginUserCmd_CS*)packet.GetPacketData();
	msg::MSG_Ret_UserMapInfo_SC* mapInfo = new msg::MSG_Ret_UserMapInfo_SC();
	msg::FloatMovePos pos;

	mapInfo->set_mapid(698);
	mapInfo->set_filename(std::move(std::string("toto")));
	mapInfo->set_mapname(std::move(std::string("toto")));
	mapInfo->set_lineid(1);
	mapInfo->set_sceneid(1);
	mapInfo->set_allocated_pos(&pos);
	mapInfo->set_copymapidx(0);
	mapInfo->set_subcopymapidx(0);

	const unsigned short protobuff_data_size = mapInfo->ByteSizeLong();
	std::vector<BYTE> protobuff_buffer(protobuff_data_size);
	mapInfo->SerializeToArray(protobuff_buffer.data(), protobuff_data_size);
	

	LOG_DEBUG << "Protobuff packet to send HEX: ";
	log_data(protobuff_buffer.data(), protobuff_data_size);

	res_test resp;
	MessageBuffer buffer;

	buffer.Resize((sizeof(res_test) + protobuff_data_size));

	resp.size = (sizeof(res_test) - HEADER_SIZE) + protobuff_data_size;
	resp.CMD = 2273;
	resp.compress = 0;
	resp.encrypt = 0;
	resp.pad = 0x81;
	resp.pad1 = 0xde;
	resp.pad2 = 0x46;
	resp.pad3 = 0xdf;
	resp.protobuff_length = protobuff_data_size;
	

	buffer.Write(&resp, sizeof(res_test));
	buffer.Write(protobuff_buffer.data(), protobuff_data_size);
	LOG_DEBUG << buffer.GetBufferSize();
	// -- padding
	BYTE padding = 0;
	while (((sizeof(res_test) + protobuff_data_size) + padding) % 8 != 0 && padding < 10)
		buffer.Write(&++padding, 1);

	LOG_DEBUG << "PACKET TO SEND HEX:";
	log_data(buffer.GetReadPointer(), sizeof(res_test) + protobuff_data_size);

	_writeQueue.push(std::move(buffer));
	*/
	return true;
}

bool CharSocket::onReceiveCharCreate(const Packet& packet)
{
	LOG_DEBUG << "NEW_ROLE_CUTSCENE_SCS";
	msg::MSG_Create_Role_CS _hero;
	fill_my_data(_hero, (unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);

	msg::MSG_Ret_UserMapInfo_SC* mapInfo = new msg::MSG_Ret_UserMapInfo_SC();
	msg::FloatMovePos pos;
	pos.set_fx(801.f);
	pos.set_fy(908.f);
	mapInfo->set_mapid(695);
	mapInfo->set_filename(std::move(std::string("Pc_sgc")));
	mapInfo->set_mapname(std::move(std::string("Time and space city")));
	mapInfo->set_lineid(0);
	mapInfo->set_sceneid(0);
	mapInfo->set_allocated_pos(&pos);
	mapInfo->set_copymapidx(0);
	mapInfo->set_subcopymapidx(0);

	const unsigned short protobuff_data_size = mapInfo->ByteSizeLong();
	std::vector<BYTE> protobuff_buffer(protobuff_data_size);
	mapInfo->SerializeToArray(protobuff_buffer.data(), protobuff_data_size);


	LOG_DEBUG << "Protobuff packet to send HEX: ";
	log_data(protobuff_buffer.data(), protobuff_data_size);

	res_test resp;
	MessageBuffer buffer;

	buffer.Resize((sizeof(res_test) + protobuff_data_size));

	resp.size = (sizeof(res_test) - HEADER_SIZE) + protobuff_data_size;
	resp.CMD = 2273;
	resp.compress = 0;
	resp.encrypt = 0;
	resp.pad = 0x81;
	resp.pad1 = 0xde;
	resp.pad2 = 0x46;
	resp.pad3 = 0xdf;
	resp.protobuff_length = protobuff_data_size;


	buffer.Write(&resp, sizeof(res_test));
	buffer.Write(protobuff_buffer.data(), protobuff_data_size);
	LOG_DEBUG << buffer.GetBufferSize();
	// -- padding
	BYTE padding = 0;
	while (((sizeof(res_test) + protobuff_data_size) + padding) % 8 != 0 && padding < 10)
		buffer.Write(&++padding, 1);

	LOG_DEBUG << "PACKET TO SEND HEX:";
	log_data(buffer.GetReadPointer(), sizeof(res_test) + protobuff_data_size);

	_writeQueue.push(std::move(buffer));

	//msg::MSG_NEW_ROLE_CUTSCENE_SCS* characterList = new msg::MSG_NEW_ROLE_CUTSCENE_SCS();
	//
	//
	//const unsigned short protobuff_data_size = characterList->ByteSizeLong();
	//std::vector<BYTE> protobuff_buffer(protobuff_data_size);
	//characterList->SerializeToArray(protobuff_buffer.data(), protobuff_data_size);


	//LOG_DEBUG << "Protobuff packet to send HEX: ";
	//log_data(protobuff_buffer.data(), protobuff_data_size);

	//res_test resp;
	//MessageBuffer buffer;

	//buffer.Resize((sizeof(res_test) + protobuff_data_size));

	//resp.size = (sizeof(res_test) - HEADER_SIZE) + protobuff_data_size;
	//resp.CMD = 2324;
	//resp.compress = 0;
	//resp.encrypt = 0;
	//resp.pad = 0x81;//Timestamp
	//resp.pad1 = 0xde;
	//resp.pad2 = 0x46;
	//resp.pad3 = 0xdf;
	//resp.protobuff_length = protobuff_data_size;


	//buffer.Write(&resp, sizeof(res_test));
	//buffer.Write(protobuff_buffer.data(), protobuff_data_size);
	//LOG_DEBUG << "Before Padding Size " << buffer.GetBufferSize();
	//// -- padding
	//BYTE padding = 0;
	//while (((sizeof(res_test) + protobuff_data_size) + padding) % 8 != 0 && padding < 10)
	//	buffer.Write(&++padding, 1);

	//
	//log_data(buffer.GetReadPointer(), sizeof(res_test) + protobuff_data_size + 2);
	//LOG_DEBUG << "Real Packet Size: " << buffer.GetBufferSize();

	//_writeQueue.push(std::move(buffer));



	msg::MSG_START_CUTSCENE_SC* cutscene = new msg::MSG_START_CUTSCENE_SC();
	cutscene->set_cutsceneid(2);
	//cutscene->set_onfinish();

	const unsigned short protobuff_data_size2 = cutscene->ByteSizeLong();
	std::vector<BYTE> protobuff_buffer2(protobuff_data_size2);
	cutscene->SerializeToArray(protobuff_buffer2.data(), protobuff_data_size2);


	LOG_DEBUG << "Protobuff packet to send HEX: ";
	log_data(protobuff_buffer2.data(), protobuff_data_size2);

	res_test resp2;
	MessageBuffer buffer2;

	buffer2.Resize((sizeof(res_test) + protobuff_data_size2));

	resp2.size = (sizeof(res_test) - HEADER_SIZE) + protobuff_data_size2;
	resp2.CMD = 2324;
	resp2.compress = 0;
	resp2.encrypt = 0;
	resp2.pad = 0x81;//Timestamp
	resp2.pad1 = 0xde;
	resp2.pad2 = 0x46;
	resp2.pad3 = 0xdf;
	resp2.protobuff_length = protobuff_data_size2;


	buffer2.Write(&resp2, sizeof(res_test));
	buffer2.Write(protobuff_buffer2.data(), protobuff_data_size2);
	LOG_DEBUG << "Before Padding Size " << buffer2.GetBufferSize();
	// -- padding
	padding = 0;
	while (((sizeof(res_test) + protobuff_data_size2) + padding) % 8 != 0 && padding < 10)
		buffer2.Write(&++padding, 1);


	log_data(buffer2.GetReadPointer(), sizeof(res_test) + protobuff_data_size2 + 2);
	LOG_DEBUG << "Real Packet Size: " << buffer2.GetBufferSize();

	_writeQueue.push(std::move(buffer2));


	/*
	LOG_DEBUG << "Received user info";
	stIphoneLoginUserCmd_CS* data = (stIphoneLoginUserCmd_CS*)packet.GetPacketData();
	msg::MSG_Ret_UserMapInfo_SC* mapInfo = new msg::MSG_Ret_UserMapInfo_SC();
	msg::FloatMovePos pos;

	mapInfo->set_mapid(698);
	mapInfo->set_filename(std::move(std::string("toto")));
	mapInfo->set_mapname(std::move(std::string("toto")));
	mapInfo->set_lineid(1);
	mapInfo->set_sceneid(1);
	mapInfo->set_allocated_pos(&pos);
	mapInfo->set_copymapidx(0);
	mapInfo->set_subcopymapidx(0);

	const unsigned short protobuff_data_size = mapInfo->ByteSizeLong();
	std::vector<BYTE> protobuff_buffer(protobuff_data_size);
	mapInfo->SerializeToArray(protobuff_buffer.data(), protobuff_data_size);


	LOG_DEBUG << "Protobuff packet to send HEX: ";
	log_data(protobuff_buffer.data(), protobuff_data_size);

	res_test resp;
	MessageBuffer buffer;

	buffer.Resize((sizeof(res_test) + protobuff_data_size));

	resp.size = (sizeof(res_test) - HEADER_SIZE) + protobuff_data_size;
	resp.CMD = 2273;
	resp.compress = 0;
	resp.encrypt = 0;
	resp.pad = 0x81;
	resp.pad1 = 0xde;
	resp.pad2 = 0x46;
	resp.pad3 = 0xdf;
	resp.protobuff_length = protobuff_data_size;


	buffer.Write(&resp, sizeof(res_test));
	buffer.Write(protobuff_buffer.data(), protobuff_data_size);
	LOG_DEBUG << buffer.GetBufferSize();
	// -- padding
	BYTE padding = 0;
	while (((sizeof(res_test) + protobuff_data_size) + padding) % 8 != 0 && padding < 10)
		buffer.Write(&++padding, 1);

	LOG_DEBUG << "PACKET TO SEND HEX:";
	log_data(buffer.GetReadPointer(), sizeof(res_test) + protobuff_data_size);

	_writeQueue.push(std::move(buffer));
	*/
	return true;
}


bool CharSocket::onReceiveMainHero(const Packet& packet)
{
	LOG_DEBUG << "on main hero request received";
	hero::MSG_SetMainHero_CSC _hero;
	fill_my_data(_hero, (unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);
	LOG_DEBUG << _hero.DebugString();
	hero::MSG_SetMainHero_CSC * hero = new hero::MSG_SetMainHero_CSC();
	hero->set_errorcode(0);
	hero->set_opcode(1);
	hero->set_herothisid(_hero.herothisid());

	const unsigned short protobuff_data_size = hero->ByteSizeLong();
	std::vector<BYTE> protobuff_buffer(protobuff_data_size);
	hero->SerializeToArray(protobuff_buffer.data(), protobuff_data_size);

	res_test resp;
	MessageBuffer buffer;

	buffer.Resize((sizeof(res_test) + protobuff_data_size));

	resp.size = (sizeof(res_test) - HEADER_SIZE) + protobuff_data_size;
	resp.CMD = 2203;
	resp.compress = 0;
	resp.encrypt = 0;
	resp.pad = 0x81;
	resp.pad1 = 0xde;
	resp.pad2 = 0x46;
	resp.pad3 = 0xdf;
	resp.protobuff_length = protobuff_data_size;

	buffer.Write(&resp, sizeof(res_test));
	buffer.Write(protobuff_buffer.data(), protobuff_data_size);
	// -- padding
	BYTE padding = 0;
	while (((sizeof(res_test) + protobuff_data_size) + padding) % 8 != 0 && padding < 10)
		buffer.Write(&++padding, 1);

	_writeQueue.push(std::move(buffer));;


	return true;
}

bool CharSocket::onSceneLoaded(const Packet& packet)
{
	LOG_DEBUG << "on scene loaded request received";
	return true;
}

bool CharSocket::onReceiveTeamMemberReq(const Packet& packet)
{
	Team::MSG_TeamMemeberList_CS _team;
	fill_my_data(_team, (unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);
	LOG_DEBUG << _team.DebugString();
	Team::MSG_TeamMemeberList_SC* team = new Team::MSG_TeamMemeberList_SC();
	team->set_id(70022);
	team->set_curmember(0);
	

	const unsigned short protobuff_data_size = team->ByteSizeLong();
	std::vector<BYTE> protobuff_buffer(protobuff_data_size);
	team->SerializeToArray(protobuff_buffer.data(), protobuff_data_size);

	res_test resp;
	MessageBuffer buffer;

	buffer.Resize((sizeof(res_test) + protobuff_data_size));

	resp.size = (sizeof(res_test) - HEADER_SIZE) + protobuff_data_size;
	resp.CMD = 60110;
	resp.compress = 0;
	resp.encrypt = 0;
	resp.pad = 0x81;
	resp.pad1 = 0xde;
	resp.pad2 = 0x46;
	resp.pad3 = 0xdf;
	resp.protobuff_length = protobuff_data_size;

	buffer.Write(&resp, sizeof(res_test));
	buffer.Write(protobuff_buffer.data(), protobuff_data_size);
	// -- padding
	BYTE padding = 0;
	while (((sizeof(res_test) + protobuff_data_size) + padding) % 8 != 0 && padding < 10)
		buffer.Write(&++padding, 1);

	_writeQueue.push(std::move(buffer));;



	//Main Data
	msg::MSG_DataCharacterMain_SC* pktMain = new msg::MSG_DataCharacterMain_SC();
	msg::CharacterMainData* charMain = new msg::CharacterMainData();
	msg::AttributeData* attrData = new msg::AttributeData();
	msg::CharacterBaseData* charBase = new msg::CharacterBaseData();
	msg::CharacterFightData* fightBase = new msg::CharacterFightData();
	msg::MapUserData* mapBase = new msg::MapUserData;
	msg::CharacterMapData* mapdata = new msg::CharacterMapData;
	msg::CharacterMapShow* mapshow = new msg::CharacterMapShow;
	attrData->set_accurate(100);
	attrData->set_bang(100);
	attrData->set_block(100);
	attrData->set_maxhp(100);
	attrData->set_maxmp(100);
	attrData->set_hp(100);
	attrData->set_mp(100);
	

	charBase->set_exp(10000);
	charBase->set_cooppoint(1000);
	std::string s("Female Saiyan");
	charBase->set_herothisid(s);

	charBase->set_viplevel(5);
	mapdata->set_hp(100);
	mapdata->set_maxhp(100);
	mapdata->set_level(10);
	
	msg::FloatMovePos pos;
	pos.set_fx(801.0f);
	pos.set_fy(905.0f);

	mapdata->set_allocated_pos(&pos);
	mapdata->set_movespeed(30);
	mapdata->set_country(1);
	mapdata->set_dir(1);
	mapshow->set_heroid(70022);
	mapshow->set_avatarid(70022);
	mapshow->set_occupation(1);
	mapshow->set_hairstyle(43);
	mapshow->set_haircolor(86);
	mapshow->set_facestyle(114);

	mapBase->set_allocated_mapdata(mapdata);
	mapBase->set_allocated_mapshow(mapshow);
	mapBase->set_charid(70022);
	mapBase->set_name(std::string("SanGawku"));
	fightBase->set_curfightvalue(0);
	charBase->set_type(2);


	charMain->set_allocated_attridata(attrData);
	charMain->set_allocated_basedata(charBase);
	charMain->set_allocated_fightdata(fightBase);
	charMain->set_allocated_mapdata(mapBase);
	pktMain->set_allocated_data(charMain);
	//cutscene->set_onfinish();

	const unsigned short protobuff_data_size3 = pktMain->ByteSizeLong();
	std::vector<BYTE> protobuff_buffer3(protobuff_data_size3);
	pktMain->SerializeToArray(protobuff_buffer3.data(), protobuff_data_size3);


	LOG_DEBUG << "Protobuff packet to send HEX: ";
	log_data(protobuff_buffer3.data(), protobuff_data_size3);

	res_test resp3;
	MessageBuffer buffer3;

	buffer3.Resize((sizeof(res_test) + protobuff_data_size3));

	resp3.size = (sizeof(res_test) - HEADER_SIZE) + protobuff_data_size3;
	resp3.CMD = 2261;
	resp3.compress = 0;
	resp3.encrypt = 0;
	resp3.pad = 0x81;//Timestamp
	resp3.pad1 = 0xde;
	resp3.pad2 = 0x46;
	resp3.pad3 = 0xdf;
	resp3.protobuff_length = protobuff_data_size3;


	buffer3.Write(&resp3, sizeof(res_test));
	buffer3.Write(protobuff_buffer3.data(), protobuff_data_size3);
	LOG_DEBUG << "Before Padding Size " << buffer3.GetBufferSize();
	// -- padding
	padding = 0;
	while (((sizeof(res_test) + protobuff_data_size3) + padding) % 8 != 0 && padding < 10)
		buffer3.Write(&++padding, 1);


	log_data(buffer3.GetReadPointer(), sizeof(res_test) + protobuff_data_size3 + 2);
	LOG_DEBUG << "Real Packet Size: " << buffer3.GetBufferSize();

	_writeQueue.push(std::move(buffer3));
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
	log_data((unsigned char*)packet.GetPacketData(), packet.GetPacketHeader().size);

	LOG_DEBUG << "USERMAP HEX[from 8]: ";
	log_data((unsigned char*)&packet.GetPacketData()[8], (packet.GetPacketHeader().size - 8));

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