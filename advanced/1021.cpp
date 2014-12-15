#include  <stdio.h>
#include  <vector>
using namespace std;

typedef struct 
{
	bool known;
	vector<unsigned int> neighbours;
}NODE;


void DFT(vector<NODE>& node_info,unsigned int number,unsigned int& depth)
{
	vector<unsigned int>& neigh=node_info[number].neighbours;
	node_info[number].known=true;
	depth=0;
	for(unsigned int i=0;i<neigh.size();i++)
	{
		unsigned int current_deep=0;
		if(!node_info[neigh[i]].known)
		{
			node_info[neigh[i]].known=true;
			DFT(node_info,neigh[i],current_deep);
			current_deep++;
		}
		if(current_deep>depth)
			depth=current_deep;
	}
}

int main()
{
	unsigned int node_num;
	while(scanf("%u",&node_num)!=EOF)
	{
		vector<NODE> node_array(node_num+1);
		for(unsigned int i=1;i<=node_num;++i)
			node_array[i].known=false;
		for(unsigned int i=1;i<node_num;++i)
		{
			unsigned int node_num1,node_num2;
			scanf("%u %u",&node_num1,&node_num2);
			node_array[node_num1].neighbours.push_back(node_num2);
			node_array[node_num2].neighbours.push_back(node_num1);
		}

		unsigned int deepest=0;
		unsigned int components_num;
		vector<unsigned int> deep_array;
		for(unsigned int i=1;i<=node_num;++i)
		{
			components_num=1;
			unsigned int deep_temp=0;
			DFT(node_array,i,deep_temp);
			if(i==1)
			{
			   for(unsigned int j=1;j<=node_num;++j)
			  {
				if(!node_array[j].known)
				{
					unsigned int deep=0;
					DFT(node_array,j,deep);
					components_num++;
				}
			  }
			  if(components_num>1)
			  {
				printf("Error: %u components\n",components_num);
				break;
			  }
			}
			if(deep_temp==deepest)
				deep_array.push_back(i);
			else if(deep_temp>deepest)
			{
				deepest=deep_temp;
				deep_array.clear();
				deep_array.push_back(i);
			}
			for(unsigned int j=1;j<=node_num;++j)
				node_array[j].known=false;
		}

		if(components_num==1)
		{
			for(unsigned int j=0;j<deep_array.size();++j)
			  printf("%u\n",deep_array[j]);
		}
	}
	return 0;
}