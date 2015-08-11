/********************************************************************************** 
* 
* Given a sorted array of integers, find the starting and ending position of a given target value.
/********************************************************************************** 
* 
* Given a sorted array and a target value, return the index if the target is found. 
* If not, return the index where it would be if it were inserted in order.
* 
* You may assume no duplicates in the array.
* 
* Here are few examples.
* [1,3,5,6], 5 → 2
* [1,3,5,6], 2 → 1
* [1,3,5,6], 7 → 4
* [1,3,5,6], 0 → 0
* 
*               
**********************************************************************************/
 
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
/// 二分查找
int binarySearch(int a[],int len,int key)
{
	int low = 0;
	int high = len-1;
	while(low<=high)
	{
		int mid = low + (high-low)/2;
		if(key == a[mid]) return mid;
		if(a[mid] < key)
			low = mid+1;
		if(a[mid]>key)
			high = mid-1;
	}
	/// 返回插入的位置
	return low;
}

int searchInsert(int a[],int len,int target)
{
	if(len == 0) return len;
	return binarySearch(a,len,target);
}

int main()
{
	int a[]={1,3,5,6};
    printf("%d -> %d\n", 5, searchInsert(a, 4, 5));
    printf("%d -> %d\n", 2, searchInsert(a, 4, 2));
    printf("%d -> %d\n", 7, searchInsert(a, 4, 7));
    printf("%d -> %d\n", 0, searchInsert(a, 4, 0));
    return 0;
}




