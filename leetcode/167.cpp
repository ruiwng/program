#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); ++i) {
            int other_value = target - numbers[i];
            int lower = i + 1;
            int upper = static_cast<int>(numbers.size()) - 1;
            int half = 0;
            while(lower <= upper) {
                half = (lower + upper) >> 1;
                if(numbers[half] == other_value) {
                    break;
                } else if(numbers[half] < other_value) {
                    lower = half + 1;
                } else {
                    upper = half - 1;
                }
            }
            if(lower <= upper) {
                return vector<int>({i + 1, half + 1});
            }
        }
        return vector<int>({0, 0});
    }
};

int main() {
    Solution s;
    vector<int> numbers({2,7,11,15});
    int target = 9;
    auto r = s.twoSum(numbers, target);
    return 0;
}
