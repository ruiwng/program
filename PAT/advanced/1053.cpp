#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <functional>

using namespace std;

struct node
{
	int weight_sum;
	int parent;
	vector<unsigned int> child_array;
	node():weight_sum(0),parent(-1),child_array(vector<unsigned int>()){}
};

void manipulate_weight(vector<node>& array,vector<unsigned int>& weight_array,unsigned int index,vector<int>& path)
{
	if(array[index].parent==-1)
		path.push_back(weight_array[index]);
	else
	{
		manipulate_weight(array,weight_array,array[index].parent,path);
		path.push_back(weight_array[index]);
	}
}

void DFS(vector<node>& array,vector<unsigned int>& weight_array,int parent,unsigned int index,unsigned int current_weight,vector<vector<int> >& info_array)
{
	array[index].weight_sum=current_weight-weight_array[index];
	current_weight=array[index].weight_sum;
	array[index].parent=parent;

	if(array[index].weight_sum==0&&array[index].child_array.empty())
	{
		vector<int> current_path; 
		manipulate_weight(array,weight_array,index,current_path);
		info_array.push_back(current_path);
		return;		
	}

	if(array[index].weight_sum<0)
	    return;
	vector<unsigned int>& child_temp=array[index].child_array;

	for(unsigned int i=0;i<child_temp.size();++i)
		DFS(array,weight_array,index,child_temp[i],array[index].weight_sum,info_array);
}

int main()
{
	unsigned int number_node,non_leaf,weight_number;
	while(scanf("%u %u %u",&number_node,&non_leaf,&weight_number)!=EOF)
	{
		vector<unsigned int> weight_array(number_node);
		for(unsigned int i=0;i<number_node;++i)
			scanf("%u",&weight_array[i]);

		vector<node> node_array(number_node);

		vector<vector<int> > path_info;
		for(unsigned int i=0;i<non_leaf;++i)
		{
			unsigned int node_index,child_sum;
			scanf("%u %u",&node_index,&child_sum);
			node_array[node_index].child_array.resize(child_sum);
			for(unsigned int j=0;j<child_sum;++j)
				scanf("%u",&node_array[node_index].child_array[j]);
		}

		DFS(node_array,weight_array,-1,0,weight_number,path_info);
		sort(path_info.begin(),path_info.end(),greater<vector<int> >());

		for(unsigned int i=0;i<path_info.size();++i)
		{
			vector<int>& path_temp=path_info[i];
			printf("%u",path_temp[0]);
			for(unsigned int j=1;j<path_temp.size();++j)
				printf(" %u",path_temp[j]);
			printf("\n");
		}
	}
	return 0;
}