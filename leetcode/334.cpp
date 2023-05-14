 #include <vector>
 using namespace std;
 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() < 3) {
            return false;
        }
        int length = static_cast<int>(nums.size());
        vector<int> increasingCount(length, 1);
        int min_1 = nums[0];
        int min_2 = 0;
        bool is_min_2_exist = false;
        for(int j = 1; j < length; ++j) {
            if(nums[j] < min_1) {
                min_1 = nums[j];
            } else if(is_min_2_exist && nums[j] > min_2) {
                return true;
            } else if(nums[j] > min_1) {
                if(!is_min_2_exist || nums[j] < min_2) {
                    min_2 = nums[j];
                }
                is_min_2_exist = true;
            }
        }
        return false;
    }
};
 
int main() {
    Solution s;
    auto nums = vector<int>({1, 2, 1, 3});
    auto r = s.increasingTriplet(nums);
    return 0;
}
