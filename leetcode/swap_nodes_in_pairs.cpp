#include  <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode *swapPairs(struct ListNode *head) {
    struct ListNode *start=(struct ListNode*)malloc(sizeof(struct ListNode));
	start->next=head;
	struct ListNode *p=start;
	while(true)
	{
		struct ListNode *p_first=p->next;
		if(p_first==NULL)
			break;
		struct ListNode *p_second=p_first->next;
		if(p_second==NULL)
			break;
		p_first->next=p_second->next;
		p_second->next=p_first;
		p->next=p_second;
		p=p_first;
	}
	return start->next;
}

int main()
{

}