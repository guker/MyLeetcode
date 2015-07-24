
#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

void CreateList(ListNode* &head, int n) 
{
	head = new ListNode(0);
	scanf("%d",&head->val);
	ListNode* L = head;
	ListNode* p = NULL;
	for(int i = n-1; i > 0 ;--i)
	{
		p = new ListNode(0);
		scanf("%d",&p->val);
	    L->next = p;
		L = p;

	}
	L->next = NULL;
}

void print(ListNode* head)
{
	if(!head)
		return;
	while(head)
	{
		printf("%d ",head->val);
		head = head->next;
	}
	
}

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int carry = 0; // 进位标志
		ListNode* tail = new ListNode(0); // 头指针tail
		ListNode* ptr = tail;
		
		while(l1 != NULL || l2 != NULL)
		{
			int val1 = 0;
			if(l1 != NULL)
			{
				val1 = l1->val;
				l1 = l1->next;
			}

			int val2 = 0; 
			if(l2 != NULL)
			{
				val2 = l2->val;
				l2 = l2->next;
			}

			int tmp = val1 + val2 + carry;
			ptr->next = new ListNode(tmp%10);
			carry = tmp/10;
			ptr = ptr->next;	
		}
		if(carry == 1)
			{
				ptr->next = new ListNode(1);
			}
		return tail->next;
	}
};

int main()
{
	ListNode* l1 = NULL;
	CreateList(l1,3); // 输入数据，长度为3
	ListNode* l2 = NULL;
	CreateList(l2,3);
	Solution sln;
	ListNode* results = NULL;
	results = sln.addTwoNumbers(l1,l2);
	print(results);
    while(1);
	
	return true;
}