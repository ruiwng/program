#include  <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int step=0;
		while(n!=1)
		{
			if(n&1)
				n=(3*n+1)>>1;
			else
				n>>=1;
			++step;
		}
		printf("%d\n",step);
	}
	return 0;
}
