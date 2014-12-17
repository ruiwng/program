#include  <stdio.h>

int main()
{
	long int n;
	while(scanf("%ld",&n)!=EOF)
	{
		if(n==1)
			printf("1=1\n");
		else
		{
			printf("%ld=",n);
			bool first=true;
			for(long int i=2;i<=n;i++)
			{
				int count=0;
				while(!(n%i))
				{
					count++;
					n/=i;
				}
				if(count)
				{
					if(first)
						first=false;
					else
						printf("*");
					if(count==1)
					    printf("%ld",i);
					else
						printf("%ld^%d",i,count);
			    }
				if(n==1)
					break;
			}
			printf("\n");
		}
	}
	return 0;
}