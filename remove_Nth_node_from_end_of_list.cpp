/*
*    remove Nth Node from end of list
* 
*    @date  2015/8/8
*
*/
#include<string>
#include<vector>


using namespace std;


struct ListNode
{
	int val;
    struct ListNode* next;
	ListNode(int x):val(x),next(NULL){};
};

ListNode* removeNthFromEnd(ListNode* head,int n)
{
	if(head == NULL)
		return NULL;
	ListNode* ahead = head;
	ListNode* behind = head;
	while(n--)
	{
		if(ahead == NULL) 
			return NULL;
		ahead = ahead->next;
	}
	while(ahead->next != NULL)
	{
		ahead = ahead->next;
		behind = behind->next;
	}
	
	ListNode* tmp =behind->next;
	behind->next = behind->next->next;
	/// ���������ͷ��ڴ棬���򷵻�ֵ��������
	//delete tmp;
	return tmp;
}

void createList(ListNode* &head)
{
	
	int i = 5;

	for(; i>0;i--)
	{
		if(i == 5)
		{
			head = new ListNode(i);
			continue;
		}
		ListNode* tmp = new ListNode(i);
	    tmp->next = head;
		head = tmp;
	}
}


int main()
{
	ListNode* head; // ��ʼ���ں����������
	createList(head);
	ListNode* RmNode = removeNthFromEnd(head,2);
	delete RmNode;

	return 0;

}