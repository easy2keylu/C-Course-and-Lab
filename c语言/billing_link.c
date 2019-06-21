#include <string.h>  // �����ַ�����ͷ�ļ�
#include <stdlib.h>  // ������̬�ڴ����ͷ�ļ�

#include "billing_file.c"  // �����ƷѼ�ʱ�ļ�

lpBillingNode billingList = NULL;    // �Ʒ���Ϣ����

int getBilling();  // ����getBilling()����

/**************************************************************
[������]�� initBillingList
[��������]����ʼ���Ʒ���Ϣ����Ϊͷ�������ڴ�
[��������]��void
[����ֵ]��void
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
[������]�� releaseBillingList
[��������]���ͷżƷ���Ϣ����
[��������]��void
[����ֵ]��void
***************************************************************/
void releaseBillingList()
{
	//��������
	lpBillingNode cur = billingList;
	lpBillingNode next = NULL;	
	while(cur != NULL) 
	{		
		next = cur->next;//����ڴ��ͷ�ǰ��next��������
		free(cur); //�ͷŽ���ڴ�
		cur = next;
	}
	billingList = NULL;
}

/**************************************************************
[������]�� getBilling
[��������]���ӼƷ���Ϣ�ļ��У���ȡ�Ʒ���Ϣ���浽������
[��������]��void
[����ֵ]��int: ��ȡ��Ϣ�ɹ�����ȡ��Ϣʧ��
***************************************************************/
int getBilling()
{
	int nCount = 0;   // �Ʒ���Ϣ����
	Billing* pBilling = NULL;  // �Ʒ���Ϣ
	lpBillingNode node = NULL;
	int i = 0;    // ѭ������
	lpBillingNode cur = NULL;

	// �������Ϊ�գ��ͷ�����
	if(billingList != NULL)
	{
		releaseBillingList();
	}

	// ��ʼ������
	initBillingList();

	// ��ȡ�Ʒ���Ϣ����
	nCount = getBillingCount(BILLINGPATH);

	// ��̬�����ڴ�
	pBilling = (Billing*)malloc(sizeof(Billing) * nCount);
	if(pBilling != NULL)
	{
		// ��ȡ�Ʒ���Ϣ
		if(FALSE == readBilling(pBilling, BILLINGPATH))
		{
			free(pBilling);
			return FALSE;
		}
	
		// ���Ʒ���Ϣ���浽������
		for(i = 0, node = billingList; i < nCount; i++)
		{
			// Ϊ��ǰ�������ڴ�
			cur = (lpBillingNode)malloc(sizeof(BillingNode));
			// �������ʧ�ܣ����ڷ���FALSEǰ����Ҫ�ͷ�pBilling���ڴ�
			if(cur == NULL)
			{
				free(pBilling);
				return FALSE;
			}

			// ��ʼ���µĿռ䣬ȫ����ֵΪ0
			memset(cur, 0, sizeof(BillingNode));

			// ��������ӵ������
			cur->data = pBilling[i];
			cur->next = NULL;

			// �������ӵ�������
			node->next = cur;
			node = cur;
		}
		free(pBilling);
		return TRUE;
	}
	return FALSE;
}

/**************************************************************
[������]�� queryBilling
[��������]���ڼƷ���Ϣ�����У���ѯ��Ӧ���ļƷ���Ϣ������ȡ�üƷ���Ϣ�������е�������
[��������]��pName: Ҫ��ѯ�ļƷ���Ϣ�Ŀ���
          pIndex:��ѯ���ļƷ���Ϣ�������е�������
[����ֵ]��Billing*:��ѯ���ļƷ���Ϣָ��
***************************************************************/
Billing* queryBilling(const char* pName, int* pIndex)
{
	lpBillingNode node = NULL;
	int nIndex = 0;

	if(FALSE == getBilling())
	{
		return NULL;
	}

	// ��������
	node = billingList->next;
	while(node != NULL)
	{
		// ��ѯ��������ͬ������û�н���ļƷ���Ϣ
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
	char aName[18] = {0};    // �ϻ�����
	
	getBilling();
	
	printf("�������ϻ�����(����Ϊ1~18):");
	scanf("%s",aName);
	if(queryBilling(aName,0)!=NULL)
		printf("��ѯ�ɹ���\n");
	else
		printf("��ѯʧ�ܣ�\n");
	
	return 0;
}
