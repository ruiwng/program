#include  <stdio.h>
#include  <math.h>

int main()
{
	int n;
	char ch[2];
	while(scanf("%d%s",&n,ch)!=EOF)
	{
			int t=sqrt((n+1)/2);
			for(int i=t;i>=1;--i)
			{
				for(int j=0;j<t-i;++j)
					printf(" ");
				int k=2*i-1;
				for(int j=0;j<k;++j)
					printf("%c",ch[0]);
				printf("\n");
			}
			for(int i=2;i<=t;++i)
			{
				for(int j=0;j<t-i;++j)
					printf(" ");
				int k=2*i-1;
				for(int j=0;j<k;++j)
					printf("%c",ch[0]);
				printf("\n");
			}
			printf("%d\n",n-(2*t*t-1));
	}
	return 0;
}