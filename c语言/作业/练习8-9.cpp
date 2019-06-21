#include<stdio.h>
#include<stdlib.h>
void bubble(int a[],int n);
int main(void)
{
	int n,*p;
	int i;
	printf("Enter n:");
	scanf("%d",&n);
	if((p=(int*)calloc(n,sizeof(int)))==NULL)
	{
		printf("Not able to allocate memory.\n");
		exit(1);
	}
	printf("Enter %d integers:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",p+i);
	}
	bubble(p,n);
	printf("After sorted:");
	for(i=0;i<n;i++)
	{
		printf("%2d",*(p+i));
	}
	free(p);
	return 0;
}
void bubble(int a[],int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
		}
	}
}
