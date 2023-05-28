#include <string>
using namespace std;

#define CHAR_COUNT   26

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash_map[CHAR_COUNT];
        memset(hash_map, 0, sizeof(hash_map));
        for(int i = 0; i < magazine.size(); ++i) {
            ++hash_map[magazine[i] - 'a'];
        }
        
        int j = 0;
        for(;j < ransomNote.size(); ++j) {
            if(--hash_map[ransomNote[j] - 'a'] < 0) {
                break;
            }
        }
        
        return j == ransomNote.size();
    }
};

int main() {
    
}
