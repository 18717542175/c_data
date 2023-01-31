#pragma once
#include <stdio.h>
typedef int SbListType;

typedef struct SbListNode
{
	SbListType data;
	struct SLTNode* next;
}SLTNode;

SLTNode* BuyListNode(SbListType x);  //创建结点函数
void SbListPrint(SLTNode* phead); //打印
void SbListPushBack(SLTNode** phead, SbListType x); //从尾部插入数据
void SbListPushFront(SLTNode** phead, SbListType x);  //头部插入
void SbListPopBack(SLTNode** phead); //从尾部删除数据
void SbListPopFront(SLTNode** phead);  //头部删除
void SbListInsert(SLTNode** phead, SLTNode* pos, SbListType x);//在某个位置插入数据
SLTNode* SbListFind(SLTNode* phead, SbListType x); //查找数据
void SbListEase(SLTNode** phead, SLTNode* pos); //删除数据
void SbListDeastory(SLTNode** phead); //销毁链表
void SbListInsertAfert(SLTNode* pos, SbListType x);	//在pos之后插入数据