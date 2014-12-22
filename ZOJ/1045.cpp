#include  <stdio.h>

int main()
{
	double overhang;
	while(scanf("%lf",&overhang)!=EOF)
	{
		if(overhang==0.00)
			break;
		double hang=0.0;
		for(int i=2;;++i)
		{
			hang+=static_cast<double>(1)/i;
			if(hang>=overhang)
			{
				printf("%d card(s)\n",i-1);
				break;
			}
		}
	}
	return 0;
}