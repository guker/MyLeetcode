/*
*    Ѱ��������Ӵ�
*   
* ˼·��ʹ������ָ�����������ɨ��
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


/// ʱ�临�Ӷ�ΪO(n2)

string longestPalindrome(string s)
{
	int n = s.length();
	if(n==1) return "";

	string longest;

	string str;
	for(int i=0;i<n-1;i++)
	{   
		/// ��ż���� aba��abba
		str= findPalindrome(s,i,i); /// ����Ϊż���ĺ�ѡ�����ַ���
		if(str.size()>longest.size())
			longest = str;
		str = findPalindrome(s,i,i+1);/// ����Ϊż���ĺ�ѡ�����ַ���
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




