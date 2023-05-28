#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> num_record;
        for(int i = 0; i < nums.size(); ++i) {
            auto iter = num_record.find(nums[i]);
            if(iter != num_record.end()) {
                if(i - iter->second <= k) {
                    return true;
                }
            }
            num_record[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<int> nums({1,2,3,1,2,3});
    int k = 1;
    bool r = s.containsNearbyDuplicate(nums, k);
    return 0;
}
