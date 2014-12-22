#include  <iostream>
#include  <string>
#include  <string.h>
#include  <stdio.h>
using namespace std;

string str_add(string lhs,string rhs)
{
	int length1=lhs.size();
	int length2=rhs.size();
	if(length1<length2)
	{
		lhs.swap(rhs);
		int temp=length1;
		length1=length2;
		length2=temp;
	}
	rhs.insert(rhs.begin(),length1-length2,'0');
	string result(length1,'0');
	int carry=0;
	for(int i=length1-1;i>=0;--i)
	{
		int temp=lhs[i]-'0'+rhs[i]-'0'+carry;
		if(temp>=10)
		{
			temp-=10;
			carry=1;
		}
		else
			carry=0;
		result[i]=temp+'0';
	}
	if(carry!=0)
		result.insert(result.begin(),'1');
	return result;
}

string str_multi(string lhs,string rhs)
{
	while(!lhs.empty()&&*lhs.begin()=='0')
		lhs.erase(lhs.begin());
	while(!rhs.empty()&&*rhs.begin()=='0')
		rhs.erase(rhs.begin());
	int length1=lhs.size();
	int length2=rhs.size();
	string result("0");
	for(int i=length1-1;i>=0;--i)
	{
		int carry=0;
		string t(length2,'0');
		for(int j=length2-1;j>=0;--j)
		{
			int temp=(lhs[i]-'0')*(rhs[j]-'0')+carry;
			carry=temp/10;
			temp%=10;
			t[j]=temp+'0';
		}
		if(carry!=0)
			t.insert(t.begin(),carry+'0');
		t.append(length1-1-i,'0');
		result=str_add(result,t);
	}
	return result;
}

int main()
{
	string str;
	while(cin>>str)
	{
		int length=str.size();
		int hash[10];
		memset(hash,0,sizeof(hash));
		for(int i=0;i<length;++i)
			++hash[str[i]-'0'];
		bool error=false;
		for(int i=2;i<=length;++i)
		{
			char temp[5];
			sprintf(temp,"%d",i);
			string result=str_multi(str,temp);
			int hash_temp[10];
			memcpy(hash_temp,hash,sizeof(hash));
			int length_temp=result.size();
			if(length_temp<=length)
				result.insert(result.begin(),length-length_temp,'0');
			else
			{
				error=true;
				break;
			}
			for(int j=0;j<length;++j)
				--hash_temp[result[j]-'0'];
			for(int j=0;j<10;++j)
				if(hash_temp[j]!=0)
				{
					error=true;
					break;
				}
			if(error)
				break;
		}
		printf("%s is %scyclic\n",str.c_str(),error?"not ":"");
	}
	return 0;
}