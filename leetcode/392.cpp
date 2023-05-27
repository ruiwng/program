#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.empty()) {
            return true;
        }
        int k = 0;
        for(int i = 0; i < t.size(); ++i) {
            if(t[i] == s[k]) {
                if(++k == s.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    
}
