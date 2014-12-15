/*#include  <stdio.h>
#include  <vector>
using namespace std;

struct node
{
	bool known;
	int parent;
	int send;
	int taken_back;
	int distance;
	node():known(false),parent(-1),send(0),taken_back(0),distance(1000000000){}
};

int dist_array[501][501];

void print_path(const vector<node>& array,int dest)
{
	if(array[dest].parent==-1)
		printf("%d",dest);
	else
	{
		print_path(array,array[dest].parent);
		printf("->%d",dest);
	}
}
int main()
{
	int max_capacity,number_station,problem_index,number_roads;
	while(scanf("%d %d %d %d",&max_capacity,&number_station,&problem_index,
		&number_roads)!=EOF)
	{
		vector<int> current_capacity(number_station+1);
		for(int i=1;i<=number_station;++i)
		  scanf("%d",&current_capacity[i]);
		current_capacity[0]=max_capacity/2;
		for(int i=0;i<number_roads;++i)
		{
			int station_one,station_two,distance_temp;
			scanf("%d %d %d",&station_one,&station_two,&distance_temp);
			dist_array[station_one][station_two]=dist_array[station_two][station_one]=distance_temp;
		}

		vector<node> node_array(number_station+1);
		node_array[0].distance=0;
		while(true)
		{
			int short_distance=1000000001;
			unsigned int current_node;
			for(int i=0;i<=number_station;++i)
			{
				if(node_array[i].known)
					continue;
				if(node_array[i].distance<short_distance)
				{
					current_node=i;
					short_distance=node_array[i].distance;
				}
			}
			if(short_distance==1000000001)
				break;
			node_array[current_node].known=true;
			if(current_node==problem_index)
				break;
			for(int i=0;i<=number_station;++i)
			{
				if(node_array[i].known||dist_array[current_node][i]==0)
					continue;
				if(node_array[current_node].distance+dist_array[current_node][i]<=node_array[i].distance)
				{
					int temp_send,temp_taken_back;
					if(current_capacity[i]<max_capacity/2)
					{
						temp_send=node_array[current_node].send+max_capacity/2-current_capacity[i]-node_array[current_node].taken_back;
						if(temp_send<node_array[current_node].send)
							temp_send=node_array[current_node].send;
						temp_taken_back=node_array[current_node].taken_back-(max_capacity/2-current_capacity[i]);
						if(temp_taken_back<0)
							temp_taken_back=0;
					}
					else if(current_capacity[i]>=max_capacity/2)
					{
						temp_send=node_array[current_node].send;
						temp_taken_back=node_array[current_node].taken_back+current_capacity[i]-max_capacity/2;
					}
					if(node_array[current_node].distance+dist_array[current_node][i]<node_array[i].distance||node_array[i].send>temp_send
					||(node_array[i].send==temp_send&&node_array[i].taken_back>temp_taken_back))
					{
					    node_array[i].distance=node_array[current_node].distance+dist_array[current_node][i];
						node_array[i].parent=current_node;
						node_array[i].send=temp_send;
						node_array[i].taken_back=temp_taken_back;
					}

				}

			}
		}
		printf("%d ",node_array[problem_index].send);
		print_path(node_array,problem_index);
		printf(" %d\n",node_array[problem_index].taken_back);
	}
	return 0;
}
*/
#include  <stdio.h>
#include  <vector>
using namespace std;

struct node
{
	bool known;
	vector<int> parent_array;
	vector<int> child_array;
	int send;
	int taken_back;
	int distance;

	node():known(false),child_array(),send(0),taken_back(0),distance(1000000000){}
};

int dist_array[501][501];

void DFS(vector<node>& node_info,const vector<int>& capacity,vector<int>& shortest_path,vector<int>& current_path,
		 int current_node,int problem_node,int& send,int& taken_back,
		 int temp_send,int temp_taken_back,int max_capacity)
{
	if(capacity[current_node]<max_capacity/2)
	{
		node_info[current_node].send=temp_send+max_capacity/2-capacity[current_node]-temp_taken_back;
		if(node_info[current_node].send<temp_send)
				node_info[current_node].send=temp_send;
		node_info[current_node].taken_back=temp_taken_back-(max_capacity/2-capacity[current_node]);
		if(node_info[current_node].taken_back<0)
				node_info[current_node].taken_back=0;
	}
    else if(capacity[current_node]>=max_capacity/2)
	{
		node_info[current_node].taken_back=temp_taken_back+capacity[current_node]-max_capacity/2;
		node_info[current_node].send=temp_send;
	}

	current_path.push_back(current_node);

	if(current_node==problem_node)
	{
		if(shortest_path.empty()||node_info[current_node].send<send||(node_info[current_node].send==send&&node_info[current_node].taken_back<taken_back))
		{
			shortest_path=current_path;
			send=node_info[current_node].send;
			taken_back=node_info[current_node].taken_back;
		}
		return;
	}
	
	const vector<int>& child_array=node_info[current_node].child_array;
	for(unsigned int i=0;i<child_array.size();++i)
	{
		while(current_path.back()!=current_node)
			current_path.pop_back();
		DFS(node_info,capacity,shortest_path,current_path,child_array[i],problem_node,send,taken_back,
			node_info[current_node].send,node_info[current_node].taken_back,max_capacity);
	}
}

int main()
{
	int max_capacity,number_station,problem_index,number_roads;
	while(scanf("%d %d %d %d",&max_capacity,&number_station,&problem_index,
		&number_roads)!=EOF)
	{
		vector<int> current_capacity(number_station+1);
		for(int i=1;i<=number_station;++i)
		  scanf("%d",&current_capacity[i]);
		current_capacity[0]=max_capacity/2;
		for(int i=0;i<number_roads;++i)
		{
			int station_one,station_two,distance_temp;
			scanf("%d %d %d",&station_one,&station_two,&distance_temp);
			dist_array[station_one][station_two]=dist_array[station_two][station_one]=distance_temp;
		}

		vector<node> node_array(number_station+1);
		node_array[0].distance=0;
		while(true)
		{
			int short_distance=1000000001;
			unsigned int current_node;
			for(int i=0;i<=number_station;++i)
			{
				if(node_array[i].known)
					continue;
				if(node_array[i].distance<short_distance)
				{
					current_node=i;
					short_distance=node_array[i].distance;
				}
			}
			if(short_distance==1000000001)
				break;
			node_array[current_node].known=true;			
			if(current_node!=0)
			{
				vector<int>& parent_array_temp=node_array[current_node].parent_array;
				for(vector<int>::iterator iter=parent_array_temp.begin();iter!=parent_array_temp.end();++iter)
				{
					node_array[*iter].child_array.push_back(current_node);
				}
			}
			if(current_node==problem_index)
				break;
			for(int i=0;i<=number_station;++i)
			{
				if(node_array[i].known||dist_array[current_node][i]==0)
					continue;
				if(node_array[current_node].distance+dist_array[current_node][i]<node_array[i].distance)
				{
					node_array[i].distance=node_array[current_node].distance+dist_array[current_node][i];
					node_array[i].parent_array.clear();
					node_array[i].parent_array.push_back(current_node);
				}
				else if(node_array[current_node].distance+dist_array[current_node][i]==node_array[i].distance)
					node_array[i].parent_array.push_back(current_node);
			}
		}
		vector<int> satisfy_path,temp_path;
		int send=0,taken_back=0,temp_send=0,temp_taken_back=0;
		DFS(node_array,current_capacity,satisfy_path,temp_path,0,problem_index,send,taken_back,temp_send,temp_taken_back,
			max_capacity);
		printf("%d ",send);
		for(unsigned int i=0;;++i)
		{
			printf("%d",satisfy_path[i]);
			if(i==satisfy_path.size()-1)
				break;
			printf("->");
		}
		printf(" %d\n",taken_back);
	}
	return 0;
}
