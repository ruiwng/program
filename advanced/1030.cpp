#include  <stdio.h>
#include  <vector>
using namespace std;


typedef struct
{
	unsigned int distance;
	unsigned int cost;
}info;

info info_matrix[500][500];

typedef struct
{
	info node_info;
	int parent;
	bool known;
}node;

void print_distance(const vector<node>& node_arr,unsigned int dest)
{
	if(node_arr[dest].parent==-1)
		printf("%u",dest);
	else
	{
		print_distance(node_arr,node_arr[dest].parent);
		printf(" %u",dest);
	}
}

int main()
{
	unsigned int number_city,number_highway,start,destination;
	while(scanf("%u %u %u %u",&number_city,&number_highway,
		&start,&destination)!=EOF)
	{

		for(unsigned int i=0;i<number_city;++i)
		 for(unsigned int j=0;j<number_city;++j)
		 {
			 info_matrix[i][j].distance=10000000;
			 info_matrix[j][i].distance=10000000;
		 }

		for(unsigned int i=0;i<number_highway;++i)
		{
			unsigned int begin_temp,dest_temp;
			info info_temp;
			scanf("%u %u %u %u",&begin_temp,&dest_temp,&info_temp.distance,
				&info_temp.cost);
			info_matrix[begin_temp][dest_temp]=info_matrix[dest_temp][begin_temp]=info_temp;
		}

		vector<node> node_array(number_city);
		for(unsigned int i=0;i<number_city;++i)
		{
			node_array[i].parent=-1;
			node_array[i].node_info.cost=0;
			node_array[i].node_info.distance=10000000;
			node_array[i].known=false;
		}
		node_array[start].node_info.distance=0;

		while(true)
		{
			unsigned int current_distance=10000001;
			int current_node=-1;
			for(unsigned int i=0;i<number_city;++i)
			{
				if(node_array[i].known==false&&node_array[i].node_info.distance<current_distance)
				{
					current_node=i;
					current_distance=node_array[i].node_info.distance;
				}
			}
			if(current_node==-1)
				break;
			node_array[current_node].known=true;
			for(unsigned int i=0;i<number_city;++i)
			{
				if(i==current_node||node_array[i].known==true)
					continue;
				info& info_temp=node_array[current_node].node_info;
				if(info_temp.distance+info_matrix[current_node][i].distance<node_array[i].node_info.distance)
				{
					node_array[i].node_info.distance=info_temp.distance+info_matrix[current_node][i].distance;
					node_array[i].parent=current_node;
					node_array[i].node_info.cost=info_temp.cost+info_matrix[current_node][i].cost;
				}
				else if(info_temp.distance+info_matrix[current_node][i].distance==node_array[i].node_info.distance)
				{
					if(info_temp.cost+info_matrix[current_node][i].cost<node_array[i].node_info.cost)
					{
						node_array[i].node_info.cost=info_temp.cost+info_matrix[current_node][i].cost;
					    node_array[i].parent=current_node;
					}
				}
			}
		}
		if(start==destination)
			printf("%u %u",start,start);
		else
		    print_distance(node_array,destination);
		printf(" %u %u\n",node_array[destination].node_info.distance,node_array[destination].node_info.cost);
	}
	return 0;
}