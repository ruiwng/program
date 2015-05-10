#include  <stdio.h>
#include  <stdlib.h>

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int *arry=(int*)malloc(m*sizeof(int));
		for(int i=0;i<n;++i)
		{
			for(int k=0;k<m;++k)
			   scanf("%d",&arry[k]);
			bool success=true;
			for(int x=2;success&&x<m;++x)
			{
				for(int j=1;success&&j<x;++j)
				{
					if((arry[j]-arry[j-1])*(arry[x]-arry[j-1])<0)
						success=false;
				}
			}
			printf("%s\n",success?"YES":"NO");
		}
		free(arry);
	}
	return 0;
}