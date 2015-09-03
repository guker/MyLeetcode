/********************************************************************************** 
 * 
 * Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters. 
 * 
 * The input string does not contain leading or trailing spaces and the words are always separated by a single space. 
 * 
 * For example,
 *  Given s = "the sky is blue",
 *  return "blue is sky the". 
 * 
 * Could you do it in-place without allocating extra space? 
 * 
 *  @author hqwsky
 *  @date  2015-9-3
 *
 *  @solution: (X^tY^t)^t = YX (^t rep  reverse)
 * 
 **********************************************************************************/
#include<stdio.h>
#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;


void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}
void reverse(string &s, int begin, int end) 
{
    while(begin < end) 
	{
        swap(s[begin++], s[end--]);
    }
}
void reverseWords(string &s)
{

    if (s.size()<=1) return;

    // reverse the whole string
    reverse(s, 0, s.size()-1);

    // reverse the each word
	int begin=0, i=0;
    for (; i<s.size(); i++ ) 
	{
        if (s[i] == ' '|| s[i] == '\0' ) 
		{
            reverse(s, begin, i-1);
            begin = i+1;
        }
    }
	/// reverse the last word
	reverse(s,begin,s.size()-1);
}


int main(int argc, char** argv)
{
    string s = "the sky is blue";
    if ( argc > 1 ) 
	{
        s = argv[1];
    }
    
    cout << s << endl;
    reverseWords(s);
    cout << s << endl;
    
}