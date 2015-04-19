#include  <stdio.h>
#include  <vector>
#include  <unordered_set>
using namespace std;

struct successor
{
	int index;
	int last_time;
};

struct node
{
	int complete_time;
	bool flag;
	unordered_set<int> precessor;
	vector<successor> successors;
	node():complete_time(0),flag(false){}
};

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		vector<node> node_array(n);
		for(int i=0;i<m;++i)
		{
			int num;
			successor s;
			scanf("%d%d%d",&num,&s.index,&s.last_time);
			node_array[num].successors.push_back(s);
			node_array[s.index].precessor.insert(num);
		}
		int num=0;
		int complete_time=0;
		while(true)
		{
			int i=0;
			for(;i<n;++i)
			{
				if(!node_array[i].flag&&node_array[i].precessor.empty())
					break;
			}
			if(i==n)
				break;
			++num;
			if(node_array[i].complete_time>complete_time)
				complete_time=node_array[i].complete_time;
			node_array[i].flag=true;
			const vector<successor>& s=node_array[i].successors;
			int length=s.size();
			for(int j=0;j<length;++j)
			{
				if(node_array[i].complete_time+s[j].last_time>node_array[s[j].index].complete_time)
					node_array[s[j].index].complete_time=node_array[i].complete_time+s[j].last_time;
				node_array[s[j].index].precessor.erase(i);
			}
		}
		if(num==n)
			printf("%d\n",complete_time);
		else
			printf("Impossible\n");
	}
	return 0;
}