/*
*    寻找最长回文子串
*   
* 思路：使用两个指针从两端向外扫描
*     
*    @date 2015/8/7
*
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;


string findPalindrome(string s,int left,int right)
{
	int n = s.size();
	int l = left;
	int r = right;

	while(left>=0&&right<=n-1&&s[left] == s[right])
	{
		left--;
		right++;
	}
	return s.substr(left+1,right-left-1);
}


/// 时间复杂度为O(n2)

string longestPalindrome(string s)
{
	int n = s.length();
	if(n==1) return "";

	string longest;

	string str;
	for(int i=0;i<n-1;i++)
	{   
		/// 奇偶讨论 aba或abba
		str= findPalindrome(s,i,i); /// 长度为偶数的候选回文字符串
		if(str.size()>longest.size())
			longest = str;
		str = findPalindrome(s,i,i+1);/// 长度为偶数的候选回文字符串
		if(str.size()>longest.size())
			longest = str;
	}

	return longest;
}

int main()
{
	string s= "abacdfdcaba";
	string str = longestPalindrome(s);
	return 0;
}




