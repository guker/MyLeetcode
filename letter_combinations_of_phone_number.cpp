/*
*    letter combination of phone numbers
* 
*    @date  2015/8/8
*
*/
#include<string>
#include<vector>


using namespace std;

char  phone[10][4]={ {' ',  '\0', '\0', '\0' }, //0
                     {'\0', '\0', '\0', '\0' }, //1
                     {'a',  'b',  'c',  '\0' }, //2
                     {'d',  'e',  'f',  '\0' }, //3
                     {'g',  'h',  'i',  '\0' }, //4
                     {'j',  'k',  'l',  '\0' }, //5
                     {'m',  'n',  'o',  '\0' }, //6
                     {'p',  'q',  'r',  's'  }, //7
                     {'t',  'u',  'v',  '\0' }, //8
                     {'w',  'x',  'y',  'z'  }  //9
                   };

vector<string>  letterCombinations(const string& digits)
{
      vector<string>  result;
	  if(digits.size() == 0)
	  {
		  result.push_back("");
		  return result;
	  }

	  for(int i=0;i<digits.size();i++)
	  {
		  /// 遇到非法输入
		  if(!isdigit(digits[i]))
		  {
			  vector<string> r;
			  return r;
		  }
		  int d = digits[i] - '0';

		  if(result.size() == 0)
		  {
			  for(int j = 0;j<4&&phone[d][j] != '\0';j++)
			  {
				  string s;
				  s += phone[d][j];
				  result.push_back(s);
			  }
			  continue;
		  }

		  vector<string> r;
		  for(int i = 0; i<result.size();i++)
		  {
			  for(int j = 0; j<4 && phone[d][j] != '\0';j++)
			  {
				  string s = result[i] + phone[d][j];
				  r.push_back(s);
			  }
		  }

		  result = r;
	  }
	  return result;

}


int main()
{

    string digit = "234";

	vector<string> result = letterCombinations(digit);

    return 0;
}