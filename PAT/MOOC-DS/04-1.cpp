#include  <stdio.h>

struct tree_node
{
	int data;
	tree_node* left_child;
	tree_node* right_child;
	int bf;

	tree_node(int d,tree_node* lt=NULL,tree_node* rt=NULL,int h=0):
		data(d),left_child(lt),right_child(rt),bf(h){}
};

void left_rotation(tree_node*& parent)
{
	tree_node* child=parent->left_child;
	if(child->bf==1)
	{
		parent->left_child=child->right_child;
		child->right_child=parent;
		parent->bf=0;
		parent=child;
	}
	else
	{
		tree_node* grand_child=child->right_child;
		parent->left_child=grand_child->right_child;
		child->right_child=grand_child->left_child;
		grand_child->right_child=parent;
		grand_child->left_child=child;
		switch(grand_child->bf)
		{
		case 0:
			parent->bf=child->bf=0;
			break;
		case 1:
			parent->bf=-1;
			child->bf=0;
			break;
		case -1:
			parent->bf=0;
			child->bf=1;
		}
		parent=grand_child;
	}
	parent->bf=0;
}

void right_rotation(tree_node*& parent)
{
	tree_node* child=parent->right_child;
	if(child->bf==-1)
	{
		parent->right_child=child->left_child;
		child->left_child=parent;
		parent->bf=0;
		parent=child;
	}
	else
	{
		tree_node* grand_child=child->left_child;
		parent->right_child=grand_child->left_child;
		child->left_child=grand_child->right_child;
		grand_child->right_child=child;
		grand_child->left_child=parent;
		switch(grand_child->bf)
		{
		case 0:
			parent->bf=child->bf=0;
			break;
		case -1:
			parent->bf=1;
			child->bf=0;
			break;
		case 1:
			parent->bf=0;
			child->bf=-1;
		}
		parent=grand_child;
	}
	parent->bf=0;
}

void avl_insert(tree_node*& parent,int x,bool& unbalanced)
{
	if(parent==NULL)
	{
		parent=new tree_node(x);
		unbalanced=true;
	}
	else if(x<parent->data)
	{
		avl_insert(parent->left_child,x,unbalanced);
		if(unbalanced)
		{
			switch(parent->bf)
			{
			case 0:
				parent->bf=1;
				break;
			case -1:
				parent->bf=0;
				unbalanced=false;
				break;
			case 1:
				left_rotation(parent);
				unbalanced=false;
			}
		}
	}
	else if(x>parent->data)
	{
		avl_insert(parent->right_child,x,unbalanced);
		if(unbalanced)
		{
			switch(parent->bf)
			{
			case 0:
				parent->bf=-1;
				break;
			case 1:
				parent->bf=0;
				unbalanced=false;
				break;
			case -1:
				right_rotation(parent);
					unbalanced=false;
			}
		}
	}
	else
		unbalanced=false;
}

int main()
{
    int num;
	while(scanf("%d",&num)!=EOF)
	{
		tree_node* root=NULL;
		for(int i=0;i<num;++i)
		{
			bool flag=false;
			int temp;
			scanf("%d",&temp);
			avl_insert(root,temp,flag);
		}
		printf("%d\n",root->data);
	}
	return 0;
}
