#include <vector>
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
    TreeNode* generateTree(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
        if(pre_start >= pre_end) {
            return nullptr;
        }
        int k = in_start;
        while(k < in_end && inorder[k] != preorder[pre_start]) {
            ++k;
        }
        int left_length = k - in_start;
        auto left_child = generateTree(preorder, inorder, pre_start + 1, pre_start + left_length + 1, in_start, in_start + left_length);
        auto right_child = generateTree(preorder, inorder, pre_start + left_length + 1, pre_end, in_start + left_length + 1, in_end);
        return new TreeNode(preorder[pre_start], left_child, right_child);
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int length = static_cast<int>(preorder.size());
        if(length == 0) {
            return nullptr;
        }
        return generateTree(preorder, inorder, 0, length, 0, length);
    }
};

int main() {
    
}
