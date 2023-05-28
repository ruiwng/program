#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool is_first_row_zero = false;
        bool is_first_column_zero = false;
        int m = static_cast<int>(matrix.size());
        int n = static_cast<int>(matrix[0].size());
        
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    if(i == 0) {
                        is_first_row_zero = true;
                    }
                    if(j == 0) {
                        is_first_column_zero = true;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(is_first_row_zero) {
            for(int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        if(is_first_column_zero) {
            for(int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};


int main() {
    Solution s;
    vector<vector<int> > matrix({
        vector<int>({1, 1, 1}),
        vector<int>({1, 0, 1}),
        vector<int>({1, 1, 1})
    });
    s.setZeroes(matrix);
    return 0;
}
