#ifndef _GAMEQUERY_H_
#define _GAMEQUERY_H_

#pragma once

#include <Game\Entity\Movement\Vector.h>
#include <Database\MySQLWrapper.h>
#include <Database\Query\QueryResult.h>
#include <Database\Query\Query.h>

class CGameQuery final
{
public:
	CGameQuery();
	~CGameQuery();

	void							GetItemsByCharIdAndByPlace(const uint32_t& iCharId, const BYTE& byPlace, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							GetItemsByCharId(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							GetBankByAccId(const uint32_t& iAccId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							GetQuickSlotInfoByCharId(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							GetRealmListByServerId(const int& iServerId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							GetRealmListByServerIdAndChannelId(const int& iServerId, const uint32_t& iChannelId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							GetSkillsByCharId(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							GetPortalsByCharid(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							GetWarfogByCharid(const uint32_t & iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;

	void							GetQuestsByCharId(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							GetQuestProgressByCharId(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							GetQuestsCompletedByCharID(const uint32_t& iCharId, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	

	const std::string				InsertQuickSlot(const uint32_t& iCharId, const std::string& sQuickSlotField, const uint32_t* tblidxQuickSlot) const;
	const std::string				InsertPortal(const uint32_t& iCharId, const unsigned int& portalId) const;
	const std::string				InsertBaseItem(const uint32_t& iCharacterID, const uint32_t& tblidx, const BYTE& place, const BYTE& pos, const int& iCount, const BYTE& rank, const BYTE& durability) const;
	const std::string				InsertBaseItemBank(const uint32_t& accountID, const uint32_t& tblidx, const BYTE& place, const BYTE& pos, const int& iCount, const BYTE& rank, const BYTE& durability) const;
	const std::string				InsertBaseSkill(const uint32_t& skill_id, const uint32_t& iCharacterID, const int& iSlotID) const;
	const std::string				InsertBaseBind(const uint32_t& iCharId, const uint32_t& worldId, const uint32_t& BindObjectTblIdx, const Vector3& position) const;
	void							InsertSkill(const uint32_t& tblidx, const uint32_t& iCharacterID, const bool& bIsRpBonusAuto, const BYTE& byRpBonusType, const BYTE& bySlotId, const uint64_t& useTime, const DWORD& coolddownremaining, const uint32_t& nExp, const uint32_t& timeRemaining, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	const std::string				InsertWarFog(const uint32_t & iCharId, const unsigned int & hObject, const unsigned int & ContentsID) const;
	//Quests
	const std::string				InsertQuest(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID) const;
	const std::string				InsertQuestProgress(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID, const unsigned int & ActionID) const;
	const std::string				InsertQuestComplete(const uint32_t & iCharId, const unsigned int & TriggerID) const;
	const std::string				UpdateQuest(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID, const unsigned int & PrevContainerID) const;
	const std::string				UpdateQuestProgress(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID, const unsigned int & ActionID, const uint8_t & slotIDX, const unsigned int & UpdateData) const;
	const std::string				UpdateQuestActionId(const uint32_t & iCharId,  const unsigned int & TriggerID, const unsigned int & ActionID ) const;
	const std::string				UpdateQuestInfo(const uint32_t & iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID, const unsigned int & ActionID) const;
	//const std::string	UpdateQuestTimer(const uint32_t & iCharId, const unsigned int & hObject, const unsigned int & ContentsID) const;
	void							UpdateQuickSlot(const BYTE& bySlotID, const uint32_t& tblidx, uint32_t iCharId);
	void							UpdateItemsByCharIdAndItemDbId(const BYTE& byPlace, const BYTE& byPos, const BYTE& byStackcount, const BYTE& byRank, const BYTE& byCurDur, const BYTE& byGrade, const BYTE& byBattleAttribute, const uint32_t* aOptionTblidx, const uint64_t& startTime, const uint64_t& endTime, const uint32_t& iCharId, const uint32_t& iItemDbId);
	void							UpdateTutorialHint(const uint32_t& iCharId, const DWORD& byNewTutorial);
	void							UpdateSkillInfoByCharIdAndSkillDbId(const uint32_t& tblidx, const bool& bIsRpBonusAuto, const BYTE& byRpBonusType, const uint64_t& useTime, const DWORD& coolddownremaining, const uint32_t& nExp, const uint32_t& timeRemaining, const uint32_t& iCharacterID, const uint32_t& iSkillDbId) const;
	void							RemoveQuickSlot(const BYTE& bySlotID, uint32_t iCharId);
	void							RemoveItemById(const uint32_t& iItemDbId);
	//Quest
	void							DeleteQuest(uint32_t iCharId, const unsigned int & TriggerID);
	void							DeleteQuestProgress(uint32_t iCharId, const unsigned int & TriggerID, const unsigned int & ContainerID, const unsigned int & ActionID);
	void							UpdateLevelAndSkillPoint(const uint32_t& iCharId, const BYTE& level, const BYTE& point);
	void							AddItem(const uint32_t& tblidx, const uint32_t& iCharId, const BYTE& byPlace, const BYTE& byPos, const BYTE& byStackcount, const BYTE& byRank, const BYTE& byCurDur, const BYTE& byGrade, const BYTE& byBattleAttribute, const uint64_t& startTime, const uint64_t& endTime, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;

	// -- bank
	void							AddBankItem(const uint32_t& tblidx, const uint32_t& iAccId, const BYTE& byPlace, const BYTE& byPos, const BYTE& byStackcount, const BYTE& byRank, const BYTE& byCurDur, const BYTE& byGrade, const BYTE& byBattleAttribute, const uint64_t& startTime, const uint64_t& endTime, boost::function<void(std::shared_ptr<QueryResult>)> callback) const;
	void							RemoveBankItemById(const uint32_t& iItemDbId);
	void							UpdateBankItemsByAccIdAndItemDbId(const BYTE& byPlace, const BYTE& byPos, const BYTE& byStackcount, const BYTE& byRank, const BYTE& byCurDur, const BYTE& byGrade, const BYTE& byBattleAttribute, const uint32_t* aOptionTblidx, const uint64_t& startTime, const uint64_t& endTime, const uint32_t& iAccID, const uint32_t& iItemDbId);
};

#endif //_GAMEQUERY_H_