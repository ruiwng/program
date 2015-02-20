#include  <stdio.h>
#include  <vector>
#include  <queue>
#include  <deque>
#include  <functional>
using namespace std;

struct connection_info
{
	int x,y;
	int length;
	bool operator>(const connection_info& c) const
	{
		return this->length>c.length;
	}
};

vector<int> disjoint_set;
int disjoint_find(int index)
{
	if(disjoint_set[index]==0)
		return index;
	return disjoint_set[index]=disjoint_find(disjoint_set[index]);
}

int main()
{
	int points_num,routes_num;
	while(scanf("%d",&points_num)!=EOF&&points_num)
	{
		scanf("%d",&routes_num);
		disjoint_set.assign(points_num+1,0);
		priority_queue<connection_info,deque<connection_info>,greater<connection_info> > connection_queue;
		for(int i=0;i<routes_num;++i)
		{
			connection_info connection_temp;
			scanf("%d%d%d",&connection_temp.x,&connection_temp.y,&connection_temp.length);
			connection_queue.push(connection_temp);
		}
		int cable_length=0;
		while(points_num>1)
		{
			connection_info connection_temp=connection_queue.top();
			connection_queue.pop();
			int parent1=disjoint_find(connection_temp.x);
			int parent2=disjoint_find(connection_temp.y);
			if(parent1!=parent2)
			{
				disjoint_set[parent2]=parent1;
				cable_length+=connection_temp.length;
				--points_num;
			}
		}
		printf("%d\n",cable_length);
	}
	return 0;
}