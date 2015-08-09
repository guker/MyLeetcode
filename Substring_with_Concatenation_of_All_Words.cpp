/*
*    Substring with Concatenation of All Words
* 
*    @date  2015/8/9
*
*/
/*  
*˼·��ά��һ���ֵ䣬��֤Ŀǰ�Ĵ������ֵ�����ĵ������ҽ���һ��
*        ά��һ�����ڣ��������ڱȶ�  
*

*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>

using namespace std;


vector<int> findSubstring(string S, vector<string>& L )
{
	vector<int> res;
	if(S.size()== 0 ||L.size()==0)
		return res;
	/// �ֵ�
	map<string,int> words;
	/// ͳ�ƴ�������Ĵ�
	map<string,int> cur;

	int wordNum = L.size();
	for(int i=0;i<wordNum;i++)
		words[L[i]]++;

	int wordLen = L[0].size();
	
	/// ����һ��һ���ַ��Ļ���
	for(int i = 0;i <= S.size()-wordLen*wordNum;i++)
	{
		cur.clear();
		int j;
		for(j = 0;j<wordNum;j++)
		{
			string word = S.substr(i+j*wordLen,wordLen);
			if(words.find(word) == words.end())
				break;
			cur[word]++;
			if(cur[word]>words[word])
				break;
		}
		if(j == wordNum)
			res.push_back(i);
	}

	return res;
}

int main()
{
	string S = "barfoothefoobarman";
	vector<string> str;
	str.push_back("bar");
	str.push_back("foo");
	
	vector<int> index = findSubstring(S,str);

	return 0;
}
