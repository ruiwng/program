#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main()
{
	char ch[1010];
	int n;
	while(scanf("%s %d",ch,&n)!=EOF)
	{
		int len=strlen(ch);
		int m=0;
		for(int i=0;i<len;i++)
		{
			int x=m*10+ch[i]-'0';
			int y=x/n;
			m=x%n;
			if(i==0&&y==0&&len>1)
			  continue;
			printf("%d",y);
		}
		printf(" %d\n",m);
	}
	return 0;
}