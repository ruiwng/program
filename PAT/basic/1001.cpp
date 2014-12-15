#include  <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int step=0;
		while(n!=1)
		{
			if(n%2)
				n=(3*n+1)/2;
			else
				n/=2;
			step++;
		}
		printf("%d\n",step);
	}
	return 0;
}