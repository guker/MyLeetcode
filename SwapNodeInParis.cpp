/*
*    swap Nodes in Paris
* 
*    @date  2015/8/8
*
*/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;


struct ListNode
{
	int val;
    struct ListNode* next;
	ListNode(int x):val(x),next(NULL){};
};

ListNode* swapPairs(ListNode* head)
{
	/// 检查是否空链表
	if(head == NULL)
		return head;
	/// 检查是否单结点链表
	if(head->next == NULL)
		return head;
	///用来保存当前结点的上一结点指针
	ListNode* prev;
	/// 当前结点指针
	ListNode* p;
	p = head;
	prev = head;
	do
	{
		ListNode* tmp = p->next;
		p->next = tmp->next;
		tmp->next = p;
		if(prev != head)
			prev->next = tmp;
		else
			head = tmp;
		prev = p;
		p = p->next;

	}while(p != NULL && p->next != NULL);
	return head;
}

ListNode* createList(int a[],int len)
{
	if(len == 0)
		return NULL;
	
	ListNode dummy(-1);
	ListNode* tail = &dummy;

	for(int i = 0; i < len; i++)
	{
		ListNode* tmp = new ListNode(a[i]);
		tail->next = tmp;
		tail = tail->next;
	}

	return dummy.next;
}

int main()
{
	int a[] = {1,2,3,4,5};
	ListNode* p = createList(a,sizeof(a)/sizeof(int));
	ListNode* head = swapPairs(p);

	return 0;

}
