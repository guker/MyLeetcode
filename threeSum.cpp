/*
*    3 sum
* 
*    @date  2015/8/7
*
*/
#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;


vector<vector<int> > threeSum(vector<int> &num)
{
	vector<vector<int> > ret;
	ret.clear();
	/// 排序
	std::sort(num.begin(),num.end());
	for(int i = 0;i !=num.size();i++)
	{
		/// 去重
		if(i>0&&num[i] == num[i-1])
			continue;
		int j,k;
		j = i+1;
		k = num.size()-1;
		while(j<k)
		{
			/// 去重
			if(j>i+1&&num[j]==num[j-1])
			{
				j++;
				continue;
			}
			/// 去重
			if(k<num.size()-1&&num[k]==num[k+1])
			{
				k--;
				continue;
			}
			int sum = num[i] + num[j] + num[k];
			if(sum>0)
				k--;
			else if(sum<0)
				j++;
			else
			{
				vector<int>  tmp;
				tmp.push_back(num[i]);
				tmp.push_back(num[j]);
				tmp.push_back(num[k]);
				ret.push_back(tmp);
				j++;
			}
		}
	}
	return ret;
}

vector<vector<int> > threeSum(vector<int> &num,bool hasmap)
{
	vector<vector<int> > ret;
	ret.clear();
	/// 排序
	std::sort(num.begin(),num.end());
	for(int i= 0;i != num.size();i++)
	{
		//去重
		if (i != 0 && num[i] == num[i-1])  
                continue;  
		int j = i+1;
		map<int,int> mp;
		mp.clear();
		for(;j != num.size();j++)
		{
			if(!mp.count(num[j]))
			{
				//mp[num[i]] = i;
				mp.insert(std::pair<int,int>(num[j],j));
			}
			if(mp.count(-num[i]-num[j]))
			{
				int n = mp[-num[i]-num[j]];
				if(n<j)
				{
					vector<int> tmp;
					tmp.push_back(num[i]);
					tmp.push_back(-num[i]-num[j]);
					tmp.push_back(num[j]);
				
					ret.push_back(tmp);
				}
			}
		}
	}
	return ret;
	
}


int main()
{
	vector<vector<int>> ret;
	int num[] = {-1,0,1,2,-1,-4,-2};
	vector<int> vec(num,num+7);

	ret = threeSum(vec,true);

	return 0;
}