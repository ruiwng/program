#include <queue>
#include <unordered_map>
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
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        queue<TreeNode*> nodeQueue;
        unordered_map<TreeNode*, int> nodeLevelMap;
        nodeQueue.push(root);
        nodeLevelMap[root] = 0;
        int maxLevel = -1;
        int leftValue = 0;
        while(!nodeQueue.empty()) {
            auto p = nodeQueue.front();
            nodeQueue.pop();
            auto iter = nodeLevelMap.find(p);
            auto level = iter->second;
            nodeLevelMap.erase(iter);
            if(p->left != nullptr) {
                nodeQueue.push(p->left);
                nodeLevelMap[p->left] = level + 1;
            }
            if(p->right != nullptr) {
                nodeQueue.push(p->right);
                nodeLevelMap[p->right] = level + 1;
            }
            if(p->left == nullptr && p->right == nullptr && level > maxLevel) {
                maxLevel = level;
                leftValue = p->val;
            }
        }
        return leftValue;
    }
};
