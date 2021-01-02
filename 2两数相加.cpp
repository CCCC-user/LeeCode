/*
���������ǿյ�����������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ�������ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢һλ���֡�

��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

�����Լ���������� 0 ֮�⣬���������������� 0��ͷ��
*/

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = NULL;
	struct ListNode* tail = NULL;
	int n1,n2;
	int sum;
	int car=0;

	while(l1!=NULL||l2!=NULL)
	{
		n1 = l1?l1->val:0;
		n2 = l2?l2->val:0;//��ѧ�ķ���
		sum = n1+n2+car;

		if(!head)//���ͷ�ǿ�
		{
			head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
			tail->val = sum%10;
			tail->next = NULL;
		}
		else//ͷ�ǿ�,ֻ����β�ڵ�
		{
			tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			tail->next->val = sum%10;
			tail = tail->next;
			tail->next = NULL;
		}

		car = sum/10;//��λ�ж��Ƿ�+1

		if(l1 != NULL)//l1����
		{
			l1 = l1->next;
		}
		if(l2 != NULL)//l2����
		{
			l2 = l2->next;
		}
	}

	if(car > 0)//ע���ʱtail��λ��
	{
		tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		tail->next->val = car;
		tail->next->next = NULL;
	}
	return head;
}

//������ע��tail��λ��