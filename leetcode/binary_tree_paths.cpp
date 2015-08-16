#include  <vector>
#include  <string>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
		if(root != NULL)
			preorder(root, result);
		return result;
    }
private:
	void preorder(TreeNode *root, vector<string> &result)
	{
		char temp[100];
		sprintf(temp, "->%d", root->val);
		str += temp;
		if(root->left == NULL && root->right == NULL)
			result.push_back(string(str.begin() + 2, str.end()));
		if(root->left != NULL)
			preorder(root->left, result);
		if(root->right != NULL)
			preorder(root->right, result);
		str.erase(str.rfind("->"));
	}
private:
	string str;
};

int main()
{
	TreeNode *root = new TreeNode(37);
	root->left = new TreeNode(-34);
	root->left->right = new TreeNode(-100);
	root->right = new TreeNode(-48);
	root->right->left = new TreeNode(-100);
	root->right->right = new TreeNode(48);
	root->right->right->left = new TreeNode(-54);
	root->right->right->left->left = new TreeNode(-71);
	root->right->right->left->right = new TreeNode(-22);
	root->right->right->left->right->right = new TreeNode(8);
	Solution s;
	vector<string> result = s.binaryTreePaths(root);
	return 0;
}