//反转一个链表
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct listNode{
	int data;
	ListNode* next;
}ListNode;

ListNode* reverseList(ListNode* head)
{
	if (head == NULL)
		return NULL;
	ListNode* cur = head;
	ListNode* prev = NULL;
	ListNode* next = NULL;

	while (cur != NULL)
	{
		//翻转
		cur->next = prev;

		//迭代
		prev = cur;
		cur = next;
		if (next != NULL) {
			next = next->next;
		}
	}
}