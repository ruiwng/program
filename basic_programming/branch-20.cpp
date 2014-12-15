#include  <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)
			printf("sign(%d) = -1\n",n);
		else if(n==0)
			printf("sign(0) = 0\n");
		else
			printf("sign(%d) = 1\n",n);
	}
	return 0;
}