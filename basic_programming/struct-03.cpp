#include  <stdio.h>

int main()
{
	double x1,y1,x2,y2;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	double x3=x1+x2,y3=y1+y2;
	if(x3>=-0.05&&x3<0.00)
		printf("(0.0,");
	else
		printf("(%.1lf,",x3);
	if(y3>=-0.05&&y3<0.00)
		printf(" 0.0)");
	else
		printf(" %.1lf)",y3);
	printf("\n");
	return 0;
}