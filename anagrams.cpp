/********************************************************************************** 
* 
* Given an array of strings, return all groups of strings that are anagrams.
* 
* Note: All inputs will be in lower-case.
*               
*
*   @date 2015-08-12
**********************************************************************************/

 

#include <iostream>
#include <vector>
#include<string>
#include<map>
#include <algorithm>
using namespace std;

/*
*  思路： 用map<string, int>记录排序后的字符串以及首次出现的位置
*
*  1. 从strs的第一个元素开始遍历，首先对string进行排序得到tmps；
*  2. 在map里查找tmps；
*  3. 若不存在，将tmps以及该元素的下标存入map<string ,int>；
*  4. 若存在，首先将第一次出现tmps时的原始字符串存入结果solution，即strs[map[tmps]]，并将map[tmps]设置为-1（防止下次再存），再将该字符串本身存入结果solution；
*  5. 重复以上1-4步，直到遍历结束。
*/


vector<string> anagrams(vector<string> &strs)
{  
	// Note: The Solution object is instantiated only once.  
	vector<string> solution;  
	map<string,int> smp;  
	map<string,int>::iterator it;  
	for(int i = 0; i < strs.size(); i++)  
	{  
		string tmps = strs[i];  
		sort(tmps.begin(),tmps.end());  
		it = smp.find(tmps);  
		if(it==smp.end())  
			smp[tmps] = i;  
		else{  
			if(smp[tmps]==-1)  
				solution.push_back(strs[i]);  
			else  
			{  
				solution.push_back(strs[smp[tmps]]);  
				smp[tmps]=-1;  
				solution.push_back(strs[i]);  
			}  
		}  
	}  
	return solution;  
}  

 

int main()
{
	string str = "tea";
	vector<string> strs;
	strs.push_back(str);
	str = "and";
	strs.push_back(str);
	str = "ate";
	strs.push_back(str);
	str = "eat";
	strs.push_back(str);
	str = "den";
	strs.push_back(str);
	vector<string> res = anagrams(strs);
	return 0;
}



