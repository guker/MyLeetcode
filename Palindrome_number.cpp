/*
*    ������ 12321
*    
*  �� int ��ת������ԭ���ıȽ�
*
*
*    @date 2015/8/7
*
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

bool isPalindrome(int x)
{
	if(x < 0) return false;

	long long target = x; /// ����Ϊlong long����ֹ���
	if(target < 0) target = -target;

	long long reverse = 0;
	long long curNum = target;

	while(curNum != 0)
	{
		reverse = 10*reverse + curNum%10;
		curNum /= 10;
	}

	return reverse == target;

}


int main(int argc, char**argv)
{
	int x = 12321;
	bool test = isPalindrome(x);


	return 0;



}


