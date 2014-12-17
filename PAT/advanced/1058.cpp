#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

typedef struct
{
	int num1;
	int num2;
	int num3;
}NUM;
int main()
{
	NUM number1,number2;
	while(scanf("%d.%d.%d %d.%d.%d",&number1.num1,&number1.num2,&number1.num3,&number2.num1,
		&number2.num2,&number2.num3)!=EOF)
	{
		NUM number3;
		int temp=0;
		number3.num3=(number1.num3+number2.num3+temp)%29;
		temp=(number1.num3+number2.num3+temp)/29;
		number3.num2=(number1.num2+number2.num2+temp)%17;
		temp=(number1.num2+number2.num2+temp)/17;
		number3.num1=number1.num1+number2.num1+temp;
		printf("%d.%d.%d\n",number3.num1,number3.num2,number3.num3);
	}
	return 0;
}