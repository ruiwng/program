#include  <stdio.h>
#include  <vector>
using namespace std;

struct NODE
{
	int number;
	NODE* left;
	NODE* right;
	NODE(int num,NODE* lt=NULL,NODE* rt=NULL):number(num),left(lt),right(rt){}
};

void BST_insert(NODE*& root,int x)
{
	if(root==NULL)
	{
		root=new NODE(x);
		return;
	}
	if(x<root->number)
		BST_insert(root->left,x);
	else
		BST_insert(root->right,x);
}

bool BST_preorder(NODE* root,vector<int>& array,unsigned int& index)
{
	if(root->number!=array[index++])
		return false;
	if(root->left!=NULL)
		return BST_preorder(root->left,array,index);		
	if(root->right!=NULL)
		return BST_preorder(root->right,array,index);
	return true;
}

bool BST_mirror_preorder(NODE* root,vector<int>& array,unsigned int& index)
{
	if(root->number!=array[index++])
		return false;
	if(root->right!=NULL)
		return BST_mirror_preorder(root->right,array,index);
	if(root->left!=NULL)
		return BST_mirror_preorder(root->left,array,index);		
	return true;
}

void BST_postorder(NODE* root)
{
	static bool first_time=true;
	if(root->left!=NULL)
		BST_postorder(root->left);
	if(root->right!=NULL)
		BST_postorder(root->right);
	if(first_time)
	{
		printf("%d",root->number);
		first_time=false;
	}
	else
		printf(" %d",root->number);
}

void BST_mirror_postorder(NODE* root)
{
	static bool first_time=true;
	if(root->right!=NULL)
		BST_mirror_postorder(root->right);
	if(root->left!=NULL)
		BST_mirror_postorder(root->left);	
	if(first_time)
	{
		printf("%d",root->number);
		first_time=false;
	}
	else
		printf(" %d",root->number);
}
int main()
{
	unsigned int num_node;
	while(scanf("%u",&num_node)!=EOF)
	{
		vector<int> node_array(num_node);
		NODE* root=NULL;
		for(unsigned int i=0;i<num_node;i++)
		{
			int node_temp;
			scanf("%d",&node_temp);
			node_array[i]=node_temp;
			BST_insert(root,node_temp);
		}
		unsigned int index=0;
		bool BST_order=BST_preorder(root,node_array,index);
		index=0;
		bool BST_mirror_order=BST_mirror_preorder(root,node_array,index);
		if(BST_order)
		{
			printf("YES\n");
			BST_postorder(root);
			printf("\n");
		}
		else if(BST_mirror_order)
		{
			printf("YES\n");
			BST_mirror_postorder(root);
			printf("\n");
		}
		else
		    printf("NO\n");
	}
	return 0;
}