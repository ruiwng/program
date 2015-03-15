#include  <stdio.h>
#include  <vector>
using namespace std;

int a[100001];

#define  HIGH_BOUND      0x7fffffff
int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		int min_sum=HIGH_BOUND;
		vector<pair<int,int> > result;
		for(int j=0,start=0,sum=0;j<n;++j)
		{
			sum+=a[j];
			if(sum>=k)
			{
				while(sum-a[start]>=k)
					sum-=a[start++];
				if(sum<min_sum)
				{
					result.clear();
					min_sum=sum;
					result.push_back(make_pair(start,j));
				}
				else if(sum==min_sum)
					result.push_back(make_pair(start,j));
				sum-=a[start++];
			}
		}
		for(int m=0;m<result.size();++m)
			printf("%d-%d\n",result[m].first+1,result[m].second+1);
	}
	return 0;
}
