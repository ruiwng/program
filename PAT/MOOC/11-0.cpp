#include  <stdio.h>

int is_zero(double a)
{
	return a>-0.05&&a<0.05;
}

int main()
{
	double x1,y1,x2,y2;
	while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!=EOF)
	{
		double x3=x1+x2;
		double y3=y1+y2;
        if(is_zero(x3))
			x3=0.0;
		if(is_zero(y3))
			y3=0.0;
		printf("(%.1lf, %.1lf)\n",x3,y3);
	}
	return 0;
}