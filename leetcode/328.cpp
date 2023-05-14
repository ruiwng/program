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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        }
        int i = 1;
        ListNode* oddListRoot = new ListNode;
        ListNode* eventListRoot = new ListNode;
        ListNode* currentOdd = oddListRoot;
        ListNode* currentEven = eventListRoot;
        ListNode* p = head;
        while(p != nullptr) {
            ListNode* q = p->next;
            if(i & 1) {
                currentOdd->next = p;
                currentOdd = p;
            } else {
                currentEven->next = p;
                currentEven = p;
            }
            ++i;
            p = q;
        }
        currentOdd->next = eventListRoot->next;
        currentEven->next = nullptr;
        ListNode *r = oddListRoot->next;
        delete oddListRoot;
        delete eventListRoot;
        return r;
    }
};

int main() {
    ListNode *root = new ListNode(1);
    
    root->next = new ListNode(2);
    ListNode* p = root->next;
    
    p->next = new ListNode(3);
    p = p->next;
    
    p->next = new ListNode(4);
    p = p->next;
    
    p->next = new ListNode(5);
    p = p->next;
    
    Solution s;
    auto r = s.oddEvenList(root);
    p = r;
    while(p != nullptr) {
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
