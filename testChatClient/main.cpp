#include "ChatClient.h"
#include "Buffer.h"

#include <stdio.h>
#include <string.h>
#include <time.h>

FILE* pFile;

int main(int argc, char* argv[])
{
	// CChatClient* pClient = new CChatClient();
	char buf[100];
	CBuffer* pBuffer = new CBuffer(51);
	fopen_s(&pFile, "testData", "r");
	int testcount = 1000;
	char cmd[20];
	FILE* pResult;
	fopen_s(&pResult, "resbuf", "w");
	while (testcount--)
	{
		fscanf(pFile, "%s", cmd);
		if (!strcmp(cmd, "read"))
		{
			memset(buf, 0, sizeof(buf));
			int size = pBuffer->GetBuf(buf, 100);
			fprintf(pResult, "%d\n", size);
			if (size != 0)
			{
				fprintf(pResult, "%s\n", buf);
			}
		}
		else
		{
			int size;
			fscanf(pFile, "%d", &size);
			fscanf(pFile, "%s", buf);
			bool succ = pBuffer->AddBuf(buf, size);
			fprintf(pResult, "%d\n", succ);
		}
	}
	return 0;
}