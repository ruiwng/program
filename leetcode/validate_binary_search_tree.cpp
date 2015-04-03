#include  <stdlib.h>
#include  <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool is_valid(struct TreeNode *root,long long min,long long max)
{
	if(root!=NULL)
	{
		if(root->val<=min||root->val>=max)
			return false;
		return is_valid(root->left,min,root->val)&&is_valid(root->right,root->val,max);
	}
	else
		return true;
}

bool isValidBST(struct TreeNode *root) {
    return is_valid(root,LLONG_MIN,LLONG_MAX);
}

int main()
{

}