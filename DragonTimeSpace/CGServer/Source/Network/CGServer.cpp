#include "CGServer.h"

#include "../Game/World/Map/map.h"

#include <Utils/Logger/Logger.h>
#include <Database\MySQLWrapper.h>
#include <Tables/TableContainer.h>

#include <boost/exception/all.hpp>

#include <exception>

//----------------------------------------
//	CGServer Constructor
//----------------------------------------
CGServer::CGServer(io_context_pool& pool)
	: network{ pool, sConfig.GetPort(), sConfig.GetWorker() }
	, strandPing{ pool.get_io_context() }
	, ping_timer{ pool.get_io_context(), boost::posix_time::hours(1) }
{
}

//----------------------------------------
//	CGServer Destructor
//----------------------------------------
CGServer::~CGServer()
{
	MySQLConnWrapper::Destruct();
}

//----------------------------------------
//	Init all data
//----------------------------------------
void CGServer::Init(io_context_pool& pool)
{
	MySQLConnWrapper::Initialize();

	connectToDatabase();
	sConfig.loadGameServerCharList();
	sTBL.load(sConfig.GetServerTbxData());

	sMapMgr.Initialize(pool);

	ping_timer.async_wait(strandPing.wrap(boost::bind(&CGServer::ping, this)));
}

//----------------------------------------
//	Connect this server to database
//----------------------------------------
void CGServer::connectToDatabase()
{
	if (sDB.connect(sConfig.GetDatabaseHost(), sConfig.GetDatabaseUser(), sConfig.GetDatabasePassword(), sConfig.GetDatabaseName()) == false)
		throw std::runtime_error("Unable to connect to database: ");
}
//----------------------------------------
//	Handle database ping
//----------------------------------------
void CGServer::ping()
{
	sDB.Ping();

	ping_timer.expires_at(ping_timer.expires_at() + boost::posix_time::hours(1));
	ping_timer.async_wait(strandPing.wrap(boost::bind(&CGServer::ping, this)));
}
//----------------------------------------
//	Start the listener
//----------------------------------------
void CGServer::run()
{
	network.run();
}