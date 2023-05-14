#include <deque>
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
    int pathSum(TreeNode* root, int targetSum) {
        mTargetSum = targetSum;
        mPathSumCount = 0;
        traverse(root);
        return mPathSumCount;
    }
    
    void traverse(TreeNode* p) {
        if(p == nullptr) {
            return;
        }
        mPathValues.push_back(p->val);
        long long sum = 0;
        for(auto iter = mPathValues.rbegin(); iter != mPathValues.rend(); ++iter) {
            sum += *iter;
            if(sum == mTargetSum) {
                ++mPathSumCount;
            }
        }
        traverse(p->left);
        traverse(p->right);
        mPathValues.pop_back();
    }
    
private:
    deque<int> mPathValues;
    int mTargetSum;
    int mPathSumCount;
};

int main() {
    
}
