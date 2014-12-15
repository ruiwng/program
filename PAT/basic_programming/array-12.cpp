#include  <stdio.h>
#include  <vector>
using namespace std;

char array_info[10][10];

struct pos
{
	unsigned int x;
	unsigned int y;
};

struct pos_pair
{
	pos pos1;
	pos pos2;
};

void print_array(unsigned int row,unsigned int column)
{
	for(unsigned int i=0;i<row;++i)
	{
		for(unsigned int j=0;j<column;++j)
		{
			printf("%c",array_info[i][j]);
			if(j==column-1)
				break;
			printf(" ");
		}
		printf("\n");
	}
}

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		getchar();
		for(unsigned int i=0;i<2*num;++i)
			for(unsigned int j=0;j<2*num;++j)
			{
				char temp;
				scanf("%c",&temp);
				array_info[i][j]=temp;
				getchar();
			}
		unsigned int operation;
		scanf("%u",&operation);
		vector<pos_pair> pos_array(operation);
		for(unsigned int i=0;i<operation;++i)
			scanf("%u %u %u %u",&pos_array[i].pos1.x,&pos_array[i].pos1.y,
				&pos_array[i].pos2.x,&pos_array[i].pos2.y);
		unsigned int count=0;
		unsigned int success=0;
		for(unsigned int i=0;i<operation;++i)
		{
			if(array_info[pos_array[i].pos1.x-1][pos_array[i].pos1.y-1]==array_info[pos_array[i].pos2.x-1][pos_array[i].pos2.y-1]
			&&array_info[pos_array[i].pos1.x-1][pos_array[i].pos1.y-1]!='*')
			{
				array_info[pos_array[i].pos1.x-1][pos_array[i].pos1.y-1]=array_info[pos_array[i].pos2.x-1][pos_array[i].pos2.y-1]='*';
				if(++success==2*num*num)
				{
					printf("Congratulations!\n");
					break;
				}
				else
				    print_array(2*num,2*num);
			}
			else
			{
				++count;
				printf("Uh-oh\n");
			}
			if(count==3)
				break;
		}
		if(count==3)
			printf("Game Over\n");
	}
	return 0;
}