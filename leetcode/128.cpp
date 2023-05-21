#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> sequence_record;
        unordered_set<int> insert_record;
        int len = static_cast<int>(nums.size());
        int longest = 0;
        for(int i = 0; i < len; ++i) {
            if(!insert_record.insert(nums[i]).second) {
                continue;
            }
            auto iter_left = sequence_record.find(nums[i] - 1);
            auto iter_right = sequence_record.find(nums[i] + 1);
            int new_left = nums[i];
            int new_right = nums[i];
            if(iter_left != sequence_record.end()) {
                new_left = iter_left->second;
                sequence_record.erase(iter_left);
            }
            if(iter_right != sequence_record.end()) {
                new_right = iter_right->second;
                sequence_record.erase(iter_right);
            }
            sequence_record[new_left] = new_right;
            sequence_record[new_right] = new_left;
            if(new_right - new_left + 1 > longest) {
                longest = new_right - new_left + 1;
            }
        }
        return longest;
    }
};

int main() {
    Solution s;
    vector<int> nums {3,2,4,4,5};
    auto r = s.longestConsecutive(nums);
    return 0;
}
