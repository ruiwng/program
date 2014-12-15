#include  <stdio.h>
#include  <vector>
#include  <algorithm>
using namespace std;

unsigned int distance_array[110][110];

struct node_info
{
	bool known;
	unsigned int distance;
	vector<unsigned int> children;
	vector<unsigned int> parent;
	vector<unsigned int> key_children;
	vector<unsigned int> key_parent;
	node_info():known(false),distance(0),children(),parent(),key_children(),key_parent(){}
};

void key_path(vector<node_info>& node_argu,unsigned int current_node)
{
	vector<unsigned int>& parent_temp=node_argu[current_node].key_parent;
	unsigned int length_temp=parent_temp.size();
	for(unsigned int i=0;i<length_temp;++i)
	{
		node_argu[parent_temp[i]].key_children.push_back(current_node);
		key_path(node_argu,parent_temp[i]);
	}
}

int main()
{
	unsigned int number_node,number_task;
	while(scanf("%u %u",&number_node,&number_task)!=EOF)
	{
		vector<node_info> node_array(number_node+1);
		vector<vector<unsigned int> > record_array(number_node+1);
		for(unsigned int i=0;i<number_task;++i)
		{
			unsigned int start,end,distance;
			scanf("%u %u %u",&start,&end,&distance);
			distance_array[start][end]=distance;
			node_array[start].children.push_back(end);
			node_array[end].parent.push_back(start);
			record_array[start].push_back(end);
		}
		bool error=false;
		unsigned int count=0;
		while(true)
		{
			unsigned int i=1;
			for(;i<=number_node;++i)
			{
				if(node_array[i].known)
					continue;
				if(node_array[i].parent.empty())
					break;
			}
			if(i==number_node+1)
				break;
			node_array[i].known=true;
			++count;
			vector<unsigned int>& children_temp=node_array[i].children;
			unsigned int length_temp=children_temp.size();
			for(unsigned int k=0;k<length_temp;++k)
			{
			   unsigned int j=children_temp[k];
			   node_array[j].parent.erase(find(node_array[j].parent.begin(),node_array[j].parent.end(),i));
			   if(node_array[i].distance+distance_array[i][j]>node_array[j].distance)
			   {
				  node_array[j].key_parent.clear();
				  node_array[j].key_parent.push_back(i);
				  node_array[j].distance=node_array[i].distance+distance_array[i][j];
			   }
			   else if(node_array[i].distance+distance_array[i][j]==node_array[j].distance)
				  node_array[j].key_parent.push_back(i);
			}
		}
		if(count!=number_node)
			printf("0\n");
		else
		{
		    unsigned int max_distance=0;
			vector<unsigned int> max_array;
			for(unsigned int i=1;i<=number_node;++i)
			{
				if(node_array[i].distance>max_distance)
				{
					max_array.clear();
					max_array.push_back(i);
					max_distance=node_array[i].distance;
				}
				else if(node_array[i].distance==max_distance)
					max_array.push_back(i);
			}
			for(unsigned int j=0;j<max_array.size();++j)
		         key_path(node_array,max_array[j]);

			printf("%u\n",max_distance);
			for(unsigned int i=1;i<=number_node;++i)
			{
				vector<unsigned int>& children_temp=node_array[i].key_children;
				unsigned int size_temp=children_temp.size();
				unsigned int temp_count=0;
				int record_size=record_array[i].size();
				for(int j=record_size-1;j>=0;--j)
				{
					if(find(children_temp.begin(),children_temp.end(),record_array[i][j])!=children_temp.end())
					{
						++temp_count;
						printf("%u->%u\n",i,record_array[i][j]);
					}
					if(temp_count==size_temp)
						break;
				}				  
			}
		}
	}
	return 0;
}

