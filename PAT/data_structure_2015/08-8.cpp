#include  <stdio.h>
#include  <set>
#include  <vector>
#include  <algorithm>
#include  <unordered_set>
using namespace std;

struct successor
{
	int index;
	int last_time;
	successor(int i=0,int l=0):index(i),last_time(l){}
};

struct node
{
	int complete_time;
	bool flag;
	unordered_set<int> predecessor;
	vector<int> key_points;
	vector<successor> successors;
	node():complete_time(0),flag(false){}
};

struct key_path
{
	int start,end;
	key_path(int s=0,int e=0):start(s),end(e){}
	bool operator<(const key_path& k) const
	{
		if(this->start!=k.start)
			return this->start<k.start;
		return this->end>k.end;
	}
};
set<key_path> path_array;
vector<node> node_array;

void dfs(int index)
{
	const vector<int>& key_points=node_array[index].key_points;
	for(int i=0;i<key_points.size();++i)
	{
		path_array.insert(key_path(key_points[i],index));
		dfs(key_points[i]);
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		path_array.clear();
		node_array.assign(n+1,node());
		for(int i=0;i<m;++i)
		{
			int start,end,last;
			scanf("%d%d%d",&start,&end,&last);
			node_array[start].successors.push_back(successor(end,last));
			node_array[end].predecessor.insert(start);
		}
		int complete_time=0;
		int num=0;
		vector<int> last_complete;
		while(true)
		{
			int i=1;
			for(;i<=n;++i)
			{
				if(!node_array[i].flag&&node_array[i].predecessor.empty())
					break;
			}
			if(i==n+1)
				break;
			++num;
			node_array[i].flag=true;
			if(node_array[i].complete_time>complete_time)
			{
				complete_time=node_array[i].complete_time;
				last_complete.clear();
				last_complete.push_back(i);
			}
			else if(node_array[i].complete_time==complete_time)
				last_complete.push_back(i);
			const vector<successor>& s=node_array[i].successors;
			int length=s.size();
			for(int j=0;j<length;++j)
			{
				int index=s[j].index;
				int t=s[j].last_time;
				node_array[index].predecessor.erase(i);
				if(node_array[i].complete_time+t>node_array[index].complete_time)
				{
					node_array[index].complete_time=node_array[i].complete_time+t;
					node_array[index].key_points.clear();
					node_array[index].key_points.push_back(i);
				}
				else if(node_array[i].complete_time+t==node_array[index].complete_time)
					node_array[index].key_points.push_back(i);
			}
		}
		if(num!=n)
			printf("0\n");
		else
		{
			printf("%d\n",complete_time);
			for(int i=0;i<last_complete.size();++i)
				dfs(last_complete[i]);
			for(set<key_path>::iterator iter=path_array.begin();iter!=path_array.end();++iter)
				printf("%d->%d\n",iter->start,iter->end);
		}
	}
	return 0;
}