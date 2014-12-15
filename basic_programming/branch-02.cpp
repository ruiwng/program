#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>

int main()
{
	double x1,y1,x2,y2,x3,y3;
	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
	{
		double line1=sqrtf(pow(x1-x2,2)+pow(y1-y2,2));
		double line2=sqrtf(pow(x1-x3,2)+pow(y1-y3,2));
		double line3=sqrtf(pow(x2-x3,2)+pow(y2-y3,2));
		if(line1+line2>line3&&line1+line3>line2&&line2+line3>line1)
		 {
			double length=line1+line2+line3;
			double temp=length/2;
			double area=sqrtf(temp*(temp-line1)*(temp-line2)*(temp-line3));
			printf("L = %.2lf, A = %.2lf\n",length,area);
		 }
		else
			printf("Impossible\n");
	}
	return 0;
}