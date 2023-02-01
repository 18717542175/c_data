//链表的中间结点 (智能遍历链表一次)
#include <stdint.h>
#include <stdlib.h>

typedef struct listNode {
	int data;
	ListNode* next;
}ListNode;

ListNode* middleNode(ListNode* head)
{
	ListNode* fast, *slow;

	slow = fast = head;

	//偶数个时fast==NULL
	//奇数个时fast->next==NULL
	while ((fast != NULL) && (fast->next != NULL))
	{
		slow = slow->next;   //慢指针走一步 快指针走两步
		fast = fast->next->next;
	}

	return slow;
}