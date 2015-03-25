#include  <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
     struct ListNode* p1=head,*p2=head;
        while(n--!=0)
         p2=p2->next;
        if(p2!=NULL)
           p2=p2->next;
        else
           return p1->next;
        while(p2!=NULL)
         {
             p1=p1->next;
             p2=p2->next;
         }
        struct ListNode* pTemp=p1->next;
        p1->next=pTemp->next;
        return head;
}

int main()
{
	
}