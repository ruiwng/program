#include  <stdio.h>

int main()
{
	int n;
	char str[4];
	while(scanf("%d%s",&n,str)!=EOF)
	{
		for(int i=0;i<n;++i)
			printf("%c",str[0]);
		printf("\n");
		int k=(n+1)/2;
		k-=2;
		for(int j=0;j<k;++j)
		{
			printf("%c",str[0]);
			for(int m=0;m<n-2;++m)
				printf(" ");
			printf("%c\n",str[0]);
		}
		for(int i=0;i<n;++i)
			printf("%c",str[0]);
		printf("\n");
	}
	return 0;
}
