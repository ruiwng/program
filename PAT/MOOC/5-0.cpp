#include  <stdio.h>

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		double n1=1.0,n2=1.0;
		double sum=0.0;
		for(unsigned int i=0;i<num;++i)
		{
			double temp=n1;
			n1+=n2;
			n2=temp;
			sum+=n1/n2;
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}