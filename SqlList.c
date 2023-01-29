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
void SqlListPopFront(SL* ps)
{
	assert(ps->size > 0);

	//挪动数据
	int begin = 0;
	while (begin < ps->size)
	{
		ps->a[begin] = ps->a[begin+1];
		++begin;
	}
	ps->size--;
}

int SqlListFind(SL* ps, SLDataType x)//查找数据
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	//没有找到返回0
	return -1;
}
void SqlListInsert(SL* ps, int post, SLDataType x) //指定pos位置插入数据
{
	if (post > ps->size || post > 0)
	{
		printf("插入位置有误");
	}
	else
	{
		SqlListCheckCapacity(ps);
		int p = ps->size - 1;

		//挪动数据
		while (p >= post)  
		{
			ps->a[p+1] = ps->a[p];
			p--;
		}

		ps->a[post] = x;
		ps->size++;
	}
}
void SqlListErase(SL* ps, int pos) //删除pos位置处的数据
{
	assert(pos >= 0 && pos < ps->size-1);

	//int p = pos;
	while (pos < ps->size-1)
	{
		ps->a[pos] = ps->a[pos + 1];
		pos++;
	}

	ps->size--;
}