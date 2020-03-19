#ifndef _CHARQUERY_H_
#define _CHARQUERY_H_

#pragma once

#include <Database\MySQLWrapper.h>
#include <Database\Query\QueryResult.h>
#include <Database\Query\Query.h>

class CCGServerQuery
{
public:
	CCGServerQuery();
	~CCGServerQuery();

	void	GetCharacterByCharId(const uint32_t&  iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	GetCharacterCountByAccountId(const uint32_t&  iAccountId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	GetCharacterlistByAccountId(const uint32_t&  iAccountId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
};

#endif //_CHARQUERY_H_