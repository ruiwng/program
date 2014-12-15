
/*
#include  <stdio.h>
#include  <map>
using namespace std;

typedef struct
{
	int key;
	int next;
}NODE;

NODE node_array[100000];
int main()
{
	unsigned int node_number;
	int start;
	while(scanf("%u %d",&node_number,&start)!=EOF)
	{
		map<int,int> node_info;
		for(unsigned int i=0;i<node_number;i++)
		{
			int address;
			int key_temp,next_temp;
			scanf("%u %d %d",&address,&key_temp,&next_temp);
			node_array[address].key=key_temp;
			node_array[address].next=next_temp;
		}

		int current_pos=start;
		while(current_pos!=-1)
		{
			node_info.insert(make_pair(node_array[current_pos].key,current_pos));
			current_pos=node_array[current_pos].next;
		}

		printf("%u",node_info.size());
		for(map<int,int>::const_iterator iter=node_info.begin();iter!=node_info.end();++iter)
		{
			printf(" %05u\n%05u %d",iter->second,iter->second,iter->first);
		}
		printf(" -1\n");
	}
	return 0;
}
*/

/*another method,如果仅仅是排序，数组相对于红黑树的效果更好！*/
#include  <stdio.h>
#include  <vector>
#include  <algorithm>

using namespace std;

typedef struct
{
	int key;
	int next;
}NODE;

typedef struct
{
	int address;
	int key;
}SATISFY_NODE;

struct sort_by_key
{
	bool operator()(const SATISFY_NODE& node1,const SATISFY_NODE& node2) const
	{
		return node1.key<node2.key;
	}
};

NODE node_array[100000];
int main()
{
	unsigned int node_number;
	int start;
	while(scanf("%u %d",&node_number,&start)!=EOF)
	{
		vector<SATISFY_NODE> node_info;
		for(unsigned int i=0;i<node_number;i++)
		{
			int address;
			int key_temp,next_temp;
			scanf("%u %d %d",&address,&key_temp,&next_temp);
			node_array[address].key=key_temp;
			node_array[address].next=next_temp;
		}

		int current_pos=start;
		while(current_pos!=-1)
		{
			SATISFY_NODE node_temp;
			node_temp.address=current_pos;
			node_temp.key=node_array[current_pos].key;
			node_info.push_back(node_temp);
			current_pos=node_array[current_pos].next;
		}
		sort(node_info.begin(),node_info.end(),sort_by_key());
		printf("%u",node_info.size());
		for(vector<SATISFY_NODE>::const_iterator iter=node_info.begin();iter!=node_info.end();++iter)
		{
			printf(" %05u\n%05u %d",iter->address,iter->address,iter->key);
		}
		printf(" -1\n");
	}
	return 0;
}