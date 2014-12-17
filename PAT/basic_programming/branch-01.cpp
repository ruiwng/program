#include  <stdio.h>

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		if(num<=60)
			printf("Speed: %u - OK\n",num);
		else
			printf("Speed: %u - Speeding\n",num);
	}
	return 0;
}