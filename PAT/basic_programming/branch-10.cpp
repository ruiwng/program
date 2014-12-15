#include  <stdio.h>

int main()
{
	unsigned int salary;
	while(scanf("%u",&salary)!=EOF)
	{
		double ratio;
		if(salary<=1600)
			ratio=0;
		else if(salary>1600&&salary<=2500)
			ratio=0.05;
		else if(salary>2500&&salary<=3500)
			ratio=0.10;
		else if(salary>3500&&salary<=4500)
			ratio=0.15;
		else 
			ratio=0.20;

		printf("%.2lf\n",ratio*(salary-1600));
	}
	return 0;
}