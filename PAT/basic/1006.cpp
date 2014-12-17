#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main()
{
	char s[4];
	while(scanf("%s",s)!=EOF)
	{
		int n=strlen(s);
		char* p=s;
		if(n==3)
		{
			for(int i=0;i<(p[0]-'0');i++)
				printf("B");
			p++;
		}
		if(n>=2)
		{
			for(int i=0;i<(p[0]-'0');i++)
				printf("S");
			p++;
		}
		if(n>=1)
		{
			for(int i=1;i<=(p[0]-'0');i++)
				printf("%d",i);
		}
		printf("\n");
	}
	return 0;
}