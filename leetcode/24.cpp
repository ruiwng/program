#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* new_head = new ListNode;
        ListNode* q = new_head;
        ListNode *p = head;
        while(p && p->next) {
            ListNode* temp = p->next->next;
            q->next = p->next;
            q = q->next;
            q->next = p;
            q = q->next;
            p = temp;
        }
        q->next = p;
        ListNode* r = new_head->next;
        delete new_head;
        return r;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution s;
    auto r = s.swapPairs(head);
    while(r != nullptr) {
        printf("%d\n", r->val);
        r = r->next;
    }
    return 0;
}
