#include  <stdio.h>

int main()
{
	int data_set;
	while(scanf("%d",&data_set)!=EOF)
	{
		for(int i=0;i<data_set;++i)
		{
			int temp;
			scanf("%d",&temp);
			int j=0;
			while(true)
			{
				int t=temp/(1<<j);
				if(t%2==1)
				{
					printf("%d %d\n",t,j);
					break;
				}
				++j;
			}
		}
	}
	return 0;
}