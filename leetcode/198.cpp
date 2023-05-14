#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        if(len == 1) {
            return nums[0];
        }
        vector<int> dp(len);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < len; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[len - 1];
    }
};

int main() {
    Solution s;
    vector<int> nums({2,7,9,3,1});
    int r = s.rob(nums);
    return 0;
}
