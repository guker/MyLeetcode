/********************************************************************************** 
* 
* Given a set of candidate numbers (C) and a target number (T), find all unique combinations 
* in C where the candidate numbers sums to T. 
* 
* The same repeated number may be chosen from C unlimited number of times.
* 
* Note:
* 
* All numbers (including target) will be positive integers.
* Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
* The solution set must not contain duplicate combinations.
* 
* For example, given candidate set 2,3,6,7 and target 7, 
* A solution set is: 
* [7] 
* [2, 2, 3] 
* 
*               
**********************************************************************************/
 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/// 递归处理
/// 前提candidates有序
void combinationSumHelper(vector<int> &candidates, int start, int target, vector<int> &solution, vector< vector<int> > &result) {
    if (target<0){
        return;
    }
    if (target==0){
        result.push_back(solution);
    }
    for(int i=start; i<candidates.size(); i++){
        //remove duplicates
        if (i>start && candidates[i] == candidates[i-1]) 
		{
            continue;
        }
        solution.push_back(candidates[i]);
        combinationSumHelper(candidates, i, target - candidates[i], solution, result);
        solution.pop_back();
    }
}

vector<vector<int> > combinationSum(vector<int> &candidates, int target)
{
    vector< vector<int> > result;
    if (candidates.size()<=0)
	{
        return result;
    }
    sort(candidates.begin(), candidates.end());
    
    vector<int> solution;
    combinationSumHelper(candidates, 0, target, solution, result);

    return result;
}

void printMatrix(vector< vector<int> > &vv)
{
    for(int i=0; i<vv.size(); i++) {
        cout << "[";
        for(int j=0; j<vv[i].size(); j++) 
		{
            cout << " " << vv[i][j];
        }
        cout << "]" << endl;;
    }
}
///第二种思路，这明显是多重背包问题，解多重背包是很容易的，麻烦的是路径
void createPath(vector<vector<int> >& ans,vector<int>& path,int k,int tar,vector<vector<bool> >& dp,vector<int>& can)  
{  
    if(tar==0)  
    {  
        reverse(path.begin(),path.end());  
        ans.push_back(path);  
        reverse(path.begin(),path.end());  
        return ;  
    }  
    if(k<0 || !dp[k][tar])  
        return ;  
    if(k>0&&dp[k-1][tar])  
        createPath(ans,path,k-1,tar,dp,can);  
    if (tar>=can[k]&&dp[k][tar-can[k]])  
    {  
        path.push_back(can[k]);  
        createPath(ans,path,k,tar-can[k],dp,can);  
        path.pop_back();  
    }  
}  
vector<vector<int> > combinationSum1(vector<int> &can, int target) {  
    // Note: The Solution object is instantiated only once and is reused by each test case.  
    sort(can.begin(),can.end());  
    int k=0;  
    while(k<can.size()&&can[k]<=target)  
        k++;  
    if(k<=0)  
        return vector<vector<int> >();  
    vector<vector<bool> > dp(k,vector<bool>(target+1,false));  
    for(int i=0;i<=target;i++)  
        if(i%can[0]==0)  
            dp[0][i]=true;  
          
    for(int i=1;i<k;i++)  
    {  
        for(int j=0;j<can[i];j++)  
            dp[i][j]=dp[i-1][j];  
        for(int j=can[i];j<=target;j++)  
            dp[i][j]=dp[i-1][j]||dp[i][j-can[i]];  
    }  
    vector<vector<int> > ans;  
    vector<int> path;  
    createPath(ans,path,k-1,target,dp,can);  
    return ans;  
}  
 


void printArray(vector<int> &v)
{
    cout << "{";
    for(int i=0; i<v.size(); i++) 
	{
        cout << " " << v[i];
    }
    cout << "}" << endl;
}


int main(int argc, char** argv)
{
    int a[] = {4,2,3,3,5,7};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    int target = 7;
    cout << "array  = ";
    printArray(v);
    cout << "target = " << target << endl;
    
    vector< vector<int> > vv = combinationSum(v, target);
    printMatrix(vv);

    return 0;
}





