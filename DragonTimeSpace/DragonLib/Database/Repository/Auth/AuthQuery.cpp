#include "AuthQuery.h"

void CAuthQuery::GetIpBanned(const std::string&  sAddress, boost::function<void(std::shared_ptr<QueryResult>)> callback)
{
	Query query("SELECT * FROM ipbanned WHERE ip = '?';");
	query.setValue(sAddress.c_str());

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void CAuthQuery::GetMACBanned(const std::string&  MAC, boost::function<void(std::shared_ptr<QueryResult>)> callback)
{
	Query query("SELECT * FROM macbanned WHERE mac = '?';");
	query.setValue(MAC.c_str());

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void CAuthQuery::GetAccountInfoByUsername(const std::string&  sUsername, boost::function<void(std::shared_ptr<QueryResult>)> callback)
{
	Query query("SELECT * FROM account WHERE UserName = '?';");
	query.setValue(sUsername);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void CAuthQuery::GetAccountInfoByAccountID(const uint32_t&  iAccountId, boost::function<void(std::shared_ptr<QueryResult>)> callback)
{
	Query query("SELECT * FROM account WHERE AccountID = '?';");
	query.setValue(iAccountId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void CAuthQuery::UpdateAuthKeyByAccountID(const char *authKey, const uint32_t&  iAccountId)
{
	Query query("UPDATE `account` SET `authkey` = '?' WHERE `AccountID` = '?';");
	query.setValue(authKey);
	query.setValue(iAccountId);

	sDB.ExecuteQuery(query.GetQuery());
}

void CAuthQuery::UpdateLastServerIDByAccountID(const int&  iLastServerId, const uint32_t&  iAccountId)
{
	Query query("UPDATE `account` SET `LastServerID` = '?' WHERE `AccountID` = '?';");
	query.setValue(iLastServerId);
	query.setValue(iAccountId);

	sDB.ExecuteQuery(query.GetQuery());
}

void CAuthQuery::UpdateLastChannelIDByAccountID(const int&  iLastChannelId, const uint32_t&  iAccountId)
{
	Query query("UPDATE `account` SET `LastChannelID` = '?' WHERE `AccountID` = '?';");
	query.setValue(iLastChannelId);
	query.setValue(iAccountId);

	sDB.ExecuteQuery(query.GetQuery());
}