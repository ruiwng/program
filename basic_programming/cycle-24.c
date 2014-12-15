#include  <stdio.h>

int main()
{
	unsigned int n;
	while(scanf("%u",&n)!=EOF)
	{
		unsigned int sum=0;
		unsigned int temp=1;
		for(unsigned int i=1;i<=n;++i)
		{
			temp*=i;
			sum+=temp;
		}
		printf("%u\n",sum);
	}
	return 0;
}
