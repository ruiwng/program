#include <stdio.h>

int main()
{
	int k;
	while(scanf("%d",&k)!=EOF)
	{
		int max=0;
		int current_max=0;
		int first,last,start=0,end=0,current_start;//first:first element,last:last element,start: beginning of the max subsequence,end: ending of 
		//the max subsequence,current_start:beginning of current continuous max subsequence 
		bool flag=false;//tag whether current_start is specified.
		bool negative=true;//tag whether nonnegative element exists.
		for(int i=0;i<k;++i)
		{
			int temp;
			scanf("%d",&temp);
			if(!flag)
			{
				flag=true;
				current_start=temp;
			}
			if(temp>=0)
				negative=false;
			if(i==0)
				first=temp;
			else if(i==k-1)
				last=temp;
			current_max+=temp;
			if(current_max>max)
			{
				max=current_max;
				start=current_start;
				end=temp;
			}
			else if(current_max<0)
			{
				current_max=0;
				flag=false;
			}
		}
		if(negative)
			printf("0 %d %d\n",first,last);
		else
			printf("%d %d %d\n",max,start,end);
	}
	return 0;
}