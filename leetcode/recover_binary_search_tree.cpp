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
    void recoverTree(TreeNode *root) {
        stack<TreeNode*> node_stack;
		node_stack.push(root);
		TreeNode *first=NULL,*second=NULL;
		TreeNode* prev=NULL;
		bool flag=true;
		while(!node_stack.empty())
		{
		     while(flag&&node_stack.top()->left!=NULL)
				 node_stack.push(node_stack.top()->left);
			 TreeNode* temp=node_stack.top();
			 node_stack.pop();
			 flag=false;
			 if(prev!=NULL&&prev->val>temp->val)
			 {
				 if(first==NULL)
				 {
					 first=prev;
					 second=temp;
				 }
				 else if(first!=NULL)
				 {
					 second=temp;
					 break;
				 }
			 }
			 prev=temp;
			 if(temp->right!=NULL)
			 {
				 flag=true;
				 node_stack.push(temp->right);
			 }
		}
		int num=first->val;
		first->val=second->val;
		second->val=num;
    }
};

int main()
{
	TreeNode* root=new TreeNode(0);
	root->left=new TreeNode(1);
	Solution s;
	s.recoverTree(root);
	return 0;
}