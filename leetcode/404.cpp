#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        TreeNode *p = root;
        stack<TreeNode*> nodeStack;
        int sum = 0;
        while(true) {
            int loop_count = 0;
            while(p != nullptr) {
                nodeStack.push(p);
                p = p->left;
                ++loop_count;
            }
            if(nodeStack.empty()) {
                break;
            }
            TreeNode* q = nodeStack.top();
            if(loop_count > 1 && q->right == nullptr) {
                sum += q->val;
            }
            nodeStack.pop();
            p = q->right;
        }
        return sum;
    }
};

int main() {
    TreeNode* p0 = new TreeNode(15);
    TreeNode* p1 = new TreeNode(7);
    TreeNode* p2 = new TreeNode(20, p0, p1);
    TreeNode* p3 = new TreeNode(9);
    TreeNode* root = new TreeNode(3, p3, p2);
    Solution s;
    int sum = s.sumOfLeftLeaves(root);
    return 0;
}
