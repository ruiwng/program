#include  <stdio.h>
#include  <vector>
#include  <queue>

using namespace std;

unsigned int disjoint_find(vector<unsigned int>& disjoint,unsigned int element)
{
	if(disjoint[element]==0)
		return element;
	else
		return disjoint[element]=disjoint_find(disjoint,disjoint[element]);
}

void disjoint_union(vector<unsigned int>& disjoint,unsigned int element1,unsigned int element2)
{

	disjoint[disjoint_find(disjoint,element2)]=element1;
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
	unsigned int number_village;
	while(scanf("%u",&number_village)!=EOF)
	{
		vector<unsigned int> disjoint_set(number_village+1);
		for(unsigned int i=1;i<=number_village;++i)
			disjoint_set[i]=0;

		unsigned int temp=number_village*(number_village-1)/2;
		priority_queue<cost_info> unconstructed_array;
		unsigned int number_sets=number_village;
		for(unsigned int i=0;i<temp;++i)
		{
			unsigned int village1,village2;
			unsigned int cost;
			unsigned int state;
			scanf("%u %u %u %u",&village1,&village2,&cost,&state);
			if(state==1&&disjoint_find(disjoint_set,village1)!=disjoint_find(disjoint_set,village2))
			{
				disjoint_union(disjoint_set,village1,village2);
			   --number_sets;
			}
			else if(state==0)
                unconstructed_array.push(cost_info(village1,village2,cost));
		}
		unsigned int cost_sum=0;
		while(number_sets!=1)
		{
			const cost_info& min_cost=unconstructed_array.top();
			if(disjoint_find(disjoint_set,min_cost.begin)!=disjoint_find(disjoint_set,min_cost.end))
			{
				cost_sum+=min_cost.cost;
				disjoint_union(disjoint_set,min_cost.begin,min_cost.end);
				--number_sets;
			}
			unconstructed_array.pop();
		}
		printf("%u\n",cost_sum);
	}
	return 0;
}