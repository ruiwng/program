#include  <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode *generate_bst(int node[],int start,int end)
{
	if(start>end)
		return NULL;
	int median=(start+end)>>1;
	struct TreeNode *head=(struct TreeNode*)malloc(sizeof(struct TreeNode));
	head->val=node[median];
	head->left=generate_bst(node,start,median-1);
	head->right=generate_bst(node,median+1,end);
	return head;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
    int num_node=0;
	struct ListNode *p=head;
	while(p!=NULL)
	{
		++num_node;
		p=p->next;
	}
	int *node_array=(int*)malloc(num_node*sizeof(int));
	p=head;
	int index=0;
	while(p!=NULL)
	{
		node_array[index++]=p->val;
		p=p->next;
	}
	return generate_bst(node_array,0,num_node-1);
}

int main()
{

}