/*
*    median of two sorted arrays
*     
*    @date 2015/8/7
*
*/
#include<iostream>
#include<algorithm>

using namespace std;

/// 二分查找
int binarySearch(int A[],int low,int high,int key)
{
	while(low<high)
	{
		int mid = low + (high - low)/2;
		if(key == A[mid])return mid;
		if(key > A[mid])
			low = mid+1;
		else
			 high = mid +1;

	}

	return low;
}


/// 一般解法
double findMedianSortedArrays(int a[],int m,int b[],int n)
{
	int *tmp = new int[m+n];   
	/// 复制数组
	memcpy(tmp,a,sizeof(int)*m); 
	memcpy(tmp+m,b,sizeof(int)*n);
	/// <algorithm>中的sort函数
	std::sort(tmp,tmp+m+n);
	double median = (double)((n+m)%2?tmp[(n+m)>>1]:(tmp[(n+m-1)>>1]+tmp[(n+m)>>1])/2.0);  
	
	delete [] tmp;
	return median;
}

/// 边合并边寻找第k小值
double findKth(int a[],int m,int b[],int n,int tar)
{
	
	int* tmp = new int[m+n];
	int i = 0;
	int j = 0;
	int k = 0;
	while(i<m&&j<n)
	{
		if(a[i] <= b[j])
		{
			tmp[k] = a[i];
			if(k == tar)
				break;
			k++;
			i++;
			
		}
		else
		{
			tmp[k] = b[j];
			if(k == tar)
				break;
			k++;
			j++;


		}
	
	}
	while(i<m)
	{
		tmp[k] = a[i];
		if(k == tar)
			break;
		k++;
		i++;
	}
	while(j<n)
	{
		tmp[k] = b[j];
		if(k == tar)
			break;
		k++;
		j++;
	}

    double res = tmp[k-1]*1.0;
	delete [] tmp;

	return res;
}


double FindMedianSortedArrays(int a[],int m,int b[],int n)
{
	int total = m + n;
	/// 判断奇偶性
	if(total&0x1)
		return findKth(a,m,b,n,total/2+1);
	else
		return (findKth(a,m,b,n,total/2) + findKth(a,m,b,n,total/2+1))/2;
}

int main()
{
	int num1[] = {5,6,7,8};
	int num2[] = {1,2,3,4};
	int m = sizeof num1 / sizeof(int);
	int n = sizeof num2 / sizeof(int);
	double median = findMedianSortedArrays(num1,m,num2,n);
	double median1 = FindMedianSortedArrays(num1,m,num2,n);
	return 0;
}