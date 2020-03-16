#pragma once

#include <Network/Socket.h>
#include <Network/Packet/Packet.h>
//#include <Utils/Opcodes.h>
//#include <Utils/ResultCode.h>
#include <Utils/Logger/Logger.h>
#include <Database\Query\QueryResult.h>

class CharSocket : public Socket
{
public:
	/**
	*  Our socket constructor
	*\	Parameters are boost::socket and callback for the socket destruction
	*/
	CharSocket(boost::asio::io_context &service);
	/**
	*  Our socket destructor
	*/
	virtual ~CharSocket() override;
	virtual void OnConnected() override;
private:
	std::string userName;
	std::string userPassword;
	std::string macAddress;

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

	bool onReceiveProtobuf(const Packet& packet);
};