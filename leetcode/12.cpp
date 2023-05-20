#include <string>
#include <stdio.h>
using namespace std;

struct RomanNumber {
    RomanNumber(int n, string r): number(n), roman(r){}
    int number;
    string roman;
};

class Solution {
public:
    string intToRoman(int num) {
        vector<RomanNumber> roman_numbers({
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        });
        std::string res;
        for(int i = 0; i < roman_numbers.size(); ++i) {
            if(num == 0) {
                break;
            }
            while(num >= roman_numbers[i].number) {
                res += roman_numbers[i].roman;
                num -= roman_numbers[i].number;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    int num = 58;
    auto res = s.intToRoman(num);
    printf("%s\n", res.c_str());
    return 0;
}
