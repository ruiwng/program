
  struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* h=NULL;
    struct ListNode *p=head;
    while(p!=NULL)
    {
        struct ListNode *q=p->next;
        p->next=h;
        h=p;
        p=q;
    }
    return h;
}
