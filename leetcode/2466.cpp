#include <vector>
using namespace std;
class Solution {
public:
    static constexpr int MAX_VALUE = 1000000007;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1);
        dp[0] = 1;
        int total = 0;
        for(int i = 1; i <= high; ++i) {
            if(i - zero >= 0) {
                dp[i] += dp[i - zero];
            }
            if(i - one >= 0) {
                dp[i] += dp[i - one];
            }
            if(dp[i] >= MAX_VALUE) {
                dp[i] -= MAX_VALUE;
            }
            if(i >= low && i <= high) {
                total += dp[i];
                if(total >= MAX_VALUE) {
                    total -= MAX_VALUE;
                }
            }
        }
        return total;
    }

};

int main() {
    Solution s;
    int r = s.countGoodStrings(2, 3, 1, 2);
    return 0;
}
