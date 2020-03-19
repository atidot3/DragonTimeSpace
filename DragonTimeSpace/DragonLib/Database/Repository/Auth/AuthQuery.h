#ifndef _AUTHQUERY_H_
#define _AUTHQUERY_H_

#pragma once

#include <Database\MySQLWrapper.h>
#include <Database\Query\QueryResult.h>
#include <Database\Query\Query.h>

class CAuthQuery final
{
public:
	std::unique_ptr<QueryResult>	GetIpBanned(const std::string& sAddress, bool& ret) const;
	std::unique_ptr<QueryResult>	GetMACBanned(const std::string&  MAC, bool& ret) const;
	std::unique_ptr<QueryResult>	GetAccountInfoByUsername(const std::string& sUsername, bool& ret) const;
	std::unique_ptr<QueryResult>	GetAccountInfoByAccountID(const uint32_t& iAccountId, bool& ret) const;
	void	UpdateAuthKeyByAccountID(const char *authKey, const uint32_t& iAccountId) const;
	void	UpdateLastServerIDByAccountID(const int& iLastServerId, const uint32_t& iAccountId) const;
	void	UpdateLastChannelIDByAccountID(const int& iLastChannelId, const uint32_t& iAccountId) const;
};

#endif //_AUTHQUERY_H_