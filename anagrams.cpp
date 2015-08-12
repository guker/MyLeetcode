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
*  ˼·�� ��map<string, int>��¼�������ַ����Լ��״γ��ֵ�λ��
*
*  1. ��strs�ĵ�һ��Ԫ�ؿ�ʼ���������ȶ�string��������õ�tmps��
*  2. ��map�����tmps��
*  3. �������ڣ���tmps�Լ���Ԫ�ص��±����map<string ,int>��
*  4. �����ڣ����Ƚ���һ�γ���tmpsʱ��ԭʼ�ַ���������solution����strs[map[tmps]]������map[tmps]����Ϊ-1����ֹ�´��ٴ棩���ٽ����ַ������������solution��
*  5. �ظ�����1-4����ֱ������������
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



