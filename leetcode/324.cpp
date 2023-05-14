#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = static_cast<int>(nums.size());
        vector<int> temp(nums.size());
        int j = 0;
        for(auto i = 0; i < length; i += 2) {
            temp[i] = nums[j++];
        }
        for(auto i = 1; i < length; i += 2) {
            temp[i] = nums[j++];
        }
        
        bool comp_larger = true;
        bool is_success = true;
        for(auto i = 1; i < length; ++i) {
            if(comp_larger) {
                if(temp[i] <= temp[i - 1]) {
                    is_success = false;
                    break;
                }
            } else {
                if(temp[i] >= temp[i - 1]) {
                    is_success = false;
                    break;
                }
            }
            comp_larger = !comp_larger;
        }
        if(!is_success) {
            int larger_start;
            int small_start;
            if(length & 1) {
                small_start = length - 1;
                larger_start = length - 2;
            } else {
                small_start = length - 2;
                larger_start = length - 1;
            }
            j = 0;
            for(auto i = small_start; i >= 0; i -= 2) {
                temp[i] = nums[j++];
            }
            for(auto i = larger_start; i >= 0; i -= 2) {
                temp[i] = nums[j++];
            }
        }
        nums.swap(temp);
    }
};

int main() {
    vector<int> nums({4,5,5,6});
    Solution s;
    s.wiggleSort(nums);
    return 0;
}
