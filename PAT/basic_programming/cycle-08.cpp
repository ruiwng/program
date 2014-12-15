#include  <stdio.h>

int main()
{
	double a3,a2,a1,a0;
	while(scanf("%lf %lf %lf %lf",&a3,&a2,&a1,&a0)!=EOF)
	{
		double a,b;
		scanf("%lf %lf",&a,&b);
		double fa=((a3*a+a2)*a+a1)*a+a0;
		double fb=((a3*b+a2)*b+a1)*b+a0;
		if(fa==0.0)
			printf("%.2f\n",a);
		else if(fb==0.0)
			printf("%.2f\n",b);
		else
		{
		   while(b-a>=0.001)
		  {
			double median=(a+b)/2;
			double fmedian=((a3*median+a2)*median+a1)*median+a0;
			if(fmedian==0.0)
				break;
			else if(fmedian*fa<0)
			{
				b=median;
				fb=fmedian;
			}
			else if(fmedian*fb<0)
			{
				a=median;
				fa=fmedian;
			}
		  }
		  printf("%.2f\n",(a+b)/2);
		}
	}
	return 0;
}