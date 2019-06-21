#include<stdio.h>
struct book{
	char name[10];
	float price;
};
int main()
{
	int i,n;
	struct book b1,max,min;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter the book's name and price\n");
	for(i=1;i<=n;i++)
	{
		printf("No.%d",i);
		scanf("%s %f",b1.name,&b1.price);
		if(i==1)
		{
			max=b1;
			min=b1; 
		}
		if(max.price<b1.price)
		max=b1;
		if(min.price>b1.price)
		min=b1;
	}
	printf("定价最高的书的名称:%s 定价:%f\n定价最低的书的名称:%s 定价:%f",max.name,max.price,min.name,min.price);
}
