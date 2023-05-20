#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void traverse(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> grid_queue;
        grid[i][j] = '2';
        grid_queue.push({i, j});
        while(!grid_queue.empty()) {
            auto t = grid_queue.front();
            grid_queue.pop();
            if(t.first > 0 && grid[t.first - 1][t.second] == '1') {
                grid[t.first - 1][t.second] = '2';
                grid_queue.push({t.first - 1, t.second});
            }
            if(t.first + 1 < mRow && grid[t.first + 1][t.second] == '1') {
                grid[t.first + 1][t.second] = '2';
                grid_queue.push({t.first + 1, t.second});
            }
            if(t.second > 0 && grid[t.first][t.second - 1] == '1') {
                grid[t.first][t.second - 1] = '2';
                grid_queue.push({t.first, t.second - 1});
            }
            if(t.second + 1 < mColumn && grid[t.first][t.second + 1] == '1') {
                grid[t.first][t.second + 1] = '2';
                grid_queue.push({t.first, t.second + 1});
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        mRow = static_cast<int>(grid.size());
        mColumn = static_cast<int>(grid[0].size());
        int island_count = 0;
        for(int i = 0; i < mRow; ++i) {
            for(int j = 0; j < mColumn; ++j) {
                if(grid[i][j] == '1') {
                    traverse(grid, i, j);
                    ++island_count;
                }
            }
        }
        return island_count;
    }
private:
    int mRow;
    int mColumn;
};

int main() {
    
}
