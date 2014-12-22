#include  <stdio.h>

int main()
{
	double sum=0.0;
	for(int i=0;i<12;++i)
	{
		double temp;
		scanf("%lf",&temp);
		sum+=temp;
	}
	printf("$%.2lf\n",sum/12);
	return 0;
}