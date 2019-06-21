#include<stdio.h>
#include<string.h>
struct bir{
	int year;
	int month;
	int day;
};
struct txl{
	char name[80];
	char pnum[80];
	struct bir b;
};
int main()
{
	int i,n,sum,choice;
	struct txl lxr[80];
	printf("初次使用本程序，您想新建几个联系人？\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("请输入第%d个联系人的名字：",i+1);
		scanf("%s",lxr[i].name);
		printf("请输入其生日（格式：年.月.日）：");
		scanf("%d.%d.%d",&lxr[i].b.year,&lxr[i].b.month,&lxr[i].b.day);
		printf("请输入其电话号码：");
		scanf("%s",lxr[i].pnum);
	}
	sum=n;
	loop1:printf("\n这是您最新的通讯录\n姓名\t生日\t\t电话号码\n");
	for(i=0;i<sum;i++)
	{
		printf("%s\t%d.%d.%d\t%s\n",lxr[i].name,lxr[i].b.year,lxr[i].b.month,lxr[i].b.day,lxr[i].pnum);
	}
	loop2:printf("\n您接下来想做什么？\n1.修改\n2.添加\n3.删除\n4.查询\n5.退出\n");
	scanf("%d",&choice);
	if(choice==5)
	{
		printf("\n退出后您的通讯录不会被保存，确定退出吗？\n1.退出\n2.取消\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\n谢谢使用！");
			return 0;
		} 
		if(choice==2)
		{
			goto loop2;
		}
	}
	switch(choice)
	{
		case 1:
			printf("\n您想修改第几个联系人？\n");
			scanf("%d",&n);
			printf("\n您想修改什么？\n1.姓名\n2.生日\n3.电话号码\n");
			scanf("%d",&i);
			if(i==1)
			{
				printf("\n请输入新姓名：");
				scanf("%s",lxr[n-1].name);
			}
			if(i==2)
			{
				printf("\n请输入新的生日：");
				scanf("%d.%d.%d",&lxr[n-1].b.year,&lxr[n-1].b.month,&lxr[n-1].b.day);
			}
			if(i==3)
			{
				printf("\n请输入新的电话号码：");
				scanf("%s",lxr[n-1].pnum);
			}
			printf("\n修改成功！\n");
			goto loop1;
			break;
		case 2:
			printf("\n您想添加几个联系人？\n");
			scanf("%d",&n);
			for(i=sum;i<sum+n;i++)
			{
					printf("\n请输入第%d个联系人的名字：",i+1);
	            	scanf("%s",lxr[i].name);
		            printf("请输入其生日：（格式：年.月.日）");
		            scanf("%d.%d.%d",&lxr[i].b.year,&lxr[i].b.month,&lxr[i].b.day);
		            printf("请输入其电话号码：");
		            scanf("%s",lxr[i].pnum);
			}
			sum=sum+n;
			printf("\n添加成功！\n");
			goto loop1;
			break;
		case 3:
			printf("\n您想删除第几个联系人？");
			scanf("%d",&n);
			for(i=n-1;i<sum-1;i++)
			{
				lxr[i]=lxr[i+1];
			}
			sum--;
			printf("\n删除成功！\n");
			goto loop1;
			break;
		case 4:
			printf("\n您想通过何种方式查询？\n1.姓名\n2.生日\n3.电话号码\n");
			scanf("%d",&n);
			switch(n)
			{
				case 1:{
					char a[80];
					int j=0;
					printf("\n请输入姓名：");
					scanf("%s",a);
					printf("查询结果：");
					for(i=0;i<sum;i++)
					{
						if(strcmp(lxr[i].name,a)==0)
						{
							printf("\n姓名\t生日\t\t电话号码\n%s\t%d.%d.%d\t%s\n",lxr[i].name,lxr[i].b.year,lxr[i].b.month,lxr[i].b.day,lxr[i].pnum);
							j++;
						}
						if(i<sum-1)
						{
							continue;
						}
						if(j==0)
						{
							printf("\n无结果\n");
						}
					}
					break;
				}
				case 2:{
					int b,c,d,k=0;
					printf("\n请输入其生日（格式：年.月.日）：");
					scanf("%d.%d.%d",&b,&c,&d);
					printf("查询结果：");
					for(i=0;i<sum;i++)
					{
						if(b==lxr[i].b.year&&c==lxr[i].b.month&&d==lxr[i].b.day)
						{
							printf("\n姓名\t生日\t\t电话号码\n%s\t%d.%d.%d\t%s\n",lxr[i].name,lxr[i].b.year,lxr[i].b.month,lxr[i].b.day,lxr[i].pnum);
							k++;
						}
						if(i<sum-1)
						{
							continue;
						}
						if(k==0)
						{
							printf("\n无结果\n");
						}
					} 
					break;
				}
				case 3:{
					char e[80];
					int l=0;
					printf("\n请输入电话号码：");
					scanf("%s",e);
					printf("查询结果：");
					for(i=0;i<sum;i++)
					{
						if(strcmp(lxr[i].pnum,e)==0)
						{
							printf("\n姓名\t生日\t\t电话号码\n%s\t%d.%d.%d\t%s\n",lxr[i].name,lxr[i].b.year,lxr[i].b.month,lxr[i].b.day,lxr[i].pnum);
							l++;
						}
						if(i<sum-1)
						{
							continue;
						}
						if(l==0)
						{
							printf("\n无结果\n");
						}
					}
					break;
				}
			}
			goto loop2;
		break;
	}
}
