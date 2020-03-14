#ifndef _AUTHQUERY_H_
#define _AUTHQUERY_H_

#pragma once

#include <Database\MySQLWrapper.h>
#include <Database\Query\QueryResult.h>
#include <Database\Query\Query.h>

class CAuthQuery final
{
public:
	void	GetIpBanned(const std::string& sAddress, boost::function<void(std::shared_ptr<QueryResult>)> callback);
	void	GetMACBanned(const std::string&  MAC, boost::function<void(std::shared_ptr<QueryResult>)> callback);
	void	GetAccountInfoByUsername(const std::string& sUsername, boost::function<void(std::shared_ptr<QueryResult>)> callback);
	void	GetAccountInfoByAccountID(const uint32_t& iAccountId, boost::function<void(std::shared_ptr<QueryResult>)> callback);
	void	UpdateAuthKeyByAccountID(const char *authKey, const uint32_t& iAccountId);
	void	UpdateLastServerIDByAccountID(const int& iLastServerId, const uint32_t& iAccountId);
	void	UpdateLastChannelIDByAccountID(const int& iLastChannelId, const uint32_t& iAccountId);
};

#endif //_AUTHQUERY_H_