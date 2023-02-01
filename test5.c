//������м��� (���ܱ�������һ��)
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

	//ż����ʱfast==NULL
	//������ʱfast->next==NULL
	while ((fast != NULL) && (fast->next != NULL))
	{
		slow = slow->next;   //��ָ����һ�� ��ָ��������
		fast = fast->next->next;
	}

	return slow;
}