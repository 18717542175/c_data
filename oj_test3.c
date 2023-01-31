//移除链表元素
/*给一个链表的头head和一个整数val，请你删除链表中所有满足Node.val == val的结点，并返回新的头节点*/

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
	int val;
	ListNode* next;
}ListNode;


ListNode* removeElement(struct ListNode* head, int val)
{
	ListNode* prev = NULL, *cur = head;
	
	//如果cur不为空继续遍历
	while (cur)
	{
		if (cur->val == val)
		{
			//头删
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else {
				//中间删除
				prev->next = cur->next;
				free(cur);

				cur = prev->next; //将指针往后挪
			}
			
		}
		else {
			//迭代往后走
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}