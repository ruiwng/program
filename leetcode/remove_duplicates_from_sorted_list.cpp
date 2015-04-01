#include  <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode *deleteDuplicates(struct ListNode *head) {
	if(head==NULL)
		return NULL;
    struct ListNode *p=head;
	struct ListNode *q=p->next;
	while(true)
	{
		while(q!=NULL&&q->val==p->val)
		   q=q->next;
		p->next=q;
		p=p->next;
		if(q==NULL)
			break;
		q=q->next;
	}
	return head;
}

int main()
{
	struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
	head->val=1;
	head->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p=head->next;
	p->val=1;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
    p=p->next;
	p->val=2;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	p=p->next;
	p->val=3;
	p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
	p=p->next;
	p->val=3;
	p->next=NULL;
	struct ListNode *t=deleteDuplicates(head);
	return 0;
}