/********************************************************************************** 
* 
* Merge two sorted linked lists and return it as a new list. The new list should be 
* made by splicing together the nodes of the first two lists.
*               
**********************************************************************************/
/*
*       合并两个有序链表
*
*
*   @date 2015-08-13
*/
#include<iostream>
#include<vector>

using namespace std;



struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode* createList(int a[],int len)
{
	if(len <= 0)
		return NULL;
	ListNode dummy(-1);
	ListNode* tail = &dummy;
	for(int i = 0;i<len;i++)
	{
		ListNode* tmp = new ListNode(a[i]);
		tail->next = tmp;
		tail = tail->next;
	}
	return dummy.next;
}
/*     
*     合并两个链表到一个新的链表
*/
ListNode* mergeTwoList(ListNode* p1,ListNode* p2)
{
	if(p1 == NULL)
		return p2;
	if(p2 == NULL)
		return p1;
  
	ListNode dummy(-1);
	ListNode* p3 = &dummy;
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->val < p2->val)
		{
			p3->next = p1;
			p1 = p1->next;
			p3 = p3->next;
		}
		else
		{
			p3->next = p2;
			p2 = p2->next;
			p3 = p3->next;
		}
	}
	if(p1 != NULL)
		p3->next = p1;
	if(p2 != NULL)
		p3->next = p2;
	/// dummy.next指向的堆上的内存(也就是堆上的对象)可以返回
	/// 如果指向栈上的对象则会出错
	return dummy.next; 
}
/*  合并两个链表到第一个链表
*   链表的插入与删除
*   当前结点指针，前向指针(当前结点的上一个指针)
*/
ListNode* mergeTwoList1(ListNode* p1,ListNode* p2)
{
	if(p1 == NULL)
		return p2;
	if(p2 == NULL)
		return p1;
	ListNode dummy(0);
	dummy.next = p1;
	/// prev保存前向结点
	ListNode* prev = &dummy;
	
	while(p1 != NULL && p2 != NULL)
	{
		if(p1->val < p2->val)
		{
			prev = p1;
			p1 = p1->next;
		}
		else
		{
			prev->next = p2;
			p2 = p2->next;
			prev = prev->next;
			prev->next = p1;
		}
	}
	if(p2)
		prev->next = p2;
	return dummy.next;
}



int main()
{
	int a[] = {1,3,5};
	int b[] = {2,4,6};
	int len1 = sizeof(a)/sizeof(int);
	int len2 = sizeof(b)/sizeof(int);
	ListNode* p1 = createList(a,len1);
	ListNode* p2 = createList(b,len2);

	ListNode* p3 = mergeTwoList1(p1,p2);
	return 0;
	
}