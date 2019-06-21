#include <stdio.h>
int main()
{
	int n,i,j,sum=0;
	printf("Enter n:");
	scanf("%d",&n);
	int a[n][n];
	printf("Enter %d integers:\n",n*n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=sum+a[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		sum=sum-a[i][n-1];
	}
	for(j=0;j<n;j++)
	{
		sum=sum-a[n-1][j];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i+j==n-1)
			{
				sum=sum-a[i][j];
			}
		}
	}
	sum=sum+a[0][n-1]+a[n-1][0]+a[n-1][n-1];
	printf("%d",sum);
 } 
