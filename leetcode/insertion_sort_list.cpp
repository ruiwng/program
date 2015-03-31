#include  <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head) {
    struct ListNode *h=(struct ListNode*)malloc(sizeof(struct ListNode));
	h->next=NULL;
	struct ListNode *q=head;
	while(q!=NULL)
	{
		struct ListNode *t=q->next;
		struct ListNode *p=h;
		while(p->next!=NULL&&p->next->val<q->val)
			p=p->next;
		q->next=p->next;
		p->next=q;
		q=t;
	}
	return h->next;
}

int main()
{

}