#include  <stdio.h>
#include  <math.h>

int main()
{
	int n;
	char sign[2];
	while(scanf("%d%s",&n,sign)!=EOF)
	{
		int row=sqrt(static_cast<double>(n+1)/2)-1;
		for(int i=row;i>=0;--i)
		{
			for(int j=0;j<row-i;++j)
				printf(" ");
			for(int j=0;j<2*i+1;++j)
				printf("%c",sign[0]);
			printf("\n");
		}
		for(int i=1;i<=row;++i)
		{
			for(int j=0;j<row-i;++j)
				printf(" ");
			for(int j=0;j<2*i+1;++j)
				printf("%c",sign[0]);
			printf("\n");
		}
		printf("%d\n",n-(2*(row+1)*(row+1)-1));
	}
	return 0;
}