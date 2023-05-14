#include <iostream>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int record[9];
        record[0] = 1;
        record[1] = 10;
        for(int i = 2; i <= n; ++i) {
            int number_without_0 = 1;
            int x = 9;
            
            // numbers without 0
            for(int j = 1; j <= i; ++j) {
                number_without_0 *= x;
                --x;
            }
            // numbers with leading number non-0, 0 inside
            int number_with_non_leading_0 = i - 1;
            x = 9;
            for(int j = 1; j < i; ++j) {
                number_with_non_leading_0 *= x;
                --x;
            }
            
            // numbers with leading 0
            int number_with_leading_0 = record[i - 1];
            record[i] = number_without_0 + number_with_non_leading_0 + number_with_leading_0;
        }
        return record[n];
    }
};

int main() {
    Solution s;
    int r = s.countNumbersWithUniqueDigits(3);
    return 0;
}
