#include  <functional>
using namespace std;

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct result
{
	struct TreeNode *pointer;
	bool ancestor1;
	bool ancestor2;
};

struct result common_ancestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q)
{
	struct result temp;
	temp.pointer = NULL;
	temp.ancestor1 = false;
	temp.ancestor2 = false;
	if(root != NULL)
	{
		temp = common_ancestor(root->left, p, q);
		if(!(temp.ancestor1 == true && temp.ancestor2 == true))
		{
			struct result temp2 = common_ancestor(root->right, p, q);
			if(temp2.ancestor1 && temp2.ancestor2)
				return temp2;
			if(temp2.ancestor1)
				temp.ancestor1 = true;
			if(temp2.ancestor2)
				temp.ancestor2 = true;
		}
		else
			return temp;
	}
	if(root == p)
		temp.ancestor1 = true;
	else if(root == q)
		temp.ancestor2 = true;
	if(temp.ancestor1 && temp.ancestor2)
		temp.pointer = root;
	return temp;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	struct result temp =  common_ancestor(root, p, q);
	return temp.pointer;
}

int main()
{
	
}