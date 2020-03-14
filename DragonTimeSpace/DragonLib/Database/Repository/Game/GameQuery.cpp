#include "GameQuery.h"
#include <Game/Entity/Character/Character.h>


CGameQuery::CGameQuery()
{
}

CGameQuery::~CGameQuery()
{	
}

void	CGameQuery::GetItemsByCharIdAndByPlace(const uint32_t& iCharId, const BYTE& byPlace, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `items` WHERE items.CharacterID = '?' AND `place` = '?';");
	query.setValue(iCharId);
	query.setValue(byPlace);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CGameQuery::GetItemsByCharId(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `items` WHERE items.CharacterID = '?' ORDER BY place ASC, pos ASC;");
	query.setValue(iCharId);	

	sDB.ExecuteQuery(query.GetQuery(), callback);
}
void	CGameQuery::GetBankByAccId(const uint32_t& iAccId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `account_bank` WHERE account_bank.AccountID = '?' ORDER BY place ASC, pos ASC;");
	query.setValue(iAccId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CGameQuery::GetQuickSlotInfoByCharId(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `quickslot` WHERE quickslot.CharacterID = '?';");
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CGameQuery::GetRealmListByServerId(const int& iServerId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `realmlist` WHERE ServerID = '?';");
	query.setValue(iServerId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CGameQuery::GetRealmListByServerIdAndChannelId(const int& iServerId, const uint32_t& iChannelId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `realmlist` WHERE `ServerID` = '?' AND `ChannelID` = '?';");
	query.setValue(iServerId);
	query.setValue(iChannelId);

	sDB.ExecuteQuery(query.GetQuery());
}

void	CGameQuery::GetSkillsByCharId(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `skills` WHERE `CharacterID` = '?';");
	query.setValue(iCharId);	

	sDB.ExecuteQuery(query.GetQuery(), callback);
}


void	CGameQuery::GetPortalsByCharid(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `portals` WHERE `CharacterID` = '?';");
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void	CGameQuery::GetWarfogByCharid(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("SELECT * FROM `warfoginfo` WHERE `CharacterID` = '?';");
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void CGameQuery::GetQuestsByCharId(const uint32_t & iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("select trigger_id, quest_state, cur_container_id, pre_container_id, quest_info_cont, quest_info_act, quest_timer_cont, quest_timer_act, quest_timer_time_left from char_quest where char_id = '?';");
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void CGameQuery::GetQuestProgressByCharId(const uint32_t & iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("select trigger_id, container_id, action_id, event_data1, event_data2, event_data3, event_data4 from char_quest_progress where char_id = '?';");
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void CGameQuery::GetQuestsCompletedByCharID(const uint32_t & iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("select trigger_id from char_quest_complete where char_id = '?';");
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

const std::string	CGameQuery::InsertQuickSlot(const uint32_t& iCharId, const std::string& sQuickSlotField, const uint32_t* tblidxQuickSlot) const
{
	std::string sValues;
	for (int i = 0; i < MAX_NEWBIE_QUICKSLOT_COUNT; i++)
	{
		if (i == (MAX_NEWBIE_QUICKSLOT_COUNT - 1))
		{
			sValues += "'"+std::to_string(tblidxQuickSlot[i])+"'";
		}
		else
		{
			sValues += "'" + std::to_string(tblidxQuickSlot[i]) + "', ";
		}
	}
	Query QuickSlot("INSERT INTO `quickslot` (`CharacterID`, "+sQuickSlotField+") VALUES ( '?', "+ sValues +" );");
	QuickSlot.setValue(iCharId);	

	return QuickSlot.GetQuery();
}

const std::string   CGameQuery::InsertPortal(const uint32_t& iCharId, unsigned const int& portalId) const
{
	Query query("INSERT INTO `portals` (`CharacterID`, `PortalID`) VALUES('?','?');");
	query.setValue(iCharId);
	query.setValue(portalId);

	return query.GetQuery();
}

const std::string	CGameQuery::InsertBaseItem(const uint32_t& iCharacterID, const uint32_t& tblidx, const BYTE& place, const BYTE& pos, const int& iCount, const BYTE& rank, const BYTE& durability) const
{
	Query Item("INSERT INTO `items` (`CharacterID`, `tblidx`, `place`, `pos`, `count`, `rank`, `durability`) VALUES ( '?', '?', '?', '?', '?', '?', '?');");
	Item.setValue(iCharacterID);
	Item.setValue(tblidx);
	Item.setValue(place);
	Item.setValue(pos);
	Item.setValue(iCount);
	Item.setValue(rank);
	Item.setValue(durability);

	return Item.GetQuery();
}

const std::string	CGameQuery::InsertBaseItemBank(const uint32_t& accountID, const uint32_t& tblidx, const BYTE& place, const BYTE& pos, const int& iCount, const BYTE& rank, const BYTE& durability) const
{
	Query Item("INSERT INTO `account_bank` (`AccountID`, `tblidx`, `place`, `pos`, `count`, `rank`, `durability`) VALUES ( '?', '?', '?', '?', '?', '?', '?');");
	Item.setValue(accountID);
	Item.setValue(tblidx);
	Item.setValue(place);
	Item.setValue(pos);
	Item.setValue(iCount);
	Item.setValue(rank);
	Item.setValue(durability);

	return Item.GetQuery();
}

const std::string	CGameQuery::InsertBaseSkill(const uint32_t& skill_id, const uint32_t& iCharacterID, const int& iSlotID) const
{
	Query Skill("INSERT INTO `skills` (`skill_id`, `CharacterID`, `SlotID`, `TimeRemaining`) VALUES ( '?', '?', '?', 0);");
	Skill.setValue(skill_id);
	Skill.setValue(iCharacterID);
	Skill.setValue(iSlotID);
	
	return Skill.GetQuery();
}

const std::string	CGameQuery::InsertBaseBind(const uint32_t& iCharId, const uint32_t& worldId, const uint32_t& BindObjectTblIdx, const Vector3& position) const
{
	Query bind("INSERT INTO `bind` (`CharacterID`, `WorldID`, `BindObjectID`, `Position_X`, `Position_Y`, `Position_Z`) VALUES ('?','?','?','?','?','?');");
	bind.setValue(iCharId);
	bind.setValue(worldId);
	bind.setValue(BindObjectTblIdx);
	bind.setValue(position.x);
	bind.setValue(position.y);
	bind.setValue(position.z);

	return bind.GetQuery();
}

void			CGameQuery::InsertSkill(const uint32_t& tblidx, const uint32_t& iCharacterID, const bool& bIsRpBonusAuto, const BYTE& byRpBonusType,
	const BYTE& bySlotId, const uint64_t& useTimePoint, const DWORD& coolddownremainingms, const uint32_t& nExp, const uint32_t& timeRemainingms,
	boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("INSERT INTO skills (`skill_id`,`CharacterID`,`RpBonusAuto`,`RpBonusType`,`SlotID`,`CoolDownRemaining`,`TimeRemaining`,`UseTimePoint`,`Exp`) VALUES('?','?','?','?','?','?','?','?','?');");
	query.setValue(tblidx);
	query.setValue(iCharacterID);
	query.setValue(bIsRpBonusAuto);
	query.setValue(byRpBonusType);
	query.setValue(bySlotId);
	query.setValue((uint32_t)coolddownremainingms);
	query.setValue(timeRemainingms);
	query.setValue(useTimePoint);
	query.setValue(nExp);

	sDB.ExecuteQuery(query.GetQuery(), callback);
}

const std::string CGameQuery::InsertWarFog(const uint32_t & iCharId, const unsigned int & hObject, const unsigned int & ContentsID) const
{
	Query query("INSERT INTO `warfoginfo` (`idFog`, `hObject`, `CharacterID`) VALUES('?','?','?');");
	query.setValue(ContentsID);
	query.setValue(hObject);
	query.setValue(iCharId);

	return query.GetQuery();
}

const std::string CGameQuery::InsertQuest(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID) const
{
	Query query("INSERT INTO `char_quest` (`char_id`, `trigger_id`, `cur_container_id`) VALUES('?','?','?');");
	query.setValue(iCharId);
	query.setValue(TriggerID);
	query.setValue(ContainerID);

	return query.GetQuery();
}

const std::string CGameQuery::InsertQuestProgress(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID, const unsigned int & ActionID) const
{
	Query query("INSERT INTO `char_quest_progress` (`char_id`, `trigger_id`, `container_id`, `action_id`) VALUES('?','?','?','?');");
	query.setValue(iCharId);
	query.setValue(TriggerID);
	query.setValue(ContainerID);
	query.setValue(ActionID);

	return query.GetQuery();
}

const std::string CGameQuery::InsertQuestComplete(const uint32_t & iCharId, const unsigned int & TriggerID) const
{
	Query query("INSERT INTO `char_quest_complete` (`char_id`, `trigger_id`) VALUES('?','?');");
	query.setValue(iCharId);
	query.setValue(TriggerID);

	return query.GetQuery();
}

const std::string CGameQuery::UpdateQuest(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID, const unsigned int & PrevContainerID) const
{
	Query query("UPDATE `char_quest` SET `cur_container_id` = '?', `pre_container_id` = '?'  WHERE `char_id`='?' AND `trigger_id` = '?';");
	query.setValue(ContainerID);
	query.setValue(PrevContainerID);
	query.setValue(iCharId);
	query.setValue(TriggerID);

	return query.GetQuery();
}

const std::string CGameQuery::UpdateQuestProgress(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID, const unsigned int & ActionID, const uint8_t & slotIDX, const unsigned int & UpdateData) const
{
	Query query("UPDATE `char_quest_progress` SET `event_data"+std::to_string(slotIDX+1)+
														   "` = '?' WHERE `char_id`= '?' AND `trigger_id` = '?' AND `container_id` = '?' AND `action_id` = '?';");
	query.setValue(UpdateData);
	query.setValue(iCharId);
	query.setValue(TriggerID);
	query.setValue(ContainerID);
	query.setValue(ActionID);

	return query.GetQuery();
}

const std::string CGameQuery::UpdateQuestActionId(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ActionID) const
{
	Query query("UPDATE `char_quest` SET `action_id` = '?' WHERE `char_id`='?' AND `trigger_id` = '?';");
	query.setValue(ActionID);
	query.setValue(iCharId);
	query.setValue(TriggerID);

	return query.GetQuery();
}

const std::string CGameQuery::UpdateQuestInfo(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID, const unsigned int & ActionID) const
{
	Query query("UPDATE `char_quest` SET `quest_info_cont` = '?', `quest_info_act` = '?' WHERE `char_id`='?' AND `trigger_id` = '?';");
	query.setValue(ContainerID);
	query.setValue(ActionID);
	query.setValue(iCharId);
	query.setValue(TriggerID);

	return query.GetQuery();
}

void CGameQuery::UpdateQuickSlot(const BYTE& bySlotID, const uint32_t& tblidx, uint32_t iCharId)
{
	Query query("UPDATE `quickslot` SET `slotId_"+std::to_string(bySlotID)+"` = '?' WHERE `CharacterID` = '?';");
	query.setValue(tblidx);
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery());
}

void CGameQuery::UpdateItemsByCharIdAndItemDbId(const BYTE& byPlace, const BYTE& byPos, const BYTE& byStackcount, const BYTE& byRank, const BYTE& byCurDur, const BYTE& byGrade, const BYTE& byBattleAttribute, const uint32_t* aOptionTblidx, const uint64_t& startTime, const uint64_t& endTime, const uint32_t& iCharId, const uint32_t& iItemDbId)
{
	Query query("UPDATE items SET `place` = '?', `pos` = '?', `count` = '?' , `rank` = '?', `durability` = '?', `grade` = '?', `battleAttribute` = '?', `option0` = '?', `option1` = '?', `startTime` = '?', `endTime` = '?' WHERE `CharacterID` = '?' AND `id` = '?' LIMIT 1;");
	query.setValue(byPlace);
	query.setValue(byPos);
	query.setValue(byStackcount);
	query.setValue(byRank);
	query.setValue(byCurDur);
	query.setValue(byGrade);
	query.setValue(byBattleAttribute);
	query.setValue(aOptionTblidx[0]);
	query.setValue(aOptionTblidx[1]);
	query.setValue(startTime);
	query.setValue(endTime);
	query.setValue(iCharId);
	query.setValue(iItemDbId);

	sDB.ExecuteQuery(query.GetQuery());
}

void				CGameQuery::UpdateSkillInfoByCharIdAndSkillDbId(const uint32_t& tblidx, const bool& bIsRpBonusAuto, const BYTE& byRpBonusType,
	const uint64_t& useTime, const DWORD& coolddownremaining, const uint32_t& nExp, const uint32_t& timeRemaining, const uint32_t& iCharacterID, const uint32_t& iSkillDbId) const
{
	Query query("UPDATE skills SET `skill_id` = '?', `RpBonusAuto` = '?', `RpBonusType` = '?', `CoolDownRemaining` = '?', `Exp` = '?', `TimeRemaining` = '?', `UseTimePoint` = '?' WHERE `CharacterID` = '?' and `id` = '?';");
	query.setValue(tblidx);
	query.setValue((int)bIsRpBonusAuto);
	query.setValue(byRpBonusType);
	query.setValue((int)coolddownremaining);
	query.setValue(nExp);
	query.setValue(timeRemaining);
	query.setValue(useTime);
	query.setValue(iCharacterID);
	query.setValue(iSkillDbId);

	sDB.ExecuteQuery(query.GetQuery());
}

void				CGameQuery::RemoveQuickSlot(const BYTE& bySlotID, uint32_t iCharId)
{
	UpdateQuickSlot(bySlotID, 0, iCharId);
}

void				CGameQuery::RemoveItemById(const uint32_t& iItemDbId)
{
	Query query("DELETE FROM items WHERE id = '?';");
	query.setValue(iItemDbId);
	sDB.ExecuteQuery(query.GetQuery());
}

void CGameQuery::DeleteQuest(uint32_t iCharId, const unsigned int & TriggerID)
{
	Query query("DELETE FROM char_quest WHERE char_id = '?' and trigger_id = '?';");
	query.setValue(iCharId);
	query.setValue(TriggerID);
	sDB.ExecuteQuery(query.GetQuery());
}

void CGameQuery::DeleteQuestProgress(uint32_t iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID, const unsigned int & ActionID)
{

	Query query("DELETE FROM char_quest_progress WHERE char_id = '?' and trigger_id = '?' and container_id = '?' and action_id = '?';");
	query.setValue(iCharId);
	query.setValue(TriggerID);
	query.setValue(ContainerID);
	query.setValue(ActionID);
	sDB.ExecuteQuery(query.GetQuery());
}

void	CGameQuery::AddItem(const uint32_t& tblidx, const uint32_t& iCharId, const BYTE& byPlace, const BYTE& byPos, const BYTE& byStackcount, const BYTE& byRank, const BYTE& byCurDur, const BYTE& byGrade, const BYTE& byBattleAttribute, const uint64_t& startTime, const uint64_t& endTime, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("INSERT INTO items (`tblidx`, `CharacterID`, `place`, `pos`, `count`, `rank`, `durability`, `grade`, `battleAttribute`, `startTime`, `endTime`) VALUES('?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?');");
	query.setValue(tblidx);
	query.setValue(iCharId);
	query.setValue(byPlace);
	query.setValue(byPos);
	query.setValue(byStackcount);
	query.setValue(byRank);
	query.setValue(byCurDur);
	query.setValue(byGrade);
	query.setValue(byBattleAttribute);
	query.setValue(startTime);
	query.setValue(endTime);
	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void CGameQuery::UpdateTutorialHint(const uint32_t& iCharId, const DWORD& byNewTutorial)
{
	Query query("UPDATE `characters` SET `HintsDone` = '?' WHERE `CharacterID` = '?';");
	query.setValue((int)byNewTutorial);
	query.setValue(iCharId);
	sDB.ExecuteQuery(query.GetQuery());
}

void CGameQuery::UpdateLevelAndSkillPoint(const uint32_t& iCharId, const BYTE& level, const BYTE& point)
{
	Query query("UPDATE characters SET `CurrentLevel` = '?', `SkillPoints` = '?' WHERE `CharacterID` = '?';");
	query.setValue(level);
	query.setValue(point);
	query.setValue(iCharId);

	sDB.ExecuteQuery(query.GetQuery());
}

void	CGameQuery::AddBankItem(const uint32_t& tblidx, const uint32_t& iAccId, const BYTE& byPlace, const BYTE& byPos, const BYTE& byStackcount, const BYTE& byRank, const BYTE& byCurDur, const BYTE& byGrade, const BYTE& byBattleAttribute, const uint64_t& startTime, const uint64_t& endTime, boost::function<void(std::shared_ptr<QueryResult>)> callback) const
{
	Query query("INSERT INTO account_bank (`tblidx`, `AccountID`, `place`, `pos`, `count`, `rank`, `durability`, `grade`, `battleAttribute`, `startTime`, `endTime`) VALUES('?', '?', '?', '?', '?', '?', '?', '?', '?', '?', '?');");
	query.setValue(tblidx);
	query.setValue(iAccId);
	query.setValue(byPlace);
	query.setValue(byPos);
	query.setValue(byStackcount);
	query.setValue(byRank);
	query.setValue(byCurDur);
	query.setValue(byGrade);
	query.setValue(byBattleAttribute);
	query.setValue(startTime);
	query.setValue(endTime);
	sDB.ExecuteQuery(query.GetQuery(), callback);
}

void				CGameQuery::RemoveBankItemById(const uint32_t& iItemDbId)
{
	Query query("DELETE FROM account_bank WHERE id = '?';");
	query.setValue(iItemDbId);
	sDB.ExecuteQuery(query.GetQuery());
}

void CGameQuery::UpdateBankItemsByAccIdAndItemDbId(const BYTE& byPlace, const BYTE& byPos, const BYTE& byStackcount, const BYTE& byRank, const BYTE& byCurDur, const BYTE& byGrade, const BYTE& byBattleAttribute, const uint32_t* aOptionTblidx, const uint64_t& startTime, const uint64_t& endTime, const uint32_t& iAccID, const uint32_t& iItemDbId)
{
	Query query("UPDATE account_bank SET `place` = '?', `pos` = '?', `count` = '?' , `rank` = '?', `durability` = '?', `grade` = '?', `battleAttribute` = '?', `option0` = '?', `option1` = '?', `startTime` = '?', `endTime` = '?' WHERE `AccountID` = '?' AND `id` = '?' LIMIT 1;");
	query.setValue(byPlace);
	query.setValue(byPos);
	query.setValue(byStackcount);
	query.setValue(byRank);
	query.setValue(byCurDur);
	query.setValue(byGrade);
	query.setValue(byBattleAttribute);
	query.setValue(aOptionTblidx[0]);
	query.setValue(aOptionTblidx[1]);
	query.setValue(startTime);
	query.setValue(endTime);
	query.setValue(iAccID);
	query.setValue(iItemDbId);

	sDB.ExecuteQuery(query.GetQuery());
}