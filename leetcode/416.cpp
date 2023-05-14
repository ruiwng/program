#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int len = static_cast<int>(nums.size());
        for(auto i = 0; i < len; ++i) {
            sum += nums[i];
        }
        if(sum & 1) {
            return false;
        }
        int half_num = sum >> 1;
        for(auto i = 0; i < len; ++i) {
            if(nums[i] > half_num) {
                return false;
            }
        }
        
        char ** dp = new char*[len];
        for(int i = 0; i < len; ++i) {
            dp[i] = new char[half_num + 1];
            memset(dp[i], 0, sizeof(char) * (half_num + 1));
            dp[i][0] = 1;
        }
        dp[0][nums[0]] = 1;
        
        bool r = false;
        for(int i = 1; i < len; ++i) {
            for(int j = 0;j <= half_num; ++j) {
                dp[i][j] = dp[i - 1][j];
                if(j >= nums[i]) {
                    dp[i][j] = max(dp[i - 1][j - nums[i]], dp[i][j]);
                }
            }
            if(dp[i][half_num] == 1) {
                r = true;
                break;
            }
        }
        for(int i = 0; i < len; ++i) {
            delete [] dp[i];
        }
        delete [] dp;
        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums({14,9,8,4,3,2});
    auto r = s.canPartition(nums);
    return 0;
}
