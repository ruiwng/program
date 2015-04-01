#include  <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode *head) {
	if(head==NULL)
		return;
	struct ListNode *h=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p=head;
	int node_num=0;
	while(p!=NULL)
	{
		++node_num;
		p=p->next;
	}
	struct ListNode **node_array=(struct ListNode**)malloc(node_num*sizeof(struct ListNode*));
	p=head;
	int index=0;
	while(p!=NULL)
	{
		node_array[index++]=p;
		p=p->next;
	}
	p=h;
	int start=0,end=node_num-1;
	while(true)
	{
		p->next=node_array[start];
		p=p->next;
		if(++start>end)
			break;
		p->next=node_array[end];
		p=p->next;
		if(--end<start)
			break;
	}
	p->next=NULL;
}

int main()
{
	struct ListNode *head=(struct ListNode*)malloc(sizeof(ListNode));
	head->val=1;
	head->next=(struct ListNode*)malloc(sizeof(ListNode));
	struct ListNode *p=head->next;
	p->val=2;
	p->next=(struct ListNode*)malloc(sizeof(ListNode));
	p=p->next;
	p->val=3;
	p->next=(struct ListNode*)malloc(sizeof(ListNode));
	p=p->next;
	p->val=4;
	p->next=NULL;
	reorderList(head);
	return 0;
}