#pragma once
class CBuffer
{
public:
	CBuffer(const unsigned int nBufSize = DEFAULT_BUF_SIZE);
	~CBuffer();

public:
	bool AddBuf(const char* pBuf, unsigned int nBufSize);
	unsigned int GetBuf(char *szBuf, unsigned int unBufSize);
	unsigned int GetEmpytSize();

private:
	void AddBufSP(const char* pBuf, unsigned int nBufSize);
	void GetBufSP(char* szBuf, unsigned int nBufSize, bool bDel = true);

private:
	char* m_pBuf;
	char* m_pReadNext;
	char* m_pWriteNext;
	char* m_pBufEnd;
	bool m_bFull;
	bool m_bEmpty;

private:
	static const unsigned int DEFAULT_BUF_SIZE = 65535;
};

