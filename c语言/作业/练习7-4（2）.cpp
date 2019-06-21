#include <stdio.h>
int main()
{
	int n,m,i,j,k=0,l=0;
	printf("Enter n:\n");
	scanf("%d",&n);
	int a[n-1];
	for(i=1;i<=n;i++)
	{
		printf("Enter number %d:\n",i);
		scanf("%d",&a[i-1]);
	}
	printf("Enter m:\n");
	scanf("%d",&m);
	int b[m-1];
	int c[9];
	for(i=1;i<=m;i++)
	{
		printf("Enter number %d:\n",i);
		scanf("%d",&b[i-1]);
		for(j=1;j<=n;j++)
		{
			if(b[i]==a[j-1])
			{
				break;
			}
			if(j<n)
			{
				continue;
			}
			if(b[i]!=a[n-1])
			{
				c[k]=b[i];
				k++;
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		for(j=l;j<=(k-1);j++)
		{
			if(b[i]==c[j])
			{
				l++;
				break;
			}
			if(j<(k-1))
			{
				continue;
			}
			if(b[i]!=c[k])
			{
				printf("%2d",b[i]);
				l++;
			 } 
		}
	}
}
