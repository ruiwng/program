#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 0; i <= amount; ++i) {
            if(dp[i] == -1) {
                continue;
            }
            for(int j = 0; j < coins.size(); ++j) {
                long long k = static_cast<long long>(i) + coins[j];
                if(k > amount) {
                    continue;
                }
                if(dp[k] == -1 || dp[i] + 1 < dp[k]) {
                    dp[k] = dp[i] + 1;
                }
            }
        }
        return dp[amount];
    }
};

int main() {
    Solution s;
    vector<int> coins({2});
    int amount = 3;
    int r = s.coinChange(coins, amount);
    return 0;
}
