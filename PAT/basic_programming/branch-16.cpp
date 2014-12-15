#include  <stdio.h>
#include  <math.h>

int main()
{
	double num;
	while(scanf("%lf",&num)!=EOF)
	{
		printf("f(%.2lf) = ",num);
		if(num>=0.0)
			printf("%.2lf\n",sqrt(num));
		else
			printf("%.2lf\n",(num+1)*(num+1)+2*num+1/num);
	}
	return 0;
}
