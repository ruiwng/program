#include  <stdio.h>
#include  <vector>
#include  <queue>
using namespace std;

struct node_info
{
	int distance;
	bool known;
	vector<unsigned int> adjacent_array;
	node_info():distance(0),known(false),adjacent_array(vector<unsigned int>()){}
};

int main()
{
	unsigned int number_node,number_road;
	while(scanf("%u %u",&number_node,&number_road)!=EOF)
	{
		vector<node_info> node_array(number_node+1);
		for(unsigned int i=0;i<number_road;++i)
		{
			unsigned int start,end;
			scanf("%u %u",&start,&end);
			node_array[start].adjacent_array.push_back(end);
			node_array[end].adjacent_array.push_back(start);
		}

		unsigned int number_query;
		scanf("%u",&number_query);
		for(unsigned int i=0;i<number_query;++i)
		{
			for(unsigned int j=1;j<=number_node;++j)
			  node_array[j].known=false;
			unsigned int start;
			scanf("%u",&start);
			unsigned int current_distance;
			queue<unsigned int> node_queue;
			node_queue.push(start);
			node_array[start].distance=0;
			node_array[start].known=true;
			unsigned int shortest_sum=0;
			unsigned int count_node=1;
			while(!node_queue.empty())
			{
				unsigned int current_node=node_queue.front();
				node_queue.pop();
				current_distance=node_array[current_node].distance+1;
				vector<unsigned int>& adjacent_temp=node_array[current_node].adjacent_array;

				for(unsigned int j=0;j<adjacent_temp.size();++j)
				{
					if(node_array[adjacent_temp[j]].known)
						continue;
					++count_node;
					node_array[adjacent_temp[j]].known=true;
					node_array[adjacent_temp[j]].distance=current_distance;
					shortest_sum+=current_distance;
					node_queue.push(adjacent_temp[j]);
				}
			}
			if(count_node==number_node)
			   printf("Cc(%u)=%.2lf\n",start,static_cast<double>(number_node-1)/shortest_sum);
			else
			   printf("Cc(%u)=0.00\n",start);
		}
	}
	return 0;
}