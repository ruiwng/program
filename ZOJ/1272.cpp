#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

void decrease_number(string& s)// decrease the number by one
{
	int pos=s.length()-1;
	while(pos>=0)
	{
		if(s[pos]!='0')
		{
			--s[pos];
			break;
		}
		s[pos]='9';
		--pos;
	}
}
void str_add(string& lhs,string rhs)// addition operation
{
	int len1=lhs.length();
	int len2=rhs.length();
	if(len1<len2)
	{
		lhs.swap(rhs);
		len1=lhs.length();
		len2=rhs.length();
	}
	rhs.insert(rhs.begin(),len1-len2,'0');
	int carry=0;
	for(int i=len1-1;i>=0;--i)
	{
		int temp=carry+lhs[i]-'0'+rhs[i]-'0';
		if(temp>=10)
		{
			carry=1;
			temp-=10;
		}
		else
			carry=0;
		lhs[i]=temp+'0';
	}
	if(carry!=0)
		lhs.insert(lhs.begin(),1,'1');
}

void str_multi(string& lhs,string rhs)
{
	if(lhs=="0"||rhs=="0")
		return;
	int len1=lhs.length();
	int len2=rhs.length();
	string result("0");
	for(int i=len2-1;i>=0;--i)
	{
		string temp(lhs);
		int carry=0;
		for(int j=len1-1;j>=0;--j)
		{
			int t=(rhs[i]-'0')*(lhs[j]-'0')+carry;
			if(t>=10)
			{
				carry=t/10;
				t%=10;
			}
			else
				carry=0;
			temp[j]=t+'0';
		}
		if(carry!=0)
			temp.insert(temp.begin(),1,carry+'0');
		temp.append(len2-1-i,'0');
		str_add(result,temp);
	}
	lhs=result;
}


int str_divide(string& s)// division operation
{
	int len=s.length();
	int remainder=0;
	string result;
	for(int i=0;i<len;++i)
	{
		remainder=(remainder*10)+s[i]-'0';
		int temp=remainder/26;
		if(!(result.empty()&&temp==0))
			result.push_back('0'+temp);
		remainder%=26;
	}
	s=result;
	if(s.empty())
		s.push_back('0');
	return remainder;
}

string number_to_string(string s)//convert number to corresponding string
{
	string result;
	int len=s.length();
	while(s!="0")
	{
		decrease_number(s);
		int remainder=str_divide(s);
		result.insert(result.begin(),1,remainder+'a');
	}
	return result;
}

string string_to_number(string s)//convert string to corresponding number
{
	int len=s.length();
	string result("0");
	for(int i=0;i<len;++i)
	{
		str_multi(result,"26");
		char temp[5];
		sprintf(temp,"%d",s[i]-'a'+1);
		str_add(result,temp);
	}
	return result;
}

string number_format(const string& s)
{
	int len=s.length();
	int t=len%3;
	if(t==0)
		t=3;
	string result=s.substr(0,t);
	while(t<len)
	{
		result.push_back(',');
		result+=s.substr(t,3);
		t+=3;
	}
	return result;
}

int main()
{
	string str;
	while(cin>>str)
	{
		if(str[0]=='*')
			break;
		else if(str[0]>='0'&&str[0]<='9')
		{
			string word=number_to_string(str);
			printf("%-22s%s\n",word.c_str(),number_format(str).c_str());
		}
		else
		{
			string number=string_to_number(str);
			printf("%-22s%s\n",str.c_str(),number_format(number).c_str());
		}
	}
	return 0;
}