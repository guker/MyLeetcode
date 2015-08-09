/*
*    reverse Nodes in k-group
* 
*    @date  2015/8/9
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

ListNode *reverseNodesInKGroup(ListNode *head,int k)  
{  
	/// dummy 维护头结点
    ListNode *dummy = new ListNode(-1);  
    dummy->next = head;  
    ListNode *pre = dummy;  
  
    while(pre->next)  
    {  
        ListNode *last = pre->next;  
        //找到第K个元素，看看是否为NULL  
        for(int i=1;i<k&&last;i++)//这里要判断Last是否为空，否则会出现空指针异常  
            last=last->next;  
  
        //如果第K个元素存在  
        if(last)  
        {  
            ListNode *p = last->next;  
            ListNode *first = pre->next; 

			/* 
			*  翻转链表的好方法 需要维护pre，cur，post 三个指针
			*/
            //group内逆序  
            ListNode *cur = pre->next;  
            ListNode *post = cur->next;  
            for(int i=1;i<k;i++)  
            {  
                ListNode *tmp = post->next;  
                post->next = cur;  
                cur=post;  
                post=tmp;  
            }             
            pre->next = last;  //pre链接上最后一个  
            first->next = p;//first链接上后一个group             
            pre = first;//pre挪到first，作为下一个group的pre  
        }  
        else  
        {  
            //什么也不做，保持原来的顺序  
            break;  
        }  
    }  
    head = dummy->next;  
    delete dummy;  
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
	ListNode* head = reverseNodesInKGroup(p,3);

	return 0;

}
