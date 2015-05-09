#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>

bool is_primer(int n)
{
	if(n==1)
		return false;
	int p=sqrt((double)n);
	for(int i=2;i<=p;++i)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		while(!is_primer(m))
			++m;
		char *position=(char *)malloc(m*sizeof(char));
		memset(position,0,m*sizeof(char));
		for(int i=0;i<n;++i)
		{
			int t;
			scanf("%d",&t);
			int hash=t%m;
			int j=0;
			for(;j<m;++j)
			{
				int k=(hash+j*j)%m;
				if(position[k]==0)
				{
					position[k]=1;
					printf("%d",k);
					break;
				}
			}
			if(j==m)
				printf("-");
			printf("%c",i==n-1?'\n':' ');
		}
		free(position);
	}
	return 0;
}