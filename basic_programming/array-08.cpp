#include  <string>
#include  <iostream>
using namespace std;

int main()
{
	string str;
	getline(std::cin,str);
	bool first=true;
	long int sum=0;
	bool negative=false;
	for(unsigned int i=0;i<str.length();++i)
	{
		if(first&&str[i]=='-')
		{
		  negative=true;
		  first=false;
		}
		else if(str[i]>='0'&&str[i]<='9')
		{
			sum=sum*16+str[i]-'0';
			first=false;
		}
		else if(str[i]>='a'&&str[i]<='f')
		{
			sum=sum*16+str[i]-'a'+10;
			first=false;
		}
		else if(str[i]>='A'&&str[i]<='F')
		{
			sum=sum*16+str[i]-'A'+10;
			first=false;
		}
		else if(str[i]=='#')
			break;
	}
	if(negative&&sum!=0)
		printf("-");
	printf("%ld\n",sum);
	return 0;
}