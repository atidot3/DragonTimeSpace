#include "RepositoryManager.h"

CAuthQuery& RepositoryManager::GetAuthRepository()
{
	static CAuthQuery authQuery;
	return authQuery;
}

CCGServerQuery& RepositoryManager::GetCGServerRepository()
{
	static CCGServerQuery server;
	return server;
}

RepositoryManager& RepositoryManager::instance()
{
	static RepositoryManager repoManager;
	return repoManager;
}