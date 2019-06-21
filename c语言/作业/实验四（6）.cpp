#include<stdio.h>
int main()
{
	int i=0,j;
	char a[80];
	printf("ÇëÊäÈë×Ö·û´®:");
	while((a[i]=getchar())!='\n')
	{
		i++;
	}
	a[i]='\0';
	for(j=0;j<i;j++)
	{
		if(a[j]==' ')
		{
			continue;
		}
		else
		{
			printf("%c",a[j]);
		}
	}
 } 
