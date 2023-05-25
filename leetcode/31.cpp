#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    void swap(vector<int>& nums, int start) {
        int i = start;
        int j = static_cast<int>(nums.size()) - 1;
        while(i < j) {
            std::swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        int index = len - 2;
        while(index >= 0) {
            if(nums[index] < nums[index + 1]) {
                break;
            }
            --index;
        }
        if(index < 0) {
            swap(nums, 0);
        } else {
            int i = len - 1;
            for(; i > index; --i) {
                if(nums[i] > nums[index]) {
                    std::swap(nums[i], nums[index]);
                    break;
                }
            }
            swap(nums, index + 1);
        }
        
    }
};

int main() {
    Solution s;
    vector<int> nums({2, 3, 1});
    s.nextPermutation(nums);
    for(int i = 0; i < nums.size(); ++i) {
        printf(" %d", nums[i]);
    }
    printf("\n");
    return 0;
}
