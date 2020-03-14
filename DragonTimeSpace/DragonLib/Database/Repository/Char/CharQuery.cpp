#include "CharQuery.h"

CCharQuery::CCharQuery()
{
}

CCharQuery::~CCharQuery()
{
}

void	CCharQuery::GetCharacterByCharId(const uint32_t&  iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `characters` WHERE `CharacterID` = '?';");
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CCharQuery::GetBindByCharId(const uint32_t&  iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `bind` WHERE `CharacterID` = '?';");
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CCharQuery::GetCharacterAttributesByCharId(const uint32_t&  iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `characters_attributes` WHERE `CharacterID` = '?';");
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CCharQuery::GetCharacterByNameAndServerId(const std::string& sCharName, const int&  iServerId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `characters` WHERE `Name` = '?' AND `ServerID`= '?';");
	query.setValue(sCharName);
	query.setValue(iServerId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CCharQuery::GetCharacterlistByAccountIdAndServerId(const uint32_t&  iAccountId, const int&  iServerId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `characters` JOIN `items` ON characters.CharacterID = items.CharacterID WHERE characters.AccountID = '?' AND `ServerID`= '?';");
	query.setValue(iAccountId);
	query.setValue(iServerId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CCharQuery::GetCharacterlistByAccountId(const uint32_t&  iAccountId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `characters` WHERE `AccountID` = '?'");
	query.setValue(iAccountId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CCharQuery::GetCharacterCountByAccountIdAndServerId(const uint32_t&  iAccountId, const int&  iServerId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT COUNT(*) as counter FROM `characters` WHERE `AccountID` = '?' AND `ServerID` = '?';");
	query.setValue(iAccountId);
	query.setValue(iServerId);
	
	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CCharQuery::UpdateCharNameByCharId(const std::string& sCharName, const uint32_t&  iCharId) const
{
	Query query("UPDATE `characters` SET `Name` = '?', `IsToRename` = '0' WHERE `CharacterID` = '?';");
	query.setValue(sCharName);
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery());
}

void	CCharQuery::UpdateCharDeletionStartByCharId(const uint64_t& sDeleteDate, const uint32_t&  iCharId, const uint32_t&  iAccID) const
{
	Query query("UPDATE characters SET `deletionStartedAt` = '?' WHERE `CharacterID` = '?' AND `AccountID` = '?' LIMIT 1;");
	query.setValue(sDeleteDate);
	query.setValue(iCharId);
	query.setValue(iAccID);

	sDB.ExecuteQuery(query.GetQuery());
}

const std::string			CCharQuery::UpdateCharacterPosition_XYZByCharId(const float&  fX, const float&  fY, const float&  fZ, const float&  rX, const float&  rY, const float&  rZ, const uint32_t&  iCharId) const
{
	Query query("UPDATE characters SET `Position_X` = '?', `Position_Y` = '?', `Position_Z` = '?', `Direction_X` = '?', `Direction_Y` = '?', `Direction_Z` = '?' WHERE `CharacterID` = '?' LIMIT 1;");
	query.setValue(fX);
	query.setValue(fY);
	query.setValue(fZ);
	query.setValue(rX);
	query.setValue(rY);
	query.setValue(rZ);
	query.setValue(iCharId);

	return query.GetQuery();
}

void							CCharQuery::UpdateCharacterPosition_XYZAndWorldTableIdAndWorldIdByCharId(const float&  fX, const float&  fY, const float&  fZ, const float&  rX, const float&  rY, const float&  rZ, const uint32_t&  worldTableId, const uint32_t&  worldId, const uint32_t&  iCharId) const
{
	Query query("UPDATE characters SET `Position_X` = '?', `Position_Y` = '?', `Position_Z` = '?', `Direction_X` = '?', `Direction_Y` = '?', `Direction_Z` = '?' , `WorldTableID` = '?', `WorldID` = '?' WHERE `CharacterID` = '?' LIMIT 1;");
	query.setValue(fX);
	query.setValue(fY);
	query.setValue(fZ);
	query.setValue(rX);
	query.setValue(rY);
	query.setValue(rZ);
	query.setValue(worldTableId);
	query.setValue(worldId);
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery());
}

void							CCharQuery::UpdateLastServerIdByAccountID(const int&  iServerId, const uint32_t& iAccountID)
{
	Query query("UPDATE account SET `LastServerID` = '?' WHERE AccountID = '?';");
	query.setValue(iServerId);
	query.setValue(iAccountID);

	sDB.ExecuteQuery(query.GetQuery());
}

void							CCharQuery::DeleteCharacterByAccountIdAndCharId(const uint32_t&  iAccountId, const uint32_t&  iCharId) const
{
	Query query("DELETE FROM `characters` WHERE `AccountID`= '?' AND `CharacterID`= '?';");

	query.setValue(iAccountId);
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery());
}

void							CCharQuery::DeleteCharacterByCharId(const uint32_t&  iCharId) const
{
	Query query("DELETE FROM `characters` WHERE `CharacterID` = '?';");
	query.setValue(iCharId);
	
	sDB.ExecuteQuery(query.GetQuery());
}

void	CCharQuery::InsertChraracter(const uint32_t&  iAccountID, const std::string& sCharName, const int&  iServerID, const BYTE& byRace, const BYTE& byClass,
	const BYTE& byGender, const BYTE& byFace, const BYTE& byHair, const BYTE& byHairColor, const BYTE& bySkinColor, const float& fSize, const uint32_t& iGuildID,
	const int& iIsGm, const std::string& sCreatedAt, const float& pX, const float& pY, const float& pZ, const float& rX, const float& rY, const float& rZ, 
	const uint32_t& mapID,
	boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("INSERT INTO `characters` (`AccountID`, `Name`, `ServerID`, `RaceID`, `ClassID`, `GenderID`, `FaceID`, `HairID`, `HairColorID`, `SkinColorID`, `Size`, `GuildID`, `IsGameMaster`, `createdAt`, `Position_X`, `Position_Y`, `Position_Z`, `Direction_X`, `Direction_Y`, `Direction_Z`, `MapInfoID`) VALUES ('?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?');");
	query.setValue(iAccountID);
	query.setValue(sCharName);
	query.setValue(iServerID);
	query.setValue(byRace);
	query.setValue(byClass);
	query.setValue(byGender);
	query.setValue(byFace);
	query.setValue(byHair);
	query.setValue(byHairColor);
	query.setValue(bySkinColor);
	query.setValue(fSize);
	query.setValue(iGuildID);
	query.setValue(iIsGm);
	query.setValue(sCreatedAt);
	query.setValue(pX);
	query.setValue(pY);
	query.setValue(pZ);
	query.setValue(rX);
	query.setValue(rY);
	query.setValue(rZ);
	query.setValue(mapID);
	
	sDB.ExecuteQuery(query.GetQuery(), callback);
}

const std::string			CCharQuery::InsertCharacterAttributes(const uint32_t&  iCharId, const WORD& LP, const WORD& EP, const WORD& RP) const
{
	Query Attribute("INSERT INTO `characters_attributes` (`CharacterID`, `CurLP`, `CurEP`, `CurRP`) VALUES ('?', '?', '?', '?');");
	Attribute.setValue(iCharId);
	Attribute.setValue(LP);
	Attribute.setValue(EP);
	Attribute.setValue(RP);

	return Attribute.GetQuery();
}
void CCharQuery::UpdateTutorialDone(const uint32_t& charid)
{
	Query query("UPDATE characters SET `IsTutorialDone` = '?' WHERE `CharacterID` = '?';");
	query.setValue(true);
	query.setValue(charid);

	sDB.ExecuteQuery(query.GetQuery());
}