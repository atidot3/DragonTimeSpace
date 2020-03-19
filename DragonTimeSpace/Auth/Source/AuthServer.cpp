#include "AuthServer.h"


#include <Utils/Logger/Logger.h>
#include <Database\MySQLWrapper.h>

#include <boost/exception/all.hpp>

#include <exception>

//----------------------------------------
//	Authserver Constructor
//----------------------------------------
AuthServer::AuthServer(io_context_pool& pool)
	: network{ pool, sConfig.GetPort(), sConfig.GetWorker() }
	, strandPing{ pool.get_io_context() }
	, ping_timer{ pool.get_io_context(), boost::posix_time::hours(1) }
{
}

//----------------------------------------
//	Authserver Destructor
//----------------------------------------
AuthServer::~AuthServer()
{
	MySQLConnWrapper::Destruct();
}

//----------------------------------------
//	Init all data
//----------------------------------------
void AuthServer::Init(io_context_pool& pool)
{
	MySQLConnWrapper::Initialize();

	connectToDatabase();
	sConfig.loadGameServerCharList();

	ping_timer.async_wait(strandPing.wrap(boost::bind(&AuthServer::ping, this)));
}

//----------------------------------------
//	Connect this server to database
//----------------------------------------
void AuthServer::connectToDatabase()
{
	if (sDB.connect(sConfig.GetDatabaseHost(), sConfig.GetDatabaseUser(), sConfig.GetDatabasePassword(), sConfig.GetDatabaseName()) == false)
		throw std::runtime_error("Unable to connect to database: ");
}
//----------------------------------------
//	Handle database ping
//----------------------------------------
void AuthServer::ping()
{
	sDB.Ping();

	ping_timer.expires_at(ping_timer.expires_at() + boost::posix_time::hours(1));
	ping_timer.async_wait(strandPing.wrap(boost::bind(&AuthServer::ping, this)));
}
//----------------------------------------
//	Start the listener
//----------------------------------------
void AuthServer::run()
{
	network.run();
}