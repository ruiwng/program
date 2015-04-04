#include  <stdio.h>
#include  <vector>
#include  <queue>
using namespace std;

struct node
{
	bool traversed;
	int layer;
	vector<int> neighbors;
	node():traversed(false),layer(0){}
};

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		vector<node> node_array(n+1,node());
		for(int i=0;i<m;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			node_array[x].neighbors.push_back(y);
			node_array[y].neighbors.push_back(x);
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				node_array[j].traversed=false;
			queue<int> node_queue;
			node_queue.push(i);
			node_array[i].traversed=true;
			node_array[i].layer=0;
			int sum=0;
			while(!node_queue.empty())
			{
				int front=node_queue.front();
				node_queue.pop();
				if(node_array[front].layer>6)
					break;
				++sum;
				const vector<int> &neigh=node_array[front].neighbors;
				int len=neigh.size();
				for(int k=0;k<len;++k)
				{
					if(!node_array[neigh[k]].traversed)
					{
						node_array[neigh[k]].traversed=true;
						node_array[neigh[k]].layer=node_array[front].layer+1;
						node_queue.push(neigh[k]);
					}
				}
			}
			printf("%d: %.2lf%%\n",i,100*static_cast<double>(sum)/n);
		}
	}
	return 0;
}