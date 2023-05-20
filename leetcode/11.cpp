#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int max_area = 0;
        while(true) {
            max_area = std::max(max_area, (right - left) * min(height[left], height[right]));
            bool is_move_left = height[left] <= height[right];
            bool is_move_right = height[left] >= height[right];
            if(is_move_left) {
                int i = left;
                ++left;
                while(left < right && height[i] >= height[left]) {
                    ++left;
                }
                
            }
            if(is_move_right) {
                int i = right;
                --right;
                while(left < right && height[i] >= height[right]) {
                    --right;
                }
            }
            if(left >= right) {
                break;
            }
        }
        return max_area;
    }
};

int main() {
    Solution s;
    vector<int> height({1,1});
    auto r = s.maxArea(height);
    return 0;
}
