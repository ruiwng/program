#include  <stdio.h>

int main()
{
	unsigned int n;
	while(scanf("%u",&n)!=EOF)
	{
		unsigned int sum=0;
		unsigned int temp=1;
		for(int i=1;i<=n;++i)
		{
			temp<<=1;
			sum+=temp;
		}
		printf("sum = %u\n",sum);
	}
	return 0;
}
