/*#include  <stdio.h>
#include  <vector>
using namespace std;
int main()
{
	int n;
	vector<int> intVec;
	while(scanf("%d",&n)!=EOF)
	{
		while(!intVec.empty())
			intVec.pop_back();
        for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			intVec.push_back(x);
		}
		int max=intVec[0],first=0,last=0;
		int temp=intVec[0],tempfirst=0;
		for(int i=1;i<n;i++)
		{
			if(temp<0)
			{
				temp=intVec[i];
				tempfirst=i;
			}
			else
				temp+=intVec[i];
			if(intVec[i]>0)
			{
				if(last==i-1)
				{
					if(max>=0)
					{
					   max+=intVec[i];
					   last=i;
					}
					else
					{
						max=intVec[i];
						first=last=i;
					}
				}
				else 
				{
					if(max<intVec[i])
					{
						max=intVec[i];
						first=last=i;
					}
				}
				if(temp>max)
				{
					first=tempfirst;
					last=i;
					max=temp;
				}
			}
			else if(intVec[i]<0)
			{
				if(max<intVec[i])
				{
					max=intVec[i];
					first=last=i;
				}
			}
		}
		if(max>=0)
		   printf("%d %d %d\n",max,intVec[first],intVec[last]);
		else
			printf("0 %d %d\n",*intVec.begin(),*intVec.rbegin());
	}
	return 0;
}*/

#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;
int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		vector<int> num_array(num);
		for(unsigned int i=0;i<num;++i)
		scanf("%d",&num_array[i]);

		int max_sum=0,this_sum=0;
		unsigned int max_begin=0,max_end=0,this_begin=0,this_end=0;
		for(int i=0;i<num;++i)
		{
			this_sum+=num_array[i];
			this_end=i;
			if(this_sum>max_sum)
			{
				max_sum=this_sum;
				max_begin=this_begin;
				max_end=this_end;
			}
			else if(this_sum<0)
			{
				this_sum=0;
				this_begin=i+1;
				this_end=i+1;
			}
		}
		if(max_sum==0)
		{
			if(find(num_array.begin(),num_array.end(),0)==num_array.end())
				printf("0 %d %d\n",num_array[0],num_array[num-1]);
			else
				printf("0 0 0\n");
		}
		else
			printf("%d %d %d\n",max_sum,num_array[max_begin],num_array[max_end]);
	}
	return 0;
}