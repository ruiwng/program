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
		queue<TreeLinkNode*> node_queue;
		unordered_map<TreeLinkNode*,int> layer_info;
		node_queue.push(root);
		int current_depth=-1;
		TreeLinkNode *current_pos=new TreeLinkNode(0);
		layer_info[root]=0;
		while(!node_queue.empty())
		{
			TreeLinkNode *front=node_queue.front();
			node_queue.pop();
			int temp=layer_info[front];
			if(temp>current_depth)
			{
				current_pos->next=NULL;
				current_pos=front;
				current_depth=temp;
			}
			else
			{
				current_pos->next=front;
				current_pos=front;
			}
			if(front->left!=NULL)
			{
				layer_info[front->left]=temp+1;
				node_queue.push(front->left);
			}
			if(front->right!=NULL)
			{
				layer_info[front->right]=temp+1;
				node_queue.push(front->right);
			}
		}
    }
};

int main()
{

}