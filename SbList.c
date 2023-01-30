/*单链表*/
#include "SbList.h"
#include <stdio.h>
#include <stdlib.h>


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

}










 