#include  <stdio.h>

int main()
{
	int values=0;
	int num;
	int up_sum=0,down_sum=0;
	int up_count=0,down_count=0;
	int equal_sum=0;
	int state=0;
	int prev;
	while(scanf("%d",&num)!=EOF)
	{
		if(num==0)
		{
			if(values==0)
				break;
			printf("Nr values = %d:  %.6lf %.6lf\n",values,up_count==0?0.0:static_cast<double>(up_sum)/up_count,
				down_count==0?0.0:static_cast<double>(down_sum)/down_count);
			values=0;
			up_sum=down_sum=up_count=down_count=equal_sum=0;
			state=0;
		}
		else
		{
			if(values!=0)
			{
				if(num>prev)
				{
					if(state==0)
					{
						up_sum+=equal_sum;
						++up_count;
					}
					else if(state==-1)
						++up_count;
					up_sum+=1;
					state=1;
				}
				else if(num==prev)
				{
					if(state==0)
						++equal_sum;
					else if(state==1)
						++up_sum;
					else
						++down_sum;
				}
				else
				{
					if(state==0)
					{
						down_sum+=equal_sum;
						++down_count;
					}
					else if(state==1)
						++down_count;
					down_sum+=1;
					state=-1;
				}
			}
			prev=num;
			++values;
		}
	}
	return 0;
}