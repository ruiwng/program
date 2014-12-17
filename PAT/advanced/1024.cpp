#include  <stdio.h>
#include  <string.h>
#include  <algorithm>
#include  <string>

using namespace std;

bool palind(string str)
{
	int n=str.length();
	for(int i=0;i<=n-i-1;i++)
	{
		if(str[i]!=str[n-i-1])
			return false;
	}
	return true;
}

string plus_s(string str1,string str2)
{
	unsigned int carry=0;
	string result(str1.size(),'0');
	for(int i=str1.size()-1;i>=0;i--)
	{
		int temp=str1[i]-'0'+str2[i]-'0'+carry;
		if(temp>=10)
		{
			temp-=10;
			carry=1;
		}
		else
			carry=0;
		result[i]=temp+'0';
	}
	if(carry==1)
		result.insert(result.begin(),'1');
	return result;
}

int main()
{
	
	char ch[80];
	unsigned int step;
	while(scanf("%s %u",ch,&step)!=EOF)
	{
		unsigned int i;
		string str=ch;
		for(i=0;i<step;i++)
		{
			if(palind(str))
				break;
			string str2=str;
			reverse(str2.begin(),str2.end());
			str=plus_s(str,str2);
		}
		printf("%s\n%u\n",str.c_str(),i);
	}
}