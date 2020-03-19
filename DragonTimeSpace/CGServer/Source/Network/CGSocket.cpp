#include "CGSocket.h"

#include "../Game/World/WorldSession.h"
#include "../Game/World/Map/map.h"

#include <Network/Packet/Packet.h>
#include <Network/Packet/ProtobufPacket.h>
#include <Network\Packet\Char\Char.h>

#include <Utils/Logger/Logger.h>
#include <Utils\Utils.h>

#include <Configuration\Configuration.h>
#include <Database\Repository\RepositoryManager.h>
#include <Configuration\Configuration.h>

#include <Network/Messages/ParseProto.h>
#include <Network/ResultCodes.h>

#include <Tables/TableContainer.h>

//----------------------------------------
//	Called when we open the socket
//----------------------------------------
CGSocket::CGSocket(boost::asio::io_context &service)
	: Socket{ service }
{
	// -- Process character server
	methodList.emplace_back(CommandID::UserVerifyVerCmd_CS, std::bind(&CGSocket::onCheckGatewayVer, this, std::placeholders::_1));
	methodList.emplace_back(CommandID::IphoneLoginUserCmd_CS, std::bind(&CGSocket::onReceiveUserInfo, this, std::placeholders::_1));
	methodList.emplace_back(CommandID::Create_Role_CS, std::bind(&CGSocket::onReceiveCharCreate, this, std::placeholders::_1));
	methodList.emplace_back(CommandID::Req_SelectCharToLogin_CS, std::bind(&CGSocket::onSelectCharToLogin, this, std::placeholders::_1));
}

//----------------------------------------
//	Called when we open the socket
//----------------------------------------
CGSocket::~CGSocket()
{
	LOG_TRACE << "CGSocket connection close: [" << GetRemoteEndPoint() << "]";
}
void CGSocket::OnConnected()
{
	LOG_DEBUG << "New Connection from: " << this->GetAddress();
}

//----------------------------------------
//	We got incomming data from our player
//	Return false in case we was not able to parse data
//	Set internalError = ResultCodes::RESULT_FAIL in case of something unexpected to kick the connection
//----------------------------------------
bool CGSocket::ProcessIncomingData(const Packet& packet)
{
	char_packet* p = (char_packet*)packet.GetPacketData();

	for (const auto& method : methodList)
	{
		if (std::get<0>(method) == p->CMD)
		{
			auto _method = std::get<1>(method);
			_method(packet);
			return true;
		}
	}

	if (_session)
	{
		return _session->_ProcessGamePacket(packet);
	}

	LOG_WARNING << "Get an unexpected packet: [" << GetPacketName(p->CMD) << "]";
	internalError = 1000;
	return false;
}

bool CGSocket::onCheckGatewayVer(const Packet& packet)
{
	LOG_DEBUG << "onCheckGatewayVer";

	gateway_version* data = (gateway_version*)packet.GetPacketData();
	LOG_DEBUG << "version : " << data->version;

	return true;
}

bool CGSocket::onReceiveUserInfo(const Packet& packet)
{
	LOG_DEBUG << "onReceiveUserInfo";
	stIphoneLoginUserCmd_CS* login_data = (stIphoneLoginUserCmd_CS*)packet.GetPacketData();

	account_id = login_data->accid;

	bool ret;
	auto result = sQueryRepository.GetCGServerRepository().GetCharacterlistByAccountId(login_data->accid, ret);
	if (!ret)
	{
		LOG_FATAL << "Query result were null";
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
	ms_Write(characterList.get_buffer());
	return true;
}

bool CGSocket::onReceiveCharCreate(const Packet& packet)
{
	LOG_DEBUG << "onReceiveCharCreate";

	auto _hero = ProtobufPacket<msg::MSG_Create_Role_CS>(packet);
	msg::FloatMovePos pos;
	auto hero_table = sTBL.get_table<pb::heros>();
	const pb::heros_t_hero_config* hero = nullptr;

	for (auto it = hero_table.datas().begin(); it != hero_table.datas().end(); ++it)
	{
		if (it->id() == _hero.get_protobuff().heroid())
		{
			hero = &(*it);
		}
	}
	if (hero != nullptr)
	{
		if (!_session)
			_session = std::make_shared<WorldSession>(this, account_id);

		bool ret = false;
		auto result = sQueryRepository.GetCGServerRepository().InsertCharacterByAccountId(account_id, _hero.get_protobuff().heroid(), hero->newavatar(), _hero.get_protobuff().sex(), _hero.get_protobuff().facestyle(),
			_hero.get_protobuff().hairstyle(), _hero.get_protobuff().haircolor(), _hero.get_protobuff().antenna(), _hero.get_protobuff().name(), ret);

		if (!ret)
		{
			LOG_FATAL << "Create character failed";
			auto res = ProtobufPacket<msg::MSG_Ret_Common_Error_SC>(CommandID::RetCommonError_SC);
			// -- need more result codes
			res.get_protobuff().set_errorcode(ResultCode::DATABASE_ERROR);
			res.compute();

			ms_Write(res.get_buffer());
			return false;
		}
		_session->CreatePlayer(result->getInsertedID());

		ProtobufPacket<msg::MSG_START_CUTSCENE_SC> cutscene(CommandID::NEW_ROLE_CUTSCENE_SCS);
		{
			cutscene.get_protobuff().set_cutsceneid(2);
			cutscene.compute();
			ms_Write(cutscene.get_buffer());
		}

		return true;
	}

	auto res = ProtobufPacket<msg::MSG_Ret_Common_Error_SC>(CommandID::RetCommonError_SC);
	// -- need more result codes
	res.get_protobuff().set_errorcode(ResultCode::DATABASE_ERROR);
	res.compute();

	ms_Write(res.get_buffer());
	return false;
}

bool CGSocket::onSelectCharToLogin(const Packet& packet)
{
	LOG_DEBUG << "onSelectCharToLogin";

	auto _hero = ProtobufPacket<msg::MSG_Req_SelectCharToLogin_CS>(packet);

	if (_session = std::make_shared<WorldSession>(this, 1))
	{
		_session->CreatePlayer(_hero.get_protobuff().charid());
	}

	return true;
}
