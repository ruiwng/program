#include  <stdio.h>
#include  <algorithm>
#include  <queue>
using namespace std;

int arry[1001];

struct node
{
	int element;
	node *left_child;
	node *right_child;
	node(int e=0,node *lhs=NULL,node *rhs=NULL):element(e),left_child(lhs),right_child(rhs){}
};

node *generate_tree(int start,int end)
{
	if(start>end)
		return NULL;
	if(start==end)
		return new node(arry[start]);
	int num=end-start;
	int count_num=1,left_num,right_num;
	while(true)
	{
		left_num=count_num-1;
		right_num=num-left_num;
		if(left_num>=right_num&&right_num>=((count_num>>1)-1))
			break;
		else if(right_num>=left_num&&right_num<=((count_num<<1)-1))
		{
			int temp=left_num;
			left_num=right_num;
			right_num=temp;
			break;
		}
		count_num<<=1;
	}
	int pos=start+left_num;
	return new node(arry[pos],generate_tree(start,pos-1),generate_tree(pos+1,end));
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&arry[i]);
		sort(arry,arry+n);
		node *root=generate_tree(0,n-1);
		queue<node*> node_queue;
		node_queue.push(root);
		bool first=true;
		while(!node_queue.empty())
		{
			node *front=node_queue.front();
			node_queue.pop();
			if(first)
				first=false;
			else
				printf(" ");
			printf("%d",front->element);
			if(front->left_child!=NULL)
				node_queue.push(front->left_child);
			if(front->right_child!=NULL)
				node_queue.push(front->right_child);
		}
		printf("\n");
	}
	return 0;
}