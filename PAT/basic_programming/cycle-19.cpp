#include  <stdio.h>
#include  <string.h>
#include  <string>
using namespace std;
char array[5]= {'0','S','B','Q','W'};

void func(string& str_temp,char* s,unsigned int len,bool high)
{
	for(unsigned int i=len-1,j=0;j<len;--i,j++)
	{
		char temp=s[j]-'0'+'a';
		{
			if(temp=='a'&&!str_temp.empty()&&str_temp.back()=='a')
				continue;
		    str_temp.push_back(temp);
		}
		if(temp!='a'&&j!=len-1)
			str_temp.push_back(array[i]);
	}
	while(!str_temp.empty()&&str_temp.back()=='a')
		str_temp.pop_back();
	if(high==true&&!str_temp.empty())
		str_temp.push_back('W');
}
int main()
{
	char str[10];
	while(scanf("%s",str)!=EOF)
	{
		unsigned int length=strlen(str);
		char* temp=str;
		if(length==9)
		{
			printf("%cY",temp[0]-'0'+'a');
			temp++;
		}
		length=strlen(temp);
		string str1,str2;
		if(length>4)
		{
			func(str1,temp,length-4,true);
			func(str2,temp+length-4,4,false);
			if(!str2.empty()&&str1.empty()&&str[0]!='a')
				str1.push_back('a');
			printf("%s%s",str1.c_str(),str2.c_str());
		}
		else
		{
			func(str2,temp,length,false);
			if(str2.empty())
				str2.push_back('a');
			printf("%s",str2.c_str());
		}
		printf("\n");
	}
	return 0;
}