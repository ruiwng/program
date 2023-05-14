#include <algorithm>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) {
            return 1;
        } else if(n == 3) {
            return 2;
        }
        int record[60];
        memset(record, 0, sizeof(record));
        record[2] = 2;
        record[3] = 3;
        record[4] = 4;
        for(int i = 5; i <= n; ++i) {
            for(int j = 2; j <= (i >> 1); ++j) {
                int k = i - j;
                if(record[j] * record[k] > record[i]) {
                    record[i] = record[j] * record[k];
                }
            }
        }
        return record[n];
    }
};

int main() {
    Solution s;
    auto r = s.integerBreak(10);
    return 0;
}
