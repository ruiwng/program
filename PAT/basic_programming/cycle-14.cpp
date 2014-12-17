#include  <stdio.h>

unsigned int gcd(unsigned int num1,unsigned int num2)
{
	while(num1%num2!=0)
	{
		unsigned int temp=num2;
		num2=num1%num2;
		num1=temp;
	}
	return num2;
}

int main()
{
	unsigned int num1,num2;
	while(scanf("%u %u",&num1,&num2)!=EOF)
	{
		unsigned int temp=gcd(num1,num2);
		printf("%u %u\n",temp,num1*num2/temp);
	}
	return 0;
}