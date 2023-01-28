#include "SqlList.h"
#include <stdio.h>
#include <stdlib.h>

void TestSqlList1()
{
	SL sl;
	SqlListInit(&sl);
	SqlListPushBack(&sl, 1);
	SqlListPushBack(&sl, 2);
	SqlListPushBack(&sl, 3);
	SqlListPushBack(&sl, 4);

	SqlListPrint(&sl);
}

int main()
{
	TestSqlList1();

	return 0;
}