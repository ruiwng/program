#include  <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

bool symmetric(struct TreeNode *lhs,struct TreeNode *rhs)
{
	if(lhs==NULL&&rhs==NULL)
		return true;
	else if(lhs!=NULL&&rhs!=NULL&&lhs->val==rhs->val)
		return symmetric(lhs->left,rhs->right)&&symmetric(lhs->right,rhs->left);
	else
		return false;
}

bool isSymmetric(struct TreeNode *root) {
    if(root==NULL)
		return true;
	return symmetric(root->left,root->right);
}

int main()
{

}