#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> traversed_numbers;
        
        while(n != 1) {
            if(traversed_numbers.find(n) != traversed_numbers.end()) {
                break;
            }
            traversed_numbers.insert(n);
            int k = 0;
            while(n != 0) {
                int temp = n % 10;
                k += temp * temp;
                n /= 10;
            }
            n = k;
        }
        return n == 1;
    }
};

int main() {
    Solution s;
    int n = 2;
    bool r = s.isHappy(n);
    return 0;
}
