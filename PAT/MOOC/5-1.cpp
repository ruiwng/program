#include  <stdio.h>

unsigned int gcd(unsigned int n1,unsigned int n2)
{
	while(n1%n2!=0)
	{
		unsigned int temp=n1%n2;
		n1=n2;
		n2=temp;
	}
	return n2;
}

int main()
{
	unsigned int num1,num2;
	while(scanf("%u/%u",&num1,&num2)!=EOF)
	{
		unsigned int temp=gcd(num1,num2);
		printf("%u/%u\n",num1/temp,num2/temp);
	}
	return 0;
}