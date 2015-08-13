/********************************************************************************** 
* 
* Given a m x n grid filled with non-negative numbers, find a path from top left to 
* bottom right which minimizes the sum of all numbers along its path.
* 
* Note: You can only move either down or right at any point in time.
*               
**********************************************************************************/

/*  一个m x n 的网格，每个格子里有一个非负整数，找到一条从左上角到右下角的路径，
*   使其经过的格子数值之和最小，每一步只能向右或向下
*   典型的动态规划题，使用动态规划求解问题，最重要的就是确定动态规划三要素：
*   问题的阶段,每个阶段的状态以及从前一个阶段转化到后一个阶段之间的递推关系。
*   递推关系必须是从次小的问题开始到较大的问题之间的转化
*
*   确定了动态规划的这三要素，整个求解过程就可以用一个最优决策表来描述，最优决策表
*   是一个二维表，其中行表示决策的阶段，列表示问题状态，表格需要填写的数据一般对应
*   此问题的在某个阶段某个状态下的最优值（如最短路径，最长公共子序列，最大价值等），
*   填表的过程就是根据递推关系，从1行1列开始，以行或者列优先的顺序，依次填写表格，
*   最后根据整个表格的数据通过简单的取舍或者运算求得问题的最优解。
* 
*   MPS[i][j] = Min（MPS[i-1][j]，MPS[i][j-1]）+ val[i][j]；
*   即格子 i，j 的MPS值可能有两个来源：其左侧格子 i，j-1 或者其上侧格子 i-1，j
*   取这两个来源的较小MPS值，再加上当前格子的值 val[i][j] 即为结果。
*
*   @date 2015-08-13
*
*/

#include <limits.h>
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int> > &grid)
{
    if (grid.size()<=0)
	{
        return 0;
    }
    int i, j;
    for(i=0; i<grid.size(); i++)
	{
        for(j=0; j<grid[i].size(); j++)
		{
            int top = i-1<0 ? INT_MAX : grid[i-1][j];
            int left = j-1<0 ? INT_MAX : grid[i][j-1];
            if (top==INT_MAX && left==INT_MAX)
			{
                continue;
            }
            grid[i][j] += (top < left? top: left);

        }
    }

    return grid[grid.size()-1][grid[0].size()-1];
}


int main()
{
    int a[6][2]={{7,2},{6,6},{8,6},{8,7},{5,0},{6,0}};
    vector< vector<int> > grid;
    for(int i=0; i<6; i++){
        vector<int> v;
        for(int j=0; j<2; j++){
            v.push_back(a[i][j]);
        }
        grid.push_back(v);
    }
    
    cout << "minPathSum=" << minPathSum(grid) << endl;

    return 0;
}
