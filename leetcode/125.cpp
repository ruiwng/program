#include <string>
using namespace std;

class Solution {
    bool isAlphanumeric(char c) {
        return (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9');
    }
    
    char convertAlphanumeric(char c) {
        if(c >= 'A' && c <= 'Z') {
            return c - 'A' + 'a';
        }
        return c;
    }
public:
    
    bool isPalindrome(string s) {
        int len = static_cast<int>(s.length());
        int i = 0;
        int j = len - 1;
        while(true) {
            while(i < j && !isAlphanumeric(s[i])) {
                ++i;
            }
            while(i < j && !isAlphanumeric(s[j])) {
                --j;
            }
            if(i >= j) {
                break;
            }
            if(convertAlphanumeric(s[i]) != convertAlphanumeric(s[j])) {
                break;
            }
            ++i;
            --j;
        }
        return i >= j;
    }
};

int main() {
    Solution s;
    string str(" ");
    bool r = s.isPalindrome(str);
    return 0;
}
