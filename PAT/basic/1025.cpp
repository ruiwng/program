#include  <stdio.h>
#include  <stack>
using namespace std;

struct node
{
	int data;
	int next;
};

node node_array[100001];

int main()
{
	int first_node,total_number,sublist_length;
	while(scanf("%d %d %d",&first_node,&total_number,&sublist_length)!=EOF)
	{
		node_array[100000].next=first_node;
		for(int i=0;i<total_number;++i)
		{
			int address_temp,data_temp,next_temp;
			scanf("%d %d %d",&address_temp,&data_temp,&next_temp);
			node_array[address_temp].data=data_temp;
			node_array[address_temp].next=next_temp;
		}

		int begin=100000;
		int node_number=0;
		while((begin=node_array[begin].next)!=-1)
			node_number++;

		if(sublist_length!=1)
		{
			int start=100000;
			for(int i=0;i<node_number/sublist_length;++i)
			{
				int temp_begin=start;
				stack<int> stack_temp;
				for(int j=0;j<sublist_length;++j)
				{
					stack_temp.push(node_array[temp_begin].next);
					temp_begin=node_array[temp_begin].next;
				}
				int end=node_array[temp_begin].next;
				temp_begin=start;
				while(!stack_temp.empty())
				{
					node_array[temp_begin].next=stack_temp.top();
					stack_temp.pop();
					temp_begin=node_array[temp_begin].next;
				}
				node_array[temp_begin].next=end;
				start=temp_begin;
			}
		}
		int start=node_array[100000].next;
		while(start!=-1)
		{
			if(node_array[start].next!=-1)
               printf("%05d %d %05d\n",start,node_array[start].data,node_array[start].next);
			else
				printf("%05d %d -1\n",start,node_array[start].data);
			start=node_array[start].next;
		}
	}
	return 0;
}
