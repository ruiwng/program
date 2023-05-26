#include <vector>
using namespace std;

/*
class Solution {
    void partition(vector<int>& nums, int start, int end) {
        int rand_index = start + static_cast<int>(float(rand()) / RAND_MAX * (end - start));
        std::swap(nums[start], nums[rand_index]);
        int pivot = start;
        
        for(int i = start + 1; i < end; ++i) {
            if(nums[i] < nums[start]) {
                std::swap(nums[i], nums[++pivot]);
            }
        }
        std::swap(nums[start], nums[pivot]);
        if(pivot < mHalfIndex) {
            partition(nums, pivot + 1, end);
        } else if(pivot > mHalfIndex) {
            partition(nums, start, pivot);
        }
    }
public:
    int majorityElement(vector<int>& nums) {
        int len = static_cast<int>(nums.size());
        mHalfIndex = len >> 1;
        partition(nums, 0, len);
        return nums[mHalfIndex];
    }
    
private:
    int mHalfIndex;
};
*/

class Solution {

public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int c = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(!c) majority = nums[i];
            nums[i] == majority ? ++c:--c;
        }
        return majority;
    }
    
};

int main() {
    Solution s;
    vector<int> nums({3, 2, 3});
    int r = s.majorityElement(nums);
    return 0;
}
