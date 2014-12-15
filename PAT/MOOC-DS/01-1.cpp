#include  <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int all_max=0;
		int this_max=0;
		for(int i=0;i<n;++i)
		{
			int temp;
			scanf("%d",&temp);
			this_max+=temp;
			if(this_max>all_max)
				all_max=this_max;
			else if(this_max<0)
				this_max=0;
		}
		printf("%d\n",all_max);
	}
	return 0;
}