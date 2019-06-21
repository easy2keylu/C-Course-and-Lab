#include <stdio.h>
int main()
{
	int n,m,i,j,k=0;
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
		for(j=0;j<n;j++)
		{
			if(b[i-1]==a[j])
			{
				c[k]=b[i-1];
				k++;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(b[i]==c[j])
			{
				break;
			}
			if(j<k)
			{
				continue;
			}
			if(b[i]!=c[k])
			{
				printf("%d\n",b[i]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=k;j++)
		{
			if(a[i]==c[j])
			{
				break;
			}
			if(j<k)
			{
				continue;
			}
			if(a[i]!=c[k])
			{
				printf("%d\n",a[i]);
			}
		}
	}
 } 
