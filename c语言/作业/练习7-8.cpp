#include <stdio.h> 
int main()
{
	int m,n,i,j,k;
	printf("Enter m:");
	scanf("%d",&m);
	printf("Enter n:");
	scanf("%d",&n);
	int a[n][n],b[n][n];
	printf("Enter %d integers:",n*n);
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
			k=n-m+j;
			b[i][k]=a[i][j];
		 } 
	}
	for(i=0;i<n;i++)
	{
		for(k=0;k<n;k++)
		{
			printf("%4d",b[i][k]);
		}
		printf("\n");
	}
}
