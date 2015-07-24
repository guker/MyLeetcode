#include<string>
#include<iostream>


class Solution
{
public:
	int lengthOfLongestSubstring(std::string s)
	{
		int len = s.length();
		int i = 0,j = 0;
		int maxlen = 0;
		bool exist[256] = {false};

		while(j < len)
		{
			if(exist[s[j]])
			{
				maxlen = (maxlen>(j-i))?maxlen:(j-i);
				while(s[i] != s[j])
				{
					exist[s[i]] = false;
					i++;
				}
				i++;
				j++;
			}else
			{
				exist[s[j]] = true;
				j++;
			}
		}
		maxlen = maxlen = (maxlen>(len-i))?maxlen:(len-i);
		return maxlen;
	}

};


int main()
{
	std::string str = "abcabcbb";
	Solution sln;
	int len = sln.lengthOfLongestSubstring(str);
	std::cout<< len <<std::endl;
	getchar();
	return true;
}