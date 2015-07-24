#include <string>
#include <iostream>

using namespace std;

class solution
{
public:
	int myAtoi(string str)
	{
		if(&str[0] == NULL)
			return 0;
		// ignore prefix blank
		int i = 0;
		while( str[i] != '\0' && str[i] == ' ')
			++i;

		
		if(str[i] == '\0')
			return 0;

		int max = 0x7fffffff;
		int min = 0x80000000;
		int signal = 1;
		int len = str.length();

		/// +,-
		if(str[i] == '+')
		{
			signal = 1;
			++i;
		}
		else if(str[i] == '-')
		{
			signal = -1;
			++i;
		}

		long long sum = 0;
		while(str[i] != '\0')
		{
			if(str[i] >= '0' && str[i] <= '9')
				sum = sum*10 + signal*(str[i]-'0');
			else
				return sum;
			if(sum > max || sum < min)
			{
				return sum>0?max:min;
			}
			++i;
		
			if(i == len) /// out of range
				break;
		
		}
		return sum;
	}
};

int main()
{
	string str = "-123";
	solution sln;
	int res = sln.myAtoi(str);
	std::cout << "str = "<< str << " res = "<< res<<std::endl;
	getchar();
}