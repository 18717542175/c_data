#pragma once
#include <stdio.h>
typedef int SbListType;

typedef struct SbListNode
{
	SbListType data;
	struct SLTNode* next;
}SLTNode;

SLTNode* BuyListNode(SbListType x);  //������㺯��
void SbListPrint(SLTNode* phead); //��ӡ
void SbListPushBack(SLTNode** phead, SbListType x); //��β����������
void SbListPushFront(SLTNode** phead, SbListType x);  //ͷ������
void SbListPopBack(SLTNode** phead); //��β��ɾ������
void SbListPopFront(SLTNode** phead);  //ͷ��ɾ��
void SbListInsert(SLTNode** phead, SLTNode* pos, SbListType x);//��ĳ��λ�ò�������
SLTNode* SbListFind(SLTNode* phead, SbListType x); //��������
void SbListEase(SLTNode** phead, SLTNode* pos); //ɾ������
void SbListDeastory(SLTNode** phead); //��������
void SbListInsertAfert(SLTNode* pos, SbListType x);	//��pos֮���������