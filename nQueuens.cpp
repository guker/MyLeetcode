/********************************************************************************** 
* 
* The n-queens puzzle is the problem of placing n queens on an n°¡n chessboard 
* such that no two queens attack each other.
* 
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* 
* Each solution contains a distinct board configuration of the n-queens' placement, 
* where 'Q' and '.' both indicate a queen and an empty space respectively.
* 
* For example,
* There exist two distinct solutions to the 4-queens puzzle:
* 
* [
*  [".Q..",  // Solution 1
*   "...Q",
*   "Q...",
*   "..Q."],
* 
*  ["..Q.",  // Solution 2
*   "Q...",
*   "...Q",
*   ".Q.."]
* ]
* 
*  @date 2015-08-12            
**********************************************************************************/
/*
*           Nª ∫ÛŒ Ã‚
*
*
*/
#include <vector>
using namespace std;

void printQueen(vector<int> &A,int n,vector<vector<string>> &result)
{  
    vector<string> r;  
        for(int i=0;i<n;i++){  
            string str(n,'.');  
            str[A[i]] = 'Q';  
            r.push_back(str);  
        }  
        result.push_back(r);  
}  
bool isValidQueens(vector<int>A,int r)
{  
    for(int i=0;i<r;i++){  
        if((A[i]==A[r])||(abs(A[i]-A[r]))==(r-i))  
            return false;  
    }  
    return true;  
}  
void nqueens(vector<int> A,int cur, int n,vector<vector<string>> &result)
{  
    if(cur == n){  
        printQueen(A,n,result);  
    }else{  
        for(int i=0;i<n;i++){  
            A[cur] = i;  
            if(isValidQueens(A,cur))  
                nqueens(A,cur+1,n,result);  
        }  
    }  
}  
vector<vector<string> > solveNQueens(int n) 
{  
    vector<vector<string>> result;  
    result.clear();  
    vector<int> A(n,-1);  
    nqueens(A,0,n,result);  
    return result;  
} 


int main()
{
	vector<vector<string> > res = solveNQueens(8);
	return 0;
}

