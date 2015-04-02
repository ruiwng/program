#include  <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k) {
	if(head==NULL)
		return NULL;
    int len=0;
	struct ListNode *p=head;
	while(p!=NULL)
	{
		++len;
		p=p->next;
	}
	k%=len;
	struct ListNode *h=(struct ListNode*)malloc(sizeof(struct ListNode));
	h->next=head;
	p=h;
	struct ListNode *q=h;
	while(k--!=0&&p!=NULL)
		p=p->next;
	while(p->next!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	p->next=h->next;
	h->next=q->next;
	q->next=NULL;
	return h->next;
}

int main()
{
	struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p=head;
	for(int i=1;i<6;++i)
	{
		p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		p=p->next;
		p->val=i;
	}
	p->next=NULL;
	struct ListNode *q=rotateRight(head->next,2);
	return 0;
}