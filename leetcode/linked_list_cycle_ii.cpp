#include  <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p=head,*q=head;
	while(p!=NULL&&p->next!=NULL)
	{
		p=p->next->next;
		q=q->next;
		if(p==q)
			break;
	}
	if(p==NULL||p->next==NULL)
		return NULL;
	struct ListNode *m=head;
	while(p!=m)
	{
		p=p->next;
		m=m->next;
	}
	return p;
}

int main()
{

}