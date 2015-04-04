#include  <stdio.h>
#include  <vector>
#include  <queue>
#include  <algorithm>
using namespace std;

struct node_info
{
	bool tranversed;
	vector<int> neighbors;
	node_info():tranversed(false){}
};

int node,edge;
vector<node_info> node_array;

void dfs(int index)
{
	if(!node_array[index].tranversed)
	{
		node_array[index].tranversed=true;
		printf(" %d",index);
		const vector<int>& neigh=node_array[index].neighbors;
		int len=neigh.size();
		for(int i=0;i<len;++i)
			dfs(neigh[i]);
	}
}

void bfs(int index)
{
	queue<int> node_queue;
	node_array[index].tranversed=true;
	node_queue.push(index);
	while(!node_queue.empty())
	{
		int front=node_queue.front();
		printf(" %d",front);
		node_queue.pop();
		const vector<int>& neigh=node_array[front].neighbors;
		int len=neigh.size();
		for(int i=0;i<len;++i)
		{
			if(!node_array[neigh[i]].tranversed)
			{
				node_array[neigh[i]].tranversed=true;
				node_queue.push(neigh[i]);
			}
		}
	}
}

int main()
{
	while(scanf("%d%d",&node,&edge)!=EOF)
	{
		node_array.assign(node,node_info());
		for(int i=0;i<edge;++i)
		{
			int m,n;
			scanf("%d%d",&m,&n);
			node_array[m].neighbors.push_back(n);
			node_array[n].neighbors.push_back(m);
		}
		for(int i=0;i<node;++i)
			sort(node_array[i].neighbors.begin(),node_array[i].neighbors.end());
		for(int i=0;i<node;++i)
		{
			if(!node_array[i].tranversed)
			{
				printf("{");
				dfs(i);
				printf(" }\n");
			}
		}
		for(int i=0;i<node;++i)
			node_array[i].tranversed=false;
		for(int i=0;i<node;++i)
		{
			if(!node_array[i].tranversed)
			{
				printf("{");
				bfs(i);
				printf(" }\n");
			}
		}
	}
	return 0;
}