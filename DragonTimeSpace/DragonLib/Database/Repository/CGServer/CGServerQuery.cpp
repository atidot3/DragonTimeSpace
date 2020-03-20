#include "CGServerQuery.h"

CCGServerQuery::CCGServerQuery()
{
}

CCGServerQuery::~CCGServerQuery()
{
}

std::unique_ptr<QueryResult>	CCGServerQuery::GetCharacterByCharId(const uint32_t&  iCharId, bool& ret) const
{
	Query query("SELECT * FROM `characters` WHERE `CharacterID` = '?';");
	query.setValue(iCharId);

	return sDB.ExecuteQuery(query.GetQuery(), ret);
}

std::unique_ptr<QueryResult>	CCGServerQuery::GetCharacterlistByAccountId(const uint32_t&  iAccountId, bool& ret) const
{
	Query query("SELECT * FROM `characters` WHERE `AccountID` = '?';");
	query.setValue(iAccountId);

	return sDB.ExecuteQuery(query.GetQuery(), ret);
}

std::unique_ptr<QueryResult>	CCGServerQuery::GetCharacterCountByAccountId(const uint32_t&  iAccountId, bool& ret) const
{
	Query query("SELECT COUNT(*) as counter FROM `characters` WHERE `AccountID` = '?';");
	query.setValue(iAccountId);
	
	return sDB.ExecuteQuery(query.GetQuery(), ret);
}

std::unique_ptr<QueryResult>	CCGServerQuery::InsertCharacterByAccountId(const uint32_t& iAccountId, const uint32_t& HeroID, const uint32_t& AvatarID, const BYTE& Gender, const uint32_t& Facestyle, const uint32_t& Hairstyle,
const uint32_t& Haircolor, const uint32_t& Antenna, const std::string& name, bool& ret) const
{
	Query query("INSERT INTO `characters`(`AccountID`,`HeroID`,`AvatarID`,`Gender`,`Facestyle`,`Hairstyle`,`Haircolor`,`Antenna`,`Name`) VALUES('?','?','?','?','?','?','?','?','?');");
	query.setValue(iAccountId);
	query.setValue(HeroID);
	query.setValue(AvatarID);
	query.setValue(Gender);
	query.setValue(Facestyle);
	query.setValue(Hairstyle);
	query.setValue(Haircolor);
	query.setValue(Antenna);
	query.setValue(name);

	return sDB.ExecuteQuery(query.GetQuery(), ret);
}

std::unique_ptr<QueryResult>	CCGServerQuery::GetAllLineId(bool& ret) const
{
	Query query("SELECT * FROM `realmlist`;");

	return sDB.ExecuteQuery(query.GetQuery(), ret);
}