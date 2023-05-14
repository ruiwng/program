#include <vector>
#include <stack>
#include <iostream>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode *p = root;
        while(true) {
            while(p != nullptr) {
                nodeStack.push(p);
                p = p->left;
            }
            if(nodeStack.empty()) {
                break;
            }
            p = nodeStack.top();
            result.push_back(p->val);
            nodeStack.pop();
            p = p->right;
        }
        return result;
    }
   TreeNode* deleteNode(TreeNode* root, int key) {
       if(root == nullptr) {
           return nullptr;
       }
       TreeNode* new_root = new TreeNode(0, root, nullptr);
       TreeNode* p_parent = new_root;
       bool isLeft = true;
       TreeNode* p = root;
       while(p) {
           if(p->val == key) {
               break;
           }
           if(p->val > key) {
               p_parent = p;
               p = p->left;
               isLeft = true;
           } else {
               p_parent = p;
               p = p->right;
               isLeft = false;
           }
       }
       if(p == nullptr) {
           delete new_root;
           return root;
       }
       if(!p->left && !p->right) {
           if(isLeft) {
               p_parent->left = nullptr;
           } else {
               p_parent->right = nullptr;
           }
       } else if(p->left && !p->right) {
           if(isLeft) {
               p_parent->left = p->left;
           } else {
               p_parent->right = p->left;
           }
       } else if(!p->left && p->right) {
           if(isLeft) {
               p_parent->left = p->right;
           } else {
               p_parent->right = p->right;
           }
       } else {
           if(isLeft) {
               p_parent->left = p->left;
           } else {
               p_parent->right = p->left;
           }
           TreeNode* q = p->left;
           while(q->right) {
               q = q->right;
           }
           q->right = p->right;
       }
       auto r = new_root->left;
       delete new_root;
       return r;
   }
};

int main() {
    TreeNode* p0 = new TreeNode(2);
    TreeNode* p1 = new TreeNode(4);
    TreeNode* p2 = new TreeNode(3, p0, p1);
    TreeNode* p3 = new TreeNode(7);
    TreeNode* p4 = new TreeNode(6, nullptr, p3);
    TreeNode* root = new TreeNode(5, p2, p4);
    Solution s;
    auto r = s.deleteNode(root, 0);
    auto result = s.inorderTraversal(r);
    for(int i = 0; i < result.size(); ++i) {
        cout << " " << result[i];
    }
    cout << endl;
    return 0;
}
