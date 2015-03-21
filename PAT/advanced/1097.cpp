#include  <stdio.h>
#include  <set>
using namespace std;

struct node
{
	int key;
	int next;
};

node node_array[100000];

int main()
{
	int start, n;
	while(scanf("%d%d",&start,&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			int address;
			scanf("%d",&address);
			scanf("%d%d",&node_array[address].key,&node_array[address].next);
		}
		int remove_start=-1,remove_end=-1;
		int end=-1;
		int current_pos=start;
		set<int> duplicate_set;
		while(current_pos!=-1)
		{
			int temp=node_array[current_pos].key<0?(-node_array[current_pos].key):node_array[current_pos].key;
			int next=node_array[current_pos].next;
			if(duplicate_set.find(temp)==duplicate_set.end())
			{
				duplicate_set.insert(temp);
				if(end==-1)
					start=end=current_pos;				
				else 
				{
					node_array[end].next=current_pos;
					end=current_pos;
				}
				node_array[end].next=-1;
			}
			else
			{
				if(remove_end==-1)
					remove_start=remove_end=current_pos;
				else
				{
					node_array[remove_end].next=current_pos;
					remove_end=current_pos;
				}
				node_array[remove_end].next=-1;
			}
			current_pos=next;
		}
		while(start!=-1)
		{
			printf("%05d %d ",start,node_array[start].key);
			if(node_array[start].next!=-1)
				printf("%05d\n",node_array[start].next);
			else
			{
				printf("-1\n");
				break;
			}
			start=node_array[start].next;
		}
		while(remove_start!=-1)
		{
			printf("%05d %d ",remove_start,node_array[remove_start].key);
			if(node_array[remove_start].next!=-1)
				printf("%05d\n",node_array[remove_start].next);
			else
			{
				printf("-1\n");
				break;
			}
			remove_start=node_array[remove_start].next;
		}
	}
	return 0;
}