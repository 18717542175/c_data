#include "SqlList.h"
#include <stdio.h>
#include <stdlib.h>

void SqlListInit(SL* ps)
{
	ps->a = NULL;
	ps->capacity = ps->size = 0;

}

//����
void SqlListCheckCapacity(SL* ps)
{
	/*����Ϊ����*/
	//���ʵ�ʴ洢�����ݿռ��С�����������Ŀռ��С
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2; //���ݶ���
		SLDataType* tmp = (SLDataType*)malloc(ps->size, newcapacity * sizeof(SLDataType)); //���п��ٿռ����

		if (tmp == NULL)
		{
			printf("malloc����ʧ��");
			exit(-1);
		}

		//��ʱ�ռ俪�ٳɹ�
		ps->a = tmp;	//��a�ĵ�ַָ��tmp
		ps->capacity = newcapacity;
	}

}


//�����ݴ�ӡ
void SqlListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
}

//����
void SqlListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}


//��β��ɾ��һ������
void SqlListPopBack(SL* ps)
{
	//ps->a[ps->size] = 0;
	assert(ps->size > 0);
	ps->size--;
}

//��β����������
void SqlListPushBack(SL* ps, SLDataType x)
 {
	SqlListCheckCapacity(ps);
	//��������
	ps->a[ps->size] = x;
	ps->size++;


}

//ͷ������
void SqlListPushFront(SL* ps, SLDataType x)
{
	SqlListCheckCapacity(ps);

	//int i = 0;

	////���ݽ��� ��������
	//for (i = ps->size; i >= 0; i--)
	//{
	//	ps->a[i + 1] = ps->a[i];
	//}

	//Ų������
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

	//Ų������
	int begin = 0;
	while (begin < ps->size)
	{
		ps->a[begin] = ps->a[begin+1];
		++begin;
	}
	ps->size--;
}

int SqlListFind(SL* ps, SLDataType x)//��������
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	//û���ҵ�����0
	return -1;
}
void SqlListInsert(SL* ps, int post, SLDataType x) //ָ��posλ�ò�������
{
	if (post > ps->size || post > 0)
	{
		printf("����λ������");
	}
	else
	{
		SqlListCheckCapacity(ps);
		int p = ps->size - 1;

		//Ų������
		while (p >= post)  
		{
			ps->a[p+1] = ps->a[p];
			p--;
		}

		ps->a[post] = x;
		ps->size++;
	}
}
void SqlListErase(SL* ps, int pos) //ɾ��posλ�ô�������
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