/********************************************************************************** 
* 
* Given an unsorted integer array, find the first missing positive integer.
* 
* For example,
* Given [1,2,0] return 3,
* and [3,4,-1,1] return 2.
* 
* Your algorithm should run in O(n) time and uses constant space.
* 
*               
**********************************************************************************/
 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
*虽然不能再另外开辟非常数级的额外空间，但是可以在输入数组上就地进行swap操作。
*
*思路：交换数组元素，使得数组中第i位存放数值(i+1)。最后遍历数组，
*      寻找第一个不符合此要求的元素，返回其下标。整个过程需要遍历两次数组，复杂度为O(n)。
*
*/

int fristMissingPositive(int a[],int len)
{
	if(len == 0) return 1;
	for(int i= 0;i<len;i++)
	{
		if(a[i] != i+1 && a[i]-1>=0 && a[i]-1<len && a[a[i]-1] != a[i])
		{
			int tmp = a[a[i]-1];
			a[a[i]-1] = a[i];
			a[i] =tmp;
			i--;
		}
	}
	for(int i = 0;i<len;i++)
	{
		if(a[i] != i+1)return i+1;

	}
	return len+1;

}

int main()
{
	int a[] = {3,4,-1,1};

	int ret = fristMissingPositive(a,sizeof(a)/sizeof(int));


	return 0;
}



