#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int current_index = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val) {
                nums[current_index++] = nums[i];
            }
        }
        return current_index;
    }
};

int main() {
    Solution s;
    vector<int> nums({3, 2, 2, 3});
    int val = 3;
    int r = s.removeElement(nums, val);
    return 0;
}
