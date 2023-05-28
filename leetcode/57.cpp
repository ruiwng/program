#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len = static_cast<int>(intervals.size());
        
        vector<vector<int>> result;
        do {
            int index = 0;
            while(index < len && intervals[index][1] < newInterval[0]) {
                result.push_back(intervals[index]);
                ++index;
            }
            if(index == len) {
                result.push_back(newInterval);
                break;
            }
            int start = min(newInterval[0], intervals[index][0]);
            
            while(index < len && newInterval[1] >= intervals[index][0]) {
                ++index;
            }
            
            int end = newInterval[1];
            if(index > 0 && intervals[index - 1][1] > end) {
                end = intervals[index - 1][1];
            }
            result.push_back(vector<int>({start, end}));
            
            for(int i = index; i < len; ++i) {
                result.push_back(intervals[i]);
            }
        } while(false);
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> intervals(
        {
            vector<int>({1, 5})
        });
    vector<int> newInterval {0, 0};
    auto r = s.insert(intervals, newInterval);
    for(int i = 0; i < r.size(); ++i) {
        printf("%d->%d\n", r[i][0], r[i][1]);
    }
    return 0;
}
