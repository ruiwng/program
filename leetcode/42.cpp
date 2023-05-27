#include <vector>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int len = static_cast<int>(height.size());
        vector<int> left_max_heights(len);
        vector<int> right_max_heights(len);
        int current_height = 0;
        for(int i = 0; i < len; ++i) {
            left_max_heights[i] = current_height;
            current_height = std::max(current_height, height[i]);
        }
        
        current_height = 0;
        for(int i = len - 1; i >= 0; --i) {
            right_max_heights[i] = current_height;
            current_height = std::max(current_height, height[i]);
        }
        
        int total_rain = 0;
        for(int i = 0; i < len; ++i) {
            total_rain += std::max(0, std::min(left_max_heights[i], right_max_heights[i]) - height[i]);
        }
        return total_rain;
    }
};

int main() {
    Solution s;
    vector<int> height({4,2,0,3,2,5});
    int r = s.trap(height);
    return 0;
}
