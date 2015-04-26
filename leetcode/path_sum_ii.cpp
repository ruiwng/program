#include  <stdio.h>
#include  <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        s=sum;
		path.clear();
		path_array.clear();
		if(root!=NULL)
			preorder(root,0);
		return path_array;
    }
private:
	void preorder(TreeNode *n,int value)
	{
		path.push_back(n->val);
		if(n->left==NULL&&n->right==NULL)
		{
			if(value+n->val==s)
				path_array.push_back(path);
		}
		else
		{
			if(n->left!=NULL)
			   preorder(n->left,value+n->val);
		    if(n->right!=NULL)
			   preorder(n->right,value+n->val);
		}
		path.pop_back();
	}
private:
	int s;
	vector<int> path;
	vector<vector<int> > path_array;
};

int main()
{
	TreeNode *root=new TreeNode(5);
	root->left=new TreeNode(4);
	root->right=new TreeNode(8);
	root->left->left=new TreeNode(11);
	root->left->left->left=new TreeNode(7);
	root->left->left->right=new TreeNode(2);
	root->right->left=new TreeNode(13);
	root->right->right=new TreeNode(4);
	root->right->right->left=new TreeNode(5);
	root->right->right->right=new TreeNode(1);
	Solution s;
	vector<vector<int> > result=s.pathSum(root,22);
	return 0;
}