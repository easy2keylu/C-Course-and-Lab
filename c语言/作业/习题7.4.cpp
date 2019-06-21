#include<stdio.h>
int main()
{
	int m,n,i,j;
	printf("Enter m:");
	scanf("%d",&m);
	printf("Enter n:");
	scanf("%d",&n);
	int a[m][n],sum[m];
	printf("Enter %d integers:");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==0)
			{
				sum[i]=0;
			}
			sum[i]=sum[i]+a[i][j];
		}
		printf("第%d行的和为:%d\n",i+1,sum[i]);
	}
	
}
