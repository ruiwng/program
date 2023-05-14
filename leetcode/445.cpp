#include <stack>
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
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *head = new ListNode;
       
       stack<ListNode*> s1;
       stack<ListNode*> s2;
       
       ListNode* p = l1;
       while(p != nullptr) {
           s1.push(p);
           p = p->next;
       }
       
       p = l2;
       while(p != nullptr) {
           s2.push(p);
           p = p->next;
       }
       int carry = 0;
       while(!s1.empty() && !s2.empty()) {
           ListNode* q = s1.top();
           ListNode* k = s2.top();
           s1.pop();
           s2.pop();
           q->val += k->val + carry;
           if(q->val >= 10) {
               q->val -= 10;
               carry = 1;
           } else {
               carry = 0;
           }
           q->next = head->next;
           head->next = q;
       }
       stack<ListNode*>& s = s1.empty() ? s2: s1;
       while(!s.empty()) {
           ListNode* q = s.top();
           s.pop();
           q->val += carry;
           if(q->val >= 10) {
               q->val -= 10;
               carry = 1;
           } else {
               carry = 0;
           }
           q->next = head->next;
           head->next = q;
       }
       
       if(carry != 0) {
           ListNode* n = new ListNode(carry);
           n->next = head->next;
           head->next = n;
       }
       p = head->next;
       delete head;
       return p;
   }
};

int main() {
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);
    
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    Solution s;
    auto r = s.addTwoNumbers(l1, l2);
    while(r != nullptr) {
        cout << r->val << endl;
        r = r->next;
    }
    return 0;
}
