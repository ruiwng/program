#include  <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *p=head;
	struct ListNode *q=head;
	while(p!=NULL&&p->next!=NULL)
	{
		p=p->next->next;
		q=q->next;
		if(p==q)
			return true;
	}
	return false;
}

int main()
{

}