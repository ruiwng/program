#include  <stdio.h>
#include  <math.h>

const double PI=3.141592653589793;

struct pos
{
	double x,y;
	pos(double x1=0.0,double y1=0.0):x(x1),y(y1){}
};

int main()
{
	pos p1,p2,p3;
	while(scanf("%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y)!=EOF)
	{
		pos p;
		double squre1=p1.x*p1.x+p1.y*p1.y;
		double squre2=p2.x*p2.x+p2.y*p2.y;
		double squre3=p3.x*p3.x+p3.y*p3.y;
		p.x=((squre1-squre2)*(p1.y-p3.y)-(squre1-squre3)*(p1.y-p2.y))/(2*((p1.y-p3.y)*(p1.x-p2.x)-(p1.y-p2.y)*(p1.x-p3.x)));
		p.y=((squre1-squre2)*(p1.x-p3.x)-(squre1-squre3)*(p1.x-p2.x))/(2*((p1.x-p3.x)*(p1.y-p2.y)-(p1.x-p2.x)*(p1.y-p3.y)));
		printf("%.2lf\n",2*PI*sqrt((p.x-p1.x)*(p.x-p1.x)+(p.y-p1.y)*(p.y-p1.y)));
	}
	return 0;
}