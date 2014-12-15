#include  <stdio.h>
#include  <string.h>

int main()
{
	char ch[81];
	while(scanf("%s",ch)!=EOF)
	{
		int len=strlen(ch);
		int x=(len-1)/3;
		int y=len-2*x;
		for(int i=0;i<x;i++)
		{
			printf("%c",ch[i]);
			for(int j=0;j<y-2;j++)
			  printf(" ");
			printf("%c\n",ch[len-i-1]);
		}
		for(int i=x;i<len-x;i++)
			printf("%c",ch[i]);
		printf("\n");
	}
	return 0;
}