/********************************************************************************** 
* 
* You are given an n x n 2D matrix representing an image.
* Rotate the image by 90 degrees (clockwise).
* Follow up:
* Could you do this in-place?
*               
**********************************************************************************/

 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
*        旋转90
*   matrix[i][j] matirx[j][n-1-i]交换
*   
*  矩阵乘以旋转矩阵(反对称单位矩阵)
*
*/


void rotate(vector<vector<int> > &matrix)
{
    int i,j,temp;
    int n=matrix.size();
    for(i = 0;i < n/2;++i) 
	{
        for (j = i;j < n-1-i;++j)
		{
            temp = matrix[j][n-i-1];
            matrix[j][n-i-1] = matrix[i][j];
            matrix[i][j] = matrix[n-j-1][i];
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            matrix[n-i-1][n-j-1] = temp;
        }
    }
}






void rotate1(vector<vector<int> > &matrix) 
{
    int i,j,temp;
    int n=matrix.size();
    // 沿着副对角线反转
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][n - 1 - i];
            matrix[n - 1 - j][n - 1 - i] = temp;
        }
    }
    // 沿着水平中线反转
    for (int i = 0; i < n / 2; ++i){
        for (int j = 0; j < n; ++j) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - i][j];
            matrix[n - 1 - i][j] = temp;
        }
    }
}

int main() 
{  
	int num[] = {1,2,3,4,5,6,7,8,9};
    vector<int> row1(num,num+3);
	vector<int> row2(num+3,num+6);
	vector<int> row3(num+6,num+9);
    vector<vector<int> > matrix;
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    rotate1(matrix);
    int n = matrix.size();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%d ",matrix[i][j]);
        }//for
        printf("\n");
    }//for
    return 0;
}
 



