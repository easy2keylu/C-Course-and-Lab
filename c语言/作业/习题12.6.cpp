#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *ifp, *ofp;
	if (!(ifp = fopen("hello.c", "r")))
	{
		printf("无法打开 \"hello.c\"\n");
		exit(0);
	}
	if (!(ofp = fopen("new_hello.c", "w")))
	{
		printf("无法打开\"new_hello.c\"\n");
		exit(0);
	}
	char line[96], *cOut, *pos;
	while (!feof(ifp))
	{
		fgets(line, 96, ifp);
		pos = strstr(line, "//");
		if (!pos)
		{
			fputs(line, ofp);
		}
		else
		{
			for (cOut = &line[0]; cOut != pos; ++cOut)
			{
				fputc(*cOut, ofp);
			}
			fprintf(ofp,"\n");
		}
	}
	if (fclose(ifp))
	{
		printf("无法关闭 \"hello.c\"\n");
		exit(0);
	}
	if (fclose(ofp))
	{
		printf("无法关闭 \"new_hello.c\"\n");
		exit(0);
	}
	return 0;
}
