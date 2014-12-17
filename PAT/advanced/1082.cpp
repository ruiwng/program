#include  <stdio.h>
#include  <string.h>
#include  <string>
#include  <vector>
using namespace std;

bool first=true;
char number[10][5]=
{
	"ling",
	"yi",
	"er",
	"san",
	"si",
	"wu",
	"liu",
	"qi",
	"ba",
	"jiu"
};

char array[5][6]= {"0","Shi","Bai","Qian","Wan"};

void func(vector<string>& str_temp,char* s,unsigned int len,bool high)
{
	for(unsigned int i=len-1,j=0;j<len;--i,j++)
	{
		int temp=s[j]-'0';
		{
			if(temp==0&&!str_temp.empty()&&str_temp.back()=="ling")
				continue;
		    str_temp.push_back(number[temp]);
		}
		if(temp!=0&&j!=len-1)
			str_temp.push_back(array[i]);
	}
	while(!str_temp.empty()&&str_temp.back()=="ling")
		str_temp.pop_back();
	if(high==true&&!str_temp.empty())
		str_temp.push_back("Wan");
}
int main()
{
	char str[10];
	while(scanf("%s",str)!=EOF)
	{
		bool first=true;
		char* temp=str;
		if(str[0]=='-')
		{
			printf("Fu");
			first=false;
			++temp;
		}
		unsigned int length=strlen(temp);
		if(length==9)
		{
			if(first)
				first=false;
			else
				printf(" ");
			printf("%s Yi",number[temp[0]-'0']);
			temp++;
		}
		length=strlen(temp);
		vector<string> str1,str2;
		if(length>4)
		{
			func(str1,temp,length-4,true);
			func(str2,temp+length-4,4,false);
			if(!str2.empty()&&str1.empty()&&str2[0]!="ling")
				str1.push_back("ling");
			for(unsigned int i=0;i<str1.size();++i)
			{
				if(first)
					first=false;
				else
					printf(" ");
				printf("%s",str1[i].c_str());
			}
			for(unsigned int i=0;i<str2.size();++i)
			{
				if(first)
					first=false;
				else
					printf(" ");
				printf("%s",str2[i].c_str());
			}
		}
		else
		{
			func(str2,temp,length,false);
			if(str2.empty())
				str2.push_back("ling");
			for(unsigned int i=0;i<str2.size();++i)
			{
				if(first)
					first=false;
				else
					printf(" ");
				printf("%s",str2[i].c_str());
			}
		}
		printf("\n");
	}
	return 0;
}