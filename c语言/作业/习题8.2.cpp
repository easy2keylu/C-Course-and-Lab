#include<stdio.h>
int search(int list[],int n,int x);
int main()
{
	int n,x;
	printf("Enter n:");
	scanf("%d",&n);
	int list[n];
	for(x=0;x<n;x++)
	{
		printf("Enter number %d:",x+1);
		scanf("%d",&list[x]);
	}
	printf("Enter x:");
	scanf("%d",&x);
	printf("%d",search(list,n,x));
}
int search(int list[],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(list[i]==x)
		{
			return i;
			break;
		}
		if(i==n-1)
		{
			return -1;
		}	
	}
}
