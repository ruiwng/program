#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int visited[10];
        for(int i = 0; i < 9; ++i) {
            memset(visited, 0, sizeof(int) * 10);
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') {
                    continue;
                }
                auto index = board[i][j] - '0';
                if(visited[index]) {
                    return false;
                }
                visited[index] = true;
            }
            memset(visited, 0, sizeof(int) * 10);
            for(int j = 0; j < 9; ++j) {
                if(board[j][i] == '.') {
                    continue;
                }
                auto index = board[j][i] - '0';
                if(visited[index]) {
                    return false;
                }
                visited[index] = true;
            }
            memset(visited, 0, sizeof(int) * 10);
            int row_start = i / 3 * 3;
            int column_start = (i % 3) * 3;
            for(int j = 0; j < 9; ++j) {
                int row = row_start + j / 3;
                int column = column_start + j % 3;
                if(board[row][column] == '.') {
                    continue;
                }
                auto index = board[row][column] - '0';
                if(visited[index]) {
                    return false;
                }
                visited[index] = true;
            }
        }
        return true;
    }
};

int main(){
    
}
