#include  <cstdio>
#include  <vector>
#include  <queue>
#include  <cmath>
using namespace std;

struct node
{
	node(int l=0):level(l),children(){}
	int level;
	vector<int> children;
};
int main()
{
	int N;double P,R;
	while(scanf("%d%lf%lf",&N,&P,&R)!=EOF)
	{
		vector<node> node_array;
		node_array.resize(N);
		vector<int> root_array;
		for(int i=0;i<N;++i)
		{
			int t;
			scanf("%d",&t);
			if(t==-1)
				root_array.push_back(i);
			else
			{
				node_array[t].children.push_back(i);
			}
		}
		int high_level=0;
		int all_counts=0;
		for(int i=0;i<root_array.size();++i)
		{
			int count=0;
			queue<int> node_queue;
			int current_level=0;
			node_queue.push(root_array[i]);
			while(!node_queue.empty())
			{
				int m=node_queue.front();
				node_queue.pop();
				int temp_level=node_array[m].level+1;
				vector<int>& child=node_array[m].children;
				if(!child.empty())
				{
					if(temp_level>current_level)
					{
						current_level=temp_level;
						count=0;
					}
					count+=child.size();
				}
				for(vector<int>::iterator iter=child.begin();iter!=child.end();++iter)
				{
					node_array[*iter].level=temp_level;
					node_queue.push(*iter);
				}
			}
			if(current_level>high_level)
			{
				high_level=current_level;
				all_counts=count;
			}
			else if(current_level==high_level)
				all_counts+=count;
		}

		double price=P*pow(1+R/100,high_level);
		if(all_counts)
            printf("%.2lf %d\n",price,all_counts);
		else
			printf("%.2lf 1\n",price);
	}
	return 0;
}