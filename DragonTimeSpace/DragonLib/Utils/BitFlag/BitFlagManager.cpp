#include "BitFlagManager.h"
#include <cstdlib>
#include <cstring>

//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
BitFlagManager::BitFlagManager(void)
{
	Init();
}
//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
BitFlagManager::~BitFlagManager(void)
{
	Destroy();
}
//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
bool BitFlagManager::Create(const DWORD& dwMaxFlagCount)
{
	return Create(NULL, dwMaxFlagCount);
}
//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
bool BitFlagManager::Create(void* pvFlag, const DWORD& dwMaxFlagCount)
{
	if (NULL != m_pabyFlag)
	{
		//- yoshiki : To log system!
		return false;
	}

	DWORD dwRequiredBytes = (dwMaxFlagCount - 1) / 8 + 1;

	m_pabyFlag = new BYTE[dwRequiredBytes];
	if (NULL == m_pabyFlag)
	{
		//- yoshiki : To log system!
		return false;
	}

	if (NULL == pvFlag)
	{
		::memset(m_pabyFlag, 0, dwRequiredBytes * sizeof(BYTE));
	}
	else
	{
		::memcpy(m_pabyFlag, pvFlag, dwRequiredBytes * sizeof(BYTE));
	}
	m_dwBytesUsed = dwRequiredBytes;

	m_dwMaxFlagCount = dwMaxFlagCount;

	return true;
}
//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
void BitFlagManager::Destroy()
{
	if (NULL != m_pabyFlag)
	{
		delete[] m_pabyFlag;
		m_pabyFlag = NULL;
	}
	m_dwBytesUsed = 0;

	m_dwMaxFlagCount = 0;
}
//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
void BitFlagManager::Init()
{
	m_pabyFlag = NULL;
	m_dwBytesUsed = 0;

	m_dwMaxFlagCount = 0;
}
//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
bool BitFlagManager::Set(const DWORD& dwIndex)
{
	if (m_dwMaxFlagCount <= dwIndex)
	{
		return false;
	}

	DWORD dwByteIndex = dwIndex / 8;
	BYTE byMask = 0x01u << (BYTE)(dwIndex % 8);

	m_pabyFlag[dwByteIndex] |= byMask;

	return true;
}
//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
bool BitFlagManager::Unset(const DWORD& dwIndex)
{
	if (m_dwMaxFlagCount <= dwIndex)
	{
		return false;
	}

	DWORD dwByteIndex = dwIndex / 8;
	BYTE byMask = 0x01u << (BYTE)(dwIndex % 8);

	m_pabyFlag[dwByteIndex] &= ~byMask;

	return true;
}
//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
bool BitFlagManager::IsSet(const DWORD& dwIndex)
{
	if (m_dwMaxFlagCount <= dwIndex)
	{
		return false;
	}

	DWORD dwByteIndex = dwIndex / 8;
	BYTE byMask = 0x01u << (BYTE)(dwIndex % 8);

	if (0x00u == (m_pabyFlag[dwByteIndex] & byMask))
	{
		return false;
	}
	return true;
}
//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
void BitFlagManager::Not()
{
	for (DWORD dwByteIndex = 0; dwByteIndex < m_dwBytesUsed; dwByteIndex++)
	{
		m_pabyFlag[dwByteIndex] = ~m_pabyFlag[dwByteIndex];
	}
}
//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
bool BitFlagManager::Replace(void* pvNewFlag, const DWORD& dwMaxFlagCount)
{
	DWORD dwRequiredBytes = (dwMaxFlagCount - 1) / 8 + 1;

	if (NULL == pvNewFlag)
	{
		//- yoshiki : To log system!
		return false;
	}

	BYTE* pabyFlag = new BYTE[dwRequiredBytes];
	if (NULL == pabyFlag)
	{
		//- yoshiki : To log system!
		return false;
	}
	::memcpy(pabyFlag, pvNewFlag, dwRequiredBytes * sizeof(BYTE));

	if (NULL != m_pabyFlag)
	{
		delete[] m_pabyFlag;
		m_pabyFlag = NULL;
	}

	m_pabyFlag = pabyFlag;
	m_dwBytesUsed = dwRequiredBytes;

	m_dwMaxFlagCount = dwMaxFlagCount;

	return true;
}