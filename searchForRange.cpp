/********************************************************************************** 
* 
* Given a sorted array of integers, find the starting and ending position of a given target value.
* 
* Your algorithm's runtime complexity must be in the order of O(log n).
* 
* If the target is not found in the array, return [-1, -1].
* 
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
* 
*               
**********************************************************************************/
 
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
/*
 *   O(log n) solution must be something like binary search.
 *
 *   So, we can use the binary search to find the one postion - `pos`
 *   
 *   then, we can keep using the binary search find the target in A[0..pos-1] and A[pos+1..n]
 *
 *   The code below is self-explaination
 */
/// ���ֲ���
int binarySearch(int a[],int low,int high,int key)
{
	while(low <= high)
	{
		int mid  = low + (high-low)/2;
		if(a[mid] == key) return mid;
		if(a[mid]<key)
			low = mid+1;
		if(a[mid]>key)
			high = mid-1;
	}
	return -1;
}

vector<int> searchRange(int a[],int len,int target)
{
	/// �ҳ�target��һ��λ�ã�Ȼ����ǰ��������
	int pos = binarySearch(a,0,len-1,target);

	vector<int> v;
	int low = -1,high = -1;
	if(pos>=0)
	{
		/// ��ǰ����
		low = high = pos;
		int l = low;
		do
		{
			low = l;
			l = binarySearch(a,0,low-1,target);
		}while(l>=0);
		/// ������
		int h = high;
		do 
		{
			high = h;
			h = binarySearch(a,high+1,len-1,target);
		}while(h>=0);


	}

	v.push_back(low);
	v.push_back(high);
	return v;

}


int main()
{
	int a[]= {5,5,5,7,7,7,7,8,8,10};
	int len = sizeof(a)/sizeof(int);

	vector<int> res = searchRange(a,len,7);
	return 0;

}



