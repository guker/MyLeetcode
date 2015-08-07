/*
*    longest common prefix
* 
*    @date  2015/8/7
*
*/
#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

/// �����ǰ׺
string longestCommonPrefix(vector<string> &strs)
{
	if(strs.size()<= 0) return "";

	string word;
	for(int i=1;i<strs[0].size();i++)
	{
		string w = strs[0].substr(0,i);
		bool match = true;
		int j = 1;
		for(;j<strs.size();j++)
		{
			// ���жϳ��ȣ�����ȡ�Ӵ����������Խ��
			if(i>strs[j].size() || w != strs[j].substr(0,i)) 
			{
				match = false;
				break;
			}
		}

		if(!match)
			return word;
		word = w;	
	}
	return word;

}


int main()
{
	vector<string> vestr;
	string str= "abcdhiwei";
	vestr.push_back(str);
	str = "abcdwhu";
	vestr.push_back(str);
	str = longestCommonPrefix(vestr);
	return 0;
}
