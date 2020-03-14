#ifndef _CHARQUERY_H_
#define _CHARQUERY_H_

#pragma once

#include <Database\MySQLWrapper.h>
#include <Database\Query\QueryResult.h>
#include <Database\Query\Query.h>

class CCharQuery
{
public:
	CCharQuery();
	~CCharQuery();
	void	GetCharacterByCharId(const uint32_t&  iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	GetBindByCharId(const uint32_t&  iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	GetCharacterAttributesByCharId(const uint32_t&  iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	GetCharacterByNameAndServerId(const std::string&  sCharName, const int&  iServerId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	GetCharacterlistByAccountIdAndServerId(const uint32_t&  iAccountId, const int&  iServerId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	GetCharacterCountByAccountIdAndServerId(const uint32_t&  iAccountId, const int&  iServerId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	GetCharacterlistByAccountId(const uint32_t&  iAccountId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void	UpdateCharNameByCharId(const std::string&  sCharName, const uint32_t&  iCharId) const;
	void	UpdateCharDeletionStartByCharId(const uint64_t&  sDeleteDate, const uint32_t&  iCharId, const uint32_t&  iAccID) const;
	const std::string				UpdateCharacterPosition_XYZByCharId(const float&  fX, const float&  fY, const float&  fZ, const float&  rX, const float&  rY, const float&  rZ, const uint32_t&  iCharId) const;
	void							UpdateCharacterPosition_XYZAndWorldTableIdAndWorldIdByCharId(const float&  fX, const float&  fY, const float&  fZ, const float&  rX, const float&  rY, const float&  rZ, const uint32_t&  worldTableId, const uint32_t&  worldId, const uint32_t&  iCharId) const;
	void							UpdateTutorialDone(const uint32_t& charid);
	void							UpdateLastServerIdByAccountID(const int&  iServerId, const uint32_t& iAccountID);

	void							DeleteCharacterByAccountIdAndCharId(const uint32_t&  iAccountId, const uint32_t&  iCharId) const;
	void							DeleteCharacterByCharId(const uint32_t&  iCharId) const;
	void							InsertChraracter(const uint32_t&  iAccountID, const std::string&  sCharName, const int&  iServerID, const BYTE&  byRace, const BYTE&  byClass, const BYTE&  byGender, const BYTE&  byFace, const BYTE&  byHair, const BYTE&  byHairColor, const BYTE&  bySkinColor, const float& fSize, const uint32_t&  iGuildID, const int&  iIsGm, const std::string&  sCreatedAt, const float& pX, const float& pY, const float& pZ, const float& rX, const float& rY, const float& rZ, const uint32_t& mapID, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	const std::string				InsertCharacterAttributes(const uint32_t&  iCharId, const WORD&  LP, const WORD&  EP, const WORD&  RP) const;
};

#endif //_CHARQUERY_H_