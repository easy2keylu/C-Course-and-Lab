#include<stdio.h>
int main()
{
	int n,i,b,c,d;
	printf("Enter n:\n");
	scanf("%d",&n);
	int a[n-1];
	printf("Enter number 1:\n");
	scanf("%d",&a[0]);
	b=d=a[0];
	c=0;
	for(i=1;i<n;i++)
	{
		printf("Enter number %d:\n",i+1);
		scanf("%d",&a[i]);
		if(a[i]>d)
		{
			b=a[i],c=i;
		}
	
	}
	printf("%d,%d",b,c);
 } 
