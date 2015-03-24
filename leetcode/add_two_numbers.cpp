#include  <stdio.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head1=new ListNode(0),*head2=new ListNode(0);
		ListNode* p1=head1;
		p1->next=l1;
		ListNode* p2=head2;
		p2->next=l2;
		int carry=0;
		while(p1->next!=NULL&&p2->next!=NULL)
		{
			int temp=p1->next->val+p2->next->val+carry;
			if(temp>=10)
			{
				temp-=10;
				carry=1;
			}
			else
				carry=0;
			p1->next->val=temp;
			p1=p1->next;
			p2=p2->next;
		}
		if(p2->next!=NULL)
			p1->next=p2->next;
		while(p1->next!=NULL)
		{
			int temp=p1->next->val+carry;
			if(temp>=10)
			{
				temp-=10;
				carry=1;
			}
			else
				carry=0;
			p1->next->val=temp;
			if(carry==0)
				break;
			p1=p1->next;
		}
		if(carry==1)
			p1->next=new ListNode(1);
		return head1->next;
    }
};

int main()
{
	
}