#include  <stdio.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL)
            return head;
        ListNode *p=head->next;
        head->next=NULL;
        while(p!=NULL)
        {
            ListNode *q=p->next;
            if(p->val<=head->val)
            {
                p->next=head;
                head=p;
            }
            else
            {
                ListNode *k=head;
                while(k->next!=NULL&&p->val>k->next->val)
                    k=k->next;
                p->next=k->next;
                k->next=p;
            }
            p=q;
        }
        return head;
    }
};

int main()
{
    
}
