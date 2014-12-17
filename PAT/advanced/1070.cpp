
#include  <stdio.h>
#include  <algorithm>
#include  <vector>
using namespace std;
typedef struct
{
	double all;
	double price;
	double average;
}N;

bool comp(N n1,N n2)
{
	return n1.average<n2.average;
}

int main()
{
	int kind;
	double sum;
	while(scanf("%d %lf",&kind,&sum)!=EOF)
	{
		N* p=(N*)malloc(kind*sizeof(N));
		for(int i=0;i<kind;i++)
			scanf("%lf",&p[i].all);
		for(int i=0;i<kind;i++)
		{
			scanf("%lf",&p[i].price);
			p[i].average=p[i].price/p[i].all;
		}
		vector<N> vec(p,p+kind);
		make_heap(vec.begin(),vec.end(),comp);
		double price=0.0;
		while(true)
		{
			if(vec.empty())
				break;
			pop_heap(vec.begin(),vec.end(),comp);
			N n=*vec.rbegin();
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

