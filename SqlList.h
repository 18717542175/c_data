#pragma once
#define N 100
typedef int SLDataType;
//
////静态顺序表
//typedef struct SqlList
//{
//	int a[N];
//	int size; //表示数组中存储了多少了有效数据
//}SL;
//
//void SqlListInit(SL* ps, SLDataType x);
//void SqlListPopBack(SL* ps, SLDataType x);
//void SqlListPushBack(SL* ps, SLDataType x);


//动态顺序表
typedef struct SqlList
{
	SLDataType* a;
	int size; //表示数组中存储了多少了有效数据
	int capacity; //表示数组实际能存的数据的空间容量
}SL;

//初始化函数  为了对形参的内容修改应该传入地址
void SqlListInit(SL* ps);
void SqlListPopBack(SL* ps);
void SqlListPushBack(SL* ps, SLDataType x);
void SqlListPushFront(SL* ps, SLDataType x);
void SqlListPopFront(SL* ps);
void SqlListPrint(SL* ps);
void SqlListDestory(SL* ps);	//内存销毁

void SqlListCheckCapacity(SL* ps); //扩容

int SqlListFind(SL* ps, SLDataType x);//查找数据
void SqlListInsert(SL* ps, int post, SLDataType x); //指定pos位置插入数据
void SqlListErase(SL* ps, int pos); //删除pos位置处的数据