#include  <stdio.h>

int main()
{
	char str[100010];
	while(scanf("%s",str)!=EOF)
	{
		char *p=str;
		long long P_count=0,PA_count=0,PAT_count=0;
		while(*p!='\0')
		{
			if(*p=='P')
				++P_count;
			else if(*p=='A')
			{
				PA_count+=P_count;
				if(PA_count>=1000000007)
					PA_count-=1000000007;
			}
			else
			{
				PAT_count+=PA_count;
				if(PAT_count>=1000000007)
					PAT_count-=1000000007;
			}
			++p;
		}
		printf("%lld\n",PAT_count);
	}
	return 0;
}
