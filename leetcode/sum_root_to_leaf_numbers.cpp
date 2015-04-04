#include  <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int sum;

void inorder(struct TreeNode *root,int n)
{
	if(root->left==NULL&&root->right==NULL)
		sum+=n*10+root->val;
	else
	{
		if(root->left!=NULL)
			inorder(root->left,n*10+root->val);
		if(root->right!=NULL)
			inorder(root->right,n*10+root->val);
	}
}

int sumNumbers(struct TreeNode *root) {
    sum=0;
	if(root!=NULL)
		inorder(root,0);
	return sum;
}

int main()
{
	struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val=1;
	root->left=(struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->left->val=2;
	root->left->left=NULL;
	root->left->right=NULL;
	root->right=(struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->right->val=3;
	root->right->left=NULL;
	root->right->right=NULL;
	int sum=sumNumbers(root);
	return 0;
}