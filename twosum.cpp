#include <iostream>
#include <vector>
#include <map>


class Solution
{
public:
	std::vector<int> twosum(std::vector<int>& nums, int target)
	{
		std::vector<int> results;
		std::map<int,int> mp;
		int len = nums.size();
		for(int i = 0; i < len; ++i)
		{
			if(!mp.count(nums[i])) // count()函数返回map中匹配的个数，否则返回zero
			{
				mp.insert(std::pair<int,int>(nums[i],i));
			}
			if(mp.count(target - nums[i]))
			{
				int n = mp[target - nums[i]];
				if(n < i)
				{
					results.push_back(n+1);
					results.push_back(i+1);
					return results;
				}
			}

		}
		return results;
		

	}
};

int main()
{
	int num[5] = {2,7,2,11,18};
	int target = 9;
	std::vector<int> nums(num,num+5);
	Solution sln;
	std::vector<int> results;

	results = sln.twosum(nums,target);
    int len = results.size();
	for(int i = 0; i < len; ++i)
	{
		std::cout<<results[i]<<std::endl;
	}
	return true;
}