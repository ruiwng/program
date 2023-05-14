#include <string>
#include <iostream>
using namespace std;

enum State {
    SUCCESS,
    FAILED,
    TOO_LONG
};

class Solution {
public:
    string sum(int start1, int length1, int start2, int length2) {
        string current;
        int other_start;
        int other_length;
        if(length1 >= length2) {
            current = mNumber.substr(start1, length1);
            other_start = start2;
            other_length = length2;
        } else {
            current = mNumber.substr(start2, length2);
            other_start = start1;
            other_length = length1;
        }
        int current_length = static_cast<int>(current.length());
        int sum = 0;
        for(int i = 0; i < current_length; ++i) {
            int current_pos = current_length - i - 1;
            sum += (current[current_pos] - '0');
            if(i < other_length) {
                int other_pos = other_start + other_length - 1 - i;
                sum += mNumber[other_pos] - '0';
            }
            int value = sum >= 10 ? (sum - 10): sum;
            sum = sum >= 10 ? 1: 0;
            current[current_pos] = '0' + value;
        }
        if(sum != 0) {
            current.insert(0, 1, '0' + sum);
        }
        return current;
    }
    bool isAdditiveNumber(string num) {
        if(num.size() < 3) {
            return false;
        }
        mNumber = num;
        int total_length = static_cast<int>(num.length());
        int i, j;
        auto checkAdditive = [&] () -> State {
            int k = 0;
            int next_pos = i + j;
            int prev_start = 0;
            int prev_length = i;
            int current_start = i;
            int current_length = j;
            while(true) {
                auto sum_str = sum(prev_start, prev_length, current_start, current_length);
                int sum_length = static_cast<int>(sum_str.length());
                if(i + j + sum_length > total_length) {
                    if(k == 0) {
                        return TOO_LONG;
                    } else {
                        return FAILED;
                    }
                }
                if(num.substr(next_pos, sum_length) != sum_str) {
                    return FAILED;
                }
                prev_start = current_start;
                prev_length = current_length;
                current_start = next_pos;
                current_length = sum_length;
                next_pos += sum_length;
                if(next_pos == total_length) {
                    return SUCCESS;
                }
                k += 1;
            }
        };
        for(i = 1; i < total_length - 1; ++i) {
            for(j = 1; j <= total_length - i; ++j) {
                auto state = checkAdditive();
                if(state == SUCCESS) {
                    return true;
                } else if(state == TOO_LONG) {
                    break;
                }
                if(num[i] == '0' && j == 1) {
                    break;
                }
            }
            if(num[i - 1] == '0' && i == 1) {
                break;
            }
        }
        return false;
    }
    std::string mNumber;
};

int main() {
    Solution s;
    auto result = s.isAdditiveNumber("199001200");
    return 0;
}
