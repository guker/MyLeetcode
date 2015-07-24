///++++++++++++++++++++++++++++++++++++++++ 
///
/// 关键问题 overflow/underflow
///
///++++++++++++++++++++++++++++++++++++++++
#include<iostream>


class Solution
{
public:
	int reverse(int x)
	{
		const int max = 0x7fffffff; /// int最大值
		const int min = 0x80000000;/// int最小值
		long long sum = 0;

		while(x != 0)
		{
			int temp = x%10;
			sum = sum*10 + temp;
			if(sum >max || sum < min)
			{
				sum = sum>0?max:min;
				return 0;
			}
			x = x/10;
		}
		return sum;
	}
};

int main()
{
	int x = 214748365; 
	Solution sln;
	int y = sln.reverse(x);
	std::cout<<"x = "<<x<<",return "<<y<<std::endl;
	getchar();

}