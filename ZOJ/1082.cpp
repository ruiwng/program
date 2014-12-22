#include  <stdio.h>

#define  MAX_DISTANCE     0x00ffffff
int dist[101][101];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dist[i][j]=MAX_DISTANCE;
		for(int i=1;i<=n;++i)
		{
			int number;
			scanf("%d",&number);
			for(int j=0;j<number;++j)
			{
				int index,dist_temp;
				scanf("%d%d",&index,&dist_temp);
				dist[i][index]=dist_temp;
			}
		}
		for(int i=1;i<=n;++i)
		   for(int j=1;j<=n;++j)
			   for(int k=1;k<=n;++k)
				   if(dist[j][i]+dist[i][k]<dist[j][k])
					   dist[j][k]=dist[j][i]+dist[i][k];

		int min_distance=MAX_DISTANCE;
		int min_index=0;
		for(int i=1;i<=n;++i)
		{
			int dist_temp=0;
			for(int j=1;j<=n;++j)
			{
				if(j==i)
					continue;
				if(dist[i][j]>dist_temp)
					dist_temp=dist[i][j];
			}
			if(dist_temp<min_distance)
			{
				min_index=i;
				min_distance=dist_temp;
			}
		}
		if(min_index==0)
			printf("disjoint\n");
		else
			printf("%d %d\n",min_index,min_distance);
	}
	return 0;
}