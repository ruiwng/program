#include  <stdio.h>
#include  <string.h>

#define MAX_LENGTH   105000

char tag[MAX_LENGTH];
int primes[10000];

int main()
{
	memset(tag,0,sizeof(tag));
	int index=0;
	for(int i=2;i<MAX_LENGTH;++i)
	{
		if(tag[i]==0)
		{
			primes[index++]=i;
			if(index==10000)
				break;
			int k=i<<1;
			for(;k<MAX_LENGTH;k+=i)
				tag[k]=1;
		}
	}
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		int j=0;
		for(int i=m;i<=n;++i)
		{
			printf("%d",primes[i-1]);
			if(++j==10)
			{
				printf("\n");
				j=0;
			}
			else if(i!=n)
				printf(" ");
		}
		if(j!=0)
			printf("\n");
	}
	return 0;
}
