#include  <stdio.h>

int main()
{
	unsigned int sum;
	while(scanf("%u",&sum)!=EOF)
	{
		unsigned int num1=0,num2=0,num3=1;
		unsigned int count=1;
		while(num1+num2+num3<sum)
		{
			unsigned int temp=num2;
			num2=num3;
			num1+=temp;
			num3=num1;
			count++;
		}
		printf("%u\n",count);
	}
	return 0;
}