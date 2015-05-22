#include  <stdio.h>
#include  <string.h>

int score[100001];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(score,0,sizeof(score));
		int large=0,index=0;
		for(int i=0;i<n;++i)
		{
			int m,n;
			scanf("%d %d",&m,&n);
			if((score[m]+=n)>large)
			{
				large=score[m];
				index=m;
			}
		}
		printf("%d %d\n",index,large);
	}
	return 0;
}
