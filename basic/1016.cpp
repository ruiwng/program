#include  <stdio.h>
#include  <string.h>

int main()
{
	char ch[2][20];
	char ch1[2];
	while(scanf("%s %c %s %c",ch[0],&ch1[0],ch[1],&ch1[1])!=EOF)
	{
		int n1=0,n2=0;
		char* p=ch[0];
		while((p=strchr(p,ch1[0])))
		{
			p++;
			n1=10*n1+ch1[0]-'0';
		}
		p=ch[1];
		while((p=strchr(p,ch1[1])))
		{
			p++;
			n2=10*n2+ch1[1]-'0';
		}
		printf("%d\n",n1+n2);
	}
	return 0;
}