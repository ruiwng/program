/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
	bool removeLeafRecursively(TreeNode* node) {
		if (node == nullptr) {
			return true;
		}
		bool l = removeLeafRecursively(node->left);
		if (l) { node->left = nullptr; }
		bool r = removeLeafRecursively(node->right);
		if (r) { node->right = nullptr; }
		if (l && r && node->val == mTarget) {
			return true;
		}
		return false;
	}
public:
	TreeNode* removeLeafNodes(TreeNode* root, int target) {
		mTarget = target;
		bool r = removeLeafRecursively(root);
		return r ? nullptr : root;
	}
private:
	int mTarget;
};

int main() {
}
