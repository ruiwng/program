#include  <stdio.h>

int main()
{
	unsigned int year;
	unsigned int time;
	while(scanf("%u %u",&year,&time)!=EOF)
	{
		double salary;
		if(year<5)
			salary=30.0;
		else
			salary=50.0;
		if(time<=40)
			printf("%.2lf\n",salary*time);
		else
			printf("%.2lf\n",salary*40+salary*1.5*(time-40));
	}
	return 0;
}