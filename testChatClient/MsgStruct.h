#pragma once
#include "define.h"


struct MSG_BASE 
{
	MSG_HEADER stHeader;
	char szBuf[MAX_MSG_CONTENT_SIZE] = {0};
};

struct MSG_LOGIN 
{
	char szName[32] = { 0 };
};

struct MSG_USER_LIST
{
	unsigned int unTot;
	USER_INFO stInfo[0];
};

struct MSG_CHAT 
{
	SOCKET sockTarget;
	unsigned int unSize;
	char szContent[0];
};