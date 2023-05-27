#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        while(true) {
            int i = 1;
            for(; i < strs.size(); ++i) {
                if(strs[i].length() <= index || strs[i][index] != strs[0][index]) {
                    break;
                }
            }
            if(i != strs.size()) {
                break;
            }
            ++index;
            if(index >= strs[0].length()) {
                break;
            }
        }
        
        return strs[0].substr(0, index);
    }
};

int main() {
    Solution s;
    vector<string> strs({"dog","racecar","car"});
    auto str = s.longestCommonPrefix(strs);
    cout << str << endl;
    return 0;
}
