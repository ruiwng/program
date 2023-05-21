#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = static_cast<int>(nums.size());
        set<vector<int>> result;
        for(int i = 0; i < length - 2; ++i) {
            if(nums[i] > 0) {
                break;
            }
            int j = i + 1;
            int k = length - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                bool move_j = false;
                bool move_k = false;
                if(sum == 0) {
                    result.insert(vector<int>({nums[i], nums[j], nums[k]}));
                    move_j = true;
                    move_k = true;
                } else if(sum < 0) {
                    move_j = true;
                } else {
                    move_k = true;
                }
                if(move_j) {
                    do {
                        ++j;
                    } while(j < k && nums[j] == nums[j - 1]);
                }
                if(move_k) {
                    do {
                        --k;
                    } while(j < k && nums[k] == nums[k + 1]);
                }
            }
        }
        vector<vector<int>> res;
        for(auto iter = result.begin(); iter != result.end(); ++iter) {
            res.push_back(vector<int>({(*iter)[0], (*iter)[1], (*iter)[2]}));
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums({-1,0,1,2,-1,-4});
    auto res = s.threeSum(nums);
    return 0;
}
