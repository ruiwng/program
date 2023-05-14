#include <vector>
using namespace std;

class Solution {
    void exchange(vector<vector<int>>& matrix, int n, int i, int j) {
        
        int temp = matrix[i][j];
        matrix[i][j] = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
        matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = temp;
    }
public:
    
    void rotate(vector<vector<int>>& matrix) {
        int n = static_cast<int>(matrix.size());
        if(n < 2) {
            return;
        }
        int half_n = (n + 1) / 2;
        for(int i = 0; i < (n >> 1); ++i) {
            for(int j = 0; j < half_n; ++j) {
                exchange(matrix, n, i, j);
            }
        }
    }
    
};

int main() {
    Solution s;
    vector<vector<int>> matrix({vector<int>{5,1,9,11}, vector<int>{2,4,8,10}, vector<int>{13,3,6,7}, vector<int>{15,14,12,16}});
    s.rotate(matrix);
    return 0;
}
