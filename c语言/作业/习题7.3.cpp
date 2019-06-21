#include<stdio.h>
int main()
{
	int n,i,j,k;
	printf("Enter n:");
	scanf("%d",&n);
	int a[n][n];
	printf("Enter %d integers:",n*n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<(n-1);i++)
	{
		for(j=(i+1);j<n;j++)
		{
			if(a[j][i]==0)
			{
				continue;
			}
			else
			{
				k++;
				break;
			}
		}
	}
	if(k==0)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
}
