#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int len = static_cast<int>(nums.size());
        if(len == 0) {
            return res;
        }
        int start = 0;
        int end = 0;
        while(true) {
            while(end + 1 < nums.size() && nums[end + 1] == nums[end] + 1) {
                ++end;
            }
            if(start == end) {
                res.push_back(to_string(nums[start]));
            } else {
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
            }
            if(end + 1 == nums.size()) {
                break;
            }
            ++end;
            start = end;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums({0,2,3,4,6,8,9});
    auto r = s.summaryRanges(nums);
    for(int i = 0; i < r.size(); ++i) {
        printf("%s\n", r[i].c_str());
    }
    return 0;
}
