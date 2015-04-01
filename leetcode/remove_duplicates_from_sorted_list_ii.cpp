#include  <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode *deleteDuplicates(struct ListNode *head) {
    struct ListNode *h=(struct ListNode*)malloc(sizeof(struct ListNode));
	h->next=NULL;
	struct ListNode *p=h;
	struct ListNode *q=head;
	while(q!=NULL)
	{
		struct ListNode *m=q->next;
		while(m!=NULL&&m->val==q->val)
			m=m->next;
		if(m==q->next)
		{
			q->next=p->next;
			p->next=q;
			p=p->next;
		}
		q=m;
	}
	return h->next;
}

int main()
{
	struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
	head->val=1;
	head->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p=head->next;
	p->val=2;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
    p=p->next;
	p->val=3;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	p=p->next;
	p->val=3;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	p=p->next;
	p->val=4;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	p=p->next;
	p->val=4;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	p=p->next;
	p->val=5;
	p->next=NULL;
	struct ListNode *q=deleteDuplicates(head);
	return 0;
}