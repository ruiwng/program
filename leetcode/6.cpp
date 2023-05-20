#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {
            return s;
        }
        int str_len = (static_cast<int>(s.length()) / (numRows * 2 - 2) + 1) * (numRows - 1);
        vector<string> str_array(numRows, string(str_len, ' '));
        int k = 0;
        int column = 0;
        while(true) {
            for(int i = 0; i < numRows && k < s.length(); ++i, ++k) {
                str_array[i][column] = s[k];
            }
            if(k >= s.length()) {
                break;
            }
            for(int i = numRows - 2; i > 0 && k < s.length(); --i, ++k) {
                str_array[i][++column] = s[k];
            }
            ++column;
            if(k >= s.length()) {
                break;
            }
        }
        string res;
        for(int i = 0; i < numRows; ++i) {
            res += str_array[i];
        }
        res.erase(std::remove(res.begin(), res.end(), ' '), res.end());
        return res;
    }
};

int main() {
    Solution s;
    string str = "PAYPALISHIRING";
    int numRows = 4;
    auto res = s.convert(str, numRows);
    printf("%s\n", res.c_str());
    return 0;
}
