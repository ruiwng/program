#include  <stdio.h>

int main()
{
	double distance,limit;
	while(scanf("%lf %lf",&distance,&limit)!=EOF)
	{
		double ratio=distance/limit;
		if(ratio<1.1)
			printf("OK\n");
		else if(ratio>=1.1&&ratio<1.5)
			printf("Exceed %.0lf%%. Ticket 200\n",(ratio-1.0)*100);
		else
			printf("Exceed %.0lf%%. License Revoked\n",(ratio-1.0)*100);
	}
	return 0;
}