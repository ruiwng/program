#include <stdlib.h>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* new_head = nullptr;
        Node* p = head;
        Node* k = nullptr;
        unordered_map<Node*, Node*> node_map;
        while(p != nullptr) {
            Node* q = new Node(p->val);
            node_map.insert({p, q});
            if(k == nullptr) {
                new_head = k = q;
            } else {
                k->next = q;
                k = k->next;
            }
            p = p->next;
        }
        p = head;
        k = new_head;
        while(p != nullptr) {
            if(p->random != nullptr) {
                k->random = node_map[p->random];
            } else {
                k->random = nullptr;
            }
            p = p->next;
            k = k->next;
        }
        return new_head;
    }
};

int main() {
    
}
