#include  <stdio.h>
#include  <vector>
using namespace std;

int distance_info[501][501];

struct node_info
{
	unsigned int rescue;
	unsigned int distance;
	bool known;
	int parent;
	unsigned int number_shortest;
	node_info():rescue(0),distance(10000000),known(false),parent(-1),number_shortest(0){}
};

void print_road(const vector<node_info>& node_array,unsigned int index)
{
	if(node_array[index].parent==-1)
		printf("%u",index);
	else
	{
		print_road(node_array,node_array[index].parent);
		printf(" %u",index);
	}
}

int main()
{
	unsigned int number_city,number_road,start,end;
	while(scanf("%u %u %u %u",&number_city,&number_road,&start,
		&end)!=EOF)
	{
		vector<unsigned int> rescue_info(number_city);
		for(unsigned int i=0;i<number_city;++i)
		   scanf("%u",&rescue_info[i]);

		for(unsigned int i=0;i<number_road;++i)
		{
			unsigned int start_temp,end_temp,distance_temp;
			scanf("%u %u %u",&start_temp,&end_temp,&distance_temp);
			distance_info[start_temp][end_temp]=distance_temp;
			distance_info[end_temp][start_temp]=distance_temp;
		}

		vector<node_info> node_array(number_city);
		node_array[start].rescue=rescue_info[start];
		node_array[start].distance=0;
		node_array[start].number_shortest=1;

		while(true)
		{
			unsigned int current_distance=10000001;
			unsigned int current_node;
			for(unsigned int i=0;i<number_city;++i)
			{
				if(node_array[i].known)
					continue;
				if(node_array[i].distance<current_distance)
				{
					current_node=i;
					current_distance=node_array[i].distance;
				}
			}
			if(current_distance==10000001)
				break;
			node_array[current_node].known=true;

			for(unsigned int i=0;i<number_city;++i)
			{
				if(node_array[i].known||distance_info[current_node][i]==0)
					continue;
				if(node_array[current_node].distance+distance_info[current_node][i]<node_array[i].distance)
				{
					node_array[i].number_shortest=node_array[current_node].number_shortest;
					node_array[i].distance=node_array[current_node].distance+distance_info[current_node][i];
					node_array[i].rescue=node_array[current_node].rescue+rescue_info[i];
					node_array[i].parent=current_node;
				}
				else if(node_array[current_node].distance+distance_info[current_node][i]==node_array[i].distance)
				{
					node_array[i].number_shortest+=node_array[current_node].number_shortest;
					if(node_array[i].rescue<node_array[current_node].rescue+rescue_info[i])
					{
						node_array[i].rescue=node_array[current_node].rescue+rescue_info[i];
						node_array[i].parent=current_node;
					}
				}
			}
		}
		printf("%u %u\n",node_array[end].number_shortest,node_array[end].rescue);
		print_road(node_array,end);
		printf("\n");
	}
	return 0;
}