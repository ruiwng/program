#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        static int num_length = static_cast<int>(nums.size());
        if(num_length <= 1) {
            return num_length;
        }
        vector<int> longest_subsequence;
        longest_subsequence.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i) {
            auto iter = lower_bound(longest_subsequence.begin(), longest_subsequence.end(), nums[i]);
            if(iter == longest_subsequence.end()) {
                longest_subsequence.push_back(nums[i]);
            } else {
                *iter = nums[i];
            }
        }
        return static_cast<int>(longest_subsequence.size());
    }
};

int main() {
    Solution s;
    vector<int> nums({10,9,2,5,3,7,101,18});
    int res = s.lengthOfLIS(nums);
    return 0;
}
