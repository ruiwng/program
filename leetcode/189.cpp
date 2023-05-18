#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = static_cast<int>(nums.size());
        k = k % len;
        /*
        nums.resize(len + k);
        for(int i = len - 1; i >= 0; --i) {
            nums[i + k] = nums[i];
        }
        for(int i = 0; i < k; ++i) {
            nums[i] = nums[i + len];
        }
        nums.resize(len);
         */
        
        std::reverse(nums.begin(), nums.begin() + len - k);
        std::reverse(nums.begin() + len - k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 2, 3, 4, 5, 6, 7});
    int k = 3;
    s.rotate(nums, k);
    return 0;
}
