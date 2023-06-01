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
        ListNode* new_head = new ListNode;
        ListNode* p = new_head;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr) {
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;
            int sum = l1->val + l2->val + carry;
            if(sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            l1->next = nullptr;
            l1->val = sum;
            p->next = l1;
            p = p->next;
            l1 = l1_next;
            l2 = l2_next;
        }
        ListNode* l_left = l1 == nullptr? l2: l1;
        while(l_left != nullptr) {
            ListNode* l_left_next = l_left->next;
            int sum = l_left->val + carry;
            if(sum >= 10) {
                sum -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            l_left->next = nullptr;
            l_left->val = sum;
            p->next = l_left;
            p = p->next;
            l_left = l_left_next;
        }
        
        if(carry != 0) {
            p->next = new ListNode(carry);
        }
        
        ListNode* p_res = new_head->next;
        delete new_head;
        return p_res;
    }
};

int main() {
    
}
