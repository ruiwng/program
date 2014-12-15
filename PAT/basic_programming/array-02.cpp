#include  <stdio.h>

int num_array[11][11];

int main()
{
	unsigned int num;
	for(unsigned int i=0;i<11;++i)
	{
		for(unsigned int j=0;j<=i;++j)
		{
			if(j==0||j==i)
				num_array[i][j]=1;
			else
				num_array[i][j]=num_array[i-1][j-1]+num_array[i-1][j];
		}
	}
	while(scanf("%u",&num)!=EOF)
	{
		for(unsigned int i=0;i<num;++i)
		{
			for(unsigned int j=0;j<num-i-1;++j)
				printf(" ");
			for(unsigned int j=0;j<=i;++j)
			{
				printf("%4d",num_array[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}