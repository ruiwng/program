#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(len == 0 || nums[i] != nums[len - 1]) {
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};

int main() {
    Solution s;
    vector<int> nums({0,0,1,1,1,2,2,3,3,4});
    auto r = s.removeDuplicates(nums);
    return 0;
}
