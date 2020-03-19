#ifndef _REPOSITORYMANAGER_H_
#define _REPOSITORYMANAGER_H_
#pragma once

#include "Auth/AuthQuery.h"
#include "CGServer/CGServerQuery.h"

class RepositoryManager final
{
public:
	RepositoryManager() {}
	~RepositoryManager() {}
	static RepositoryManager& instance();
	static CAuthQuery& GetAuthRepository();
	static CCGServerQuery& GetCGServerRepository();
};

#define sQueryRepository RepositoryManager::instance()

#endif //! _REPOSITORYMANAGER_H_