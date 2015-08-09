/*
*    meger K sorted lists
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

/// meger two lists
// 合并两个有序链表  
ListNode * MergeSortedList(ListNode * pHead1, ListNode * pHead2)  
{
	if(pHead1 == NULL)
		return pHead2;
	if(pHead2 == NULL)
		return pHead1;
	///初始化头指针
	ListNode* pHeadMerged = NULL;
	if(pHead1->val < pHead2->val)
	{
		pHeadMerged = pHead1;
		pHead1 = pHead1->next;
		pHeadMerged->next = NULL;
	}
	else
	{
		pHeadMerged = pHead2;
		pHead2 = pHead2->next;
		pHeadMerged->next = NULL;
	}

	ListNode* pTemp = pHeadMerged;
	while(pHead1 != NULL && pHead2 != NULL)
	{
		if(pHead1->val < pHead2->val)
		{
			pTemp->next = pHead1;  
            pHead1 = pHead1->next;  
            pTemp = pTemp->next;  
            pTemp->next = NULL;  
		}
		else
		{
			pTemp->next = pHead2;  
            pHead2 = pHead2->next;  
            pTemp = pTemp->next;  
            pTemp->next = NULL; 

		}
	}
	if(pHead1 != NULL)
	{
		pTemp->next = pHead1;
	}
	else if(pHead2 != NULL)
		pTemp->next = pHead2;
	return pHeadMerged;
}


ListNode* createList(int a[], int n)
{
    ListNode *head=NULL, *p=NULL;
    for(int i=0; i<n; i++){
        if (head == NULL){
            head = p = new ListNode(a[i]);
        }else{
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}

class ListNodeCompare:public binary_function<ListNode*,ListNode*,bool>  
{  
public:  
    bool operator()(ListNode* t1,ListNode* t2)const  
    {  
        if ( !t1||!t2 )  
            return !t2;  
        return t1->val>t2->val;  
    }  
}; 

/// 优先队列
ListNode *mergeKLists(vector<ListNode *> &lists) {  
    // Note: The Solution object is instantiated only once and is reused by each test case.  
    if (lists.empty())  
        return NULL;
    // 定义优先队列，最小堆实现	
    priority_queue<ListNode*,vector<ListNode*>,ListNodeCompare> Q;  
    for(int i=0;i<lists.size();i++)  
	{
        if ( lists[i]!=NULL)  
            Q.push(lists[i]); 
	}
	/// 新建链表,设置头结点，傀儡结点dummy
    ListNode guard(-1);  
    ///  尾指针，始终指向链表的尾部，常用于构建链表记录尾结点的位置
    ListNode* tail=&guard;  
    while(!Q.empty())  
    {  
        ListNode* toAdd=Q.top();  
        Q.pop();  
        tail->next=toAdd;  
        tail=tail->next;  
        if (toAdd->next)  
            Q.push(toAdd->next);  
    }  
    return guard.next;  
} 


 
int main()
{
	int a[] = {2,3,5};
	int b[] = {1,4};
	ListNode* p1 = createList(a,sizeof(a)/sizeof(int));
	ListNode* p2 = createList(b,sizeof(b)/sizeof(int));
	vector<ListNode*> vec;
	vec.push_back(p1);
	vec.push_back(p2);
	//ListNode* p3 = MergeSortedList(p1,p2);
	ListNode* p4 = mergeKLists(vec); 
	return 0;
}
