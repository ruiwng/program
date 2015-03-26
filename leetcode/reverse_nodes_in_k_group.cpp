#include  <stdlib.h>

struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    struct ListNode *start=(struct ListNode*)malloc(sizeof(struct ListNode));
	start->next=head;
	struct ListNode *p=start->next,*p_begin=start;
	struct ListNode **pArray=(struct ListNode**)malloc(k*sizeof(struct ListNode*));
	while(true)
	{
		int index=0;
		while(p!=NULL&&index!=k)
	    {
			pArray[index++]=p;
			p=p->next;
	    }
		if(index!=k)
			break;
		while(--index>=0)
		{
			p_begin->next=pArray[index];
			p_begin=p_begin->next;
		}
		p_begin->next=p;
	}
	return start->next;
}

int main()
{
	struct ListNode *start=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p=start;
	for(int i=1;i<6;++i)
	{
		p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		p->next->val=i;
		p->next->next=NULL;
		p=p->next;
	}
	struct ListNode *result=reverseKGroup(start->next,3);
	return 0;
}