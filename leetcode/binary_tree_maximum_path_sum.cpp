#include  <stdio.h>
#include  <algorithm>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        first=true;
        max_func(root);
        return max_value;
    }
private:
    int max_func(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lhs=max_func(root->left);
        int rhs=max_func(root->right);
        int current_max=root->val;
        if(lhs>0)
            current_max+=lhs;
        if(rhs>0)
            current_max+=rhs;            
        if(first||current_max>max_value)
        {
            first=false;
            max_value=current_max;
        }
        int temp=max(lhs,rhs);
        if(temp>0)
            return root->val+temp;
        else
            return root->val;
    }
private:
    int max_value;
    bool first;
};

int main()
{
    TreeNode* root=new TreeNode(-1);
    root->left=new TreeNode(2);
    Solution s;
    int result=s.maxPathSum(root);
    printf("%d\n",result);
    return 0;
}
