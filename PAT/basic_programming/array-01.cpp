#include  <stdio.h>
#include  <string.h>
#include  <string>
using namespace std;

int main()
{
	char str[100];
	while(scanf("%s",str)!=EOF)
	{
		int len=strlen(str);
		string char_array;
		for(int i=0;i<len;++i)
		{
			if(str[i]>='0'&&str[i]<='9')
					char_array.push_back(str[i]);
		}
		while(!char_array.empty()&&char_array.front()=='0')
			char_array.erase(char_array.begin());
		if(char_array.empty())
			printf("0");
		else
		    printf("%s",char_array.c_str());
	}
	return 0;
}