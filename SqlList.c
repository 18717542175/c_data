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
void SqlListPopFront(SL* ps);