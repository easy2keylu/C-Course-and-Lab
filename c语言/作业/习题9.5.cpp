#include<stdio.h>
struct bir{
	int year;
	int month;
	int day;
};
struct addb{
	char name[9];
	struct bir b;
	int phon;
};
int main()
{
	int i,j,n,index;
	struct addb addbs[9],temp;
	printf("Enter n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter No.%d name:",i+1);
		scanf("%s",addbs[i].name);
		printf("Enter No.%d birthday:(yyyy.mm.dd)",i+1);
		scanf("%d.%d.%d",&addbs[i].b.year,&addbs[i].b.month,&addbs[i].b.day);
		printf("Enter No.%d phone number:",i+1);
		scanf("%d",&addbs[i].phon);
	}
	for(i=0;i<n-1;i++)
	{
		index=i; 
		for(j=i+1;j<n;j++)
		{
			if(addbs[j].b.year<addbs[index].b.year)
			index=j;
			else if(addbs[j].b.month<addbs[index].b.month)
			index=j;
			else if(addbs[j].b.day<addbs[index].b.day)
			index=j;
		}
		temp=addbs[index];
		addbs[index]=addbs[i];
		addbs[i]=temp;
	}
	for(i=0;i<n;i++)
	{
		printf("%s\t%d.%d.%d\t%d\n",addbs[i].name,addbs[i].b.year,addbs[i].b.month,addbs[i].b.day,addbs[i].phon);
	}
}
