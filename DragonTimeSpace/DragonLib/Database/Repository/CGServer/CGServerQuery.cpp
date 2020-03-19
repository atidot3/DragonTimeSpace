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