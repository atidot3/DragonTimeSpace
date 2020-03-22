#include "CGServer.h"

#include "../Game/World/Map/MapManager.h"

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
	update_lineid(ServerState::DOWN);
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
	register_lineid();

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
//----------------------------------------
//	Update the server on lineid database
//----------------------------------------
void CGServer::update_lineid(const ServerState& state)
{
	bool ret = false;
	Query query("UPDATE `realmlist` SET `realmflags` = '?', `population` = '?' WHERE `LineID` = '?';");
	query.setValue((BYTE)state);
	query.setValue(0);
	query.setValue(sConfig.GetGameServerServerId());
	auto result = sDB.ExecuteQuery(query.GetQuery(), ret);
	// -- check wtf
	if (!ret || !result)
	{
		throw std::runtime_error("Unable to update realmlist");
	}
	else if (ret && result)
	{
		LOG_INFO << "Server [" << sConfig.GetGameServerServerId() << "] updated to state: [" << state << "]" << std::endl;
	}
}
//----------------------------------------
//	Register the server on lineid database
//----------------------------------------
void CGServer::register_lineid()
{
	bool ret = false;
	Query query("SELECT * FROM `realmlist` WHERE `LineID` = '?';");
	query.setValue(sConfig.GetGameServerServerId());

	auto result = sDB.ExecuteQuery(query.GetQuery(), ret);
	if (!ret || !result)
	{
		// -- unable to request mysql
		throw std::runtime_error("Unable to query database");
	}
	else
	{
		if (result->rowsCount() == 0)
		{
			// -- insert
			query.setSQL("INSERT INTO `realmlist` (`LineID`, `realmflags`, `population`, `Ip`, `Port`) VALUES ('?', '?', '?', '?', '?');");
			query.setValue(sConfig.GetGameServerServerId());
			query.setValue(0);// todo enum
			query.setValue(0);
			query.setValue(sConfig.GetServerIp());
			query.setValue(sConfig.GetPort());
			result = sDB.ExecuteQuery(query.GetQuery(), ret);
			// -- check wtf
			if (!ret || !result)
			{
				throw std::runtime_error("Unable to add realmlist");
			}
			else if (ret && result)
			{
				LOG_INFO << "Server [" << sConfig.GetGameServerServerId() << "] registered" << std::endl;;
			}
		}
		else
		{
			// -- update
			update_lineid(ServerState::UP);
		}
	}
}