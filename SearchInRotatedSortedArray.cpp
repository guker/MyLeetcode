/*
*    Search in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array
* 
*    @date  2015/8/9
*
*/
 
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


int search(vector<int> a,int target)
{
	int left = 0;
	int right = a.size()-1;
	while(left<=right)
	{
		int mid = (left+right)/2;
		if(target == a[mid]) return mid;
		if(a[left]<=a[right])
		{
			if(target < a[mid]) right = mid -1;
			else left = mid+1;
		}
		else if(a[left]<=a[mid])
		{
			if(target > a[mid] || target < a[left])
				left = mid+1;
			else
				right = mid-1;
		}
		else
		{
			if(target < a[mid]||target>a[right])
				right = mid-1;
			else
				left = mid+1;
		}
	}
	return -1;
}

int main()
{
	int num[] = {4,5,6,7,0,1,2};
	vector<int> vec(num,num+7);
	int pos = search(vec,1);
	return 0;
}
