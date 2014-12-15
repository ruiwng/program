#include  <stdio.h>

struct rational
{
	unsigned int numerator;
	unsigned int denominator;
};
unsigned int gcd(unsigned int num1,unsigned int num2)
{
	while(num1%num2!=0)
	{
		unsigned int temp=num1%num2;
		num1=num2;
		num2=temp;
	}
	return num2;
}

int main()
{
	rational ration1,ration2;
	while(scanf("%u/%u %u/%u",&ration1.numerator,&ration1.denominator,
		&ration2.numerator,&ration2.denominator)!=EOF)
	{
		unsigned int gcd_temp=gcd(ration1.denominator,ration2.denominator);
		unsigned int gcm_temp=ration1.denominator*ration2.denominator/gcd_temp;

		rational ration_sum;
		ration_sum.denominator=gcm_temp;
		ration_sum.numerator=ration1.numerator*ration2.denominator/gcd_temp+ration2.numerator*ration1.denominator/gcd_temp;
		gcd_temp=gcd(ration_sum.denominator,ration_sum.numerator);
		ration_sum.denominator/=gcd_temp;
		ration_sum.numerator/=gcd_temp;

		printf("%u",ration_sum.numerator);
		if(ration_sum.denominator!=1)
			printf("/%u",ration_sum.denominator);
		printf("\n");
	}
	return 0;
}