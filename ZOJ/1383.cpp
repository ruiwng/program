#include  <stdio.h>

int main()
{
	int d;
	while(scanf("%d",&d)!=EOF)
	{
		while(--d>=0)
		{
			int n;
			scanf("%d",&n);
			int first=1;
			int index=0;
			while(n!=0)
			{
				if(n&1!=0)
				{
					if(first)
						first=0;
					else
						printf(" ");
					printf("%d",index);
				}
				++index;
				n>>=1;
			}
			printf("\n");
		}
	}
	return 0;
}