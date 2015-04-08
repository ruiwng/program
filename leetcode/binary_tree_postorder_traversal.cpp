#include  <vector>
#include  <deque>
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
    vector<int> postorderTraversal(TreeNode *root) {
        deque<int> result;
		stack<TreeNode*> node_stack;
		if(root!=NULL)
			node_stack.push(root);
		while(!node_stack.empty())
		{
			TreeNode *top=node_stack.top();
			node_stack.pop();
			if(top->left!=NULL)
				node_stack.push(top->left);
			if(top->right!=NULL)
				node_stack.push(top->right);
			result.push_front(top->val);
		}
		return vector<int>(result.begin(),result.end());
    }
};

int main()
{
	TreeNode *head=new TreeNode(1);
	head->right=new TreeNode(2);
	head->right->left=new TreeNode(3);
	Solution s;
	vector<int> result=s.postorderTraversal(head);
	return 0;
}