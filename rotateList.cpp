/********************************************************************************** 
* 
* Given a list, rotate the list to the right by k places, where k is non-negative.
* 
* For example:
* Given 1->2->3->4->5->NULL and k = 2,
* return 4->5->1->2->3->NULL.
*               
**********************************************************************************/

/*
*                 旋转链表
* 
*      @date 2015-08-13
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

/// made by hqwsky
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

ListNode *rotateRight(ListNode *head, int k) 
{
	if(head == NULL || head->next == NULL || k < 0)
		return head;
	ListNode* p = head;
	/// 查找第K个结点
	p = head;
	for(int i = 0;i < k;i++)
	{
		p = p->next;
	}
	///链尾则原链表输出
	if(p->next == NULL)
		return head;

	ListNode* tmp = head;
	head = p->next;
	p->next = NULL;

	p = head;
	while(p != NULL&&p->next != NULL)
		p = p->next;
	p->next = tmp;
	return head;
	
}
/*
*   思路：先把链表拼成首尾相连的环形链表
*/

ListNode *rotateRight1(ListNode *head, int k) {
    if (!head || k<=0){
        return head;
    }
        
    //find the length of List
    int len=1;
    ListNode *p=head;
    while( p->next != NULL ){
        p = p->next;
        len++;
    }
    //connect the tail to head
    p->next = head;
    //find the left place (take care the case - k > len)
    k = len - k % len;
        
    //find the place
    for(int i=0; i<k; i++){
        p = p->next;
    }
        
    //break the list
    head = p->next;
    p->next = NULL;
        
    return head;
        
}

int main()
{
	int a[] = {1,2,3,4,5};
	int len = sizeof(a)/sizeof(int);
	ListNode* p = createList(a,len);
	ListNode* res = rotateRight(p,3);

	return 0;
	
}
 