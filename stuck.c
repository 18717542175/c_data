#include "stuck.h"
#include <stdio.h>
#include <stdlib.h>

void StackInit(ST* ps)
{
	assert(ps != NULL);
	ps->a = NULL;
	ps->top = 0; //��ʱtopָ��ջ�����ݵ���һ�� top=-1ʱtopָ��ջ������
	ps->capacity = 0;
}
void StackDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->capacity = 0;
	ps->top = 0;
}
void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	//����ռ䲻�� ����
	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType)*newCapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->capacity = newCapacity;
		ps->a = tmp; 
	}

	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}