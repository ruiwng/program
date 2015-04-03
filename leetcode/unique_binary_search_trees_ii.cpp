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
    vector<TreeNode *> generateTrees(int n) {
        trees_array.assign(n+1,vector<TreeNode*>());
		trees_array[0].push_back(NULL);
		if(n>0)
		    trees_array[1].push_back(new TreeNode(1));
		for(int i=2;i<=n;++i)
		{
			for(int j=0;j<i;++j)
			{
				vector<TreeNode*> left_tree=get_trees(0,j);
				vector<TreeNode*> right_tree=get_trees(j+1,i-1-j);
				int left_len=left_tree.size();
				int right_len=right_tree.size();
				for(int x=0;x<left_len;++x)
				  for(int y=0;y<right_len;++y)
				  {
					  TreeNode *head=new TreeNode(j+1);
					  head->left=left_tree[x];
					  head->right=right_tree[y];
					  trees_array[i].push_back(head);
				  }
			}
		}
		return trees_array[n];
    }
private:
	vector<TreeNode*> get_trees(int start,int n)
	{
		begin=start;
		int len=trees_array[n].size();
		vector<TreeNode*> result(len);
		for(int i=0;i<len;++i)
			copy_tree(result[i],trees_array[n][i]);
		return result;
	}
private:
	void copy_tree(TreeNode *&dest,TreeNode *source)
	{
		if(source!=NULL)
		{
			dest=new TreeNode(begin+source->val);
			copy_tree(dest->left,source->left);
			copy_tree(dest->right,source->right);
		}
	}
private:
	int begin;
	vector<vector<TreeNode*> > trees_array;
};

int main()
{
	Solution s;
	vector<TreeNode*> m=s.generateTrees(0);
	return 0;
}