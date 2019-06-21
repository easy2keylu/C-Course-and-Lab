#include <stdio.h>
#include <stdlib.h>

struct Student
{
	long num;
	float score;
	struct Student *next;
};
struct Student *creat(void);
void print(struct Student *p);
int n,t;

int main()
{ 
	struct Student *pt;
	pt=creat();
	printf("接下来做什么？\n1.查找\n2.打印\n");
	scanf("%d",&t); 
	switch(t) 
	print(pt);
	return 0;
}

struct Student *creat(void) 
{ 
	struct Student *head,*p1,*p2;  n=0;
	p1=p2=( struct Student*) malloc(sizeof(struct Student));
	printf("请输入第1个学生的学号与成绩\n");
	scanf("%ld%f",&p1->num,&p1->score); 
	head=NULL;
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1) 
			head=p1;
		else  
			p2->next=p1;
		p2=p1;
		p1=(struct Student*)malloc(sizeof(struct Student)); 
		printf("请输入第%d个学生的成绩（结束请输入0 -1）\n",n+1);
		scanf("%ld%f",&p1->num,&p1->score);
	}
	p2->next=NULL;    
	return(head);
}

void print(struct Student *p)  
{
	printf("\n这%d个学生的学号与对应成绩为:\n",n);   
	if(p!=NULL)
	{ 
      do
      {
 		 printf("%ld %5.1f\n",p->num,p->score);
		 p=p->next;
      }while(p!=NULL);
 	} 
}
