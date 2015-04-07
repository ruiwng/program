struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int max_value;
bool first;
int max_func(struct TreeNode* root)
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
        int temp=(lhs>=rhs?lhs:rhs);
        if(temp>0)
            return root->val+temp;
        else
            return root->val;
}
int maxPathSum(struct TreeNode *root) {
        first=true;
        max_func(root);
        return max_value;
    }

int main()
{
	
}