/*
*    next permutation
* 
*    @date  2015/8/9
*
*/
 
/*
*  ²Î¼û¡¶c++ prime¡·¸½Â¼
*  
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
	for(j = len-2;j >= 0;j--)
	{
		if(num[j]<num[j+1])
			break;
	}

	if(j == -1)
	{
		reverse(num.begin(),num.end());
		return;
	}
	
	
	int k = j+1;
	for(int i = len-1;i>j;--i)
	{
		if(num[i]>num[j])
		{
			k = i;
			break;
		}
	}
	swap(num[j],num[k]);

	reverse(num.begin()+j+1,num.end());
}

int main()
{
	int num[] = {1,4,5,3,2};
	vector<int> vec(num,num+5);
	nextPermutation(vec);
	return 0;
}

