#include <stdio.h>
int main()
{
	int i=0,k=0,l=0;
	char s[80],h[80],a=' ';
	printf("请输入字符串:\n");
	while((s[i]=getchar())!='#')
	{
		i++;
	}
	s[i]='\0';
	for(i=0;s[i]!='\0';i++)
	{
		if(k==0&&s[i]=='-')
		{
			a=s[i];
			k++;
		}
		if(s[i]>='0'&&s[i]<='9'||s[i]>='a'&&s[i]<='f'||s[i]>='A'&&s[i]<='F')
		{
			h[k]=s[i];
		    k++;
		}
	}
	h[k]='\0';
	for(i=0;h[i]!='\0';i++)
	{
		if(h[i]>='0'&&h[i]<='9')
		{
			l=l*16+h[i]-'0';
		}
		else if(h[i]>='A'&&h[i]<='F')
		{
			l=l*16+h[i]-'A'+10;
		}
	    else if(h[i]>='a'&&h[i]<='f')
		{
			l=l*16+h[i]-'a'+10;
		}
	}
	printf("十进制数为%c%d",a,l);
	return 0;
}

