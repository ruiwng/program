#include  <vector>
#include  <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root){
		stack<TreeNode*> node_stack;
		vector<int> result;
		while(!node_stack.empty()||root!=NULL)
		{
			if(root!=NULL)
			{
				node_stack.push(root);
				root=root->left;
			}
			else
			{
				TreeNode *top=node_stack.top();
				node_stack.pop();
				result.push_back(top->val);
				root=top->right;
			}
		}
		return result;
	}
};

int main()
{
	TreeNode *root=new TreeNode(1);
	Solution s;
	vector<int> result=s.inorderTraversal(root);
	return 0;
}