#include "Configuration.h"
#include "../Utils/Logger/Logger.h"

#include <sstream>
#include <cstring>

Configuration& Configuration::instance()
{
	static Configuration mapManager;
	return mapManager;
}
Configuration::~Configuration()
{
}
Configuration::Configuration()
{
}
void Configuration::Load(const std::string& file)
{
	std::ifstream ifs(file);
	if (!ifs.is_open())
	{
		throw std::runtime_error("Unable to load: " + file + "\n");
	}
	reader.parse(ifs, obj); // reader can also read strings
}
// General
int Configuration::GetWorker() const
{
	return obj["serverworker"].asInt();
}
int Configuration::GetLogLevel() const
{
	return obj["loglevel"].asInt();
}

// Auth
bool Configuration::isFounderOnly()
{
	return obj["FounderOnly"].asBool();
}

// Database
std::string Configuration::GetDatabaseHost() const
{
	const Json::Value& database = obj["database"];

	return database["Host"].asString();
}
std::string Configuration::GetDatabaseUser() const
{
	const Json::Value& database = obj["database"];

	return database["User"].asString();
}
std::string Configuration::GetDatabasePassword() const
{
	const Json::Value& database = obj["database"];

	return database["Password"].asString();
}
std::string Configuration::GetDatabaseName() const
{
	const Json::Value& database = obj["database"];

	return database["DB"].asString();
}

// Server
int Configuration::GetPort() const
{
	const Json::Value& server = obj["server"];

	return server["Port"].asInt();
}
std::string Configuration::GetServerIp() const
{
	const Json::Value& server = obj["server"];

	return server["IP"].asString();
}
std::string Configuration::GetLogFile() const
{
	return obj["logFile"].asString();
}

//GameServer : charserverlist
void Configuration::loadGameServerCharList()
{
	const Json::Value charServerList = obj["charserverlist"];
	CharServerList charsrv;

	for (Json::UInt i = 0; i < charServerList.size(); i++)
	{
		charsrv.IP = charServerList[i]["IP"].asString();
		charsrv.Port = charServerList[i]["Port"].asInt();
		gameServerCharList.push_back(charsrv);
	}
}

void Configuration::loadGameServerRate()
{
	const Json::Value& server = obj["Config"];

	rates.DropAmount = server["MobDropAmountRate"].asInt();
	rates.DropRate = server["MobDropRate"].asDouble();
	rates.ExpAmount = server["MobExpRate"].asDouble();
	rates.QuestExpAmount = server["QuestExpRate"].asDouble();
	rates.QuestRwdAmount = server["QuestRwdRate"].asDouble();

	if (GetMobDropRate() <= 0 || GetMobExpRate() <= 0 || GetMobDropAmountRate() <= 0 || GetQuestExpRate() <= 0 || GetQuestRwdRate() <= 0)
	{
		throw std::runtime_error("Error while loading config file, Rate can't be 0 value");
	}
}

const std::list<CharServerList> Configuration::GetCharServerList() const
{
	return gameServerCharList;
}
//GameServer : gameserverchannellist
int Configuration::GetGameServerServerId() const
{
	const Json::Value& server = obj["server"];

	return server["ID"].asInt();
}
int Configuration::GetGameServerChannelId() const
{
	const Json::Value& server = obj["server"];

	return server["ChannelID"].asInt();
}
double Configuration::GetMobDropRate() const
{
	return rates.DropRate;
}
double Configuration::GetMobExpRate() const
{
	return rates.ExpAmount;
}
int Configuration::GetMobDropAmountRate() const
{
	return rates.DropAmount;
}
double Configuration::GetQuestRwdRate() const
{
	return rates.QuestRwdAmount;
}
double Configuration::GetQuestExpRate() const
{
	return rates.QuestExpAmount;
}
//TBX File Load Directory
std::string Configuration::GetServerTbxData()
{
	const Json::Value& data = obj["TbxFile"];
	return obj["TbxFile"].asString();
}
std::string Configuration::GetServerMapJsonData()
{
	const Json::Value& data = obj["MapJsonFile"];
	return obj["MapJsonFile"].asString();
}

std::string Configuration::GetMapConfigJsonData()
{
	const Json::Value& data = obj["MapConfigJsonFile"];
	return obj["MapConfigJsonFile"].asString();
}