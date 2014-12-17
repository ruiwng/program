#include  <stdio.h>
#include  <vector>
using namespace std;

unsigned int distance_info[501][501];

typedef struct
{
	unsigned int rescue_number;
	unsigned int distance;
	unsigned int path_number;
	bool known;
}node;

int main()
{
	unsigned int number_city,number_road,current,save;
	while(scanf("%u %u %u %u",&number_city,&number_road,&current,&save)!=EOF)
	{
		vector<unsigned int> rescue_array(number_city);
		for(unsigned int i=0;i<number_city;++i)
			scanf("%u",&rescue_array[i]);

		for(unsigned int i=0;i<number_road;++i)
		{
			unsigned int node1,node2,distance_temp;
			scanf("%u %u %u",&node1,&node2,&distance_temp);
			distance_info[node1][node2]=distance_info[node2][node1]=distance_temp;
		}

		vector<node> node_array(number_city);
		for(unsigned int i=0;i<number_city;++i)
		{
			node_array[i].distance=1000000;
			node_array[i].known=false;
			node_array[i].rescue_number=0;
			node_array[i].path_number=0;
		}

		node_array[current].distance=0;
		node_array[current].rescue_number=rescue_array[current];
		node_array[current].path_number=1;

		while(true)
		{
			unsigned int current_distance=1000000;
			unsigned int current_node;
			for(unsigned int i=0;i<number_city;++i)
			{
				if(node_array[i].known)
					continue;
				if(node_array[i].distance<current_distance)
				{
					current_distance=node_array[i].distance;
					current_node=i;
				}
			}
			node_array[current_node].known=true;
			if(current_node==save)
				break;

			for(unsigned int i=0;i<number_city;++i)
			{
				if(node_array[i].known)
					continue;
				if(distance_info[current_node][i]==0)
					continue;
				if(node_array[current_node].distance+distance_info[current_node][i]<node_array[i].distance)
				{
					node_array[i].path_number=node_array[current_node].path_number;
					node_array[i].distance=node_array[current_node].distance+distance_info[current_node][i];
					node_array[i].rescue_number=node_array[current_node].rescue_number+rescue_array[i];
				}
				else if(node_array[current_node].distance+distance_info[current_node][i]==node_array[i].distance)
				{
					node_array[i].path_number+=node_array[current_node].path_number;
					if(node_array[current_node].rescue_number+rescue_array[i]>node_array[i].rescue_number)
						node_array[i].rescue_number=node_array[current_node].rescue_number+rescue_array[i];
				}
			}
		}
		printf("%u %u\n",node_array[save].path_number,node_array[save].rescue_number);
	}
	return 0;
}