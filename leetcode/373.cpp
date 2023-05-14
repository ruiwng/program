#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> pairs_queue;
        for(int i = 0; i < nums1.size(); ++i) {
            for(int j = 0; j < nums2.size(); ++j) {
                int sum = nums1[i] + nums2[j];
                if(pairs_queue.size() < k) {
                    pairs_queue.push({sum, {nums1[i], nums2[j]}});
                } else if(sum < pairs_queue.top().first) {
                    pairs_queue.pop();
                    pairs_queue.push({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }
        vector<vector<int>> result;
        while(!pairs_queue.empty()) {
            auto top = pairs_queue.top();
            pairs_queue.pop();
            result.push_back(vector<int>({top.second.first, top.second.second}));
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums1({1, 2});
    vector<int> nums2({3});
    auto r = s.kSmallestPairs(nums1, nums2, 3);
    return 0;
}
