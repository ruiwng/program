#include  <stdio.h>
#include  <string.h>

int main()
{
	char s[4];
	while(scanf("%s",s)!=EOF)
	{
		int n=strlen(s);
		char* p=s;
		int num;
		if(n==3)
		{
			num=*p-'0';
			for(int i=0;i<num;++i)
				printf("B");
			p++;
		}
		if(n>=2)
		{
			num=*p-'0';
			for(int i=0;i<num;++i)
				printf("S");
			p++;
		}
		if(n>=1)
		{
			num=*p-'0';
			for(int i=1;i<=num;++i)
				printf("%d",i);
		}
		printf("\n");
	}
	return 0;
}
