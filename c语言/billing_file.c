#include <stdio.h>   // �����ļ�����ͷ�ļ�
#include <stdlib.h>  // ������̬�ڴ����ͷ�ļ�
#include <time.h> 
#define FALSE 0
#define TRUE  1
#define BILLINGPATH "billing.dat" // �Ʒ���Ϣ����·��

// �Ʒ���Ϣ�ṹ��
typedef struct Billing
{
	char aCardName[18];    // ����
	time_t tStart;         // �ϻ�ʱ��
	time_t tEnd;           // �»�ʱ��
	float fAmount;         // ���ѽ��
	int nStatus;           // ����״̬��0-δ���㣬1-�Ѿ�����
	int nDel;              // ɾ����ʶ��0-δɾ��,1-ɾ��
}Billing;

// �Ʒ���Ϣ���
typedef struct BillingNode
{
	Billing data;
	struct BillingNode *next;
}BillingNode, *lpBillingNode;

/*************************************************
[������] saveBilling
[����]  ����Ʒ���Ϣ
[����]  pBilling: �Ʒ���Ϣ�ṹ��ָ��
       pPath: ����Ʒ���Ϣ�ļ�·��
[����ֵ] int�ͣ�TRUE��ʾ�ɹ���FALSE��ʾʧ��
*************************************************/
int saveBilling(const Billing* pBilling, const char* pPath)
{
	FILE* fp = NULL;   // �ļ��ṹ��ָ��

	// ��׷�ӷ�ʽ��һ���������ļ�
	if((fp = fopen(pPath, "ab")) == NULL)
	{
		// �����׷�ӷ�ʽʧ�ܣ�����ֻд��ʽ����һ���ļ�����
		if((fp = fopen(pPath, "wb")) == NULL)
		{
			return FALSE;
		}
	}

	// ���Ʒ���Ϣ���浽�ļ���
	fwrite(pBilling, sizeof(Billing), 1, fp);

	// �ر��ļ�
	fclose(fp);

	return TRUE;
}

/*************************************************
[������] readBilling
[����]  ��ȡ�Ʒ���Ϣ
[����]  pBilling: �Ʒ���Ϣ�ṹ��ָ��
       pPath: ����Ʒ���Ϣ�ļ�·��
[����ֵ] int�ͣ�TRUE��ʾ�ɹ���FALSE��ʾʧ��
*************************************************/
int readBilling(Billing* pBilling, const char* pPath)
{
	FILE* fp = NULL;  // �ļ��ṹ��ָ��
	int nIndex = 0;

	// ��ֻ����ʽ���ļ��������ʧ�ܣ����ȡʧ��
	if((fp = fopen(pPath, "rb")) == NULL)
	{
		return FALSE;
	}

	// ��ȡ�ļ�����
	while(!feof(fp))
	{
		if(fread(&pBilling[nIndex], sizeof(Billing), 1, fp) != 0)
		{
			nIndex++;
		}
	}
	
	// �ر��ļ�
	fclose(fp);

	return TRUE;
}

/*************************************************
[������] getBillingCount
[����]  ��ȡ�ļ��мƷ���Ϣ����
[����]  pPath: ����Ʒ���Ϣ�ļ�·��
[����ֵ] int:�Ʒ���Ϣ����
*************************************************/
int getBillingCount(const char* pPath)
{
	FILE* fp = NULL;
	int nCount = 0;
	Billing* pBilling = (Billing*)malloc(sizeof(Billing));

	// ��ֻ����ʽ���ļ��������ʧ�ܣ����ȡʧ��
	if((fp = fopen(pPath, "rb")) == NULL)
	{
		return 0;
	}

	// ��ȡ�ļ�����
	while(!feof(fp))
	{
		if(fread(pBilling, sizeof(Billing), 1, fp) != 0)
		{
			nCount++;
		}
	}
	
	// �ر��ļ�
	fclose(fp);
	free(pBilling);
	return nCount;
}


//���Ա������Ѽ�¼ 
int saveBillingTest()
{
	Billing billing;  // �Ʒ���Ϣ
	// ������Ѽ�¼
	char aName[18] = {0};    // �ϻ�����
    printf("----------�ϻ�----------\n");
	printf("�������ϻ�����(����Ϊ1~18):");
	scanf("%s", billing.aCardName);              // �ϻ�����
	billing.tStart = time(NULL);                 // �ϻ�ʱ��
	billing.tEnd = 0;                            // �»�ʱ��
	billing.nStatus = 0;                         // ����״̬
	billing.fAmount = 0;                         // ���ѽ��
	billing.nDel = 0;                            // ɾ����ʶ

	// ���Ʒ���Ϣ���浽�ļ���
	return saveBilling(&billing, BILLINGPATH); 
}

/* 
int main()
{
	Billing tmp;
	int n;

	//�������Ѽ�¼ ���� 
	if (TRUE == saveBillingTest())
		printf("���Ѽ�¼����ɹ���\n");
	else  
		printf("���Ѽ�¼����ʧ�ܣ�\n");
		
	
	
	//��ȡ���Ѽ�¼����	���� 
	n = getBillingCount(BILLINGPATH);
	printf("��%d�����Ѽ�¼!\n",n);

	

	// ��ȡ���Ѽ�¼ ���� 
	if(TRUE == readBilling(&tmp, BILLINGPATH))
		printf("���Ѽ�¼��ȡ�ɹ���\n");
	else  
		printf("���Ѽ�¼��ȡʧ�ܣ�\n");

		
	return 0;
}
*/ 
