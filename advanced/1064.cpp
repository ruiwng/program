#include  <stdio.h>
#include  <vector>
#include  <algorithm>
#include  <queue>
using namespace std;

struct NODE
{
	unsigned int key;
	NODE* left;
	NODE* right;
	NODE(unsigned int k,NODE* lf=NULL,NODE* rt=NULL):key(k),left(lf),right(rt){}
};


NODE* generate_node(vector<unsigned int>& array,vector<unsigned int>::iterator iter1,
					vector<unsigned int>::iterator iter2)
{
	if(iter1==iter2)
		return NULL;
	if(iter1+1==iter2)
		return new NODE(*iter1);
	unsigned int num=iter2-iter1;
	unsigned int num_temp=num+1;
	unsigned int count=0;
	while(num_temp!=0)
	{
		num_temp>>=1;
		count++;
	}
	unsigned int median=num-(1<<(count-2));
	if(median>(1<<(count-1))-1)
		median=(1<<(count-1))-1;
    return new NODE(*(iter1+median),generate_node(array,iter1,iter1+median),generate_node(array,iter1+median+1,iter2));
}

int main()
{
	unsigned int node_number;
	while(scanf("%u",&node_number)!=EOF)
	{
		vector<unsigned int> node_array;
		queue<NODE*> node_queue;
		for(unsigned int i=0;i<node_number;i++)
		{
			unsigned int node_temp;
			scanf("%u",&node_temp);
			node_array.push_back(node_temp);
		}
		sort(node_array.begin(),node_array.end());

		NODE* root=generate_node(node_array,node_array.begin(),node_array.end());

		node_queue.push(root);
		printf("%u",root->key);
		while(!node_queue.empty())
		{
			NODE* temp=node_queue.front();
			node_queue.pop();
			if(temp->left!=NULL)
			{
				printf(" %u",temp->left->key);
				node_queue.push(temp->left);
			}
			if(temp->right!=NULL)
			{
				printf(" %u",temp->right->key);
				node_queue.push(temp->right);
			}
		}
		printf("\n");
	}
	return 0;
}