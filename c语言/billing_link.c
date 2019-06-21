#include <string.h>  // 包含字符处理头文件
#include <stdlib.h>  // 包含动态内存分配头文件

#include "billing_file.c"  // 包含计费计时文件

lpBillingNode billingList = NULL;    // 计费信息链表

int getBilling();  // 声明getBilling()函数

/**************************************************************
[函数名]： initBillingList
[函数功能]：初始化计费信息链表，为头结点分配内存
[函数参数]：void
[返回值]：void
***************************************************************/
void initBillingList()
{
	lpBillingNode head = NULL;
	if(billingList == NULL)
	{
		head = (lpBillingNode)malloc(sizeof(BillingNode));
		
		head->next = NULL;
		billingList = head;
	}
}

/**************************************************************
[函数名]： releaseBillingList
[函数功能]：释放计费信息链表
[函数参数]：void
[返回值]：void
***************************************************************/
void releaseBillingList()
{
	//销毁链表
	lpBillingNode cur = billingList;
	lpBillingNode next = NULL;	
	while(cur != NULL) 
	{		
		next = cur->next;//结点内存释放前，next保存其后继
		free(cur); //释放结点内存
		cur = next;
	}
	billingList = NULL;
}

/**************************************************************
[函数名]： getBilling
[函数功能]：从计费信息文件中，获取计费信息保存到链表中
[函数参数]：void
[返回值]：int: 获取信息成功，获取信息失败
***************************************************************/
int getBilling()
{
	int nCount = 0;   // 计费信息数量
	Billing* pBilling = NULL;  // 计费信息
	lpBillingNode node = NULL;
	int i = 0;    // 循环变量
	lpBillingNode cur = NULL;

	// 如果链表不为空，释放链表
	if(billingList != NULL)
	{
		releaseBillingList();
	}

	// 初始化链表
	initBillingList();

	// 获取计费信息数量
	nCount = getBillingCount(BILLINGPATH);

	// 动态分配内存
	pBilling = (Billing*)malloc(sizeof(Billing) * nCount);
	if(pBilling != NULL)
	{
		// 获取计费信息
		if(FALSE == readBilling(pBilling, BILLINGPATH))
		{
			free(pBilling);
			return FALSE;
		}
	
		// 将计费信息保存到链表中
		for(i = 0, node = billingList; i < nCount; i++)
		{
			// 为当前结点分配内存
			cur = (lpBillingNode)malloc(sizeof(BillingNode));
			// 如果分配失败，则在返回FALSE前，需要释放pBilling的内存
			if(cur == NULL)
			{
				free(pBilling);
				return FALSE;
			}

			// 初始化新的空间，全部赋值为0
			memset(cur, 0, sizeof(BillingNode));

			// 将数据添加到结点中
			cur->data = pBilling[i];
			cur->next = NULL;

			// 将结点添加到链表中
			node->next = cur;
			node = cur;
		}
		free(pBilling);
		return TRUE;
	}
	return FALSE;
}

/**************************************************************
[函数名]： queryBilling
[函数功能]：在计费信息链表中，查询对应卡的计费信息，并获取该计费信息在链表中的索引号
[函数参数]：pName: 要查询的计费信息的卡号
          pIndex:查询到的计费信息在链表中的索引号
[返回值]：Billing*:查询到的计费信息指针
***************************************************************/
Billing* queryBilling(const char* pName, int* pIndex)
{
	lpBillingNode node = NULL;
	int nIndex = 0;

	if(FALSE == getBilling())
	{
		return NULL;
	}

	// 遍历链表
	node = billingList->next;
	while(node != NULL)
	{
		// 查询到卡号相同，并且没有结算的计费信息
		if(strcmp(node->data.aCardName, pName) == 0 && node->data.nStatus == 0)
		{
			return &node->data;
		}

		node = node->next;
		nIndex++;
		*pIndex = nIndex;
	}

	return NULL;
}


int main()
{
	char aName[18] = {0};    // 上机卡号
	
	getBilling();
	
	printf("请输入上机卡号(长度为1~18):");
	scanf("%s",aName);
	if(queryBilling(aName,0)!=NULL)
		printf("查询成功！\n");
	else
		printf("查询失败！\n");
	
	return 0;
}
