#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        unordered_map<Node*, int> level_record;
        if(root == nullptr) {
            return result;
        }
        queue<Node*> node_queue;
        node_queue.push(root);
        level_record[root] = 0;
        int current_level = 0;
        vector<int> level_node;
        while(!node_queue.empty()) {
            Node* p = node_queue.front();
            auto iter = level_record.find(p);
            int level = iter->second;
            level_record.erase(iter);
            if(level != current_level) {
                current_level = level;
                result.push_back(level_node);
                level_node.clear();
            }
            level_node.push_back(p->val);
            node_queue.pop();
            for(auto &child: p->children) {
                level_record[child] = level + 1;
                node_queue.push(child);
            }
        }
        result.push_back(level_node);
        return result;
    }
};

int main() {
    
}
