#include  <stdio.h>
#include  <stdlib.h>

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int *arry=(int*)malloc(n*sizeof(int));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&arry[i]);
			int j=i;
			int parent;
			while((parent=(j-1)>>1)>=0)
			{
				if(arry[parent]>arry[j])
				{
					int temp=arry[j];
					arry[j]=arry[parent];
					arry[parent]=temp;
					j=parent;					
				}
				else
					break;
			}
		}
		for(int i=0;i<m;++i)
		{
			int t;
			scanf("%d",&t);
			--t;
			while(t>=0)
			{
				printf("%d%c",arry[t],t==0?'\n':' ');
				t=(t-1)>>1;
			}
		}
		free(arry);
	}
	return 0;
}