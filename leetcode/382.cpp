#include <vector>
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
    Solution(ListNode* head) {
        ListNode* p = head;
        while(p != nullptr) {
            mValues.push_back(p->val);
            p = p->next;
        }
    }
    
    int getRandom() {
        if(mTemp.empty()) {
            mTemp = mValues;
        }
        float t = float(rand()) / RAND_MAX;
        int index = t * mTemp.size();
        int x = mTemp[index];
        mTemp.erase(mTemp.begin() + index);
        return x;
    }
    
private:
    vector<int> mValues;
    vector<int> mTemp;
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution s(head);
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    cout << s.getRandom() << endl;
    return 0;
}
