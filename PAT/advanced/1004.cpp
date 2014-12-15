#include  <stdio.h>
#include  <vector>
#include  <queue>
using namespace std;

typedef struct
{
	int level;
	vector<unsigned int> child_array;
}node_info;
int main()
{
	unsigned int sum_node,nonleaf;
	vector<node_info> array(100);
	while(scanf("%u %u",&sum_node,&nonleaf)!=EOF)
	{
		queue<unsigned int> node_queue;
		for(unsigned int i=0;i<nonleaf;++i)
		{
			unsigned int node_index;
			scanf("%u",&node_index);
			unsigned int node_number;
			scanf("%u",&node_number);

			for(unsigned int j=0;j<node_number;++j)
			{
				unsigned int temp;
				scanf("%u",&temp);
				array[node_index].child_array.push_back(temp);
			}
		}

		node_queue.push(1);
		array[1].level=1;
		unsigned int current_level=1;
		unsigned int leaf_sum=0;
		while(!node_queue.empty())
		{
			unsigned int temp=node_queue.front();
			node_queue.pop();
			if(array[temp].level==current_level)
			{
				if(array[temp].child_array.empty())
				   leaf_sum++;
			}
			else
			{
				if(current_level>1)
					printf(" ");
				printf("%u",leaf_sum);
				if(array[temp].child_array.empty())
				    leaf_sum=1;
				else
					leaf_sum=0;
				current_level=array[temp].level;
			}
			vector<unsigned int>& child_temp(array[temp].child_array);
			if(!child_temp.empty())
			{
			   for(unsigned int i=0;i<child_temp.size();++i)
			   {
				   array[child_temp[i]].level=array[temp].level+1;
				   node_queue.push(child_temp[i]);
			   }
			}
			if(node_queue.empty())
			{
				if(current_level>1)
					printf(" ");
				printf("%u",leaf_sum);
			}
		}
		printf("\n");
	}
	return 0;
}