/*������*/
#include "SbList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


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
	if (*phead == NULL)
	{
		return;
	}else {
		SLTNode* next = (*phead)->next;  //����ڶ������ĵ�ַ

		free(*phead);
		*phead = next;
	}  
}

void SbListInsert(SLTNode** phead, SLTNode* pos, SbListType x)//��ĳ��λ�ò�������
{
	//assert(*phead != NULL);
	//
	//SLTNode* curnode = *phead;
	//SLTNode* nextnode = (*phead)->next;

	////����һ���½��
	//SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	//newnode->data = x;
	//newnode->next = NULL;
	//


	////�ҵ�Ŀ����
	//while (curnode->next != NULL)
	//{
	//	if (curnode == pos)
	//	{
	//		curnode->next = newnode;
	//		newnode->next = nextnode;
	//	}
	//	else
	//	{
	//		curnode = curnode->next;
	//		nextnode = curnode->next;
	//	}  
	//}

	SLTNode* newnode = BuyListNode(x);

	//�ҵ�pos��ǰһ��λ��
	SLTNode* posPrev = *phead;
	while (posPrev->next != pos)
	{
		posPrev = pos->next;
	}
	posPrev->next = newnode;
	newnode->next = pos;
}
SLTNode* SbListFind(SLTNode* phead, SbListType x) //��������
{
	//��������
	SLTNode* node = phead;
	while (node->next != NULL)
	{
		if (node->data == x)
			return node;
		else
			node = node->next;
	}
	return NULL; 
}
void SbListEase(SLTNode** phead, SLTNode* pos)
{
	if (*phead == pos)
	{
		*phead = pos->next;
		free(pos);
	}
	else {
		SLTNode* prev = *phead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void SbListDeastory(SLTNode** phead)//��������
{
	assert(phead);

	SLTNode* cur = *phead;
	while (cur != NULL)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
void SbListInsertAfert(SLTNode* pos, SbListType x)
{
	SLTNode* newnode = BuyListNode(x);

	//�Ƚ��½���nextָ��pos���һ������next
	//�ٽ�pos��nextָ��newnode
	newnode->next = pos->next;
	pos->next = newnode;
}










 