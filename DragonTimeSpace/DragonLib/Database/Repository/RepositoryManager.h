#ifndef _REPOSITORYMANAGER_H_
#define _REPOSITORYMANAGER_H_
#pragma once

/*#include "Auth/AuthQuery.h"
#include "Char/CharQuery.h"
#include "Game/GameQuery.h"*/

class RepositoryManager final
{
public:
	RepositoryManager() {}
	~RepositoryManager() {}
	static RepositoryManager& instance();
	/*static CAuthQuery& GetAuthRepository();
	static CCharQuery& GetCharRepository();
	static CGameQuery& GetGameRepository();*/
};

#define sRepositoryManager RepositoryManager::instance()

#endif //! _REPOSITORYMANAGER_H_