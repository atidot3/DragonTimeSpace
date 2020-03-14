#include "RepositoryManager.h"

/*CAuthQuery& RepositoryManager::GetAuthRepository()
{
	static CAuthQuery authQuery;
	return authQuery;
}

CCharQuery& RepositoryManager::GetCharRepository()
{
	static CCharQuery charQuery;
	return charQuery;
}

CGameQuery& RepositoryManager::GetGameRepository()
{
	static CGameQuery gameQuery;
	return gameQuery;
}*/

RepositoryManager& RepositoryManager::instance()
{
	static RepositoryManager repoManager;
	return repoManager;
}