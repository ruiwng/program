#include  <stdio.h>

int main()
{
	int k;
	while(scanf("%d",&k)!=EOF)
	{
		int max=0;
		int current_max=0;
		for(int i=0;i<k;++i)
		{
			int temp;
			scanf("%d",&temp);
			current_max+=temp;
			if(current_max>max)
				max=current_max;
			else if(current_max<0)
				current_max=0;
		}
		printf("%d\n",max);
	}
	return 0;
}