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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* new_head = new ListNode;
        new_head->next = head;
        ListNode* p = new_head;
        for(int i = 1; i < left; ++i) {
            p = p->next;
        }
        
        ListNode* tail = p->next;
        if(right - left > 0) {
            ListNode* q = tail->next;
            for(int i = left + 1; i <= right; ++i) {
                ListNode* t = q->next;
                q->next = p->next;
                p->next = q;
                q = t;
            }
            tail->next = q;
        }
        
        ListNode* res = new_head->next;
        delete new_head;
        return res;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    head = s.reverseBetween(head, 1, 1);
    while(head != nullptr) {
        printf(" %d", head->val);
        head = head->next;
    }
    printf("\n");
    return 0;
}
