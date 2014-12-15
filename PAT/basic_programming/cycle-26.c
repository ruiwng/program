#include  <stdio.h>

int main()
{
	unsigned int n;
	while(scanf("%u",&n)!=EOF)
	{
		double sum=0.0;
		double temp=-2;
		int flag=1;
		for(unsigned int i=1;i<=n;++i)
		{
			temp+=3;
			if(flag)
			{
				sum+=1/temp;
				flag=0;
			}
			else
			{
				sum-=1/temp;
				flag=1;
			}
		}
		printf("sum = %.3lf\n",sum);
	}
	return 0;
}
