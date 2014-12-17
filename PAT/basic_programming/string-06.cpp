#include  <stdio.h>

int main()
{
	char str[4][9];
	while(scanf("%08s%08s%08s%08s",str[0],str[1],str[2],str[3])!=EOF)
	{
		for(unsigned int i=0;i<=3;++i)
		{
			unsigned int sum=0;
			for(unsigned j=0;j<8;++j)
				sum=sum*2+str[i][j]-'0';
			printf("%u",sum);
			if(i==3)
				break;
			printf(".");
		}
		printf("\n");
	}
	return 0;
}