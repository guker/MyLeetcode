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
	/// dummy ά��ͷ���
    ListNode *dummy = new ListNode(-1);  
    dummy->next = head;  
    ListNode *pre = dummy;  
  
    while(pre->next)  
    {  
        ListNode *last = pre->next;  
        //�ҵ���K��Ԫ�أ������Ƿ�ΪNULL  
        for(int i=1;i<k&&last;i++)//����Ҫ�ж�Last�Ƿ�Ϊ�գ��������ֿ�ָ���쳣  
            last=last->next;  
  
        //�����K��Ԫ�ش���  
        if(last)  
        {  
            ListNode *p = last->next;  
            ListNode *first = pre->next; 

			/* 
			*  ��ת����ĺ÷��� ��Ҫά��pre��cur��post ����ָ��
			*/
            //group������  
            ListNode *cur = pre->next;  
            ListNode *post = cur->next;  
            for(int i=1;i<k;i++)  
            {  
                ListNode *tmp = post->next;  
                post->next = cur;  
                cur=post;  
                post=tmp;  
            }             
            pre->next = last;  //pre���������һ��  
            first->next = p;//first�����Ϻ�һ��group             
            pre = first;//preŲ��first����Ϊ��һ��group��pre  
        }  
        else  
        {  
            //ʲôҲ����������ԭ����˳��  
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
