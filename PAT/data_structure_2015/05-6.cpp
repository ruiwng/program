#include  <stdio.h>

int arry[1001];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&arry[i]);
			int j=i;
			while(j>0)
			{
				int k=(j-1)/2;
				if(arry[k]>arry[j])
				{
					int temp=arry[k];
					arry[k]=arry[j];
					arry[j]=temp;
					j=k;
				}
				else
				   break;
			}
		}
		for(int i=0;i<m;++i)
		{
			int pos;
			scanf("%d",&pos);
			--pos;
			while(true)
			{
				printf("%d",arry[pos]);
				if(pos!=0)
					printf(" ");
				else
				{
					printf("\n");
					break;
				}
				pos=(pos-1)/2;
			}
		}
	}
	return 0;
}