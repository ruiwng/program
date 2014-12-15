#include  <stdio.h>

int main()
{
	float num1;
	int num2;
	char num3;
	float num4;
	while(scanf("%f %d %c %f",&num1,&num2,&num3,&num4)!=EOF)
	{
		printf("%c %d %.2f %.2f\n",num3,num2,num1,num4);
	}
	return 0;
}