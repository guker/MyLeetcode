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
*                        ȫ���еĵݹ�ʵ��
*
* ˼·:��ÿ��Ԫ�طŵ�n��Ԫ����ɵĶ�����ǰ����Ȼ���ʣ��Ԫ�ؽ���ȫ���У����εݹ���ȥ
* {a b c}
* ���Ƚ�a�ŵ���ǰ�棨����һ��Ԫ�ؽ�������Ȼ������bc��Ȼ��a�Ż�ԭ��λ��
*  {a b c} {a c b}
* ��ν�b�ŵ���ǰ��������һ��Ԫ�ؽ�������Ȼ��ȫ����ac��Ȼ��b�Ż�
* {b a c} {b c a}
*
* �����4��Ԫ�أ���Ԫ�����ηŵ���һ��Ԫ�ص�λ�ã������������������3Ԫ������
*/

class Solution {  
private:    
    vector<vector<int> > ret;  
    int len;  
      
public:  
	///�����̶���ǰ�� k-1 λ��Ȼ��ֱ� swap(k,k), swap(k, k+1) , swap(k, k+2) ...
    void perm(vector<int> &num, int i){  
        if( i == len){  
            ret.push_back(num);  
        }  
          
        for(int j = i; j < len; j++){  
			///ѡ���ε�����ͷ
            swap(num[i], num[j]);  
            perm(num, i + 1); 
			/// �ָ��ϴε�����
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
  
    ///stl��algorithm�����next_permutation�㷨
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