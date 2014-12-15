#include  <stdio.h>

struct rational
{
	unsigned int numerator;
	unsigned int denominator;
};
int main()
{
	rational ration1,ration2;
	while(scanf("%u/%u %u/%u",&ration1.numerator,&ration1.denominator,
		&ration2.numerator,&ration2.denominator)!=EOF)
	{
		double num1=static_cast<double>(ration1.numerator)/ration1.denominator;
		double num2=static_cast<double>(ration2.numerator)/ration2.denominator;
		printf("%u/%u",ration1.numerator,ration1.denominator);
		if(num1>num2)
			printf(" > ");
		else if(num1==num2)
			printf(" = ");
		else
			printf(" < ");
		printf("%u/%u",ration2.numerator,ration2.denominator);
		printf("\n");
	}
	return 0;
}