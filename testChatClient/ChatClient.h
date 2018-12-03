#pragma once
#undef _WINSOCKAPI_
#define _WINSOCKAPI_
#include <windows.h>
#include <WinSock2.h>
#include "define.h"

class CChatClient
{
public:
	CChatClient();
	~CChatClient();

private:
	SOCKET sockSvr;
	HANDLE hProc;

private:
	char m_szSendBuf[MAX_MSG_CONTENT_SIZE];
};

