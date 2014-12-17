#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <queue>
using namespace std;

struct NODE
{
	unsigned int number;
	NODE* left;
	NODE* right;
	NODE(unsigned int num,NODE* lt=NULL,NODE* rt=NULL):number(num),left(lt),right(rt){}
};
/*
NODE* generate_tree(vector<int> post_order,vector<int> in_order)
{
	if(post_order.empty())
		return NULL;
	vector<int>::iterator iter=find(in_order.begin(),in_order.end(),post_order.back());
	NODE* node=new NODE(post_order.back());
	vector<int>::iterator iter_temp=post_order.begin()+(iter-in_order.begin());
	node->left=generate_tree(vector<int>(post_order.begin(),iter_temp),
		vector<int>(in_order.begin(),iter));
	node->right=generate_tree(vector<int>(iter_temp,post_order.end()-1),vector<int>(++iter,in_order.end()));
	return node;
}
*/
NODE* generate_tree(vector<int>& post_order,vector<int>::iterator post_begin,vector<int>::iterator post_end,
					vector<int>& in_order,vector<int>::iterator in_begin,vector<int>::iterator in_end)
{
	if(post_begin==post_end)
		return NULL;
	vector<int>::iterator iter_temp=post_end;
	NODE* node=new NODE(*(--iter_temp));
	vector<int>::iterator in_iter=find(in_begin,in_end,*iter_temp);
	vector<int>::iterator post_iter=post_begin+(in_iter-in_begin);
	node->left=generate_tree(post_order,post_begin,post_iter,in_order,in_begin,in_iter);
	node->right=generate_tree(post_order,post_iter,iter_temp,in_order,++in_iter,in_end);
	return node;
}

int main()
{
	unsigned int node_number;
	while(scanf("%u",&node_number)!=EOF)
	{
		vector<int> post_order,in_order;
		for(unsigned int i=0;i<node_number;i++)
		{
			unsigned int node_temp;
			scanf("%d",&node_temp);
			post_order.push_back(node_temp);
		}
		for(unsigned int i=0;i<node_number;i++)
		{
			unsigned int node_temp;
			scanf("%d",&node_temp);
			in_order.push_back(node_temp);
		}
		NODE* root=generate_tree(post_order,post_order.begin(),post_order.end(),in_order,in_order.begin(),in_order.end());
		/*NODE* root=generate_tree(post_order,in_order);*/
		queue<NODE*> layer_queue;
		NODE* current_point=root;
		printf("%u",current_point->number);
		layer_queue.push(current_point);
		while(!layer_queue.empty())
		{
			NODE*& temp_point=layer_queue.front();
			if(temp_point->left!=NULL)
			{
				layer_queue.push(temp_point->left);
				printf(" %u",temp_point->left->number);
			}
			if(temp_point->right!=NULL)
			{
				layer_queue.push(temp_point->right);
				printf(" %u",temp_point->right->number);
			}
			layer_queue.pop();
		}
		printf("\n");
	}
	return 0;
}