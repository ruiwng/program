#include  <stdio.h>
#include  <algorithm>
#include  <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

struct cmp_func
{
    bool operator()(ListNode *lhs,ListNode *rhs) const
    {
        return lhs->val<rhs->val;
    }
};
class Solution {
public:
/*
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
    }*/
    ListNode *insertionSortList(ListNode *head){
        vector<ListNode*> node_array;
        ListNode *p=head;
        while(p!=NULL)
        {
            node_array.push_back(p);
            p=p->next;
        }
        sort(node_array.begin(),node_array.end(),cmp_func());
        node_array.push_back(NULL);
        int k=0;
        while(node_array[k]!=NULL)
        {
            node_array[k]->next=node_array[k+1];
            ++k;
        }
        return node_array[0];
    }
};

int main()
{
    
}
