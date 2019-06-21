#include <stdio.h>
int main()
{
	int n,m,i,j,k=0,l=0,o=1;
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
	int d[9];
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
			    d[l]=b[i];
			    l++;
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
				d[l]=a[i];
				l++;
			}
		}
	}
	for(i=0;i<=(l-1);i++)
	{
		if(i<(l-1))
		{
	        for(j=o;j<=(l-1);j++)
		    {   
			    if(d[i]==d[j])
			    {
				    o++;
				    break;
			    }
			    if(j<(l-1))
			    {
				    continue;
			    }
			    if(d[i]!=d[l-1])
			    {
				    printf("%2d",d[i]);
			    }
		    }
    	}
	    else
	    {
		    printf("%2d",d[i]);
	    }
	}
 } 
