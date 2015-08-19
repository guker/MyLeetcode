/*
*   连续子数组最大乘积
* 动态规划
*
*   数组中存在正负零的情况
*   假设数组为a[N]，max[N] 表示以下标为 i 结尾的子数组乘积最大值，min[N] 表示以下标为 i 结尾的子数组乘积最小值。
*
*   为了处理数组元素为负的问题，必须将最小乘积也保存起来。很容易想到，若当前元素a[i]为负数，那么a[i]*max[i-1]得到的值并不一定比a[i]*min[i-1]大，因为min[i-1]可能为负，如果min[i-1]的绝对值大于max[i-1]，那么a[i]*min[i-1]负负相乘的值是更大的，因此有转移方程：
*
*   max[i] = MaxinThree(a[i],  a[i]*max[i-1],  a[i]*min[i-1]);    //求三者最大
*   min[ i] = MininThree(a[i],  a[i]*max[i-1],  a[i]*min[i-1]);     //求三者最小
*/
#include<vector>

using namespace std;

double MaxinThree(double a, double b, double c)  
{  
	return (((a>b)?a:b)>c) ? (a>b?a:b) : c;  
}  

double MininThree(double a, double b, double c)  
{  
	return (((a<b)?a:b)<c) ? (a<b?a:b) : c;  
}

double maxProduct(vector<double> arr)
{
	int len = arr.size();
	if(len <= 0)
		return 0;
	if(len == 1)
		return arr[0];
	double* max = new double[len];
	double* min = new double[len];
	max[0] = arr[0];
	min[0] = arr[0];

	double product = max[0];
	for(int i=1;i<len;i++)
	{
		max[i] = MaxinThree(arr[i],arr[i]*max[i-1],arr[i]*min[i-1]);
		min[i] = MininThree(arr[i],arr[i]*max[i-1],arr[i]*min[i-1]);
		if(max[i]>product)
			product = max[i];
	}
	delete [] max;
	delete [] min;
	return product;

}

