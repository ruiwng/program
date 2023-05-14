#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graphs(n);
        vector<int> connect_count(n);
        for(auto& edge: edges) {
            graphs[edge[0]].push_back(edge[1]);
            graphs[edge[1]].push_back(edge[0]);
            ++connect_count[edge[0]];
            ++connect_count[edge[1]];
        }
        
        queue<int> current_queue;
        int visit_count = 0;
        vector<bool> visited(n, false);
        for(auto i = 0; i < n; ++i) {
            if(connect_count[i] <= 1) {
                current_queue.push(i);
                visited[i] = true;
                ++visit_count;
            }
        }
        queue<int> next_queue;
        while(true) {
            if(visit_count == n) {
                break;
            }
            while(!current_queue.empty()) {
                auto top = current_queue.front();
                current_queue.pop();
                auto &connects = graphs[top];
                for(auto& connect: connects) {
                    if(visited[connect]) {
                        continue;
                    }
                    if(--connect_count[connect] <= 1) {
                        visited[connect] = true;
                        ++visit_count;
                        next_queue.push(connect);
                    }
                }
            }
            swap(current_queue, next_queue);
        }
        vector<int> roots;
        while(!current_queue.empty()) {
            roots.push_back(current_queue.front());
            current_queue.pop();
        }
        return roots;
    }
};

int main() {
    Solution s;
    auto edges = vector<vector<int>> ({
    });
    auto result = s.findMinHeightTrees(1, edges);
    return 0;
}
