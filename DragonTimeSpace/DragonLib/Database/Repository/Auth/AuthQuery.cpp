#include "AuthQuery.h"

std::unique_ptr<QueryResult> CAuthQuery::GetIpBanned(const std::string&  sAddress, bool& ret) const
{
	Query query("SELECT * FROM `ipbanned` WHERE `ip` = '?';");
	query.setValue(sAddress.c_str());

	return sDB.ExecuteQuery(query.GetQuery(), ret);
}

std::unique_ptr<QueryResult> CAuthQuery::GetMACBanned(const std::string&  MAC, bool& ret) const
{
	Query query("SELECT * FROM `macbanned` WHERE `mac` = '?';");
	query.setValue(MAC.c_str());

	return sDB.ExecuteQuery(query.GetQuery(), ret);
}

std::unique_ptr<QueryResult> CAuthQuery::GetAccountInfoByUsername(const std::string&  sUsername, bool& ret) const
{
	Query query("SELECT * FROM `account` WHERE `UserName` = '?';");
	query.setValue(sUsername);

	return sDB.ExecuteQuery(query.GetQuery(), ret);
}

std::unique_ptr<QueryResult> CAuthQuery::GetAccountInfoByAccountID(const uint32_t&  iAccountId, bool& ret) const
{
	Query query("SELECT * FROM `account` WHERE `AccountID` = '?';");
	query.setValue(iAccountId);

	return sDB.ExecuteQuery(query.GetQuery(), ret);
}

void CAuthQuery::UpdateAuthKeyByAccountID(const char *authKey, const uint32_t&  iAccountId) const
{
	Query query("UPDATE `account` SET `authkey` = '?' WHERE `AccountID` = '?';");
	query.setValue(authKey);
	query.setValue(iAccountId);

	sDB.DirectExecute(query.GetQuery());
}

void CAuthQuery::UpdateLastServerIDByAccountID(const int&  iLastServerId, const uint32_t&  iAccountId) const
{
	Query query("UPDATE `account` SET `LastServerID` = '?' WHERE `AccountID` = '?';");
	query.setValue(iLastServerId);
	query.setValue(iAccountId);

	sDB.DirectExecute(query.GetQuery());
}

void CAuthQuery::UpdateLastChannelIDByAccountID(const int&  iLastChannelId, const uint32_t&  iAccountId) const
{
	Query query("UPDATE `account` SET `LastChannelID` = '?' WHERE `AccountID` = '?';");
	query.setValue(iLastChannelId);
	query.setValue(iAccountId);

	sDB.DirectExecute(query.GetQuery());
}