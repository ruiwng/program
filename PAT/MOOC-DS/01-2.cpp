#include  <stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int first,last;
		int all_sum=0;
		int this_sum=0;
		int all_start;
		int all_end;
		int this_start;
		int first_flag=0;
		int negative=1;
		for(int i=0;i<n;++i)
		{
			int temp;
			scanf("%d",&temp);
			if(temp>=0)
				negative=0;
			if(!first_flag)
			{
				this_start=temp;
				first_flag=1;
			}
			if(i==0)
			{
				first=temp;
				all_start=temp;
				all_end=temp;
			}
			else if(i==n-1)
				last=temp;
			this_sum+=temp;
			if(this_sum>all_sum)
			{
				all_sum=this_sum;
				all_start=this_start;
				all_end=temp;
			}
			else if(this_sum<0)
			{
				this_sum=0;
				first_flag=0;
			}
		}
		if(all_sum>0)
			printf("%d %d %d\n",all_sum,all_start,all_end);
		else if(all_sum==0)
		{
			if(negative)
				printf("0 %d %d\n",first,last);
			else
				printf("0 0 0\n");
		}
	}
	return 0;
}