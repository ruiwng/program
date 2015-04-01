#include  <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode *partition(struct ListNode *head, int x) {
    struct ListNode *h=(struct ListNode*)malloc(sizeof(struct ListNode));
	h->next=head;
	struct ListNode *p=h;
	while(p->next!=NULL&&p->next->val<x)
	   p=p->next;
	struct ListNode *q=p;
	while(true)
	{
		while(q->next!=NULL&&q->next->val>=x)
		  q=q->next;	
		if(q->next==NULL)
			break;
		struct ListNode *m=q->next;
		q->next=m->next;
		m->next=p->next;
		p->next=m;
		p=p->next;
	}
	return h->next;
}

int main()
{
	struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
	head->val=1;
	head->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p=head->next;
	p->val=4;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
    p=p->next;
	p->val=3;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	p=p->next;
	p->val=2;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	p=p->next;
	p->val=5;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	p=p->next;
	p->val=2;
	p->next=NULL;
	struct ListNode *t=partition(head,3);
	return 0;
}