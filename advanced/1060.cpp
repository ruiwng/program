#include  <stdio.h>
#include  <string>
#include  <iostream>
using namespace std;

string change(string& s,unsigned int signi)
{
	int pos1=s.find('.');
	if(pos1==string::npos)
		pos1=s.size();
	int pos2=s.find_first_not_of("0.");
	string result("0.");
	if(pos2==string::npos)
	{
		result.append(signi,'0');
		result+="*10^0";
		return result;
	}
	for(unsigned int i=pos2;i<s.size();i++)
	{
		if(s[i]=='.')
			continue;
		result.push_back(s[i]);
		if(result.size()>=signi+2)
			break;
	}
	if(result.size()<signi+2)
	  result.append(signi+2-result.size(),'0');
	result+="*10^";
	char ch[30];
	if(pos1+1<=pos2)
	{
		if(pos1+1!=pos2)
		  result+="-";
		sprintf(ch,"%u",pos2-pos1-1);
		result+=ch;
	}
	else
	{
		sprintf(ch,"%u",pos1-pos2);
		result+=ch;
	}
	return result;
}
int main()
{
	unsigned int signi_digits;
	string str1,str2;
	while(cin>>signi_digits>>str1>>str2)
	{
		string str_change1=change(str1,signi_digits),
			str_change2=change(str2,signi_digits);
		if(str_change1==str_change2)
			printf("YES %s\n",str_change1.c_str());
		else
			printf("NO %s %s\n",str_change1.c_str(),str_change2.c_str());
	}
	return 0;
}