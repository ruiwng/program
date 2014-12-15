#include  <stdio.h>
int main()
{
	double amount;
	while(scanf("%lf",&amount)!=EOF)
	{
		if(amount<=15)
			printf("%.2f\n",4*amount/3);
		else
			printf("%.2f\n",2.5*amount-17.5);
	}
	return 0;
}