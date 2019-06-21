#include <stdio.h>   // 包含文件处理头文件
#include <stdlib.h>  // 包含动态内存分配头文件
#include <time.h> 
#define FALSE 0
#define TRUE  1
#define BILLINGPATH "billing.dat" // 计费信息保存路径

// 计费信息结构体
typedef struct Billing
{
	char aCardName[18];    // 卡号
	time_t tStart;         // 上机时间
	time_t tEnd;           // 下机时间
	float fAmount;         // 消费金额
	int nStatus;           // 消费状态，0-未结算，1-已经结算
	int nDel;              // 删除标识，0-未删除,1-删除
}Billing;

// 计费信息结点
typedef struct BillingNode
{
	Billing data;
	struct BillingNode *next;
}BillingNode, *lpBillingNode;

/*************************************************
[函数名] saveBilling
[功能]  保存计费信息
[参数]  pBilling: 计费信息结构体指针
       pPath: 保存计费信息文件路径
[返回值] int型，TRUE表示成功，FALSE表示失败
*************************************************/
int saveBilling(const Billing* pBilling, const char* pPath)
{
	FILE* fp = NULL;   // 文件结构体指针

	// 以追加方式打开一个二进制文件
	if((fp = fopen(pPath, "ab")) == NULL)
	{
		// 如果以追加方式失败，则以只写方式创建一个文件并打开
		if((fp = fopen(pPath, "wb")) == NULL)
		{
			return FALSE;
		}
	}

	// 将计费信息保存到文件中
	fwrite(pBilling, sizeof(Billing), 1, fp);

	// 关闭文件
	fclose(fp);

	return TRUE;
}

/*************************************************
[函数名] readBilling
[功能]  读取计费信息
[参数]  pBilling: 计费信息结构体指针
       pPath: 保存计费信息文件路径
[返回值] int型，TRUE表示成功，FALSE表示失败
*************************************************/
int readBilling(Billing* pBilling, const char* pPath)
{
	FILE* fp = NULL;  // 文件结构体指针
	int nIndex = 0;

	// 以只读方式打开文件，如果打开失败，则读取失败
	if((fp = fopen(pPath, "rb")) == NULL)
	{
		return FALSE;
	}

	// 读取文件内容
	while(!feof(fp))
	{
		if(fread(&pBilling[nIndex], sizeof(Billing), 1, fp) != 0)
		{
			nIndex++;
		}
	}
	
	// 关闭文件
	fclose(fp);

	return TRUE;
}

/*************************************************
[函数名] getBillingCount
[功能]  获取文件中计费信息数量
[参数]  pPath: 保存计费信息文件路径
[返回值] int:计费信息数量
*************************************************/
int getBillingCount(const char* pPath)
{
	FILE* fp = NULL;
	int nCount = 0;
	Billing* pBilling = (Billing*)malloc(sizeof(Billing));

	// 以只读方式打开文件，如果打开失败，则读取失败
	if((fp = fopen(pPath, "rb")) == NULL)
	{
		return 0;
	}

	// 读取文件内容
	while(!feof(fp))
	{
		if(fread(pBilling, sizeof(Billing), 1, fp) != 0)
		{
			nCount++;
		}
	}
	
	// 关闭文件
	fclose(fp);
	free(pBilling);
	return nCount;
}


//测试保存消费记录 
int saveBillingTest()
{
	Billing billing;  // 计费信息
	// 添加消费记录
	char aName[18] = {0};    // 上机卡号
    printf("----------上机----------\n");
	printf("请输入上机卡号(长度为1~18):");
	scanf("%s", billing.aCardName);              // 上机卡号
	billing.tStart = time(NULL);                 // 上机时间
	billing.tEnd = 0;                            // 下机时间
	billing.nStatus = 0;                         // 消费状态
	billing.fAmount = 0;                         // 消费金额
	billing.nDel = 0;                            // 删除标识

	// 将计费信息保存到文件中
	return saveBilling(&billing, BILLINGPATH); 
}

/* 
int main()
{
	Billing tmp;
	int n;

	//保存消费记录 测试 
	if (TRUE == saveBillingTest())
		printf("消费记录保存成功！\n");
	else  
		printf("消费记录保存失败！\n");
		
	
	
	//获取消费记录数量	测试 
	n = getBillingCount(BILLINGPATH);
	printf("共%d条消费记录!\n",n);

	

	// 读取消费记录 测试 
	if(TRUE == readBilling(&tmp, BILLINGPATH))
		printf("消费记录读取成功！\n");
	else  
		printf("消费记录读取失败！\n");

		
	return 0;
}
*/ 
