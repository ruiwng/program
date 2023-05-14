#include <string>
#include <iostream>
using namespace std;

union Number {
    int num1;
    unsigned int num2;
};

class Solution {
public:
    string toHex(int num) {
        Number n;
        n.num1 = num;
        string result;
        do {
            int mod = n.num2 & 0xf;
            if(mod < 10) {
                result = static_cast<char>('0' + mod) + result;
            } else {
                result = static_cast<char>('a' + mod - 10) + result;
            }
            n.num2 = n.num2 >> 4;
        } while(n.num2 != 0);
        return result;
    }
};

int main() {
    Solution s;
    auto s1 = s.toHex(26);
    cout << s1 << endl;
    auto s2 = s.toHex(-1);
    cout << s2 << endl;
    return 0;
}
