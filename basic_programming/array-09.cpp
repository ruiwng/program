#include  <stdio.h>

int array_info[22][22];

int main()
{
	unsigned int row,column;
	while(scanf("%u %u",&row,&column)!=EOF)
	{
		for(unsigned int i=0;i<row;++i)
			for(unsigned int j=0;j<column;++j)
				scanf("%u",&array_info[i][j]);

		bool exist=false;
		for(unsigned int i=1;i<row-1;++i)
			for(unsigned int j=1;j<column-1;++j)
			{
				if(array_info[i][j]>array_info[i-1][j]&&
					array_info[i][j]>array_info[i][j-1]&&
					array_info[i][j]>array_info[i+1][j]&&
					array_info[i][j]>array_info[i][j+1])
				{
					printf("%d %u %u\n",array_info[i][j],i+1,j+1);
					exist=true;
				}
			}
			if(!exist)
				printf("None %u %u\n",row,column);
	}
	return 0;
}