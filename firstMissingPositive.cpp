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
*��Ȼ���������⿪�ٷǳ������Ķ���ռ䣬���ǿ��������������Ͼ͵ؽ���swap������
*
*˼·����������Ԫ�أ�ʹ�������е�iλ�����ֵ(i+1)�����������飬
*      Ѱ�ҵ�һ�������ϴ�Ҫ���Ԫ�أ��������±ꡣ����������Ҫ�����������飬���Ӷ�ΪO(n)��
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



