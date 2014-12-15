#include  <stdio.h>
#include  <math.h>

int main()
{
	double a,b,c;
	while(scanf("%lf %lf %lf",&a,&b,&c)!=EOF)
	{
		if(a==0.0)
		{
			if(b==0.0)
			{
				if(c==0.0)
					printf("Zero Equation\n");
				else
					printf("Not An Equation\n");
			}
			else
				printf("%.2lf\n",-c/b);
		}
		else
		{
			double temp=b*b-4*a*c;
			if(temp>0)
			{
				printf("%.2lf\n",(-b+sqrt(temp))/(2*a));
				printf("%.2lf\n",(-b-sqrt(temp))/(2*a));
			}
			else if(temp==0)
			    printf("%.2lf\n",-b/(2*a));
			else
			{
				if(b!=0.0)
				{
				   printf("%.2lf+%.2lfi\n",-b/(2*a),sqrt(-temp)/(2*a));
				   printf("%.2lf-%.2lfi\n",-b/(2*a),sqrt(-temp)/(2*a));
				}
				else
				{
				   printf("0.00+%.2lfi\n",sqrt(c/a));
				   printf("0.00-%.2lfi\n",sqrt(c/a));
				}
			}
		}
	}
	return 0;
}