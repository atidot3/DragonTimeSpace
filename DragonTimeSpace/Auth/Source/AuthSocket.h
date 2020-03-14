#pragma once

#include <Network/Socket.h>
#include <Network/Packet/Packet.h>
//#include <Utils/Opcodes.h>
//#include <Utils/ResultCode.h>
#include <Utils/Logger/Logger.h>
#include <Database\Query\QueryResult.h>

class AuthSocket : public Socket
{
public:
	/**
	*  Our socket constructor
	*\	Parameters are boost::socket and callback for the socket destruction
	*/
	AuthSocket(boost::asio::io_context &service);
	/**
	*  Our socket destructor
	*/
	virtual ~AuthSocket() override;
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
	bool onConnectFit(const Packet& packet);
	bool OnClientIp(const Packet& packet);
	bool OnLoginReq(const Packet& packet);
};