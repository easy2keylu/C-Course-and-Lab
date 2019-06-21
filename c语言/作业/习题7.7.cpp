#include<stdio.h>
int main()
{
	char str[80]; 
	int i=0;
	while((str[i]=getchar())!='\n')
	{
		i++;
	}
	str[i]='\0';
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
		{
			str[i]='Z'-str[i]+'A';
		}
	}
	for(i=0;str[i]!='\0';i++)
	{
		putchar(str[i]);
	}
	return 0;
}
