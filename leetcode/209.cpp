#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int current_sum = 0;
        int start = 0;
        int end = 0;
        while(end < nums.size()) {
            current_sum += nums[end++];
            if(current_sum >= target) {
                break;
            }
        }
        if(current_sum < target) {
            return 0;
        }
        int min_len = end - start;
        while(true) {
            while(current_sum - nums[start] >= target) {
                current_sum = current_sum - nums[start];
                ++start;
            }
            if(end - start < min_len) {
                min_len = end - start;
            }
            if(end >= nums.size()) {
                break;
            }
            current_sum += nums[end++];
        }
        return min_len;
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 2, 3, 4, 5});
    int len = s.minSubArrayLen(11, nums);
    return 0;
}
