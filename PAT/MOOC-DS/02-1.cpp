#include  <stdio.h>
#include  <stack>
using namespace std;

struct node
{
	int element;
	int next;
};

node node_array[100001];
int main()
{
	int start,node_num,elements;
	while(scanf("%d%d%d",&start,&node_num,&elements)!=EOF)
	{
		node_array[100000].next=start;
		for(int i=0;i<node_num;++i)
		{
			int address;
			node n;
			scanf("%d%d%d",&address,&n.element,&n.next);
			node_array[address]=n;
		}
		int current_start=100000;
		while(true)
		{
			stack<int> node_stack;
			int t=current_start;
			while(node_array[t].next!=-1&&node_stack.size()!=elements)
			{
				node_stack.push(node_array[t].next);
				t=node_array[t].next;
			}
			if(node_stack.size()!=elements)
				break;
			int end=node_array[node_stack.top()].next;
			while(!node_stack.empty())
			{
				node_array[current_start].next=node_stack.top();
				current_start=node_stack.top();
				node_stack.pop();
			}
			node_array[current_start].next=end;
		}
		int t=node_array[100000].next;
		while(true)
		{		
			printf("%05d %d ",t,node_array[t].element);
			if(node_array[t].next==-1)
			{
				printf("-1\n");
				break;
			}
			else
				printf("%05d\n",node_array[t].next);
			t=node_array[t].next;
		}
	}
	return 0;
}