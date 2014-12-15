#include  <stdio.h>

int main()
{
	unsigned int test;
	scanf("%u",&test);
	for(unsigned int i=1;i<=test;++i)
	{
		long long num1,num2,num3;
		scanf("%lld %lld %lld",&num1,&num2,&num3);
		printf("Case #%u: ",i);
		if(num1+num2>num3)
			printf("true\n");
		else
			printf("false\n");
	}
	return 0;
}