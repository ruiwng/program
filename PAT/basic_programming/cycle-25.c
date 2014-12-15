#include  <stdio.h>

int main()
{
	unsigned int n;
	while(scanf("%u",&n)!=EOF)
	{
		double sum=0.0;
		double temp=-1;
		for(int i=1;i<=n;++i)
		{
			temp+=2;
			sum+=1/temp;
		}
		printf("sum = %.6lf\n",sum);
	}
}
