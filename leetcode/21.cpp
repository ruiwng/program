struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p = list1;
        ListNode* q = list2;
        ListNode* r = new ListNode;
        ListNode* k = r;
        while(p != nullptr && q != nullptr) {
            if(p->val <= q->val) {
                k->next = p;
                p = p->next;
            } else {
                k->next = q;
                q = q->next;
            }
            k = k->next;
        }
        if(p != nullptr) {
            k->next = p;
        } else {
            k->next = q;
        }
        ListNode* m = r->next;
        delete r;
        return m;
    }
};

int main() {
    
}
