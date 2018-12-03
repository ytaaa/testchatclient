#include "ChatClient.h"
#include "Buffer.h"

int main(int argc, char* argv[])
{
	// CChatClient* pClient = new CChatClient();
	CBuffer* pBuffer = new CBuffer(10);
	pBuffer->AddBuf("asdf", 4);
	char szBuf[10] = { 0 };
	int size = pBuffer->GetBuf(szBuf, 10);
	return 0;
}