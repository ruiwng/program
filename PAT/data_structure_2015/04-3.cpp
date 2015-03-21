#include  <stdio.h>
#include  <algorithm>
using namespace std;

struct node
{
	int element;
	node *parent;
	int depth;
	node *left_child;
	node *right_child;
	node(int e=0,node *p=NULL):element(e),parent(p),depth(1),left_child(NULL),right_child(NULL){}
};

inline int get_depth(node *p)
{
	return p==NULL?0:p->depth;
}

node* left_rotation(node *p)
{
	node *q=p->right_child;
	q->parent=p->parent;
	if(p->parent->left_child==p)
		p->parent->left_child=q;
	else
		p->parent->right_child=q;
	p->right_child=q->left_child;
	if(q->left_child!=NULL)
	    q->left_child->parent=p;
	q->left_child=p;
	p->parent=q;
	p->depth=max(get_depth(p->left_child),get_depth(p->right_child))+1;
	q->depth=max(get_depth(q->left_child),get_depth(q->right_child))+1;
	return q;
}

node* right_rotation(node *p) 
{
	node *q=p->left_child;
	q->parent=p->parent;
	if(p->parent->left_child==p)
		p->parent->left_child=q;
	else
		p->parent->right_child=q;
	p->left_child=q->right_child;
	if(q->right_child!=NULL)
	   q->right_child->parent=p;
	q->right_child=p;
	p->parent=q;
	p->depth=max(get_depth(p->left_child),get_depth(p->right_child))+1;
	q->depth=max(get_depth(q->left_child),get_depth(q->right_child))+1;
	return q;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		node *root=new node;
		while(n--!=0)
		{
			int temp;
			scanf("%d",&temp);
			if(root->left_child==NULL)
				root->left_child=new node(temp,root);
			else
			{
				node *p=root->left_child;
				while(true)
				{
					if(p->element<temp)
					{
						if(p->right_child==NULL)
						{
							p->right_child=new node(temp,p);
							break;
						}
						else
							p=p->right_child;
					}
					else
					{
						if(p->left_child==NULL)
						{
							p->left_child=new node(temp,p);
							break;
						}
						else
							p=p->left_child;
					}
				}
				while(true)
				{
					int left_depth=get_depth(p->left_child);
					int right_depth=get_depth(p->right_child);
					if(left_depth-right_depth>1)
					{
						node *q=p->left_child;
						if(get_depth(q->left_child)<get_depth(q->right_child))
							left_rotation(q);
						p=right_rotation(p);
					}
					else if(right_depth-left_depth>1)
					{
						node *q=p->right_child;
						if(get_depth(q->left_child)>get_depth(q->right_child))
							right_rotation(q);
						p=left_rotation(p);
					}
					else
						p->depth=max(left_depth,right_depth)+1;
					p=p->parent;
					if(p==root)
						break;
				}
			}
		}
		printf("%d\n",root->left_child->element);
	}
	return 0;
}