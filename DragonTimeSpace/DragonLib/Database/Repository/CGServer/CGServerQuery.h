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
	std::unique_ptr<QueryResult>	GetCharacterByCharId(const uint32_t& iCharId, bool& ret) const;
	std::unique_ptr<QueryResult>	GetCharacterCountByAccountId(const uint32_t& iAccountId, bool& ret) const;
	std::unique_ptr<QueryResult>	GetCharacterlistByAccountId(const uint32_t&  iAccountId, bool& ret) const;
	//Set
	std::unique_ptr<QueryResult>	InsertCharacterByAccountId(const uint32_t& iAccountId, const uint32_t& HeroID, const uint32_t& AvatarID, const BYTE& Gender, const uint32_t& Facestyle, const uint32_t& Hairstyle,
		const uint32_t& Haircolor, const uint32_t& Antenna, const std::string& name, bool& ret) const;
};

#endif //_CHARQUERY_H_