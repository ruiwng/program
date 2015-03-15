#include  <stdio.h>
#include  <string.h>
#include  <stack>
using namespace std;

struct node
{
	int element;
	node *left;
	node *right;
	node(int e=0):element(e),left(NULL),right(NULL){}
};

bool first;
void post_order(node *n)
{
	if(n!=NULL)
	{
		post_order(n->left);
		post_order(n->right);
		if(first)
			first=false;
		else
			printf(" ");
		printf("%d",n->element);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		node *head=NULL,*p;
		bool tag=true;
		stack<node*> node_stack;
		while(true)
		{
			char str[10];
			scanf("%s",str);
			if(strcmp(str,"Push")==0)
			{
				int num;
				--n;
				scanf("%d",&num);
				node *q=new node(num);
				if(head==NULL)
					head=q;
				else
				{
					if(tag)
						p->left=q;
					else
						p->right=q;
					tag=true;
				}
				p=q;
				node_stack.push(q);
			}
			else
			{
				tag=false;
				p=node_stack.top();
				node_stack.pop();
				if(node_stack.empty()&&n==0)
					break;
			}
		}
		first=true;
		post_order(head);
		printf("\n");
	}
	return 0;
}
