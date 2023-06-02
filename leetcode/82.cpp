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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* new_head = new ListNode;
        ListNode* p = new_head;
        ListNode* q = head;
        while(true) {
            if(q == nullptr) {
                break;
            }
            ListNode* k = q;
            int equal_count = 0;
            while(k != nullptr && k->val == q->val) {
                k = k->next;
                ++equal_count;
            }
            if(equal_count == 1) {
                p->next = q;
                p = p->next;
            }
            q = k;
        }
        p->next = nullptr;
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
    vector<int> nums({1, 1, 1, 2, 3});
    ListNode* head = createListNode(nums);
    printListNode(head);
    Solution s;
    head = s.deleteDuplicates(head);
    printListNode(head);
    return 0;
}
