#if 0
#include <iostream>
using namespace std;

struct ListNode
{
	ListNode(int _data)
		:data(_data)
		, next(NULL)
	{}
	ListNode* next;
	int data;
};
ListNode *insertionSortList(ListNode* head) {
	if (head == NULL)
		return NULL;
	ListNode *p = head;
	ListNode *newhead = NULL;

	while (p != NULL)
	{
		ListNode* cur = newhead;
		ListNode* pre = NULL;
		ListNode* pnext = p->next;
		while (cur != NULL &&  cur->data <= p->data)
		{
			pre = cur;
			cur = cur->next;
		}

		if (pre == NULL)
		{
			p->next = newhead;
			newhead = p;
		}
		else
		{
			p->next = pre->next;
			pre->next = p;
		}
		p = pnext;
	}
	return head;
}

#endif

//int main()
//{
//	ListNode node(5);
//	ListNode *head = &node;
//	ListNode *cur = head;
//	cur->next = new ListNode(2);
//	cur = cur->next;
//	cur->next = new ListNode(3);
//	cur = cur->next;
//	cur->next = new ListNode(5);
//	cur = cur->next;
//	cur->next = new ListNode(1);
//	cur = cur->next;
//	cur->next = new ListNode(4);
//	cur = cur->next;
//
//	head = insertionSortList(head);
//	return 0;
//}