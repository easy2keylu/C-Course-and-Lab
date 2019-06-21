#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *ifp;
	if (!(ifp = fopen("习题12.5.txt", "r")))
	{
		printf("无法打开此文件.\n");
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
		printf("无法关闭此文件.\n");
		exit(0);
	}
	return 0;
}
