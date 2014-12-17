#include  <stdio.h>

int main()
{
	double threshold;
	while(scanf("%lf",&threshold)!=EOF)
	{
		double sum=1;
		double num1=1;
		double num2=1;
		for(double i=1;;++i)
		{
			num1*=i;
			num2*=(2*i+1);
			double temp=num1/num2;
			sum+=temp;
			if(temp<threshold)
				break;
		}
		printf("%.6lf\n",sum*2);
	}
	return 0;
}