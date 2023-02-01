/*链表中倒数第k个结点*/
#include <stdint.h>
#include <stdlib.h>

typedef struct listNode {
	int data;
	ListNode* next;
}ListNode;

/*
	1.fast先走k步
	2.slow和fast再一起走，fast==NULL时slow就是倒数第k个
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