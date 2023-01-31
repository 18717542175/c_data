//�Ƴ�����Ԫ��
/*��һ�������ͷhead��һ������val������ɾ����������������Node.val == val�Ľ�㣬�������µ�ͷ�ڵ�*/

#include <stdio.h>
#include <stdlib.h>

typedef struct listNode {
	int val;
	ListNode* next;
}ListNode;


ListNode* removeElement(struct ListNode* head, int val)
{
	ListNode* prev = NULL, *cur = head;
	
	//���cur��Ϊ�ռ�������
	while (cur)
	{
		if (cur->val == val)
		{
			//ͷɾ
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else {
				//�м�ɾ��
				prev->next = cur->next;
				free(cur);

				cur = prev->next; //��ָ������Ų
			}
			
		}
		else {
			//����������
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}