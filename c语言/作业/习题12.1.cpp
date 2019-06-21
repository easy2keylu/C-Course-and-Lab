#include <stdio.h>
#include <stdlib.h>
int main()
{
	int sumAlpha = 0, sumNum = 0, sumRest = 0;
	char c;
	FILE *fp;
	if ((fp = fopen("习题12.1.txt", "r")) == NULL)
	{
		printf("无法打开这个文件!\n");
		exit(0);
	}
	while (!feof(fp))
	{
		c = fgetc(fp);
		if (c >= '0'&&c <= '9')
		{
			++sumNum;
		}
		else if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
		{
			++sumAlpha;
		}
		else
		{
			++sumRest;
		}
	}
	printf("There are %d characters, %d numbers and %d other symbols.\n", sumAlpha, sumNum, sumRest-1);
	if (fclose(fp))
	{
		printf("无法关闭这个文件!\n");
		exit(0);
	}
	return 0;
}
