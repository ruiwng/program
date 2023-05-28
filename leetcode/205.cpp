#include <string>
using namespace std;

#define CHAR_COUNT  256

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash_map[CHAR_COUNT];
        bool is_maped[CHAR_COUNT];
        for(int i = 0; i < CHAR_COUNT; ++i) {
            hash_map[i] = -1;
            is_maped[i] = false;
        }
        
        int j = 0;
        for(; j < s.length(); ++j) {
            if(hash_map[s[j]] != -1 && hash_map[s[j]] != t[j]) {
                break;
            }
            if(hash_map[s[j]] == -1) {
                if(is_maped[t[j]]) {
                    break;
                }
                is_maped[t[j]] = true;
                hash_map[s[j]] = t[j];
            }
        }
        
        return j == s.length();
    }
};

int main() {
    Solution s;
    s.isIsomorphic("badc", "baba");
    return 0;
}
