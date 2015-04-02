#include  <stdlib.h>

struct ListNode {
     int val;
    struct ListNode *next;
};

struct ListNode *reverseBetween(struct ListNode *head, int m, int n) {
	int len=n-m+1;
    struct ListNode **node_array=(struct ListNode**)malloc(len*sizeof(struct ListNode*));
	struct ListNode *h=(struct ListNode*)malloc(sizeof(struct ListNode));
	h->next=head;
	struct ListNode *p=h;
	int index=0;
	while(p->next!=NULL&&++index<m)
	    p=p->next;
	struct ListNode *left=p;
	p=p->next;
	while(p!=NULL&&index<=n)
	{
		node_array[index-m]=p;
		p=p->next;
		if(index!=m)
			node_array[index-m]->next=node_array[index-m-1];
		++index;
	}
	left->next=node_array[len-1];
	node_array[0]->next=p;
	free(node_array);
	return h->next;
}

int main()
{
	int num[]={1,2,3,4,5};
	struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p=head;
	for(int i=0;i<5;++i)
	{
		p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		p=p->next;
		p->val=num[i];
	}
	p->next=NULL;
	struct ListNode *q=reverseBetween(head->next,2,4);
	return 0;
}