#include  <vector>
#include  <queue>
#include  <unordered_map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
		vector<int> result;
		if(root==NULL)
			return result;
		unordered_map<TreeNode*,int> depth_record;
        queue<TreeNode*> node_queue;
		node_queue.push(root);
		depth_record.insert(make_pair(root,1));
		int current_depth=0;
		while(!node_queue.empty())
		{
			TreeNode *front=node_queue.front();
			node_queue.pop();
			int temp=depth_record[front];
			if(temp>current_depth)
			{
				result.push_back(front->val);
				current_depth=temp;
			}
			if(front->right!=NULL)
			{
				depth_record.insert(make_pair(front->right,temp+1));
				node_queue.push(front->right);
			}
			if(front->left!=NULL)
			{
				depth_record.insert(make_pair(front->left,temp+1));
				node_queue.push(front->left);
			}
		}
		return result;
    }
};

int main()
{
	TreeNode *root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->left->right=new TreeNode(5);
	root->right=new TreeNode(3);
	root->right->right=new TreeNode(4);
	Solution s;
	vector<int> result=s.rightSideView(root);
	return 0;
}