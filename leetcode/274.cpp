#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int left = 0;
        if(citations[left] < (left + 1)) {
            return 0;
        }
        int right = static_cast<int>(citations.size()) - 1;
        if(citations[right] >= (right + 1)) {
            return right + 1;
        }
        int half = 0;
        while(left + 1 < right) {
            half = (left + right) >> 1;
            if(citations[half] >= half + 1) {
                left = half;
            } else if(citations[half] < half + 1) {
                right = half;
            }
        }
        return left + 1;
    }
};

int main() {
    Solution s;
    vector<int> citations({3, 0, 6, 1, 5});
    int r = s.hIndex(citations);
    return 0;
}
