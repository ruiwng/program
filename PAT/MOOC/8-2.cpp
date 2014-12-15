#include  <stdio.h>

int matrix[21][21];

int main()
{
	unsigned int row,column;
	while(scanf("%u %u",&row,&column)!=EOF)
	{
		for(unsigned int i=0;i<row;++i)
			for(unsigned int j=0;j<column;++j)
				scanf("%d",&matrix[i][j]);
		int exist=0;
		for(unsigned int i=1;i+1<row;++i)
			for(unsigned int j=1;j+1<column;++j)
				if(matrix[i][j]>matrix[i][j-1]&&matrix[i][j]>matrix[i-1][j]
				&&matrix[i][j]>matrix[i][j+1]&&matrix[i][j]>matrix[i+1][j])
				{
					printf("%d %u %u\n",matrix[i][j],i+1,j+1);
					exist=1;
				}
		if(exist==0)
			printf("None %u %u\n",row,column);
	}
	return 0;
}