#include  <stdio.h>
#include  <vector>
#include  <queue>
using namespace std;
vector<int> disjoint;
int disjoint_find(int element)
{
	if(disjoint[element]==0)
		return element;
	else
		return disjoint[element]=disjoint_find(disjoint[element]);
}
struct cost_info
{
	unsigned int begin;
	unsigned int end;
	unsigned int cost;
	cost_info(unsigned int b,unsigned int e,unsigned int c):begin(b),end(e),cost(c){}
	bool operator<(const cost_info& info) const
	{
		return cost>info.cost;
	}
};
int main()
{
	int number_village;
	while(scanf("%d",&number_village)!=EOF)
	{
		disjoint.assign(number_village+1,0);
	    int temp=number_village*(number_village-1)/2;
		priority_queue<cost_info> unconstructed_array;
		int number_sets=number_village;
		for(int i=0;i<temp;++i)
		{
			int village1,village2;
			int cost;
			int state;
			scanf("%d %d %d %d",&village1,&village2,&cost,&state);
			int parent1=disjoint_find(village1);
			int parent2=disjoint_find(village2);
			if(state==1&&parent1!=parent2)
			{
			   disjoint[parent2]=parent1;
			   --number_sets;
			}
			else if(state==0)
                unconstructed_array.push(cost_info(village1,village2,cost));
		}
		int cost_sum=0;
		while(number_sets!=1)
		{
			const cost_info& min_cost=unconstructed_array.top();
			int parent1=disjoint_find(min_cost.begin);
			int parent2=disjoint_find(min_cost.end);
			if(parent1!=parent2)
			{
				cost_sum+=min_cost.cost;
				disjoint[parent2]=parent1;
				--number_sets;
			}
			unconstructed_array.pop();
		}
		printf("%d\n",cost_sum);
	}
	return 0;
}