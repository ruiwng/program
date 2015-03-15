#include  <stdio.h>
#include  <string.h>

int score[101];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(score,0,sizeof(score));
		for(int i=0;i<n;++i)
		{
			int temp;
			scanf("%d",&temp);
			++score[temp];
		}
		int query;
		scanf("%d",&query);
		for(int j=0;j<query;++j)
		{
			int temp;
			scanf("%d",&temp);
			printf("%d%c",score[temp],j==query-1?'\n':' ');
		}
	}
	return 0;
}
