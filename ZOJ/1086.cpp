#include  <stdio.h>
#include  <string.h>
#include  <string>
using namespace std;

string string_add(string lhs,string rhs)
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
	string result(lhs);
	rhs.insert(rhs.begin(),length1-length2,'0');
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
	return result;
}

string fraction_add(string lhs,string rhs)
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
	rhs.erase(rhs.begin(),rhs.begin()+2);
	lhs.erase(lhs.begin(),lhs.begin()+2);
	rhs.append(length1-length2,'0');
	string result=string_add(lhs,rhs);
	result.insert(0,string("0."));
	while(*(result.end()-1)=='0')
		result.erase(result.end()-1);
	return result;
}

string fraction_multi(string lhs,string rhs)
{
	if(lhs=="0"||rhs=="0")
		return string("0.0");
	int number=0;
	if(lhs.size()>=2)
	{
		number+=lhs.size()-2;
		lhs.erase(lhs.begin(),lhs.begin()+2);
		while(lhs[0]=='0')
			lhs.erase(lhs.begin());
	}
	if(rhs.size()>=2)
	{
		number+=rhs.size()-2;
		rhs.erase(rhs.begin(),rhs.begin()+2);
		while(rhs[0]=='0')
			rhs.erase(rhs.begin());
	}
	int length1=lhs.size();
	int length2=rhs.size();
	string result("0");
	for(int i=length1-1;i>=0;--i)
	{
		string temp(rhs);
		int carry=0;
		for(int j=length2-1;j>=0;--j)
		{
			int t=(rhs[j]-'0')*(lhs[i]-'0')+carry;
			carry=t/10;
			t=t%10;
			temp[j]=t+'0';
		}
		if(carry!=0)
			temp.insert(temp.begin(),carry+'0');
		temp.append(length1-1-i,'0');
		result=string_add(result,temp);
	}
	int length=result.size();
	result.insert(result.begin(),number-length,'0');
	result.insert(0,string("0."));
	return result;
}

int main()
{
	char str[10000];
	while(scanf("%s",str)!=EOF)
	{
		if(str[1]=='\0')
		   printf("%s [8] = %s [10]\n",str,str);
		else
		{
			string result("0.0");
			char *p=strchr(str,'.');
			++p;
			string radix("0.125");
			while(*p!='\0')
			{
				char s[5];
				sprintf(s,"%d",*p-'0');
				string temp=fraction_multi(s,radix);
				radix=fraction_multi(radix,"0.125");
				result=fraction_add(result,temp);
				++p;
			}
			while(!result.empty()&&*(result.end()-1)=='0')
				result.erase(result.end()-1);
			printf("%s [8] = %s [10]\n",str,result.c_str());
		}	
	}
	return 0;
}