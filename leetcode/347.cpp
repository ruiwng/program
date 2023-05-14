#include <vector>
#include <unordered_map>
using namespace std;

struct FrequentInfo {
    int num;
    int frequent;
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequent_map;
        for(auto &num: nums) {
            auto iter = frequent_map.find(num);
            if(iter != frequent_map.end()) {
                ++iter->second;
            } else {
                frequent_map.insert({num, 1});
            }
        }
        vector<FrequentInfo> frequent_info;
        frequent_info.reserve(frequent_map.size());
        for(auto iter = frequent_map.begin(); iter != frequent_map.end(); ++iter) {
            frequent_info.push_back({iter->first, iter->second});
        }
        
        nth_element(frequent_info.begin(), frequent_info.begin() + k - 1, frequent_info.end(), [](const FrequentInfo& lhs, const FrequentInfo& rhs) -> bool {
            return lhs.frequent > rhs.frequent;
        });
        vector<int> result;
        for(int i = 0; i < k; ++i) {
            result.push_back(frequent_info[i].num);
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    auto r = s.topKFrequent(nums, 2);
    return 0;
}
