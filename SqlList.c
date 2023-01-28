#include "SqlList.h"
#include <stdio.h>
#include <stdlib.h>

void SqlListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;

}

//扩容
void SqlListCheckCapacity(SL* ps)
{
	/*以下为扩容*/
	//如果实际存储的数据空间大小等于最大允许的空间大小
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2; //扩容二倍
		SLDataType* tmp = (SLDataType*)malloc(ps->size, newcapacity * sizeof(SLDataType)); //进行开辟空间操作

		if (tmp == NULL)
		{
			printf("malloc开辟失败");
			exit(-1);
		}

		//此时空间开辟成功
		ps->a = tmp;	//将a的地址指向tmp
		ps->capacity = newcapacity;
	}

}


//表内容打印
void SqlListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

//销毁
void SqlListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


//从尾部删除一个数据
void SqlListPopBack(SL* ps)
{
	//ps->a[ps->size] = 0;
	assert(ps->size > 0);
	ps->size--;
}

//从尾部插入数据
void SqlListPushBack(SL* ps, SLDataType x)
 {
	SqlListCheckCapacity(ps);
	//插入数据
	ps->a[ps->size] = x;
	ps->size++;


}

//头部插入
void SqlListPushFront(SL* ps, SLDataType x)
{
	SqlListCheckCapacity(ps);

	//int i = 0;

	////扩容结束 插入数据
	//for (i = ps->size; i >= 0; i--)
	//{
	//	ps->a[i + 1] = ps->a[i];
	//}

	//挪动数据
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}

	ps->a[0] = x;
	ps->size++;

}
void SqlListPopFront(SL* ps);