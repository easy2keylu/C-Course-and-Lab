#include<stdio.h>
int main()
{
	int i,n=0;
	char str[80];
	printf("Enter words:\n");
	while((str[i]=getchar())!='\n')
	{
		i++; 
	}
	str[i]='\0';
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
		{
			continue;
		}
		else if(str[i]>='A'&&str[i]<='Z')
		{
			n++;
		}
	}
	printf("The number of capital consonant word is %d .",n);
 } 
