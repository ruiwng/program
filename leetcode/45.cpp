#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] = max(nums[i] + i, nums[i - 1]);
        }
        int step = 0;
        int pos = 0;
        while(pos < nums.size() - 1) {
            ++step;
            pos = nums[pos];
        }
        return step;
    }
};

int main() {
    Solution s;
    vector<int> nums({0});
    int r = s.jump(nums);
    return 0;
}
