#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
   ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* new_head = new ListNode;
       new_head->next = head;
       ListNode* p = new_head;
       int k = 0;
       while(p->next != nullptr && k < n) {
           p = p->next;
           ++k;
       }
       ListNode* q = new_head;
       while(p->next != nullptr) {
           p = p->next;
           q = q->next;
       }
       q->next = q->next->next;
       head = new_head->next;
       delete new_head;
       return head;
   }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    auto p = s.removeNthFromEnd(head, 2);
    while(p != nullptr) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
