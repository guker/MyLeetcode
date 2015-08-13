/********************************************************************************** 
* 
* Find the contiguous subarray within an array (containing at least one number) 
* which has the largest sum.
* 
* For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
* the contiguous subarray [4,−1,2,1] has the largest sum = 6.
* 
* More practice:
* 
* If you have figured out the O(n) solution, try coding another solution using 
* the divide and conquer approach, which is more subtle.
* 
*               
**********************************************************************************/
/*
*     最大和子序列
*  若a[i]是负数，那么它不可能为具有最大序列和的起点，因为任何包含a[i]的作为起点的子序列都可以通过用a[i+1]作为起点来改进。
*  类似的有，任何的和为负的子序列不可能是最优子序列的前缀，比如，循环中我们检测到从a[i]到a[j]的子序列都是负数，那么我们
*  把起点推进到j+1；
*  举例来说，令p是i+1到j之间的任何一个下标，由于前面假设a[i]+...+a[j]是负数，则开始于下标p的任何子序列都不会大于在下标i
*  并且包含从a[i]到a[p-1]的子序列对应的子序列(j是使得从下标i开始成为负数的第一个下标)，因此，把i推进到j+1是安全的，不会
*  最优解，注意的是：虽然，如果有以a[j]结尾的某序列和是负数就表明了这个序列中的任何一个数不可能是与a[j]后面的数形成的
*  最大子序列的开头，但是并不表明a[j]前面的某个序列就不是最大序列，也就是说不能确定最大子序列在a[j]前还是a[j]后，即最大
*  子序列位置不能求出。但是能确保maxSum的值是当前最大的子序列和。这个算法还有一个有点就是，它只对数据进行一次扫描，一旦
*  a[j]被读入处理就不需要再记忆。它是一个联机算法.
*
*   @date 2015-08-12
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INT_MIN     (-2147483647 - 1)

int maxSubArray1(int A[], int n);
int maxSubArray2(int A[], int n); 

int max(int x, int y){
    return x>y?x:y;
}
/* O(n3)算法，算法本身很容易理解，而且很直观的感觉做了很多无用操作。
例如：i = 0, j = 3时，会计算a[0] + a[1] +…+ a[3]；而当i = 0, j = 4时候又会计算a[0] + a[1] +…a[4]。
*/
long maxSubSum1(const vector<int>& a) 
{ 
       long maxSum = 0; 
       for (int i = 0; i < a.size(); i++) 
       { 
              for (int j = i; j < a.size(); j++) 
              { 
                     long thisSum = 0; 
 
                     for (int k = i; k <= j; k++) 
                     { 
                            thisSum += a[k]; 
                     } 
                     if (thisSum > maxSum) 
                            maxSum = thisSum; 
              } 
       } 
       return maxSum; 
} 

/*
* O(n2)算法，thisSum表示a[i] + a[i+1] + … + a[j-1]
*
*/
long maxSubSum2(const vector<int>& a) 
{ 
       long maxSum = 0; 
       for (int i = 0; i < a.size(); i++) 
       { 
              long thisSum = 0; 
              for (int j = i; j < a.size(); j++) 
              { 
                     thisSum += a[j]; 
                     if (thisSum > maxSum) 
                            maxSum = thisSum; 
              } 
       } 
       return maxSum; 
}

int maxSubArray(int A[], int n)
{
    if (rand()%2){
        return maxSubArray1(A, n);
    }
    return maxSubArray2(A, n);
}
/// 线性算法O(n)
int maxSubArray1(int A[], int n)
{
    int *sum = new int[n];
    sum[0] = A[0];
    int m = A[0]; 
    for (int i=1; i<n; i++)
	{
        sum[i] = max(A[i], A[i] + sum[i-1]);
        m = max(m, sum[i]);
    }
    delete[] sum;
    return m;
}

int maxSubArray2(int A[], int n) {
    int m=INT_MIN;
    int sum=0;
    for (int i=0; i<n; i++)
	{
        sum += A[i];
        m = max(sum, m);
        if (sum<0)
		{
            sum = 0;
        }
    }
    return m;
}

int main()
{
    srand(time(NULL));
    int a[]= {2,1,-3,-1,-1,2,-1,-5,-4};
    printf("%d\n", maxSubArray(a, sizeof(a)/sizeof(int)));
    printf("%d\n", maxSubArray(a, sizeof(a)/sizeof(int)));
    return 0;
}

