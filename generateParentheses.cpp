/********************************************************************************** 
* 
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
* 
* For example, given n = 3, a solution set is:
* 
* "((()))", "(()())", "(())()", "()(())", "()()()"
* 
*  @date 2015-08-14             
**********************************************************************************/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include<string>
using namespace std;


void generator(vector<string>& result, int left, int right, string s);
vector<string> generateParenthesis(int n) {
    
    vector<string> result;
    string s;
    generator(result, n, n, s);
    return result;
}

/// 递归思路 清晰明了
/// left代表左括号的个数
/// right代表右括号的个数
void generator(vector<string>& result, int left, int right, string s){
    if (left==0 && right==0){
        result.push_back(s);
        return;
    }
	//左括弧的个数有剩余，则往字符串中添加一个左括弧
   // 需要再定义一个字符串变量，否则会影响后续程序
   // 再递归时，左括弧个数减一，此处不要改变n0的值，否则影响后续程序
    if (left>0){
        generator(result, left-1, right, s +'(');
    }
	 //右括弧的个数有剩余，且右括弧剩余的数量多于左括弧
     //即当前字符串中左括弧多于右括弧，才将右括弧加入到字符串中
    if (right>0 && right>left){
        generator(result, left, right-1, s+')');
    }
}
    
void printResult(vector<string>& result)
{
    for(int i=0; i<result.size(); i++){
        cout<<result[i] <<endl;
    }
}

int main(int argc, char** argv) 
{
    int n=3;
    if (argc>1){
        n = atoi(argv[1]);
    }
    vector<string> r = generateParenthesis(n);
    printResult(r);
    return 0;
}
