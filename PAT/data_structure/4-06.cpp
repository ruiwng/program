#include  <stdio.h>
#include  <vector>
using namespace std;

struct BST_node
{
	int element;
	BST_node* left_child;
	BST_node* right_child;
	BST_node(int e,BST_node* lhs=NULL,BST_node* rhs=NULL):element(e),left_child(lhs),
		right_child(rhs){}
};

void BST_insert(BST_node*& head,int element)
{
	if(head==NULL)
		head=new BST_node(element);
	else if(element<head->element)
		BST_insert(head->left_child,element);
	else
		BST_insert(head->right_child,element);
}

bool is_inorder(BST_node* head,vector<int>& num_array,unsigned int& current_index)
{
	if(head==NULL)
		return true;
	bool temp1=(head->element==num_array[current_index++]);
	bool temp2=is_inorder(head->left_child,num_array,current_index);
	bool temp3=is_inorder(head->right_child,num_array,current_index);
	return temp1&&temp2&&temp3;
}

bool is_mirror_inorder(BST_node* head,vector<int>& num_array,unsigned int& current_index)
{
	if(head==NULL)
		return true;
	bool temp1=(head->element==num_array[current_index++]);
	bool temp2=is_mirror_inorder(head->right_child,num_array,current_index);
	bool temp3=is_mirror_inorder(head->left_child,num_array,current_index);
	return temp1&&temp2&&temp3;
}

void post_order(BST_node* head,bool& first)
{
     if(head->left_child!=NULL)
		 post_order(head->left_child,first);
	 if(head->right_child!=NULL)
		 post_order(head->right_child,first);
	 if(first)
		 first=false;
	 else
		 printf(" ");
	 printf("%d",head->element);
}

void mirror_post_order(BST_node* head,bool& first)
{
	if(head->right_child!=NULL)
		mirror_post_order(head->right_child,first);
	if(head->left_child!=NULL)
		mirror_post_order(head->left_child,first);
	if(first)
		first=false;
	else
		printf(" ");
	printf("%d",head->element);
}

int main()
{
	unsigned int num;
	while(scanf("%u",&num)!=EOF)
	{
		BST_node* head=NULL; 
		vector<int> num_array(num);
		for(unsigned int i=0;i<num;++i)
		{
			scanf("%d",&num_array[i]);
		    BST_insert(head,num_array[i]);
		}
		unsigned int current_value1=0,current_value2=0;
		if(is_inorder(head,num_array,current_value1))
		{
			printf("YES\n");
			bool first=true;
			post_order(head,first);
			printf("\n");
		}
		else if(is_mirror_inorder(head,num_array,current_value2))
		{
			printf("YES\n");
			bool first=true;
			mirror_post_order(head,first);
			printf("\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}