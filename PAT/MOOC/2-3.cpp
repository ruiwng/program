#include  <stdio.h>
#include  <string.h>

int main()
{
	char str[4];
	while(scanf("%s",str)!=EOF)
	{
		unsigned int str_len=strlen(str);
		int tag=0;
		for(unsigned int i=0;i<str_len;++i)
		{
			if(tag==0&&str[str_len-i-1]=='0')
			 continue;
			printf("%c",str[str_len-i-1]);
			tag=1;
		}
		printf("\n");
	}
	return 0;
}