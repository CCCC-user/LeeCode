/*
给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，并且它们的每个节点只能存储一位数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0开头。
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
		n2 = l2?l2->val:0;//新学的方法
		sum = n1+n2+car;

		if(!head)//如果头是空
		{
			head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
			tail->val = sum%10;
			tail->next = NULL;
		}
		else//头非空,只操作尾节点
		{
			tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			tail->next->val = sum%10;
			tail = tail->next;
			tail->next = NULL;
		}

		car = sum/10;//进位判断是否+1

		if(l1 != NULL)//l1后移
		{
			l1 = l1->next;
		}
		if(l2 != NULL)//l2后移
		{
			l2 = l2->next;
		}
	}

	if(car > 0)//注意此时tail的位置
	{
		tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		tail->next->val = car;
		tail->next->next = NULL;
	}
	return head;
}

//本题需注意tail的位置