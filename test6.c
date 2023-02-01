/*�����е�����k�����*/
#include <stdint.h>
#include <stdlib.h>

typedef struct listNode {
	int data;
	ListNode* next;
}ListNode;

/*
	1.fast����k��
	2.slow��fast��һ���ߣ�fast==NULLʱslow���ǵ�����k��
*/
ListNode* FindKthToTail(ListNode* pListHead, int k)
{
	ListNode* fast, *slow;
	fast = slow = pListHead;
	for (int i = 0; i < k; i++)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}