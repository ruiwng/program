/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   ListNode* swapNodes(ListNode* head, int k) {
       ListNode* p = head;
       
       int i = 1;
       while(i < k) {
           p = p->next;
           ++i;
       }
       ListNode* forwardK = p;
       
       ListNode* q = head;
       while(p->next != nullptr) {
           p = p->next;
           q = q->next;
       }
       ListNode* backwardK = q;
       swap(forwardK->val, backwardK->val);
       return head;
   }
};

int main() {
}
