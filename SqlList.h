#pragma once
#define N 100
typedef int SLDataType;
//
////��̬˳���
//typedef struct SqlList
//{
//	int a[N];
//	int size; //��ʾ�����д洢�˶�������Ч����
//}SL;
//
//void SqlListInit(SL* ps, SLDataType x);
//void SqlListPopBack(SL* ps, SLDataType x);
//void SqlListPushBack(SL* ps, SLDataType x);


//��̬˳���
typedef struct SqlList
{
	SLDataType* a;
	int size; //��ʾ�����д洢�˶�������Ч����
	int capacity; //��ʾ����ʵ���ܴ�����ݵĿռ�����
}SL;

//��ʼ������  Ϊ�˶��βε������޸�Ӧ�ô����ַ
void SqlListInit(SL* ps);
void SqlListPopBack(SL* ps);
void SqlListPushBack(SL* ps, SLDataType x);
void SqlListPushFront(SL* ps, SLDataType x);
void SqlListPopFront(SL* ps);
void SqlListPrint(SL* ps);
void SqlListDestory(SL* ps);	//�ڴ�����

void SqlListCheckCapacity(SL* ps); //����

int SqlListFind(SL* ps, SLDataType x);//��������
void SqlListInsert(SL* ps, int post, SLDataType x); //ָ��posλ�ò�������
void SqlListErase(SL* ps, int pos); //ɾ��posλ�ô�������