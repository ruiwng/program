#include  <stdio.h>

int main()
{
	double length;
	while(scanf("%lf",&length)!=EOF)
	{
		length=length/100/0.3048;
		int num1=length;
		int num2=(length-num1)*12;
		printf("%d %d\n",num1,num2);
	}
	return 0;
}