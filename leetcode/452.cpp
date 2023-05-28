#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int shot_count = 0;
        bool is_exist = false;
        int end = 0;
        sort(points.begin(), points.end(), [](const vector<int>& lhs, const vector<int>& rhs) -> bool {
            return lhs[0] < rhs[0];
        });
        
        for(int i = 0; i < points.size(); ++i) {
            if(!is_exist) {
                end = points[i][1];
                is_exist = true;
            } else {
                if(points[i][0] > end) {
                    ++shot_count;
                    end = points[i][1];
                } else {
                    end = min(end, points[i][1]);
                }
            }
        }
        if(is_exist) {
            shot_count += 1;
        }
        return shot_count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points;
    points.push_back(vector<int>({1, 2}));
    points.push_back(vector<int>({2, 3}));
    points.push_back(vector<int>({3, 4}));
    points.push_back(vector<int>({4, 5}));
    int r = s.findMinArrowShots(points);
    return 0;
}
