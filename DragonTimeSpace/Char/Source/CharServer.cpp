#include "CharServer.h"


#include <Utils/Logger/Logger.h>
#include <Database\MySQLWrapper.h>

#include <boost/exception/all.hpp>

#include <exception>

//----------------------------------------
//	Charserver Constructor
//----------------------------------------
CharServer::CharServer(io_context_pool& pool)
	: network{ pool, sConfig.GetPort(), sConfig.GetWorker() }
	, strandPing{ pool.get_io_context() }
	, ping_timer{ pool.get_io_context(), boost::posix_time::hours(1) }
{
}

//----------------------------------------
//	Charserver Destructor
//----------------------------------------
CharServer::~CharServer()
{
	MySQLConnWrapper::Destruct();
}

//----------------------------------------
//	Init all data
//----------------------------------------
void CharServer::Init(io_context_pool& pool)
{
	MySQLConnWrapper::Initialize();

	//connectToDatabase();
	sConfig.loadGameServerCharList();

	ping_timer.async_wait(strandPing.wrap(boost::bind(&CharServer::ping, this)));
}

//----------------------------------------
//	Connect this server to database
//----------------------------------------
void CharServer::connectToDatabase()
{
	//if (sDB.connect(sConfig.GetDatabaseHost(), sConfig.GetDatabaseUser(), sConfig.GetDatabasePassword(), sConfig.GetDatabaseName()) == false)
		//throw std::runtime_error("Unable to connect to database: ");
}
//----------------------------------------
//	Handle database ping
//----------------------------------------
void CharServer::ping()
{
	//sDB.Ping();

	ping_timer.expires_at(ping_timer.expires_at() + boost::posix_time::hours(1));
	ping_timer.async_wait(strandPing.wrap(boost::bind(&CharServer::ping, this)));
}
//----------------------------------------
//	Start the listener
//----------------------------------------
void CharServer::run()
{
	network.run();
}