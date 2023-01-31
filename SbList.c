/*单链表*/
#include "SbList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


SLTNode* BuyListNode(SbListType x)
{
	//对新节点进行定义
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

	//判断链表是否为空
	if (*phead == NULL)
	{
		*phead = newnode;
	}
	else 
	{
		SLTNode* tail = *phead;
		//找到尾结点
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		//此时已经找到尾部
		tail->next = newnode;
	}
}

void SbListPushFront(SLTNode** phead, SbListType x)
{
	//创建节点
	SLTNode* newnode =  BuyListNode(x);
	 
	newnode->next = *phead; //将新节点的next指向原来的头
	*phead = newnode; //将头标志放到newnode
}

void SbListPopBack(SLTNode** phead)//从尾部删除数据
{
	if (*phead == NULL)
		return;


	SLTNode* prev = NULL;  //用来存放前一个的地址
	//找尾部
	SLTNode* tail = *phead;
	while (tail->next != NULL)
	{
		prev = tail;       //将自己给前一个
		tail = tail->next;
	}

	//此时找到尾部
	free(tail);
	tail = NULL;
	prev->next = NULL;

}
void SbListPopFront(SLTNode** phead)  //头部删除
{
	if (*phead == NULL)
	{
		return;
	}else {
		SLTNode* next = (*phead)->next;  //保存第二个结点的地址

		free(*phead);
		*phead = next;
	}  
}

void SbListInsert(SLTNode** phead, SLTNode* pos, SbListType x)//在某个位置插入数据
{
	//assert(*phead != NULL);
	//
	//SLTNode* curnode = *phead;
	//SLTNode* nextnode = (*phead)->next;

	////创造一个新结点
	//SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	//newnode->data = x;
	//newnode->next = NULL;
	//


	////找到目标结点
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

	//找到pos的前一个位置
	SLTNode* posPrev = *phead;
	while (posPrev->next != pos)
	{
		posPrev = pos->next;
	}
	posPrev->next = newnode;
	newnode->next = pos;
}
SLTNode* SbListFind(SLTNode* phead, SbListType x) //查找数据
{
	//遍历链表
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
void SbListDeastory(SLTNode** phead)//销毁链表
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

	//先将新结点的next指向pos后的一个结点的next
	//再将pos的next指向newnode
	newnode->next = pos->next;
	pos->next = newnode;
}










 