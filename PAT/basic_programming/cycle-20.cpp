#include  <stdio.h>
#include  <vector>
using namespace std;

int main()
{
	unsigned int rand_num,time;
	while(scanf("%u %u",&rand_num,&time)!=EOF)
	{
		unsigned int current_time=0;
		int temp;
		vector<int> array;
		while(scanf("%u",&temp))
		{
			if(++current_time<=time)
				array.push_back(temp);
			if(temp<0)
				break;			
		}
		unsigned int i;
		for(i=0;i<array.size();++i)
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
		if(i==array.size())
			printf("Game Over\n");
	}
	return 0;
}