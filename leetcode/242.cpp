#include <string>
using namespace std;

#define CHAR_COUNT   26

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        int hash_map[CHAR_COUNT];
        memset(hash_map, 0, sizeof(hash_map));
        
        for(int i = 0; i < s.size(); ++i) {
            ++hash_map[s[i] - 'a'];
        }
        
        for(int i = 0; i < t.size(); ++i) {
            if(--hash_map[t[i] - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    
}
