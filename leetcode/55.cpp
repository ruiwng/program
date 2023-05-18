#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_value = 0;
        int len = static_cast<int>(nums.size());
        for(int i = 0; i < len; ++i) {
            if(i <= max_value) {
                if(i + nums[i] > max_value) {
                    max_value = i + nums[i];
                }
            } else {
                break;
            }
        }
        return max_value >= len - 1;
    }
};

int main() {
    Solution s;
    vector<int> nums({3,2,1,0,4});
    bool r = s.canJump(nums);
    return 0;
}
