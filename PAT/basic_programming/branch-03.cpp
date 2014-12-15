#include  <stdio.h>

int main()
{
	unsigned int day;
	while(scanf("%d",&day)!=EOF)
	{
		unsigned int temp=(day-1)%5;
		if(temp>=0&&temp<=2)
			printf("Fishing in day %u\n",day);
		else
			printf("Drying in day %u\n",day);
	}
	return 0;
}