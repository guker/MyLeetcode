#include<stdio.h>
#include<string>
#include<iostream>


using namespace std;

bool ismatch(const char* s, const char* p)
{
	if(s == NULL || p == NULL)
		return false;
	if(*p == '\0')
		return *s == '\0';

	if(*(p+1) == '\0'|| *(p+1) != '*')
	{
		if(*s == '\0' || (*p != '.' && *s != *p))
			return false;
		return ismatch(s+1,p+1);
	}
	int len = strlen(s);
	int i = -1;
	while(i<len && (i<0 || *p == '.' || *p == *(s+i)))
	{
		if(ismatch(s+i+1,p+2))
			return true;
		i++;
	}

	return false;
}


int main()
{
	const char* s= "abc";
	const char* p = "a.*";
    bool ok = ismatch(s,p);
	return 0;
}
