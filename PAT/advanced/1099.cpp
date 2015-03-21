#include  <stdio.h>
#include  <algorithm>
#include  <queue>
using namespace std;

struct node
{
	int pos;
	int parent;
	int left_child;
	int right_child;
	node():pos(0),parent(-1),left_child(-1),right_child(-1){}
};

node node_array[101];
int num_array[101];
int order_array[101];
int index;

void inorder(int i)
{
	if(i==-1)
		return;
	inorder(node_array[i].left_child);
	order_array[index++]=i;
	inorder(node_array[i].right_child);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			int left,right;
			scanf("%d%d",&left,&right);
			if(left!=-1)
			{
				node_array[i].left_child=left;
				node_array[left].parent=i;
			}
			if(right!=-1)
			{
				node_array[i].right_child=right;
				node_array[right].parent=i;
			}
		}
		for(int i=0;i<n;++i)
			scanf("%d",&num_array[i]);
		sort(num_array,num_array+n);
		index=0;
		inorder(0);
		for(int i=0;i<n;++i)
			node_array[order_array[i]].pos=i;
		bool first=true;
		queue<int> node_queue;
		node_queue.push(0);
		while(!node_queue.empty())
		{
			int front=node_queue.front();
			node_queue.pop();
			if(first)
				first=false;
			else
				printf(" ");
			printf("%d",num_array[node_array[front].pos]);
			if(node_array[front].left_child!=-1)
				node_queue.push(node_array[front].left_child);
			if(node_array[front].right_child!=-1)
				node_queue.push(node_array[front].right_child);
		}
		printf("\n");
	}
	return 0;
}