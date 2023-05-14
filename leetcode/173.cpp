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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        TreeNode* p = root;
        while (p != nullptr) {
            mTreeNodes.push(p);
            p = p->left;
        }
    }

    int next() {
        if (mTreeNodes.empty()) {
            return 0;
        }
        TreeNode* p = mTreeNodes.top();
        mTreeNodes.pop();
        TreeNode* q = p->right;
        while (q != nullptr) {
            mTreeNodes.push(q);
            q = q->left;
        }
        return p->val;
    }

    bool hasNext() {
        return !mTreeNodes.empty();
    }
    std::stack<TreeNode*> mTreeNodes;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
 
 int main() {
 }
