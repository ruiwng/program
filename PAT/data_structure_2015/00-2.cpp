#include  <stdio.h>
#include  <string.h>

const int LIMIT=100000;
char n[LIMIT];

int prime[10000];

int main()
{
	int index=0;
	memset(n,0,sizeof(n));
	for(int i=2;i<LIMIT;++i)
	{
		if(n[i]==0)
		{
			prime[index++]=i;
			int k=i<<1;
			for(;k<LIMIT;k+=i)
				n[k]=1;
		}
	}
	int m;
	while(scanf("%d",&m)!=EOF)
	{
		int t=0;
		for(int	i=1;i<index&&prime[i]<=m;++i)
		{
			if(prime[i]-prime[i-1]==2)
				++t;
		}
		printf("%d\n",t);
	}
	return 0;
}