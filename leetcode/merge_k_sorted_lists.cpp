#include  <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode *lists[], int k) {
    struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
	while(k>1)
	{
		int index=0;
		for(int i=0;i<k;i+=2)
		{
			if(i==k-1)
			{
				lists[index++]=lists[i];
				break;
			}
			struct ListNode *p=lists[i];
			struct ListNode *q=lists[i+1];
			struct ListNode *r=head;
			while(p!=NULL&&q!=NULL)
			{
				if(p->val<=q->val)
				{
					r->next=p;
					p=p->next;
				}
				else
				{
					r->next=q;
					q=q->next;
				}
				r=r->next;
			}
			if(p!=NULL)
				r->next=p;
			else
				r->next=q;
			lists[index++]=head->next;
		}
		k=index;
	}
	return lists[0];
}

int main()
{

}