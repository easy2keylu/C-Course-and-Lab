#include<stdio.h>
int main()
{
	int n,i;
	printf("Enter n:\n");
	scanf("%d",&n);
	int a[n-1];
	for(i=n;i>=1;i--)
	{
		printf("Enter number %d\n",n-i+1);
		scanf("%d",&a[i-1]);
	}
	for(i=0;i<n;i++)
	{
		printf("%2d",a[i]);
	}
}
