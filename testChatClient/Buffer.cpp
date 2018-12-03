#include <memory.h>
#include "Buffer.h"


CBuffer::CBuffer(const unsigned int nBufSize)
{
	m_pBuf = new char[nBufSize];
	memset(m_pBuf, 0, nBufSize);
	m_pReadNext = m_pBuf;
	m_pWriteNext = m_pBuf;
	m_pBufEnd = m_pBuf + nBufSize;
	m_bEmpty = false;
}


CBuffer::~CBuffer()
{
}

void CBuffer::AddBufSP(const char* pBuf, unsigned int unBufSize)
{
	do 
	{
		if (m_pBufEnd - m_pWriteNext >= unBufSize)
		{
			memcpy(m_pWriteNext, pBuf, unBufSize);
			m_pWriteNext = m_pWriteNext + unBufSize;
			break;
		}

		unsigned int unFrontSize = m_pBufEnd - m_pWriteNext;
		memcpy(m_pWriteNext, pBuf, unFrontSize);
		memcpy(m_pBuf, pBuf + unFrontSize, unBufSize - unFrontSize);
		m_pWriteNext = m_pBuf + unBufSize - unFrontSize;
	} while (0);

	if (m_pWriteNext == m_pReadNext || (m_pBuf == m_pReadNext && m_pBufEnd == m_pWriteNext))
	{
		m_bEmpty = true;
	}
}

bool CBuffer::AddBuf(const char* pBuf, unsigned int unBufSize)
{
	if (this->GetEmpytSize() + sizeof(unsigned int) < unBufSize)
	{
		return false;
	}

	this->AddBufSP((const char*)&unBufSize, sizeof(unsigned int));
	this->AddBufSP(pBuf, unBufSize);
	return true;
}

void CBuffer::GetBufSP(char* szBuf, unsigned int unBufSize, bool bDel)
{
	do 
	{
		if (m_pBufEnd - m_pReadNext >= unBufSize)
		{
			memcpy(szBuf, m_pReadNext, unBufSize);
			if (bDel)
			{
				m_pReadNext = m_pReadNext + unBufSize;
			}

			break;
		}

		unsigned int unFrontSize = m_pBufEnd - m_pReadNext;
		memcpy(szBuf, m_pReadNext, unFrontSize);
		memcpy(szBuf + unFrontSize, m_pBuf, unBufSize - unFrontSize);
		if (bDel)
		{
			m_pReadNext = m_pReadNext + unBufSize - unFrontSize;
		}
	} while (0);

	if (unBufSize != 0 && bDel)
	{
		m_bEmpty = false;
	}
}

unsigned int CBuffer::GetBuf(char *szBuf, unsigned int unBufSize)
{
	unsigned int unSize = 0;
	this->GetBufSP((char*)&unSize, sizeof(unsigned int), false);
	if (unSize > unBufSize)
	{
		return false;
	}

	this->GetBufSP((char*)&unSize, sizeof(unsigned int));
	this->GetBufSP(szBuf, unSize);
	return unSize;
}

unsigned int CBuffer::GetEmpytSize()
{
	if (m_bEmpty)
	{
		return 0;
	}

	if (m_pWriteNext > m_pReadNext)
	{
		return m_pBufEnd - m_pBuf - (m_pWriteNext - m_pReadNext);
	}

	return m_pReadNext - m_pWriteNext;
}