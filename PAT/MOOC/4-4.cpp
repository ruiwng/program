#include  <stdio.h>
#include  <stdlib.h>

int main()
{
	unsigned int rand_num,time;
	while(scanf("%u %u",&rand_num,&time)!=EOF)
	{
		unsigned int current_time=0;
		int temp;
		int *array=(int*)malloc(time*sizeof(int));
		int size=0;
		while(scanf("%u",&temp))
		{
			if(++current_time<=time)
				array[size++]=temp;
			if(temp<0)
				break;			
		}
		unsigned int i;
		for(i=0;i<size;++i)
		{
			if(array[i]<0)
			{
				printf("Game Over\n");
				break;
			}
			if(array[i]<rand_num)
				printf("Too small\n");
			else if(array[i]==rand_num)
			{
				if(i==0)
					printf("Bingo!\n");
				else if(i==1||i==2)
					printf("Lucky You!\n");
				else
				    printf("Good Guess!\n");
				break;
			}
			else
				printf("Too big\n");
		}
		if(i==size)
			printf("Game Over\n");
	}
	return 0;
}