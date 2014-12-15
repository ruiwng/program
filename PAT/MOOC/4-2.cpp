#include  <stdio.h>

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		for(unsigned int i=1;i<=num;++i)
		{
			for(unsigned int j=1;j<=i;++j)
				printf("%u*%u=%-4u",j,i,j*i);
			printf("\n");
		}
	}
	return 0;
}