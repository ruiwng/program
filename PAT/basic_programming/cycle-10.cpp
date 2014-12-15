#include  <stdio.h>

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		double sum=0.0;
		double num1=2.0;
		double num2=1.0;
		for(unsigned int i=1;i<=num;++i)
		{
			sum+=num1/num2;
			double temp=num1;
			num1=num1+num2;
			num2=temp;
		}
		printf("%.2f\n",sum);
	}
	return 0;
}