#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
            if(lhs[0] != rhs[0]) {
                return lhs[0] < rhs[0];
            }
            return lhs[1] < rhs[1];
        });
        vector<vector<int>> result;
        int current_start = 0, current_end = 0;
        int is_current_empty = true;
        for(int i = 0; i < intervals.size(); ++i) {
            if(is_current_empty) {
                current_start = intervals[i][0];
                current_end = intervals[i][1];
                is_current_empty = false;
            } else {
                if(intervals[i][0] > current_end) {
                    result.push_back(vector<int>({current_start, current_end}));
                    current_start = intervals[i][0];
                    current_end = intervals[i][1];
                } else {
                    current_end = std::max(current_end, intervals[i][1]);
                }
            }
        }
        if(!is_current_empty) {
            result.push_back(vector<int>({current_start, current_end}));
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals({
        vector<int>({1, 3}),
        vector<int>({2, 6}),
        vector<int>({8, 10}),
        vector<int>({15, 18})
    });
    auto r = s.merge(intervals);
    return 0;
}
