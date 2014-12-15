#include  <stdio.h>

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		for(unsigned int i=num;i<num+4;++i)
		{
			int first=1;
			for(unsigned int j=num;j<num+4;++j)
			{
				if(j==i)
					continue;
				for(unsigned int k=num;k<num+4;++k)
				{
					if(k==j||k==i)
						continue;
					if(first==1)
						first=0;
					else
						printf(" ");
					printf("%u%u%u",i,j,k);
				}
			}
			printf("\n");
		}
	}
	return 0;
}