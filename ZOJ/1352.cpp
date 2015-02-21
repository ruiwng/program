#include  <stdio.h>
#include  <string.h>
#include  <string>
using namespace std;

void str_add(string& lhs,string rhs)
{
	if(lhs.length()<rhs.length())
		lhs.swap(rhs);
	int len1=lhs.length();
	int len2=rhs.length();
	rhs.insert(rhs.begin(),len1-len2,'0');
	int carry=0;
	for(int i=len1-1;i>=0;--i)
	{
		int temp=lhs[i]-'0'+rhs[i]-'0'+carry;
		if(temp>=10)
		{
			temp-=10;
			carry=1;
		}
		else
			carry=0;
		lhs[i]=temp+'0';
	}
	if(carry==1)
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
		int carry=0;
		string temp(lhs);
		for(int j=len1-1;j>=0;--j)
		{
			int t=(lhs[j]-'0')*(rhs[i]-'0')+carry;
			temp[j]=t%10+'0';
			carry=t/10;
		}
		if(carry!=0)
			temp.insert(temp.begin(),1,carry+'0');
		temp.append(len2-1-i,'0');
		str_add(result,temp);
	}
	lhs.swap(result);
}

int main()
{
	int lines_num;
	while(scanf("%d",&lines_num)!=EOF)
	{
		for(int i=0;i<lines_num;++i)
		{
			int input_base,output_base;
			char str[1000];
			scanf("%d%d%s",&input_base,&output_base,str);
			string decimal_num("0");
			char t[10];
			sprintf(t,"%d",input_base);
			char *p=str;
			while(*p!='\0')
			{
				int num;
				char temp[10];
				if(*p>='0'&&*p<='9')
					num=*p-'0';
				else if(*p>='A'&&*p<='Z')
					num=*p-'A'+10;
				else
					num=*p-'a'+36;
				++p;
				sprintf(temp,"%d",num);
				str_multi(decimal_num,t);
				str_add(decimal_num,temp);
			}

			string result;
			while(true)
			{
				int len=decimal_num.length();
				int remainder=0;
				string divider;
				for(int j=0;j<len;++j)
				{
					int t=remainder*10+decimal_num[j]-'0';
					int m=t/output_base;
					remainder=t%output_base;
					if(!(divider.empty()&&m==0))
					{
						if(m>=0&&m<=9)
							divider.push_back(m+'0');
						else if(m>=10&&m<=35)
							divider.push_back(m-10+'A');
						else
							divider.push_back(m-36+'a');
					}
				}
				if(remainder>=0&&remainder<=9)
					result.insert(result.begin(),1,remainder+'0');
				else if(remainder>=10&&remainder<=35)
					result.insert(result.begin(),1,remainder-10+'A');
				else
					result.insert(result.begin(),1,remainder-36+'a');
				if(divider.empty())
					break;
				else
					decimal_num.swap(divider);
			}
			if(result.empty())
				result.push_back('0');
			printf("%d %s\n%d %s\n\n",input_base,str,output_base,result.c_str());
		}
	}
	return 0;
}