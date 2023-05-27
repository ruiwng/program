#include <string>
using namespace std;

struct Roman {
    string str;
    int number;
};

class Solution {
public:
    int romanToInt(string s) {
        vector<Roman> roman_numbers({
            {"M", 1000},
            {"CM", 900},
            {"D", 500},
            {"CD", 400},
            {"C", 100},
            {"XC", 90},
            {"L", 50},
            {"XL", 40},
            {"X", 10},
            {"IX", 9},
            {"V", 5},
            {"IV", 4},
            {"I", 1}
        });
        
        int start = 0;
        int len = static_cast<int>(s.length());
        int i = 0;
        int number = 0;
        for(int i = 0; i < roman_numbers.size(); ++i) {
            int roman_len = static_cast<int>(roman_numbers[i].str.length());
            while(start < len && s.substr(start, roman_len) == roman_numbers[i].str) {
                start += roman_len;
                number += roman_numbers[i].number;
            }
            if(start == len) {
                break;
            }
        }
        return number;
    }
};

int main() {
    Solution s;
    string str("MCMXCIV");
    int r = s.romanToInt(str);
    return 0;
}
