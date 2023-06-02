#include <vector>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* new_head = new ListNode;
        ListNode* p = new_head;
        ListNode* q = head;
        while(true) {
            int i = 0;
            ListNode* m = q;
            while(m != nullptr && i < k) {
                m = m->next;
                ++i;
            }
            if(i < k) {
                p->next = q;
                break;
            }
            ListNode* n = q;
            for(i = 0; i < k; ++i) {
                ListNode* temp = q->next;
                q->next = p->next;
                p->next = q;
                q = temp;
                
            }
            p = n;
        }
        ListNode* r = new_head->next;
        delete new_head;
        return r;
    }
};

ListNode* createListNode(vector<int>& nums) {
    ListNode* new_head = new ListNode;
    ListNode* p = new_head;
    for(int i = 0; i < nums.size(); ++i) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    ListNode* r = new_head->next;
    delete new_head;
    return r;
}

void printListNode(ListNode* head) {
    ListNode* p = head;
    while(p != nullptr) {
        printf(" %d", p->val);
        p = p->next;
    }
    printf("\n");
}

int main() {
    vector<int> nums({1, 2, 3, 4, 5});
    ListNode* head = createListNode(nums);
    printListNode(head);
    Solution s;
    head = s.reverseKGroup(head, 3);
    printListNode(head);
    return 0;
}
