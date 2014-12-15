#include  <stdio.h>
#include  <math.h>

int main()
{
	unsigned int number;
	while(scanf("%u",&number)!=EOF)
	{
		int change_number=0;
		int time=0;
		while(number!=0)
		{
			change_number+=number%16*pow(10.0f,time++);
			number/=16;
		}
		printf("%d\n",change_number);
	}
	return 0;
}