#include  <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *h=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p=h;
	struct ListNode *q=head;
	while(q!=NULL)
	{
		if(q->val!=val)
		{
			p->next=q;
			p=p->next;
		}
		q=q->next;
	}
	p->next=NULL;
	return h->next;
}

int main()
{

}