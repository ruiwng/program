#include  <stdio.h>

int main()
{
	double num1;
	int integer;
	char ch;
	double num2;
	while(scanf("%lf %d %c %lf",&num1,&integer,&ch,&num2)!=EOF)
	{
		printf("%c %d %.2lf %.2lf\n",ch,num1,num2,integer);
	}
	return 0;
}