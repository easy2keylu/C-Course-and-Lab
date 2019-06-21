#include <stdio.h>
int main()
{
	char s[80];
	int i=0,j;
	while((s[i]=getchar())!='\n')
	{
		i++;
	}
	s[i]='\0';
	for(j=(i-1);j>=0;j--)
	{
		putchar(s[j]);
	}
}
