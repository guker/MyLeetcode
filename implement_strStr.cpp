/*
*    implement strStr
* 
*    @date  2015/8/9
*
*/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;


char* strStr(char*haystack,char* needle)
{
	int haylen = strlen(haystack);
	int needlen = strlen(needle);

	for(int i = 0;i<=haylen-needlen;i++)
	{
		char* p = haystack+i;
		char* q = needle;
		while(*q != '\0')
		{
			if(*p != *q)
				break;
			else
			{
				p++;q++;
			}
		}

		if(*q == '\0')
			return haystack+i;
	}
	return NULL;
}


int main()
{
	const char* haystack = "mississippi";
	const char* needle = "issi";
	printf("%s, %s : %s\n", haystack, needle, strStr((char*)haystack, (char*)needle));
}