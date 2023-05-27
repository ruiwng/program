#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        vector<int> result(len);
        int product = 1;
        for(int i = len - 1; i >= 0; --i) {
            product *= nums[i];
            result[i] = product;
        }
        int left = 1;
        for(int i = 0; i < len; ++i) {
            int right = i == (len - 1) ? 1: result[i + 1];
            result[i] = left * right;
            left *= nums[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums({1, 2, 3, 4});
    auto r = s.productExceptSelf(nums);
    return 0;
}
