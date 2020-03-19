#include "CGServerQuery.h"

CCGServerQuery::CCGServerQuery()
{
}

CCGServerQuery::~CCGServerQuery()
{
}

void	CCGServerQuery::GetCharacterByCharId(const uint32_t&  iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `characters` WHERE `CharacterID` = '?';");
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CCGServerQuery::GetCharacterlistByAccountId(const uint32_t&  iAccountId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `characters` WHERE `AccountID` = '?';");
	query.setValue(iAccountId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CCGServerQuery::GetCharacterCountByAccountId(const uint32_t&  iAccountId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT COUNT(*) as counter FROM `characters` WHERE `AccountID` = '?';");
	query.setValue(iAccountId);
	
	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CCGServerQuery::SaveCharacterByAccountId(const uint32_t& iAccountId, uint32_t& iCharId, uint32_t& iCurrentLevel, BYTE& Gender, uint32_t& iHeroID, uint32_t& facestyle, uint32_t& iHairStyle, uint32_t& iHairColor, uint32_t& iAvatarId, uint32_t& mapid, std::string& charname, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("INSERT INTO `characters`(`AccountID`,`CurrentLevel`,`Gender`,`HeroID`,`Facestyle`,`Hairstyle`,`Haircolor`,`Haircolor`,`AvatarID`,`Name`, `MapID`)VALUES('?','?','?','?','?','?','?','?','?','?','?');");
	query.setValue(iAccountId);
	query.setValue(iCharId);
	query.setValue(iCurrentLevel);
	query.setValue(Gender);
	query.setValue(iHeroID);
	query.setValue(facestyle);
	query.setValue(iHairStyle);
	query.setValue(iHairColor);
	query.setValue(iAvatarId);
	query.setValue(charname);
	query.setValue(mapid);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}