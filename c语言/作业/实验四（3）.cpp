#include <stdio.h>
int main()
{
	char a[80];
	int i=0;
	printf("请输入字符串:");
	while(a[i]=getchar()!='\n')
	{
		i++;
	}
	a[i]='\0';
	printf("字符串的长度为:%d",i);
 } 
