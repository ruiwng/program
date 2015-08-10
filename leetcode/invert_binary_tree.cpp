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
    TreeNode* invertTree(TreeNode* root) {
        if(root != NULL)
		{
			TreeNode *temp = new TreeNode(root->val);
			temp->left = invertTree(root->right);
			temp->right = invertTree(root->left);
			return temp;
		}
		else
			return NULL;
    }
};

int main()
{

}