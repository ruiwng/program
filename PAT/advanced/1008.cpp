#include  <stdio.h>
#include  <stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int current=0;
		int time=0;
		for(int i=0;i<n;i++)
		{
			int temp;
			scanf("%d",&temp);
			if(temp>current)
			{
				time+=6*(temp-current)+5;
				current=temp;
			}
			else if(temp<current)
			{
				time+=4*(current-temp)+5;
				current=temp;
			}
			else
				time+=5;
		}
		printf("%d\n",time);
	}
	return 0;
}