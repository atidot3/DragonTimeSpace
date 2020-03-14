#ifndef _BITFLAGMANAGER_H_
#define _BITFLAGMANAGER_H_

#pragma once

#include <Utils\Define.h>

class BitFlagManager
{
public:

	BitFlagManager(void);
	virtual ~BitFlagManager(void);

public:
	bool							Create(const DWORD& dwMaxFlagCount);
	bool							Create(void* pvFlag, const DWORD& dwMaxFlagCount);
	void							Destroy();
protected:
	void							Init();
public:
	bool							Set(const DWORD& dwIndex);
	bool							Unset(const DWORD& dwIndex);
	bool							IsSet(const DWORD& dwIndex);
	void							Not();
	bool							Replace(void* pvNewFlag, const DWORD& dwMaxFlagCount);
public:
	BYTE							*GetRawData() { return m_pabyFlag; }
	const DWORD&					GetBytesUsed() { return m_dwBytesUsed; }
	const DWORD&					GetMaxFlagCount() { return m_dwMaxFlagCount; }
private:
	BYTE							*m_pabyFlag;
	DWORD							m_dwBytesUsed;
	DWORD							m_dwMaxFlagCount;
};

#endif // !_BITFLAGMANAGER_H_