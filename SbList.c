/*������*/
#include "SbList.h"
#include <stdio.h>
#include <stdlib.h>


SLTNode* BuyListNode(SbListType x)
{
	//���½ڵ���ж���
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->next = NULL;
	newnode->data = x;

	return newnode;
}

void SbListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}

}

void SbListPushBack(SLTNode** phead, SbListType x)
{

	SLTNode* newnode =  BuyListNode(x);

	//�ж������Ƿ�Ϊ��
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else 
	{
		SLTNode* tail = *phead;
		//�ҵ�β���
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		//��ʱ�Ѿ��ҵ�β��
		tail->next = newnode;
	}
}

void SbListPushFront(SLTNode** phead, SbListType x)
{
	//�����ڵ�
	SLTNode* newnode =  BuyListNode(x);
	 
	newnode->next = *phead; //���½ڵ��nextָ��ԭ����ͷ
	*phead = newnode; //��ͷ��־�ŵ�newnode
}

void SbListPopBack(SLTNode** phead)//��β��ɾ������
{
	if (*phead == NULL)
		return;


	SLTNode* prev = NULL;  //�������ǰһ���ĵ�ַ
	//��β��
	SLTNode* tail = *phead;
	while (tail->next != NULL)
	{
		prev = tail;       //���Լ���ǰһ��
		tail = tail->next;
	}

	//��ʱ�ҵ�β��
	free(tail);
	tail = NULL;
	prev->next = NULL;

}
void SbListPopFront(SLTNode** phead)  //ͷ��ɾ��
{

}










 