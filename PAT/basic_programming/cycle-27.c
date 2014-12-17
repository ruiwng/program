#include  <stdio.h>

int main()
{
	unsigned int n;
	while(scanf("%u",&n)!=EOF)
	{
		double sum=0.0;
		for(unsigned int i=1;i<=n;++i)
			sum+=1/(double)(i);
		printf("sum = %.6lf\n",sum);
	}
	return 0;
}
