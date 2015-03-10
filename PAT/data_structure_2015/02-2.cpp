#include  <stdio.h>
#include  <stack>
using namespace std;

struct record
{
	int data;
	int next;
};

record arry[100001];

int main()
{
	int n,k;
	while(scanf("%d%d%d",&arry[100000].next,&n,&k)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			int position;
			scanf("%d",&position);
			scanf("%d%d",&arry[position].data,&arry[position].next);
		}
		int begin=100000;
		stack<int> record_stack;
		while(true)
		{
			int current=arry[begin].next;
			while(current!=-1&&record_stack.size()!=k)
			{
				record_stack.push(current);
				current=arry[current].next;
			}
			if(record_stack.size()!=k)
				break;
			while(!record_stack.empty())
			{
				arry[begin].next=record_stack.top();
				begin=record_stack.top();
				record_stack.pop();
			}
			arry[begin].next=current;
		}
		begin=arry[100000].next;
		while(true)
		{
			printf("%05d %d ",begin,arry[begin].data);
			if(arry[begin].next==-1)
			{
				printf("-1\n");
				break;
			}
			else
				printf("%05d\n",arry[begin].next);
			begin=arry[begin].next;
		}
	}
	return 0;
}