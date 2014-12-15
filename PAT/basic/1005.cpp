#include  <stdio.h>
#include  <stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		bool b[101];
		for(int i=0;i<101;i++)
			b[i]=false;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			b[x]=true;
		}
		for(int i=2;i<101;i++)
		{
			if(b[i]!=true)
				continue;
			int j=i;
			while(j!=1)
			{
				if(j%2==0)
					j/=2;
				else
					j=(3*j+1)/2;
				if(j>1&&j<=101)
				    b[j]=false;
			}
		}
		bool first=true;
		for(int i=100;i>1;i--)
		{
			if(b[i]==true)
			{
				if(first==true)
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