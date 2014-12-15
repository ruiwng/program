#include  <stdio.h>

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		double sum=0.0;
		for(unsigned int i=1;i<=num;++i)
		{
			if(i%2==1)
				sum+=(double)i/(2*i-1);
			else
				sum-=(double)i/(2*i-1);
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}