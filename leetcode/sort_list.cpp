#include  <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode *mergeList(struct ListNode *left,struct ListNode *right)
{
	struct ListNode *p=left;
	struct ListNode *q=right;
	struct ListNode *result=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *l=result;
	while(p!=NULL&&q!=NULL)
	{
		if(p->val<=q->val)
		{
			l->next=p;
			p=p->next;
		}
		else
		{
			l->next=q;
			q=q->next;
		}
		l=l->next;
	}
	if(q!=NULL)
		l->next=q;
	else
		l->next=p;
	p=result->next;
	free(result);
	return p;
}

struct ListNode *sortList(struct ListNode *head) {
	if(head==NULL||head->next==NULL)
		return head;
    struct ListNode *p=head;
	struct ListNode *q=head;
	while(p!=NULL&&p->next!=NULL&&p->next->next!=NULL)
	{
		q=q->next;
		p=p->next->next;
	}
	p=q->next;
	q->next=NULL;
	struct ListNode *left=sortList(head);
	struct ListNode *right=sortList(p);
	return mergeList(left,right);
}

int main()
{
	int num[]={5,4,3,2,1};
	struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *p=head;
	for(int i=0;i<5;++i)
	{
		p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		p=p->next;
		p->val=num[i];
	}
	p->next=NULL;
	p=sortList(head->next);
	return 0;
}