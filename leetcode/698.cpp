#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool dfs(vector<int>& nums, vector<bool>& used, int sum, int target, int index, int k) {
        if(k == 1) {
            return true;
        }
        if(index == nums.size()) {
            return false;
        }
        if(sum == target) {
            return dfs(nums, used, 0, target, 0, k - 1);
        }
        for(auto i = index; i < nums.size(); ++i) {
            if(used[i] || (sum + nums[i] > target)) {
                continue;
            }
            used[i] = true;
            if(dfs(nums, used, sum + nums[i], target, i + 1, k)) {
                return true;
            }
            used[i] = false;
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int len = static_cast<int>(nums.size());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum / k;
        if(target * k != sum) {
            return false;
        }
        for(auto &num: nums) {
            if(target < num) {
                return false;
            }
        }
        sort(nums.begin(), nums.end(), greater<int>());
        vector<bool> used(len, false);
        
        bool r = dfs(nums, used, 0, target, 0, k);
        return r;
    }
};

int main() {
    Solution s;
    vector<int> nums {4,3,2,3,5,2,1};
    auto r = s.canPartitionKSubsets(nums, 4);
    return 0;
}
