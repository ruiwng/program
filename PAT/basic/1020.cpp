#include  <stdio.h>
#include  <algorithm>
#include  <vector>
using namespace std;
struct cake
{
	double all;
	double price;
	double average;
        bool operator<(const cake &rhs) const
        {return this->average<rhs.average;}
};
int main()
{
	int kind;
	int sum;
	while(scanf("%d %d",&kind,&sum)!=EOF)
	{
		vector<cake> vec(kind);
                for(int i=0;i<kind;++i)
			scanf("%lf",&vec[i].all);
		for(int i=0;i<kind;++i)
		{
			scanf("%lf",&vec[i].price);
			vec[i].average=vec[i].price/vec[i].all;
		}
		make_heap(vec.begin(),vec.end());
		double price=0.0;
		while(true)
		{
			if(vec.empty())
				break;
			pop_heap(vec.begin(),vec.end());
			cake n=vec.back();
			vec.pop_back();
			if(sum>=n.all)
			{
				price+=n.price;
				sum-=n.all;
			}
			else if(sum<n.all)
			{
				price+=sum*n.average;
				break;
			}
		}
		printf("%.2lf\n",price);
	}
	return 0;
}
