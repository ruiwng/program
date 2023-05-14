class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = static_cast<int>(board.size());
        if (rows == 0)
            return;
        int columns = static_cast<int>(board[0].size());
        if (columns == 0)
            return;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                int total = 0, live = 0;
                for (int m = -1; m <= 1; ++m) {
                    for (int n = -1; n <= 1; ++n) {
                        int x = i + m;
                        int y = j + n;
                        if ((x == i && y == j) || x < 0 || x >= rows || y < 0 || y >= columns) {
                            continue;
                        }
                        total += 1;
                        if (board[x][y] < 2)
                            live += board[x][y];
                        else
                            live += (board[x][y] - 1) & 1;
                    }
                }
                if (board[i][j] == 1) {
                    if (live < 2 || live > 3) {
                        board[i][j] = 2;
                    } 
                }
                else {
                    if (live == 3) {
                        board[i][j] = 3;
                    }
                }
            }
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                board[i][j] &= 1;
            }
        }
    }
};

int main() {
}
