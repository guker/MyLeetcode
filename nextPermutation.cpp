/*
*    next permutation
* 
*    @date  2015/8/9
*
*/
 
/*
* 参见《C++ prime》附录
*  http://blog.csdn.net/hqwsky
*/
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


void nextPermutation(vector<int>&num)
{
	int len = num.size();
	if(len <= 1)
		return;
	int j;
	/// 从右边开始，找第一个比它右边树小的数据索引j
	for(j = len-2;j >= 0;j--)
	{
		if(num[j]<num[j+1])
			break;
	}
        /// 表示为全排列的最大值，下个则逆序，最小值
	if(j == -1)
	{
		reverse(num.begin(),num.end());
		return;
	}
	
	/// 在j右边的区间，从右向左找出比num[j]大的数字中最小的数字num[k]
	int k = j+1;
	for(int i = len-1;i>j;--i)
	{
		if(num[i]>num[j])
		{
			k = i;
			break;
		}
	}
	/// 交换
	swap(num[j],num[k]);
        /// 逆序
	reverse(num.begin()+j+1,num.end());
}

int main()
{
	int num[] = {1,4,5,3,2};
	vector<int> vec(num,num+5);
	nextPermutation(vec);
	return 0;
}

