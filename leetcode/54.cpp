#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = static_cast<int>(matrix.size());
        if(row == 0) {
            return result;
        }
        int column = static_cast<int>(matrix[0].size());
        if(column == 0) {
            return result;
        }
        int left = 0;
        int right = column - 1;
        int top = 0;
        int bottom = row - 1;
        result.resize(row * column);
        int index = 0;
        while(true) {
            for(int i = left; i <= right; ++i) {
                result[index++] = matrix[top][i];
            }
            ++top;
            if(top > bottom) {
                break;
            }
            for(int i = top; i <= bottom; ++i) {
                result[index++] = matrix[i][right];
            }
            --right;
            if(left > right) {
                break;
            }
            for(int i = right; i >= left; --i) {
                result[index++] = matrix[bottom][i];
            }
            --bottom;
            if(top > bottom) {
                break;
            }
            for(int i = bottom; i >= top; --i) {
                result[index++] = matrix[i][left];
            }
            ++left;
            if(left > right) {
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix(vector<vector<int>>({
        vector<int>({1, 2, 3, 4}),
        vector<int>({5, 6, 7, 8}),
        vector<int>({9, 10, 11, 12})
    }));
    auto r = s.spiralOrder(matrix);
    return 0;
}
