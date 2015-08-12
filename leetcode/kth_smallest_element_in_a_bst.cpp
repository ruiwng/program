#include  <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> node_stack;
		while(true)
		{
			while(root != NULL)
			{
				node_stack.push(root);
				root = root->left;
			}
			root = node_stack.top();
			node_stack.pop();
			if(--k == 0)
				return root->val;
			root = root->right;
		}
    }
};

int main()
{

}