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
	//Get
	void	GetCharacterByCharId(const uint32_t&  iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	GetCharacterCountByAccountId(const uint32_t&  iAccountId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	GetCharacterlistByAccountId(const uint32_t&  iAccountId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	//Set
	void   SaveCharacterByAccountId(const uint32_t& iAccountId, uint32_t& iCharId, uint32_t& iCurrentLevel, BYTE& Gender, uint32_t& iHeroID, uint32_t& facestyle, uint32_t& iHairStyle, uint32_t& iHairColor, uint32_t& iAvatarId, uint32_t& mapid, std::string& charname, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
};

#endif //_CHARQUERY_H_