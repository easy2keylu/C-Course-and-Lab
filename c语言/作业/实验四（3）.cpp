#include <stdio.h>
int main()
{
	char a[80];
	int i=0;
	printf("�������ַ���:");
	while(a[i]=getchar()!='\n')
	{
		i++;
	}
	a[i]='\0';
	printf("�ַ����ĳ���Ϊ:%d",i);
 } 
