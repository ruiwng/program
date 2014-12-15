#include  <stdio.h>

int main()
{
	unsigned int time;
	while(scanf("%u",&time)!=EOF)
	{
		unsigned int current_time=0;cycle
		unsigned int current_distance=0;
		while(current_time<time)
		{
			if(current_time+10<time)
			{
				current_distance+=90;
				current_time+=10;
			}
			else
			{
				current_distance+=9*(time-current_time);
				current_time=time;
				break;
			}
			if(current_distance<current_time*3)
				continue;
			else
				current_time+=30;
		}

		unsigned int tortoise_distance=3*time;
		if(current_distance>tortoise_distance)
			printf("^_^ %u\n",current_distance);
		else if(current_distance==tortoise_distance)
			printf("-_- %u\n",current_distance);
		else
			printf("@_@ %u\n",tortoise_distance);
	}
	return 0;
}