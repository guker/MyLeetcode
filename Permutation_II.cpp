/********************************************************************************** 
* 
* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
* 
* For example,
* [1,1,2] have the following unique permutations:
* [1,1,2], [1,2,1], and [2,1,1].
* 
*               
**********************************************************************************/

 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
*                           去重规则
* 对122，第一个数1与第二个数2交换得到212，然后考虑第一个数1与第三个数2交换，
* 此时由于第三个数等于第二个数，所以第一个数不再与第三个数交换。再考虑212，
* 它的第二个数与第三个数交换可以得到解决221。此时全排列生成完毕
* 这样我们也得到了在全排列中去掉重复的规则——去重的全排列就是从第一个数字起每
* 个数分别与它后面非重复出现的数字交换。用编程的话描述就是第i个数与第j个数交换时，
* 要求[i,j)中没有与第j个数相等的数
*
* 全排列就是从第一个数字起每个数分别与它后面的数字狡猾
*
* 去重全排列为从第一个数字起每个数字分别与它后面的非重复出现的数字交换
*
* 全排列的非递归就是由后向前找替换数和替换点，然后由后向前找第一个比替换数大的数与替换数交换，
* 最后颠倒替换点后的所有数据。
*
*/

class Solution {
public:
    bool noswap(vector<int> &num, int i, int step) {
        int j;
        for (j = step; j < i; j++) {
            if (num[i] == num[j])
                return true;
        }
        return false;
    }
    void dfs(vector<int> &num, int step, vector<vector<int> > &res) {
        if (step > num.size()-1) {
            res.push_back(num);
            return;
        }
        int i;
        for (i = step; i < num.size(); i++) {
			/// 去重
            if (noswap(num, i, step))
                continue;
            swap(num[i], num[step]);
            dfs(num, step + 1, res);
            swap(num[i], num[step]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        dfs(num, 0, res);
        return res;
    }
};

int main()
{
	int num[] = {1,1,2};
	vector<int> vec(num,num+3);
	Solution sln;
	vector<vector<int> > p = sln.permuteUnique(vec);

	return 0;
}

