/*
*    Substring with Concatenation of All Words
* 
*    @date  2015/8/9
*
*/
/*  
*思路：维护一个字典，保证目前的串包含字典里面的单词有且仅有一次
*        维护一个窗口，滑动窗口比对  
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
	/// 字典
	map<string,int> words;
	/// 统计窗口里面的词
	map<string,int> cur;

	int wordNum = L.size();
	for(int i=0;i<wordNum;i++)
		words[L[i]]++;

	int wordLen = L[0].size();
	
	/// 窗口一个一个字符的滑动
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
