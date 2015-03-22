#include  <stdio.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int node_num1=0,node_num2=0;
	struct ListNode *p=headA;
	while(p!=NULL)
	{
		++node_num1;
		p=p->next;
	}
	p=headB;
	while(p!=NULL)
	{
		++node_num2;
		p=p->next;
	}
	p=headA;
	struct ListNode *q=headB;
	int temp;
	if(node_num1>node_num2)
	{
		temp=node_num1-node_num2;
		struct ListNode *k=q;
		q=p;
		p=k;
	}
	else
		temp=node_num2-node_num1;
	while(temp--!=0)
		q=q->next;
	while(p!=NULL)
	{
		if(p==q)
			break;
		p=p->next;
		q=q->next;
	}
	return p;
}

int main()
{
	
}