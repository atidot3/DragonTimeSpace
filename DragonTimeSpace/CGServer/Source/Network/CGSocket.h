#pragma once

#include <Network/Socket.h>
#include <Network/Packet/Packet.h>
#include <Utils/Logger/Logger.h>
#include <Database/Query/QueryResult.h>

class WorldSession;
class CGSocket : public Socket
{
public:
	/**
	*  Our socket constructor
	*\	Parameters are boost::socket and callback for the socket destruction
	*/
	CGSocket(boost::asio::io_context &service);
	/**
	*  Our socket destructor
	*/
	virtual ~CGSocket() override;
	virtual void OnConnected() override;
private:
	std::string userName;
	std::string userPassword;
	std::string macAddress;
	std::shared_ptr<WorldSession> _session;

	using Method = std::function<bool(const Packet& packet)>;
	using TupleMethod = std::tuple<unsigned short, Method>;
	using MethodList = std::list<TupleMethod>;
	MethodList methodList;
protected:
	/**
	*  We get incoming packets so process then
	*\
	\*	set InternalError to fail in case of bad data
	*/
	virtual bool ProcessIncomingData(const Packet& packet) override;

private:
	bool onCheckGatewayVer(const Packet& packet);
	bool onReceiveUserInfo(const Packet& packet);
	bool onReceiveCharCreate(const Packet& packet);
	bool onReceiveMainHero(const Packet& packet);
	bool onSceneLoaded(const Packet& packet);
	bool onReceiveOperateDatasReq(const Packet& packet);
	bool onReceiveImportantBroadcast(const Packet& packet);
	bool onReceiveTeamMemberReq(const Packet& packet);
	bool onReceiveCardPackInfo(const Packet& packet);
	bool onReceiveMyHeroAttrData(const Packet& packet);
	bool onReceiveDNABagInfo(const Packet& packet);
	bool onReceiveVisitNpcTrade(const Packet& packet);

	bool onReceiveAllDNAPageInfo(const Packet& packet);

	bool onSelectCharToLogin(const Packet& packet);
	bool onRecieveChat(const Packet& packet);
	bool onReceiveRefreshRadar(const Packet& packet);
	bool onReceiveRefreshMapQuestInfo(const Packet& packet);
	bool onReceiveEntrySelectState(const Packet& packet);
	bool onReceiveSetChooseTarget(const Packet& packet);

	bool onReceiveProtobuf(const Packet& packet);
};