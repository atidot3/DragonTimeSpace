#pragma once

#include <boost\move\unique_ptr.hpp>
#include <libjson\json\json.h>
#include <list>


struct CharServerList
{
public:
	CharServerList() {}
	~CharServerList() {}
	std::string IP;
	int Port;
};
struct RateControl
{
	double DropRate;
	double ExpAmount;
	int DropAmount;
	double QuestExpAmount;
	double QuestRwdAmount;
};
class Configuration final
{
private:
	Configuration();
	~Configuration();
public:
	static Configuration& instance();
	void Load(const std::string& file);
	// General
	int GetWorker() const;
	int GetLogLevel() const;

	// Auth
	bool isFounderOnly();

	// Database
	std::string GetDatabaseHost() const;
	std::string GetDatabaseUser() const;
	std::string GetDatabasePassword() const;
	std::string GetDatabaseName() const;

	// Sever
	int GetPort() const;
	std::string GetServerIp() const;
	std::string GetLogFile() const;

	// GameServer
	int GetGameServerServerId() const;
	int GetGameServerChannelId() const;
	void loadGameServerCharList();
	void loadGameServerRate();
	const std::list<CharServerList> GetCharServerList() const;
	double GetMobDropRate() const;
	double GetMobExpRate() const;
	int GetMobDropAmountRate() const;
	double GetQuestExpRate() const;
	double GetQuestRwdRate() const;
	void loadGameServerData();
	std::string GetTriggerDir() const;
	std::string GetWorldDataDir() const;
protected:
	Json::Reader reader;
	Json::Value obj;

// General
	int loglevel;
	int port;
	int worker;

// GameServer
	std::list<CharServerList> gameServerCharList;
	RateControl rates;

// StressClient
	int connectionsToSpawn;
};

#define sConfig Configuration::instance()