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
*                           ȥ�ع���
* ��122����һ����1��ڶ�����2�����õ�212��Ȼ���ǵ�һ����1���������2������
* ��ʱ���ڵ����������ڵڶ����������Ե�һ������������������������ٿ���212��
* ���ĵڶ���������������������Եõ����221����ʱȫ�����������
* ��������Ҳ�õ�����ȫ������ȥ���ظ��Ĺ��򡪡�ȥ�ص�ȫ���о��Ǵӵ�һ��������ÿ
* �����ֱ�����������ظ����ֵ����ֽ������ñ�̵Ļ��������ǵ�i�������j��������ʱ��
* Ҫ��[i,j)��û�����j������ȵ���
*
* ȫ���о��Ǵӵ�һ��������ÿ�����ֱ�������������ֽƻ�
*
* ȥ��ȫ����Ϊ�ӵ�һ��������ÿ�����ֱַ���������ķ��ظ����ֵ����ֽ���
*
* ȫ���еķǵݹ�����ɺ���ǰ���滻�����滻�㣬Ȼ���ɺ���ǰ�ҵ�һ�����滻����������滻��������
* ���ߵ��滻�����������ݡ�
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
			/// ȥ��
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

