/********************************************************************************** 
* 
* Given a collection of numbers, return all possible permutations.
* 
* For example,
* [1,2,3] have the following permutations:
* [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
* 
*               
**********************************************************************************/
 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/* 
*                        全排列的递归实现
*
* 思路:将每个元素放到n个元素组成的队列最前方，然后对剩余元素进行全排列，依次递归下去
* {a b c}
* 首先将a放到最前面（跟第一个元素交换），然后排列bc，然后将a放回原来位置
*  {a b c} {a c b}
* 其次将b放到最前方（跟第一个元素交换），然后全排列ac，然后将b放回
* {b a c} {b c a}
*
* 如果是4个元素，则将元素依次放到第一个元素的位置，后面的排序类似上面3元素排序
*/

class Solution {  
private:    
    vector<vector<int> > ret;  
    int len;  
      
public:  
	///交换固定了前面 k-1 位，然后分别 swap(k,k), swap(k, k+1) , swap(k, k+2) ...
    void perm(vector<int> &num, int i){  
        if( i == len){  
            ret.push_back(num);  
        }  
          
        for(int j = i; j < len; j++){  
			///选当次的排列头
            swap(num[i], num[j]);  
            perm(num, i + 1); 
			/// 恢复上次的排列
            swap(num[j], num[i]);  
        }  
    }  
  
  
    vector<vector<int> > permute(vector<int> &num) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        len = num.size();  
        ret.clear();  
          
        perm(num, 0);  
          
        return ret;  
          
    }  
};

class Solver {  
public:

    int factorial(int n){  
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;  
    }  
  
    ///stl的algorithm里面的next_permutation算法
    vector<vector<int> > permute(vector<int> &num) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int N = num.size();  
        vector<vector<int> > ret;  
          
        ret.push_back(num);  
          
        for(int i = 1; i < factorial(N); i++){  
            next_permutation(num.begin(),num.end());  
            ret.push_back(num);  
        }  
          
        return ret;  
          
    }  
};  

int main()
{
	int num[] = {1,2,3,4};
	vector<int> vec(num,num+4);
	Solver sln;
	vector<vector<int> > p =  sln.permute(vec);
	return 0;

}