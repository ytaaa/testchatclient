#include <WS2tcpip.h>
#include "ChatClient.h"
#include "define.h"

DWORD WINAPI ProcessThread(LPVOID lpParameter)
{
	SOCKET sockCli = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sockaddr_in svrAddr;
	svrAddr.sin_family = AF_INET;
	inet_pton(AF_INET, SVRIP, &svrAddr.sin_addr);
	svrAddr.sin_port = htons(PORT);
	sockCli = connect(sockCli, (const sockaddr*)&svrAddr, sizeof(sockaddr));

	return 0;
}

CChatClient::CChatClient()
{
	hProc = CreateThread(NULL, 0, ProcessThread, NULL, 0, NULL);
}


CChatClient::~CChatClient()
{
}
