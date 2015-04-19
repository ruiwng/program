#include  <stdio.h>
#include  <string.h>
#include  <queue>
#include  <functional>
using namespace std;

struct road
{
	int start,end;
	int cost;
	road(){}
	road(const road& r):start(r.start),end(r.end),cost(r.cost){}
	bool operator>(const road& r) const
	{
		return this->cost>r.cost;
	}
};

int disjoint_set[1001];

int disjoint_find(int index)
{
	if(disjoint_set[index]==0)
		return index;
	else
		return disjoint_set[index]=disjoint_find(disjoint_set[index]);
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(disjoint_set,0,sizeof(disjoint_set));
		priority_queue<road,deque<road>,greater<road> > road_queue;
		for(int i=0;i<m;++i)
		{
			road r;
			scanf("%d%d%d",&r.start,&r.end,&r.cost);
			road_queue.push(r);
		}
		int cost_sum=0;
		while(!road_queue.empty())
		{
			road t(road_queue.top());
			road_queue.pop();
			int parent1=disjoint_find(t.start);
			int parent2=disjoint_find(t.end);
			if(parent1!=parent2)
			{
				cost_sum+=t.cost;
				disjoint_set[parent2]=parent1;
				if(--n==1)
					break;
			}
		}
		printf("%d\n",n==1?cost_sum:-1);
	}
	return 0;
}