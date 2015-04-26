#include  <stdio.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};
int s;
bool flag;
void preorder(struct TreeNode *n,int value)
{
	if(n->left==NULL&&n->right==NULL)
	{
		if(value+n->val==s)
			flag=true;
		return;
	}
	if(n->left!=NULL)
		preorder(n->left,value+n->val);
	if(n->right!=NULL)
		preorder(n->right,value+n->val);
}
bool hasPathSum(struct TreeNode *root, int sum) {
    s=sum;
	flag=false;
	if(root)
		preorder(root,0);
	return flag;
}

int main()
{

}