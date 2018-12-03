#pragma once
#include <string.h>
#include <WinSock2.h>

enum MSG_TYPE
{
	MSG_TYPE_NONE = 0,
	MSG_TYPE_LOGIN = 1,
	MSG_TYPE_USER_LIST = 2,
	MSG_TYPE_CHAT = 3,
};

struct MSG_HEADER
{
	unsigned short usMsgSize;
	MSG_TYPE eMsgType;
};

const unsigned int MAX_MSG_CONTENT_SIZE = 1024;
const unsigned int MAX_MSG_SIZE = MAX_MSG_CONTENT_SIZE + sizeof(MSG_HEADER);
const unsigned int MAX_NAME_SIZE = 32;
const char SVRIP[] = "127.0.0.1";
const unsigned int PORT = 12345;
const unsigned int BACKLOG = 20;

struct USER_INFO 
{
	unsigned int id;
	char szName[MAX_NAME_SIZE];
	USER_INFO(unsigned int ID, const char* Name) : id(ID)
	{
		strncpy_s(szName, Name, MAX_NAME_SIZE);
	}
};