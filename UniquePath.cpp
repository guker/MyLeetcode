/********************************************************************************** 
* 
* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
* 
* The robot can only move either down or right at any point in time. The robot is trying to reach 
* the bottom-right corner of the grid (marked 'Finish' in the diagram below).
* 
* How many possible unique paths are there?
* 
* Above is a 3 x 7 grid. How many possible unique paths are there?
* 
* Note: m and n will be at most 100.
*               
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int*a, int m, int n);

/*   
*  mxn的格子里从左上角走到右下角有多少种走法，只能向右或向下走。
*  分析：向下需要 m-1 步，向右需要 n-1步

*            递归（回溯法）
*  int uniquePathsBackTrack(int m, int n) 
*  {
*      if(m==1 || n==1) return 1;
*     return uniquePaths(m-1, n) + uniquePaths(m, n-1);
*  }
*
*           动态规划
*  定义一个二维数组 A[M][N]，从左上开始依次计算每一行的值，最后返回 A[M-1][N-1]即可，递推方程是：
*  A[I][J]=A[I-1][J]+A[I][J-1]
*
*     @date 2015-08-13
*/

int uniquePaths(int m, int n) 
{
    int* matrix = new int[m*n];
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++)
		{
            if(i==0 || j==0)
			{
                matrix[i*n+j]=1;
            }
			else
			{
                matrix[i*n+j] = matrix[(i-1)*n+j] + matrix[i*n+j-1];
            }
        }
    } 
    printMatrix(matrix, m, n);
    int u = matrix[m*n-1];
    delete[] matrix;
    return u;
}

void printMatrix(int*a, int m, int n)
{
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("%4d ", a[i*n+j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    int m=3, n=7;
    if( argc>2){
        m = atoi(argv[1]);
        n = atoi(argv[2]);
    }
    
    printf("uniquePaths=%d\n", uniquePaths(m,n));
    return  0;
}
 