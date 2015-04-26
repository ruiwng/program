#include  <queue>
#include  <unordered_map>
using namespace std;

 struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {
		if(root==NULL)
			return;
        TreeLinkNode *current_node=new TreeLinkNode(0);
		int current_layer=-1;
		queue<TreeLinkNode*> node_queue;
		node_queue.push(root);
		layer_info.insert(make_pair(root,0));
		while(!node_queue.empty())
		{
			TreeLinkNode *t=node_queue.front();
			node_queue.pop();
			int layer_num=layer_info[t];
			if(layer_num>current_layer)
			{
				current_node->next=NULL;
				current_layer=layer_num;
			}
			else
			    current_node->next=t;
			current_node=t;
			if(t->left!=NULL)
			{
				layer_info.insert(make_pair(t->left,layer_num+1));
				node_queue.push(t->left);
			}
			if(t->right!=NULL)
			{
				layer_info.insert(make_pair(t->right,layer_num+1));
				node_queue.push(t->right);
			}
		}
    }
private:
	unordered_map<TreeLinkNode*,int> layer_info;
};

int main()
{

}