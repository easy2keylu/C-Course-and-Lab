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
	printf("����ʹ�ñ����������½�������ϵ�ˣ�\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("�������%d����ϵ�˵����֣�",i+1);
		scanf("%s",lxr[i].name);
		printf("�����������գ���ʽ����.��.�գ���");
		scanf("%d.%d.%d",&lxr[i].b.year,&lxr[i].b.month,&lxr[i].b.day);
		printf("��������绰���룺");
		scanf("%s",lxr[i].pnum);
	}
	sum=n;
	loop1:printf("\n���������µ�ͨѶ¼\n����\t����\t\t�绰����\n");
	for(i=0;i<sum;i++)
	{
		printf("%s\t%d.%d.%d\t%s\n",lxr[i].name,lxr[i].b.year,lxr[i].b.month,lxr[i].b.day,lxr[i].pnum);
	}
	loop2:printf("\n������������ʲô��\n1.�޸�\n2.���\n3.ɾ��\n4.��ѯ\n5.�˳�\n");
	scanf("%d",&choice);
	if(choice==5)
	{
		printf("\n�˳�������ͨѶ¼���ᱻ���棬ȷ���˳���\n1.�˳�\n2.ȡ��\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("\nллʹ�ã�");
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
			printf("\n�����޸ĵڼ�����ϵ�ˣ�\n");
			scanf("%d",&n);
			printf("\n�����޸�ʲô��\n1.����\n2.����\n3.�绰����\n");
			scanf("%d",&i);
			if(i==1)
			{
				printf("\n��������������");
				scanf("%s",lxr[n-1].name);
			}
			if(i==2)
			{
				printf("\n�������µ����գ�");
				scanf("%d.%d.%d",&lxr[n-1].b.year,&lxr[n-1].b.month,&lxr[n-1].b.day);
			}
			if(i==3)
			{
				printf("\n�������µĵ绰���룺");
				scanf("%s",lxr[n-1].pnum);
			}
			printf("\n�޸ĳɹ���\n");
			goto loop1;
			break;
		case 2:
			printf("\n������Ӽ�����ϵ�ˣ�\n");
			scanf("%d",&n);
			for(i=sum;i<sum+n;i++)
			{
					printf("\n�������%d����ϵ�˵����֣�",i+1);
	            	scanf("%s",lxr[i].name);
		            printf("�����������գ�����ʽ����.��.�գ�");
		            scanf("%d.%d.%d",&lxr[i].b.year,&lxr[i].b.month,&lxr[i].b.day);
		            printf("��������绰���룺");
		            scanf("%s",lxr[i].pnum);
			}
			sum=sum+n;
			printf("\n��ӳɹ���\n");
			goto loop1;
			break;
		case 3:
			printf("\n����ɾ���ڼ�����ϵ�ˣ�");
			scanf("%d",&n);
			for(i=n-1;i<sum-1;i++)
			{
				lxr[i]=lxr[i+1];
			}
			sum--;
			printf("\nɾ���ɹ���\n");
			goto loop1;
			break;
		case 4:
			printf("\n����ͨ�����ַ�ʽ��ѯ��\n1.����\n2.����\n3.�绰����\n");
			scanf("%d",&n);
			switch(n)
			{
				case 1:{
					char a[80];
					int j=0;
					printf("\n������������");
					scanf("%s",a);
					printf("��ѯ�����");
					for(i=0;i<sum;i++)
					{
						if(strcmp(lxr[i].name,a)==0)
						{
							printf("\n����\t����\t\t�绰����\n%s\t%d.%d.%d\t%s\n",lxr[i].name,lxr[i].b.year,lxr[i].b.month,lxr[i].b.day,lxr[i].pnum);
							j++;
						}
						if(i<sum-1)
						{
							continue;
						}
						if(j==0)
						{
							printf("\n�޽��\n");
						}
					}
					break;
				}
				case 2:{
					int b,c,d,k=0;
					printf("\n�����������գ���ʽ����.��.�գ���");
					scanf("%d.%d.%d",&b,&c,&d);
					printf("��ѯ�����");
					for(i=0;i<sum;i++)
					{
						if(b==lxr[i].b.year&&c==lxr[i].b.month&&d==lxr[i].b.day)
						{
							printf("\n����\t����\t\t�绰����\n%s\t%d.%d.%d\t%s\n",lxr[i].name,lxr[i].b.year,lxr[i].b.month,lxr[i].b.day,lxr[i].pnum);
							k++;
						}
						if(i<sum-1)
						{
							continue;
						}
						if(k==0)
						{
							printf("\n�޽��\n");
						}
					} 
					break;
				}
				case 3:{
					char e[80];
					int l=0;
					printf("\n������绰���룺");
					scanf("%s",e);
					printf("��ѯ�����");
					for(i=0;i<sum;i++)
					{
						if(strcmp(lxr[i].pnum,e)==0)
						{
							printf("\n����\t����\t\t�绰����\n%s\t%d.%d.%d\t%s\n",lxr[i].name,lxr[i].b.year,lxr[i].b.month,lxr[i].b.day,lxr[i].pnum);
							l++;
						}
						if(i<sum-1)
						{
							continue;
						}
						if(l==0)
						{
							printf("\n�޽��\n");
						}
					}
					break;
				}
			}
			goto loop2;
		break;
	}
}
