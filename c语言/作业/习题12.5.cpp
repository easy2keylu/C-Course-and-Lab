#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *ifp;
	if (!(ifp = fopen("ϰ��12.5.txt", "r")))
	{
		printf("�޷��򿪴��ļ�.\n");
		exit(0);
	}
	char line[80];
	while (!feof(ifp))
	{
		fgets(line, 80, ifp);
		if (strstr(line, "for"))
		{
			printf("%s", line);
		}
	}
	puts("");
	if (fclose(ifp))
	{
		printf("�޷��رմ��ļ�.\n");
		exit(0);
	}
	return 0;
}
