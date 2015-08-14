/********************************************************************************** 
* 
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
* determine if the input string is valid.
* 
* The brackets must close in the correct order, "()" and "()[]{}" are all valid 
* but "(]" and "([)]" are not.
* 
*               
**********************************************************************************/

/*
*                           使用栈实现
*  做一个空栈，读入字符，如果字符是一个开放符号（即（，{，[）,则入栈
*  如果为封闭字符（即），}，]）,当栈为空时return false，否则将栈元素弹出
*  如果弹出的字符不是对应的开放字符，则return false
*
*/

#include<iostream>
#include<stack>
#include<string>

using namespace std;

/// 使用栈来保存前括号，然后有后括号来时弹出栈顶来判断

bool isValid(string s)
{
	stack<char> st;
	for(int i =0; i < s.size();i++)
	{
		if(s[i] == ')' || s[i] == '}'||s[i] == ']')
		{
			if(st.empty())
				return false;
			else
			{
				char c = st.top();
				st.pop();
				if((c == '('&&s[i] != ')') || (c == '['&& s[i] != ']')||(c == '{' && s[i] != '}'))
					return false;
			}
		}
		else
			st.push(s[i]);
	}
	return st.empty();
}

bool isValid1(string s)
{
	
    string stack;

    while(s.size()>0){

        char lch = s.back();

        if (lch == '[' || lch=='{' || lch=='(') {
            if (s.size()<=0) return false;
            char rch = stack.back();
            if ((lch=='[' && rch ==']') ||
                    (lch=='{' && rch =='}') ||
                    (lch=='(' && rch ==')') ) {
                s.pop_back();
                stack.pop_back();
            }else{
                return false;
            }
        } else if (lch== ']' || lch=='}' || lch==')' ) {
            s.pop_back();
            stack.push_back(lch);
        } else {
            //skip the other charactors
            s.pop_back();
        }
    }
    return (s.size()==0 && stack.size()==0 );
}

int main(int argc, char**argv)
{
    string s = "{{}{[]()}}";
    if (argc>1){
        s = argv[1];
    }
    cout << "str = \"" << (s) << "\"" << endl;
    cout << isValid1(s) << endl;
}
