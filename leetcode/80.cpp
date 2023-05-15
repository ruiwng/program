#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current_num = 0;
        int repeat_count = 0;
        int start_pos = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == current_num) {
                ++repeat_count;
            } else {
                repeat_count = 1;
                current_num = nums[i];
            }
            if(repeat_count <= 2) {
                nums[start_pos++] = nums[i];
            }
        }
        return start_pos;
    }
};

int main() {
    Solution s;
    vector<int> nums({0,0,1,1,1,1,2,3,3});
    int len = s.removeDuplicates(nums);
    return 0;
}
