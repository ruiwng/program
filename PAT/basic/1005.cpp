#include  <stdio.h>
#include  <string.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		char tag[101];
		memset(tag,0,sizeof(tag));
		for(int i=0;i<n;++i)
		{
			int x;
			scanf("%d",&x);
			tag[x]=1;
		}
		for(int i=2;i<101;++i)
		{
			if(tag[i]!=1)
				continue;
			int j=i;
			while(j!=1)
			{
				if(j&1)
					j=(3*j+1)>>1;
				else
					j>>=1;
				if(j>1&&j<=101)
				    tag[j]=0;
			}
		}
		bool first=true;
		for(int i=100;i>1;--i)
		{
			if(tag[i]==1)
			{
				if(first)
				{
					first=false;
					printf("%d",i);
				}
				else
					printf(" %d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
