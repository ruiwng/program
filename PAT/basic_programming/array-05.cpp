#include  <iostream>
#include  <string>
#include  <ctype.h>
using namespace std;
int main()
{
	string str;
	while(getline(std::cin,str)!=0)
	{
		size_t len=str.length();
		for(size_t i=0;i<len;++i)
		{
			if(str[i]=='#')
				break;
			if(isupper(str[i]))
				str[i]=tolower(str[i]);
			else if(islower(str[i]))
				str[i]=toupper(str[i]);
			printf("%c",str[i]);
		}
		printf("\n");
	}
	return 0;
}