#include  <vector>
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
    vector<int> preorderTraversal(TreeNode *root) {
		stack<TreeNode*> node_stack;
		vector<int> result;
		while(!node_stack.empty()||root!=NULL)
		{
			if(root!=NULL)
			{
				result.push_back(root->val);
				if(root->right!=NULL)
					node_stack.push(root->right);
				root=root->left;
			}
			else
			{
				root=node_stack.top();
				node_stack.pop();
			}
		}
		return result;
    }
};

int main()
{

}